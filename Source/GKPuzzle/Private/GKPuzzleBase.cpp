#include "GKPuzzleBase.h"
#include "GKCodexSubsystem.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "GKPuzzleBase"

AGKPuzzleActor::AGKPuzzleActor()
	: PuzzleID(NAME_None)
	, EvidenceRewardID(NAME_None)
	, CurrentPuzzleState(EGKPuzzleState::Unsolved)
{
	PrimaryActorTick.bCanEverTick = false;

	// Populate three standard fallback hint tiers
	HintTiers.Add(LOCTEXT("DefaultHint1", "Examine the materials and sequence carefully."));
	HintTiers.Add(LOCTEXT("DefaultHint2", "Look for alignment marks or comparative script traits."));
	HintTiers.Add(LOCTEXT("DefaultHint3", "The correct placement directly balances the structure."));
}

EGKPuzzleState AGKPuzzleActor::GetPuzzleState_Implementation() const
{
	return CurrentPuzzleState;
}

bool AGKPuzzleActor::AttemptSolve_Implementation()
{
	if (CurrentPuzzleState == EGKPuzzleState::Solved)
	{
		return true;
	}

	const bool bSolved = EvaluateSolutionConditions();
	if (bSolved)
	{
		SetPuzzleState(EGKPuzzleState::Solved);

		// Unlock associated Codex entry if configured
		if (!EvidenceRewardID.IsNone())
		{
			if (UGKCodexSubsystem* CodexSubsystem = UGKCodexSubsystem::Get(this))
			{
				CodexSubsystem->UnlockEntry(EvidenceRewardID);
			}
		}

		OnPuzzleSolved.Broadcast(this, EvidenceRewardID);
		UE_LOG(LogGKPuzzle, Log, TEXT("Puzzle '%s' successfully SOLVED! Unlocked reward: %s"),
			*PuzzleID.ToString(), *EvidenceRewardID.ToString());
		return true;
	}

	SetPuzzleState(EGKPuzzleState::InProgress);
	UE_LOG(LogGKPuzzle, Verbose, TEXT("Puzzle '%s' solution attempt incomplete."), *PuzzleID.ToString());
	return false;
}

void AGKPuzzleActor::ResetPuzzle_Implementation()
{
	if (CurrentPuzzleState == EGKPuzzleState::Solved)
	{
		return;
	}

	OnResetPuzzleElements();
	SetPuzzleState(EGKPuzzleState::Unsolved);
	UE_LOG(LogGKPuzzle, Log, TEXT("Puzzle '%s' reset to initial state."), *PuzzleID.ToString());
}

FText AGKPuzzleActor::GetPuzzleHint_Implementation(int32 HintTier) const
{
	const int32 ClampedIndex = FMath::Clamp(HintTier - 1, 0, HintTiers.Num() - 1);
	if (HintTiers.IsValidIndex(ClampedIndex))
	{
		return HintTiers[ClampedIndex];
	}

	return LOCTEXT("NoHintAvailable", "No hint available for this tier.");
}

void AGKPuzzleActor::SetPuzzleState(EGKPuzzleState NewState)
{
	if (CurrentPuzzleState != NewState)
	{
		CurrentPuzzleState = NewState;
		OnPuzzleStateChanged.Broadcast(this, NewState);
	}
}

bool AGKPuzzleActor::EvaluateSolutionConditions()
{
	// Overridden by derived puzzle types
	return false;
}

void AGKPuzzleActor::OnResetPuzzleElements()
{
	// Overridden by derived puzzle types
}

#undef LOCTEXT_NAMESPACE
