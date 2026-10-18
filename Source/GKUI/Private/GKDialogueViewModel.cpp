#include "GKDialogueViewModel.h"
#include "GKDialogueComponent.h"

#define LOCTEXT_NAMESPACE "GKDialogueViewModel"

UGKDialogueOptionViewModel* UGKDialogueOptionViewModel::CreateFromOption(UObject* Outer, int32 InIndex, const FGKDialogueOption& Option)
{
	UGKDialogueOptionViewModel* VM = NewObject<UGKDialogueOptionViewModel>(Outer);
	if (VM)
	{
		VM->OptionIndex = InIndex;
		VM->OptionText = Option.OptionText;
		VM->bHasHistoricalClaim = Option.bHasHistoricalClaim;
		VM->Category = Option.HistoricalCategory;
	}
	return VM;
}

FText UGKDialogueOptionViewModel::GetCategoryBadgeText() const
{
	if (!bHasHistoricalClaim)
	{
		return FText::GetEmpty();
	}

	switch (Category)
	{
	case EGKEvidenceCategory::Documented:
		return LOCTEXT("BadgeDoc", "[DOCUMENTED]");
	case EGKEvidenceCategory::PlausibleReconstruction:
		return LOCTEXT("BadgePlausible", "[PLAUSIBLE RECONSTRUCTION]");
	case EGKEvidenceCategory::Fictional:
	default:
		return LOCTEXT("BadgeFictional", "[FICTIONAL]");
	}
}

EGKCodexBorderStyle UGKDialogueOptionViewModel::GetBorderStyle() const
{
	switch (Category)
	{
	case EGKEvidenceCategory::Documented:
		return EGKCodexBorderStyle::Solid;
	case EGKEvidenceCategory::PlausibleReconstruction:
		return EGKCodexBorderStyle::DashedHatched;
	case EGKEvidenceCategory::Fictional:
	default:
		return EGKCodexBorderStyle::Desaturated;
	}
}

FLinearColor UGKDialogueOptionViewModel::GetThemeColor() const
{
	switch (Category)
	{
	case EGKEvidenceCategory::Documented:
		return FLinearColor(0.85f, 0.65f, 0.20f, 1.0f);
	case EGKEvidenceCategory::PlausibleReconstruction:
		return FLinearColor(0.70f, 0.50f, 0.30f, 1.0f);
	case EGKEvidenceCategory::Fictional:
	default:
		return FLinearColor(0.45f, 0.45f, 0.48f, 1.0f);
	}
}

void UGKDialogueViewModel::Initialize(UGKDialogueComponent* InDialogueComponent)
{
	if (!InDialogueComponent)
	{
		return;
	}

	BoundDialogueComponent = InDialogueComponent;
	InDialogueComponent->OnNodeChanged.AddDynamic(this, &UGKDialogueViewModel::HandleNodeChanged);
	InDialogueComponent->OnOptionsUpdated.AddDynamic(this, &UGKDialogueViewModel::HandleOptionsUpdated);
	InDialogueComponent->OnDialogueEnded.AddDynamic(this, &UGKDialogueViewModel::HandleDialogueEnded);
}

void UGKDialogueViewModel::HandleNodeChanged(const FGKDialogueNode& NewNode)
{
	CurrentSpeakerName = NewNode.SpeakerDisplayName;
	CurrentSpeakerRoleTitle = NewNode.SpeakerRoleTitle;
	CurrentSubtitleText = NewNode.SpokenText;
}

void UGKDialogueViewModel::HandleOptionsUpdated(const TArray<FGKDialogueOption>& AvailableOptions)
{
	CachedOptionViewModels.Empty();
	CachedOptionViewModels.Reserve(AvailableOptions.Num());

	for (int32 i = 0; i < AvailableOptions.Num(); ++i)
	{
		UGKDialogueOptionViewModel* OptVM = UGKDialogueOptionViewModel::CreateFromOption(this, i, AvailableOptions[i]);
		if (OptVM)
		{
			CachedOptionViewModels.Add(OptVM);
		}
	}
}

void UGKDialogueViewModel::HandleDialogueEnded()
{
	CurrentSpeakerName = FText::GetEmpty();
	CurrentSpeakerRoleTitle = FText::GetEmpty();
	CurrentSubtitleText = FText::GetEmpty();
	CachedOptionViewModels.Empty();
}

bool UGKDialogueViewModel::SelectOption(int32 OptionIndex)
{
	if (BoundDialogueComponent.IsValid())
	{
		return BoundDialogueComponent->SelectOption(OptionIndex);
	}
	return false;
}

bool UGKDialogueViewModel::IsDialogueActive() const
{
	return BoundDialogueComponent.IsValid() && BoundDialogueComponent->IsInDialogue();
}

#undef LOCTEXT_NAMESPACE
