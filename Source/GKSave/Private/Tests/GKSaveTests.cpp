#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "GKSaveGame.h"
#include "GKSaveSubsystem.h"
#include "GKWorldStateSubsystem.h"
#include "GKLogChannels.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Save.SerializationRoundTripAndSpike
 * Validates full binary round-trip serialization of the Doc 18 §6 save schema.
 * Executes the technical spike evaluating NPCMemory and WorldState serialization costs (Doc 01 §27, Doc 18 §6).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKSaveSerializationTest, "GK.Save.SerializationRoundTripAndSpike", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKSaveSerializationTest::RunTest(const FString& Parameters)
{
	// 1. Construct source save game object
	UGKSaveGame* SourceSave = NewObject<UGKSaveGame>();
	TestNotNull(TEXT("SourceSave created"), SourceSave);

	SourceSave->SaveSlotName = TEXT("VerticalSlice_Checkpoint");
	SourceSave->ActiveQuestID = TEXT("MQ_VS_CityOfTheConqueror");
	SourceSave->SaveVersion = UGKSaveGame::CurrentSaveVersion;

	// Populate 13 Vertical Slice Quests / Objectives
	for (int32 i = 1; i <= 13; ++i)
	{
		const FName QuestBeatID = *FString::Printf(TEXT("Beat_%02d"), i);
		SourceSave->QuestState.Add(QuestBeatID, i <= 7 ? EGKQuestState::Completed : (i == 8 ? EGKQuestState::InProgress : EGKQuestState::NotStarted));
	}

	// Populate 30 Historical Codex evidence IDs (Doc 03 / Doc 10)
	const TCHAR* EvidenceIDs[] = {
		TEXT("A1"), TEXT("A2"), TEXT("A3"), TEXT("A4"),
		TEXT("B1"), TEXT("B2"), TEXT("B3"), TEXT("B4"),
		TEXT("C1"), TEXT("C2"), TEXT("C3"), TEXT("C4"),
		TEXT("D1"), TEXT("D2"), TEXT("D3"),
		TEXT("E1"), TEXT("E2"), TEXT("E3"), TEXT("E4"),
		TEXT("F1"), TEXT("F2"), TEXT("F3"),
		TEXT("G1"), TEXT("G2"), TEXT("G3"),
		TEXT("H1"), TEXT("H2"),
		TEXT("I1"), TEXT("I2"), TEXT("I3")
	};
	for (const TCHAR* Id : EvidenceIDs)
	{
		SourceSave->CodexUnlocked.Add(FName(Id));
	}

	// Populate 5 Bounded NPC Memory records (Doc 13 §4 budget: max 32 flags per NPC)
	const FName NPCIDs[] = { TEXT("NPC_Scholar"), TEXT("NPC_Architect"), TEXT("NPC_Foreman"), TEXT("NPC_Priest"), TEXT("NPC_Guard") };
	for (const FName& Npc : NPCIDs)
	{
		FGKNPCMemorySaveRecord Record;
		Record.Flags.Add(TEXT("has_spoken"), true);
		Record.Flags.Add(TEXT("inspected_inscription"), true);
		Record.Flags.Add(TEXT("architect_favors_hydraulics"), false);
		Record.Flags.Add(TEXT("foreman_trust_established"), true);
		Record.Flags.Add(TEXT("witness_bribe_offered"), false);
		Record.Flags.Add(TEXT("sanctuary_clearance_granted"), true);
		Record.Flags.Add(TEXT("quarry_wagon_delayed"), false);
		Record.Flags.Add(TEXT("stone_load_path_verified"), true);
		SourceSave->NPCMemory.Add(Npc, Record);
	}

	// Populate World Construction progression across 5 zones
	SourceSave->WorldState.Add(TEXT("Zone5_Gangaikonda"), EGKConstructionStage::ScaffoldingVimanaMid);
	SourceSave->WorldState.Add(TEXT("Zone5_LionWell"), EGKConstructionStage::LowerGraniteCourses);
	SourceSave->WorldState.Add(TEXT("Zone5_QuarryRoad"), EGKConstructionStage::FoundationExcavation);
	SourceSave->WorldState.Add(TEXT("Zone5_RoyalEncampment"), EGKConstructionStage::CompletedSanctuary);
	SourceSave->WorldState.Add(TEXT("Zone5_WaterBasin"), EGKConstructionStage::LowerGraniteCourses);

	// Populate non-numeric faction reputations (Doc 01 §23, Doc 14)
	SourceSave->FactionReputation.Add(TEXT("RoyalCourt"), EGKFactionReputation::Respected);
	SourceSave->FactionReputation.Add(TEXT("GuildOfArchitects"), EGKFactionReputation::Honored);
	SourceSave->FactionReputation.Add(TEXT("QuarryWorkers"), EGKFactionReputation::Neutral);
	SourceSave->FactionReputation.Add(TEXT("TemplePriesthood"), EGKFactionReputation::Distrusted);

	// Populate 4 Puzzle state records
	FGKPuzzleSaveRecord StonePuzzle;
	StonePuzzle.State = EGKPuzzleState::Solved;
	StonePuzzle.HintsUnlocked = 1;
	StonePuzzle.SolvedStage = 3;
	SourceSave->PuzzleState.Add(TEXT("P01_StoneAlignment"), StonePuzzle);

	FGKPuzzleSaveRecord LionWellPuzzle;
	LionWellPuzzle.State = EGKPuzzleState::InProgress;
	LionWellPuzzle.HintsUnlocked = 2;
	LionWellPuzzle.SolvedStage = 2;
	SourceSave->PuzzleState.Add(TEXT("P04_LionWellHydraulics"), LionWellPuzzle);

	FGKPuzzleSaveRecord InscriptionPuzzle;
	InscriptionPuzzle.State = EGKPuzzleState::Solved;
	InscriptionPuzzle.HintsUnlocked = 0;
	InscriptionPuzzle.SolvedStage = 1;
	SourceSave->PuzzleState.Add(TEXT("P10_InscriptionDecoding"), InscriptionPuzzle);

	// Player State
	SourceSave->PlayerState.Location = FVector(12500.0f, -4200.0f, 650.0f);
	SourceSave->PlayerState.Rotation = FRotator(0.0f, 90.0f, 0.0f);
	SourceSave->PlayerState.Health = 85.0f;
	SourceSave->PlayerState.Stamina = 70.0f;

	// 2. Binary Serialization (Spike measurement)
	TArray<uint8> SerializedBytes;
	FMemoryWriter MemoryWriter(SerializedBytes, true);
	FObjectAndNameAsStringProxyArchive ArchiveWriter(MemoryWriter, false);
	SourceSave->Serialize(ArchiveWriter);

	const int32 TotalPayloadBytes = SerializedBytes.Num();
	UE_LOG(LogGKSave, Log, TEXT("--- TECHNICAL SPIKE REPORT: Vertical Slice Save Payload Cost ---"));
	UE_LOG(LogGKSave, Log, TEXT("Total payload size: %d bytes (%.2f KB)"), TotalPayloadBytes, TotalPayloadBytes / 1024.0f);
	UE_LOG(LogGKSave, Log, TEXT("Components: 13 Quests, 30 Codex IDs, 5 NPCs (40 flags), 5 World States, 4 Factions, 3 Puzzles, Player Vitals"));

	// Enforce strict technical spike budget (< 8 KB budget, typical vertical slice < 6 KB)
	TestTrue(TEXT("Save payload is under 8 KB budget"), TotalPayloadBytes < 8192);

	// 3. Binary Deserialization Round-Trip
	UGKSaveGame* RestoredSave = NewObject<UGKSaveGame>();
	TestNotNull(TEXT("RestoredSave created"), RestoredSave);

	FMemoryReader MemoryReader(SerializedBytes, true);
	FObjectAndNameAsStringProxyArchive ArchiveReader(MemoryReader, false);
	RestoredSave->Serialize(ArchiveReader);

	// 4. Validate exact reconstruction
	TestEqual(TEXT("SaveSlotName restored"), RestoredSave->SaveSlotName, SourceSave->SaveSlotName);
	TestEqual(TEXT("ActiveQuestID restored"), RestoredSave->ActiveQuestID, SourceSave->ActiveQuestID);
	TestEqual(TEXT("SaveVersion restored"), RestoredSave->SaveVersion, SourceSave->SaveVersion);
	TestEqual(TEXT("Quest count restored"), RestoredSave->QuestState.Num(), 13);
	TestEqual(TEXT("Beat_01 state restored"), RestoredSave->QuestState.FindRef(TEXT("Beat_01")), EGKQuestState::Completed);
	TestEqual(TEXT("Beat_08 state restored"), RestoredSave->QuestState.FindRef(TEXT("Beat_08")), EGKQuestState::InProgress);
	TestEqual(TEXT("Codex count restored"), RestoredSave->CodexUnlocked.Num(), 30);
	TestTrue(TEXT("Evidence A1 present"), RestoredSave->CodexUnlocked.Contains(TEXT("A1")));
	TestTrue(TEXT("Evidence I3 present"), RestoredSave->CodexUnlocked.Contains(TEXT("I3")));

	// Validate NPC Memory
	TestEqual(TEXT("NPC Memory count restored"), RestoredSave->NPCMemory.Num(), 5);
	const FGKNPCMemorySaveRecord* RestoredScholar = RestoredSave->NPCMemory.Find(TEXT("NPC_Scholar"));
	TestNotNull(TEXT("Scholar memory restored"), RestoredScholar);
	if (RestoredScholar)
	{
		TestEqual(TEXT("Scholar flags count"), RestoredScholar->Flags.Num(), 8);
		TestEqual(TEXT("Scholar inspected_inscription"), RestoredScholar->Flags.FindRef(TEXT("inspected_inscription")), true);
		TestEqual(TEXT("Scholar architect_favors_hydraulics"), RestoredScholar->Flags.FindRef(TEXT("architect_favors_hydraulics")), false);
	}

	// Validate World State & Factions
	TestEqual(TEXT("WorldState count restored"), RestoredSave->WorldState.Num(), 5);
	TestEqual(TEXT("Zone5_Gangaikonda stage restored"), RestoredSave->WorldState.FindRef(TEXT("Zone5_Gangaikonda")), EGKConstructionStage::ScaffoldingVimanaMid);
	TestEqual(TEXT("FactionReputation count restored"), RestoredSave->FactionReputation.Num(), 4);
	TestEqual(TEXT("GuildOfArchitects reputation restored"), RestoredSave->FactionReputation.FindRef(TEXT("GuildOfArchitects")), EGKFactionReputation::Honored);

	// Validate Puzzles & Player State
	TestEqual(TEXT("PuzzleState count restored"), RestoredSave->PuzzleState.Num(), 3);
	const FGKPuzzleSaveRecord* RestoredP01 = RestoredSave->PuzzleState.Find(TEXT("P01_StoneAlignment"));
	TestNotNull(TEXT("P01 puzzle restored"), RestoredP01);
	if (RestoredP01)
	{
		TestEqual(TEXT("P01 state restored"), RestoredP01->State, EGKPuzzleState::Solved);
		TestEqual(TEXT("P01 solved stage restored"), RestoredP01->SolvedStage, 3);
	}

	TestEqual(TEXT("Player location X restored"), RestoredSave->PlayerState.Location.X, 12500.0);
	TestEqual(TEXT("Player health restored"), RestoredSave->PlayerState.Health, 85.0f);

	return true;
}

/**
 * Test: GK.Save.CombatGatingAndSubsystem
 * Validates that manual saves are strictly blocked during active combat (Doc 18 §6).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKSaveCombatGatingTest, "GK.Save.CombatGatingAndSubsystem", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKSaveCombatGatingTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance created"), GameInstance);

	UGKSaveSubsystem* SaveSubsystem = NewObject<UGKSaveSubsystem>(GameInstance);
	TestNotNull(TEXT("SaveSubsystem created"), SaveSubsystem);

	// Initially not in combat: CanSave must be true
	SaveSubsystem->SetInCombat(false);
	TestTrue(TEXT("CanSave is true when outside combat"), SaveSubsystem->CanSave());

	// Set player in combat: CanSave must be strictly false per Doc 18 §6
	SaveSubsystem->SetInCombat(true);
	TestFalse(TEXT("CanSave is false during combat"), SaveSubsystem->CanSave());

	// Leave combat: CanSave is restored
	SaveSubsystem->SetInCombat(false);
	TestTrue(TEXT("CanSave is restored after exiting combat"), SaveSubsystem->CanSave());

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
