#include "GKQuestJournalViewModel.h"

UGKQuestJournalViewModel::UGKQuestJournalViewModel()
	: SelectedQuest(nullptr)
{
	DetailCurrentObjective = FText::GetEmpty();
	DetailEvidenceBadge = FText::GetEmpty();
}

void UGKQuestJournalViewModel::RefreshFromSubsystem(UGKQuestSubsystem* Subsystem)
{
	ActiveQuests.Empty();
	CompletedQuests.Empty();

	if (!Subsystem)
	{
		UpdateDetailPanel();
		return;
	}

	const FName ActiveID = Subsystem->GetActiveQuestID();
	UGKQuestDataAsset* ActiveData = Subsystem->GetActiveQuestData();
	if (ActiveData)
	{
		UGKQuestJournalEntryViewModel* Entry = NewObject<UGKQuestJournalEntryViewModel>(this);
		Entry->QuestID = ActiveData->QuestID;
		Entry->Title = ActiveData->Title;
		Entry->CategoryName = NSLOCTEXT("GKUI", "MainQuestCat", "Main Campaign");
		Entry->EvidenceCategory = ActiveData->HistoricalCategory;
		Entry->QuestState = Subsystem->GetQuestState(ActiveData->QuestID);

		switch (ActiveData->HistoricalCategory)
		{
		case EGKEvidenceCategory::Documented:
			Entry->EvidenceCategoryBadge = NSLOCTEXT("GKUI", "BadgeDoc", "[DOCUMENTED]");
			break;
		case EGKEvidenceCategory::PlausibleReconstruction:
			Entry->EvidenceCategoryBadge = NSLOCTEXT("GKUI", "BadgePlausible", "[PLAUSIBLE RECONSTRUCTION]");
			break;
		case EGKEvidenceCategory::Fictional:
		default:
			Entry->EvidenceCategoryBadge = NSLOCTEXT("GKUI", "BadgeFictional", "[FICTIONAL]");
			break;
		}

		TArray<FGKQuestObjective> Objs = Subsystem->GetQuestObjectives(ActiveData->QuestID);
		for (const FGKQuestObjective& Obj : Objs)
		{
			if (Obj.State == EGKObjectiveState::Active)
			{
				Entry->CurrentObjectiveText = Obj.Description;
			}
			else if (Obj.State == EGKObjectiveState::Completed)
			{
				Entry->CompletedObjectiveDescriptions.Add(Obj.Description);
			}
			else
			{
				Entry->PendingObjectiveDescriptions.Add(Obj.Description);
			}
		}

		if (Entry->CurrentObjectiveText.IsEmpty() && Objs.Num() > 0)
		{
			Entry->CurrentObjectiveText = Objs[0].Description;
		}

		if (Entry->QuestState == EGKQuestState::Completed)
		{
			CompletedQuests.Add(Entry);
		}
		else
		{
			ActiveQuests.Add(Entry);
		}
	}

	UE_MVVM_SET_PROPERTY_VALUE(ActiveQuests, ActiveQuests);
	UE_MVVM_SET_PROPERTY_VALUE(CompletedQuests, CompletedQuests);

	if (ActiveQuests.Num() > 0)
	{
		SelectQuest(ActiveQuests[0]);
	}
	else if (CompletedQuests.Num() > 0)
	{
		SelectQuest(CompletedQuests[0]);
	}
	else
	{
		SelectQuest(nullptr);
	}
}

void UGKQuestJournalViewModel::SelectQuest(UGKQuestJournalEntryViewModel* Quest)
{
	SelectedQuest = Quest;
	UE_MVVM_SET_PROPERTY_VALUE(SelectedQuest, SelectedQuest);
	UpdateDetailPanel();
}

void UGKQuestJournalViewModel::UpdateDetailPanel()
{
	if (SelectedQuest)
	{
		DetailCurrentObjective = SelectedQuest->CurrentObjectiveText;
		DetailEvidenceBadge = SelectedQuest->EvidenceCategoryBadge;
	}
	else
	{
		DetailCurrentObjective = NSLOCTEXT("GKUI", "NoActiveQuest", "No active objectives.");
		DetailEvidenceBadge = FText::GetEmpty();
	}

	UE_MVVM_SET_PROPERTY_VALUE(DetailCurrentObjective, DetailCurrentObjective);
	UE_MVVM_SET_PROPERTY_VALUE(DetailEvidenceBadge, DetailEvidenceBadge);
}
