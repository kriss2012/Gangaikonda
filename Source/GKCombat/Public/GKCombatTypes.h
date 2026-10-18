#pragma once

#include "CoreMinimal.h"
#include "GKCombatTypes.generated.h"

/**
 * Combat stance of a combatant (Doc 10 §4–§7).
 */
UENUM(BlueprintType)
enum class EGKCombatStance : uint8
{
	Neutral   UMETA(DisplayName = "Neutral"),
	Blocking  UMETA(DisplayName = "Blocking (Shield Raised)"),
	Attacking UMETA(DisplayName = "Attacking"),
	Parrying  UMETA(DisplayName = "Parrying (Active Window)"),
	Dodging   UMETA(DisplayName = "Dodging (Evasion Window)"),
	Staggered UMETA(DisplayName = "Staggered (Guard Broken)")
};

/**
 * Grounded damage payload.
 * Rule: No numeric RPG stat leveling, no floating damage numbers (Doc 10 §1).
 */
USTRUCT(BlueprintType)
struct GKCOMBAT_API FGKDamageEvent
{
	GENERATED_BODY()

	FGKDamageEvent()
		: BaseDamage(30.0f)
		, DamageCauser(nullptr)
		, bIsHeavyAttack(false)
		, bIsParryable(true)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	float BaseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	TObjectPtr<AActor> DamageCauser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	bool bIsHeavyAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Combat")
	bool bIsParryable;
};
