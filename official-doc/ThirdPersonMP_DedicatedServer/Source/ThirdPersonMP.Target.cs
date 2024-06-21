using UnrealBuildTool;
using System.Collections.Generic;

public class ThirdPersonMPTarget : TargetRules
{
	public ThirdPersonMPTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		ExtraModuleNames.Add("ThirdPersonMP");
	}
}
