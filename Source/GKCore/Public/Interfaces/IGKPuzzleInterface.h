#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GKCoreTypes.h"
#include "IGKPuzzleInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UGKPuzzleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by all puzzle actor types.
 * Allows Save, Quest, and UI modules to interact generically with puzzles without per-type branching (Doc 18 §4).
 */
class GKCORE_API IGKPuzzleInterface
{
	GENERATED_BODY()

public:
	/**
	 * Queries current puzzle state.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Puzzle")
	EGKPuzzleState GetPuzzleState() const;

	/**
	 * Attempts to evaluate puzzle solution.
	 * @return True if solution conditions are satisfied.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Puzzle")
	bool AttemptSolve();

	/**
	 * Resets puzzle elements to their default initial state.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Puzzle")
	void ResetPuzzle();

	/**
	 * Retrieves structured hint content for the specified hint tier (Tiers 1-3, Doc 09/Doc 20 §11).
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Puzzle")
	FText GetPuzzleHint(int32 HintTier) const;
};
