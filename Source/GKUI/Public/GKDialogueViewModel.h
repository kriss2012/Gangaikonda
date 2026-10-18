#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GKDialogueTypes.h"
#include "GKCodexTypes.h"
#include "GKDialogueViewModel.generated.h"

class UGKDialogueComponent;

/**
 * UI presentation model for an individual dialogue response option.
 * Exposes the Doc 20 §8 evidence-category indicator badge and styling tokens.
 */
UCLASS(BlueprintType)
class GKUI_API UGKDialogueOptionViewModel : public UObject
{
	GENERATED_BODY()

public:
	static UGKDialogueOptionViewModel* CreateFromOption(UObject* Outer, int32 InIndex, const FGKDialogueOption& Option);

	UPROPERTY(BlueprintReadOnly, Category = "GK|DialogueUI")
	int32 OptionIndex;

	UPROPERTY(BlueprintReadOnly, Category = "GK|DialogueUI")
	FText OptionText;

	UPROPERTY(BlueprintReadOnly, Category = "GK|DialogueUI")
	bool bHasHistoricalClaim;

	UPROPERTY(BlueprintReadOnly, Category = "GK|DialogueUI")
	EGKEvidenceCategory Category;

	/** Text badge displayed next to the choice (e.g. "[DOCUMENTED]", "[PLAUSIBLE RECONSTRUCTION]") */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	FText GetCategoryBadgeText() const;

	/** Border style per Doc 20 §6 & §8 */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	EGKCodexBorderStyle GetBorderStyle() const;

	/** Linear color code reflecting accessibility requirements */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	FLinearColor GetThemeColor() const;
};

/**
 * UI presentation ViewModel driving the subtitle HUD and dialogue option wheel/list (Doc 20 §8).
 */
UCLASS(BlueprintType)
class GKUI_API UGKDialogueViewModel : public UObject
{
	GENERATED_BODY()

public:
	/** Initializes the ViewModel bound to a dialogue component */
	UFUNCTION(BlueprintCallable, Category = "GK|DialogueUI")
	void Initialize(UGKDialogueComponent* InDialogueComponent);

	/** Current speaker name */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	FText GetSpeakerName() const { return CurrentSpeakerName; }

	/** Current speaker role or title */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	FText GetSpeakerRoleTitle() const { return CurrentSpeakerRoleTitle; }

	/** Current spoken subtitle text */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	FText GetSubtitleText() const { return CurrentSubtitleText; }

	/** List of selectable dialogue option view models */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	const TArray<UGKDialogueOptionViewModel*>& GetOptions() const { return CachedOptionViewModels; }

	/** Invokes selection of an option by index */
	UFUNCTION(BlueprintCallable, Category = "GK|DialogueUI")
	bool SelectOption(int32 OptionIndex);

	/** True if dialogue is currently active */
	UFUNCTION(BlueprintPure, Category = "GK|DialogueUI")
	bool IsDialogueActive() const;

private:
	UFUNCTION()
	void HandleNodeChanged(const FGKDialogueNode& NewNode);

	UFUNCTION()
	void HandleOptionsUpdated(const TArray<FGKDialogueOption>& AvailableOptions);

	UFUNCTION()
	void HandleDialogueEnded();

	UPROPERTY()
	TWeakObjectPtr<UGKDialogueComponent> BoundDialogueComponent;

	UPROPERTY()
	FText CurrentSpeakerName;

	UPROPERTY()
	FText CurrentSpeakerRoleTitle;

	UPROPERTY()
	FText CurrentSubtitleText;

	UPROPERTY()
	TArray<TObjectPtr<UGKDialogueOptionViewModel>> CachedOptionViewModels;
};
