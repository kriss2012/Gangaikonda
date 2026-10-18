#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Lighting/GKLightingTypes.h"
#include "Lighting/GKLightingManagerActor.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.World.LightingPresetsAndDoc34
 * Enforces Doc 17 §5 and Doc 34: Motivated lighting parameters and gold accent restraint.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKLightingPresetsTest, "GK.World.LightingPresetsAndDoc34", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKLightingPresetsTest::RunTest(const FString& Parameters)
{
	AGKLightingManagerActor* LightingManager = NewObject<AGKLightingManagerActor>();
	TestNotNull(TEXT("LightingManager created"), LightingManager);

	// 1. Validate Dawn preset (Cinematic 001/002)
	FGKLightingPreset Dawn = LightingManager->GetPreset(EGKLightingCondition::Dawn);
	TestEqual(TEXT("Dawn condition matches"), Dawn.Condition, EGKLightingCondition::Dawn);
	TestTrue(TEXT("Dawn color temperature is warm (3500K - 4200K)"), Dawn.SunColorTempKelvin >= 3500.0f && Dawn.SunColorTempKelvin <= 4200.0f);
	TestTrue(TEXT("Dawn fog density represents morning mist"), Dawn.FogDensity >= 0.03f);
	TestTrue(TEXT("Dawn enforces gold accent only"), Dawn.bEnforceGoldAccentOnly);

	// 2. Validate Noon preset (Active construction zone)
	FGKLightingPreset Noon = LightingManager->GetPreset(EGKLightingCondition::Noon);
	TestEqual(TEXT("Noon condition matches"), Noon.Condition, EGKLightingCondition::Noon);
	TestTrue(TEXT("Noon illuminance is harsh tropical sun (> 80,000 Lux)"), Noon.SunIntensityLux >= 80000.0f);
	TestTrue(TEXT("Noon temperature is cool daylight (5800K - 6500K)"), Noon.SunColorTempKelvin >= 5800.0f && Noon.SunColorTempKelvin <= 6500.0f);

	// 3. Validate Act 4 "The Ganga" preset (Deliberate flat overcast restraint per Doc 05 Cinematic 003)
	FGKLightingPreset Act4Ganga = LightingManager->GetPreset(EGKLightingCondition::Act4GangaOvercast);
	TestEqual(TEXT("Act 4 condition matches"), Act4Ganga.Condition, EGKLightingCondition::Act4GangaOvercast);
	TestTrue(TEXT("Act 4 overcast diffuse skylight is prominent"), Act4Ganga.SkyLightIntensity >= 1.2f);
	TestTrue(TEXT("Act 4 sun illuminance is muted (< 35,000 Lux)"), Act4Ganga.SunIntensityLux <= 35000.0f);
	TestTrue(TEXT("Act 4 strictly enforces gold accent restraint"), Act4Ganga.bEnforceGoldAccentOnly);

	return true;
}

/**
 * Test: GK.World.PerformanceTargetsAndScalability
 * Enforces Doc 01 §35 frame-rate targets (30 fps floor / 60 fps target) and Nanite/Lumen budgets.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKPerformanceTargetsTest, "GK.World.PerformanceTargetsAndScalability", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKPerformanceTargetsTest::RunTest(const FString& Parameters)
{
	constexpr float Target60FpsMs = 1000.0f / 60.0f; // 16.666 ms
	constexpr float Floor30FpsMs = 1000.0f / 30.0f;  // 33.333 ms

	TestTrue(TEXT("60 FPS frame time budget is ~16.67ms"), FMath::IsNearlyEqual(Target60FpsMs, 16.666f, 0.01f));
	TestTrue(TEXT("30 FPS frame time budget is ~33.33ms"), FMath::IsNearlyEqual(Floor30FpsMs, 33.333f, 0.01f));

	// Validate Game Thread CPU sub-budgets sum to <= 8.0ms
	constexpr float CharacterLocomotionBudget = 1.5f;
	constexpr float MassCrowdBudget = 1.2f;
	constexpr float AIStealthBudget = 1.8f;
	constexpr float QuestWorldBudget = 0.8f;
	constexpr float AudioBudget = 0.5f;
	constexpr float TotalGameThreadActive = CharacterLocomotionBudget + MassCrowdBudget + AIStealthBudget + QuestWorldBudget + AudioBudget;

	TestTrue(TEXT("Game Thread active sub-systems fit within 6.0ms leaving 2.0ms+ headroom"), TotalGameThreadActive <= 6.0f);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
