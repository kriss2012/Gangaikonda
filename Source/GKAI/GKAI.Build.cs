using UnrealBuildTool;

public class GKAI : ModuleRules
{
	public GKAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"AIModule",
			"GameplayTasks",
			"MassEntity",
			"MassCore",
			"MassCommon",
			"GKCore",
			"GKCharacter"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
