#pragma once

#include "CoreMinimal.h"
#include "GKLightingTypes.generated.h"

/**
 * Motivated lighting conditions matching Doc 34 §1 and Art Direction Bible Doc 17 §5.
 * Strictly adheres to Hard Rule 5: Physically motivated in-world light sources only.
 */
UENUM(BlueprintType)
enum class EGKLightingCondition : uint8
{
	Dawn               UMETA(DisplayName = "Dawn (Low Warm Directional, Mist, Golden Caps)"),
	Morning            UMETA(DisplayName = "Morning (Clean Warm Light, Crisp Stone Shadows)"),
	Noon               UMETA(DisplayName = "Noon (Harsh High Contrast, Active Construction Dust)"),
	Afternoon          UMETA(DisplayName = "Afternoon (Warm Lengthening Shadows)"),
	Sunset             UMETA(DisplayName = "Sunset (Strong Gold Accent on Temple Silhouette)"),
	Night              UMETA(DisplayName = "Night (Moonlight & In-World Oil Lamps/Torches)"),
	Monsoon            UMETA(DisplayName = "Monsoon (Soft Diffuse Cool, Desaturated Rain-Slick)"),
	Act4GangaOvercast  UMETA(DisplayName = "Act 4 The Ganga (Deliberate Flat Overcast Restraint)")
};

/**
 * Physically calibrated parameters for a motivated lighting scenario.
 */
USTRUCT(BlueprintType)
struct GKWORLD_API FGKLightingPreset
{
	GENERATED_BODY()

	FGKLightingPreset()
		: Condition(EGKLightingCondition::Noon)
		, SunIntensityLux(75000.0f)
		, SunColorTempKelvin(5800.0f)
		, SunLightColor(FLinearColor(1.0f, 0.98f, 0.95f))
		, SunRotation(FRotator(-60.0f, 45.0f, 0.0f))
		, SkyLightIntensity(1.0f)
		, FogDensity(0.02f)
		, FogHeightFalloff(0.2f)
		, ExposureCompensation(0.0f)
		, bEnforceGoldAccentOnly(true)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	EGKLightingCondition Condition;

	/** Direct solar illuminance in Lux */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float SunIntensityLux;

	/** Blackbody color temperature in Kelvin (Doc 34) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float SunColorTempKelvin;

	/** Sun tint color */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	FLinearColor SunLightColor;

	/** Sun angle in the sky */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	FRotator SunRotation;

	/** Indirect sky illuminance multiplier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float SkyLightIntensity;

	/** Atmospheric mist/dust density */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float FogDensity;

	/** Atmospheric fog height falloff rate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float FogHeightFalloff;

	/** EV100 exposure adjustment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	float ExposureCompensation;

	/** True enforces Doc 17 §8: Gold is a material accent, never an ambient color wash */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Lighting")
	bool bEnforceGoldAccentOnly;
};
