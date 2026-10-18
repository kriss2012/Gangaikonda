#include "Enemy/GKEnemyCharacter.h"
#include "GKCombatComponent.h"
#include "Stealth/GKStealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GKLogChannels.h"

AGKEnemyCharacter::AGKEnemyCharacter()
	: FleeHealthPercentage(0.25f)
	, bIsFleeing(false)
{
	PrimaryActorTick.bCanEverTick = true;

	CombatComponent = CreateDefaultSubobject<UGKCombatComponent>(TEXT("CombatComponent"));
	StealthComponent = CreateDefaultSubobject<UGKStealthComponent>(TEXT("StealthComponent"));

	WalkSpeed = 200.0f;
	RunSpeed = 480.0f; // Fleeing enemies run faster
}

void AGKEnemyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (CombatComponent)
	{
		CombatComponent->OnDamageProcessed.RemoveAll(this);
		CombatComponent->OnDamageProcessed.AddDynamic(this, &AGKEnemyCharacter::HandleDamageTaken);
	}
}

void AGKEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (CombatComponent)
	{
		CombatComponent->OnDamageProcessed.RemoveAll(this);
		CombatComponent->OnDamageProcessed.AddDynamic(this, &AGKEnemyCharacter::HandleDamageTaken);
	}
}

void AGKEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsFleeing)
	{
		// Maintain sprint locomotion while escaping
		if (GetLocomotionState() != EGKLocomotionState::Running)
		{
			SetLocomotionState(EGKLocomotionState::Running);
		}
	}
}

void AGKEnemyCharacter::HandleDamageTaken(float FinalDamage, bool bBlocked, bool bParried)
{
	CheckFleeCondition();
}

void AGKEnemyCharacter::CheckFleeCondition()
{
	if (bIsFleeing)
	{
		return;
	}

	const float CurrentHP = CombatComponent ? CombatComponent->GetHealth() : 0.0f;
	const float MaxHP = CombatComponent ? CombatComponent->MaxHealth : 100.0f;
	const float HealthNorm = MaxHP > 0.0f ? CurrentHP / MaxHP : 0.0f;

	// Check if health drops below flee threshold (Doc 10 §3)
	if (CurrentHP > 0.0f && HealthNorm <= FleeHealthPercentage)
	{
		TriggerFleeBehavior();
	}
}

void AGKEnemyCharacter::TriggerFleeBehavior()
{
	if (bIsFleeing)
	{
		return;
	}

	bIsFleeing = true;
	SetLocomotionState(EGKLocomotionState::Running);

	// Lower shield / drop combat stance
	if (CombatComponent)
	{
		CombatComponent->StopBlock();
	}

	UE_LOG(LogGKCombat, Log, TEXT("Enemy '%s' outmatched (HP: %.1f%%). Breaking combat to FLEE!"),
		*GetName(), CombatComponent ? CombatComponent->GetHealthNormalized() * 100.0f : 0.0f);

	OnEnemyFled.Broadcast(this);
}
