#pragma once

#include "CoreMinimal.h"
#include "GKStealthTypes.generated.h"

/**
 * Graduated NPC suspicion state machine (Doc 11 §3).
 * Non-punitive: Suspicion can decay back to Unaware if player breaks sight and avoids sound.
 */
UENUM(BlueprintType)
enum class EGKSuspicionState : uint8
{
	Unaware   UMETA(DisplayName = "Unaware (Normal Routine)"),
	Alert     UMETA(DisplayName = "Alert (Investigating Anomaly)"),
	Searching UMETA(DisplayName = "Searching (Active Sweep)"),
	Hostile   UMETA(DisplayName = "Hostile (Engaged in Combat)")
};

/**
 * Period-appropriate role disguises (Doc 11 §4).
 */
UENUM(BlueprintType)
enum class EGKDisguiseRole : uint8
{
	None     UMETA(DisplayName = "Standard Attire"),
	Worker   UMETA(DisplayName = "Quarry / Construction Worker"),
	Scribe   UMETA(DisplayName = "Temple Scribe"),
	Merchant UMETA(DisplayName = "Guild Merchant")
};
