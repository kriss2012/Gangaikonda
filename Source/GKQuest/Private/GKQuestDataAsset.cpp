#include "GKQuestDataAsset.h"

UGKQuestDataAsset::UGKQuestDataAsset()
	: QuestID(NAME_None)
	, ActNumber(1)
	, HistoricalCategory(EGKEvidenceCategory::Documented)
	, NextQuestID(NAME_None)
{
}

bool UGKQuestDataAsset::FindObjective(FName ObjectiveID, FGKQuestObjective& OutObjective) const
{
	for (const FGKQuestObjective& Obj : Objectives)
	{
		if (Obj.ObjectiveID == ObjectiveID)
		{
			OutObjective = Obj;
			return true;
		}
	}
	return false;
}

int32 UGKQuestDataAsset::GetObjectiveIndex(FName ObjectiveID) const
{
	for (int32 i = 0; i < Objectives.Num(); ++i)
	{
		if (Objectives[i].ObjectiveID == ObjectiveID)
		{
			return i;
		}
	}
	return INDEX_NONE;
}
