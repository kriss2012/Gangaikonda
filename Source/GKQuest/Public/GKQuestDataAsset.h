#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GKCoreTypes.h"
#include "GKQuestTypes.h"
#include "GKQuestDataAsset.generated.h"

/**
 * DataAsset definition for a quest in GANGAIKONDA (Doc 18 §3).
 * Houses quest title, historical category tag, objective chain, and Codex reward references.
 */
UCLASS(BlueprintType)
class GKQUEST_API UGKQuestDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UGKQuestDataAsset();

	/** Unique quest identifier (e.g. MQ02, MQ11, VS_MainQuest) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	FName QuestID;

	/** Player-facing quest name */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	FText QuestTitle;

	/** Journal overview summary */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	FText QuestDescription;

	/** Story act number (1 to 12) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	int32 ActNumber;

	/** Historical category tag displayed in Quest Journal (Doc 20 §4) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	EGKEvidenceCategory HistoricalCategory;

	/** Sequential objectives comprising this quest */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	TArray<FGKQuestObjective> Objectives;

	/** Array of EvidenceIDs from DT_HistoricalEvidence unlocked upon quest completion */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	TArray<FName> CodexRewardIDs;

	/** Subsequent quest triggered upon completion */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	FName NextQuestID;

	/** Bounded world-state or NPC flags written on quest completion */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GK|Quest")
	TMap<FName, bool> CompletionWorldFlags;

	/** Finds an objective by ID; returns true if found */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	bool FindObjective(FName ObjectiveID, FGKQuestObjective& OutObjective) const;

	/** Returns index of objective by ID (-1 if not found) */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	int32 GetObjectiveIndex(FName ObjectiveID) const;
};
