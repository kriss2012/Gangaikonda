#pragma once

#include "CoreMinimal.h"
#include "GKWorldTypes.generated.h"

/**
 * Monumental temple construction progression milestones (Doc 02, Doc 13 §5, Doc 19 §3).
 * Governs visual scaffolding, asset swapping, and NPC working dialog.
 */
UENUM(BlueprintType)
enum class EGKConstructionStage : uint8
{
	FoundationExcavation UMETA(DisplayName = "1. Foundation Trench & Drainage Channels"),
	LowerGraniteCourses  UMETA(DisplayName = "2. Lower Plinth & Garbhagriha Courses"),
	ScaffoldingVimanaMid UMETA(DisplayName = "3. Mid-Vimana Scaffolding Lattice (Vertical Slice)"),
	UpperVimanaCapstone  UMETA(DisplayName = "4. Upper Courses & Capstone Hoist"),
	CompletedSanctuary   UMETA(DisplayName = "5. Consecrated Living Temple")
};

/**
 * Non-numeric faction reputation standing (Doc 01 §23, Doc 14).
 * Governs NPC trust, witness disclosure, and guard suspicion baselines.
 */
UENUM(BlueprintType)
enum class EGKFactionReputation : uint8
{
	Hostile    UMETA(DisplayName = "Hostile"),
	Distrusted UMETA(DisplayName = "Distrusted"),
	Neutral    UMETA(DisplayName = "Neutral"),
	Respected  UMETA(DisplayName = "Respected"),
	Honored    UMETA(DisplayName = "Honored")
};
