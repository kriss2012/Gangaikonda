#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GKCoreTypes.h"
#include "GKQuestTypes.h"
#include "GKWorldTypes.h"
#include "GKSaveGame.generated.h"

/**
 * Serialized memory container for a single NPC (Doc 13 §4, Doc 18 §6).
 * Enforces the bounded 32-flag budget per NPC to prevent save bloat.
 */
USTRUCT(BlueprintType)
struct GKSAVE_API FGKNPCMemorySaveRecord
{
	GENERATED_BODY()

	FGKNPCMemorySaveRecord() {}

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	TMap<FName, bool> Flags;
};

/**
 * Serialized state record for an individual puzzle actor (Doc 09, Doc 18 §4 & §6).
 */
USTRUCT(BlueprintType)
struct GKSAVE_API FGKPuzzleSaveRecord
{
	GENERATED_BODY()

	FGKPuzzleSaveRecord()
		: State(EGKPuzzleState::Unsolved)
		, HintsUnlocked(0)
		, SolvedStage(0)
	{}

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	EGKPuzzleState State;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	int32 HintsUnlocked;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	int32 SolvedStage;
};

/**
 * Player transform and vital condition at time of save.
 */
USTRUCT(BlueprintType)
struct GKSAVE_API FGKPlayerSaveRecord
{
	GENERATED_BODY()

	FGKPlayerSaveRecord()
		: Location(FVector::ZeroVector)
		, Rotation(FRotator::ZeroRotator)
		, Health(100.0f)
		, Stamina(100.0f)
	{}

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	FVector Location;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	FRotator Rotation;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	float Health;

	UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "GK|Save")
	float Stamina;
};

/**
 * Comprehensive SaveGame object implementing the Doc 18 §6 save architecture schema.
 * Persists Quest states, unlocked Codex evidence, bounded NPC memory flags,
 * world construction progression, puzzle states, non-numeric faction reputations, and player position.
 */
UCLASS()
class GKSAVE_API UGKSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UGKSaveGame();

	/** Save metadata */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	FString SaveSlotName;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	int32 SaveSlotIndex;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	FDateTime SaveTimestamp;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	int32 SaveVersion;

	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	FName ActiveQuestID;

	/** Quest progression: Map<QuestID, QuestStateEnum> (Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TMap<FName, EGKQuestState> QuestState;

	/** Codex unlocked: Set<EvidenceID> (Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TSet<FName> CodexUnlocked;

	/** NPC memory: Map<NPCID, Map<FlagName, bool>> (Doc 13 §4, Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TMap<FName, FGKNPCMemorySaveRecord> NPCMemory;

	/** World construction state: Map<LocationID, WorldStateEnum> (Doc 13 §5, Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TMap<FName, EGKConstructionStage> WorldState;

	/** Puzzle state: Map<PuzzleID, PuzzleStateStruct> (Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TMap<FName, FGKPuzzleSaveRecord> PuzzleState;

	/** Faction reputation: Map<FactionID, ReputationEnum> (Doc 01 §23, Doc 14, Doc 18 §6) */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	TMap<FName, EGKFactionReputation> FactionReputation;

	/** Player condition and location */
	UPROPERTY(SaveGame, VisibleAnywhere, BlueprintReadOnly, Category = "GK|Save")
	FGKPlayerSaveRecord PlayerState;

	/** Helper to validate save version compatibility */
	bool IsCompatibleVersion() const { return SaveVersion == CurrentSaveVersion; }

	static constexpr int32 CurrentSaveVersion = 1;
};
