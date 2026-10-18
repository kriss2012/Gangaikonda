#include "GKTestInvestigatableActor.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "GKTestInvestigatable"

AGKTestInvestigatableActor::AGKTestInvestigatableActor()
	: PromptText(LOCTEXT("DefaultPrompt", "[E] Inspect Inscription Stone"))
	, EvidenceIDToUnlock(FName(TEXT("C1")))
	, bIsActive(true)
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	MeshComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
}

void AGKTestInvestigatableActor::OnInvestigate_Implementation(AActor* Investigator)
{
	UE_LOG(LogGKExploration, Log, TEXT("Actor %s investigated by %s. Linked EvidenceID: %s"),
		*GetName(),
		Investigator ? *Investigator->GetName() : TEXT("None"),
		*EvidenceIDToUnlock.ToString());
}

bool AGKTestInvestigatableActor::CanInvestigate_Implementation(AActor* Investigator) const
{
	return bIsActive;
}

FText AGKTestInvestigatableActor::GetInvestigationPromptText_Implementation() const
{
	return PromptText;
}

#undef LOCTEXT_NAMESPACE
