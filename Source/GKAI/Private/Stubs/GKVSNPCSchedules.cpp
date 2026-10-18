#include "Stubs/GKVSNPCSchedules.h"

#define LOCTEXT_NAMESPACE "GKVSNPCSchedules"

FGKNPCSchedule FGKVSNPCSchedules::BuildScholarSchedule()
{
	FGKNPCSchedule Sched;
	Sched.NPCID = FName(TEXT("NPC_Scholar"));
	Sched.PopulationTier = EGKPopulationTier::Tier1_Named;

	// Morning
	FGKScheduleActivity Morning;
	Morning.TimeOfDay = EGKTimeOfDay::Morning;
	Morning.Behavior = EGKNPCBehaviorState::Work;
	Morning.TargetLocationTag = FName(TEXT("Tag_ArchiveTent"));
	Morning.ActivityBark = LOCTEXT("ScholarMornBark", "The morning light is cleanest for reading fragile palm-leaf records.");
	Sched.Activities.Add(Morning);

	// Afternoon
	FGKScheduleActivity Afternoon;
	Afternoon.TimeOfDay = EGKTimeOfDay::Afternoon;
	Afternoon.Behavior = EGKNPCBehaviorState::Work;
	Afternoon.TargetLocationTag = FName(TEXT("Tag_SiteOffice"));
	Afternoon.ActivityBark = LOCTEXT("ScholarAfterBark", "Compare these foundation block squeezes against the Tiruvalangadu plates.");
	Sched.Activities.Add(Afternoon);

	// Evening
	FGKScheduleActivity Evening;
	Evening.TimeOfDay = EGKTimeOfDay::Evening;
	Evening.Behavior = EGKNPCBehaviorState::Socialize;
	Evening.TargetLocationTag = FName(TEXT("Tag_OverlookVista"));
	Evening.ActivityBark = LOCTEXT("ScholarEveBark", "The vimana rises another stone course with every passing week.");
	Sched.Activities.Add(Evening);

	// Night
	FGKScheduleActivity Night;
	Night.TimeOfDay = EGKTimeOfDay::Night;
	Night.Behavior = EGKNPCBehaviorState::Work;
	Night.TargetLocationTag = FName(TEXT("Tag_ArchiveTent_Inner"));
	Night.ActivityBark = LOCTEXT("ScholarNightBark", "These shipment registers contain an unmistakable contradiction...");
	Sched.Activities.Add(Night);

	return Sched;
}

FGKNPCSchedule FGKVSNPCSchedules::BuildArchitectSchedule()
{
	FGKNPCSchedule Sched;
	Sched.NPCID = FName(TEXT("NPC_Architect"));
	Sched.PopulationTier = EGKPopulationTier::Tier1_Named;

	// Morning
	FGKScheduleActivity Morning;
	Morning.TimeOfDay = EGKTimeOfDay::Morning;
	Morning.Behavior = EGKNPCBehaviorState::Work;
	Morning.TargetLocationTag = FName(TEXT("Tag_StagingPlaza"));
	Morning.ActivityBark = LOCTEXT("ArchMornBark", "Every granite block must be dressed true to the plumb-line before hoisting.");
	Sched.Activities.Add(Morning);

	// Afternoon
	FGKScheduleActivity Afternoon;
	Afternoon.TimeOfDay = EGKTimeOfDay::Afternoon;
	Afternoon.Behavior = EGKNPCBehaviorState::Work;
	Afternoon.TargetLocationTag = FName(TEXT("Tag_VimanaScaffoldBase"));
	Afternoon.ActivityBark = LOCTEXT("ArchAfterBark", "Steady on the hemp cables! Keep the four corner mortises aligned!");
	Sched.Activities.Add(Afternoon);

	// Evening
	FGKScheduleActivity Evening;
	Evening.TimeOfDay = EGKTimeOfDay::Evening;
	Evening.Behavior = EGKNPCBehaviorState::Work;
	Evening.TargetLocationTag = FName(TEXT("Tag_PlanningPavilion"));
	Evening.ActivityBark = LOCTEXT("ArchEveBark", "The fall from Cholagangam reservoir must preserve steady water pressure.");
	Sched.Activities.Add(Evening);

	// Night
	FGKScheduleActivity Night;
	Night.TimeOfDay = EGKTimeOfDay::Night;
	Night.Behavior = EGKNPCBehaviorState::Sleep;
	Night.TargetLocationTag = FName(TEXT("Tag_ArchitectQuarters"));
	Night.ActivityBark = LOCTEXT("ArchNightBark", "Rest now, while the stone rests.");
	Sched.Activities.Add(Night);

	return Sched;
}

FGKNPCSchedule FGKVSNPCSchedules::BuildQuarryWorkerSchedule()
{
	FGKNPCSchedule Sched;
	Sched.NPCID = FName(TEXT("NPC_QuarryForeman"));
	Sched.PopulationTier = EGKPopulationTier::Tier2_SemiNamed;

	FGKScheduleActivity Morning;
	Morning.TimeOfDay = EGKTimeOfDay::Morning;
	Morning.Behavior = EGKNPCBehaviorState::Travel;
	Morning.TargetLocationTag = FName(TEXT("Tag_QuarryRoad"));
	Morning.ActivityBark = LOCTEXT("WorkerMornBark", "Roll the timber sledges! The oxen are ready.");
	Sched.Activities.Add(Morning);

	FGKScheduleActivity Afternoon;
	Afternoon.TimeOfDay = EGKTimeOfDay::Afternoon;
	Afternoon.Behavior = EGKNPCBehaviorState::Work;
	Afternoon.TargetLocationTag = FName(TEXT("Tag_DressingPit"));
	Afternoon.ActivityBark = LOCTEXT("WorkerAfterBark", "Chisel the top facet flat; the master sthapati checks each one.");
	Sched.Activities.Add(Afternoon);

	FGKScheduleActivity Evening;
	Evening.TimeOfDay = EGKTimeOfDay::Evening;
	Evening.Behavior = EGKNPCBehaviorState::Eat;
	Evening.TargetLocationTag = FName(TEXT("Tag_WorkerMess"));
	Evening.ActivityBark = LOCTEXT("WorkerEveBark", "Rice and lentils after twelve hours on the granite face.");
	Sched.Activities.Add(Evening);

	FGKScheduleActivity Night;
	Night.TimeOfDay = EGKTimeOfDay::Night;
	Night.Behavior = EGKNPCBehaviorState::Sleep;
	Night.TargetLocationTag = FName(TEXT("Tag_WorkerBarracks"));
	Night.ActivityBark = LOCTEXT("WorkerNightBark", "Zzz...");
	Sched.Activities.Add(Night);

	return Sched;
}

#undef LOCTEXT_NAMESPACE
