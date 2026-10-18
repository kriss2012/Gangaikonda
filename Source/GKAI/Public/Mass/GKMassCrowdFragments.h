#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "GKAITypes.h"
#include "GKMassCrowdFragments.generated.h"

/**
 * Mass Entity fragment for Tier 3 background population (Doc 13 §2, Doc 18 §2).
 * Operates with cache-coherent batch processing (consuming ~24 bytes per entity).
 */
USTRUCT()
struct GKAI_API FGKCrowdMemberFragment : public FMassFragment
{
	GENERATED_BODY()

	FGKCrowdMemberFragment()
		: CurrentBehavior(EGKNPCBehaviorState::Work)
		, CurrentTimeOfDay(EGKTimeOfDay::Morning)
		, TargetWorkstationLocation(FVector::ZeroVector)
		, MovementSpeed(180.0f)
	{
	}

	UPROPERTY(EditAnywhere, Category = "GK|MassCrowd")
	EGKNPCBehaviorState CurrentBehavior;

	UPROPERTY(EditAnywhere, Category = "GK|MassCrowd")
	EGKTimeOfDay CurrentTimeOfDay;

	UPROPERTY(EditAnywhere, Category = "GK|MassCrowd")
	FVector TargetWorkstationLocation;

	UPROPERTY(EditAnywhere, Category = "GK|MassCrowd")
	float MovementSpeed;
};
