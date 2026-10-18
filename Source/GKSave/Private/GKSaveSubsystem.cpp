#include "GKSaveSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GKLogChannels.h"
#include "GKCodexSubsystem.h"
#include "GKQuestSubsystem.h"
#include "GKWorldStateSubsystem.h"
#include "Interfaces/IGKMemoryHolder.h"
#include "Interfaces/IGKPuzzleInterface.h"
#include "NPC/GKNPCMemoryComponent.h"
#include "GKCombatComponent.h"

const FString UGKSaveSubsystem::AutosaveSlotName = TEXT("Autosave_Current");

UGKSaveSubsystem::UGKSaveSubsystem()
	: bPlayerInCombat(false)
{
}

void UGKSaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogGKSave, Log, TEXT("UGKSaveSubsystem initialized. Ready for Doc 18 §6 persistence."));
}

void UGKSaveSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

UGKSaveSubsystem* UGKSaveSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
	return GameInstance ? GameInstance->GetSubsystem<UGKSaveSubsystem>() : nullptr;
}

bool UGKSaveSubsystem::CanSave() const
{
	// Gating: Manual save is blocked while in active combat per Doc 18 §6
	if (bPlayerInCombat)
	{
		return false;
	}

	// Verify player character is alive
	if (const UWorld* World = GetWorld())
	{
		if (const ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(World, 0))
		{
			if (const UGKCombatComponent* CombatComp = PlayerChar->FindComponentByClass<UGKCombatComponent>())
			{
				if (!CombatComp->IsAlive())
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool UGKSaveSubsystem::SaveGame(const FString& InSlotName, int32 InUserIndex)
{
	if (!CanSave())
	{
		UE_LOG(LogGKSave, Warning, TEXT("Cannot save: Player is currently engaged in combat or incapacitated."));
		OnSaveCompleted.Broadcast(InSlotName, false);
		return false;
	}

	UGKSaveGame* SaveObject = CreateSaveSnapshot(InSlotName);
	if (!SaveObject)
	{
		UE_LOG(LogGKSave, Error, TEXT("Failed to generate save snapshot for slot [%s]"), *InSlotName);
		OnSaveCompleted.Broadcast(InSlotName, false);
		return false;
	}

	SaveObject->SaveSlotName = InSlotName;
	SaveObject->SaveSlotIndex = InUserIndex;
	SaveObject->SaveTimestamp = FDateTime::UtcNow();

	const bool bSuccess = UGameplayStatics::SaveGameToSlot(SaveObject, InSlotName, InUserIndex);
	UE_LOG(LogGKSave, Log, TEXT("SaveGame to slot [%s] result: %s (Payload size: %d bytes)"),
		*InSlotName, bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"), MeasureSavePayloadBytes(SaveObject));

	OnSaveCompleted.Broadcast(InSlotName, bSuccess);
	return bSuccess;
}

bool UGKSaveSubsystem::LoadGame(const FString& InSlotName, int32 InUserIndex)
{
	if (!DoesSaveExist(InSlotName, InUserIndex))
	{
		UE_LOG(LogGKSave, Warning, TEXT("Save slot [%s] does not exist."), *InSlotName);
		OnLoadCompleted.Broadcast(InSlotName, false);
		return false;
	}

	USaveGame* LoadedBase = UGameplayStatics::LoadGameFromSlot(InSlotName, InUserIndex);
	UGKSaveGame* SaveObject = Cast<UGKSaveGame>(LoadedBase);
	if (!SaveObject)
	{
		UE_LOG(LogGKSave, Error, TEXT("Loaded save object from slot [%s] is not a valid UGKSaveGame."), *InSlotName);
		OnLoadCompleted.Broadcast(InSlotName, false);
		return false;
	}

	if (!SaveObject->IsCompatibleVersion())
	{
		UE_LOG(LogGKSave, Warning, TEXT("Save version mismatch: save has version %d, expected %d."),
			SaveObject->SaveVersion, UGKSaveGame::CurrentSaveVersion);
	}

	const bool bApplied = ApplySaveSnapshot(SaveObject);
	UE_LOG(LogGKSave, Log, TEXT("LoadGame from slot [%s] completed: %s"), *InSlotName, bApplied ? TEXT("SUCCESS") : TEXT("FAILED"));

	OnLoadCompleted.Broadcast(InSlotName, bApplied);
	return bApplied;
}

bool UGKSaveSubsystem::TriggerAutosave(FName ReasonTag)
{
	UE_LOG(LogGKSave, Log, TEXT("Autosave triggered with reason: [%s]"), *ReasonTag.ToString());

	UGKSaveGame* SaveObject = CreateSaveSnapshot(AutosaveSlotName);
	if (!SaveObject)
	{
		return false;
	}

	SaveObject->SaveSlotName = AutosaveSlotName;
	SaveObject->SaveSlotIndex = 0;
	SaveObject->SaveTimestamp = FDateTime::UtcNow();

	const bool bSuccess = UGameplayStatics::SaveGameToSlot(SaveObject, AutosaveSlotName, 0);
	OnAutosaveTriggered.Broadcast(ReasonTag);
	return bSuccess;
}

bool UGKSaveSubsystem::DoesSaveExist(const FString& InSlotName, int32 InUserIndex) const
{
	return UGameplayStatics::DoesSaveGameExist(InSlotName, InUserIndex);
}

bool UGKSaveSubsystem::DeleteSave(const FString& InSlotName, int32 InUserIndex)
{
	return UGameplayStatics::DeleteGameInSlot(InSlotName, InUserIndex);
}

void UGKSaveSubsystem::RegisterNPC(FName NPCID, UObject* MemoryHolder)
{
	if (!NPCID.IsNone() && MemoryHolder)
	{
		RegisteredNPCs.Add(NPCID, MemoryHolder);
	}
}

void UGKSaveSubsystem::UnregisterNPC(FName NPCID)
{
	RegisteredNPCs.Remove(NPCID);
}

void UGKSaveSubsystem::RegisterPuzzle(FName PuzzleID, UObject* PuzzleActor)
{
	if (!PuzzleID.IsNone() && PuzzleActor)
	{
		RegisteredPuzzles.Add(PuzzleID, PuzzleActor);
	}
}

void UGKSaveSubsystem::UnregisterPuzzle(FName PuzzleID)
{
	RegisteredPuzzles.Remove(PuzzleID);
}

void UGKSaveSubsystem::SetInCombat(bool bInCombat)
{
	bPlayerInCombat = bInCombat;
}

UGKSaveGame* UGKSaveSubsystem::CreateSaveSnapshot(const FString& InSlotName)
{
	UGKSaveGame* SaveObject = Cast<UGKSaveGame>(UGameplayStatics::CreateSaveGameObject(UGKSaveGame::StaticClass()));
	if (!SaveObject)
	{
		return nullptr;
	}

	SaveObject->SaveSlotName = InSlotName;
	SaveObject->SaveVersion = UGKSaveGame::CurrentSaveVersion;
	SaveObject->SaveTimestamp = FDateTime::UtcNow();

	GatherSubsystemState(SaveObject);
	return SaveObject;
}

void UGKSaveSubsystem::GatherSubsystemState(UGKSaveGame* SaveObject)
{
	if (!SaveObject)
	{
		return;
	}

	UGameInstance* GI = GetGameInstance();
	if (!GI)
	{
		return;
	}

	// 1. Codex Subsystem
	if (UGKCodexSubsystem* CodexSubsystem = GI->GetSubsystem<UGKCodexSubsystem>())
	{
		SaveObject->CodexUnlocked = CodexSubsystem->GetUnlockedEntryIDs();
	}

	// 2. Quest Subsystem
	if (UGKQuestSubsystem* QuestSubsystem = GI->GetSubsystem<UGKQuestSubsystem>())
	{
		SaveObject->QuestState = QuestSubsystem->GetSavedQuestStates();
		SaveObject->ActiveQuestID = QuestSubsystem->GetActiveQuestID();
	}

	// 3. World State Subsystem
	if (UGKWorldStateSubsystem* WorldSubsystem = GI->GetSubsystem<UGKWorldStateSubsystem>())
	{
		SaveObject->WorldState = WorldSubsystem->GetAllConstructionStages();
		SaveObject->FactionReputation = WorldSubsystem->GetAllFactionReputations();
	}

	// 4. Bounded NPC Memory (Doc 13 §4, Doc 18 §6)
	SaveObject->NPCMemory.Empty();
	for (auto It = RegisteredNPCs.CreateIterator(); It; ++It)
	{
		if (UObject* Holder = It.Value().Get())
		{
			FGKNPCMemorySaveRecord Record;
			if (Holder->GetClass()->ImplementsInterface(UGKMemoryHolder::StaticClass()))
			{
				Record.Flags = IGKMemoryHolder::Execute_GetAllMemoryFlags(Holder);
			}
			else if (UGKNPCMemoryComponent* MemComp = Cast<UGKNPCMemoryComponent>(Holder))
			{
				Record.Flags = MemComp->GetAllMemoryFlags_Implementation();
			}
			SaveObject->NPCMemory.Add(It.Key(), Record);
		}
	}

	// 5. Puzzles
	SaveObject->PuzzleState.Empty();
	for (auto It = RegisteredPuzzles.CreateIterator(); It; ++It)
	{
		if (UObject* PuzzleObj = It.Value().Get())
		{
			FGKPuzzleSaveRecord Record;
			if (PuzzleObj->GetClass()->ImplementsInterface(UGKPuzzleInterface::StaticClass()))
			{
				Record.State = IGKPuzzleInterface::Execute_GetPuzzleState(PuzzleObj);
			}
			SaveObject->PuzzleState.Add(It.Key(), Record);
		}
	}

	// 6. Player State
	if (const UWorld* World = GetWorld())
	{
		if (const ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(World, 0))
		{
			SaveObject->PlayerState.Location = PlayerChar->GetActorLocation();
			SaveObject->PlayerState.Rotation = PlayerChar->GetActorRotation();

			if (const UGKCombatComponent* CombatComp = PlayerChar->FindComponentByClass<UGKCombatComponent>())
			{
				SaveObject->PlayerState.Health = CombatComp->GetHealth();
			}
		}
	}
}

bool UGKSaveSubsystem::ApplySaveSnapshot(UGKSaveGame* SaveObject)
{
	if (!SaveObject)
	{
		return false;
	}

	DispatchSubsystemState(SaveObject);
	return true;
}

void UGKSaveSubsystem::DispatchSubsystemState(const UGKSaveGame* SaveObject)
{
	if (!SaveObject)
	{
		return;
	}

	UGameInstance* GI = GetGameInstance();
	if (!GI)
	{
		return;
	}

	// 1. Codex Subsystem
	if (UGKCodexSubsystem* CodexSubsystem = GI->GetSubsystem<UGKCodexSubsystem>())
	{
		CodexSubsystem->RestoreUnlockedEntries(SaveObject->CodexUnlocked);
	}

	// 2. Quest Subsystem
	if (UGKQuestSubsystem* QuestSubsystem = GI->GetSubsystem<UGKQuestSubsystem>())
	{
		QuestSubsystem->RestoreQuestStates(SaveObject->QuestState, SaveObject->ActiveQuestID);
	}

	// 3. World State Subsystem
	if (UGKWorldStateSubsystem* WorldSubsystem = GI->GetSubsystem<UGKWorldStateSubsystem>())
	{
		WorldSubsystem->RestoreWorldState(SaveObject->WorldState, SaveObject->FactionReputation);
	}

	// 4. Bounded NPC Memory
	for (const auto& Pair : SaveObject->NPCMemory)
	{
		if (TWeakObjectPtr<UObject>* FoundHolder = RegisteredNPCs.Find(Pair.Key))
		{
			if (UObject* Holder = FoundHolder->Get())
			{
				if (UGKNPCMemoryComponent* MemComp = Cast<UGKNPCMemoryComponent>(Holder))
				{
					MemComp->RestoreMemoryFlags(Pair.Value.Flags);
				}
				else if (Holder->GetClass()->ImplementsInterface(UGKMemoryHolder::StaticClass()))
				{
					for (const auto& FlagPair : Pair.Value.Flags)
					{
						IGKMemoryHolder::Execute_SetMemoryFlag(Holder, FlagPair.Key, FlagPair.Value);
					}
				}
			}
		}
	}

	// 5. Player State
	if (UWorld* World = GetWorld())
	{
		if (ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(World, 0))
		{
			PlayerChar->SetActorLocationAndRotation(SaveObject->PlayerState.Location, SaveObject->PlayerState.Rotation);
		}
	}
}

int32 UGKSaveSubsystem::MeasureSavePayloadBytes(UGKSaveGame* InSaveGame) const
{
	if (!InSaveGame)
	{
		return 0;
	}

	TArray<uint8> Buffer;
	if (UGameplayStatics::SaveGameToMemory(InSaveGame, Buffer))
	{
		return Buffer.Num();
	}
	return 0;
}
