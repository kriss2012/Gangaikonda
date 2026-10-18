#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKHUDViewModel.h"
#include "GKCodexJournalViewModel.h"
#include "GKQuestJournalViewModel.h"
#include "GKPauseMenuViewModel.h"
#include "GKAccessibilitySettingsViewModel.h"
#include "GKCodexSubsystem.h"
#include "GKQuestSubsystem.h"
#include "GKSaveSubsystem.h"
#include "Stubs/GKVSQuestChain.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.UI.HUDGroundedVitalsAndZeroDamageNumbers
 * Enforces Doc 01 §29, Doc 20 §9, and Hard Rule 5:
 * Zero floating damage numbers, grounded vitals representation.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKHUDViewModelTest, "GK.UI.HUDGroundedVitalsAndZeroDamageNumbers", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKHUDViewModelTest::RunTest(const FString& Parameters)
{
	UGKHUDViewModel* HUDVM = NewObject<UGKHUDViewModel>();
	TestNotNull(TEXT("HUDVM created"), HUDVM);

	// Hard Rule 5 validation: Floating damage numbers strictly prohibited
	TestFalse(TEXT("Floating damage numbers are strictly disabled"), UGKHUDViewModel::AreDamageNumbersEnabled());

	// Default state validation
	TestEqual(TEXT("Initial health percent is 1.0"), HUDVM->HealthPercent, 1.0f);
	TestEqual(TEXT("Initial stamina percent is 1.0"), HUDVM->StaminaPercent, 1.0f);
	TestFalse(TEXT("Not initial low health"), HUDVM->bIsLowHealth);
	TestFalse(TEXT("Not initial low stamina"), HUDVM->bIsLowStamina);
	TestFalse(TEXT("Not initial in combat"), HUDVM->bIsInCombat);
	TestEqual(TEXT("Initial stance is Neutral"), HUDVM->CombatStance, EGKCombatStance::Neutral);

	return true;
}

