using UnrealBuildTool;

public class GKQuest : ModuleRules
{
	public GKQuest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags",
			"GKCore",
			"GKCodex"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
