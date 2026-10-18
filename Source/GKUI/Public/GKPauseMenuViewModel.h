#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GKSaveSubsystem.h"
#include "GKPauseMenuViewModel.generated.h"

UENUM(BlueprintType)
enum class EGKPauseMenuScreen : uint8
{
	Root,
	Map,
	QuestJournal,
	Inventory,
	Codex,
	Settings,
	SaveLoad
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGKResumeRequested);

/**
 * View model managing the in-game Pause Menu navigation and actions (Doc 20 §2).
 * Integrates with UGKSaveSubsystem to enforce non-combat save restrictions (Doc 18 §6).
 */
UCLASS(BlueprintType)
class GKUI_API UGKPauseMenuViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGKPauseMenuViewModel();

	/** Updates subsystem availability (checks combat state for save gating) */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Pause")
	void RefreshState(UGKSaveSubsystem* SaveSubsystem);

	/** Navigates to a specific sub-screen */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Pause")
	void NavigateTo(EGKPauseMenuScreen Screen);

	/** Requests game resume */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Pause")
	void RequestResume();

	/** Attempts manual save, strictly respecting combat gating */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Pause")
	bool TriggerManualSave(UGKSaveSubsystem* SaveSubsystem, const FString& SlotName = TEXT("ManualSave_0"));

	/** Active pause menu sub-screen */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Pause")
	EGKPauseMenuScreen CurrentScreen;

	/** True if saving is permitted right now (disabled during combat per Doc 18 §6) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Pause")
	bool bCanSaveGame;

	/** Status feedback message (e.g. "Game Saved Successfully" or "Cannot save in combat") */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|Pause")
	FText SaveStatusMessage;

	UPROPERTY(BlueprintAssignable, Category = "GK|UI|Pause")
	FOnGKResumeRequested OnResumeRequested;
};
