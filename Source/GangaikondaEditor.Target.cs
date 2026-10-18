using UnrealBuildTool;
using System.Collections.Generic;

public class GangaikondaEditorTarget : TargetRules
{
	public GangaikondaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
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
