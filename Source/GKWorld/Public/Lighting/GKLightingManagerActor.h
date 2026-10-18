#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lighting/GKLightingTypes.h"
#include "GKLightingManagerActor.generated.h"

class UDirectionalLightComponent;
class USkyLightComponent;
class UExponentialHeightFogComponent;
class UPostProcessComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKLightingConditionChanged, EGKLightingCondition, NewCondition);

/**
 * Level actor managing motivated lighting conditions per Doc 34 and Art Direction Doc 17 §5.
 * Calibrates solar angle, color temperature (Kelvin), Lumen GI exposure,
 * and atmospheric fog for each narrative condition and time-of-day.
 */
UCLASS()
class GKWORLD_API AGKLightingManagerActor : public AActor
{
	GENERATED_BODY()

public:
	AGKLightingManagerActor();

	/** Applies a motivated lighting condition immediately */
	UFUNCTION(BlueprintCallable, Category = "GK|Lighting")
	void ApplyLightingCondition(EGKLightingCondition Condition);

	/** Retrieves the currently active condition */
	UFUNCTION(BlueprintPure, Category = "GK|Lighting")
	EGKLightingCondition GetCurrentCondition() const { return ActiveCondition; }

	/** Retrieves the calibrated preset definition for a condition */
	UFUNCTION(BlueprintPure, Category = "GK|Lighting")
	FGKLightingPreset GetPreset(EGKLightingCondition Condition) const;

	UPROPERTY(BlueprintAssignable, Category = "GK|Lighting")
	FOnGKLightingConditionChanged OnLightingConditionChanged;

	/** Active narrative lighting condition */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	EGKLightingCondition ActiveCondition;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Lighting")
	TObjectPtr<UDirectionalLightComponent> SunDirectionalLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Lighting")
	TObjectPtr<USkyLightComponent> SkyLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Lighting")
	TObjectPtr<UExponentialHeightFogComponent> AtmosphericFog;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Lighting")
	TObjectPtr<UPostProcessComponent> PostProcessVolume;

private:
	UPROPERTY(Transient)
	TMap<EGKLightingCondition, FGKLightingPreset> ConfiguredPresets;

	void InitializePresets();
	void ApplyPreset(const FGKLightingPreset& Preset);
};
