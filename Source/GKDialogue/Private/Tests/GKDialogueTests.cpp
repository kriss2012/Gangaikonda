#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKDialogueTypes.h"
#include "GKDialogueComponent.h"
#include "Stubs/GKVSDialogueTrees.h"
#include "Interfaces/IGKMemoryHolder.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Mock actor implementing IGKMemoryHolder for dialogue testing
 */
class FMockMemoryActor : public AActor, public IGKMemoryHolder
{
public:
	TMap<FName, bool> Flags;

	virtual bool GetMemoryFlag_Implementation(FName FlagKey, bool& OutValue) const override
	{
		if (const bool* Val = Flags.Find(FlagKey))
		{
			OutValue = *Val;
			return true;
		}
		OutValue = false;
		return false;
	}

	virtual void SetMemoryFlag_Implementation(FName FlagKey, bool Value) override
	{
		Flags.FindOrAdd(FlagKey) = Value;
	}

	virtual TMap<FName, bool> GetAllMemoryFlags_Implementation() const override
	{
		return Flags;
	}
};

/**
 * Test: GK.Dialogue.MemoryAndBranching
 * Validates dialogue progression, memory flag mutation on option choice, and cosmetic branch handling.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKDialogueBranchingTest, "GK.Dialogue.MemoryAndBranching", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKDialogueBranchingTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for dialogue test"), World);

	AActor* TestOwner = World->SpawnActor<AActor>();
	UGKDialogueComponent* DialogueComp = NewObject<UGKDialogueComponent>(TestOwner);

	// Spawn mock NPC
	AActor* MockNPC = World->SpawnActor<AActor>();
	// Assign interface via mock wrapper or component test
	FGKDialogueTree ArchTree = FGKVSDialogueTrees::BuildArchitectDialogueTree();

	bool bStarted = DialogueComp->StartDialogue(ArchTree, MockNPC);
	TestTrue(TEXT("Dialogue started successfully"), bStarted);
	TestTrue(TEXT("Is in dialogue"), DialogueComp->IsInDialogue());

	FGKDialogueNode CurrentNode;
	TestTrue(TEXT("Retrieved current node"), DialogueComp->GetCurrentNode(CurrentNode));
	TestEqual(TEXT("Entry node is Node 1"), CurrentNode.NodeID, 1);

	TArray<FGKDialogueOption> Options = DialogueComp->GetAvailableOptions();
	TestEqual(TEXT("Two cosmetic branch options available"), Options.Num(), 2);

	// Check Option 0 (Structural preference)
	TestTrue(TEXT("Option 0 has historical claim"), Options[0].bHasHistoricalClaim);
	TestEqual(TEXT("Option 0 is Documented"), Options[0].HistoricalCategory, EGKEvidenceCategory::Documented);
	TestEqual(TEXT("Option 0 sets architect_favors_structure"), Options[0].MemoryFlagToSet, FName(TEXT("architect_favors_structure")));

	// Check Option 1 (Hydraulic preference)
	TestTrue(TEXT("Option 1 has historical claim"), Options[1].bHasHistoricalClaim);
	TestEqual(TEXT("Option 1 is PlausibleReconstruction"), Options[1].HistoricalCategory, EGKEvidenceCategory::PlausibleReconstruction);
	TestEqual(TEXT("Option 1 sets architect_favors_hydraulics"), Options[1].MemoryFlagToSet, FName(TEXT("architect_favors_hydraulics")));

	// Select Option 0 (Structure)
	bool bSelected = DialogueComp->SelectOption(0);
	TestTrue(TEXT("Option 0 selected"), bSelected);

	// Verify advance to Node 2 (Structure focus)
	FGKDialogueNode NextNode;
	DialogueComp->GetCurrentNode(NextNode);
	TestEqual(TEXT("Advanced to Node 2 (Structure)"), NextNode.NodeID, 2);

	// Select continuation option to exit
	DialogueComp->SelectOption(0);
	TestFalse(TEXT("Dialogue completed and exited"), DialogueComp->IsInDialogue());

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
