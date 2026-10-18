#include "Hydraulic/GKLionWellPuzzleActor.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "GKLionWell"

AGKLionWellPuzzleActor::AGKLionWellPuzzleActor()
	: CurrentStage(1)
	, bHiddenInscriptionRevealed(false)
	, bFlowPreviewActive(false)
{
	PuzzleID = FName(TEXT("P04_LionWell"));
	EvidenceRewardID = FName(TEXT("D1")); // Traces to Doc 03 D1: Cholagangam reservoir

	// Three-tier hints per Doc 09 P04/P05 and Doc 37
	HintTiers.Empty();
	HintTiers.Add(LOCTEXT("LionWellHint1", "Water descends strictly by gravity: raise the intake gate at the reservoir source first."));
	HintTiers.Add(LOCTEXT("LionWellHint2", "Opening the lower feeder before the bypass weir creates dangerous back-pressure. Open the lateral gate second."));
	HintTiers.Add(LOCTEXT("LionWellHint3", "Sequence: Raise Gate 1 (Intake), then Gate 2 (Bypass), then Gate 3 (Feeder), then dredge the silt basin."));

	SetupDefaultHydraulicNetwork();
}

void AGKLionWellPuzzleActor::BeginPlay()
{
	Super::BeginPlay();
	SimulateFlowGraph();
}

void AGKLionWellPuzzleActor::SetupDefaultHydraulicNetwork()
{
	HydraulicNodes.Empty();

	// 5 descending nodes (Deterministic DAG)
	FGKHydraulicNode N_Source;
	N_Source.NodeID = FName(TEXT("Node_Source"));
	N_Source.NodeDisplayName = LOCTEXT("NodeSource", "Cholagangam Reservoir Intake");
	N_Source.ElevationMeters = 48.0f;
	N_Source.bHasWater = true;
	N_Source.bIsSedimentBlocked = false;
	HydraulicNodes.Add(N_Source);

	FGKHydraulicNode N_Upper;
	N_Upper.NodeID = FName(TEXT("Node_UpperCanal"));
	N_Upper.NodeDisplayName = LOCTEXT("NodeUpper", "Upper Masonry Canal");
	N_Upper.ElevationMeters = 42.0f;
	N_Upper.bHasWater = false;
	N_Upper.bIsSedimentBlocked = false;
	HydraulicNodes.Add(N_Upper);

	FGKHydraulicNode N_Bypass;
	N_Bypass.NodeID = FName(TEXT("Node_BypassWeir"));
	N_Bypass.NodeDisplayName = LOCTEXT("NodeBypass", "Lateral Pressure Bypass Weir");
	N_Bypass.ElevationMeters = 36.0f;
	N_Bypass.bHasWater = false;
	N_Bypass.bIsSedimentBlocked = false;
	HydraulicNodes.Add(N_Bypass);

	FGKHydraulicNode N_Sediment;
	N_Sediment.NodeID = FName(TEXT("Node_SedimentBasin"));
	N_Sediment.NodeDisplayName = LOCTEXT("NodeSediment", "Sediment Settling Basin");
	N_Sediment.ElevationMeters = 30.0f;
	N_Sediment.bHasWater = false;
	N_Sediment.bIsSedimentBlocked = true; // Stage 4 silt blockage
	HydraulicNodes.Add(N_Sediment);

	FGKHydraulicNode N_LionWell;
	N_LionWell.NodeID = FName(TEXT("Node_LionWellBasin"));
	N_LionWell.NodeDisplayName = LOCTEXT("NodeLionWell", "Lion Well Spout Basin");
	N_LionWell.ElevationMeters = 22.0f;
	N_LionWell.bHasWater = false;
	N_LionWell.bIsSedimentBlocked = false;
	HydraulicNodes.Add(N_LionWell);

	// 3 controllable sluice gates
	SluiceGates.Empty();

	FGKSluiceGate G1;
	G1.GateID = 1;
	G1.GateName = FName(TEXT("Gate_01_Intake"));
	G1.UpstreamNodeID = FName(TEXT("Node_Source"));
	G1.DownstreamNodeID = FName(TEXT("Node_UpperCanal"));
	G1.bIsOpen = false;
	G1.CorrectSequenceStep = 1;
	SluiceGates.Add(G1);

	FGKSluiceGate G2;
	G2.GateID = 2;
	G2.GateName = FName(TEXT("Gate_02_Bypass"));
	G2.UpstreamNodeID = FName(TEXT("Node_UpperCanal"));
	G2.DownstreamNodeID = FName(TEXT("Node_BypassWeir"));
	G2.bIsOpen = false;
	G2.CorrectSequenceStep = 2;
	SluiceGates.Add(G2);

	FGKSluiceGate G3;
	G3.GateID = 3;
	G3.GateName = FName(TEXT("Gate_03_Feeder"));
	G3.UpstreamNodeID = FName(TEXT("Node_BypassWeir"));
	G3.DownstreamNodeID = FName(TEXT("Node_SedimentBasin"));
	G3.bIsOpen = false;
	G3.CorrectSequenceStep = 3;
	SluiceGates.Add(G3);
}

