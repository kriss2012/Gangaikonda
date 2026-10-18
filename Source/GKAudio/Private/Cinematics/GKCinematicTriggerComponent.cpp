#include "Cinematics/GKCinematicTriggerComponent.h"
#include "GameFramework/PlayerController.h"
#include "GKAudioSubsystem.h"
#include "GKLogChannels.h"

UGKCinematicTriggerComponent::UGKCinematicTriggerComponent()
	: CinematicID(TEXT("CIN_001_Prologue"))
	, PreTextCard(FText::GetEmpty())
	, PreTextCardDuration(2.0f)
	, AssociatedMusicTheme(EGKMusicTheme::None)
	, bSeamlessGameplayHandoff(true)
	, bIsPlaying(false)
{
}

bool UGKCinematicTriggerComponent::TriggerCinematic(APlayerController* PlayerController)
{
	if (bIsPlaying)
	{
		return false;
	}

	bIsPlaying = true;
	BoundController = PlayerController;

	// 1. Lock player inputs during cinematic execution
	if (PlayerController)
	{
		PlayerController->SetIgnoreMoveInput(true);
		PlayerController->SetIgnoreLookInput(true);
	}

	// 2. Trigger associated earned music theme
	if (AssociatedMusicTheme != EGKMusicTheme::None)
	{
		if (UGKAudioSubsystem* AudioSubsystem = UGKAudioSubsystem::Get(this))
		{
			AudioSubsystem->TriggerMusicCue(AssociatedMusicTheme, true); // Cinematics are earned swells
		}
	}

	UE_LOG(LogGKAudio, Log, TEXT("Cinematic [%s] started. Seamless handoff: %s"),
		*CinematicID.ToString(), bSeamlessGameplayHandoff ? TEXT("YES") : TEXT("NO"));

	if (!PreTextCard.IsEmpty())
	{
		UE_LOG(LogGKAudio, Log, TEXT("Cinematic [%s] Pre-Text Card: '%s' (Hold %.1fs)"),
			*CinematicID.ToString(), *PreTextCard.ToString(), PreTextCardDuration);
	}

	OnCinematicStarted.Broadcast(CinematicID);
	return true;
}

void UGKCinematicTriggerComponent::CompleteCinematic()
{
	if (!bIsPlaying)
	{
		return;
	}

	bIsPlaying = false;

	// Restore player inputs cleanly (Doc 05 gameplay handoff)
	if (APlayerController* PC = BoundController.Get())
	{
		PC->SetIgnoreMoveInput(false);
		PC->SetIgnoreLookInput(false);
	}

	// Stop cinematic score and return to exploration soundscape
	if (UGKAudioSubsystem* AudioSubsystem = UGKAudioSubsystem::Get(this))
	{
		AudioSubsystem->StopMusicCue();
	}

	UE_LOG(LogGKAudio, Log, TEXT("Cinematic [%s] finished. Player controls restored cleanly."), *CinematicID.ToString());
	OnCinematicFinished.Broadcast(CinematicID);
}
