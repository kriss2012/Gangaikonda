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
			"GKCore",
			"GKCodex",
			"GKQuest",
			"GKWorld",
			"GKCharacter",
			"GKPuzzle",
			"GKCombat"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
