#pragma once

#include "CoreMinimal.h"
#include "GKCoreTypes.generated.h"

/**
 * Historical evidence categories governing every historical claim in the game.
 * Rule: Fictional elements are strictly labeled and never upgraded to Documented.
 */
UENUM(BlueprintType)
enum class EGKEvidenceCategory : uint8
{
	Documented              UMETA(DisplayName = "Documented"),
	PlausibleReconstruction UMETA(DisplayName = "Plausible Reconstruction"),
	Fictional               UMETA(DisplayName = "Fictional")
};

/**
 * Historical confidence levels reflecting evidentiary rigor.
 * Rule: Confidence must never be upgraded when moving data from research to player-facing Codex.
 */
UENUM(BlueprintType)
enum class EGKConfidence : uint8
{
	Known     UMETA(DisplayName = "Known"),
	Likely    UMETA(DisplayName = "Likely"),
	Uncertain UMETA(DisplayName = "Uncertain"),
	Unknown   UMETA(DisplayName = "Unknown")
};

/**
 * Population tiers reconciling living-world density with production and technical feasibility (Doc 13 §2).
 */
UENUM(BlueprintType)
enum class EGKPopulationTier : uint8
{
	Tier1_Named      UMETA(DisplayName = "Tier 1 - Named (Hand-Authored)"),
	Tier2_SemiNamed  UMETA(DisplayName = "Tier 2 - Semi-Named (Templated)"),
	Tier3_Background UMETA(DisplayName = "Tier 3 - Background (Mass Entity)")
};

/**
 * Generic state of any puzzle actor (Doc 09 & Doc 18 §4).
 */
UENUM(BlueprintType)
enum class EGKPuzzleState : uint8
{
	Unsolved   UMETA(DisplayName = "Unsolved"),
	InProgress UMETA(DisplayName = "In Progress"),
	Solved     UMETA(DisplayName = "Solved"),
	Failed     UMETA(DisplayName = "Failed")
};
