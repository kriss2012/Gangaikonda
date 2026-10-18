#include "GKWorldModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKWorldModule"

void FGKWorldModule::StartupModule()
{
	UE_LOG(LogGKWorld, Log, TEXT("GKWorld module initialized."));
}

void FGKWorldModule::ShutdownModule()
{
	UE_LOG(LogGKWorld, Log, TEXT("GKWorld module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKWorldModule, GKWorld);
