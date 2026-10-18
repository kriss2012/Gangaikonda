#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GKScaffoldVolume.generated.h"

/**
 * Climbable bamboo and timber scaffolding volume typical of Chola monumental construction (Doc 29).
 * Defines vertical climb planes and exit ledges for traversal.
 */
UCLASS(BlueprintType)
class GKEXPLORATION_API AGKScaffoldVolume : public AActor
{
	GENERATED_BODY()

public:
	AGKScaffoldVolume();

	/** Box component marking the volume of the climbable scaffold */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Scaffold")
	TObjectPtr<UBoxComponent> ClimbTriggerBox;

	/** Outward facing normal vector representing the direction the character faces while climbing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Scaffold")
	FVector ClimbFacingNormal;

	/** Height of the top exit ledge in local space */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Scaffold")
	float TopLedgeHeight;

	/** Returns true if character location is within acceptable vertical climbing bounds */
	UFUNCTION(BlueprintPure, Category = "GK|Scaffold")
	bool IsWithinClimbBounds(const FVector& WorldLocation) const;

	/** Returns the world position of the top exit ledge */
	UFUNCTION(BlueprintPure, Category = "GK|Scaffold")
	FVector GetTopLedgeWorldLocation() const;

	/** Returns the world position of the bottom entry point */
	UFUNCTION(BlueprintPure, Category = "GK|Scaffold")
	FVector GetBottomEntryWorldLocation() const;
};
