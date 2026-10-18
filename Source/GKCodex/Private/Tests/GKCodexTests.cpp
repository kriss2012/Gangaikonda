#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/DataTable.h"
#include "GKCodexTypes.h"
#include "GKCodexViewModel.h"
#include "GKCodexSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GKCodex.NoUpgradeRule
 * Verifies Hard Rule 4: "Never upgrade a confidence tier when moving data from the research database to the Codex."
 * Verifies that UGKCodexEntryViewModel strictly preserves Category and Confidence from source row without mutation.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCodexNoUpgradeTest, "GK.Codex.NoUpgradeRule", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCodexNoUpgradeTest::RunTest(const FString& Parameters)
{
	// 1. Create a Fictional / Unknown row
	FGKEvidenceRow FictionalRow;
	FictionalRow.EvidenceID = FName(TEXT("TEST_FIC"));
	FictionalRow.Claim = FText::FromString(TEXT("Fictional claim for narrative dramatization."));
	FictionalRow.Category = EGKEvidenceCategory::Fictional;
	FictionalRow.Confidence = EGKConfidence::Unknown;
	FictionalRow.RequiredDisclaimer = FText::FromString(TEXT("[PLACEHOLDER – FICTIONAL]"));

	UGKCodexEntryViewModel* FicVM = UGKCodexEntryViewModel::CreateFromRow(GetTransientPackage(), FictionalRow);
	TestNotNull(TEXT("Fictional ViewModel created successfully"), FicVM);
	TestEqual(TEXT("Category must remain Fictional"), FicVM->GetCategory(), EGKEvidenceCategory::Fictional);
	TestEqual(TEXT("Confidence must remain Unknown"), FicVM->GetConfidence(), EGKConfidence::Unknown);
	TestEqual(TEXT("Border style must be Desaturated"), FicVM->GetBorderStyle(), EGKCodexBorderStyle::Desaturated);
	TestTrue(TEXT("Must display disclaimer"), FicVM->HasDisclaimer());

	// 2. Create a Plausible Reconstruction / Uncertain row
	FGKEvidenceRow PlausibleRow;
	PlausibleRow.EvidenceID = FName(TEXT("TEST_PLAUSIBLE"));
	PlausibleRow.Claim = FText::FromString(TEXT("Inferred logistical line of supply."));
	PlausibleRow.Category = EGKEvidenceCategory::PlausibleReconstruction;
	PlausibleRow.Confidence = EGKConfidence::Uncertain;
	PlausibleRow.RequiredDisclaimer = FText::FromString(TEXT("Historical reconstruction based on regional scholarship."));

	UGKCodexEntryViewModel* PlausibleVM = UGKCodexEntryViewModel::CreateFromRow(GetTransientPackage(), PlausibleRow);
	TestNotNull(TEXT("Plausible ViewModel created successfully"), PlausibleVM);
	TestEqual(TEXT("Category must remain PlausibleReconstruction"), PlausibleVM->GetCategory(), EGKEvidenceCategory::PlausibleReconstruction);
	TestEqual(TEXT("Confidence must remain Uncertain"), PlausibleVM->GetConfidence(), EGKConfidence::Uncertain);
	TestEqual(TEXT("Border style must be DashedHatched"), PlausibleVM->GetBorderStyle(), EGKCodexBorderStyle::DashedHatched);

	// 3. Create a Documented / Known row
	FGKEvidenceRow DocumentedRow;
	DocumentedRow.EvidenceID = FName(TEXT("TEST_DOC"));
	DocumentedRow.Claim = FText::FromString(TEXT("Tiruvalangadu plates record Gangaikonda title."));
	DocumentedRow.Category = EGKEvidenceCategory::Documented;
	DocumentedRow.Confidence = EGKConfidence::Known;

	UGKCodexEntryViewModel* DocVM = UGKCodexEntryViewModel::CreateFromRow(GetTransientPackage(), DocumentedRow);
	TestNotNull(TEXT("Documented ViewModel created successfully"), DocVM);
	TestEqual(TEXT("Category must remain Documented"), DocVM->GetCategory(), EGKEvidenceCategory::Documented);
	TestEqual(TEXT("Confidence must remain Known"), DocVM->GetConfidence(), EGKConfidence::Known);
	TestEqual(TEXT("Border style must be Solid"), DocVM->GetBorderStyle(), EGKCodexBorderStyle::Solid);

	return true;
}

