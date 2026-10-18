using UnrealBuildTool;

public class GKPuzzle : ModuleRules
{
	public GKPuzzle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GKCore",
			"GKCodex"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
