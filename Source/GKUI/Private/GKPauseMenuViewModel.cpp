#include "GKPauseMenuViewModel.h"

UGKPauseMenuViewModel::UGKPauseMenuViewModel()
	: CurrentScreen(EGKPauseMenuScreen::Root)
	, bCanSaveGame(true)
{
	SaveStatusMessage = FText::GetEmpty();
}

void UGKPauseMenuViewModel::RefreshState(UGKSaveSubsystem* SaveSubsystem)
{
	if (SaveSubsystem)
	{
		bCanSaveGame = SaveSubsystem->CanSave();
		if (!bCanSaveGame)
		{
			SaveStatusMessage = NSLOCTEXT("GKUI", "SaveBlockedCombat", "Cannot save while in combat or incapacitated.");
		}
		else
		{
			SaveStatusMessage = FText::GetEmpty();
		}
	}
	else
	{
		bCanSaveGame = false;
		SaveStatusMessage = NSLOCTEXT("GKUI", "SaveSubsystemUnavailable", "Save system unavailable.");
	}

	UE_MVVM_SET_PROPERTY_VALUE(bCanSaveGame, bCanSaveGame);
	UE_MVVM_SET_PROPERTY_VALUE(SaveStatusMessage, SaveStatusMessage);
}

void UGKPauseMenuViewModel::NavigateTo(EGKPauseMenuScreen Screen)
{
	CurrentScreen = Screen;
	UE_MVVM_SET_PROPERTY_VALUE(CurrentScreen, CurrentScreen);
}

void UGKPauseMenuViewModel::RequestResume()
{
	NavigateTo(EGKPauseMenuScreen::Root);
	OnResumeRequested.Broadcast();
}

bool UGKPauseMenuViewModel::TriggerManualSave(UGKSaveSubsystem* SaveSubsystem, const FString& SlotName)
{
	if (!SaveSubsystem)
	{
		SaveStatusMessage = NSLOCTEXT("GKUI", "SaveFailed", "Save system unavailable.");
		UE_MVVM_SET_PROPERTY_VALUE(SaveStatusMessage, SaveStatusMessage);
		return false;
	}

	if (!SaveSubsystem->CanSave())
	{
		SaveStatusMessage = NSLOCTEXT("GKUI", "SaveBlockedCombat", "Cannot save while in combat or incapacitated.");
		UE_MVVM_SET_PROPERTY_VALUE(SaveStatusMessage, SaveStatusMessage);
		return false;
	}

	const bool bSuccess = SaveSubsystem->SaveGame(SlotName, 0);
	if (bSuccess)
	{
		SaveStatusMessage = NSLOCTEXT("GKUI", "SaveSuccess", "Game saved successfully.");
	}
	else
	{
		SaveStatusMessage = NSLOCTEXT("GKUI", "SaveWriteError", "Failed to write save file.");
	}

	UE_MVVM_SET_PROPERTY_VALUE(SaveStatusMessage, SaveStatusMessage);
	return bSuccess;
}
