#include "Climbing/GKClimbingComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GKLogChannels.h"

UGKClimbingComponent::UGKClimbingComponent()
	: ClimbSpeed(160.0f)
	, bIsClimbing(false)
	, CurrentScaffold(nullptr)
	, OwnerCharacter(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGKClimbingComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UGKClimbingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsClimbing && CurrentScaffold.IsValid() && OwnerCharacter)
	{
		// Validate that character is still within scaffold bounds
		if (!CurrentScaffold->IsWithinClimbBounds(OwnerCharacter->GetActorLocation()))
		{
			StopClimb(false);
		}
	}
}

AGKScaffoldVolume* UGKClimbingComponent::FindNearbyScaffold() const
{
	if (!OwnerCharacter)
	{
		return nullptr;
	}

	const FVector Origin = OwnerCharacter->GetActorLocation();
	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		Origin,
		180.0f,
		ObjectTypes,
		AGKScaffoldVolume::StaticClass(),
		TArray<AActor*>(),
		OverlappingActors
	);

	for (AActor* Actor : OverlappingActors)
	{
		AGKScaffoldVolume* Scaffold = Cast<AGKScaffoldVolume>(Actor);
		if (Scaffold && Scaffold->IsWithinClimbBounds(Origin))
		{
			return Scaffold;
		}
	}

	return nullptr;
}

bool UGKClimbingComponent::TryStartClimb()
{
	if (bIsClimbing || !OwnerCharacter)
	{
		return false;
	}

	AGKScaffoldVolume* TargetScaffold = FindNearbyScaffold();
	if (!TargetScaffold)
	{
		return false;
	}

	CurrentScaffold = TargetScaffold;
	bIsClimbing = true;

	UCharacterMovementComponent* MoveComp = OwnerCharacter->GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->SetMovementMode(MOVE_Flying);
		MoveComp->Velocity = FVector::ZeroVector;
	}

	// Orient character to face the climb normal
	const FRotator TargetRot = (-TargetScaffold->ClimbFacingNormal).Rotation();
	OwnerCharacter->SetActorRotation(FRotator(0.0f, TargetRot.Yaw, 0.0f));

	UE_LOG(LogGKExploration, Log, TEXT("Character attached to scaffold %s"), *TargetScaffold->GetName());
	OnClimbStateChanged.Broadcast(true);
	return true;
}

void UGKClimbingComponent::ClimbVertical(float InputValue)
{
	if (!bIsClimbing || !CurrentScaffold.IsValid() || !OwnerCharacter || FMath::IsNearlyZero(InputValue))
	{
		return;
	}

	const float DeltaSeconds = GetWorld() ? GetWorld()->GetDeltaSeconds() : 0.016f;
	const FVector DeltaMove = FVector(0.0f, 0.0f, InputValue * ClimbSpeed * DeltaSeconds);
	const FVector NewLocation = OwnerCharacter->GetActorLocation() + DeltaMove;

	// Check if character reached top or bottom boundaries
	const FVector TopLedge = CurrentScaffold->GetTopLedgeWorldLocation();
	const FVector BottomEntry = CurrentScaffold->GetBottomEntryWorldLocation();

	if (InputValue > 0.0f && NewLocation.Z >= TopLedge.Z - 20.0f)
	{
		// Mantle onto ledge
		StopClimb(true);
		return;
	}
	else if (InputValue < 0.0f && NewLocation.Z <= BottomEntry.Z + 10.0f)
	{
		// Step off onto ground
		StopClimb(false);
		return;
	}

	OwnerCharacter->SetActorLocation(NewLocation, true);
}

void UGKClimbingComponent::StopClimb(bool bDismountAtLedge)
{
	if (!bIsClimbing || !OwnerCharacter)
	{
		return;
	}

	bIsClimbing = false;

	if (bDismountAtLedge && CurrentScaffold.IsValid())
	{
		// Teleport or snap onto top platform slightly forward
		const FVector ForwardOffset = (-CurrentScaffold->ClimbFacingNormal) * 60.0f;
		const FVector LedgeTarget = CurrentScaffold->GetTopLedgeWorldLocation() + ForwardOffset + FVector(0.0f, 0.0f, 10.0f);
		OwnerCharacter->SetActorLocation(LedgeTarget, true);
	}

	UCharacterMovementComponent* MoveComp = OwnerCharacter->GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->SetMovementMode(MOVE_Walking);
		MoveComp->Velocity = FVector::ZeroVector;
	}

	CurrentScaffold = nullptr;
	UE_LOG(LogGKExploration, Log, TEXT("Character dismounted scaffold (Mantle=%s)"), bDismountAtLedge ? TEXT("True") : TEXT("False"));
	OnClimbStateChanged.Broadcast(false);
}
