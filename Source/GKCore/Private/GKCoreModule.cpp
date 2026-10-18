#include "GKCoreModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKCoreModule"

void FGKCoreModule::StartupModule()
{
	UE_LOG(LogGKCore, Log, TEXT("GKCore module initialized successfully."));
}

void FGKCoreModule::ShutdownModule()
{
	UE_LOG(LogGKCore, Log, TEXT("GKCore module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_PRIMARY_GAME_MODULE(FGKCoreModule, GKCore, "GKCore");
