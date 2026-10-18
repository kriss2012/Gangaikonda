import unreal

def create_gameplay_materials():
    unreal.log("Creating Chola Historical Materials...")
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    factory = unreal.MaterialInstanceConstantFactoryNew()
    base_mat = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")
    
    colors = {
        "MI_CholaSandstone": unreal.LinearColor(0.85, 0.72, 0.52, 1.0),
        "MI_CholaWood": unreal.LinearColor(0.35, 0.20, 0.10, 1.0),
        "MI_CholaTerracotta": unreal.LinearColor(0.72, 0.38, 0.22, 1.0),
        "MI_CholaFoliage": unreal.LinearColor(0.18, 0.45, 0.16, 1.0),
        "MI_CholaGranite": unreal.LinearColor(0.48, 0.48, 0.46, 1.0),
        "MI_CholaGold": unreal.LinearColor(1.0, 0.82, 0.15, 1.0),
    }
    
    created_materials = {}
    for mat_name, col in colors.items():
        mat_path = f"/Game/Materials/{mat_name}"
        if not unreal.EditorAssetLibrary.does_asset_exist(mat_path):
            mat_inst = asset_tools.create_asset(mat_name, "/Game/Materials", unreal.MaterialInstanceConstant, factory)
            if mat_inst:
                unreal.MaterialEditingLibrary.set_material_instance_parent(mat_inst, base_mat)
                unreal.MaterialEditingLibrary.set_material_instance_vector_parameter_value(mat_inst, "Color", col)
                unreal.EditorAssetLibrary.save_asset(mat_path)
                created_materials[mat_name] = mat_inst
                unreal.log(f"Created material: {mat_name}")
        else:
            created_materials[mat_name] = unreal.EditorAssetLibrary.load_asset(mat_path)
            
    return created_materials

if __name__ == "__main__" or __name__ == "builtins":
    create_gameplay_materials()
