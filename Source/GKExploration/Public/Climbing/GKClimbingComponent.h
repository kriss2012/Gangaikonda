#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Climbing/GKScaffoldVolume.h"
#include "GKClimbingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClimbStateChanged, bool, bIsClimbing);

/**
 * Handles character attachment, vertical ascension/descension, and ledge mantling on scaffold volumes (Doc 01 §11, Doc 29).
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKEXPLORATION_API UGKClimbingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKClimbingComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Attempts to attach to a nearby scaffold volume */
	UFUNCTION(BlueprintCallable, Category = "GK|Climbing")
	bool TryStartClimb();

	/** Move along climb surface (positive = ascend, negative = descend) */
	UFUNCTION(BlueprintCallable, Category = "GK|Climbing")
	void ClimbVertical(float InputValue);

	/** Exits climbing mode, optionally performing a mantle onto the top ledge */
	UFUNCTION(BlueprintCallable, Category = "GK|Climbing")
	void StopClimb(bool bDismountAtLedge = false);

	/** Returns true if character is actively attached to a scaffold */
	UFUNCTION(BlueprintPure, Category = "GK|Climbing")
	bool IsClimbing() const { return bIsClimbing; }

	/** Current scaffold volume being traversed */
	UFUNCTION(BlueprintPure, Category = "GK|Climbing")
	AGKScaffoldVolume* GetCurrentScaffold() const { return CurrentScaffold.Get(); }

	UPROPERTY(BlueprintAssignable, Category = "GK|Climbing")
	FOnClimbStateChanged OnClimbStateChanged;

	/** Climbing vertical speed in cm/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Climbing")
	float ClimbSpeed;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Climbing")
	bool bIsClimbing;

	UPROPERTY()
	TWeakObjectPtr<AGKScaffoldVolume> CurrentScaffold;

	UPROPERTY()
	TObjectPtr<ACharacter> OwnerCharacter;

private:
	AGKScaffoldVolume* FindNearbyScaffold() const;
};
