#include "Inscription/GKInscriptionActor.h"
#include "GKLogChannels.h"

#define LOCTEXT_NAMESPACE "GKInscriptionActor"

AGKInscriptionActor::AGKInscriptionActor()
{
	PuzzleID = FName(TEXT("P10_ScratchedStone"));
	EvidenceRewardID = FName(TEXT("H2")); // Traces to Doc 03 H2: Script paleography evolution
	InvestigationPrompt = LOCTEXT("DecodePrompt", "[E] Decode Foundation Inscription");

	StoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StoneMesh"));
	RootComponent = StoneMesh;
	StoneMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	InscriptionPanelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InscriptionPanelMesh"));
	InscriptionPanelMesh->SetupAttachment(RootComponent);
	InscriptionPanelMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
	InscriptionPanelMesh->SetCollisionProfileName(TEXT("NoCollision"));

	SetupDefaultHistoricalFragments();
}

void AGKInscriptionActor::BeginPlay()
{
	Super::BeginPlay();
	OnResetPuzzleElements();
}

void AGKInscriptionActor::SetupDefaultHistoricalFragments()
{
	// Strict adherence to Hard Rule 2: Placeholder text must be visibly marked [PLACEHOLDER – FICTIONAL]
	FullDecodedText = LOCTEXT("FoundationVerse",
		"[PLACEHOLDER – FICTIONAL] In the regnal period of Rajendra Chola I, Gangaikonda Chola, by imperial command "
		"this foundation course is laid for the great abode of Shiva, commemorating the holy Ganga waters brought south.");

	PaleographicPeriodNotes = LOCTEXT("PaleoNotes",
		"Early 11th century Grantha-Tamil transitional paleography characterized by rounded loop ligatures and distinctive pulli marks.");

	// Three-tier hints for Doc 09 P10
	HintTiers.Empty();
	HintTiers.Add(LOCTEXT("P10Hint1", "Compare the looped prefix glyph against the Scholar's reference chart."));
	HintTiers.Add(LOCTEXT("P10Hint2", "Early Chola royal inscriptions consistently open with the standard praśasti ligature."));
	HintTiers.Add(LOCTEXT("P10Hint3", "The eroded central stone fragment matches the Grantha character 'Konda' on line 2 of the chart."));

	// Four seed fragments (P10)
	InscribedFragments.Empty();

	FGKInscriptionFragment Frag1;
	Frag1.FragmentID = 1;
	Frag1.PaleographicGlyph = FText::FromString(TEXT("𑌸𑍍𑌵"));
	Frag1.Transliteration = FText::FromString(TEXT("Sva-sti"));
	Frag1.MeaningTranslation = LOCTEXT("Frag1Meaning", "Hail / Auspicious beginning");
	Frag1.bIsDamaged = false;
	InscribedFragments.Add(Frag1);

	FGKInscriptionFragment Frag2;
	Frag2.FragmentID = 2;
	Frag2.PaleographicGlyph = FText::FromString(TEXT("𑌗𑌙𑍍𑌗𑍈"));
	Frag2.Transliteration = FText::FromString(TEXT("Gan-gai"));
	Frag2.MeaningTranslation = LOCTEXT("Frag2Meaning", "The sacred Ganga river");
	Frag2.bIsDamaged = true; // Requires chart matching
	InscribedFragments.Add(Frag2);

	FGKInscriptionFragment Frag3;
	Frag3.FragmentID = 3;
	Frag3.PaleographicGlyph = FText::FromString(TEXT("𑌕𑍋𑌟𑍍𑌟"));
	Frag3.Transliteration = FText::FromString(TEXT("Kon-da"));
	Frag3.MeaningTranslation = LOCTEXT("Frag3Meaning", "He who took / Conquered");
	Frag3.bIsDamaged = true; // Requires chart matching
	InscribedFragments.Add(Frag3);

	FGKInscriptionFragment Frag4;
	Frag4.FragmentID = 4;
	Frag4.PaleographicGlyph = FText::FromString(TEXT("𑌚𑍋𑌴"));
	Frag4.Transliteration = FText::FromString(TEXT("Cho-la"));
	Frag4.MeaningTranslation = LOCTEXT("Frag4Meaning", "The Chola King");
	Frag4.bIsDamaged = false;
	InscribedFragments.Add(Frag4);

	// Scholar's reference chart
	ScholarReferenceChart.Empty();

	FGKScholarReferenceEntry RefA;
	RefA.ScriptSymbol = FText::FromString(TEXT("𑌸𑍍𑌵 (Svasti)"));
	RefA.PeriodClassification = LOCTEXT("RefAPeriod", "Grantha Royal Formula (10th–11th c.)");
	RefA.PhoneticKey = FText::FromString(TEXT("sva-sti"));
	RefA.HistoricalNotes = LOCTEXT("RefANotes", "Universal invocation opening royal praśasti grants.");
	ScholarReferenceChart.Add(RefA);

	FGKScholarReferenceEntry RefB;
	RefB.ScriptSymbol = FText::FromString(TEXT("𑌗𑌙𑍍𑌗𑍈 (Gangai)"));
	RefB.PeriodClassification = LOCTEXT("RefBPeriod", "Early Chola Tamil-Grantha blend");
	RefB.PhoneticKey = FText::FromString(TEXT("gan-gai"));
	RefB.HistoricalNotes = LOCTEXT("RefBNotes", "Distinctive double velar nasal curl denoting the northern river.");
	ScholarReferenceChart.Add(RefB);

	FGKScholarReferenceEntry RefC;
	RefC.ScriptSymbol = FText::FromString(TEXT("𑌕𑍋𑌟𑍍𑌟 (Konda)"));
	RefC.PeriodClassification = LOCTEXT("RefCPeriod", "Chola Epigraphic Tamil");
	RefC.PhoneticKey = FText::FromString(TEXT("kon-da"));
	RefC.HistoricalNotes = LOCTEXT("RefCNotes", "Past verbal participle ('having taken').");
	ScholarReferenceChart.Add(RefC);

	FGKScholarReferenceEntry RefD;
	RefD.ScriptSymbol = FText::FromString(TEXT("𑌚𑍋𑌴 (Chola)"));
	RefD.PeriodClassification = LOCTEXT("RefDPeriod", "Epigraphic Tamil");
	RefD.PhoneticKey = FText::FromString(TEXT("co-zha"));
	RefD.HistoricalNotes = LOCTEXT("RefDNotes", "Dynastic title with characteristic retroflex zh sound.");
	ScholarReferenceChart.Add(RefD);

	// Correct sequence: 1, 2, 3, 4 -> "Svasti Gangai Konda Chola"
	SolutionSequence = { 1, 2, 3, 4 };
}

