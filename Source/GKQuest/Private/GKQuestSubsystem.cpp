#include "GKQuestSubsystem.h"
#include "GKCodexSubsystem.h"
#include "GKLogChannels.h"
#include "Kismet/GameplayStatics.h"

UGKQuestSubsystem::UGKQuestSubsystem()
	: CurrentActiveQuestID(NAME_None)
{
}

void UGKQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadDefaultQuests();
	UE_LOG(LogGKQuest, Log, TEXT("UGKQuestSubsystem initialized."));
}

void UGKQuestSubsystem::Deinitialize()
{
	RegisteredQuests.Empty();
	QuestStates.Empty();
	RuntimeObjectives.Empty();
	CurrentActiveQuestID = NAME_None;
	Super::Deinitialize();
}

UGKQuestSubsystem* UGKQuestSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
	if (!GameInstance)
	{
		return nullptr;
	}

	return GameInstance->GetSubsystem<UGKQuestSubsystem>();
}

void UGKQuestSubsystem::LoadDefaultQuests()
{
	// Subsystem initialization hook for discovering DA_Quest_* assets
}

void UGKQuestSubsystem::RegisterQuest(UGKQuestDataAsset* QuestAsset)
{
	if (!QuestAsset || QuestAsset->QuestID.IsNone())
	{
		return;
	}

	RegisteredQuests.Add(QuestAsset->QuestID, QuestAsset);
	if (!QuestStates.Contains(QuestAsset->QuestID))
	{
		QuestStates.Add(QuestAsset->QuestID, EGKQuestState::NotStarted);
	}

	UE_LOG(LogGKQuest, Verbose, TEXT("Registered quest: %s ('%s')"),
		*QuestAsset->QuestID.ToString(), *QuestAsset->QuestTitle.ToString());
}

bool UGKQuestSubsystem::StartQuest(FName QuestID)
{
	UGKQuestDataAsset* QuestData = RegisteredQuests.FindRef(QuestID);
	if (!QuestData)
	{
		UE_LOG(LogGKQuest, Warning, TEXT("StartQuest failed: Quest '%s' not registered."), *QuestID.ToString());
		return false;
	}

	EGKQuestState& State = QuestStates.FindOrAdd(QuestID);
	if (State == EGKQuestState::InProgress)
	{
		UE_LOG(LogGKQuest, Verbose, TEXT("Quest '%s' is already in progress."), *QuestID.ToString());
		return false;
	}

	State = EGKQuestState::InProgress;
	CurrentActiveQuestID = QuestID;

	// Initialize runtime objectives
	TArray<FGKQuestObjective>& Objectives = RuntimeObjectives.FindOrAdd(QuestID);
	Objectives = QuestData->Objectives;

	// Activate first objective
	if (Objectives.Num() > 0)
	{
		Objectives[0].State = EGKObjectiveState::Active;
	}

	UE_LOG(LogGKQuest, Log, TEXT("QUEST STARTED: %s ('%s') - Act %d"),
		*QuestID.ToString(), *QuestData->QuestTitle.ToString(), QuestData->ActNumber);

	OnQuestStarted.Broadcast(QuestID);
	return true;
}

