#include "GKSaveGame.h"

UGKSaveGame::UGKSaveGame()
	: SaveSlotName(TEXT("ManualSave_0"))
	, SaveSlotIndex(0)
	, SaveTimestamp(FDateTime::UtcNow())
	, SaveVersion(CurrentSaveVersion)
	, ActiveQuestID(NAME_None)
{
}