void AGKInscriptionActor::OnResetPuzzleElements()
{
	PlayerAssignedSequence.Init(0, SolutionSequence.Num());
}

bool AGKInscriptionActor::AssignFragmentToSlot(int32 SlotIndex, int32 FragmentID)
{
	if (!PlayerAssignedSequence.IsValidIndex(SlotIndex))
	{
		return false;
	}

	PlayerAssignedSequence[SlotIndex] = FragmentID;
	OnSlotUpdated.Broadcast(SlotIndex, FragmentID);

	// Auto-check if all slots are filled
	bool bAllFilled = true;
	for (int32 Val : PlayerAssignedSequence)
	{
		if (Val <= 0)
		{
			bAllFilled = false;
			break;
		}
	}

	if (bAllFilled)
	{
		AttemptSolve_Implementation();
	}

	return true;
}

void AGKInscriptionActor::ClearSlot(int32 SlotIndex)
{
	if (PlayerAssignedSequence.IsValidIndex(SlotIndex))
	{
		PlayerAssignedSequence[SlotIndex] = 0;
		OnSlotUpdated.Broadcast(SlotIndex, 0);
	}
}

bool AGKInscriptionActor::EvaluateSolutionConditions()
{
	if (PlayerAssignedSequence.Num() != SolutionSequence.Num())
	{
		return false;
	}

	for (int32 i = 0; i < SolutionSequence.Num(); ++i)
	{
		if (PlayerAssignedSequence[i] != SolutionSequence[i])
		{
			return false;
		}
	}

	return true;
}

void AGKInscriptionActor::OnInvestigate_Implementation(AActor* Investigator)
{
	UE_LOG(LogGKPuzzle, Log, TEXT("Arulan engaged with inscription actor %s. State=%d"),
		*GetName(), (int32)CurrentPuzzleState);

	OnDecodingSessionStarted.Broadcast(this);
}

bool AGKInscriptionActor::CanInvestigate_Implementation(AActor* Investigator) const
{
	return true;
}

FText AGKInscriptionActor::GetInvestigationPromptText_Implementation() const
{
	if (CurrentPuzzleState == EGKPuzzleState::Solved)
	{
		return LOCTEXT("DecodedPrompt", "[E] Read Decoded Inscription");
	}

	return InvestigationPrompt;
}

#undef LOCTEXT_NAMESPACE
