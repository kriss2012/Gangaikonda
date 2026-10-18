#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GKQuestTypes.h"
#include "GKQuestDataAsset.h"
#include "GKQuestSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKQuestStarted, FName, QuestID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKObjectiveCompleted, FName, QuestID, FName, ObjectiveID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKQuestCompleted, FName, QuestID);

/**
 * Global game instance subsystem driving the data-driven quest state machine (Doc 18 §2 & §5).
 * Persists across level streaming, broadcasts completion events, unlocks Codex rewards, and integrates with UGKSaveGame.
 */
UCLASS(BlueprintType)
class GKQUEST_API UGKQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGKQuestSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Convenience accessor to get subsystem instance */
	UFUNCTION(BlueprintPure, Category = "GK|Quest", meta = (WorldContext = "WorldContextObject"))
	static UGKQuestSubsystem* Get(const UObject* WorldContextObject);

	/** Registers a quest data asset into the runtime database */
	UFUNCTION(BlueprintCallable, Category = "GK|Quest")
	void RegisterQuest(UGKQuestDataAsset* QuestAsset);

	/** Begins a quest, activating its first objective */
	UFUNCTION(BlueprintCallable, Category = "GK|Quest")
	bool StartQuest(FName QuestID);

	/** Completes a specific objective within an active quest */
	UFUNCTION(BlueprintCallable, Category = "GK|Quest")
	bool CompleteObjective(FName QuestID, FName ObjectiveID);

	/** Completes an overall quest, unlocking all associated Codex entries and broadcasting events */
	UFUNCTION(BlueprintCallable, Category = "GK|Quest")
	bool CompleteQuest(FName QuestID);

	/** Queries current quest lifecycle state */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	EGKQuestState GetQuestState(FName QuestID) const;

	/** Returns the currently active main quest identifier */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	FName GetActiveQuestID() const { return CurrentActiveQuestID; }

	/** Retrieves data asset for currently active quest */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	UGKQuestDataAsset* GetActiveQuestData() const;

	/** Retrieves all objectives with current runtime states for a quest */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	TArray<FGKQuestObjective> GetQuestObjectives(FName QuestID) const;

	/** Returns true if a quest is completed */
	UFUNCTION(BlueprintPure, Category = "GK|Quest")
	bool IsQuestCompleted(FName QuestID) const { return GetQuestState(QuestID) == EGKQuestState::Completed; }

	// Save / Load state serialization hooks (Doc 18 §6)
	const TMap<FName, EGKQuestState>& GetSavedQuestStates() const { return QuestStates; }

	UFUNCTION(BlueprintCallable, Category = "GK|Quest")
	void RestoreQuestStates(const TMap<FName, EGKQuestState>& InStates, FName InActiveQuestID);

	/** Dependency injection hook for mock Codex subsystem in tests */
	void SetCodexSubsystem(class UGKCodexSubsystem* InSubsystem) { CodexSubsystemOverride = InSubsystem; }

	UPROPERTY(BlueprintAssignable, Category = "GK|Quest")
	FOnGKQuestStarted OnQuestStarted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Quest")
	FOnGKObjectiveCompleted OnObjectiveCompleted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Quest")
	FOnGKQuestCompleted OnQuestCompleted;

private:
	/** Registered quest definitions */
	UPROPERTY()
	TMap<FName, TObjectPtr<UGKQuestDataAsset>> RegisteredQuests;

	/** Quest states map (persisted in save game) */
	UPROPERTY(SaveGame)
	TMap<FName, EGKQuestState> QuestStates;

	/** Active objective progress per quest */
	UPROPERTY(SaveGame)
	TMap<FName, FGKQuestObjectiveList> RuntimeObjectives;

	/** Active quest ID */
	UPROPERTY(SaveGame)
	FName CurrentActiveQuestID;

	UPROPERTY(Transient)
	TObjectPtr<class UGKCodexSubsystem> CodexSubsystemOverride;

	void LoadDefaultQuests();
};
