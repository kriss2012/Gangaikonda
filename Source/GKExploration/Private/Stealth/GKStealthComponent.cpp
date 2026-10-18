#include "Stealth/GKStealthComponent.h"
#include "GKLogChannels.h"

UGKStealthComponent::UGKStealthComponent()
	: AllowedDisguiseRole(EGKDisguiseRole::None)
	, SuspicionBuildRate(45.0f)
	, SuspicionDecayRate(18.0f)
	, SightRange(1600.0f)
	, CurrentState(EGKSuspicionState::Unaware)
	, CurrentSuspicion(0.0f)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UGKStealthComponent::ProcessPerception(float DeltaTime, bool bHasLineOfSight, float DistanceToPlayer, bool bIsPlayerCrowdBlending, EGKDisguiseRole PlayerDisguise)
{
	if (bHasLineOfSight && DistanceToPlayer <= SightRange)
	{
		// 1. Check disguise immunity (Doc 11 §4)
		if (AllowedDisguiseRole != EGKDisguiseRole::None && PlayerDisguise == AllowedDisguiseRole)
		{
			// Appropriate disguise: guard treats player as authorized worker/scribe
			CurrentSuspicion = FMath::FInterpTo(CurrentSuspicion, 0.0f, DeltaTime, 1.5f);
		}
		else
		{
			// 2. Modulate rate by distance
			const float DistanceFactor = 1.0f - FMath::Clamp(DistanceToPlayer / SightRange, 0.0f, 1.0f);
			float Rate = SuspicionBuildRate * (0.5f + 0.5f * DistanceFactor);

			// 3. Social stealth crowd-blending dampening (Doc 11 §5)
			if (bIsPlayerCrowdBlending)
			{
				Rate *= 0.25f; // 75% reduction in crowd
			}

			CurrentSuspicion = FMath::Clamp(CurrentSuspicion + (Rate * DeltaTime), 0.0f, 100.0f);
		}
	}
	else
	{
		// Out of sight: decay suspicion gradually
		CurrentSuspicion = FMath::Clamp(CurrentSuspicion - (SuspicionDecayRate * DeltaTime), 0.0f, 100.0f);
	}

	OnSuspicionMeterChanged.Broadcast(GetSuspicionNormalized());

	// State resolution per thresholds
	if (CurrentSuspicion >= 100.0f)
	{
		TransitionState(EGKSuspicionState::Hostile);
	}
	else if (CurrentSuspicion >= 60.0f)
	{
		TransitionState(EGKSuspicionState::Searching);
	}
	else if (CurrentSuspicion >= 25.0f)
	{
		TransitionState(EGKSuspicionState::Alert);
	}
	else
	{
		TransitionState(EGKSuspicionState::Unaware);
	}
}

void UGKStealthComponent::TransitionState(EGKSuspicionState NewState)
{
	if (CurrentState != NewState)
	{
		const EGKSuspicionState OldState = CurrentState;
		CurrentState = NewState;
		UE_LOG(LogGKExploration, Log, TEXT("Guard '%s' suspicion state: %s -> %s (Meter: %.1f)"),
			*GetOwner()->GetName(), *UEnum::GetValueAsString(OldState), *UEnum::GetValueAsString(NewState), CurrentSuspicion);

		OnSuspicionStateChanged.Broadcast(OldState, NewState);
	}
}
