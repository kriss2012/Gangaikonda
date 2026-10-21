import unreal

def inspect():
    world = unreal.EditorLevelLibrary.get_editor_world()
    actors = unreal.EditorLevelLibrary.get_all_level_actors()
    for a in actors:
        if "ThirdPersonCharacter" in a.get_name() or "PlayerStart" in a.get_name():
            unreal.log(f"ACTOR: {a.get_name()} class: {a.get_class().get_name()} loc: {a.get_actor_location()} rot: {a.get_actor_rotation()}")
            for c in a.get_components_by_class(unreal.SceneComponent):
                unreal.log(f"  COMP: {c.get_name()} class: {c.get_class().get_name()} rel_loc: {c.get_editor_property('relative_location')} rel_rot: {c.get_editor_property('relative_rotation')}")

inspect()
