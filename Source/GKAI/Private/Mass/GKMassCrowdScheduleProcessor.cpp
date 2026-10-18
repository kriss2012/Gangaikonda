#include "Mass/GKMassCrowdScheduleProcessor.h"
#include "MassExecutionContext.h"
#include "GKLogChannels.h"

EGKTimeOfDay UGKMassCrowdScheduleProcessor::GlobalTimeOfDay = EGKTimeOfDay::Morning;

UGKMassCrowdScheduleProcessor::UGKMassCrowdScheduleProcessor()
	: CrowdQuery(*this)
{
	bAutoRegisterWithProcessingPhases = true;
	ProcessingPhase = EMassProcessingPhase::PrePhysics;
}

void UGKMassCrowdScheduleProcessor::SetGlobalTimeOfDay(EGKTimeOfDay NewTime)
{
	GlobalTimeOfDay = NewTime;
}

void UGKMassCrowdScheduleProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	CrowdQuery.AddRequirement<FGKCrowdMemberFragment>(EMassFragmentAccess::ReadWrite);
}

void UGKMassCrowdScheduleProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	CrowdQuery.ForEachEntityChunk(Context, [this](FMassExecutionContext& ChunkContext)
	{
		const int32 NumEntities = ChunkContext.GetNumEntities();
		const TArrayView<FGKCrowdMemberFragment> CrowdFragments = ChunkContext.GetMutableFragmentView<FGKCrowdMemberFragment>();

		for (int32 i = 0; i < NumEntities; ++i)
		{
			FGKCrowdMemberFragment& Fragment = CrowdFragments[i];

			if (Fragment.CurrentTimeOfDay != GlobalTimeOfDay)
			{
				Fragment.CurrentTimeOfDay = GlobalTimeOfDay;

				// Update background behavior according to time of day
				switch (GlobalTimeOfDay)
				{
				case EGKTimeOfDay::Morning:
					// Travel from settlement to temple construction zone
					Fragment.CurrentBehavior = EGKNPCBehaviorState::Travel;
					Fragment.MovementSpeed = 200.0f;
					break;
				case EGKTimeOfDay::Afternoon:
					// Peak physical labor (hewing stone, carrying mortar)
					Fragment.CurrentBehavior = EGKNPCBehaviorState::Work;
					Fragment.MovementSpeed = 140.0f;
					break;
				case EGKTimeOfDay::Evening:
					// Return to worker mess / settlement social area
					Fragment.CurrentBehavior = EGKNPCBehaviorState::Socialize;
					Fragment.MovementSpeed = 160.0f;
					break;
				case EGKTimeOfDay::Night:
				default:
					// Crowd population sleeps / thins out
					Fragment.CurrentBehavior = EGKNPCBehaviorState::Sleep;
					Fragment.MovementSpeed = 0.0f;
					break;
				}
			}
		}
	});
}
