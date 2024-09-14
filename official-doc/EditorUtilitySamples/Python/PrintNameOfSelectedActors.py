import unreal

editorSubsystem = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)

world = editorSubsystem.get_game_world()

actors = unreal.EditorUtilityLibrary.get_selected_actors()

for asset in assets:      

   unreal.SystemLibrary.print_string(world, asset.get_full_name(), print_to_screen=True, print_to_log=True, text_color=[0.0, 0.0, 0.0, 0.0], duration=2.0)