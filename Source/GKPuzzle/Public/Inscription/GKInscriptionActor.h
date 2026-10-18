#pragma once

#include "CoreMinimal.h"
#include "GKPuzzleBase.h"
#include "GKPuzzleTypes.h"
#include "Interfaces/IGKInvestigatable.h"
#include "Components/StaticMeshComponent.h"
#include "GKInscriptionActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInscriptionDecodingSessionStarted, AGKInscriptionActor*, InscriptionActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInscriptionFragmentSlotUpdated, int32, SlotIndex, int32, FragmentID);

/**
 * Physical inscribed stone actor implementing Inscription Decoding Tier 1 (Doc 09 P10, Doc 08 Minutes 9–14).
 * Dual nature: It is both an investigatable environmental prop (IGKInvestigatable) and a puzzle actor (AGKPuzzleActor).
 */
UCLASS(BlueprintType)
class GKPUZZLE_API AGKInscriptionActor : public AGKPuzzleActor, public IGKInvestigatable
{
	GENERATED_BODY()

public:
	AGKInscriptionActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Inscription")
	TObjectPtr<UStaticMeshComponent> StoneMesh;

	/** Inscribed panel receiving chisel/scan contrast highlight */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Inscription")
	TObjectPtr<UStaticMeshComponent> InscriptionPanelMesh;

	/** Fragments carved into this inscription that must be identified */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	TArray<FGKInscriptionFragment> InscribedFragments;

	/** The Scholar's reference chart provided to Arulan (Doc 09 P10) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	TArray<FGKScholarReferenceEntry> ScholarReferenceChart;

	/** The correct sequence of fragment IDs constituting the authentic decipherment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	TArray<int32> SolutionSequence;

	/** Current player slot assignments */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Inscription")
	TArray<int32> PlayerAssignedSequence;

	/**
	 * Full translated inscriptional text revealed upon decoding.
	 * Hard Rule: Invented verses must carry explicit placeholder tagging.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText FullDecodedText;

	/** Historical paleographic context */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText PaleographicPeriodNotes;

	/** Prompt text displayed when Arulan approaches */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Inscription")
	FText InvestigationPrompt;

	// Inscription decoding mechanics
	UFUNCTION(BlueprintCallable, Category = "GK|Inscription")
	bool AssignFragmentToSlot(int32 SlotIndex, int32 FragmentID);

	UFUNCTION(BlueprintCallable, Category = "GK|Inscription")
	void ClearSlot(int32 SlotIndex);

	UFUNCTION(BlueprintPure, Category = "GK|Inscription")
	bool IsFullyDecoded() const { return CurrentPuzzleState == EGKPuzzleState::Solved; }

	// IGKInvestigatable implementation
	virtual void OnInvestigate_Implementation(AActor* Investigator) override;
	virtual bool CanInvestigate_Implementation(AActor* Investigator) const override;
	virtual FText GetInvestigationPromptText_Implementation() const override;

	UPROPERTY(BlueprintAssignable, Category = "GK|Inscription")
	FOnInscriptionDecodingSessionStarted OnDecodingSessionStarted;

	UPROPERTY(BlueprintAssignable, Category = "GK|Inscription")
	FOnInscriptionFragmentSlotUpdated OnSlotUpdated;

protected:
	virtual void BeginPlay() override;
	virtual bool EvaluateSolutionConditions() override;
	virtual void OnResetPuzzleElements() override;

	void SetupDefaultHistoricalFragments();
};
