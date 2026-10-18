#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GKCodexTypes.h"
#include "GKCodexViewModel.h"
#include "GKCodexSubsystem.h"
#include "GKCodexJournalViewModel.generated.h"

/**
 * Presentation ViewModel for the full-screen Codex Journal (Doc 03, Doc 20 §6).
 * Enforces the locked 4-field layout: Source / Date-Period / Confidence / Description.
 * Enforces redundant coding for color-blind accessibility:
 * Border style + explicit text tags, never color alone.
 */
UCLASS(BlueprintType)
class GKUI_API UGKCodexJournalViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGKCodexJournalViewModel();

	/** Populates entries from the live Codex subsystem */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Codex")
	void RefreshFromSubsystem(UGKCodexSubsystem* Subsystem);

	/** Sets the currently selected entry for detailed inspection */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Codex")
	void SelectEntry(UGKCodexEntryViewModel* Entry);

	/** Filters displayed records by evidence category */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Codex")
	void FilterByCategory(bool bApplyFilter, EGKEvidenceCategory Category);

	/** All entries matching current filter */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	TArray<TObjectPtr<UGKCodexEntryViewModel>> VisibleEntries;

	/** Currently selected entry shown in the detail panel */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	TObjectPtr<UGKCodexEntryViewModel> SelectedEntry;

	/** Total unlocked count summary text (e.g. "18 / 30 Records Recovered") */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DiscoveryProgressText;

	/** Detail view: Explicit 4-field Source */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DetailSource;

	/** Detail view: Explicit 4-field Date/Period */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DetailDatePeriod;

	/** Detail view: Explicit 4-field Confidence text label (Redundant coding per Doc 20 §6) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DetailConfidenceText;

	/** Detail view: Explicit 4-field Description */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DetailDescription;

	/** Detail view: Border style (Solid, Dashed, Muted) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	EGKCodexBorderStyle DetailBorderStyle;

	/** Detail view: Distinct category tag badge (e.g. "[DOCUMENTED]") */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Codex")
	FText DetailCategoryBadge;

private:
	UPROPERTY()
	TArray<TObjectPtr<UGKCodexEntryViewModel>> AllEntries;

	bool bIsFilterActive;
	EGKEvidenceCategory ActiveFilterCategory;

	void UpdateVisibleEntries();
	void UpdateDetailPanel();
};