bool UGKQuestSubsystem::CompleteObjective(FName QuestID, FName ObjectiveID)
{
	TArray<FGKQuestObjective>* ObjectivesPtr = RuntimeObjectives.Find(QuestID);
	if (!ObjectivesPtr)
	{
		UE_LOG(LogGKQuest, Warning, TEXT("CompleteObjective: Quest '%s' has no active runtime objectives."), *QuestID.ToString());
		return false;
	}

	TArray<FGKQuestObjective>& Objectives = *ObjectivesPtr;
	int32 CompletedIndex = INDEX_NONE;

	for (int32 i = 0; i < Objectives.Num(); ++i)
	{
		if (Objectives[i].ObjectiveID == ObjectiveID)
		{
			if (Objectives[i].State == EGKObjectiveState::Completed)
			{
				return false;
			}
			Objectives[i].State = EGKObjectiveState::Completed;
			CompletedIndex = i;
			break;
		}
	}

	if (CompletedIndex == INDEX_NONE)
	{
		UE_LOG(LogGKQuest, Warning, TEXT("Objective '%s' not found in quest '%s'."), *ObjectiveID.ToString(), *QuestID.ToString());
		return false;
	}

	UE_LOG(LogGKQuest, Log, TEXT("Objective completed: [%s] on quest '%s'"), *ObjectiveID.ToString(), *QuestID.ToString());
	OnObjectiveCompleted.Broadcast(QuestID, ObjectiveID);

	// Activate next sequential objective if available
	const int32 NextIndex = CompletedIndex + 1;
	if (Objectives.IsValidIndex(NextIndex))
	{
		if (Objectives[NextIndex].State == EGKObjectiveState::Inactive)
		{
			Objectives[NextIndex].State = EGKObjectiveState::Active;
		}
	}

	// Check if all non-optional objectives are finished
	bool bAllMainObjectivesComplete = true;
	for (const FGKQuestObjective& Obj : Objectives)
	{
		if (!Obj.bIsOptional && Obj.State != EGKObjectiveState::Completed)
		{
			bAllMainObjectivesComplete = false;
			break;
		}
	}

	if (bAllMainObjectivesComplete)
	{
		CompleteQuest(QuestID);
	}

	return true;
}

bool UGKQuestSubsystem::CompleteQuest(FName QuestID)
{
	UGKQuestDataAsset* QuestData = RegisteredQuests.FindRef(QuestID);
	if (!QuestData)
	{
		return false;
	}

	QuestStates.FindOrAdd(QuestID) = EGKQuestState::Completed;

	// Concrete implementation of Doc 19 §4: Unlock Codex rewards via DT_HistoricalEvidence
	UGKCodexSubsystem* CodexSubsystem = UGKCodexSubsystem::Get(this);
	for (const FName& EvidenceID : QuestData->CodexRewardIDs)
	{
		if (CodexSubsystem)
		{
			CodexSubsystem->UnlockEntry(EvidenceID);
		}
	}

	UE_LOG(LogGKQuest, Log, TEXT("QUEST COMPLETED: %s ('%s'). %d Codex rewards unlocked."),
		*QuestID.ToString(), *QuestData->QuestTitle.ToString(), QuestData->CodexRewardIDs.Num());

	OnQuestCompleted.Broadcast(QuestID);

	if (CurrentActiveQuestID == QuestID)
	{
		CurrentActiveQuestID = NAME_None;
	}

	// Auto-advance next quest if designated
	if (!QuestData->NextQuestID.IsNone())
	{
		StartQuest(QuestData->NextQuestID);
	}

	return true;
}

EGKQuestState UGKQuestSubsystem::GetQuestState(FName QuestID) const
{
	if (const EGKQuestState* StatePtr = QuestStates.Find(QuestID))
	{
		return *StatePtr;
	}
	return EGKQuestState::NotStarted;
}

UGKQuestDataAsset* UGKQuestSubsystem::GetActiveQuestData() const
{
	if (CurrentActiveQuestID.IsNone())
	{
		return nullptr;
	}
	return RegisteredQuests.FindRef(CurrentActiveQuestID);
}

TArray<FGKQuestObjective> UGKQuestSubsystem::GetQuestObjectives(FName QuestID) const
{
	if (const TArray<FGKQuestObjective>* ObjPtr = RuntimeObjectives.Find(QuestID))
	{
		return *ObjPtr;
	}

	if (UGKQuestDataAsset* QuestData = RegisteredQuests.FindRef(QuestID))
	{
		return QuestData->Objectives;
	}

	return TArray<FGKQuestObjective>();
}

void UGKQuestSubsystem::RestoreQuestStates(const TMap<FName, EGKQuestState>& InStates, FName InActiveQuestID)
{
	QuestStates = InStates;
	CurrentActiveQuestID = InActiveQuestID;
	UE_LOG(LogGKQuest, Log, TEXT("Restored %d quest states from save data. Active: %s"),
		QuestStates.Num(), *CurrentActiveQuestID.ToString());
}
