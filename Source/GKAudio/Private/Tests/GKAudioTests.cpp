#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKAudioTypes.h"
#include "GKAudioSubsystem.h"
#include "Cinematics/GKCinematicTriggerComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Audio.SoundscapeTransitionsAndWater
 * Validates dynamic soundscapes and distinct water acoustics per Doc 21 §1.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKSoundscapeTransitionTest, "GK.Audio.SoundscapeTransitionsAndWater", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKSoundscapeTransitionTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance created"), GameInstance);

	UGKAudioSubsystem* AudioSubsystem = NewObject<UGKAudioSubsystem>(GameInstance);
	TestNotNull(TEXT("AudioSubsystem created"), AudioSubsystem);

	AudioSubsystem->Initialize(*static_cast<FSubsystemCollectionBase*>(nullptr));

	// 1. Initial State: Zone 5 Construction site
	const FGKSoundscapeDefinition& InitialScape = AudioSubsystem->GetCurrentSoundscape();
	TestEqual(TEXT("Initial soundscape is Zone 5"), InitialScape.SoundscapeID, FName(TEXT("Zone5_Gangaikonda")));
	TestEqual(TEXT("Initial category is City"), InitialScape.PrimaryCategory, EGKAmbientSoundCategory::City);
	TestTrue(TEXT("High construction noise intensity"), InitialScape.ConstructionIntensity > 0.8f);

	// 2. Transition to Lion Well Subterranean Hydraulic Chamber
	AudioSubsystem->SetSoundscape(TEXT("Zone5_LionWell"));
	const FGKSoundscapeDefinition& LionWellScape = AudioSubsystem->GetCurrentSoundscape();
	TestEqual(TEXT("Soundscape is Lion Well"), LionWellScape.SoundscapeID, FName(TEXT("Zone5_LionWell")));
	TestEqual(TEXT("Category is Water"), LionWellScape.PrimaryCategory, EGKAmbientSoundCategory::Water);
	TestEqual(TEXT("Water acoustic type is CanalSluice"), LionWellScape.WaterType, EGKWaterAcousticType::CanalSluice);
	TestTrue(TEXT("High stone reverb decay in subterranean well"), LionWellScape.ReverbDecaySeconds >= 3.0f);

	// 3. Dynamic construction intensity adjustment
	AudioSubsystem->SetConstructionAcousticIntensity(0.45f);
	TestEqual(TEXT("Construction intensity updated"), AudioSubsystem->GetCurrentSoundscape().ConstructionIntensity, 0.45f);

	return true;
}

/**
 * Test: GK.Audio.ScoreRestraintRule
 * Enforces Doc 21 §3: Everyday exploration leans on diegetic ambience.
 * Music swells are suppressed unless explicitly earned via story milestones or landmark reveals.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKScoreRestraintTest, "GK.Audio.ScoreRestraintRule", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKScoreRestraintTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	UGKAudioSubsystem* AudioSubsystem = NewObject<UGKAudioSubsystem>(GameInstance);

	// 1. Initially score is restrained
	TestTrue(TEXT("Score is initially restrained to silence"), AudioSubsystem->IsScoreRestrained());
	TestEqual(TEXT("Active theme is None"), AudioSubsystem->GetCurrentTheme(), EGKMusicTheme::None);

	// 2. Attempt unearned music swell during routine exploration: must be suppressed per Doc 21 §3
	bool bTriggeredUnearned = AudioSubsystem->TriggerMusicCue(EGKMusicTheme::CapitalTheme, false);
	TestFalse(TEXT("Unearned music cue is suppressed"), bTriggeredUnearned);
	TestTrue(TEXT("Score remains restrained"), AudioSubsystem->IsScoreRestrained());

	// 3. Trigger earned music swell upon major landmark reveal: must succeed
	bool bTriggeredEarned = AudioSubsystem->TriggerMusicCue(EGKMusicTheme::CapitalTheme, true);
	TestTrue(TEXT("Earned music swell succeeds"), bTriggeredEarned);
	TestFalse(TEXT("Score is now playing earned theme"), AudioSubsystem->IsScoreRestrained());
	TestEqual(TEXT("Current theme is Capital Theme"), AudioSubsystem->GetCurrentTheme(), EGKMusicTheme::CapitalTheme);

	// 4. Return to diegetic exploration ambience
	AudioSubsystem->StopMusicCue();
	TestTrue(TEXT("Score returns to diegetic restraint"), AudioSubsystem->IsScoreRestrained());

	return true;
}

/**
 * Test: GK.Audio.CinematicTriggerAndHandoff
 * Validates Doc 05 cinematic execution, pre-text cards, and seamless completion handoff.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCinematicTriggerTest, "GK.Audio.CinematicTriggerAndHandoff", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCinematicTriggerTest::RunTest(const FString& Parameters)
{
	UGKCinematicTriggerComponent* TriggerComp = NewObject<UGKCinematicTriggerComponent>();
	TestNotNull(TEXT("TriggerComp created"), TriggerComp);

	TriggerComp->CinematicID = TEXT("CIN_003_TheGanga");
	TriggerComp->PreTextCard = FText::FromString(TEXT("INSPIRED BY THE HISTORICAL EXPEDITION"));
	TriggerComp->PreTextCardDuration = 2.0f;
	TriggerComp->AssociatedMusicTheme = EGKMusicTheme::GangaTheme;
	TriggerComp->bSeamlessGameplayHandoff = false; // Hard cut per Doc 05 Act 4

	TestFalse(TEXT("Initially not playing"), TriggerComp->IsPlaying());

	// Start cinematic
	bool bStarted = TriggerComp->TriggerCinematic(nullptr);
	TestTrue(TEXT("Cinematic playback initiated"), bStarted);
	TestTrue(TEXT("IsPlaying is true"), TriggerComp->IsPlaying());

	// Complete cinematic
	TriggerComp->CompleteCinematic();
	TestFalse(TEXT("IsPlaying is false after completion"), TriggerComp->IsPlaying());

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
