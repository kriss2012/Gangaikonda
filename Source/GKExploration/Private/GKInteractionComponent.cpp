#include "GKInteractionComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GKLogChannels.h"

UGKInteractionComponent::UGKInteractionComponent()
	: InteractionRange(260.0f)
	, SweepRadius(60.0f)
	, bIsScanning(false)
	, FocusedActor(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.05f; // 20 Hz update is optimal for interaction sweep
}

void UGKInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UGKInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateTargetDetection();
}

void UGKInteractionComponent::UpdateTargetDetection()
{
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return;
	}

	FVector ViewLoc;
	FRotator ViewRot;
	Owner->GetActorEyesViewPoint(ViewLoc, ViewRot);

	const FVector TraceStart = ViewLoc;
	const FVector TraceEnd = TraceStart + (ViewRot.Vector() * InteractionRange);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Owner);

	FHitResult HitResult;
	const bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(),
		TraceStart,
		TraceEnd,
		SweepRadius,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult,
		true
	);

	AActor* BestCandidate = nullptr;
	if (bHit && HitResult.GetActor())
	{
		if (HitResult.GetActor()->Implements<UGKInvestigatable>())
		{
			if (IGKInvestigatable::Execute_CanInvestigate(HitResult.GetActor(), Owner))
			{
				BestCandidate = HitResult.GetActor();
			}
		}
	}

	// Update focus state
	if (BestCandidate != FocusedActor.Get())
	{
		FocusedActor = BestCandidate;
		if (FocusedActor.IsValid())
		{
			const FText Prompt = IGKInvestigatable::Execute_GetInvestigationPromptText(FocusedActor.Get());
			UE_LOG(LogGKExploration, Verbose, TEXT("Focusing investigatable actor: %s"), *FocusedActor->GetName());
			OnInvestigatableFocused.Broadcast(FocusedActor.Get(), Prompt);
		}
		else
		{
			OnInvestigatableLost.Broadcast();
		}
	}
}

bool UGKInteractionComponent::Interact()
{
	if (!FocusedActor.IsValid() || !GetOwner())
	{
		return false;
	}

	if (IGKInvestigatable::Execute_CanInvestigate(FocusedActor.Get(), GetOwner()))
	{
		UE_LOG(LogGKExploration, Log, TEXT("Executing investigation on %s"), *FocusedActor->GetName());
		IGKInvestigatable::Execute_OnInvestigate(FocusedActor.Get(), GetOwner());
		return true;
	}

	return false;
}

void UGKInteractionComponent::SetScanMode(bool bActive)
{
	if (bIsScanning != bActive)
	{
		bIsScanning = bActive;
		UE_LOG(LogGKExploration, Log, TEXT("Scan mode toggled: %s"), bActive ? TEXT("Active") : TEXT("Inactive"));
		OnScanModeToggled.Broadcast(bIsScanning);
	}
}
