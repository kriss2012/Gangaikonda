#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/IGKInvestigatable.h"
#include "GKInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInvestigatableFocused, AActor*, TargetActor, const FText&, PromptText);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInvestigatableLost);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScanModeToggled, bool, bIsScanning);

/**
 * Sweeps for and detects actors implementing IGKInvestigatable (Doc 11 §6, Doc 18 §4).
 * Drives HUD prompt display and interaction triggers for inscriptions, ledgers, and clues.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKEXPLORATION_API UGKInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKInteractionComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Executes investigation on currently focused target */
	UFUNCTION(BlueprintCallable, Category = "GK|Interaction")
	bool Interact();

	/** Toggles scan mode for discovering environmental clues and inscriptions */
	UFUNCTION(BlueprintCallable, Category = "GK|Interaction")
	void SetScanMode(bool bActive);

	/** Returns currently focused investigatable actor */
	UFUNCTION(BlueprintPure, Category = "GK|Interaction")
	AActor* GetFocusedActor() const { return FocusedActor.Get(); }

	/** Returns true if scan mode is active */
	UFUNCTION(BlueprintPure, Category = "GK|Interaction")
	bool IsScanning() const { return bIsScanning; }

	/** Max detection range in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Interaction")
	float InteractionRange;

	/** Sphere sweep radius in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Interaction")
	float SweepRadius;

	UPROPERTY(BlueprintAssignable, Category = "GK|Interaction")
	FOnInvestigatableFocused OnInvestigatableFocused;

	UPROPERTY(BlueprintAssignable, Category = "GK|Interaction")
	FOnInvestigatableLost OnInvestigatableLost;

	UPROPERTY(BlueprintAssignable, Category = "GK|Interaction")
	FOnScanModeToggled OnScanModeToggled;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TWeakObjectPtr<AActor> FocusedActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Interaction")
	bool bIsScanning;

private:
	void UpdateTargetDetection();
};
