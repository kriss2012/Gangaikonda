using UnrealBuildTool;

public class GKWorld : ModuleRules
{
	public GKWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GKCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
