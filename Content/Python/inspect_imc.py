import unreal

def inspect_imc():
    for name in ["IMC_Default", "IMC_MouseLook"]:
        imc = unreal.EditorAssetLibrary.load_asset(f"/Game/Input/{name}")
        if not imc:
            unreal.log(f"IMC not found: {name}")
            continue
        unreal.log(f"=== {name} ({imc.get_class().get_name()}) ===")
        # Get all mappings
        mappings = imc.get_editor_property("mappings")
        unreal.log(f"Mappings count: {len(mappings)}")
        for m in mappings:
            action = m.get_editor_property("action")
            key = m.get_editor_property("key")
            act_name = action.get_name() if action else "None"
            key_name = key.get_editor_property("key_name") if key else "None"
            unreal.log(f"  Action: {act_name} -> Key: {key_name}")

inspect_imc()
