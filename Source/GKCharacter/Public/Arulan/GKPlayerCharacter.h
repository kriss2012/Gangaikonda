#pragma once

#include "CoreMinimal.h"
#include "GKCharacterBase.h"
#include "InputActionValue.h"
#include "GKPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGKInteractionComponent;
class UGKClimbingComponent;
class UInputMappingContext;
class UInputAction;

/**
 * Arulan — Protagonist and player-controlled character (Doc 06 §2, Doc 08).
 * Third-person perspective, Enhanced Input, camera collision, grounded locomotion, and investigation interaction.
 */
UCLASS()
class GKCHARACTER_API AGKPlayerCharacter : public AGKCharacterBase
{
	GENERATED_BODY()

public:
	AGKPlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	/** Follow camera providing third-person view */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	/** Interaction and scan detector component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Interaction")
	TObjectPtr<UGKInteractionComponent> InteractionComponent;

	/** Scaffold traversal and climbing component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Climbing")
	TObjectPtr<UGKClimbingComponent> ClimbingComponent;

	// Enhanced Input Actions & Contexts
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> CrouchAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> ScanAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GK|Input")
	TObjectPtr<UInputAction> ClimbAction;

protected:
	virtual void BeginPlay() override;

	// Input Handlers
	void Input_Move(const FInputActionValue& Value);
	void Input_Look(const FInputActionValue& Value);
	void Input_SprintStarted();
	void Input_SprintEnded();
	void Input_CrouchToggle();
	void Input_Interact();
	void Input_ScanStarted();
	void Input_ScanEnded();
	void Input_ClimbToggle();
};
