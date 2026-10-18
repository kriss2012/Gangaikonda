#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKPuzzleTypes.h"
#include "Inscription/GKInscriptionActor.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Inscription.P10_DecodingLifecycle
 * Verifies Inscription Decoding Tier 1 (Doc 09 P10 / Doc 08 Minutes 9–14).
 * Validates fragment matching, soft fail on wrong sequences, correct solution verification, and placeholder tagging.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKInscriptionDecodingTest, "GK.Inscription.P10_DecodingLifecycle", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKInscriptionDecodingTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for inscription test"), World);

	AGKInscriptionActor* Inscription = World->SpawnActor<AGKInscriptionActor>();
	TestNotNull(TEXT("AGKInscriptionActor spawned"), Inscription);

	// Verify initial state
	TestEqual(TEXT("Initial state is Unsolved"), Inscription->CurrentPuzzleState, EGKPuzzleState::Unsolved);
	TestEqual(TEXT("Associated reward is Evidence H2"), Inscription->EvidenceRewardID, FName(TEXT("H2")));

	// Verify mandatory placeholder tag on decoded text (Hard Rule 2)
	const FString DecodedStr = Inscription->FullDecodedText.ToString();
	TestTrue(TEXT("Placeholder text must contain [PLACEHOLDER – FICTIONAL]"), DecodedStr.Contains(TEXT("[PLACEHOLDER – FICTIONAL]")));

	// Test 1: Wrong sequence assignment (1, 4, 3, 2)
	Inscription->AssignFragmentToSlot(0, 1);
	Inscription->AssignFragmentToSlot(1, 4);
	Inscription->AssignFragmentToSlot(2, 3);
	Inscription->AssignFragmentToSlot(3, 2);

	TestFalse(TEXT("Incorrect sequence must not solve puzzle"), Inscription->AttemptSolve_Implementation());
	TestEqual(TEXT("Puzzle state must remain InProgress or Unsolved"), Inscription->CurrentPuzzleState, EGKPuzzleState::InProgress);

	// Test 2: Clear and reset
	Inscription->ResetPuzzle_Implementation();
	TestEqual(TEXT("Reset restores Unsolved state"), Inscription->CurrentPuzzleState, EGKPuzzleState::Unsolved);
	TestEqual(TEXT("Slot 0 cleared"), Inscription->PlayerAssignedSequence[0], 0);

	// Test 3: Correct sequence assignment (1, 2, 3, 4 -> Svasti Gangai Konda Chola)
	Inscription->AssignFragmentToSlot(0, 1);
	Inscription->AssignFragmentToSlot(1, 2);
	Inscription->AssignFragmentToSlot(2, 3);
	Inscription->AssignFragmentToSlot(3, 4);

	TestTrue(TEXT("Correct sequence must successfully solve puzzle"), Inscription->IsFullyDecoded());
	TestEqual(TEXT("Puzzle state must transition to Solved"), Inscription->CurrentPuzzleState, EGKPuzzleState::Solved);

	// Clean up transient test world
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
