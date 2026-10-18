#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GKCombatTypes.h"
#include "GKCombatComponent.generated.h"

class AGKCharacterBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGKDamageProcessed, float, FinalDamage, bool, bBlocked, bool, bParried);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKParryExecuted, AActor*, StaggeredAttacker);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGKCombatantDied);

/**
 * Grounded combat component attached to Arulan and combat-capable NPCs (Doc 10 §1–§8).
 * Manages sword/shield, stamina costs, active block, 0.25s parry window, directional dodge, and stealth takedown.
 * Strictly adheres to Hard Rule 5: Zero floating damage numbers, grounded mortal damage model.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKCOMBAT_API UGKCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKCombatComponent();

	/** Initiates standard light sword slash (30 dmg, 12 stamina) */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	bool PerformLightAttack(AActor* TargetActor);

	/** Initiates committed heavy strike (55 dmg, 25 stamina, guard-breaking) */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	bool PerformHeavyAttack(AActor* TargetActor);

	/** Raises shield to block incoming strikes */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	void StartBlock();

	/** Lowers shield */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	void StopBlock();

	/** Attempts sword parry with precise 0.25s timing window (Doc 10 §5) */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	bool AttemptParry();

	/** Executes quick directional evasion roll/step (18 stamina) */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	bool PerformDodge(const FVector& Direction);

	/** Executes silent dagger takedown on unaware or alert target (Doc 10 §8) */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	bool ExecuteStealthTakedown(AActor* TargetActor);

	/** Processes incoming damage against current stance, blocking shield, and parry window */
	UFUNCTION(BlueprintCallable, Category = "GK|Combat")
	float ReceiveDamage(const FGKDamageEvent& DamageEvent);

	/** Current health pool */
	UFUNCTION(BlueprintPure, Category = "GK|Combat")
	float GetHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category = "GK|Combat")
	float GetHealthNormalized() const { return MaxHealth > 0.0f ? CurrentHealth / MaxHealth : 0.0f; }

	UFUNCTION(BlueprintPure, Category = "GK|Combat")
	EGKCombatStance GetCombatStance() const { return CurrentStance; }

	UFUNCTION(BlueprintPure, Category = "GK|Combat")
	bool IsAlive() const { return CurrentHealth > 0.0f; }

	UPROPERTY(BlueprintAssignable, Category = "GK|Combat")
	FOnGKDamageProcessed OnDamageProcessed;

	UPROPERTY(BlueprintAssignable, Category = "GK|Combat")
	FOnGKParryExecuted OnParryExecuted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Combat")
	FOnGKCombatantDied OnCombatantDied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	float MaxHealth;

	/** Duration in seconds of the active parry timing window (Doc 10 §5) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	float ParryWindowDuration;

	/** Duration of the dodge evasion invulnerability window */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	float DodgeWindowDuration;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Combat")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Combat")
	EGKCombatStance CurrentStance;

	UPROPERTY()
	TObjectPtr<AGKCharacterBase> OwnerCharacter;

	FTimerHandle StanceResetTimerHandle;

private:
	void ResetStanceToNeutral();
	void ApplyStagger();
};
