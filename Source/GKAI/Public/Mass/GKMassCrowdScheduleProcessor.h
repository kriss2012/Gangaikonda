#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "GKMassCrowdFragments.h"
#include "GKMassCrowdScheduleProcessor.generated.h"

/**
 * Mass Entity processor driving daily schedule updates across hundreds of Tier 3 background crowd entities (Doc 13 §2).
 */
UCLASS()
class GKAI_API UGKMassCrowdScheduleProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UGKMassCrowdScheduleProcessor();

	/** Globally updates the time of day for Tier 3 Mass crowds */
	static void SetGlobalTimeOfDay(EGKTimeOfDay NewTime);
	static EGKTimeOfDay GetGlobalTimeOfDay() { return GlobalTimeOfDay; }

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery CrowdQuery;

private:
	static EGKTimeOfDay GlobalTimeOfDay;
};
