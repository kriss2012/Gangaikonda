#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TP_ThirdPersonPlayerController.generated.h"

UCLASS(minimalapi)
class ATP_ThirdPersonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATP_ThirdPersonPlayerController();

protected:
	virtual void BeginPlay() override;
};
