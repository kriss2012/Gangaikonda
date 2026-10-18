#include "GKPuzzleModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKPuzzleModule"

void FGKPuzzleModule::StartupModule()
{
	UE_LOG(LogGKPuzzle, Log, TEXT("GKPuzzle module initialized."));
}

void FGKPuzzleModule::ShutdownModule()
{
	UE_LOG(LogGKPuzzle, Log, TEXT("GKPuzzle module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKPuzzleModule, GKPuzzle);
