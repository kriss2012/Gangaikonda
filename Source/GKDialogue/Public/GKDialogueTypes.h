#pragma once

#include "CoreMinimal.h"
#include "GKCoreTypes.h"
#include "GKDialogueTypes.generated.h"

/**
 * An individual interactive dialogue choice presented to the player (Doc 20 §8).
 */
USTRUCT(BlueprintType)
struct GKDIALOGUE_API FGKDialogueOption
{
	GENERATED_BODY()

	FGKDialogueOption()
		: OptionID(0)
		, NextNodeID(-1)
		, MemoryFlagCondition(NAME_None)
		, bRequiredConditionValue(true)
		, MemoryFlagToSet(NAME_None)
		, bValueToSet(true)
		, bHasHistoricalClaim(false)
		, HistoricalCategory(EGKEvidenceCategory::Fictional)
		, EvidenceIDToUnlock(NAME_None)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	int32 OptionID;

	/** Player choice text displayed in the dialogue wheel/list */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FText OptionText;

	/** Next dialogue node ID to transition to (-1 indicates exit dialogue) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	int32 NextNodeID;

	/** Optional memory flag condition required for this choice to be selectable (Doc 13 §4) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName MemoryFlagCondition;

	/** Expected boolean value for the condition check */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	bool bRequiredConditionValue;

	/** Memory flag key set on the NPC when this choice is selected */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName MemoryFlagToSet;

	/** Boolean value written to the NPC memory */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	bool bValueToSet;

	/** True if this dialogue choice engages authentic historical evidence (Doc 20 §8) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	bool bHasHistoricalClaim;

	/** Evidence category indicator displayed alongside the dialogue choice */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	EGKEvidenceCategory HistoricalCategory;

	/** Optional EvidenceID to unlock in DT_HistoricalEvidence when chosen */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName EvidenceIDToUnlock;
};

/**
 * A single spoken node within a branching dialogue sequence.
 */
USTRUCT(BlueprintType)
struct GKDIALOGUE_API FGKDialogueNode
{
	GENERATED_BODY()

	FGKDialogueNode()
		: NodeID(0)
		, SpeakerID(NAME_None)
		, bIsExitNode(false)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	int32 NodeID;

	/** Identifier of the speaker (e.g. NPC_Scholar, NPC_Architect, Arulan) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName SpeakerID;

	/** Display name for subtitle header */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FText SpeakerDisplayName;

	/** Title or occupation (e.g. "Royal Epigraphist", "Chief Sthapati") */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FText SpeakerRoleTitle;

	/** Subtitle line delivered by the speaker */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FText SpokenText;

	/** Available player response options branching from this node */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	TArray<FGKDialogueOption> Options;

	/** True if selecting this node terminates the conversation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	bool bIsExitNode;
};

/**
 * Full authored dialogue tree for an encounter or NPC interaction.
 */
USTRUCT(BlueprintType)
struct GKDIALOGUE_API FGKDialogueTree
{
	GENERATED_BODY()

	FGKDialogueTree()
		: TreeID(NAME_None)
		, ParticipantNPCID(NAME_None)
		, EntryNodeID(0)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName TreeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	FName ParticipantNPCID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	TMap<int32, FGKDialogueNode> Nodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Dialogue")
	int32 EntryNodeID;
};
