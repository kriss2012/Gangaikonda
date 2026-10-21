import unreal

# In standalone game mode (-game), GEditor is null so EditorAssetLibrary must not be invoked.
try:
    if unreal.is_editor():
        map_path = "/Game/Maps/Test_Zone5_Greybox"
        if hasattr(unreal, "EditorAssetLibrary") and not unreal.EditorAssetLibrary.does_asset_exist(map_path):
            unreal.log("init_unreal.py: Test_Zone5_Greybox does not exist. Auto-generating greybox arena...")
            try:
                import create_greybox
                create_greybox.build_greybox_level()
            except Exception as e:
                unreal.log_error(f"init_unreal.py error building level: {e}")
except Exception as e:
    unreal.log_warning(f"init_unreal.py non-fatal exception: {e}")

