#include "Climbing/GKScaffoldVolume.h"

AGKScaffoldVolume::AGKScaffoldVolume()
	: ClimbFacingNormal(FVector::ForwardVector)
	, TopLedgeHeight(600.0f)
{
	PrimaryActorTick.bCanEverTick = false;

	ClimbTriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ClimbTriggerBox"));
	RootComponent = ClimbTriggerBox;

	ClimbTriggerBox->SetBoxExtent(FVector(80.0f, 150.0f, 300.0f));
	ClimbTriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	ClimbTriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	ClimbTriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

bool AGKScaffoldVolume::IsWithinClimbBounds(const FVector& WorldLocation) const
{
	if (!ClimbTriggerBox)
	{
		return false;
	}

	const FVector LocalPoint = ClimbTriggerBox->GetComponentTransform().InverseTransformPosition(WorldLocation);
	const FVector BoxExtent = ClimbTriggerBox->GetUnscaledBoxExtent();

	return FMath::Abs(LocalPoint.X) <= BoxExtent.X * 1.2f &&
	       FMath::Abs(LocalPoint.Y) <= BoxExtent.Y * 1.2f &&
	       LocalPoint.Z >= -BoxExtent.Z && LocalPoint.Z <= BoxExtent.Z;
}

FVector AGKScaffoldVolume::GetTopLedgeWorldLocation() const
{
	if (!ClimbTriggerBox)
	{
		return GetActorLocation();
	}

	const FVector TopLocal(0.0f, 0.0f, ClimbTriggerBox->GetUnscaledBoxExtent().Z);
	return ClimbTriggerBox->GetComponentTransform().TransformPosition(TopLocal);
}

FVector AGKScaffoldVolume::GetBottomEntryWorldLocation() const
{
	if (!ClimbTriggerBox)
	{
		return GetActorLocation();
	}

	const FVector BottomLocal(0.0f, 0.0f, -ClimbTriggerBox->GetUnscaledBoxExtent().Z);
	return ClimbTriggerBox->GetComponentTransform().TransformPosition(BottomLocal);
}
