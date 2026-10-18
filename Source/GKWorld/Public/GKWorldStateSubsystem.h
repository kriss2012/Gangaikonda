#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GKWorldTypes.h"
#include "GKWorldStateSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKConstructionStageChanged, FName, LocationID, EGKConstructionStage, NewStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKFactionReputationChanged, FName, FactionID, EGKFactionReputation, NewReputation);

/**
 * Global game subsystem managing dynamic world simulation state (Doc 13 §5, Doc 18 §6).
 * Persists across level streaming, tracking monumental construction progress
 * and non-numeric faction relationships across the Chola realm.
 */
UCLASS(BlueprintType)
class GKWORLD_API UGKWorldStateSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGKWorldStateSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Convenience static accessor */
	UFUNCTION(BlueprintPure, Category = "GK|World", meta = (WorldContext = "WorldContextObject"))
	static UGKWorldStateSubsystem* Get(const UObject* WorldContextObject);

	/** Sets construction progress milestone for a location */
	UFUNCTION(BlueprintCallable, Category = "GK|World")
	void SetConstructionStage(FName LocationID, EGKConstructionStage NewStage);

	/** Queries current construction stage for a location */
	UFUNCTION(BlueprintPure, Category = "GK|World")
	EGKConstructionStage GetConstructionStage(FName LocationID) const;

	/** Gets all location construction stages (for serialization & debug overlay) */
	UFUNCTION(BlueprintPure, Category = "GK|World")
	const TMap<FName, EGKConstructionStage>& GetAllConstructionStages() const { return ConstructionStages; }

	/** Sets non-numeric faction reputation standing (Doc 01 §23, Doc 14) */
	UFUNCTION(BlueprintCallable, Category = "GK|World")
	void SetFactionReputation(FName FactionID, EGKFactionReputation NewReputation);

	/** Queries current faction reputation */
	UFUNCTION(BlueprintPure, Category = "GK|World")
	EGKFactionReputation GetFactionReputation(FName FactionID) const;

	/** Gets all faction standings (for serialization & debug overlay) */
	UFUNCTION(BlueprintPure, Category = "GK|World")
	const TMap<FName, EGKFactionReputation>& GetAllFactionReputations() const { return FactionReputations; }

	/** Restores world simulation state from save game data (Doc 18 §6) */
	UFUNCTION(BlueprintCallable, Category = "GK|World")
	void RestoreWorldState(const TMap<FName, EGKConstructionStage>& InStages, const TMap<FName, EGKFactionReputation>& InReputations);

	/** Resets world state to vertical slice baseline defaults */
	UFUNCTION(BlueprintCallable, Category = "GK|World")
	void ResetToDefaults();

	/** Broadcast when monumental construction advances */
	UPROPERTY(BlueprintAssignable, Category = "GK|World")
	FOnGKConstructionStageChanged OnConstructionStageChanged;

	/** Broadcast when faction standings shift */
	UPROPERTY(BlueprintAssignable, Category = "GK|World")
	FOnGKFactionReputationChanged OnFactionReputationChanged;

private:
	/** Tracked construction stage per location */
	UPROPERTY(SaveGame)
	TMap<FName, EGKConstructionStage> ConstructionStages;

	/** Non-numeric reputation standing per faction */
	UPROPERTY(SaveGame)
	TMap<FName, EGKFactionReputation> FactionReputations;
};
