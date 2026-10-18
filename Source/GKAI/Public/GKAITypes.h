#pragma once

#include "CoreMinimal.h"
#include "GKCoreTypes.h"
#include "GKAITypes.generated.h"

/**
 * 4-phase daily living cycle governing NPC routines (Doc 13 §3).
 */
UENUM(BlueprintType)
enum class EGKTimeOfDay : uint8
{
	Morning   UMETA(DisplayName = "Morning (06:00 - 12:00)"),
	Afternoon UMETA(DisplayName = "Afternoon (12:00 - 17:00)"),
	Evening   UMETA(DisplayName = "Evening (17:00 - 21:00)"),
	Night     UMETA(DisplayName = "Night (21:00 - 06:00)")
};

/**
 * Primitive living world behavior states (Doc 13 §5).
 */
UENUM(BlueprintType)
enum class EGKNPCBehaviorState : uint8
{
	Idle          UMETA(DisplayName = "Idle"),
	Work          UMETA(DisplayName = "Work / Craft"),
	Travel        UMETA(DisplayName = "Travel / Patrol"),
	Eat           UMETA(DisplayName = "Eat / Mess"),
	Socialize     UMETA(DisplayName = "Socialize / Converse"),
	Guard         UMETA(DisplayName = "Guard / Watch"),
	Sleep         UMETA(DisplayName = "Sleep / Rest"),
	ReactToPlayer UMETA(DisplayName = "React to Player")
};

/**
 * An individual scheduled activity within an NPC's daily routine (Doc 13 §1 & §3).
 */
USTRUCT(BlueprintType)
struct GKAI_API FGKScheduleActivity
{
	GENERATED_BODY()

	FGKScheduleActivity()
		: TimeOfDay(EGKTimeOfDay::Morning)
		, Behavior(EGKNPCBehaviorState::Work)
		, TargetLocationTag(NAME_None)
		, TargetCoordinates(FVector::ZeroVector)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	EGKTimeOfDay TimeOfDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	EGKNPCBehaviorState Behavior;

	/** Actor or marker tag representing the workstation or destination in the world */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	FName TargetLocationTag;

	/** World destination coordinates (if no actor tag) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	FVector TargetCoordinates;

	/** Ambient dialogue bark spoken while engaged in this activity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	FText ActivityBark;
};

/**
 * Full daily routine definition for an NPC (Doc 13 §1).
 */
USTRUCT(BlueprintType)
struct GKAI_API FGKNPCSchedule
{
	GENERATED_BODY()

	FGKNPCSchedule()
		: NPCID(NAME_None)
		, PopulationTier(EGKPopulationTier::Tier1_Named)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	FName NPCID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	EGKPopulationTier PopulationTier;

	/** Four activities corresponding to Morning, Afternoon, Evening, Night */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	TArray<FGKScheduleActivity> Activities;

	/** Retrieves the scheduled activity for a given time of day */
	bool GetActivityForTimeOfDay(EGKTimeOfDay TimeOfDay, FGKScheduleActivity& OutActivity) const
	{
		for (const FGKScheduleActivity& Act : Activities)
		{
			if (Act.TimeOfDay == TimeOfDay)
			{
				OutActivity = Act;
				return true;
			}
		}
		return false;
	}
};
