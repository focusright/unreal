:: Copyright Epic Games, Inc. All Rights Reserved

:: Instructions: Update the following paths to point to your UE executable and uproject file
SET UE5_PATH="C:\Program Files\Epic Games\UE_5.4\Engine\Binaries\Win64"
SET PROJECT=%~dp0EditorUtilitySamples.uproject

%UE5_PATH%\UnrealEditor-Cmd.exe %PROJECT% -nosplash -nocontentbrowser -nopause -Unattended -NullRHI Log=HeadlessExample.log -ini:EditorPerProjectUserSettings:[/Script/Blutility.EditorUtilitySubsystem]:StartupObjects=/Game/BlueprintUtilities/StartupUtilityScript/EUO_HeadlessStartupScript.EUO_HeadlessStartupScript

PAUSE