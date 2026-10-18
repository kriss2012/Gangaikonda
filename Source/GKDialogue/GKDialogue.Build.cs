using UnrealBuildTool;

public class GKDialogue : ModuleRules
{
	public GKDialogue(ReadOnlyTargetRules Target) : base(Target)
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
