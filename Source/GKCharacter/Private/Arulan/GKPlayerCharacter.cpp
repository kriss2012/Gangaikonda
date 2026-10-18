#include "Arulan/GKPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GKInteractionComponent.h"
#include "Climbing/GKClimbingComponent.h"
#include "GKLogChannels.h"

AGKPlayerCharacter::AGKPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Camera boom setup with collision test
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 360.0f;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bDoCollisionTest = true; // Probe test: camera does not clip through temple stone/scaffolding
	CameraBoom->ProbeSize = 14.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 35.0f, 65.0f); // Grounded over-the-shoulder framing

	// Follow camera setup
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Exploration and interaction components
	InteractionComponent = CreateDefaultSubobject<UGKInteractionComponent>(TEXT("InteractionComponent"));
	ClimbingComponent = CreateDefaultSubobject<UGKClimbingComponent>(TEXT("ClimbingComponent"));
}

void AGKPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Register default Enhanced Input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AGKPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGKPlayerCharacter::Input_Move);
		}
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGKPlayerCharacter::Input_Look);
		}
		if (SprintAction)
		{
			EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AGKPlayerCharacter::Input_SprintStarted);
			EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AGKPlayerCharacter::Input_SprintEnded);
		}
		if (CrouchAction)
		{
			EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AGKPlayerCharacter::Input_CrouchToggle);
		}
		if (InteractAction)
		{
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AGKPlayerCharacter::Input_Interact);
		}
		if (ScanAction)
		{
			EnhancedInputComponent->BindAction(ScanAction, ETriggerEvent::Started, this, &AGKPlayerCharacter::Input_ScanStarted);
			EnhancedInputComponent->BindAction(ScanAction, ETriggerEvent::Completed, this, &AGKPlayerCharacter::Input_ScanEnded);
		}
		if (ClimbAction)
		{
			EnhancedInputComponent->BindAction(ClimbAction, ETriggerEvent::Started, this, &AGKPlayerCharacter::Input_ClimbToggle);
		}
	}
}

void AGKPlayerCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (ClimbingComponent && ClimbingComponent->IsClimbing())
	{
		// While on scaffold: forward/backward drives vertical ascension/descension
		ClimbingComponent->ClimbVertical(MovementVector.Y);
		return;
	}

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGKPlayerCharacter::Input_Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGKPlayerCharacter::Input_SprintStarted()
{
	if (CurrentLocomotionState != EGKLocomotionState::Climbing && CurrentStamina > 10.0f)
	{
		SetLocomotionState(EGKLocomotionState::Running);
	}
}

void AGKPlayerCharacter::Input_SprintEnded()
{
	if (CurrentLocomotionState == EGKLocomotionState::Running)
	{
		SetLocomotionState(EGKLocomotionState::Walking);
	}
}

void AGKPlayerCharacter::Input_CrouchToggle()
{
	if (CurrentLocomotionState == EGKLocomotionState::Crouching)
	{
		SetLocomotionState(EGKLocomotionState::Walking);
	}
	else if (CurrentLocomotionState != EGKLocomotionState::Climbing)
	{
		SetLocomotionState(EGKLocomotionState::Crouching);
	}
}

void AGKPlayerCharacter::Input_Interact()
{
	if (InteractionComponent)
	{
		InteractionComponent->Interact();
	}
}

void AGKPlayerCharacter::Input_ScanStarted()
{
	if (InteractionComponent)
	{
		InteractionComponent->SetScanMode(true);
	}
}

void AGKPlayerCharacter::Input_ScanEnded()
{
	if (InteractionComponent)
	{
		InteractionComponent->SetScanMode(false);
	}
}

void AGKPlayerCharacter::Input_ClimbToggle()
{
	if (!ClimbingComponent)
	{
		return;
	}

	if (ClimbingComponent->IsClimbing())
	{
		ClimbingComponent->StopClimb(false);
		SetLocomotionState(EGKLocomotionState::Walking);
	}
	else
	{
		if (ClimbingComponent->TryStartClimb())
		{
			SetLocomotionState(EGKLocomotionState::Climbing);
		}
	}
}
