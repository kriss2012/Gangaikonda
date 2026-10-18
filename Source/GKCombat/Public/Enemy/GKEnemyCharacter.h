#pragma once

#include "CoreMinimal.h"
#include "GKCharacterBase.h"
#include "GKEnemyCharacter.generated.h"

class UGKCombatComponent;
class UGKStealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKEnemyFled, AGKEnemyCharacter*, FleeingEnemy);

/**
 * Ambush encounter enemy character (Doc 10 §3, Doc 08 Minutes 33–37).
 * Implements grounded sword/spear combat, perception/stealth, and opportunistic human flee AI.
 */
UCLASS()
class GKCOMBAT_API AGKEnemyCharacter : public AGKCharacterBase
{
	GENERATED_BODY()

public:
	AGKEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Combat")
	TObjectPtr<UGKCombatComponent> CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Stealth")
	TObjectPtr<UGKStealthComponent> StealthComponent;

	/** Health threshold (percentage, e.g. 0.25) triggering retreat / flee behavior (Doc 10 §3) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|AI")
	float FleeHealthPercentage;

	/** True if this enemy has abandoned combat and is actively fleeing */
	UFUNCTION(BlueprintPure, Category = "GK|AI")
	bool IsFleeing() const { return bIsFleeing; }

	UFUNCTION(BlueprintCallable, Category = "GK|AI")
	void TriggerFleeBehavior();

	/** Evaluates current health against FleeHealthPercentage and triggers retreat if threshold is breached */
	UFUNCTION(BlueprintCallable, Category = "GK|AI")
	void CheckFleeCondition();

	UPROPERTY(BlueprintAssignable, Category = "GK|AI")
	FOnGKEnemyFled OnEnemyFled;

	UFUNCTION()
	void HandleDamageTaken(float FinalDamage, bool bBlocked, bool bParried);

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|AI")
	bool bIsFleeing;
};
