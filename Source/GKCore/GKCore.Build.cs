using UnrealBuildTool;

public class GKCore : ModuleRules
{
	public GKCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags",
			"EnhancedInput"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
