#pragma once

#include "CoreMinimal.h"
#include "GKDialogueTypes.h"

/**
 * Hand-authored vertical slice dialogue trees (Doc 08 Minutes 6–9 and 14–18).
 * Provides the Scholar encounter and Architect encounter with the first cosmetic branch.
 */
class GKDIALOGUE_API FGKVSDialogueTrees
{
public:
	/**
	 * Beat 3: Meet Scholar in Archive Tent (Minutes 6–9).
	 * Sets 'scholar_met = true', unlocks scan tool context, engages Doc 03 B1/H1 historical evidence.
	 */
	static FGKDialogueTree BuildScholarDialogueTree();

	/**
	 * Beat 5: Meet Architect in Planning Pavilion (Minutes 14–18).
	 * Houses the first cosmetic branch: Structure preference vs. Hydraulics preference.
	 * Sets 'architect_favors_structure = true' OR 'architect_favors_hydraulics = true'.
	 */
	static FGKDialogueTree BuildArchitectDialogueTree();
};
