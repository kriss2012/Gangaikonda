#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GKCoreTypes.h"
#include "GKCharacterBase.generated.h"

/**
 * Movement and physical state for grounded human characters.
 */
UENUM(BlueprintType)
enum class EGKLocomotionState : uint8
{
	Idle      UMETA(DisplayName = "Idle"),
	Walking   UMETA(DisplayName = "Walking"),
	Running   UMETA(DisplayName = "Running"),
	Crouching UMETA(DisplayName = "Crouching"),
	Climbing  UMETA(DisplayName = "Climbing")
};

/**
 * Base character class for both Arulan and humanoid NPCs (Doc 18 §2).
 * Houses shared stamina, health, and locomotion baseline.
 */
UCLASS(Abstract)
class GKCHARACTER_API AGKCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AGKCharacterBase();

	virtual void Tick(float DeltaTime) override;

	/** Current locomotion state */
	UFUNCTION(BlueprintPure, Category = "GK|Locomotion")
	EGKLocomotionState GetLocomotionState() const { return CurrentLocomotionState; }

	/** Sets locomotion state and adjusts CharacterMovementComponent parameters */
	UFUNCTION(BlueprintCallable, Category = "GK|Locomotion")
	virtual void SetLocomotionState(EGKLocomotionState NewState);

	/** Current stamina ratio (0.0 to 1.0) */
	UFUNCTION(BlueprintPure, Category = "GK|Attributes")
	float GetStaminaNormalized() const { return MaxStamina > 0.0f ? CurrentStamina / MaxStamina : 0.0f; }

	/** Consumes stamina; returns true if sufficient stamina was available */
	UFUNCTION(BlueprintCallable, Category = "GK|Attributes")
	bool ConsumeStamina(float Amount);

	/** Restores stamina up to MaxStamina */
	UFUNCTION(BlueprintCallable, Category = "GK|Attributes")
	void RestoreStamina(float Amount);

	/** Maximum sprint speed in cm/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Movement")
	float RunSpeed;

	/** Standard walk speed in cm/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Movement")
	float WalkSpeed;

	/** Crouch walk speed in cm/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Movement")
	float CrouchSpeed;

	/** Scaffold climbing speed in cm/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Movement")
	float ClimbSpeed;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Locomotion")
	EGKLocomotionState CurrentLocomotionState;

	/** Current stamina pool */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Attributes")
	float CurrentStamina;

	/** Maximum stamina pool */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Attributes")
	float MaxStamina;

	/** Stamina cost per second while sprinting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Attributes")
	float SprintStaminaCostPerSecond;

	/** Stamina recovery rate per second when not exerting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Attributes")
	float StaminaRecoveryRatePerSecond;

	/** Delay in seconds after consuming stamina before recovery begins */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Attributes")
	float StaminaRecoveryDelay;

	float LastStaminaDrainTime;
};
