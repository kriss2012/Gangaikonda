#include "GKAudioSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GKLogChannels.h"

UGKAudioSubsystem::UGKAudioSubsystem()
	: ActiveTheme(EGKMusicTheme::None)
	, bInCombatMix(false)
{
}

void UGKAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegisterDefaultSoundscapes();

	// Default to Zone 5 Gangaikonda construction soundscape (Doc 08, Doc 21 §1)
	SetSoundscape(TEXT("Zone5_Gangaikonda"));

	UE_LOG(LogGKAudio, Log, TEXT("UGKAudioSubsystem initialized. Score Restraint Rule active."));
}

void UGKAudioSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

UGKAudioSubsystem* UGKAudioSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
	return GameInstance ? GameInstance->GetSubsystem<UGKAudioSubsystem>() : nullptr;
}

void UGKAudioSubsystem::RegisterDefaultSoundscapes()
{
	SoundscapeRegistry.Empty();

	// 1. Zone 5 Construction Site (Doc 21 §1 City: stone dust, chisel work, tool clatter, ox carts)
	FGKSoundscapeDefinition Zone5;
	Zone5.SoundscapeID = TEXT("Zone5_Gangaikonda");
	Zone5.PrimaryCategory = EGKAmbientSoundCategory::City;
	Zone5.WaterType = EGKWaterAcousticType::None;
	Zone5.ConstructionIntensity = 0.85f; // Heavy granite chiseling & scaffolding
	Zone5.CrowdMurmurIntensity = 0.6f;
	Zone5.WindDustIntensity = 0.4f;
	Zone5.ReverbDecaySeconds = 1.2f;
	SoundscapeRegistry.Add(Zone5.SoundscapeID, Zone5);

	// 2. Lion Well Hydraulic Sub-Level (Doc 21 §1 Water: canal sluice flow, subterranean stone echoes)
	FGKSoundscapeDefinition LionWell;
	LionWell.SoundscapeID = TEXT("Zone5_LionWell");
	LionWell.PrimaryCategory = EGKAmbientSoundCategory::Water;
	LionWell.WaterType = EGKWaterAcousticType::CanalSluice;
	LionWell.ConstructionIntensity = 0.15f;
	LionWell.CrowdMurmurIntensity = 0.1f;
	LionWell.WindDustIntensity = 0.05f;
	LionWell.ReverbDecaySeconds = 3.5f; // Deep subterranean stone chamber resonance
	SoundscapeRegistry.Add(LionWell.SoundscapeID, LionWell);

	// 3. Consecrated Temple Sanctuary (Doc 21 §1 Temple: resonant stone footsteps, bells)
	FGKSoundscapeDefinition Temple;
	Temple.SoundscapeID = TEXT("Zone5_Sanctuary");
	Temple.PrimaryCategory = EGKAmbientSoundCategory::Temple;
	Temple.WaterType = EGKWaterAcousticType::None;
	Temple.ConstructionIntensity = 0.0f;
	Temple.CrowdMurmurIntensity = 0.2f;
	Temple.WindDustIntensity = 0.05f;
	Temple.ReverbDecaySeconds = 4.2f;
	SoundscapeRegistry.Add(Temple.SoundscapeID, Temple);

	// 4. Cholagangam Lake Reservoir Margin (Doc 21 §1 Water)
	FGKSoundscapeDefinition Lake;
	Lake.SoundscapeID = TEXT("Zone5_Cholagangam");
	Lake.PrimaryCategory = EGKAmbientSoundCategory::Water;
	Lake.WaterType = EGKWaterAcousticType::Reservoir;
	Lake.ConstructionIntensity = 0.1f;
	Lake.CrowdMurmurIntensity = 0.2f;
	Lake.WindDustIntensity = 0.5f;
	Lake.ReverbDecaySeconds = 0.8f;
	SoundscapeRegistry.Add(Lake.SoundscapeID, Lake);
}

void UGKAudioSubsystem::SetSoundscape(FName SoundscapeID)
{
	if (const FGKSoundscapeDefinition* Found = SoundscapeRegistry.Find(SoundscapeID))
	{
		CurrentSoundscape = *Found;
		UE_LOG(LogGKAudio, Log, TEXT("Soundscape transitioned to [%s]. Construction intensity: %.2f"),
			*SoundscapeID.ToString(), CurrentSoundscape.ConstructionIntensity);
		OnSoundscapeChanged.Broadcast(CurrentSoundscape);
	}
	else
	{
		UE_LOG(LogGKAudio, Warning, TEXT("Soundscape [%s] not found in registry."), *SoundscapeID.ToString());
	}
}

void UGKAudioSubsystem::SetConstructionAcousticIntensity(float Intensity)
{
	CurrentSoundscape.ConstructionIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);
	UE_LOG(LogGKAudio, Log, TEXT("Construction acoustic intensity adjusted to %.2f"), CurrentSoundscape.ConstructionIntensity);
	OnSoundscapeChanged.Broadcast(CurrentSoundscape);
}

void UGKAudioSubsystem::SetWaterAcoustics(EGKWaterAcousticType WaterType)
{
	CurrentSoundscape.WaterType = WaterType;
	UE_LOG(LogGKAudio, Log, TEXT("Water acoustic signature set to [%d]"), static_cast<int32>(WaterType));
	OnSoundscapeChanged.Broadcast(CurrentSoundscape);
}

bool UGKAudioSubsystem::TriggerMusicCue(EGKMusicTheme Theme, bool bIsEarnedSwell)
{
	// Score Restraint Rule (Doc 21 §3):
	// Everyday exploration defaults to pure diegetic ambience.
	// Music swells are allowed only if explicitly earned via story milestones or landmark reveals.
	if (!bIsEarnedSwell && Theme != EGKMusicTheme::None)
	{
		UE_LOG(LogGKAudio, Log, TEXT("Score Restraint Rule: Music cue [%d] suppressed in favor of diegetic ambience."),
			static_cast<int32>(Theme));
		return false;
	}

	ActiveTheme = Theme;
	UE_LOG(LogGKAudio, Log, TEXT("Music Theme [%d] triggered (Earned Swell: %s)"),
		static_cast<int32>(Theme), bIsEarnedSwell ? TEXT("YES") : TEXT("NO"));

	OnMusicThemeTriggered.Broadcast(Theme, bIsEarnedSwell);
	return true;
}

void UGKAudioSubsystem::StopMusicCue()
{
	if (ActiveTheme != EGKMusicTheme::None)
	{
		ActiveTheme = EGKMusicTheme::None;
		UE_LOG(LogGKAudio, Log, TEXT("Music cue stopped. Restored pure diegetic exploration ambience."));
		OnMusicThemeTriggered.Broadcast(EGKMusicTheme::None, false);
	}
}

void UGKAudioSubsystem::PlayCodexDiscoveryChime()
{
	// Tactile bronze/stone UI feedback (Doc 21 §1 UI category)
	UE_LOG(LogGKAudio, Log, TEXT("Playing Codex Discovery tactile bronze/stone chime."));
}

void UGKAudioSubsystem::SetCombatAudioActive(bool bActive)
{
	if (bInCombatMix != bActive)
	{
		bInCombatMix = bActive;
		if (bInCombatMix)
		{
			// Battle audio: Grounded weapon impact bed, tense rhythmic percussion (Doc 21 §1 Battle row: no stylized horns)
			UE_LOG(LogGKAudio, Log, TEXT("Combat audio mix activated (grounded percussion bed)."));
		}
		else
		{
			UE_LOG(LogGKAudio, Log, TEXT("Combat audio mix deactivated. Returning to ambient exploration."));
			StopMusicCue();
		}
	}
}
