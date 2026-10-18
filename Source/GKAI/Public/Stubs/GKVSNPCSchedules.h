#pragma once

#include "CoreMinimal.h"
#include "GKAITypes.h"

/**
 * Hand-authored vertical slice schedules for Tier 1 and Tier 2 NPCs (Doc 13 §2 & §3).
 */
class GKAI_API FGKVSNPCSchedules
{
public:
	/** Tier 1 Named NPC: Royal Epigraphist Ilango (Archive Tent, Site Office) */
	static FGKNPCSchedule BuildScholarSchedule();

	/** Tier 1 Named NPC: Chief Sthapati Maravan (Planning Pavilion, Scaffolding) */
	static FGKNPCSchedule BuildArchitectSchedule();

	/** Tier 2 Templated Semi-Named NPC: Quarry Stonecutter Foreman */
	static FGKNPCSchedule BuildQuarryWorkerSchedule();
};
