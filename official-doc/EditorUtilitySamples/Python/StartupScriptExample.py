import unreal
levelManager = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)

startupLevel = levelManager.load_level('/Game/BlueprintUtilities/StartupUtilityScript/LevelToLoadOnStartup')