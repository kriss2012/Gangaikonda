#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKAITypes.h"
#include "Schedule/GKScheduleComponent.h"
#include "Stubs/GKVSNPCSchedules.h"
#include "Mass/GKMassCrowdFragments.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.AI.ScheduleTransitions
 * Validates 4-phase daily cycle transitions (Morning -> Afternoon -> Evening -> Night) on Tier 1 named NPCs (Doc 13 §3).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKAIScheduleTest, "GK.AI.ScheduleTransitions", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKAIScheduleTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for AI schedule test"), World);

	AActor* TestNPCActor = World->SpawnActor<AActor>();
	UGKScheduleComponent* SchedComp = NewObject<UGKScheduleComponent>(TestNPCActor);

	// Setup Scholar Schedule
	FGKNPCSchedule ScholarSched = FGKVSNPCSchedules::BuildScholarSchedule();
	SchedComp->SetSchedule(ScholarSched);

	// 1. Morning check
	SchedComp->SetTimeOfDay(EGKTimeOfDay::Morning);
	TestEqual(TEXT("Morning behavior is Work"), SchedComp->GetCurrentActivity().Behavior, EGKNPCBehaviorState::Work);
	TestEqual(TEXT("Morning destination is Archive Tent"), SchedComp->GetCurrentActivity().TargetLocationTag, FName(TEXT("Tag_ArchiveTent")));

	// 2. Afternoon check
	SchedComp->SetTimeOfDay(EGKTimeOfDay::Afternoon);
	TestEqual(TEXT("Afternoon destination is Site Office"), SchedComp->GetCurrentActivity().TargetLocationTag, FName(TEXT("Tag_SiteOffice")));

	// 3. Evening check
	SchedComp->SetTimeOfDay(EGKTimeOfDay::Evening);
	TestEqual(TEXT("Evening behavior is Socialize"), SchedComp->GetCurrentActivity().Behavior, EGKNPCBehaviorState::Socialize);
	TestEqual(TEXT("Evening destination is Overlook Vista"), SchedComp->GetCurrentActivity().TargetLocationTag, FName(TEXT("Tag_OverlookVista")));

	// 4. Night check
	SchedComp->SetTimeOfDay(EGKTimeOfDay::Night);
	TestEqual(TEXT("Night destination is Inner Archive"), SchedComp->GetCurrentActivity().TargetLocationTag, FName(TEXT("Tag_ArchiveTent_Inner")));

	World->DestroyWorld(false);
	return true;
}

/**
 * Test: GK.AI.CrowdMemoryProfile
 * Asserts Mass Entity Tier 3 fragment memory budget to guarantee living-world performance target (Doc 13 §2).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKMCMemoryProfileTest, "GK.AI.CrowdMemoryProfile", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKMCMemoryProfileTest::RunTest(const FString& Parameters)
{
	const size_t FragmentSize = sizeof(FGKCrowdMemberFragment);
	TestTrue(TEXT("FGKCrowdMemberFragment must be <= 64 bytes"), FragmentSize <= 64);

	// Estimate RAM for 1,000 Mass Entity crowd workers in Zone 5
	const size_t TotalRam1000Entities = FragmentSize * 1000;
	TestTrue(TEXT("1000 background entities must consume <= 64 KB of fragment data"), TotalRam1000Entities <= (64 * 1024));

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