void AGKLionWellPuzzleActor::OnResetPuzzleElements()
{
	CurrentStage = 1;
	bHiddenInscriptionRevealed = false;
	GateOperationSequence.Empty();

	for (FGKSluiceGate& Gate : SluiceGates)
	{
		Gate.bIsOpen = false;
	}

	for (FGKHydraulicNode& Node : HydraulicNodes)
	{
		Node.bHasWater = (Node.NodeID == FName(TEXT("Node_Source")));
		if (Node.NodeID == FName(TEXT("Node_SedimentBasin")))
		{
			Node.bIsSedimentBlocked = true;
		}
	}

	SimulateFlowGraph();
}

bool AGKLionWellPuzzleActor::ToggleSluiceGate(int32 GateID)
{
	FGKSluiceGate* TargetGate = nullptr;
	for (FGKSluiceGate& Gate : SluiceGates)
	{
		if (Gate.GateID == GateID)
		{
			TargetGate = &Gate;
			break;
		}
	}

	if (!TargetGate)
	{
		return false;
	}

	TargetGate->bIsOpen = !TargetGate->bIsOpen;

	if (TargetGate->bIsOpen)
	{
		GateOperationSequence.Add(GateID);
	}
	else
	{
		GateOperationSequence.Remove(GateID);
	}

	UE_LOG(LogGKPuzzle, Log, TEXT("Sluice Gate %d ('%s') toggled: %s"),
		GateID, *TargetGate->GateName.ToString(), TargetGate->bIsOpen ? TEXT("Open") : TEXT("Closed"));

	OnSluiceGateToggled.Broadcast(GateID, TargetGate->bIsOpen);
	SimulateFlowGraph();
	AttemptSolve();
	return true;
}

bool AGKLionWellPuzzleActor::ClearSedimentBlockage()
{
	for (FGKHydraulicNode& Node : HydraulicNodes)
	{
		if (Node.NodeID == FName(TEXT("Node_SedimentBasin")))
		{
			if (Node.bIsSedimentBlocked)
			{
				Node.bIsSedimentBlocked = false;
				UE_LOG(LogGKPuzzle, Log, TEXT("Sediment basin cleared of silt blockage."));
				SimulateFlowGraph();
				AttemptSolve();
				return true;
			}
			return false;
		}
	}
	return false;
}

void AGKLionWellPuzzleActor::SimulateFlowGraph()
{
	// Reset downstream water state
	for (FGKHydraulicNode& Node : HydraulicNodes)
	{
		if (Node.NodeID != FName(TEXT("Node_Source")))
		{
			Node.bHasWater = false;
		}
	}

	// Step 1: Check Gate 1
	if (SluiceGates.IsValidIndex(0) && SluiceGates[0].bIsOpen)
	{
		// Water enters Upper Canal
		for (FGKHydraulicNode& Node : HydraulicNodes)
		{
			if (Node.NodeID == FName(TEXT("Node_UpperCanal")))
			{
				Node.bHasWater = true;
				CurrentStage = FMath::Max(CurrentStage, 2);
			}
		}

		// Step 2: Check Gate 2 (Requires Upper Canal to have water)
		if (SluiceGates.IsValidIndex(1) && SluiceGates[1].bIsOpen)
		{
			for (FGKHydraulicNode& Node : HydraulicNodes)
			{
				if (Node.NodeID == FName(TEXT("Node_BypassWeir")))
				{
					Node.bHasWater = true;
					CurrentStage = FMath::Max(CurrentStage, 3);
				}
			}

			// Step 3: Check Gate 3 (Requires Bypass to have water)
			if (SluiceGates.IsValidIndex(2) && SluiceGates[2].bIsOpen)
			{
				for (FGKHydraulicNode& Node : HydraulicNodes)
				{
					if (Node.NodeID == FName(TEXT("Node_SedimentBasin")))
					{
						Node.bHasWater = true;
						CurrentStage = FMath::Max(CurrentStage, 4);

						// Step 4: Check if sediment blockage is cleared
						if (!Node.bIsSedimentBlocked)
						{
							for (FGKHydraulicNode& FinalNode : HydraulicNodes)
							{
								if (FinalNode.NodeID == FName(TEXT("Node_LionWellBasin")))
								{
									FinalNode.bHasWater = true;
								}
							}
						}
					}
				}
			}
		}
	}

	OnFlowUpdated.Broadcast(CurrentStage);
}

bool AGKLionWellPuzzleActor::EvaluateSolutionConditions()
{
	// Verification of Stage 4 completion
	for (const FGKHydraulicNode& Node : HydraulicNodes)
	{
		if (Node.NodeID == FName(TEXT("Node_LionWellBasin")))
		{
			if (Node.bHasWater)
			{
				if (!bHiddenInscriptionRevealed)
				{
					bHiddenInscriptionRevealed = true;
					UE_LOG(LogGKPuzzle, Log, TEXT("STAGE 4 COMPLETE: Hidden Inscription Chamber Revealed!"));
					OnHiddenChamberRevealed.Broadcast();
				}
				return true;
			}
		}
	}

	return false;
}

void AGKLionWellPuzzleActor::SetFlowPreviewActive(bool bActive)
{
	bFlowPreviewActive = bActive;
	UE_LOG(LogGKPuzzle, Log, TEXT("Lion Well flow preview toggle: %s"),
		bActive ? TEXT("Enabled") : TEXT("Disabled"));
}

#undef LOCTEXT_NAMESPACE
