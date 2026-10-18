#include "GKCodexViewModel.h"

#define LOCTEXT_NAMESPACE "GKCodexViewModel"

UGKCodexEntryViewModel* UGKCodexEntryViewModel::CreateFromRow(UObject* Outer, const FGKEvidenceRow& SourceRow)
{
	UGKCodexEntryViewModel* ViewModel = NewObject<UGKCodexEntryViewModel>(Outer);
	if (ViewModel)
	{
		// Strict copy: values are cached directly from source row with zero mutation
		ViewModel->CachedRow = SourceRow;
	}
	return ViewModel;
}

FText UGKCodexEntryViewModel::GetCategoryDisplayText() const
{
	switch (CachedRow.Category)
	{
	case EGKEvidenceCategory::Documented:
		return LOCTEXT("CatDocumented", "DOCUMENTED");
	case EGKEvidenceCategory::PlausibleReconstruction:
		return LOCTEXT("CatPlausible", "PLAUSIBLE RECONSTRUCTION");
	case EGKEvidenceCategory::Fictional:
	default:
		return LOCTEXT("CatFictional", "FICTIONAL");
	}
}

FText UGKCodexEntryViewModel::GetConfidenceDisplayText() const
{
	switch (CachedRow.Confidence)
	{
	case EGKConfidence::Known:
		return LOCTEXT("ConfKnown", "KNOWN");
	case EGKConfidence::Likely:
		return LOCTEXT("ConfLikely", "LIKELY");
	case EGKConfidence::Uncertain:
		return LOCTEXT("ConfUncertain", "UNCERTAIN");
	case EGKConfidence::Unknown:
	default:
		return LOCTEXT("ConfUnknown", "UNKNOWN");
	}
}

FLinearColor UGKCodexEntryViewModel::GetCategoryThemeColor() const
{
	switch (CachedRow.Category)
	{
	case EGKEvidenceCategory::Documented:
		// Full rich bronze/gold tone
		return FLinearColor(0.85f, 0.65f, 0.20f, 1.0f);
	case EGKEvidenceCategory::PlausibleReconstruction:
		// Weathered sandstone/amber tone
		return FLinearColor(0.70f, 0.50f, 0.30f, 1.0f);
	case EGKEvidenceCategory::Fictional:
	default:
		// Desaturated granite grey tone
		return FLinearColor(0.45f, 0.45f, 0.48f, 1.0f);
	}
}

#undef LOCTEXT_NAMESPACE
