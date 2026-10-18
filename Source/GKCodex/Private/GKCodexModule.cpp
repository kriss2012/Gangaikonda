#include "GKCodexModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKCodexModule"

void FGKCodexModule::StartupModule()
{
	UE_LOG(LogGKCodex, Log, TEXT("GKCodex module initialized."));
}

void FGKCodexModule::ShutdownModule()
{
	UE_LOG(LogGKCodex, Log, TEXT("GKCodex module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKCodexModule, GKCodex);
