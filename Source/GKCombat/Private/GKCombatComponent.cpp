#include "GKCombatComponent.h"
#include "GKCharacterBase.h"
#include "Stealth/GKStealthComponent.h"
#include "GKLogChannels.h"

UGKCombatComponent::UGKCombatComponent()
	: MaxHealth(100.0f)
	, ParryWindowDuration(0.25f)
	, DodgeWindowDuration(0.35f)
	, CurrentHealth(100.0f)
	, CurrentStance(EGKCombatStance::Neutral)
	, OwnerCharacter(nullptr)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UGKCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	OwnerCharacter = Cast<AGKCharacterBase>(GetOwner());
}

bool UGKCombatComponent::PerformLightAttack(AActor* TargetActor)
{
	if (!IsAlive() || CurrentStance == EGKCombatStance::Staggered)
	{
		return false;
	}

	if (OwnerCharacter && !OwnerCharacter->ConsumeStamina(12.0f))
	{
		UE_LOG(LogGKCombat, Verbose, TEXT("Insufficient stamina for light attack."));
		return false;
	}

	CurrentStance = EGKCombatStance::Attacking;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(StanceResetTimerHandle, this, &UGKCombatComponent::ResetStanceToNeutral, 0.4f, false);
	}

	if (TargetActor)
	{
		if (UGKCombatComponent* TargetCombat = TargetActor->FindComponentByClass<UGKCombatComponent>())
		{
			FGKDamageEvent DamageEvent;
			DamageEvent.BaseDamage = 30.0f;
			DamageEvent.DamageCauser = GetOwner();
			DamageEvent.bIsHeavyAttack = false;
			DamageEvent.bIsParryable = true;
			TargetCombat->ReceiveDamage(DamageEvent);
		}
	}

	return true;
}

bool UGKCombatComponent::PerformHeavyAttack(AActor* TargetActor)
{
	if (!IsAlive() || CurrentStance == EGKCombatStance::Staggered)
	{
		return false;
	}

	if (OwnerCharacter && !OwnerCharacter->ConsumeStamina(25.0f))
	{
		UE_LOG(LogGKCombat, Verbose, TEXT("Insufficient stamina for heavy attack."));
		return false;
	}

	CurrentStance = EGKCombatStance::Attacking;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(StanceResetTimerHandle, this, &UGKCombatComponent::ResetStanceToNeutral, 0.7f, false);
	}

	if (TargetActor)
	{
		if (UGKCombatComponent* TargetCombat = TargetActor->FindComponentByClass<UGKCombatComponent>())
		{
			FGKDamageEvent DamageEvent;
			DamageEvent.BaseDamage = 55.0f;
			DamageEvent.DamageCauser = GetOwner();
			DamageEvent.bIsHeavyAttack = true; // Guard-breaker
			DamageEvent.bIsParryable = true;
			TargetCombat->ReceiveDamage(DamageEvent);
		}
	}

	return true;
}

void UGKCombatComponent::StartBlock()
{
	if (IsAlive() && CurrentStance != EGKCombatStance::Staggered && CurrentStance != EGKCombatStance::Attacking)
	{
		CurrentStance = EGKCombatStance::Blocking;
	}
}

void UGKCombatComponent::StopBlock()
{
	if (CurrentStance == EGKCombatStance::Blocking)
	{
		CurrentStance = EGKCombatStance::Neutral;
	}
}

bool UGKCombatComponent::AttemptParry()
{
	if (!IsAlive() || CurrentStance == EGKCombatStance::Staggered)
	{
		return false;
	}

	if (OwnerCharacter && !OwnerCharacter->ConsumeStamina(8.0f))
	{
		return false;
	}

	CurrentStance = EGKCombatStance::Parrying;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(StanceResetTimerHandle);
		World->GetTimerManager().SetTimer(StanceResetTimerHandle, this, &UGKCombatComponent::ResetStanceToNeutral, ParryWindowDuration, false);
	}

	UE_LOG(LogGKCombat, Verbose, TEXT("Combatant '%s' entered active parry window."), *GetOwner()->GetName());
	return true;
}

bool UGKCombatComponent::PerformDodge(const FVector& Direction)
{
	if (!IsAlive() || CurrentStance == EGKCombatStance::Staggered)
	{
		return false;
	}

	if (OwnerCharacter && !OwnerCharacter->ConsumeStamina(18.0f))
	{
		return false;
	}

	CurrentStance = EGKCombatStance::Dodging;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(StanceResetTimerHandle);
		World->GetTimerManager().SetTimer(StanceResetTimerHandle, this, &UGKCombatComponent::ResetStanceToNeutral, DodgeWindowDuration, false);
	}

	UE_LOG(LogGKCombat, Verbose, TEXT("Combatant '%s' executed directional dodge."), *GetOwner()->GetName());
	return true;
}

