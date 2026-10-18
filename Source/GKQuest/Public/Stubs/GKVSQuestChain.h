#pragma once

#include "CoreMinimal.h"
#include "GKQuestDataAsset.h"

/**
 * Factory class generating the vertical slice main quest data asset (Doc 08 Beats 1–13).
 */
class GKQUEST_API FGKVSQuestChain
{
public:
	/**
	 * Builds DA_Quest_VS_CityOfTheConqueror containing all 13 vertical slice beats.
	 * Historical Category: Documented (Act 6).
	 * Codex Rewards: C1, C2, C3, D1, H2.
	 */
	static UGKQuestDataAsset* BuildVerticalSliceQuest(UObject* Outer);
};
