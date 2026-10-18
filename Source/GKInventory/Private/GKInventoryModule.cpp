#include "GKInventoryModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKInventoryModule"

void FGKInventoryModule::StartupModule()
{
	UE_LOG(LogGKInventory, Log, TEXT("GKInventory module initialized."));
}

void FGKInventoryModule::ShutdownModule()
{
	UE_LOG(LogGKInventory, Log, TEXT("GKInventory module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKInventoryModule, GKInventory);