/**
 * Test: GK.UI.CodexJournalRedundantAccessibility
 * Validates locked 4-field format and redundant coding (border style + explicit text label, never color alone).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCodexJournalAccessibilityTest, "GK.UI.CodexJournalRedundantAccessibility", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCodexJournalAccessibilityTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance created"), GameInstance);

	UGKCodexSubsystem* CodexSubsystem = NewObject<UGKCodexSubsystem>(GameInstance);
	TestNotNull(TEXT("CodexSubsystem created"), CodexSubsystem);

	// Setup mock table with Documented and Fictional rows
	UDataTable* MockTable = NewObject<UDataTable>(GetTransientPackage());
	MockTable->RowStruct = FGKEvidenceRow::StaticStruct();

	FGKEvidenceRow DocRow;
	DocRow.EvidenceID = TEXT("A1");
	DocRow.Claim = FText::FromString(TEXT("Tirumavalavan title attested on South Wall"));
	DocRow.Category = EGKEvidenceCategory::Documented;
	DocRow.Confidence = EGKConfidence::Known;
	DocRow.Source = FText::FromString(TEXT("SII Vol II No 20"));
	DocRow.DatePeriod = FText::FromString(TEXT("c. 1025 CE"));
	MockTable->AddRow(TEXT("A1"), DocRow);

	FGKEvidenceRow FictionalRow;
	FictionalRow.EvidenceID = TEXT("Z9");
	FictionalRow.Claim = FText::FromString(TEXT("[PLACEHOLDER – FICTIONAL] Narrative scaffolding"));
	FictionalRow.Category = EGKEvidenceCategory::Fictional;
	FictionalRow.Confidence = EGKConfidence::Unknown;
	FictionalRow.Source = FText::FromString(TEXT("Narrative Design team"));
	FictionalRow.DatePeriod = FText::FromString(TEXT("Modern Reconstruction"));
	MockTable->AddRow(TEXT("Z9"), FictionalRow);

	CodexSubsystem->SetEvidenceDataTable(MockTable);
	CodexSubsystem->UnlockEntry(TEXT("A1"));
	CodexSubsystem->UnlockEntry(TEXT("Z9"));

	// Initialize Journal ViewModel
	UGKCodexJournalViewModel* JournalVM = NewObject<UGKCodexJournalViewModel>();
	JournalVM->RefreshFromSubsystem(CodexSubsystem);

	TestEqual(TEXT("Has 2 unlocked entries"), JournalVM->VisibleEntries.Num(), 2);

	// Select Documented Entry
	JournalVM->SelectEntry(JournalVM->VisibleEntries[0]);
	TestEqual(TEXT("Detail Source matches A1"), JournalVM->DetailSource.ToString(), TEXT("SII Vol II No 20"));
	TestEqual(TEXT("Detail Date matches A1"), JournalVM->DetailDatePeriod.ToString(), TEXT("c. 1025 CE"));
	TestEqual(TEXT("Explicit Confidence Text label is KNOWN"), JournalVM->DetailConfidenceText.ToString(), TEXT("KNOWN"));
	TestEqual(TEXT("Border style is SolidBronze"), JournalVM->DetailBorderStyle, EGKCodexBorderStyle::SolidBronze);
	TestEqual(TEXT("Badge label is [DOCUMENTED]"), JournalVM->DetailCategoryBadge.ToString(), TEXT("[DOCUMENTED]"));

	// Select Fictional Entry
	JournalVM->SelectEntry(JournalVM->VisibleEntries[1]);
	TestEqual(TEXT("Explicit Confidence Text label is UNKNOWN"), JournalVM->DetailConfidenceText.ToString(), TEXT("UNKNOWN"));
	TestEqual(TEXT("Border style is MutedGranite"), JournalVM->DetailBorderStyle, EGKCodexBorderStyle::MutedGranite);
	TestEqual(TEXT("Badge label is [FICTIONAL]"), JournalVM->DetailCategoryBadge.ToString(), TEXT("[FICTIONAL]"));

	return true;
}

/**
 * Test: GK.UI.QuestJournalEvidenceTags
 * Enforces Doc 20 §4: Quest entries must display evidence category badges directly in the journal.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKQuestJournalEvidenceTest, "GK.UI.QuestJournalEvidenceTags", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKQuestJournalEvidenceTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance created"), GameInstance);

	UGKQuestSubsystem* QuestSubsystem = NewObject<UGKQuestSubsystem>(GameInstance);
	TestNotNull(TEXT("QuestSubsystem created"), QuestSubsystem);

	UGKQuestDataAsset* VSQuest = FGKVSQuestChain::BuildVerticalSliceQuest(GetTransientPackage());
	QuestSubsystem->RegisterQuest(VSQuest);
	QuestSubsystem->StartQuest(VSQuest->QuestID);

	UGKQuestJournalViewModel* JournalVM = NewObject<UGKQuestJournalViewModel>();
	JournalVM->RefreshFromSubsystem(QuestSubsystem);

	TestEqual(TEXT("1 active quest in journal"), JournalVM->ActiveQuests.Num(), 1);
	if (JournalVM->ActiveQuests.Num() > 0)
	{
		UGKQuestJournalEntryViewModel* Entry = JournalVM->ActiveQuests[0];
		TestEqual(TEXT("Quest title matches"), Entry->Title.ToString(), VSQuest->Title.ToString());
		// Vertical Slice Quest is PlausibleReconstruction
		TestEqual(TEXT("Evidence badge is [PLAUSIBLE RECONSTRUCTION]"), Entry->EvidenceCategoryBadge.ToString(), TEXT("[PLAUSIBLE RECONSTRUCTION]"));
		TestEqual(TEXT("Current objective matches first beat"), Entry->CurrentObjectiveText.ToString(), VSQuest->Objectives[0].Description.ToString());
	}

	return true;
}

/**
 * Test: GK.UI.PauseMenuCombatGating
 * Enforces Doc 18 §6 & Doc 20 §2: Manual saves disabled during combat.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKPauseMenuCombatGatingTest, "GK.UI.PauseMenuCombatGating", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKPauseMenuCombatGatingTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	UGKSaveSubsystem* SaveSubsystem = NewObject<UGKSaveSubsystem>(GameInstance);
	UGKPauseMenuViewModel* PauseVM = NewObject<UGKPauseMenuViewModel>();

	// Test outside combat: save enabled
	SaveSubsystem->SetInCombat(false);
	PauseVM->RefreshState(SaveSubsystem);
	TestTrue(TEXT("Can save outside combat"), PauseVM->bCanSaveGame);

	// Test inside combat: save disabled
	SaveSubsystem->SetInCombat(true);
	PauseVM->RefreshState(SaveSubsystem);
	TestFalse(TEXT("Cannot save inside combat"), PauseVM->bCanSaveGame);
	TestFalse(TEXT("Manual save attempt rejected"), PauseVM->TriggerManualSave(SaveSubsystem));

	return true;
}

/**
 * Test: GK.UI.AccessibilitySettingsDefaults
 * Enforces Doc 37: Subtitles on by default, correct assist multipliers.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKAccessibilityDefaultsTest, "GK.UI.AccessibilitySettingsDefaults", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKAccessibilityDefaultsTest::RunTest(const FString& Parameters)
{
	UGKAccessibilitySettingsViewModel* SettingsVM = NewObject<UGKAccessibilitySettingsViewModel>();
	TestNotNull(TEXT("SettingsVM created"), SettingsVM);

	// Doc 37 Requirement: Subtitles on by default
	TestTrue(TEXT("Subtitles on by default"), SettingsVM->bSubtitlesEnabled);
	TestTrue(TEXT("Subtitle background on by default"), SettingsVM->bSubtitleBackground);
	TestEqual(TEXT("Default text scale is 1.0"), SettingsVM->TextScaleFactor, 1.0f);

	// Assists disabled by default (1.0x multipliers)
	TestEqual(TEXT("Default parry duration multiplier is 1.0"), SettingsVM->GetParryWindowDurationMultiplier(), 1.0f);
	TestEqual(TEXT("Default stamina consumption multiplier is 1.0"), SettingsVM->GetStaminaConsumptionMultiplier(), 1.0f);

	// Assists enabled
	SettingsVM->bExtendedParryWindow = true;
	SettingsVM->bStaminaConsumptionAssist = true;
	TestEqual(TEXT("Extended parry multiplier is 1.6"), SettingsVM->GetParryWindowDurationMultiplier(), 1.6f);
	TestEqual(TEXT("Assisted stamina consumption is 0.5"), SettingsVM->GetStaminaConsumptionMultiplier(), 0.5f);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
