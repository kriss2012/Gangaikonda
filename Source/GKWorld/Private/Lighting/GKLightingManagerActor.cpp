#include "Lighting/GKLightingManagerActor.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "GKLogChannels.h"

AGKLightingManagerActor::AGKLightingManagerActor()
	: ActiveCondition(EGKLightingCondition::Noon)
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(RootComp);

	SunDirectionalLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("SunDirectionalLight"));
	SunDirectionalLight->SetupAttachment(RootComp);
	SunDirectionalLight->bUseTemperature = true;

	SkyLight = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
	SkyLight->SetupAttachment(RootComp);

	AtmosphericFog = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("AtmosphericFog"));
	AtmosphericFog->SetupAttachment(RootComp);

	PostProcessVolume = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcessVolume"));
	PostProcessVolume->SetupAttachment(RootComp);
	PostProcessVolume->bUnbound = true;

	InitializePresets();
}

void AGKLightingManagerActor::BeginPlay()
{
	Super::BeginPlay();
	ApplyLightingCondition(ActiveCondition);
}

void AGKLightingManagerActor::InitializePresets()
{
	ConfiguredPresets.Empty();

	// 1. Dawn (Doc 34: Low warm directional, mist, golden temple tops, Cinematic 001/002)
	FGKLightingPreset Dawn;
	Dawn.Condition = EGKLightingCondition::Dawn;
	Dawn.SunIntensityLux = 28000.0f;
	Dawn.SunColorTempKelvin = 3800.0f; // Warm dawn
	Dawn.SunLightColor = FLinearColor(1.0f, 0.88f, 0.72f);
	Dawn.SunRotation = FRotator(-12.0f, 75.0f, 0.0f);
	Dawn.SkyLightIntensity = 0.8f;
	Dawn.FogDensity = 0.045f; // Morning mist
	Dawn.FogHeightFalloff = 0.15f;
	Dawn.ExposureCompensation = 0.5f;
	Dawn.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Dawn.Condition, Dawn);

	// 2. Morning (Doc 34: Clean warm light, crisp stone shadows)
	FGKLightingPreset Morning;
	Morning.Condition = EGKLightingCondition::Morning;
	Morning.SunIntensityLux = 60000.0f;
	Morning.SunColorTempKelvin = 4900.0f;
	Morning.SunLightColor = FLinearColor(1.0f, 0.95f, 0.88f);
	Morning.SunRotation = FRotator(-35.0f, 60.0f, 0.0f);
	Morning.SkyLightIntensity = 1.0f;
	Morning.FogDensity = 0.02f;
	Morning.FogHeightFalloff = 0.2f;
	Morning.ExposureCompensation = 0.0f;
	Morning.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Morning.Condition, Morning);

	// 3. Noon (Doc 34: Harsh high contrast, active construction dust haze, deep shadows)
	FGKLightingPreset Noon;
	Noon.Condition = EGKLightingCondition::Noon;
	Noon.SunIntensityLux = 95000.0f;
	Noon.SunColorTempKelvin = 6200.0f; // Harsh tropical sun
	Noon.SunLightColor = FLinearColor(1.0f, 0.99f, 0.96f);
	Noon.SunRotation = FRotator(-78.0f, 25.0f, 0.0f);
	Noon.SkyLightIntensity = 1.2f;
	Noon.FogDensity = 0.025f; // Quarry and stone carving dust
	Noon.FogHeightFalloff = 0.25f;
	Noon.ExposureCompensation = -0.5f;
	Noon.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Noon.Condition, Noon);

	// 4. Sunset (Doc 34: Strong gold accent on temple silhouette, used for earned reveals)
	FGKLightingPreset Sunset;
	Sunset.Condition = EGKLightingCondition::Sunset;
	Sunset.SunIntensityLux = 32000.0f;
	Sunset.SunColorTempKelvin = 3200.0f; // Deep amber
	Sunset.SunLightColor = FLinearColor(1.0f, 0.75f, 0.5f);
	Sunset.SunRotation = FRotator(-8.0f, -80.0f, 0.0f);
	Sunset.SkyLightIntensity = 0.7f;
	Sunset.FogDensity = 0.03f;
	Sunset.FogHeightFalloff = 0.18f;
	Sunset.ExposureCompensation = 0.3f;
	Sunset.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Sunset.Condition, Sunset);

	// 5. Night (Doc 34: In-world oil lamps, torches, moonlight; stealth readability Doc 11)
	FGKLightingPreset Night;
	Night.Condition = EGKLightingCondition::Night;
	Night.SunIntensityLux = 0.25f; // Pure moonlight
	Night.SunColorTempKelvin = 6800.0f; // Cool moon tint
	Night.SunLightColor = FLinearColor(0.6f, 0.75f, 1.0f);
	Night.SunRotation = FRotator(-60.0f, -120.0f, 0.0f);
	Night.SkyLightIntensity = 0.3f;
	Night.FogDensity = 0.015f;
	Night.FogHeightFalloff = 0.3f;
	Night.ExposureCompensation = 1.5f;
	Night.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Night.Condition, Night);

	// 6. Act 4 "The Ganga" (Doc 05 Cinematic 003 & Doc 34: Flat, unglamorous overcast restraint)
	FGKLightingPreset Act4Ganga;
	Act4Ganga.Condition = EGKLightingCondition::Act4GangaOvercast;
	Act4Ganga.SunIntensityLux = 22000.0f;
	Act4Ganga.SunColorTempKelvin = 5600.0f; // Neutral overcast grey
	Act4Ganga.SunLightColor = FLinearColor(0.9f, 0.9f, 0.92f);
	Act4Ganga.SunRotation = FRotator(-50.0f, 0.0f, 0.0f);
	Act4Ganga.SkyLightIntensity = 1.5f; // Diffuse omnidirectional sky dome
	Act4Ganga.FogDensity = 0.04f;
	Act4Ganga.FogHeightFalloff = 0.1f;
	Act4Ganga.ExposureCompensation = 0.0f;
	Act4Ganga.bEnforceGoldAccentOnly = true;
	ConfiguredPresets.Add(Act4Ganga.Condition, Act4Ganga);
}

