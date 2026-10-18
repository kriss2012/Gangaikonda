#pragma once

#include "CoreMinimal.h"
#include "GKPuzzleTypes.generated.h"

/**
 * An individual inscribed fragment/glyph on a temple stone or copper plate (Doc 09 P10).
 */
USTRUCT(BlueprintType)
struct FGKInscriptionFragment
{
	GENERATED_BODY()

	FGKInscriptionFragment()
		: FragmentID(0)
		, bIsDamaged(false)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	int32 FragmentID;

	/** The script symbol / ligature (Grantha or Chola Tamil paleographic script) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText PaleographicGlyph;

	/** Phonetic transliteration / reading */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText Transliteration;

	/** Translated English meaning */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText MeaningTranslation;

	/** True if erosion or chisel marks require reference chart comparison */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	bool bIsDamaged;
};

/**
 * Scholar's Reference Chart entry used in Inscription Decoding Tier 1 (Doc 09 P10, Doc 20 §7).
 * Presented as an in-world parchment document from the Scholar's archive tent.
 */
USTRUCT(BlueprintType)
struct FGKScholarReferenceEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|ScholarChart")
	FText ScriptSymbol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|ScholarChart")
	FText PeriodClassification;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|ScholarChart")
	FText PhoneticKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|ScholarChart")
	FText HistoricalNotes;
};
