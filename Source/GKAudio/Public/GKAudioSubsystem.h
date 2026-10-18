#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GKAudioTypes.h"
#include "GKWorldTypes.h"
#include "GKAudioSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKSoundscapeChanged, const FGKSoundscapeDefinition&, NewSoundscape);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKMusicThemeTriggered, EGKMusicTheme, Theme, bool, bIsEarnedSwell);

/**
 * Global game subsystem driving dynamic environmental soundscapes and musical cues (Doc 21).
 * Strictly enforces the Score Restraint Rule (Doc 21 §3):
 * Score is not continuous; everyday exploration is carried by diegetic soundscapes,
 * while music swells are earned solely at landmark reveals and key story milestones.
 */
UCLASS(BlueprintType)
class GKAUDIO_API UGKAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGKAudioSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Convenience static accessor */
	UFUNCTION(BlueprintPure, Category = "GK|Audio", meta = (WorldContext = "WorldContextObject"))
	static UGKAudioSubsystem* Get(const UObject* WorldContextObject);

	/** Transitions the active environment to a new soundscape profile */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void SetSoundscape(FName SoundscapeID);

	/** Adjusts environmental construction noise intensity (Doc 21 §1) */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void SetConstructionAcousticIntensity(float Intensity);

	/** Sets water flow acoustic signature for Lion Well or reservoirs */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void SetWaterAcoustics(EGKWaterAcousticType WaterType);

	/**
	 * Triggers a musical cue, enforcing the Score Restraint Rule (Doc 21 §3).
	 * If bIsEarnedSwell is false and player is in general exploration, cue is suppressed in favor of diegetic ambience.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	bool TriggerMusicCue(EGKMusicTheme Theme, bool bIsEarnedSwell = false);

	/** Stops currently playing music cue and returns to pure diegetic ambience */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void StopMusicCue();

	/** Plays tactile bronze/stone UI feedback chime for Codex discovery */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void PlayCodexDiscoveryChime();

	/** Updates audio mix when combat initiates or concludes */
	UFUNCTION(BlueprintCallable, Category = "GK|Audio")
	void SetCombatAudioActive(bool bActive);

	/** Returns currently active environmental soundscape */
	UFUNCTION(BlueprintPure, Category = "GK|Audio")
	const FGKSoundscapeDefinition& GetCurrentSoundscape() const { return CurrentSoundscape; }

	/** Returns currently playing music theme */
	UFUNCTION(BlueprintPure, Category = "GK|Audio")
	EGKMusicTheme GetCurrentTheme() const { return ActiveTheme; }

	/** Returns true if score restraint is actively keeping the score silent in favor of ambience */
	UFUNCTION(BlueprintPure, Category = "GK|Audio")
	bool IsScoreRestrained() const { return ActiveTheme == EGKMusicTheme::None; }

	UPROPERTY(BlueprintAssignable, Category = "GK|Audio")
	FOnGKSoundscapeChanged OnSoundscapeChanged;

	UPROPERTY(BlueprintAssignable, Category = "GK|Audio")
	FOnGKMusicThemeTriggered OnMusicThemeTriggered;

private:
	/** Active environmental soundscape profile */
	UPROPERTY(Transient)
	FGKSoundscapeDefinition CurrentSoundscape;

	/** Active musical motif */
	UPROPERTY(Transient)
	EGKMusicTheme ActiveTheme;

	/** Flag tracking combat soundscape */
	UPROPERTY(Transient)
	bool bInCombatMix;

	/** Registry of pre-configured soundscapes for Zone 5 and vertical slice */
	UPROPERTY(Transient)
	TMap<FName, FGKSoundscapeDefinition> SoundscapeRegistry;

	void RegisterDefaultSoundscapes();
};
