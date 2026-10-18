#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Stealth/GKStealthTypes.h"
#include "GKStealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKSuspicionStateChanged, EGKSuspicionState, OldState, EGKSuspicionState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKSuspicionMeterChanged, float, NormalizedSuspicion);

/**
 * Perception and graduated suspicion component attached to guards and hostile NPCs (Doc 11 §1–§5).
 * Modulated by line-of-sight, lighting shadows, social crowd-blending, and disguise role.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKEXPLORATION_API UGKStealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKStealthComponent();

	/** Updates suspicion meter based on perception factors */
	UFUNCTION(BlueprintCallable, Category = "GK|Stealth")
	void ProcessPerception(float DeltaTime, bool bHasLineOfSight, float DistanceToPlayer, bool bIsPlayerCrowdBlending, EGKDisguiseRole PlayerDisguise);

	/** Current suspicion state */
	UFUNCTION(BlueprintPure, Category = "GK|Stealth")
	EGKSuspicionState GetSuspicionState() const { return CurrentState; }

	/** Suspicion meter ratio (0.0 to 1.0) */
	UFUNCTION(BlueprintPure, Category = "GK|Stealth")
	float GetSuspicionNormalized() const { return CurrentSuspicion / 100.0f; }

	/** Role-based access level required to enter this guard's post without suspicion */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Stealth")
	EGKDisguiseRole AllowedDisguiseRole;

	/** Rate at which suspicion builds per second at standard detection range */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Stealth")
	float SuspicionBuildRate;

	/** Rate at which suspicion decays when out of sight */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Stealth")
	float SuspicionDecayRate;

	/** Maximum visual detection distance in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Stealth")
	float SightRange;

	UPROPERTY(BlueprintAssignable, Category = "GK|Stealth")
	FOnGKSuspicionStateChanged OnSuspicionStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "GK|Stealth")
	FOnGKSuspicionMeterChanged OnSuspicionMeterChanged;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Stealth")
	EGKSuspicionState CurrentState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Stealth")
	float CurrentSuspicion;

private:
	void TransitionState(EGKSuspicionState NewState);
};
