#pragma once

#include "CoreMinimal.h"
#include "GKPuzzleBase.h"
#include "GKLionWellPuzzleActor.generated.h"

/**
 * A channel node in the deterministic hydraulic flow graph (Doc 09 P04/P05).
 */
USTRUCT(BlueprintType)
struct FGKHydraulicNode
{
	GENERATED_BODY()

	FGKHydraulicNode()
		: NodeID(NAME_None)
		, ElevationMeters(0.0f)
		, bHasWater(false)
		, bIsSedimentBlocked(false)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	FName NodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	FText NodeDisplayName;

	/** Channel elevation; water strictly descends from higher to lower nodes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	float ElevationMeters;

	/** True if active water flow is currently reaching this node */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Hydraulic")
	bool bHasWater;

	/** True if accumulated silt/sediment obstructs flow */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	bool bIsSedimentBlocked;
};

/**
 * Controllable stone sluice gate connecting hydraulic channels.
 */
USTRUCT(BlueprintType)
struct FGKSluiceGate
{
	GENERATED_BODY()

	FGKSluiceGate()
		: GateID(0)
		, GateName(NAME_None)
		, UpstreamNodeID(NAME_None)
		, DownstreamNodeID(NAME_None)
		, bIsOpen(false)
		, CorrectSequenceStep(0)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	int32 GateID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	FName GateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	FName UpstreamNodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	FName DownstreamNodeID;

	/** True if sluice gate is raised allowing water passage */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Hydraulic")
	bool bIsOpen;

	/** The correct sequence order (1, 2, or 3) for opening this gate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	int32 CorrectSequenceStep;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSluiceGateToggled, int32, GateID, bool, bIsOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHydraulicFlowUpdated, int32, CurrentStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHiddenInscriptionChamberRevealed);

/**
 * Lion Well Hydraulic Simulation Stages 1–4 (Doc 08 Minutes 18–23, Doc 09 P04/P05).
 * Simulates Chola reservoir diversion channels as a deterministic directed acyclic graph.
 * Restoring flow through stages 1–3 and clearing Stage 4 sediment reveals the hidden inscription chamber.
 */
UCLASS(BlueprintType)
class GKPUZZLE_API AGKLionWellPuzzleActor : public AGKPuzzleActor
{
	GENERATED_BODY()

public:
	AGKLionWellPuzzleActor();

	/** Nodes defining channel elevations and water locations */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	TArray<FGKHydraulicNode> HydraulicNodes;

	/** Sluice gates regulating flow between nodes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Hydraulic")
	TArray<FGKSluiceGate> SluiceGates;

	/** Current operational stage reached (1 to 4) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Hydraulic")
	int32 CurrentStage;

	/** True when Stage 4 is solved and the hidden inscription chamber is revealed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Hydraulic")
	bool bHiddenInscriptionRevealed;

	/** Toggles an individual sluice gate open or closed */
	UFUNCTION(BlueprintCallable, Category = "GK|Hydraulic")
	bool ToggleSluiceGate(int32 GateID);

	/** Clears sediment obstruction at the Stage 4 silt basin */
	UFUNCTION(BlueprintCallable, Category = "GK|Hydraulic")
	bool ClearSedimentBlockage();

	/** Toggles color-blind safe flow preview indicators (Doc 37 / Doc 09 P04) */
	UFUNCTION(BlueprintCallable, Category = "GK|Hydraulic")
	void SetFlowPreviewActive(bool bActive);

	UFUNCTION(BlueprintPure, Category = "GK|Hydraulic")
	bool IsFlowPreviewActive() const { return bFlowPreviewActive; }

	/** Runs the deterministic flow graph propagation */
	UFUNCTION(BlueprintCallable, Category = "GK|Hydraulic")
	void SimulateFlowGraph();

	UPROPERTY(BlueprintAssignable, Category = "GK|Hydraulic")
	FOnSluiceGateToggled OnSluiceGateToggled;

	UPROPERTY(BlueprintAssignable, Category = "GK|Hydraulic")
	FOnHydraulicFlowUpdated OnFlowUpdated;

	UPROPERTY(BlueprintAssignable, Category = "GK|Hydraulic")
	FOnHiddenInscriptionChamberRevealed OnHiddenChamberRevealed;

protected:
	virtual void BeginPlay() override;
	virtual bool EvaluateSolutionConditions() override;
	virtual void OnResetPuzzleElements() override;

	void SetupDefaultHydraulicNetwork();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Hydraulic")
	bool bFlowPreviewActive;

	/** Tracks gate operation history to detect back-pressure violations */
	UPROPERTY()
	TArray<int32> GateOperationSequence;
};
