#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GKAITypes.h"
#include "GKScheduleComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGKScheduleActivityChanged, EGKTimeOfDay, TimeOfDay, const FGKScheduleActivity&, Activity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGKPlayerReactionTriggered, AActor*, PlayerActor);

/**
 * Schedule driver component attached to Tier 1 and Tier 2 NPCs (Doc 13 §1 & §3, Doc 18 §2).
 * Drives the 4-phase daily cycle (Morning/Afternoon/Evening/Night) and player proximity reactions.
 */
UCLASS(ClassGroup = (GK), meta = (BlueprintSpawnableComponent))
class GKAI_API UGKScheduleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGKScheduleComponent();

	/** Assigns or updates the daily schedule */
	UFUNCTION(BlueprintCallable, Category = "GK|Schedule")
	void SetSchedule(const FGKNPCSchedule& InSchedule);

	/** Advances or sets the global time of day, re-evaluating active workstation and behavior */
	UFUNCTION(BlueprintCallable, Category = "GK|Schedule")
	void SetTimeOfDay(EGKTimeOfDay NewTimeOfDay);

	/** Triggers contextual reaction when Arulan approaches (greeting bark or suspicion) */
	UFUNCTION(BlueprintCallable, Category = "GK|Schedule")
	void ReactToPlayer(AActor* PlayerActor);

	/** Current time of day */
	UFUNCTION(BlueprintPure, Category = "GK|Schedule")
	EGKTimeOfDay GetCurrentTimeOfDay() const { return CurrentTimeOfDay; }

	/** Currently active scheduled activity */
	UFUNCTION(BlueprintPure, Category = "GK|Schedule")
	const FGKScheduleActivity& GetCurrentActivity() const { return CurrentActivity; }

	/** Returns current ambient bark text */
	UFUNCTION(BlueprintPure, Category = "GK|Schedule")
	FText GetActiveActivityBark() const { return CurrentActivity.ActivityBark; }

	UPROPERTY(BlueprintAssignable, Category = "GK|Schedule")
	FOnGKScheduleActivityChanged OnActivityChanged;

	UPROPERTY(BlueprintAssignable, Category = "GK|Schedule")
	FOnGKPlayerReactionTriggered OnPlayerReactionTriggered;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Schedule")
	FGKNPCSchedule AssignedSchedule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Schedule")
	EGKTimeOfDay CurrentTimeOfDay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GK|Schedule")
	FGKScheduleActivity CurrentActivity;

	/** Timer handle restoring normal schedule following a player reaction */
	FTimerHandle ReactionRestoreTimerHandle;

private:
	void ExecuteActivityTransition();
	void EndPlayerReaction();
};
