#include "GKDiscoveryNotificationViewModel.h"

#define LOCTEXT_NAMESPACE "GKDiscoveryNotification"

UGKDiscoveryNotificationViewModel* UGKDiscoveryNotificationViewModel::CreateFromEvidenceRow(UObject* Outer, const FGKEvidenceRow& Row)
{
	UGKDiscoveryNotificationViewModel* VM = NewObject<UGKDiscoveryNotificationViewModel>(Outer);
	if (VM)
	{
		VM->CachedRow = Row;
	}
	return VM;
}

FText UGKDiscoveryNotificationViewModel::GetBannerHeader() const
{
	return LOCTEXT("BannerHeader", "HISTORICAL RECORD DISCOVERED");
}

FText UGKDiscoveryNotificationViewModel::GetConfidenceLabel() const
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

FText UGKDiscoveryNotificationViewModel::GetCategoryLabel() const
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

FLinearColor UGKDiscoveryNotificationViewModel::GetThemeColor() const
{
	switch (CachedRow.Category)
	{
	case EGKEvidenceCategory::Documented:
		return FLinearColor(0.85f, 0.65f, 0.20f, 1.0f); // Bronze/Gold
	case EGKEvidenceCategory::PlausibleReconstruction:
		return FLinearColor(0.70f, 0.50f, 0.30f, 1.0f); // Weathered Sandstone
	case EGKEvidenceCategory::Fictional:
	default:
		return FLinearColor(0.45f, 0.45f, 0.48f, 1.0f); // Granite Grey
	}
}

#undef LOCTEXT_NAMESPACE
