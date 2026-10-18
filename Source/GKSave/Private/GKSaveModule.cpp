#include "GKSaveModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKSaveModule"

void FGKSaveModule::StartupModule()
{
	UE_LOG(LogGKSave, Log, TEXT("GKSave module initialized."));
}

void FGKSaveModule::ShutdownModule()
{
	UE_LOG(LogGKSave, Log, TEXT("GKSave module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKSaveModule, GKSave);
