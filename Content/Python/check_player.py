import unreal

def inspect_player():
    bp_char_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    unreal.log(f"BP_ThirdPersonCharacter class loaded: {bp_char_cls}")
    
    gm_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonGameMode.BP_ThirdPersonGameMode_C")
    unreal.log(f"BP_ThirdPersonGameMode class loaded: {gm_cls}")

    level_path = "/Game/Maps/Test_Zone5_Greybox"
    subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    subsystem.load_level(level_path)

    actors = actor_subsystem.get_all_level_actors()
    unreal.log(f"Level actors count in {level_path}: {len(actors)}")
    for a in actors:
        if "ThirdPerson" in a.get_name() or "Player" in a.get_name():
            unreal.log(f"Found player-related actor: {a.get_name()} ({a.get_class().get_name()}) at {a.get_actor_location()}")
            if hasattr(a, "auto_possess_player"):
                unreal.log(f"auto_possess_player = {a.get_editor_property('auto_possess_player')}")

if __name__ == "__main__" or __name__ == "builtins":
    inspect_player()
