#include "TP_ThirdPersonPlayerController.h"

ATP_ThirdPersonPlayerController::ATP_ThirdPersonPlayerController()
{
	bShowMouseCursor = false;
	bEnableClickEvents = false;
	bEnableMouseOverEvents = false;
}

void ATP_ThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(false);
	SetInputMode(InputMode);
}
