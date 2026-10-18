#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GKSaveGame.h"
#include "GKSaveSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKSaveCompleted, const FString&, SlotName, bool, bSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKLoadCompleted, const FString&, SlotName, bool, bSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKAutosaveTriggered, FName, ReasonTag);

/**
 * Global game subsystem orchestrating save/load operations, autosaves,
 * and serialization across all gameplay subsystems (Doc 18 §6).
 * Enforces non-combat manual save restrictions and bounds NPC memory payloads.
 */
UCLASS(BlueprintType)
class GKSAVE_API UGKSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGKSaveSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Convenience static accessor */
	UFUNCTION(BlueprintPure, Category = "GK|Save", meta = (WorldContext = "WorldContextObject"))
	static UGKSaveSubsystem* Get(const UObject* WorldContextObject);

	/**
	 * Saves the full game simulation state to a slot.
	 * Fails if player is currently engaged in combat (Doc 18 §6).
	 * @return True if save operation succeeded.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	bool SaveGame(const FString& InSlotName = TEXT("ManualSave_0"), int32 InUserIndex = 0);

	/**
	 * Loads game state from a slot and dispatches data to all respective subsystems.
	 * @return True if load operation succeeded.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	bool LoadGame(const FString& InSlotName = TEXT("ManualSave_0"), int32 InUserIndex = 0);

	/**
	 * Triggers an autosave on quest transitions or major zone streaming (Doc 18 §6).
	 * Bypasses manual slot naming with reserved "Autosave_Current" slot.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	bool TriggerAutosave(FName ReasonTag);

	/**
	 * Verifies whether saving is currently permitted.
	 * Fails if player is in combat, dead, or locked in critical cinematic (Doc 18 §6).
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Save")
	bool CanSave() const;

	/** Checks if a valid save file exists at the given slot */
	UFUNCTION(BlueprintPure, Category = "GK|Save")
	bool DoesSaveExist(const FString& InSlotName = TEXT("ManualSave_0"), int32 InUserIndex = 0) const;

	/** Deletes a save slot */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	bool DeleteSave(const FString& InSlotName = TEXT("ManualSave_0"), int32 InUserIndex = 0);

	/** Registers an NPC memory holder actor/component for save gathering */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	void RegisterNPC(FName NPCID, UObject* MemoryHolder);

	/** Unregisters an NPC memory holder */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	void UnregisterNPC(FName NPCID);

	/** Registers a puzzle actor for state tracking */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	void RegisterPuzzle(FName PuzzleID, UObject* PuzzleActor);

	/** Unregisters a puzzle actor */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	void UnregisterPuzzle(FName PuzzleID);

	/** Explicitly sets combat flag for save gating */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	void SetInCombat(bool bInCombat);

	/** Returns true if player is considered in combat */
	UFUNCTION(BlueprintPure, Category = "GK|Save")
	bool IsInCombat() const { return bPlayerInCombat; }

	/**
	 * Populates a UGKSaveGame object with current live state without writing to disk.
	 * Useful for profiling and fast serialization spikes.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	UGKSaveGame* CreateSaveSnapshot(const FString& InSlotName = TEXT("Snapshot"));

	/**
	 * Applies a UGKSaveGame snapshot directly to live subsystems.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	bool ApplySaveSnapshot(UGKSaveGame* InSaveGame);

	/**
	 * Measures exact serialization payload size in bytes for a save object (Doc 18 §6 technical spike).
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Save")
	int32 MeasureSavePayloadBytes(UGKSaveGame* InSaveGame) const;

	UPROPERTY(BlueprintAssignable, Category = "GK|Save")
	FOnGKSaveCompleted OnSaveCompleted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Save")
	FOnGKLoadCompleted OnLoadCompleted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Save")
	FOnGKAutosaveTriggered OnAutosaveTriggered;

	static const FString AutosaveSlotName;

private:
	/** Tracked NPCs implementing IGKMemoryHolder */
	UPROPERTY(Transient)
	TMap<FName, TWeakObjectPtr<UObject>> RegisteredNPCs;

	/** Tracked puzzles implementing IGKPuzzleInterface */
	UPROPERTY(Transient)
	TMap<FName, TWeakObjectPtr<UObject>> RegisteredPuzzles;

	/** Combat status flag gating manual saves */
	UPROPERTY(Transient)
	bool bPlayerInCombat;

	void GatherSubsystemState(UGKSaveGame* SaveObject);
	void DispatchSubsystemState(const UGKSaveGame* SaveObject);
};
