using UnrealBuildTool;

public class GKCombat : ModuleRules
{
	public GKCombat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"GKCore",
			"GKCharacter",
			"GKExploration"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
