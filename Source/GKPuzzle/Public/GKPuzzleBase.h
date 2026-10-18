#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GKCoreTypes.h"
#include "Interfaces/IGKPuzzleInterface.h"
#include "GKPuzzleBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKPuzzleStateChanged, AGKPuzzleActor*, PuzzleActor, EGKPuzzleState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKPuzzleSolved, AGKPuzzleActor*, PuzzleActor, FName, EvidenceRewardID);

/**
 * Shared C++ base for all puzzle actor types in GANGAIKONDA (Doc 18 §2 & §4).
 * Implements IGKPuzzleInterface so Save, Quest, and UI systems interact generically.
 */
UCLASS(Abstract)
class GKPUZZLE_API AGKPuzzleActor : public AActor, public IGKPuzzleInterface
{
	GENERATED_BODY()

public:
	AGKPuzzleActor();

	/** Unique puzzle identifier */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Puzzle")
	FName PuzzleID;

	/** Associated historical evidence unlocked upon solving this puzzle */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Puzzle")
	FName EvidenceRewardID;

	/** Three-tier hint strings per Doc 09 and Doc 20 §11 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Puzzle")
	TArray<FText> HintTiers;

	/** Current operational state of the puzzle */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Puzzle")
	EGKPuzzleState CurrentPuzzleState;

	// IGKPuzzleInterface implementation
	virtual EGKPuzzleState GetPuzzleState_Implementation() const override;
	virtual bool AttemptSolve_Implementation() override;
	virtual void ResetPuzzle_Implementation() override;
	virtual FText GetPuzzleHint_Implementation(int32 HintTier) const override;

	/** Sets puzzle state and broadcasts updates */
	UFUNCTION(BlueprintCallable, Category = "GK|Puzzle")
	virtual void SetPuzzleState(EGKPuzzleState NewState);

	UPROPERTY(BlueprintAssignable, Category = "GK|Puzzle")
	FOnGKPuzzleStateChanged OnPuzzleStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "GK|Puzzle")
	FOnGKPuzzleSolved OnPuzzleSolved;

protected:
	/** Hook for derived puzzle types to evaluate specific solution logic */
	virtual bool EvaluateSolutionConditions();

	/** Hook for derived puzzle types to reset their unique elements */
	virtual void OnResetPuzzleElements();
};
