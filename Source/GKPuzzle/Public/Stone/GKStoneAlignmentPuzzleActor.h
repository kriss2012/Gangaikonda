#pragma once

#include "CoreMinimal.h"
#include "GKPuzzleBase.h"
#include "Components/StaticMeshComponent.h"
#include "GKStoneAlignmentPuzzleActor.generated.h"

/**
 * Data representing an individual granite block in the course (Doc 09 P01).
 */
USTRUCT(BlueprintType)
struct FGKStoneCourseBlock
{
	GENERATED_BODY()

	FGKStoneCourseBlock()
		: BlockID(0)
		, CurrentOrientationQuarterTurns(0)
		, TargetOrientationQuarterTurns(0)
		, LoadStressRatio(0.0f)
		, bIsCracking(false)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|StonePuzzle")
	int32 BlockID;

	/** Name or marker on the stone (e.g. North-West Course Block) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|StonePuzzle")
	FText BlockName;

	/** Current rotation in 90-degree increments (0 = 0°, 1 = 90°, 2 = 180°, 3 = 270°) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|StonePuzzle")
	int32 CurrentOrientationQuarterTurns;

	/** Correct rotation in 90-degree increments that balances the load-path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|StonePuzzle")
	int32 TargetOrientationQuarterTurns;

	/** Calculated stress ratio (0.0 to 1.0); values > 0.6 indicate dangerous uneven load */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|StonePuzzle")
	float LoadStressRatio;

	/** True if excessive load is causing visible hairline fissures */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|StonePuzzle")
	bool bIsCracking;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnStoneBlockRotated, int32, BlockIndex, int32, NewQuarterTurns, float, NewStress);

/**
 * Stone Alignment Tier 1: Course of Four (Doc 09 P01, Doc 08 Minutes 23–27).
 * Simulates dry-joint load-bearing Dravidian granite construction.
 * Players rotate 4 massive granite blocks until load vectors balance across mortise-tenon contact points.
 */
UCLASS(BlueprintType)
class GKPUZZLE_API AGKStoneAlignmentPuzzleActor : public AGKPuzzleActor
{
	GENERATED_BODY()

public:
	AGKStoneAlignmentPuzzleActor();

	/** Array of 4 granite course blocks */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|StonePuzzle")
	TArray<FGKStoneCourseBlock> CourseBlocks;

	/** Threshold stress ratio above which blocks show cracking feedback */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|StonePuzzle")
	float StressWarningThreshold;

	/** Rotates a specific block clockwise by 90 degrees and recalculates course load paths */
	UFUNCTION(BlueprintCallable, Category = "GK|StonePuzzle")
	bool RotateBlockClockwise(int32 BlockIndex);

	/** Returns true if visual accessibility assistance is active (Doc 37) */
	UFUNCTION(BlueprintPure, Category = "GK|StonePuzzle")
	bool IsVisualAssistActive() const { return bVisualAssistActive; }

	/** Toggles mortise contact notch visual assistance (Doc 37 accessibility) */
	UFUNCTION(BlueprintCallable, Category = "GK|StonePuzzle")
	void SetVisualAssistActive(bool bActive);

	/** Computes the global load imbalance across the 4 blocks */
	UFUNCTION(BlueprintPure, Category = "GK|StonePuzzle")
	float GetTotalCourseImbalance() const;

	UPROPERTY(BlueprintAssignable, Category = "GK|StonePuzzle")
	FOnStoneBlockRotated OnStoneBlockRotated;

protected:
	virtual void BeginPlay() override;
	virtual bool EvaluateSolutionConditions() override;
	virtual void OnResetPuzzleElements() override;

	void RecalculateLoadPaths();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|StonePuzzle")
	bool bVisualAssistActive;
};
