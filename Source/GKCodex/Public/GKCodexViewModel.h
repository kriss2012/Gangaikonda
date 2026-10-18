#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GKCodexTypes.h"
#include "GKCodexViewModel.generated.h"

/**
 * UI presentation model for historical Codex entries.
 * Enforces Hard Rule 4: "Never upgrade a confidence tier when moving data from the research database to the Codex."
 * Enforces Doc 20 §6: "Redundant coding for accessibility — confidence tier shown as explicit text, never color alone."
 */
UCLASS(BlueprintType)
class GKCODEX_API UGKCodexEntryViewModel : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Factory method to instantiate a presentation ViewModel from an authentic evidence row.
	 * There are NO setter methods on this class to prevent any programmatic tier upgrading.
	 */
	static UGKCodexEntryViewModel* CreateFromRow(UObject* Outer, const FGKEvidenceRow& SourceRow);

	/** Unique evidence identifier (e.g., A1, B1, C2) */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FName GetEvidenceID() const { return CachedRow.EvidenceID; }

	/** Claim text */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetClaim() const { return CachedRow.Claim; }

	/** Raw category enum — exactly preserved from source row */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	EGKEvidenceCategory GetCategory() const { return CachedRow.Category; }

	/** Explicit text label for evidence category (e.g. "DOCUMENTED", "PLAUSIBLE RECONSTRUCTION", "FICTIONAL") */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetCategoryDisplayText() const;

	/** Primary historical source or archaeological citation */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetSource() const { return CachedRow.Source; }

	/** Source type text */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetSourceType() const { return CachedRow.SourceType; }

	/** Date / historical period text */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetDatePeriod() const { return CachedRow.DatePeriod; }

	/** Raw confidence enum — exactly preserved from source row without alteration */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	EGKConfidence GetConfidence() const { return CachedRow.Confidence; }

	/** Explicit text label for confidence (e.g. "KNOWN", "LIKELY", "UNCERTAIN", "UNKNOWN") */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetConfidenceDisplayText() const;

	/** Gameplay connection description */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetGameUsage() const { return CachedRow.GameUsage; }

	/** Mandatory disclaimer text */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FText GetRequiredDisclaimer() const { return CachedRow.RequiredDisclaimer; }

	/** Returns true if a non-empty disclaimer must be displayed */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	bool HasDisclaimer() const { return !CachedRow.RequiredDisclaimer.IsEmpty(); }

	/** Border style token per Doc 20 §6 */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	EGKCodexBorderStyle GetBorderStyle() const { return CachedRow.GetBorderStyle(); }

	/** Linear color code reflecting accessibility requirements (accompanied by explicit text) */
	UFUNCTION(BlueprintPure, Category = "GK|CodexUI")
	FLinearColor GetCategoryThemeColor() const;

private:
	UPROPERTY()
	FGKEvidenceRow CachedRow;
};
