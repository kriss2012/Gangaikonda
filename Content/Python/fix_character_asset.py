import unreal

def fix_character():
    char_bp_path = "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"
    char_bp = unreal.EditorAssetLibrary.load_asset(char_bp_path)
    if not char_bp:
        unreal.log_error(f"Could not load {char_bp_path}")
        return

    imc_path = "/Game/Input/IMC_Default.IMC_Default"
    imc_asset = unreal.EditorAssetLibrary.load_asset(imc_path)
    if not imc_asset:
        unreal.log_error(f"Could not load IMC asset {imc_path}")
        return

    gen_class = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    cdo = unreal.get_default_object(gen_class)
    cdo.set_editor_property("default_mapping_context", imc_asset)
    unreal.log("Assigned default_mapping_context to IMC_Default on CDO.")

    # Save the blueprint asset
    unreal.EditorAssetLibrary.save_loaded_asset(char_bp)
    unreal.log("Saved BP_ThirdPersonCharacter.")

fix_character()
