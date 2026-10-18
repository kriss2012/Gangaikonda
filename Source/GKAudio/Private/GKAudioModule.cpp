#include "GKAudioModule.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "FGKAudioModule"

void FGKAudioModule::StartupModule()
{
	UE_LOG(LogGKAudio, Log, TEXT("GKAudio module initialized."));
}

void FGKAudioModule::ShutdownModule()
{
	UE_LOG(LogGKAudio, Log, TEXT("GKAudio module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGKAudioModule, GKAudio);
