using UnrealBuildTool;

public class GKUI : ModuleRules
{
	public GKUI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"UMG",
			"Slate",
			"SlateCore",
			"ModelViewViewModel",
			"GKCore",
			"GKCodex",
			"GKDialogue"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
