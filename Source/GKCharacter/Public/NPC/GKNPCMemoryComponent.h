#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/IGKMemoryHolder.h"
#include "GKNPCMemoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNPCMemoryFlagChanged, FName, FlagKey, bool, NewValue);

/**
 * Bounded memory component implementing IGKMemoryHolder (Doc 13 §4, Doc 18 §4).
 * Stores a strictly capped number of boolean flags per NPC to prevent save bloat and preserve dramatic clarity.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKCHARACTER_API UGKNPCMemoryComponent : public UActorComponent, public IGKMemoryHolder
{
	GENERATED_BODY()

public:
	UGKNPCMemoryComponent();

	/** Maximum allowed memory flags per NPC (enforces Doc 13 §4 budget) */
	static constexpr int32 MaxMemoryFlags = 32;

	// IGKMemoryHolder implementation
	virtual bool GetMemoryFlag_Implementation(FName FlagKey, bool& OutValue) const override;
	virtual void SetMemoryFlag_Implementation(FName FlagKey, bool Value) override;
	virtual TMap<FName, bool> GetAllMemoryFlags_Implementation() const override;

	/** Direct C++ accessor for fast queries */
	UFUNCTION(BlueprintPure, Category = "GK|Memory")
	bool HasMemoryFlag(FName FlagKey) const;

	/** Direct C++ accessor for flag value */
	UFUNCTION(BlueprintPure, Category = "GK|Memory")
	bool ReadMemoryFlag(FName FlagKey, bool DefaultValue = false) const;

	/** Restores memory state from save data (Doc 18 §6) */
	UFUNCTION(BlueprintCallable, Category = "GK|Memory")
	void RestoreMemoryFlags(const TMap<FName, bool>& InFlags);

	UPROPERTY(BlueprintAssignable, Category = "GK|Memory")
	FOnNPCMemoryFlagChanged OnMemoryFlagChanged;

protected:
	/** Bounded persistent memory flags */
	UPROPERTY(SaveGame, VisibleAnywhere, Category = "GK|Memory")
	TMap<FName, bool> BoundedMemoryFlags;
};
