#include "Schedule/GKScheduleComponent.h"
#include "GameFramework/Character.h"
#include "GKLogChannels.h"

UGKScheduleComponent::UGKScheduleComponent()
	: CurrentTimeOfDay(EGKTimeOfDay::Morning)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UGKScheduleComponent::BeginPlay()
{
	Super::BeginPlay();
	ExecuteActivityTransition();
}

void UGKScheduleComponent::SetSchedule(const FGKNPCSchedule& InSchedule)
{
	AssignedSchedule = InSchedule;
	ExecuteActivityTransition();
}

void UGKScheduleComponent::SetTimeOfDay(EGKTimeOfDay NewTimeOfDay)
{
	if (CurrentTimeOfDay != NewTimeOfDay)
	{
		CurrentTimeOfDay = NewTimeOfDay;
		ExecuteActivityTransition();
	}
}

void UGKScheduleComponent::ExecuteActivityTransition()
{
	FGKScheduleActivity TargetActivity;
	if (AssignedSchedule.GetActivityForTimeOfDay(CurrentTimeOfDay, TargetActivity))
	{
		CurrentActivity = TargetActivity;
		UE_LOG(LogGKAI, Log, TEXT("NPC '%s' transitioned to %s schedule: %s (Location: %s)"),
			*GetOwner()->GetName(),
			*UEnum::GetValueAsString(CurrentTimeOfDay),
			*UEnum::GetValueAsString(CurrentActivity.Behavior),
			*CurrentActivity.TargetLocationTag.ToString());

		OnActivityChanged.Broadcast(CurrentTimeOfDay, CurrentActivity);
	}
	else
	{
		// Fallback default activity
		CurrentActivity.TimeOfDay = CurrentTimeOfDay;
		CurrentActivity.Behavior = EGKNPCBehaviorState::Idle;
	}
}

void UGKScheduleComponent::ReactToPlayer(AActor* PlayerActor)
{
	if (!PlayerActor || !GetOwner())
	{
		return;
	}

	// Orient towards player if humanoid character
	if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
	{
		const FVector Direction = (PlayerActor->GetActorLocation() - OwnerChar->GetActorLocation()).GetSafeNormal2D();
		OwnerChar->SetActorRotation(FRotator(0.0f, Direction.Rotation().Yaw, 0.0f));
	}

	OnPlayerReactionTriggered.Broadcast(PlayerActor);

	UE_LOG(LogGKAI, Verbose, TEXT("NPC '%s' reacting to player '%s'"),
		*GetOwner()->GetName(), *PlayerActor->GetName());

	// Schedule return to regular schedule after brief reaction pause (4.0s)
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ReactionRestoreTimerHandle);
		World->GetTimerManager().SetTimer(ReactionRestoreTimerHandle, this, &UGKScheduleComponent::EndPlayerReaction, 4.0f, false);
	}
}

void UGKScheduleComponent::EndPlayerReaction()
{
	ExecuteActivityTransition();
}
