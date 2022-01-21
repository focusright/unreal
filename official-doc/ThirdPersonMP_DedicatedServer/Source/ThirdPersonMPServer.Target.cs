using UnrealBuildTool;
using System.Collections.Generic;

public class ThirdPersonMPServerTarget : TargetRules //Change this line according to the name of your project
{
    public ThirdPersonMPServerTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("ThirdPersonMP"); //Change this line according to the name of your project
    }
}