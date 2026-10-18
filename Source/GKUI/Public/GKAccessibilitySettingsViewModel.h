#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GKAccessibilitySettingsViewModel.generated.h"

UENUM(BlueprintType)
enum class EGKSubtitleSize : uint8
{
	Small,
	Medium,
	Large,
	ExtraLarge
};

UENUM(BlueprintType)
enum class EGKColorblindPreset : uint8
{
	None,
	Protanopia,
	Deuteranopia,
	Tritanopia
};

UENUM(BlueprintType)
enum class EGKPuzzleHintDepth : uint8
{
	Minimal,
	Moderate,
	Direct
};

/**
 * Settings and accessibility view model implementing Doc 20 §11–12 and Doc 37.
 * Provides granular toggles for color-blind correction, text scaling,
 * high-contrast highlight, subtitle presentation, motion reduction, and combat assist.
 */
UCLASS(BlueprintType)
class GKUI_API UGKAccessibilitySettingsViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGKAccessibilitySettingsViewModel();

	/** Resets all settings to the accessible baseline recommended by Doc 37 */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|Accessibility")
	void ResetToDefaults();

	/** Subtitle visibility toggle (Doc 37: on by default for Tamil/historical VO) */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bSubtitlesEnabled;

	/** Subtitle font size tier */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	EGKSubtitleSize SubtitleSize;

	/** Dark translucent background panel behind subtitles for readability */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bSubtitleBackground;

	/** Color-blind palette preset (re-shades accents; borders & text remain primary) */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	EGKColorblindPreset ColorblindPreset;

	/** High contrast mode outlining interactables and UI text */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bHighContrastMode;

	/** Motion reduction disabling camera shake, bobbing, and violent FOV shifts */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bMotionReduction;

	/** Puzzle hint depth setting (Doc 01 §28: adjustability preserving intellectual content) */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	EGKPuzzleHintDepth PuzzleHintDepth;

	/** Extended parry window (+0.15s) for players needing reaction time accommodations */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bExtendedParryWindow;

	/** Reduces stamina consumption by 50% */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	bool bStaminaConsumptionAssist;

	/** UI text scale multiplier (0.8x to 1.5x) */
	UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "GK|UI|Accessibility")
	float TextScaleFactor;

	/** Helper to retrieve effective parry window multiplier */
	UFUNCTION(BlueprintPure, Category = "GK|UI|Accessibility")
	float GetParryWindowDurationMultiplier() const { return bExtendedParryWindow ? 1.6f : 1.0f; }

	/** Helper to retrieve effective stamina consumption multiplier */
	UFUNCTION(BlueprintPure, Category = "GK|UI|Accessibility")
	float GetStaminaConsumptionMultiplier() const { return bStaminaConsumptionAssist ? 0.5f : 1.0f; }
};
