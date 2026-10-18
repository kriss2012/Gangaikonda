using UnrealBuildTool;

public class GKAudio : ModuleRules
{
	public GKAudio(ReadOnlyTargetRules Target) : base(Target)
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
