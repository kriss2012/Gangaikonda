#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKCoreTypes.h"
#include "GKLogChannels.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Core.TypeDefinitions
 * Validates fundamental evidence categories, confidence tiers, and core enums.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCoreTypesTest, "GK.Core.TypeDefinitions", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCoreTypesTest::RunTest(const FString& Parameters)
{
	// Validate Evidence Categories
	TestEqual(TEXT("Documented is enum value 0"), static_cast<uint8>(EGKEvidenceCategory::Documented), 0);
	TestEqual(TEXT("PlausibleReconstruction is enum value 1"), static_cast<uint8>(EGKEvidenceCategory::PlausibleReconstruction), 1);
	TestEqual(TEXT("Fictional is enum value 2"), static_cast<uint8>(EGKEvidenceCategory::Fictional), 2);

	// Validate Confidence Tiers
	TestEqual(TEXT("Known is enum value 0"), static_cast<uint8>(EGKConfidence::Known), 0);
	TestEqual(TEXT("Likely is enum value 1"), static_cast<uint8>(EGKConfidence::Likely), 1);
	TestEqual(TEXT("Uncertain is enum value 2"), static_cast<uint8>(EGKConfidence::Uncertain), 2);
	TestEqual(TEXT("Unknown is enum value 3"), static_cast<uint8>(EGKConfidence::Unknown), 3);

	// Validate Puzzle States
	TestEqual(TEXT("Unsolved is 0"), static_cast<uint8>(EGKPuzzleState::Unsolved), 0);
	TestEqual(TEXT("Solved is 2"), static_cast<uint8>(EGKPuzzleState::Solved), 2);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
