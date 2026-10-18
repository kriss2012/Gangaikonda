#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Stone/GKStoneAlignmentPuzzleActor.h"
#include "Hydraulic/GKLionWellPuzzleActor.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Puzzle.StoneAlignment_StressMath
 * Validates load-path stress calculations, block rotation, and solve evaluation for Stone Alignment Tier 1 (Doc 09 P01).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKStoneAlignmentTest, "GK.Puzzle.StoneAlignment_StressMath", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKStoneAlignmentTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for stone alignment test"), World);

	AGKStoneAlignmentPuzzleActor* StoneActor = World->SpawnActor<AGKStoneAlignmentPuzzleActor>();
	TestNotNull(TEXT("AGKStoneAlignmentPuzzleActor spawned"), StoneActor);

	TestEqual(TEXT("Initial state is Unsolved"), StoneActor->CurrentPuzzleState, EGKPuzzleState::Unsolved);
	TestTrue(TEXT("Initial course has positive load imbalance"), StoneActor->GetTotalCourseImbalance() > 0.0f);

	// Rotate Block 0 (Target = 1, Current = 0): 1 rotation
	StoneActor->RotateBlockClockwise(0);

	// Rotate Block 1 (Target = 2, Current = 3): 3 rotations (3 -> 0 -> 1 -> 2)
	StoneActor->RotateBlockClockwise(1);
	StoneActor->RotateBlockClockwise(1);
	StoneActor->RotateBlockClockwise(1);

	// Rotate Block 2 (Target = 0, Current = 2): 2 rotations (2 -> 3 -> 0)
	StoneActor->RotateBlockClockwise(2);
	StoneActor->RotateBlockClockwise(2);

	// Rotate Block 3 (Target = 3, Current = 1): 2 rotations (1 -> 2 -> 3)
	StoneActor->RotateBlockClockwise(3);
	StoneActor->RotateBlockClockwise(3);

	// Verification
	TestTrue(TEXT("Total course imbalance is 0.0 when fully aligned"), FMath::IsNearlyZero(StoneActor->GetTotalCourseImbalance()));
	TestEqual(TEXT("Puzzle transitions to Solved"), StoneActor->CurrentPuzzleState, EGKPuzzleState::Solved);
	TestEqual(TEXT("Evidence reward matches G2"), StoneActor->EvidenceRewardID, FName(TEXT("G2")));

	World->DestroyWorld(false);
	return true;
}

/**
 * Test: GK.Puzzle.LionWell_HydraulicStages
 * Validates deterministic graph propagation, sluice gate sequencing (Stages 1-3), sediment clearing (Stage 4),
 * and hidden inscription chamber trigger (Doc 08 Minutes 18–23, Doc 09 P04/P05).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKLionWellTest, "GK.Puzzle.LionWell_HydraulicStages", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKLionWellTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for Lion Well test"), World);

	AGKLionWellPuzzleActor* LionWell = World->SpawnActor<AGKLionWellPuzzleActor>();
	TestNotNull(TEXT("AGKLionWellPuzzleActor spawned"), LionWell);

	TestEqual(TEXT("Initial state is Unsolved"), LionWell->CurrentPuzzleState, EGKPuzzleState::Unsolved);
	TestEqual(TEXT("Initial stage is 1"), LionWell->CurrentStage, 1);
	TestFalse(TEXT("Hidden chamber initially locked"), LionWell->bHiddenInscriptionRevealed);

	// Opening Gate 2 first must NOT propagate water (upstream has no water)
	LionWell->ToggleSluiceGate(2);
	TestFalse(TEXT("Bypass weir has no water without intake"), LionWell->HydraulicNodes[2].bHasWater);

	// Stage 1: Open Gate 1 (Intake)
	LionWell->ToggleSluiceGate(1);
	TestTrue(TEXT("Upper canal receives water"), LionWell->HydraulicNodes[1].bHasWater);
	TestTrue(TEXT("Bypass weir receives water via Gate 2"), LionWell->HydraulicNodes[2].bHasWater);
	TestEqual(TEXT("Advanced to Stage 3"), LionWell->CurrentStage, 3);

	// Stage 3: Open Gate 3 (Feeder)
	LionWell->ToggleSluiceGate(3);
	TestTrue(TEXT("Sediment basin receives water"), LionWell->HydraulicNodes[3].bHasWater);
	TestEqual(TEXT("Advanced to Stage 4"), LionWell->CurrentStage, 4);

	// Lion Well basin still dry due to silt blockage
	TestFalse(TEXT("Lion Well basin dry before sediment dredge"), LionWell->HydraulicNodes[4].bHasWater);
	TestFalse(TEXT("Puzzle not yet solved"), LionWell->CurrentPuzzleState == EGKPuzzleState::Solved);

	// Stage 4: Clear sediment blockage
	bool bCleared = LionWell->ClearSedimentBlockage();
	TestTrue(TEXT("Sediment cleared successfully"), bCleared);
	TestTrue(TEXT("Water reaches Lion Well basin"), LionWell->HydraulicNodes[4].bHasWater);
	TestTrue(TEXT("Hidden inscription chamber revealed"), LionWell->bHiddenInscriptionRevealed);
	TestEqual(TEXT("Puzzle state is Solved"), LionWell->CurrentPuzzleState, EGKPuzzleState::Solved);

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
