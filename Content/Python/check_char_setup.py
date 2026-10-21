import unreal

def check():
    bp_char_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    cdo = unreal.get_default_object(bp_char_cls)
    unreal.log(f"CDO: {cdo}")
    for prop in ["default_mapping_context", "jump_action", "move_action", "look_action"]:
        try:
            val = cdo.get_editor_property(prop)
            unreal.log(f"  {prop}: {val}")
        except Exception as e:
            unreal.log(f"  {prop} error: {e}")

    gm_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonGameMode.BP_ThirdPersonGameMode_C")
    gm_cdo = unreal.get_default_object(gm_cls)
    unreal.log(f"GM CDO: {gm_cdo}")
    try:
        unreal.log(f"  default_pawn_class: {gm_cdo.get_editor_property('default_pawn_class')}")
    except Exception as e:
        unreal.log(f"  default_pawn_class error: {e}")

check()
