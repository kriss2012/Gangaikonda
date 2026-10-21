import unreal

def setup_imc():
    imc_path = "/Game/Input/IMC_Default"
    imc = unreal.EditorAssetLibrary.load_asset(imc_path)
    if not imc:
        unreal.log_error("Failed to load IMC_Default")
        return

    ia_move = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Move")
    ia_look = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Look")
    ia_jump = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Jump")

    # Clear existing and add fresh mappings using Enhanced Input subsystem library
    # In UE5 Python API: imc.map_key(action, key)
    try:
        # Check available methods on InputMappingContext
        unreal.log(f"IMC methods: {[m for m in dir(imc) if 'map' in m.lower()]}")
    except Exception as e:
        unreal.log(f"Error checking IMC: {e}")

setup_imc()
