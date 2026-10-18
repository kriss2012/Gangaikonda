#include "Stone/GKStoneAlignmentPuzzleActor.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "GKStoneAlignment"

AGKStoneAlignmentPuzzleActor::AGKStoneAlignmentPuzzleActor()
	: StressWarningThreshold(0.6f)
	, bVisualAssistActive(false)
{
	PuzzleID = FName(TEXT("P01_CourseOfFour"));
	EvidenceRewardID = FName(TEXT("G2")); // Traces to Doc 03 G2: Stone temple construction techniques

	// Populate three-tier hints per Doc 09 P01
	HintTiers.Empty();
	HintTiers.Add(LOCTEXT("P01Hint1", "Granite courses bear weight only when dressed mortise slots align squarely with the tenons below."));
	HintTiers.Add(LOCTEXT("P01Hint2", "Examine the hairline fissures: the eastern corner stones are bearing excessive shear thrust."));
	HintTiers.Add(LOCTEXT("P01Hint3", "Rotate the north-east stone twice and the south-west stone once to equalize the load vectors."));

	// Initialize 4 granite course blocks
	CourseBlocks.Empty();

	FGKStoneCourseBlock B0;
	B0.BlockID = 0;
	B0.BlockName = LOCTEXT("B0Name", "North-West Course Stone");
	B0.TargetOrientationQuarterTurns = 1;
	B0.CurrentOrientationQuarterTurns = 0;
	CourseBlocks.Add(B0);

	FGKStoneCourseBlock B1;
	B1.BlockID = 1;
	B1.BlockName = LOCTEXT("B1Name", "North-East Course Stone");
	B1.TargetOrientationQuarterTurns = 2;
	B1.CurrentOrientationQuarterTurns = 3;
	CourseBlocks.Add(B1);

	FGKStoneCourseBlock B2;
	B2.BlockID = 2;
	B2.BlockName = LOCTEXT("B2Name", "South-East Course Stone");
	B2.TargetOrientationQuarterTurns = 0;
	B2.CurrentOrientationQuarterTurns = 2;
	CourseBlocks.Add(B2);

	FGKStoneCourseBlock B3;
	B3.BlockID = 3;
	B3.BlockName = LOCTEXT("B3Name", "South-West Course Stone");
	B3.TargetOrientationQuarterTurns = 3;
	B3.CurrentOrientationQuarterTurns = 1;
	CourseBlocks.Add(B3);

	RecalculateLoadPaths();
}

void AGKStoneAlignmentPuzzleActor::BeginPlay()
{
	Super::BeginPlay();
	RecalculateLoadPaths();
}

void AGKStoneAlignmentPuzzleActor::OnResetPuzzleElements()
{
	if (CourseBlocks.IsValidIndex(0)) CourseBlocks[0].CurrentOrientationQuarterTurns = 0;
	if (CourseBlocks.IsValidIndex(1)) CourseBlocks[1].CurrentOrientationQuarterTurns = 3;
	if (CourseBlocks.IsValidIndex(2)) CourseBlocks[2].CurrentOrientationQuarterTurns = 2;
	if (CourseBlocks.IsValidIndex(3)) CourseBlocks[3].CurrentOrientationQuarterTurns = 1;

	RecalculateLoadPaths();
}

bool AGKStoneAlignmentPuzzleActor::RotateBlockClockwise(int32 BlockIndex)
{
	if (!CourseBlocks.IsValidIndex(BlockIndex))
	{
		return false;
	}

	CourseBlocks[BlockIndex].CurrentOrientationQuarterTurns =
		(CourseBlocks[BlockIndex].CurrentOrientationQuarterTurns + 1) % 4;

	RecalculateLoadPaths();

	OnStoneBlockRotated.Broadcast(
		BlockIndex,
		CourseBlocks[BlockIndex].CurrentOrientationQuarterTurns,
		CourseBlocks[BlockIndex].LoadStressRatio
	);

	UE_LOG(LogGKPuzzle, Log, TEXT("Stone [%d] rotated to %d deg. Stress ratio: %.2f"),
		BlockIndex, CourseBlocks[BlockIndex].CurrentOrientationQuarterTurns * 90,
		CourseBlocks[BlockIndex].LoadStressRatio);

	// Check if all blocks are aligned
	AttemptSolve_Implementation();
	return true;
}

void AGKStoneAlignmentPuzzleActor::RecalculateLoadPaths()
{
	for (FGKStoneCourseBlock& Block : CourseBlocks)
	{
		const int32 Diff = FMath::Abs(Block.CurrentOrientationQuarterTurns - Block.TargetOrientationQuarterTurns);
		const int32 MinDistance = FMath::Min(Diff, 4 - Diff);

		Block.LoadStressRatio = (float)MinDistance / 2.0f; // 0.0 (aligned), 0.5 (90 deg off), 1.0 (180 deg off)
		Block.bIsCracking = (Block.LoadStressRatio >= StressWarningThreshold);
	}
}

float AGKStoneAlignmentPuzzleActor::GetTotalCourseImbalance() const
{
	float Total = 0.0f;
	for (const FGKStoneCourseBlock& Block : CourseBlocks)
	{
		Total += Block.LoadStressRatio;
	}
	return Total;
}

bool AGKStoneAlignmentPuzzleActor::EvaluateSolutionConditions()
{
	for (const FGKStoneCourseBlock& Block : CourseBlocks)
	{
		if (Block.CurrentOrientationQuarterTurns != Block.TargetOrientationQuarterTurns)
		{
			return false;
		}
	}
	return true;
}

void AGKStoneAlignmentPuzzleActor::SetVisualAssistActive(bool bActive)
{
	bVisualAssistActive = bActive;
	UE_LOG(LogGKPuzzle, Log, TEXT("Stone Alignment visual notch assistance: %s"),
		bActive ? TEXT("Enabled") : TEXT("Disabled"));
}

#undef LOCTEXT_NAMESPACE
