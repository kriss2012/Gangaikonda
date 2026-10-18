using UnrealBuildTool;

public class GKCharacter : ModuleRules
{
	public GKCharacter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GKCore",
			"GKExploration"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
