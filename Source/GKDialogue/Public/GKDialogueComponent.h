#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GKDialogueTypes.h"
#include "GKDialogueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKDialogueNodeChanged, const FGKDialogueNode&, NewNode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKDialogueOptionsUpdated, const TArray<FGKDialogueOption>&, AvailableOptions);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGKDialogueEnded);

/**
 * Branching dialogue runtime component (Doc 18 §2).
 * Drives subtitle delivery, option filtering via IGKMemoryHolder, memory flag mutation, and Codex unlocks.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKDIALOGUE_API UGKDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKDialogueComponent();

	/** Begins a dialogue conversation tree with an NPC */
	UFUNCTION(BlueprintCallable, Category = "GK|Dialogue")
	bool StartDialogue(const FGKDialogueTree& DialogueTree, AActor* InParticipantNPC);

	/** Selects a dialogue response option by index from the available list */
	UFUNCTION(BlueprintCallable, Category = "GK|Dialogue")
	bool SelectOption(int32 OptionIndex);

	/** Exits the current dialogue conversation */
	UFUNCTION(BlueprintCallable, Category = "GK|Dialogue")
	void EndDialogue();

	/** Returns true if a conversation is actively running */
	UFUNCTION(BlueprintPure, Category = "GK|Dialogue")
	bool IsInDialogue() const { return bIsInDialogue; }

	/** Retrieves the currently active spoken node */
	UFUNCTION(BlueprintPure, Category = "GK|Dialogue")
	bool GetCurrentNode(FGKDialogueNode& OutNode) const;

	/** Retrieves currently available options filtered by NPC memory conditions */
	UFUNCTION(BlueprintPure, Category = "GK|Dialogue")
	TArray<FGKDialogueOption> GetAvailableOptions() const;

	/** Currently interacting NPC actor */
	UFUNCTION(BlueprintPure, Category = "GK|Dialogue")
	AActor* GetParticipantNPC() const { return ParticipantNPC.Get(); }

	UPROPERTY(BlueprintAssignable, Category = "GK|Dialogue")
	FOnGKDialogueNodeChanged OnNodeChanged;

	UPROPERTY(BlueprintAssignable, Category = "GK|Dialogue")
	FOnGKDialogueOptionsUpdated OnOptionsUpdated;

	UPROPERTY(BlueprintAssignable, Category = "GK|Dialogue")
	FOnGKDialogueEnded OnDialogueEnded;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Dialogue")
	bool bIsInDialogue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Dialogue")
	FGKDialogueTree CurrentTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Dialogue")
	int32 CurrentNodeID;

	UPROPERTY()
	TWeakObjectPtr<AActor> ParticipantNPC;

private:
	bool CheckOptionCondition(const FGKDialogueOption& Option) const;
	void AdvanceToNode(int32 TargetNodeID);
};
