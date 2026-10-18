#include "GKCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GKLogChannels.h"

AGKCharacterBase::AGKCharacterBase()
	: CurrentLocomotionState(EGKLocomotionState::Idle)
	, RunSpeed(450.0f)
	, WalkSpeed(220.0f)
	, CrouchSpeed(160.0f)
	, ClimbSpeed(150.0f)
	, CurrentStamina(100.0f)
	, MaxStamina(100.0f)
	, SprintStaminaCostPerSecond(20.0f)
	, StaminaRecoveryRatePerSecond(15.0f)
	, StaminaRecoveryDelay(1.2f)
	, LastStaminaDrainTime(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->MaxWalkSpeed = WalkSpeed;
		MoveComp->MaxWalkSpeedCrouched = CrouchSpeed;
		MoveComp->bCanWalkOffLedges = true;
		MoveComp->bCanWalkOffLedgesWhenCrouching = true;
		MoveComp->GetNavAgentPropertiesRef().bCanCrouch = true;
		MoveComp->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
		MoveComp->bOrientRotationToMovement = true;
	}

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AGKCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentStamina = MaxStamina;
}

void AGKCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Stamina regeneration logic
	const float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	if (CurrentLocomotionState == EGKLocomotionState::Running)
	{
		if (!ConsumeStamina(SprintStaminaCostPerSecond * DeltaTime))
		{
			// Stamina depleted: drop back to normal walking
			SetLocomotionState(EGKLocomotionState::Walking);
		}
	}
	else if (CurrentTime - LastStaminaDrainTime >= StaminaRecoveryDelay)
	{
		if (CurrentStamina < MaxStamina)
		{
			RestoreStamina(StaminaRecoveryRatePerSecond * DeltaTime);
		}
	}
}

void AGKCharacterBase::SetLocomotionState(EGKLocomotionState NewState)
{
	if (CurrentLocomotionState == NewState)
	{
		return;
	}

	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (!MoveComp)
	{
		return;
	}

	// Exit current state if needed
	if (CurrentLocomotionState == EGKLocomotionState::Crouching && NewState != EGKLocomotionState::Crouching)
	{
		UnCrouch();
	}

	CurrentLocomotionState = NewState;

	switch (NewState)
	{
	case EGKLocomotionState::Idle:
	case EGKLocomotionState::Walking:
		MoveComp->MaxWalkSpeed = WalkSpeed;
		break;
	case EGKLocomotionState::Running:
		MoveComp->MaxWalkSpeed = RunSpeed;
		break;
	case EGKLocomotionState::Crouching:
		Crouch();
		MoveComp->MaxWalkSpeedCrouched = CrouchSpeed;
		break;
	case EGKLocomotionState::Climbing:
		MoveComp->MaxWalkSpeed = ClimbSpeed;
		break;
	}
}

bool AGKCharacterBase::ConsumeStamina(float Amount)
{
	if (CurrentStamina < Amount)
	{
		CurrentStamina = 0.0f;
		LastStaminaDrainTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
		return false;
	}

	CurrentStamina -= Amount;
	LastStaminaDrainTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	return true;
}

void AGKCharacterBase::RestoreStamina(float Amount)
{
	CurrentStamina = FMath::Clamp(CurrentStamina + Amount, 0.0f, MaxStamina);
}
