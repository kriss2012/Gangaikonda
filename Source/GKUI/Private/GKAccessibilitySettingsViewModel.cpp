#include "GKAccessibilitySettingsViewModel.h"

UGKAccessibilitySettingsViewModel::UGKAccessibilitySettingsViewModel()
{
	ResetToDefaults();
}

void UGKAccessibilitySettingsViewModel::ResetToDefaults()
{
	// Doc 37 baseline defaults
	bSubtitlesEnabled = true; // On by default for Tamil/historical VO
	SubtitleSize = EGKSubtitleSize::Medium;
	bSubtitleBackground = true;
	ColorblindPreset = EGKColorblindPreset::None;
	bHighContrastMode = false;
	bMotionReduction = false;
	PuzzleHintDepth = EGKPuzzleHintDepth::Moderate;
	bExtendedParryWindow = false;
	bStaminaConsumptionAssist = false;
	TextScaleFactor = 1.0f;

	UE_MVVM_SET_PROPERTY_VALUE(bSubtitlesEnabled, bSubtitlesEnabled);
	UE_MVVM_SET_PROPERTY_VALUE(SubtitleSize, SubtitleSize);
	UE_MVVM_SET_PROPERTY_VALUE(bSubtitleBackground, bSubtitleBackground);
	UE_MVVM_SET_PROPERTY_VALUE(ColorblindPreset, ColorblindPreset);
	UE_MVVM_SET_PROPERTY_VALUE(bHighContrastMode, bHighContrastMode);
	UE_MVVM_SET_PROPERTY_VALUE(bMotionReduction, bMotionReduction);
	UE_MVVM_SET_PROPERTY_VALUE(PuzzleHintDepth, PuzzleHintDepth);
	UE_MVVM_SET_PROPERTY_VALUE(bExtendedParryWindow, bExtendedParryWindow);
	UE_MVVM_SET_PROPERTY_VALUE(bStaminaConsumptionAssist, bStaminaConsumptionAssist);
	UE_MVVM_SET_PROPERTY_VALUE(TextScaleFactor, TextScaleFactor);
}
