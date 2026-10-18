#include "NPC/GKNPCMemoryComponent.h"
#include "GKLogChannels.h"

UGKNPCMemoryComponent::UGKNPCMemoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UGKNPCMemoryComponent::GetMemoryFlag_Implementation(FName FlagKey, bool& OutValue) const
{
	if (const bool* ValPtr = BoundedMemoryFlags.Find(FlagKey))
	{
		OutValue = *ValPtr;
		return true;
	}

	OutValue = false;
	return false;
}

void UGKNPCMemoryComponent::SetMemoryFlag_Implementation(FName FlagKey, bool Value)
{
	if (FlagKey.IsNone())
	{
		return;
	}

	if (!BoundedMemoryFlags.Contains(FlagKey) && BoundedMemoryFlags.Num() >= MaxMemoryFlags)
	{
		UE_LOG(LogGKDialogue, Warning,
			TEXT("NPCMemoryComponent on %s exceeded memory budget (%d flags). Flag '%s' rejected."),
			GetOwner() ? *GetOwner()->GetName() : TEXT("Standalone"), MaxMemoryFlags, *FlagKey.ToString());
		return;
	}

	const bool bExisted = BoundedMemoryFlags.Contains(FlagKey);
	const bool bOldValue = bExisted ? BoundedMemoryFlags[FlagKey] : false;

	BoundedMemoryFlags.FindOrAdd(FlagKey) = Value;

	if (!bExisted || bOldValue != Value)
	{
		UE_LOG(LogGKDialogue, Log, TEXT("NPC %s memory flag updated: %s = %s"),
			GetOwner() ? *GetOwner()->GetName() : TEXT("Standalone"), *FlagKey.ToString(), Value ? TEXT("True") : TEXT("False"));
		OnMemoryFlagChanged.Broadcast(FlagKey, Value);
	}
}

TMap<FName, bool> UGKNPCMemoryComponent::GetAllMemoryFlags_Implementation() const
{
	return BoundedMemoryFlags;
}

bool UGKNPCMemoryComponent::HasMemoryFlag(FName FlagKey) const
{
	return BoundedMemoryFlags.Contains(FlagKey);
}

bool UGKNPCMemoryComponent::ReadMemoryFlag(FName FlagKey, bool DefaultValue) const
{
	if (const bool* ValPtr = BoundedMemoryFlags.Find(FlagKey))
	{
		return *ValPtr;
	}
	return DefaultValue;
}

void UGKNPCMemoryComponent::RestoreMemoryFlags(const TMap<FName, bool>& InFlags)
{
	BoundedMemoryFlags.Empty();
	int32 Count = 0;
	for (const auto& Pair : InFlags)
	{
		if (Count < MaxMemoryFlags)
		{
			BoundedMemoryFlags.Add(Pair.Key, Pair.Value);
			Count++;
		}
	}
	UE_LOG(LogGKDialogue, Log, TEXT("NPC %s restored %d memory flags from save state."),
		GetOwner() ? *GetOwner()->GetName() : TEXT("Standalone"), BoundedMemoryFlags.Num());
}
