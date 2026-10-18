#include "GKCodexJournalViewModel.h"

UGKCodexJournalViewModel::UGKCodexJournalViewModel()
	: SelectedEntry(nullptr)
	, DetailBorderStyle(EGKCodexBorderStyle::Solid)
	, bIsFilterActive(false)
	, ActiveFilterCategory(EGKEvidenceCategory::Documented)
{
	DiscoveryProgressText = FText::FromString(TEXT("0 / 30 Records Recovered"));
}

void UGKCodexJournalViewModel::RefreshFromSubsystem(UGKCodexSubsystem* Subsystem)
{
	AllEntries.Empty();
	if (Subsystem)
	{
		AllEntries = Subsystem->GetUnlockedViewModels(this);
		const int32 UnlockedCount = Subsystem->GetUnlockedCount();
		const int32 TotalCount = Subsystem->GetTotalCount();
		DiscoveryProgressText = FText::Format(
			NSLOCTEXT("GKUI", "DiscoveryProgressFmt", "{0} / {1} Historical Records Recovered"),
			FText::AsNumber(UnlockedCount),
			FText::AsNumber(TotalCount)
		);
		UE_MVVM_SET_PROPERTY_VALUE(DiscoveryProgressText, DiscoveryProgressText);
	}

	UpdateVisibleEntries();

	if (VisibleEntries.Num() > 0)
	{
		SelectEntry(VisibleEntries[0]);
	}
	else
	{
		SelectEntry(nullptr);
	}
}

void UGKCodexJournalViewModel::SelectEntry(UGKCodexEntryViewModel* Entry)
{
	SelectedEntry = Entry;
	UE_MVVM_SET_PROPERTY_VALUE(SelectedEntry, SelectedEntry);
	UpdateDetailPanel();
}

void UGKCodexJournalViewModel::FilterByCategory(bool bApplyFilter, EGKEvidenceCategory Category)
{
	bIsFilterActive = bApplyFilter;
	ActiveFilterCategory = Category;
	UpdateVisibleEntries();

	if (VisibleEntries.Num() > 0)
	{
		SelectEntry(VisibleEntries[0]);
	}
	else
	{
		SelectEntry(nullptr);
	}
}

void UGKCodexJournalViewModel::UpdateVisibleEntries()
{
	VisibleEntries.Empty();
	for (UGKCodexEntryViewModel* Entry : AllEntries)
	{
		if (Entry)
		{
			if (!bIsFilterActive || Entry->GetCategory() == ActiveFilterCategory)
			{
				VisibleEntries.Add(Entry);
			}
		}
	}
	UE_MVVM_SET_PROPERTY_VALUE(VisibleEntries, VisibleEntries);
}

void UGKCodexJournalViewModel::UpdateDetailPanel()
{
	if (SelectedEntry)
	{
		DetailSource = SelectedEntry->GetSource();
		DetailDatePeriod = SelectedEntry->GetDatePeriod();
		DetailConfidenceText = SelectedEntry->GetConfidenceDisplayText();
		DetailDescription = SelectedEntry->GetClaim();
		DetailBorderStyle = SelectedEntry->GetBorderStyle();
		DetailCategoryBadge = SelectedEntry->GetCategoryDisplayText();
	}
	else
	{
		DetailSource = FText::GetEmpty();
		DetailDatePeriod = FText::GetEmpty();
		DetailConfidenceText = FText::GetEmpty();
		DetailDescription = NSLOCTEXT("GKUI", "NoEntrySelected", "No historical record selected.");
		DetailBorderStyle = EGKCodexBorderStyle::Desaturated;
		DetailCategoryBadge = FText::GetEmpty();
	}

	UE_MVVM_SET_PROPERTY_VALUE(DetailSource, DetailSource);
	UE_MVVM_SET_PROPERTY_VALUE(DetailDatePeriod, DetailDatePeriod);
	UE_MVVM_SET_PROPERTY_VALUE(DetailConfidenceText, DetailConfidenceText);
	UE_MVVM_SET_PROPERTY_VALUE(DetailDescription, DetailDescription);
	UE_MVVM_SET_PROPERTY_VALUE(DetailBorderStyle, DetailBorderStyle);
	UE_MVVM_SET_PROPERTY_VALUE(DetailCategoryBadge, DetailCategoryBadge);
}
