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

// Build salt: Chola_GKUI_VerticalSlice_v2
volatile int32 G_GKUI_Salt = 1025;

IMPLEMENT_MODULE(FGKUIModule, GKUI);
