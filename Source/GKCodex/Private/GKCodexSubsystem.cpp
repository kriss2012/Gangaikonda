#include "GKCodexSubsystem.h"
#include "GKLogChannels.h"
#include "Kismet/GameplayStatics.h"

const FSoftObjectPath UGKCodexSubsystem::DefaultEvidenceTablePath(TEXT("/Game/Data/DataTables/DT_HistoricalEvidence.DT_HistoricalEvidence"));

UGKCodexSubsystem::UGKCodexSubsystem()
	: CachedEvidenceTable(nullptr)
{
}

void UGKCodexSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ResolveEvidenceTable();
	UE_LOG(LogGKCodex, Log, TEXT("UGKCodexSubsystem initialized. Evidence table resolved."));
}

void UGKCodexSubsystem::Deinitialize()
{
	UnlockedEntryIDs.Empty();
	CachedEvidenceTable = nullptr;
	Super::Deinitialize();
}

UGKCodexSubsystem* UGKCodexSubsystem::Get(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	if (const UGameInstance* GI = Cast<UGameInstance>(WorldContextObject))
	{
		return const_cast<UGameInstance*>(GI)->GetSubsystem<UGKCodexSubsystem>();
	}

	if (const UGameInstanceSubsystem* Subsystem = Cast<UGameInstanceSubsystem>(WorldContextObject))
	{
		if (UGameInstance* GI = Subsystem->GetGameInstance())
		{
			return GI->GetSubsystem<UGKCodexSubsystem>();
		}
	}

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
	if (!GameInstance)
	{
		return nullptr;
	}

	return GameInstance->GetSubsystem<UGKCodexSubsystem>();
}

UDataTable* UGKCodexSubsystem::ResolveEvidenceTable() const
{
	if (CachedEvidenceTable)
	{
		return CachedEvidenceTable.Get();
	}

	UDataTable* LoadedTable = Cast<UDataTable>(DefaultEvidenceTablePath.TryLoad());
	if (LoadedTable)
	{
		CachedEvidenceTable = LoadedTable;
	}
	else
	{
		UE_LOG(LogGKCodex, Warning, TEXT("DT_HistoricalEvidence could not be loaded at default path %s"),
			*DefaultEvidenceTablePath.ToString());
	}

	return CachedEvidenceTable.Get();
}

void UGKCodexSubsystem::SetEvidenceDataTable(UDataTable* InTable)
{
	CachedEvidenceTable = InTable;
}

bool UGKCodexSubsystem::GetEvidenceRow(FName EvidenceID, FGKEvidenceRow& OutRow) const
{
	UDataTable* Table = ResolveEvidenceTable();
	if (!Table)
	{
		UE_LOG(LogGKCodex, Error, TEXT("GetEvidenceRow failed: Evidence DataTable is null."));
		return false;
	}

	FGKEvidenceRow* FoundRow = Table->FindRow<FGKEvidenceRow>(EvidenceID, TEXT("GKCodexSubsystem"));
	if (!FoundRow)
	{
		// Try case-insensitive fallback across all rows if key is not exact row name
		for (const auto& It : Table->GetRowMap())
		{
			const FGKEvidenceRow* RowPtr = reinterpret_cast<const FGKEvidenceRow*>(It.Value);
			if (RowPtr && RowPtr->EvidenceID == EvidenceID)
			{
				OutRow = *RowPtr;
				return true;
			}
		}

		UE_LOG(LogGKCodex, Warning, TEXT("EvidenceID '%s' not found in DT_HistoricalEvidence."), *EvidenceID.ToString());
		return false;
	}

	OutRow = *FoundRow;
	return true;
}

bool UGKCodexSubsystem::UnlockEntry(FName EvidenceID)
{
	if (EvidenceID.IsNone())
	{
		UE_LOG(LogGKCodex, Warning, TEXT("UnlockEntry rejected: EvidenceID is None."));
		return false;
	}

	if (UnlockedEntryIDs.Contains(EvidenceID))
	{
		UE_LOG(LogGKCodex, Verbose, TEXT("EvidenceID '%s' is already unlocked."), *EvidenceID.ToString());
		return false;
	}

	FGKEvidenceRow EvidenceRow;
	if (!GetEvidenceRow(EvidenceID, EvidenceRow))
	{
		UE_LOG(LogGKCodex, Warning, TEXT("UnlockEntry failed: ID '%s' has no valid row in DT_HistoricalEvidence."),
			*EvidenceID.ToString());
		return false;
	}

	UnlockedEntryIDs.Add(EvidenceID);
	UE_LOG(LogGKCodex, Log, TEXT("HISTORICAL RECORD DISCOVERED: [%s] Category=%d, Confidence=%d"),
		*EvidenceID.ToString(), (int32)EvidenceRow.Category, (int32)EvidenceRow.Confidence);

	OnEntryUnlocked.Broadcast(EvidenceRow);
	return true;
}

bool UGKCodexSubsystem::IsUnlocked(FName EvidenceID) const
{
	return UnlockedEntryIDs.Contains(EvidenceID);
}

TArray<FGKEvidenceRow> UGKCodexSubsystem::GetAllUnlockedEntries() const
{
	TArray<FGKEvidenceRow> Results;
	Results.Reserve(UnlockedEntryIDs.Num());

	for (const FName& Id : UnlockedEntryIDs)
	{
		FGKEvidenceRow Row;
		if (GetEvidenceRow(Id, Row))
		{
			Results.Add(Row);
		}
	}

	return Results;
}

TArray<FGKEvidenceRow> UGKCodexSubsystem::GetUnlockedEntriesByCategory(EGKEvidenceCategory Category) const
{
	TArray<FGKEvidenceRow> Results;

	for (const FName& Id : UnlockedEntryIDs)
	{
		FGKEvidenceRow Row;
		if (GetEvidenceRow(Id, Row) && Row.Category == Category)
		{
			Results.Add(Row);
		}
	}

	return Results;
}

TArray<UGKCodexEntryViewModel*> UGKCodexSubsystem::GetUnlockedViewModels(UObject* Outer)
{
	TArray<UGKCodexEntryViewModel*> ViewModels;
	ViewModels.Reserve(UnlockedEntryIDs.Num());

	for (const FName& Id : UnlockedEntryIDs)
	{
		FGKEvidenceRow Row;
		if (GetEvidenceRow(Id, Row))
		{
			UGKCodexEntryViewModel* VM = UGKCodexEntryViewModel::CreateFromRow(Outer, Row);
			if (VM)
			{
				ViewModels.Add(VM);
			}
		}
	}

	return ViewModels;
}

int32 UGKCodexSubsystem::GetTotalCount() const
{
	UDataTable* Table = ResolveEvidenceTable();
	return Table ? Table->GetRowNames().Num() : 0;
}

void UGKCodexSubsystem::RestoreUnlockedEntries(const TSet<FName>& InUnlockedIDs)
{
	UnlockedEntryIDs = InUnlockedIDs;
	UE_LOG(LogGKCodex, Log, TEXT("Restored %d unlocked Codex entries from save state."), UnlockedEntryIDs.Num());
}
