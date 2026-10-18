#include "Stubs/GKVSQuestChain.h"

#define LOCTEXT_NAMESPACE "GKVSQuestChain"

UGKQuestDataAsset* FGKVSQuestChain::BuildVerticalSliceQuest(UObject* Outer)
{
	UGKQuestDataAsset* Quest = NewObject<UGKQuestDataAsset>(Outer);
	if (!Quest)
	{
		return nullptr;
	}

	Quest->QuestID = FName(TEXT("MQ_VS_CityOfTheConqueror"));
	Quest->QuestTitle = LOCTEXT("VSQuestTitle", "The City of the Conqueror");
	Quest->QuestDescription = LOCTEXT("VSQuestDesc",
		"Arulan arrives at the grand construction site of Gangaikondacholapuram. "
		"Investigate the foundation inscriptions, assist the Master Architect, restore the royal water channels, "
		"and uncover the conspiracy threatening the imperial ledger.");
	Quest->ActNumber = 6;
	Quest->HistoricalCategory = EGKEvidenceCategory::Documented;

	// Authentic Codex rewards directly referencing DT_HistoricalEvidence
	Quest->CodexRewardIDs = {
		FName(TEXT("C1")), // Gangaikondacholapuram capital
		FName(TEXT("C2")), // Brihadisvara Temple
		FName(TEXT("C3")), // Temple architecture
		FName(TEXT("D1")), // Cholagangam reservoir
		FName(TEXT("H2"))  // Paleographic script evolution
	};

	// 13 Beats from Doc 08
	TArray<FGKQuestObjective>& Objectives = Quest->Objectives;
	Objectives.Empty();

	// Beat 1: Arrival (0–2 min)
	FGKQuestObjective Obj1;
	Obj1.ObjectiveID = FName(TEXT("Beat01_Arrival"));
	Obj1.Description = LOCTEXT("Beat01Desc", "Traverse the approach road to the outer construction gate.");
	Obj1.bIsOptional = false;
	Obj1.TriggerTag = FName(TEXT("Trigger_GateReached"));
	Objectives.Add(Obj1);

	// Beat 2: City exploration (2–6 min)
	FGKQuestObjective Obj2;
	Obj2.ObjectiveID = FName(TEXT("Beat02_CityExploration"));
	Obj2.Description = LOCTEXT("Beat02Desc", "Explore the worker settlement and scan the quarry staging area.");
	Obj2.bIsOptional = false;
	Obj2.TriggerTag = FName(TEXT("Trigger_SettlementExplored"));
	Objectives.Add(Obj2);

	// Beat 3: Meet Scholar (6–9 min)
	FGKQuestObjective Obj3;
	Obj3.ObjectiveID = FName(TEXT("Beat03_MeetScholar"));
	Obj3.Description = LOCTEXT("Beat03Desc", "Speak with Royal Epigraphist Ilango in the Archive Tent.");
	Obj3.bIsOptional = false;
	Obj3.TriggerTag = FName(TEXT("Trigger_ScholarSpoken"));
	Objectives.Add(Obj3);

	// Beat 4: Discover inscription (9–14 min)
	FGKQuestObjective Obj4;
	Obj4.ObjectiveID = FName(TEXT("Beat04_DiscoverInscription"));
	Obj4.Description = LOCTEXT("Beat04Desc", "Decipher the foundation stone inscription using the Scholar's paleographic chart.");
	Obj4.bIsOptional = false;
	Obj4.TriggerTag = FName(TEXT("Trigger_InscriptionDecoded"));
	Objectives.Add(Obj4);

	// Beat 5: Meet architect (14–18 min)
	FGKQuestObjective Obj5;
	Obj5.ObjectiveID = FName(TEXT("Beat05_MeetArchitect"));
	Obj5.Description = LOCTEXT("Beat05Desc", "Consult Chief Sthapati Maravan at the Planning Pavilion.");
	Obj5.bIsOptional = false;
	Obj5.TriggerTag = FName(TEXT("Trigger_ArchitectSpoken"));
	Objectives.Add(Obj5);

	// Beat 6: Water puzzle (18–23 min)
	FGKQuestObjective Obj6;
	Obj6.ObjectiveID = FName(TEXT("Beat06_WaterPuzzle"));
	Obj6.Description = LOCTEXT("Beat06Desc", "Sequence the reservoir sluice gates at the Lion Well to restore water flow.");
	Obj6.bIsOptional = false;
	Obj6.TriggerTag = FName(TEXT("Trigger_LionWellSolved"));
	Objectives.Add(Obj6);

	// Beat 7: Temple construction (23–27 min)
	FGKQuestObjective Obj7;
	Obj7.ObjectiveID = FName(TEXT("Beat07_TempleScaffolding"));
	Obj7.Description = LOCTEXT("Beat07Desc", "Climb the vimana scaffolding to inspect load-path alignment on the upper course.");
	Obj7.bIsOptional = false;
	Obj7.TriggerTag = FName(TEXT("Trigger_StoneAlignmentSolved"));
	Objectives.Add(Obj7);

	// Beat 8: Investigation (27–31 min)
	FGKQuestObjective Obj8;
	Obj8.ObjectiveID = FName(TEXT("Beat08_Investigation"));
	Obj8.Description = LOCTEXT("Beat08Desc", "Investigate the Site Office and detect the granite shipment ledger discrepancy.");
	Obj8.bIsOptional = false;
	Obj8.TriggerTag = FName(TEXT("Trigger_LedgerDiscrepancyFound"));
	Objectives.Add(Obj8);

	// Beat 9: Political conspiracy (31–33 min)
	FGKQuestObjective Obj9;
	Obj9.ObjectiveID = FName(TEXT("Beat09_PoliticalConspiracy"));
	Obj9.Description = LOCTEXT("Beat09Desc", "Confront the site administrator regarding the forged royal seal.");
	Obj9.bIsOptional = false;
	Obj9.TriggerTag = FName(TEXT("Trigger_ConspiracyConfronted"));
	Objectives.Add(Obj9);

	// Beat 10: Ambush (33–37 min)
	FGKQuestObjective Obj10;
	Obj10.ObjectiveID = FName(TEXT("Beat10_Ambush"));
	Obj10.Description = LOCTEXT("Beat10Desc", "Evade or overcome the hired skirmishers along the transit corridor.");
	Obj10.bIsOptional = false;
	Obj10.TriggerTag = FName(TEXT("Trigger_AmbushSurvived"));
	Objectives.Add(Obj10);

	// Beat 11: Return (37–38 min)
	FGKQuestObjective Obj11;
	Obj11.ObjectiveID = FName(TEXT("Beat11_Return"));
	Obj11.Description = LOCTEXT("Beat11Desc", "Return to the settlement core to report findings.");
	Obj11.bIsOptional = false;
	Obj11.TriggerTag = FName(TEXT("Trigger_ReportDelivered"));
	Objectives.Add(Obj11);

	// Beat 12: Historical Codex assembly (38–40 min)
	FGKQuestObjective Obj12;
	Obj12.ObjectiveID = FName(TEXT("Beat12_CodexAssembly"));
	Obj12.Description = LOCTEXT("Beat12Desc", "Review the newly compiled historical evidence records in the archive.");
	Obj12.bIsOptional = false;
	Obj12.TriggerTag = FName(TEXT("Trigger_CodexReviewed"));
	Objectives.Add(Obj12);

	// Beat 13: Closing cinematic (40 min)
	FGKQuestObjective Obj13;
	Obj13.ObjectiveID = FName(TEXT("Beat13_Cinematic"));
	Obj13.Description = LOCTEXT("Beat13Desc", "Look out from the dusk overlook over the rising vimana silhouette.");
	Obj13.bIsOptional = false;
	Obj13.TriggerTag = FName(TEXT("Trigger_CinematicEnded"));
	Objectives.Add(Obj13);

	return Quest;
}

#undef LOCTEXT_NAMESPACE
