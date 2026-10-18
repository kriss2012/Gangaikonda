#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IGKMemoryHolder.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UGKMemoryHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by characters/NPCs that maintain bounded memory flags.
 * Governs NPC reactions, dialogue branching, and investigation outcomes (Doc 13 §4, Doc 18 §4).
 */
class GKCORE_API IGKMemoryHolder
{
	GENERATED_BODY()

public:
	/**
	 * Queries a specific boolean memory flag.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Memory")
	bool GetMemoryFlag(FName FlagKey, bool& OutValue) const;

	/**
	 * Sets a specific boolean memory flag.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Memory")
	void SetMemoryFlag(FName FlagKey, bool Value);

	/**
	 * Returns all memory flags currently held by this entity for debugging/serialization.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Memory")
	TMap<FName, bool> GetAllMemoryFlags() const;
};
