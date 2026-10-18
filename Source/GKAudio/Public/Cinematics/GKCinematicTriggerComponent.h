#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GKAudioTypes.h"
#include "GKCinematicTriggerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKCinematicStarted, FName, CinematicID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKCinematicFinished, FName, CinematicID);

/**
 * Component driving cinematic playback, pre-text cards, and seamless gameplay handoffs (Doc 05).
 * Disables player inputs cleanly during sequencer execution and integrates with UGKAudioSubsystem.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKAUDIO_API UGKCinematicTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKCinematicTriggerComponent();

	/** Initiates cinematic sequence playback and input handoff */
	UFUNCTION(BlueprintCallable, Category = "GK|Cinematic")
	bool TriggerCinematic(APlayerController* PlayerController);

	/** Manually signals sequence completion (called via Sequencer event track or timer) */
	UFUNCTION(BlueprintCallable, Category = "GK|Cinematic")
	void CompleteCinematic();

	/** Identifier for the cinematic sequence (e.g. CIN_001_Prologue, CIN_003_TheGanga) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Cinematic")
	FName CinematicID;

	/** Mandatory historical disclaimer card displayed prior to playback (Doc 05 Cinematic 003) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Cinematic")
	FText PreTextCard;

	/** Duration to hold pre-text card before sequence begins */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Cinematic")
	float PreTextCardDuration;

	/** Associated musical motif triggered during sequence */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Cinematic")
	EGKMusicTheme AssociatedMusicTheme;

	/** True if camera smoothly settles behind player character without a hard cut (Doc 05 handoff note) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Cinematic")
	bool bSeamlessGameplayHandoff;

	/** Returns true while sequence is actively executing */
	UFUNCTION(BlueprintPure, Category = "GK|Cinematic")
	bool IsPlaying() const { return bIsPlaying; }

	UPROPERTY(BlueprintAssignable, Category = "GK|Cinematic")
	FOnGKCinematicStarted OnCinematicStarted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Cinematic")
	FOnGKCinematicFinished OnCinematicFinished;

private:
	UPROPERTY(Transient)
	bool bIsPlaying;

	UPROPERTY(Transient)
	TWeakObjectPtr<APlayerController> BoundController;
};
