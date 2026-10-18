#include "GKUIModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKUIModule"

void FGKUIModule::StartupModule()
{
	UE_LOG(LogGKUI, Log, TEXT("GKUI module initialized."));
}

void FGKUIModule::ShutdownModule()
{
	UE_LOG(LogGKUI, Log, TEXT("GKUI module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKUIModule, GKUI);
