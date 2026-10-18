#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IGKInvestigatable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UGKInvestigatable : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by any actor that can be investigated (inscriptions, ledgers, environmental clues).
 * Decouples the investigation system from concrete object types (Doc 18 §4, Doc 11 §6).
 */
class GKCORE_API IGKInvestigatable
{
	GENERATED_BODY()

public:
	/**
	 * Called when the player or investigator initiates investigation.
	 * @param Investigator The actor conducting the investigation (typically Arulan).
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Investigation")
	void OnInvestigate(AActor* Investigator);

	/**
	 * Returns whether the object can currently be investigated.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Investigation")
	bool CanInvestigate(AActor* Investigator) const;

	/**
	 * Returns prompt text to display on HUD (e.g., "Inspect Inscription", "Read Ledger").
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GK|Investigation")
	FText GetInvestigationPromptText() const;
};
