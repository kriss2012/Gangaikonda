#include "GKWorldStateSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GKLogChannels.h"

UGKWorldStateSubsystem::UGKWorldStateSubsystem()
{
}

void UGKWorldStateSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ResetToDefaults();
	UE_LOG(LogGKWorld, Log, TEXT("UGKWorldStateSubsystem initialized with default vertical slice state."));
}

void UGKWorldStateSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

UGKWorldStateSubsystem* UGKWorldStateSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
	return GameInstance ? GameInstance->GetSubsystem<UGKWorldStateSubsystem>() : nullptr;
}

void UGKWorldStateSubsystem::SetConstructionStage(FName LocationID, EGKConstructionStage NewStage)
{
	if (LocationID.IsNone())
	{
		return;
	}

	const EGKConstructionStage* ExistingStage = ConstructionStages.Find(LocationID);
	if (!ExistingStage || *ExistingStage != NewStage)
	{
		ConstructionStages.Add(LocationID, NewStage);
		UE_LOG(LogGKWorld, Log, TEXT("Construction stage changed for location [%s] to [%d]"), *LocationID.ToString(), static_cast<int32>(NewStage));
		OnConstructionStageChanged.Broadcast(LocationID, NewStage);
	}
}

EGKConstructionStage UGKWorldStateSubsystem::GetConstructionStage(FName LocationID) const
{
	if (const EGKConstructionStage* Found = ConstructionStages.Find(LocationID))
	{
		return *Found;
	}
	return EGKConstructionStage::FoundationExcavation;
}

void UGKWorldStateSubsystem::SetFactionReputation(FName FactionID, EGKFactionReputation NewReputation)
{
	if (FactionID.IsNone())
	{
		return;
	}

	const EGKFactionReputation* ExistingReputation = FactionReputations.Find(FactionID);
	if (!ExistingReputation || *ExistingReputation != NewReputation)
	{
		FactionReputations.Add(FactionID, NewReputation);
		UE_LOG(LogGKWorld, Log, TEXT("Faction [%s] reputation changed to [%d]"), *FactionID.ToString(), static_cast<int32>(NewReputation));
		OnFactionReputationChanged.Broadcast(FactionID, NewReputation);
	}
}

EGKFactionReputation UGKWorldStateSubsystem::GetFactionReputation(FName FactionID) const
{
	if (const EGKFactionReputation* Found = FactionReputations.Find(FactionID))
	{
		return *Found;
	}
	return EGKFactionReputation::Neutral;
}

void UGKWorldStateSubsystem::RestoreWorldState(const TMap<FName, EGKConstructionStage>& InStages, const TMap<FName, EGKFactionReputation>& InReputations)
{
	ConstructionStages = InStages;
	FactionReputations = InReputations;

	UE_LOG(LogGKWorld, Log, TEXT("UGKWorldStateSubsystem restored: %d construction stages, %d faction standings."),
		ConstructionStages.Num(), FactionReputations.Num());
}

void UGKWorldStateSubsystem::ResetToDefaults()
{
	ConstructionStages.Empty();
	FactionReputations.Empty();

	// Vertical slice Zone 5 Gangaikonda default is Stage 3: Mid-Vimana Scaffolding Lattice (Doc 02, Doc 08, Doc 19)
	ConstructionStages.Add(TEXT("Zone5_Gangaikonda"), EGKConstructionStage::ScaffoldingVimanaMid);
	ConstructionStages.Add(TEXT("Zone5_LionWell"), EGKConstructionStage::LowerGraniteCourses);

	// Non-numeric faction defaults (Doc 01 §23, Doc 14)
	FactionReputations.Add(TEXT("RoyalCourt"), EGKFactionReputation::Neutral);
	FactionReputations.Add(TEXT("GuildOfArchitects"), EGKFactionReputation::Respected);
	FactionReputations.Add(TEXT("QuarryWorkers"), EGKFactionReputation::Neutral);
	FactionReputations.Add(TEXT("TemplePriesthood"), EGKFactionReputation::Neutral);
}
