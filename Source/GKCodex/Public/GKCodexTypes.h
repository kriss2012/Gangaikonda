#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GKCoreTypes.h"
#include "GKCodexTypes.generated.h"

/**
 * UI visual border styling according to Doc 20 §6:
 * - Documented: Solid border, full color.
 * - Plausible Reconstruction: Dashed / hatched border.
 * - Fictional: Desaturated treatment with distinct header color.
 */
UENUM(BlueprintType)
enum class EGKCodexBorderStyle : uint8
{
	Solid         UMETA(DisplayName = "Solid (Documented)"),
	DashedHatched UMETA(DisplayName = "Dashed / Hatched (Plausible Reconstruction)"),
	Desaturated   UMETA(DisplayName = "Desaturated (Fictional)")
};

/**
 * Single source of truth for historical claims in GANGAIKONDA.
 * Corresponds to entries in Doc 03 and Doc 10 research bibles.
 * Hard Rule: Historical content lives in Data Tables, never hardcoded strings.
 */
USTRUCT(BlueprintType)
struct GKCODEX_API FGKEvidenceRow : public FTableRowBase
{
	GENERATED_BODY()

	FGKEvidenceRow()
		: EvidenceID(NAME_None)
		, Category(EGKEvidenceCategory::Fictional)
		, Confidence(EGKConfidence::Unknown)
	{
	}

	/** Unique alphanumeric evidence identifier matching Doc 03 (e.g., A1, B2, C1) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FName EvidenceID;

	/** The historical claim or factual statement */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText Claim;

	/** Evidence category: Documented, PlausibleReconstruction, or Fictional */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	EGKEvidenceCategory Category;

	/** Primary historical source or archaeological citation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText Source;

	/** Type of source (e.g., Epigraphic, Archaeological, Foreign Chronicle, Secondary Scholarship) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText SourceType;

	/** Historical date or period (e.g., c. 1023–1025 CE) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText DatePeriod;

	/** Confidence rating: Known, Likely, Uncertain, Unknown */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	EGKConfidence Confidence;

	/** How this evidence connects to gameplay systems or narrative acts */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText GameUsage;

	/** Mandatory disclaimer text for Uncertain/Plausible/Fictional claims */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Historical Evidence")
	FText RequiredDisclaimer;

	/** Resolves the UI border style corresponding to the evidence category */
	EGKCodexBorderStyle GetBorderStyle() const
	{
		switch (Category)
		{
		case EGKEvidenceCategory::Documented:
			return EGKCodexBorderStyle::Solid;
		case EGKEvidenceCategory::PlausibleReconstruction:
			return EGKCodexBorderStyle::DashedHatched;
		case EGKEvidenceCategory::Fictional:
		default:
			return EGKCodexBorderStyle::Desaturated;
		}
	}
};