void AGKLightingManagerActor::ApplyLightingCondition(EGKLightingCondition Condition)
{
	ActiveCondition = Condition;
	if (const FGKLightingPreset* Found = ConfiguredPresets.Find(Condition))
	{
		ApplyPreset(*Found);
		UE_LOG(LogGKWorld, Log, TEXT("Motivated lighting scenario applied: [%d]. Sun Lux: %.0f, Temp: %.0fK"),
			static_cast<int32>(Condition), Found->SunIntensityLux, Found->SunColorTempKelvin);
		OnLightingConditionChanged.Broadcast(Condition);
	}
	else
	{
		UE_LOG(LogGKWorld, Warning, TEXT("Lighting condition [%d] not found in preset registry."), static_cast<int32>(Condition));
	}
}

void AGKLightingManagerActor::ApplyPreset(const FGKLightingPreset& Preset)
{
	if (SunDirectionalLight)
	{
		SunDirectionalLight->SetIntensity(Preset.SunIntensityLux);
		SunDirectionalLight->SetTemperature(Preset.SunColorTempKelvin);
		SunDirectionalLight->SetLightColor(Preset.SunLightColor);
		SunDirectionalLight->SetWorldRotation(Preset.SunRotation);
	}

	if (SkyLight)
	{
		SkyLight->SetIntensity(Preset.SkyLightIntensity);
	}

	if (AtmosphericFog)
	{
		AtmosphericFog->SetDensity(Preset.FogDensity);
		AtmosphericFog->SetHeightFalloff(Preset.FogHeightFalloff);
	}

	if (PostProcessVolume)
	{
		PostProcessVolume->Settings.bOverride_AutoExposureBias = true;
		PostProcessVolume->Settings.AutoExposureBias = Preset.ExposureCompensation;

		// Enforce Doc 17 §8: Gold is a material accent, never an ambient color wash.
		// Restrict bloom convolution wash.
		PostProcessVolume->Settings.bOverride_BloomIntensity = true;
		PostProcessVolume->Settings.BloomIntensity = 0.35f;
	}
}

FGKLightingPreset AGKLightingManagerActor::GetPreset(EGKLightingCondition Condition) const
{
	if (const FGKLightingPreset* Found = ConfiguredPresets.Find(Condition))
	{
		return *Found;
	}
	return FGKLightingPreset();
}
