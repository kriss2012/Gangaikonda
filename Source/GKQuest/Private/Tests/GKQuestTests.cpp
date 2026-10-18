#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKQuestTypes.h"
#include "GKQuestDataAsset.h"
#include "GKQuestSubsystem.h"
#include "Stubs/GKVSQuestChain.h"
#include "GKCodexSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Quest.LifecycleAndCodexRewards
 * Validates quest registration, objective sequential activation, completion, and automated Codex reward unlocks.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKQuestProgressionTest, "GK.Quest.LifecycleAndCodexRewards", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKQuestProgressionTest::RunTest(const FString& Parameters)
{
	// 1. Setup in-memory environment
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance created"), GameInstance);

	UGKQuestSubsystem* QuestSubsystem = NewObject<UGKQuestSubsystem>(GameInstance);
	TestNotNull(TEXT("QuestSubsystem created"), QuestSubsystem);

	UGKCodexSubsystem* CodexSubsystem = NewObject<UGKCodexSubsystem>(GameInstance);
	TestNotNull(TEXT("CodexSubsystem created"), CodexSubsystem);

	// Setup mock data table for Codex subsystem
	UDataTable* MockTable = NewObject<UDataTable>(GetTransientPackage());
	MockTable->RowStruct = FGKEvidenceRow::StaticStruct();

	auto AddMockRow = [MockTable](FName Id)
	{
		FGKEvidenceRow Row;
		Row.EvidenceID = Id;
		Row.Category = EGKEvidenceCategory::Documented;
		Row.Confidence = EGKConfidence::Known;
		MockTable->AddRow(Id, Row);
	};

	AddMockRow(FName(TEXT("C1")));
	AddMockRow(FName(TEXT("C2")));
	AddMockRow(FName(TEXT("C3")));
	AddMockRow(FName(TEXT("D1")));
	AddMockRow(FName(TEXT("H2")));

	CodexSubsystem->SetEvidenceDataTable(MockTable);

	// 2. Build and register vertical slice quest
	UGKQuestDataAsset* VSQuest = FGKVSQuestChain::BuildVerticalSliceQuest(GetTransientPackage());
	TestNotNull(TEXT("Vertical slice quest asset built"), VSQuest);
	TestEqual(TEXT("Has 13 objectives"), VSQuest->Objectives.Num(), 13);
	TestEqual(TEXT("Has 5 Codex rewards"), VSQuest->CodexRewardIDs.Num(), 5);

	QuestSubsystem->RegisterQuest(VSQuest);

	// 3. Start quest
	bool bStarted = QuestSubsystem->StartQuest(VSQuest->QuestID);
	TestTrue(TEXT("Quest started"), bStarted);
	TestEqual(TEXT("Active quest matches VSQuest"), QuestSubsystem->GetActiveQuestID(), VSQuest->QuestID);
	TestEqual(TEXT("Quest state is InProgress"), QuestSubsystem->GetQuestState(VSQuest->QuestID), EGKQuestState::InProgress);

	TArray<FGKQuestObjective> Objectives = QuestSubsystem->GetQuestObjectives(VSQuest->QuestID);
	TestEqual(TEXT("Objective 0 is Active"), Objectives[0].State, EGKObjectiveState::Active);
	TestEqual(TEXT("Objective 1 is Inactive"), Objectives[1].State, EGKObjectiveState::Inactive);

	// 4. Progress objective 1
	bool bBeat1 = QuestSubsystem->CompleteObjective(VSQuest->QuestID, FName(TEXT("Beat01_Arrival")));
	TestTrue(TEXT("Beat 1 completed"), bBeat1);

	Objectives = QuestSubsystem->GetQuestObjectives(VSQuest->QuestID);
	TestEqual(TEXT("Objective 0 is Completed"), Objectives[0].State, EGKObjectiveState::Completed);
	TestEqual(TEXT("Objective 1 is now Active"), Objectives[1].State, EGKObjectiveState::Active);

	// 5. Complete remaining objectives up to 13
	for (int32 i = 1; i < VSQuest->Objectives.Num(); ++i)
	{
		QuestSubsystem->CompleteObjective(VSQuest->QuestID, VSQuest->Objectives[i].ObjectiveID);
	}

	// 6. Verify full quest completion
	TestEqual(TEXT("Quest state is now Completed"), QuestSubsystem->GetQuestState(VSQuest->QuestID), EGKQuestState::Completed);
	TestTrue(TEXT("IsQuestCompleted returns true"), QuestSubsystem->IsQuestCompleted(VSQuest->QuestID));

	// 7. Verify automated Codex rewards unlocked without hardcoded strings (Doc 19 §4)
	TestTrue(TEXT("Codex reward C1 unlocked"), CodexSubsystem->IsUnlocked(FName(TEXT("C1"))));
	TestTrue(TEXT("Codex reward C2 unlocked"), CodexSubsystem->IsUnlocked(FName(TEXT("C2"))));
	TestTrue(TEXT("Codex reward C3 unlocked"), CodexSubsystem->IsUnlocked(FName(TEXT("C3"))));
	TestTrue(TEXT("Codex reward D1 unlocked"), CodexSubsystem->IsUnlocked(FName(TEXT("D1"))));
	TestTrue(TEXT("Codex reward H2 unlocked"), CodexSubsystem->IsUnlocked(FName(TEXT("H2"))));

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