bool UGKCombatComponent::ExecuteStealthTakedown(AActor* TargetActor)
{
	if (!TargetActor || !IsAlive())
	{
		return false;
	}

	// Verify target is unaware or alert (Doc 10 §8)
	if (UGKStealthComponent* TargetStealth = TargetActor->FindComponentByClass<UGKStealthComponent>())
	{
		const EGKSuspicionState TargetSuspicion = TargetStealth->GetSuspicionState();
		if (TargetSuspicion == EGKSuspicionState::Hostile)
		{
			UE_LOG(LogGKCombat, Verbose, TEXT("Stealth takedown failed: target is already Hostile."));
			return false;
		}
	}

	if (UGKCombatComponent* TargetCombat = TargetActor->FindComponentByClass<UGKCombatComponent>())
	{
		FGKDamageEvent LethalTakedown;
		LethalTakedown.BaseDamage = 150.0f; // Fatal incapacitation
		LethalTakedown.DamageCauser = GetOwner();
		TargetCombat->ReceiveDamage(LethalTakedown);

		UE_LOG(LogGKCombat, Log, TEXT("Stealth takedown executed silently on '%s'."), *TargetActor->GetName());
		return true;
	}

	return false;
}

float UGKCombatComponent::ReceiveDamage(const FGKDamageEvent& DamageEvent)
{
	if (!IsAlive())
	{
		return 0.0f;
	}

	// 1. Evasion check
	if (CurrentStance == EGKCombatStance::Dodging)
	{
		UE_LOG(LogGKCombat, Verbose, TEXT("Attack evaded via dodge window."));
		OnDamageProcessed.Broadcast(0.0f, false, false);
		return 0.0f;
	}

	// 2. Active Parry check (Doc 10 §5)
	if (CurrentStance == EGKCombatStance::Parrying && DamageEvent.bIsParryable)
	{
		UE_LOG(LogGKCombat, Log, TEXT("PARRY SUCCESS: Deflected strike from '%s'!"),
			DamageEvent.DamageCauser ? *DamageEvent.DamageCauser->GetName() : TEXT("Unknown"));

		if (OwnerCharacter)
		{
			OwnerCharacter->ConsumeStamina(5.0f);
		}

		if (DamageEvent.DamageCauser)
		{
			if (UGKCombatComponent* AttackerCombat = DamageEvent.DamageCauser->FindComponentByClass<UGKCombatComponent>())
			{
				AttackerCombat->ApplyStagger();
			}
		}

		OnParryExecuted.Broadcast(DamageEvent.DamageCauser.Get());
		OnDamageProcessed.Broadcast(0.0f, false, true);
		ResetStanceToNeutral();
		return 0.0f;
	}

	// 3. Shield Block check (Doc 10 §5)
	if (CurrentStance == EGKCombatStance::Blocking)
	{
		if (DamageEvent.bIsHeavyAttack)
		{
			// Guard Break! Heavy attack breaks block
			UE_LOG(LogGKCombat, Log, TEXT("GUARD BROKEN: Heavy attack shattered block of '%s'!"), *GetOwner()->GetName());
			ApplyStagger();
			const float GuardBreakDamage = DamageEvent.BaseDamage * 0.5f;
			CurrentHealth = FMath::Max(CurrentHealth - GuardBreakDamage, 0.0f);
			OnDamageProcessed.Broadcast(GuardBreakDamage, true, false);
			return GuardBreakDamage;
		}

		// Standard attack blocked: 85% damage mitigation, drains 15 stamina
		if (OwnerCharacter && !OwnerCharacter->ConsumeStamina(15.0f))
		{
			// Stamina broke during block
			ApplyStagger();
		}

		const float MitigatedDamage = DamageEvent.BaseDamage * 0.15f;
		CurrentHealth = FMath::Max(CurrentHealth - MitigatedDamage, 0.0f);
		OnDamageProcessed.Broadcast(MitigatedDamage, true, false);
		return MitigatedDamage;
	}

	// 4. Unmitigated clean hit (no floating damage numbers popups!)
	CurrentHealth = FMath::Max(CurrentHealth - DamageEvent.BaseDamage, 0.0f);
	OnDamageProcessed.Broadcast(DamageEvent.BaseDamage, false, false);

	if (CurrentHealth <= 0.0f)
	{
		UE_LOG(LogGKCombat, Log, TEXT("Combatant '%s' defeated."), *GetOwner()->GetName());
		OnCombatantDied.Broadcast();
	}

	return DamageEvent.BaseDamage;
}

void UGKCombatComponent::ApplyStagger()
{
	CurrentStance = EGKCombatStance::Staggered;
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(StanceResetTimerHandle);
		World->GetTimerManager().SetTimer(StanceResetTimerHandle, this, &UGKCombatComponent::ResetStanceToNeutral, 1.2f, false);
	}
}

void UGKCombatComponent::ResetStanceToNeutral()
{
	if (CurrentStance != EGKCombatStance::Blocking)
	{
		CurrentStance = EGKCombatStance::Neutral;
	}
}
