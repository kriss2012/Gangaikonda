#include "GKQuestModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKQuestModule"

void FGKQuestModule::StartupModule()
{
	UE_LOG(LogGKQuest, Log, TEXT("GKQuest module initialized."));
}

void FGKQuestModule::ShutdownModule()
{
	UE_LOG(LogGKQuest, Log, TEXT("GKQuest module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKQuestModule, GKQuest);
