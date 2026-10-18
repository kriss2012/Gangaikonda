#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GKCoreTypes.h"
#include "GKQuestTypes.h"
#include "GKQuestDataAsset.h"
#include "GKQuestSubsystem.h"
#include "GKQuestJournalViewModel.generated.h"

/**
 * Individual entry model for a quest inside the Quest Journal (Doc 20 §4).
 * Directly displays its Evidence Category badge alongside title and objectives.
 */
UCLASS(BlueprintType)
class GKUI_API UGKQuestJournalEntryViewModel : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	FName QuestID;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	FText Title;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	FText CategoryName;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	FText CurrentObjectiveText;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	FText EvidenceCategoryBadge;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	EGKEvidenceCategory EvidenceCategory;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	EGKQuestState QuestState;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	TArray<FText> CompletedObjectiveDescriptions;

	UPROPERTY(BlueprintReadOnly, Category = "GK|UI|Quest")
	TArray<FText> PendingObjectiveDescriptions;
};

/**
 * Presentation ViewModel for the full Quest Journal screen (Doc 20 §4).
 * Surfaces active and completed quests with explicit historical evidence tags.
 */
UCLASS(BlueprintType)
class GKUI_API UGKQuestJournalViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGKQuestJournalViewModel();

	/** Refreshes quest entries from the live quest subsystem */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Quest")
	void RefreshFromSubsystem(UGKQuestSubsystem* Subsystem);

	/** Sets the active quest in the detail panel */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Quest")
	void SelectQuest(UGKQuestJournalEntryViewModel* Quest);

	/** Active quests list */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Quest")
	TArray<TObjectPtr<UGKQuestJournalEntryViewModel>> ActiveQuests;

	/** Completed quests list */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Quest")
	TArray<TObjectPtr<UGKQuestJournalEntryViewModel>> CompletedQuests;

	/** Currently selected quest shown in the detail panel */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Quest")
	TObjectPtr<UGKQuestJournalEntryViewModel> SelectedQuest;

	/** Detail view: Current main objective */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Quest")
	FText DetailCurrentObjective;

	/** Detail view: Evidence category badge (e.g. "[PLAUSIBLE RECONSTRUCTION]") */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Quest")
	FText DetailEvidenceBadge;

private:
	void UpdateDetailPanel();
};
