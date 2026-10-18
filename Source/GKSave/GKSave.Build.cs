using UnrealBuildTool;

public class GKSave : ModuleRules
{
	public GKSave(ReadOnlyTargetRules Target) : base(Target)
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
