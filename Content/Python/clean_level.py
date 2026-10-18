import unreal

def clean_and_fix_level():
    unreal.log("=== CLEANING LEVEL: REMOVING DUPLICATE DIRECTIONAL LIGHTS ===")
    level_path = "/Game/Maps/Test_Zone5_Greybox"
    
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    
    level_editor_subsystem.load_level(level_path)
    
    actors = editor_actor_subsystem.get_all_level_actors()
    deleted_count = 0
    for actor in actors:
        if actor and actor.get_class().get_name() == "DirectionalLight":
            unreal.log(f"Deleting duplicate DirectionalLight: {actor.get_actor_label()}")
            editor_actor_subsystem.destroy_actor(actor)
            deleted_count += 1
            
    unreal.log(f"Deleted {deleted_count} duplicate directional light(s).")
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== LEVEL SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    clean_and_fix_level()
