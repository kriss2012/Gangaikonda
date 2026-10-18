#include "GKCharacterModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKCharacterModule"

void FGKCharacterModule::StartupModule()
{
	UE_LOG(LogGKCharacter, Log, TEXT("GKCharacter module initialized."));
}

void FGKCharacterModule::ShutdownModule()
{
	UE_LOG(LogGKCharacter, Log, TEXT("GKCharacter module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKCharacterModule, GKCharacter);
