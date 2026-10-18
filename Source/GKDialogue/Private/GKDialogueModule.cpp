#include "GKDialogueModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKDialogueModule"

void FGKDialogueModule::StartupModule()
{
	UE_LOG(LogGKDialogue, Log, TEXT("GKDialogue module initialized."));
}

void FGKDialogueModule::ShutdownModule()
{
	UE_LOG(LogGKDialogue, Log, TEXT("GKDialogue module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKDialogueModule, GKDialogue);
