#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IGKInvestigatable.h"
#include "Components/StaticMeshComponent.h"
#include "GKTestInvestigatableActor.generated.h"

/**
 * Greybox investigatable test actor for Zone 5 (inscriptions, stone blocks, site ledgers).
 * Implements IGKInvestigatable to verify Arulan's forward sweep and HUD prompt dispatch.
 */
UCLASS(BlueprintType)
class GKEXPLORATION_API AGKTestInvestigatableActor : public AActor, public IGKInvestigatable
{
	GENERATED_BODY()

public:
	AGKTestInvestigatableActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Investigation")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	/** Prompt displayed when Arulan approaches and looks at this object */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Investigation")
	FText PromptText;

	/** Evidence ID unlocked upon completing investigation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Investigation")
	FName EvidenceIDToUnlock;

	/** Whether this actor can currently be investigated */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Investigation")
	bool bIsActive;

	// IGKInvestigatable implementation
	virtual void OnInvestigate_Implementation(AActor* Investigator) override;
	virtual bool CanInvestigate_Implementation(AActor* Investigator) const override;
	virtual FText GetInvestigationPromptText_Implementation() const override;
};
