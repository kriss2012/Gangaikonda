#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GKCodexTypes.h"
#include "GKDiscoveryNotificationViewModel.generated.h"

/**
 * Presentation ViewModel for the "HISTORICAL RECORD DISCOVERED" on-screen notification popup (Doc 08 Minutes 9–14, Doc 20 §6).
 * Formats: Source / Date-period / Confidence / Description.
 * Enforces Doc 20 §6: Border styling + redundant text labels (never color alone).
 */
UCLASS(BlueprintType)
class GKUI_API UGKDiscoveryNotificationViewModel : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Factory method creating a notification view model from an authentic unlocked evidence row.
	 */
	static UGKDiscoveryNotificationViewModel* CreateFromEvidenceRow(UObject* Outer, const FGKEvidenceRow& Row);

	/** Banner header text (always "HISTORICAL RECORD DISCOVERED") */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetBannerHeader() const;

	/** Unique evidence identifier (e.g. H2, B1) */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FName GetEvidenceID() const { return CachedRow.EvidenceID; }

	/** Historical claim / description text */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetDescription() const { return CachedRow.Claim; }

	/** Citation source (e.g. Inscriptions, archaeological excavation) */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetSource() const { return CachedRow.Source; }

	/** Historical date or period */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetDatePeriod() const { return CachedRow.DatePeriod; }

	/** Explicit text label for confidence rating (KNOWN / LIKELY / UNCERTAIN / UNKNOWN) */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetConfidenceLabel() const;

	/** Explicit text label for evidence category (DOCUMENTED / PLAUSIBLE RECONSTRUCTION / FICTIONAL) */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetCategoryLabel() const;

	/** UI border style (Solid / DashedHatched / Desaturated) per Doc 20 §6 */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	EGKCodexBorderStyle GetBorderStyle() const { return CachedRow.GetBorderStyle(); }

	/** Linear color code reflecting accessibility requirements */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FLinearColor GetThemeColor() const;

	/** Mandatory disclaimer text */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	FText GetRequiredDisclaimer() const { return CachedRow.RequiredDisclaimer; }

	/** Returns true if disclaimer must be displayed */
	UFUNCTION(BlueprintPure, Category = "GK|UI")
	bool HasDisclaimer() const { return !CachedRow.RequiredDisclaimer.IsEmpty(); }

private:
	UPROPERTY()
	FGKEvidenceRow CachedRow;
};
