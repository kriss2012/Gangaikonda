#pragma once

#include "CoreMinimal.h"
#include "GKCoreTypes.h"
#include "GKQuestTypes.generated.h"

/**
 * Lifecycle states of an overall quest.
 */
UENUM(BlueprintType)
enum class EGKQuestState : uint8
{
	NotStarted UMETA(DisplayName = "Not Started"),
	InProgress UMETA(DisplayName = "In Progress"),
	Completed  UMETA(DisplayName = "Completed"),
	Failed     UMETA(DisplayName = "Failed")
};

/**
 * Status of an individual objective within a quest.
 */
UENUM(BlueprintType)
enum class EGKObjectiveState : uint8
{
	Inactive  UMETA(DisplayName = "Inactive"),
	Active    UMETA(DisplayName = "Active"),
	Completed UMETA(DisplayName = "Completed"),
	Failed    UMETA(DisplayName = "Failed")
};

/**
 * A single objective in a quest's progression graph (Doc 07 / Doc 18 §3).
 */
USTRUCT(BlueprintType)
struct GKQUEST_API FGKQuestObjective
{
	GENERATED_BODY()

	FGKQuestObjective()
		: ObjectiveID(NAME_None)
		, State(EGKObjectiveState::Inactive)
		, bIsOptional(false)
		, TriggerTag(NAME_None)
	{
	}

	/** Unique alphanumeric objective key */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Quest")
	FName ObjectiveID;

	/** User-facing journal description of the objective */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Quest")
	FText Description;

	/** Current status */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	EGKObjectiveState State;

	/** True if this is an optional investigation or secondary task */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Quest")
	bool bIsOptional;

	/** Gameplay event tag or trigger that satisfies this objective */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Quest")
	FName TriggerTag;
};
