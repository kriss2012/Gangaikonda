#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GKCombatTypes.h"
#include "GKHUDViewModel.generated.h"

class AGKCharacterBase;
class UGKCombatComponent;

/**
 * View model driving the minimal, grounded player HUD (Doc 01 §29, Doc 20 §9).
 * Strictly restricts display to health, stamina, and equipped armament.
 * Strictly adheres to Hard Rule 5: Zero floating damage numbers, no numeric leveling.
 */
UCLASS(BlueprintType)
class GKUI_API UGKHUDViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGKHUDViewModel();

	/** Binds this ViewModel to the player character and its combat component */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|HUD")
	void BindToCharacter(AGKCharacterBase* Character);

	/** Synchronizes data from the bound character */
	UFUNCTION(BlueprintCallable, Category = "GK|UI|HUD")
	void UpdateVitals();

	/** Normalized health pool (0.0 to 1.0) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	float HealthPercent;

	/** Normalized stamina pool (0.0 to 1.0) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	float StaminaPercent;

	/** True if health is critically low (< 25%), driving red stone vignette */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	bool bIsLowHealth;

	/** True if stamina is depleted (< 15%), driving breath sound/visual pulse */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	bool bIsLowStamina;

	/** True if player is actively engaged with hostiles */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	bool bIsInCombat;

	/** Equipped primary weapon title */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	FText EquippedWeaponName;

	/** Current defensive shield/buckler title */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	FText EquippedOffhandName;

	/** Current combat stance (Neutral, Blocking, Parrying, Dodging) */
	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "GK|UI|HUD")
	EGKCombatStance CombatStance;

	/** Explicitly returns false: No floating damage numbers allowed in this game (Hard Rule 5) */
	UFUNCTION(BlueprintPure, Category = "GK|UI|HUD")
	static bool AreDamageNumbersEnabled() { return false; }

private:
	UPROPERTY()
	TWeakObjectPtr<AGKCharacterBase> BoundCharacter;

	UPROPERTY()
	TWeakObjectPtr<UGKCombatComponent> BoundCombatComp;
};
