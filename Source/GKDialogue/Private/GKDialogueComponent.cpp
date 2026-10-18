#include "GKDialogueComponent.h"
#include "Interfaces/IGKMemoryHolder.h"
#include "GKCodexSubsystem.h"
#include "GKLogChannels.h"

UGKDialogueComponent::UGKDialogueComponent()
	: bIsInDialogue(false)
	, CurrentNodeID(0)
	, ParticipantNPC(nullptr)
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UGKDialogueComponent::StartDialogue(const FGKDialogueTree& DialogueTree, AActor* InParticipantNPC)
{
	if (DialogueTree.Nodes.Num() == 0 || !DialogueTree.Nodes.Contains(DialogueTree.EntryNodeID))
	{
		UE_LOG(LogGKDialogue, Warning, TEXT("StartDialogue failed: Tree '%s' is empty or has invalid EntryNodeID."),
			*DialogueTree.TreeID.ToString());
		return false;
	}

	CurrentTree = DialogueTree;
	ParticipantNPC = InParticipantNPC;
	bIsInDialogue = true;

	UE_LOG(LogGKDialogue, Log, TEXT("Dialogue started: Tree '%s' with NPC '%s'"),
		*CurrentTree.TreeID.ToString(), InParticipantNPC ? *InParticipantNPC->GetName() : TEXT("None"));

	AdvanceToNode(CurrentTree.EntryNodeID);
	return true;
}

void UGKDialogueComponent::AdvanceToNode(int32 TargetNodeID)
{
	if (!CurrentTree.Nodes.Contains(TargetNodeID))
	{
		UE_LOG(LogGKDialogue, Log, TEXT("Target node %d not found or exit reached. Ending dialogue."), TargetNodeID);
		EndDialogue();
		return;
	}

	CurrentNodeID = TargetNodeID;
	const FGKDialogueNode& CurrentNode = CurrentTree.Nodes[CurrentNodeID];

	OnNodeChanged.Broadcast(CurrentNode);

	if (CurrentNode.bIsExitNode)
	{
		EndDialogue();
		return;
	}

	const TArray<FGKDialogueOption> AvailableOptions = GetAvailableOptions();
	OnOptionsUpdated.Broadcast(AvailableOptions);
}

bool UGKDialogueComponent::SelectOption(int32 OptionIndex)
{
	if (!bIsInDialogue)
	{
		return false;
	}

	const TArray<FGKDialogueOption> AvailableOptions = GetAvailableOptions();
	if (!AvailableOptions.IsValidIndex(OptionIndex))
	{
		UE_LOG(LogGKDialogue, Warning, TEXT("SelectOption: Invalid index %d."), OptionIndex);
		return false;
	}

	const FGKDialogueOption Selected = AvailableOptions[OptionIndex];

	// 1. Write memory flag if specified (Doc 13 §4)
	if (!Selected.MemoryFlagToSet.IsNone() && ParticipantNPC.IsValid())
	{
		if (ParticipantNPC->Implements<UGKMemoryHolder>())
		{
			IGKMemoryHolder::Execute_SetMemoryFlag(ParticipantNPC.Get(), Selected.MemoryFlagToSet, Selected.bValueToSet);
		}
	}

	// 2. Unlock Codex entry if specified
	if (!Selected.EvidenceIDToUnlock.IsNone())
	{
		if (UGKCodexSubsystem* CodexSubsystem = UGKCodexSubsystem::Get(this))
		{
			CodexSubsystem->UnlockEntry(Selected.EvidenceIDToUnlock);
		}
	}

	UE_LOG(LogGKDialogue, Log, TEXT("Dialogue choice selected: [%d] -> Next Node: %d (Flag: %s)"),
		Selected.OptionID, Selected.NextNodeID, *Selected.MemoryFlagToSet.ToString());

	// 3. Advance to next node or exit
	if (Selected.NextNodeID < 0)
	{
		EndDialogue();
	}
	else
	{
		AdvanceToNode(Selected.NextNodeID);
	}

	return true;
}

void UGKDialogueComponent::EndDialogue()
{
	if (!bIsInDialogue)
	{
		return;
	}

	bIsInDialogue = false;
	CurrentNodeID = -1;
	UE_LOG(LogGKDialogue, Log, TEXT("Dialogue ended for tree '%s'."), *CurrentTree.TreeID.ToString());
	OnDialogueEnded.Broadcast();
}

bool UGKDialogueComponent::GetCurrentNode(FGKDialogueNode& OutNode) const
{
	if (bIsInDialogue && CurrentTree.Nodes.Contains(CurrentNodeID))
	{
		OutNode = CurrentTree.Nodes[CurrentNodeID];
		return true;
	}
	return false;
}

TArray<FGKDialogueOption> UGKDialogueComponent::GetAvailableOptions() const
{
	TArray<FGKDialogueOption> Filtered;

	if (!bIsInDialogue || !CurrentTree.Nodes.Contains(CurrentNodeID))
	{
		return Filtered;
	}

	const FGKDialogueNode& Node = CurrentTree.Nodes[CurrentNodeID];
	for (const FGKDialogueOption& Option : Node.Options)
	{
		if (CheckOptionCondition(Option))
		{
			Filtered.Add(Option);
		}
	}

	return Filtered;
}

bool UGKDialogueComponent::CheckOptionCondition(const FGKDialogueOption& Option) const
{
	if (Option.MemoryFlagCondition.IsNone())
	{
		return true;
	}

	if (!ParticipantNPC.IsValid() || !ParticipantNPC->Implements<UGKMemoryHolder>())
	{
		return false;
	}

	bool bFlagValue = false;
	IGKMemoryHolder::Execute_GetMemoryFlag(ParticipantNPC.Get(), Option.MemoryFlagCondition, bFlagValue);
	return bFlagValue == Option.bRequiredConditionValue;
}
