#include "GKCombatModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKCombatModule"

void FGKCombatModule::StartupModule()
{
	UE_LOG(LogGKCombat, Log, TEXT("GKCombat module initialized."));
}

void FGKCombatModule::ShutdownModule()
{
	UE_LOG(LogGKCombat, Log, TEXT("GKCombat module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKCombatModule, GKCombat);
