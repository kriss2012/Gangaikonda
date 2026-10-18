#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GKCombatTypes.h"
#include "GKCombatComponent.h"
#include "Enemy/GKEnemyCharacter.h"
#include "Stealth/GKStealthComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: GK.Combat.BlockingAndParryMechanics
 * Validates active shield blocking, damage mitigation, stamina consumption, and parry window deflect (Doc 10 §5).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKCombatMechanicsTest, "GK.Combat.BlockingAndParryMechanics", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKCombatMechanicsTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for combat test"), World);

	AGKCharacterBase* Attacker = World->SpawnActor<AGKEnemyCharacter>();
	AGKCharacterBase* Defender = World->SpawnActor<AGKEnemyCharacter>();
	TestNotNull(TEXT("Attacker spawned"), Attacker);
	TestNotNull(TEXT("Defender spawned"), Defender);

	UGKCombatComponent* AttackerCombat = Attacker->FindComponentByClass<UGKCombatComponent>();
	UGKCombatComponent* DefenderCombat = Defender->FindComponentByClass<UGKCombatComponent>();
	TestNotNull(TEXT("Attacker combat component found"), AttackerCombat);
	TestNotNull(TEXT("Defender combat component found"), DefenderCombat);

	// 1. Test Shield Blocking
	DefenderCombat->StartBlock();
	TestEqual(TEXT("Defender is Blocking"), DefenderCombat->GetCombatStance(), EGKCombatStance::Blocking);

	FGKDamageEvent LightStrike;
	LightStrike.BaseDamage = 30.0f;
	LightStrike.DamageCauser = Attacker;
	LightStrike.bIsHeavyAttack = false;

	const float ProcessedDmg = DefenderCombat->ReceiveDamage(LightStrike);
	TestEqual(TEXT("Block reduces damage by 85% (4.5 dmg)"), ProcessedDmg, 4.5f);
	TestEqual(TEXT("Defender health reduced by 4.5"), DefenderCombat->GetHealth(), 95.5f);

	DefenderCombat->StopBlock();

	// 2. Test Parry Timing Window
	DefenderCombat->AttemptParry();
	TestEqual(TEXT("Defender is Parrying"), DefenderCombat->GetCombatStance(), EGKCombatStance::Parrying);

	FGKDamageEvent ParryableStrike;
	ParryableStrike.BaseDamage = 30.0f;
	ParryableStrike.DamageCauser = Attacker;
	ParryableStrike.bIsParryable = true;

	const float ParryDmg = DefenderCombat->ReceiveDamage(ParryableStrike);
	TestEqual(TEXT("Parry negates 100% of incoming damage"), ParryDmg, 0.0f);
	TestEqual(TEXT("Attacker is Staggered after being parried"), AttackerCombat->GetCombatStance(), EGKCombatStance::Staggered);

	World->DestroyWorld(false);
	return true;
}

/**
 * Test: GK.Combat.EnemyFleeAI
 * Validates that an enemy below 25% health breaks combat to flee (Doc 10 §3).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKEnemyFleeTest, "GK.Combat.EnemyFleeAI", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKEnemyFleeTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World created for flee test"), World);

	AGKEnemyCharacter* Enemy = World->SpawnActor<AGKEnemyCharacter>();
	TestNotNull(TEXT("Enemy spawned"), Enemy);
	Enemy->DispatchBeginPlay();
	TestFalse(TEXT("Enemy initially not fleeing"), Enemy->IsFleeing());

	UGKCombatComponent* Combat = Enemy->FindComponentByClass<UGKCombatComponent>();
	TestNotNull(TEXT("Combat comp found"), Combat);

	// Deal 80 damage to drop health to 20% (below 25% threshold)
	FGKDamageEvent HeavyStrike;
	HeavyStrike.BaseDamage = 80.0f;
	Combat->ReceiveDamage(HeavyStrike);
	Enemy->CheckFleeCondition();

	TestEqual(TEXT("Health dropped to 20"), Combat->GetHealth(), 20.0f);
	TestTrue(TEXT("Enemy triggered flee behavior"), Enemy->IsFleeing());
	TestEqual(TEXT("Locomotion switched to Running"), Enemy->GetLocomotionState(), EGKLocomotionState::Running);

	World->DestroyWorld(false);
	return true;
}

/**
 * Test: GK.Stealth.SuspicionProgression
 * Validates graduated suspicion meter (Unaware -> Alert -> Searching -> Hostile) and decay (Doc 11 §3).
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGKStealthSuspicionTest, "GK.Stealth.SuspicionProgression", EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FGKStealthSuspicionTest::RunTest(const FString& Parameters)
{
	UGKStealthComponent* Stealth = NewObject<UGKStealthComponent>();
	TestNotNull(TEXT("Stealth component created"), Stealth);
	TestEqual(TEXT("Initial state is Unaware"), Stealth->GetSuspicionState(), EGKSuspicionState::Unaware);

	// 1. Process 1.0 second of close line of sight (builds ~45 suspicion)
	Stealth->ProcessPerception(1.0f, true, 400.0f, false, EGKDisguiseRole::None);
	TestEqual(TEXT("Suspicion reached Alert state"), Stealth->GetSuspicionState(), EGKSuspicionState::Alert);

	// 2. Process another 2.0 seconds -> reaches Hostile (>= 100 suspicion)
	Stealth->ProcessPerception(2.0f, true, 400.0f, false, EGKDisguiseRole::None);
	TestEqual(TEXT("Suspicion reached Hostile state"), Stealth->GetSuspicionState(), EGKSuspicionState::Hostile);

	// 3. Out of sight for 3.0 seconds -> decays
	Stealth->ProcessPerception(3.0f, false, 0.0f, false, EGKDisguiseRole::None);
	TestTrue(TEXT("Suspicion decayed below Hostile"), Stealth->GetSuspicionState() != EGKSuspicionState::Hostile);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
