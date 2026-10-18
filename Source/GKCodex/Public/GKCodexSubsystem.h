#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GKCodexTypes.h"
#include "GKCodexViewModel.h"
#include "GKCodexSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKCodexEntryUnlocked, const FGKEvidenceRow&, UnlockedEntry);

/**
 * Global game subsystem managing unlocked historical Codex records.
 * Acts as the authoritative link between DT_HistoricalEvidence and gameplay/UI.
 * Persists across level streaming and integrates directly with UGKSaveGame.
 */
UCLASS(BlueprintType)
class GKCODEX_API UGKCodexSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGKCodexSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/**
	 * Convenience accessor to retrieve the subsystem instance.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex", meta = (WorldContext = "WorldContextObject"))
	static UGKCodexSubsystem* Get(const UObject* WorldContextObject);

	/**
	 * Unlocks a historical record by EvidenceID (e.g., A1, B2).
	 * Broadcasts OnEntryUnlocked if newly unlocked.
	 * @return True if the entry was newly unlocked, false if already unlocked or invalid.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Codex")
	bool UnlockEntry(FName EvidenceID);

	/**
	 * Checks if a specific evidence record has already been discovered/unlocked.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	bool IsUnlocked(FName EvidenceID) const;

	/**
	 * Retrieves the authentic source row directly from DT_HistoricalEvidence.
	 * @return True if the row exists in the data table.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	bool GetEvidenceRow(FName EvidenceID, FGKEvidenceRow& OutRow) const;

	/**
	 * Returns an array of all currently unlocked evidence rows.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	TArray<FGKEvidenceRow> GetAllUnlockedEntries() const;

	/**
	 * Returns unlocked evidence rows filtered strictly by category.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	TArray<FGKEvidenceRow> GetUnlockedEntriesByCategory(EGKEvidenceCategory Category) const;

	/**
	 * Returns presentation ViewModels for all unlocked entries (enforcing no-upgrade rule).
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Codex")
	TArray<UGKCodexEntryViewModel*> GetUnlockedViewModels(UObject* Outer);

	/**
	 * Returns number of unlocked records.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	int32 GetUnlockedCount() const { return UnlockedEntryIDs.Num(); }

	/**
	 * Returns total number of registered evidence rows in DT_HistoricalEvidence.
	 */
	UFUNCTION(BlueprintPure, Category = "GK|Codex")
	int32 GetTotalCount() const;

	/**
	 * Returns raw set of unlocked IDs for save game serialization (Doc 18 §6).
	 */
	const TSet<FName>& GetUnlockedEntryIDs() const { return UnlockedEntryIDs; }

	/**
	 * Restores unlocked state from save game data.
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Codex")
	void RestoreUnlockedEntries(const TSet<FName>& InUnlockedIDs);

	/**
	 * Explicitly sets or overrides the data table asset (used in tests or dynamic loading).
	 */
	UFUNCTION(BlueprintCallable, Category = "GK|Codex")
	void SetEvidenceDataTable(UDataTable* InTable);

	/**
	 * Broadcast event whenever a new historical record is discovered.
	 */
	UPROPERTY(BlueprintAssignable, Category = "GK|Codex")
	FOnGKCodexEntryUnlocked OnEntryUnlocked;

private:
	/** Loads and caches the evidence data table */
	UDataTable* ResolveEvidenceTable() const;

	/** Set of unlocked evidence identifiers */
	UPROPERTY(SaveGame)
	TSet<FName> UnlockedEntryIDs;

	/** Cached pointer to DT_HistoricalEvidence */
	UPROPERTY(Transient)
	mutable TObjectPtr<UDataTable> CachedEvidenceTable;

	/** Path to DT_HistoricalEvidence */
	static const FSoftObjectPath DefaultEvidenceTablePath;
};
