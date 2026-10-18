using UnrealBuildTool;

public class GKExploration : ModuleRules
{
	public GKExploration(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"EnhancedInput",
			"GKCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
