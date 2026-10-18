#include "GKHUDViewModel.h"
#include "GKCharacterBase.h"
#include "GKCombatComponent.h"

UGKHUDViewModel::UGKHUDViewModel()
	: HealthPercent(1.0f)
	, StaminaPercent(1.0f)
	, bIsLowHealth(false)
	, bIsLowStamina(false)
	, bIsInCombat(false)
	, EquippedWeaponName(NSLOCTEXT("GKUI", "DefaultWeapon", "Chola Bronze-Pommeled Longsword"))
	, EquippedOffhandName(NSLOCTEXT("GKUI", "DefaultOffhand", "Leather-Faced Buckler"))
	, CombatStance(EGKCombatStance::Neutral)
{
}

void UGKHUDViewModel::BindToCharacter(AGKCharacterBase* Character)
{
	BoundCharacter = Character;
	if (Character)
	{
		BoundCombatComp = Character->FindComponentByClass<UGKCombatComponent>();
	}
	else
	{
		BoundCombatComp.Reset();
	}
	UpdateVitals();
}

void UGKHUDViewModel::UpdateVitals()
{
	if (AGKCharacterBase* Char = BoundCharacter.Get())
	{
		const float NewStaminaPercent = FMath::Clamp(Char->GetStaminaNormalized(), 0.0f, 1.0f);
		if (!FMath::IsNearlyEqual(StaminaPercent, NewStaminaPercent, 0.001f))
		{
			StaminaPercent = NewStaminaPercent;
			UE_MVVM_SET_PROPERTY_VALUE(StaminaPercent, StaminaPercent);
		}

		const bool bNewLowStamina = (StaminaPercent < 0.15f);
		if (bIsLowStamina != bNewLowStamina)
		{
			bIsLowStamina = bNewLowStamina;
			UE_MVVM_SET_PROPERTY_VALUE(bIsLowStamina, bIsLowStamina);
		}
	}

	if (UGKCombatComponent* CombatComp = BoundCombatComp.Get())
	{
		const float NewHealthPercent = FMath::Clamp(CombatComp->GetHealthNormalized(), 0.0f, 1.0f);
		if (!FMath::IsNearlyEqual(HealthPercent, NewHealthPercent, 0.001f))
		{
			HealthPercent = NewHealthPercent;
			UE_MVVM_SET_PROPERTY_VALUE(HealthPercent, HealthPercent);
		}

		const bool bNewLowHealth = (HealthPercent < 0.25f);
		if (bIsLowHealth != bNewLowHealth)
		{
			bIsLowHealth = bNewLowHealth;
			UE_MVVM_SET_PROPERTY_VALUE(bIsLowHealth, bIsLowHealth);
		}

		const EGKCombatStance NewStance = CombatComp->GetCombatStance();
		if (CombatStance != NewStance)
		{
			CombatStance = NewStance;
			UE_MVVM_SET_PROPERTY_VALUE(CombatStance, CombatStance);
		}

		const bool bNewInCombat = (NewStance != EGKCombatStance::Neutral);
		if (bIsInCombat != bNewInCombat)
		{
			bIsInCombat = bNewInCombat;
			UE_MVVM_SET_PROPERTY_VALUE(bIsInCombat, bIsInCombat);
		}
	}
}
