using UnrealBuildTool;
using System.Collections.Generic;

public class GangaikondaTarget : TargetRules
{
	public GangaikondaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange(new string[] {
			"GKCore",
			"GKCodex",
			"GKCharacter",
			"GKCombat",
			"GKExploration",
			"GKPuzzle",
			"GKQuest",
			"GKDialogue",
			"GKInventory",
			"GKWorld",
			"GKAI",
			"GKSave",
			"GKUI",
			"GKAudio"
		});
	}
}
