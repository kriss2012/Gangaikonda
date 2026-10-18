#include "GKAIModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKAIModule"

void FGKAIModule::StartupModule()
{
	UE_LOG(LogGKAI, Log, TEXT("GKAI module initialized."));
}

void FGKAIModule::ShutdownModule()
{
	UE_LOG(LogGKAI, Log, TEXT("GKAI module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKAIModule, GKAI);
