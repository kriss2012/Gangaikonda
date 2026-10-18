#include "GKExplorationModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKExplorationModule"

void FGKExplorationModule::StartupModule()
{
	UE_LOG(LogGKExploration, Log, TEXT("GKExploration module initialized."));
}

void FGKExplorationModule::ShutdownModule()
{
	UE_LOG(LogGKExploration, Log, TEXT("GKExploration module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKExplorationModule, GKExploration);
