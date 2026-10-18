using UnrealBuildTool;

public class GKCodex : ModuleRules
{
	public GKCodex(ReadOnlyTargetRules Target) : base(Target)
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