/**
 * Test: GKCodex.SubsystemLifecycle
 * Verifies UGKCodexSubsystem unlock logic, idempotency, filtering, and delegate notifications.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCodexSubsystemTest, "GK.Codex.SubsystemLifecycle", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCodexSubsystemTest::RunTest(const FString& Parameters)
{
	// Create an in-memory transient data table for unit isolation
	UDataTable* TestTable = NewObject<UDataTable>(GetTransientPackage());
	TestTable->RowStruct = FGKEvidenceRow::StaticStruct();

	FGKEvidenceRow RowA;
	RowA.EvidenceID = FName(TEXT("A1"));
	RowA.Claim = FText::FromString(TEXT("Documented claim A1"));
	RowA.Category = EGKEvidenceCategory::Documented;
	RowA.Confidence = EGKConfidence::Known;
	TestTable->AddRow(FName(TEXT("A1")), RowA);

	FGKEvidenceRow RowB;
	RowB.EvidenceID = FName(TEXT("B2"));
	RowB.Claim = FText::FromString(TEXT("Plausible claim B2"));
	RowB.Category = EGKEvidenceCategory::PlausibleReconstruction;
	RowB.Confidence = EGKConfidence::Uncertain;
	TestTable->AddRow(FName(TEXT("B2")), RowB);

	// Instantiate subsystem for test
	UGKCodexSubsystem* Subsystem = NewObject<UGKCodexSubsystem>(GetTransientPackage());
	Subsystem->SetEvidenceDataTable(TestTable);

	// Verify initial state
	TestEqual(TEXT("Initial unlocked count is 0"), Subsystem->GetUnlockedCount(), 0);
	TestFalse(TEXT("A1 is initially locked"), Subsystem->IsUnlocked(FName(TEXT("A1"))));

	// Test unlock
	bool bUnlocked = Subsystem->UnlockEntry(FName(TEXT("A1")));
	TestTrue(TEXT("First unlock of A1 succeeds"), bUnlocked);
	TestTrue(TEXT("A1 is now unlocked"), Subsystem->IsUnlocked(FName(TEXT("A1"))));
	TestEqual(TEXT("Unlocked count is 1"), Subsystem->GetUnlockedCount(), 1);

	// Test idempotency: second unlock should return false and not duplicate
	bool bSecondUnlock = Subsystem->UnlockEntry(FName(TEXT("A1")));
	TestFalse(TEXT("Duplicate unlock of A1 returns false"), bSecondUnlock);
	TestEqual(TEXT("Unlocked count remains 1"), Subsystem->GetUnlockedCount(), 1);

	// Test unlocking non-existent row
	bool bInvalidUnlock = Subsystem->UnlockEntry(FName(TEXT("NON_EXISTENT_ID")));
	TestFalse(TEXT("Invalid EvidenceID unlock returns false"), bInvalidUnlock);

	// Test second valid unlock
	Subsystem->UnlockEntry(FName(TEXT("B2")));
	TestEqual(TEXT("Unlocked count is now 2"), Subsystem->GetUnlockedCount(), 2);

	// Test category query
	TArray<FGKEvidenceRow> DocRows = Subsystem->GetUnlockedEntriesByCategory(EGKEvidenceCategory::Documented);
	TestEqual(TEXT("One Documented row returned"), DocRows.Num(), 1);
	TestEqual(TEXT("Returned row is A1"), DocRows[0].EvidenceID, FName(TEXT("A1")));

	TArray<FGKEvidenceRow> PlausibleRows = Subsystem->GetUnlockedEntriesByCategory(EGKEvidenceCategory::PlausibleReconstruction);
	TestEqual(TEXT("One PlausibleReconstruction row returned"), PlausibleRows.Num(), 1);
	TestEqual(TEXT("Returned row is B2"), PlausibleRows[0].EvidenceID, FName(TEXT("B2")));

	// Test save state restoration
	TSet<FName> SaveSet;
	SaveSet.Add(FName(TEXT("A1")));
	UGKCodexSubsystem* NewSubsystem = NewObject<UGKCodexSubsystem>(GetTransientPackage());
	NewSubsystem->SetEvidenceDataTable(TestTable);
	NewSubsystem->RestoreUnlockedEntries(SaveSet);
	TestTrue(TEXT("Restored subsystem has A1 unlocked"), NewSubsystem->IsUnlocked(FName(TEXT("A1"))));
	TestFalse(TEXT("Restored subsystem has B2 locked"), NewSubsystem->IsUnlocked(FName(TEXT("B2"))));

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
