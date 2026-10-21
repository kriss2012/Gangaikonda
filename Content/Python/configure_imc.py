import unreal

def configure_imc_default():
    imc = unreal.EditorAssetLibrary.load_asset("/Game/Input/IMC_Default")
    if not imc:
        unreal.log_error("Could not load IMC_Default")
        return

    ia_move = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Move")
    ia_look = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Look")
    ia_jump = unreal.EditorAssetLibrary.load_asset("/Game/Input/Actions/IA_Jump")

    # Clear old mappings
    imc.unmap_all()

    # 1. IA_Jump -> Space Bar
    m_jump = imc.map_key(ia_jump, unreal.Key("SpaceBar"))
    unreal.log("Mapped IA_Jump to SpaceBar")

    # 2. IA_Look -> Mouse XY 2D-Axis and Mouse X, Mouse Y
    m_look = imc.map_key(ia_look, unreal.Key("Mouse2D"))
    # In UE5, Mouse Y usually needs Negate on Pitch
    negate_mod = unreal.InputModifierNegate()
    m_look.set_editor_property("modifiers", [negate_mod])
    unreal.log("Mapped IA_Look to Mouse2D with Negate modifier")

    # Also map MouseX and MouseY individually as fallback
    m_mx = imc.map_key(ia_look, unreal.Key("MouseX"))
    m_my = imc.map_key(ia_look, unreal.Key("MouseY"))
    swizzle = unreal.InputModifierSwizzleAxis()
    swizzle.set_editor_property("order", unreal.InputAxisSwizzle.YXZ)
    m_my.set_editor_property("modifiers", [swizzle, negate_mod])

    # 3. IA_Move -> W, S, A, D
    # W: Forward (+Y in 2D input) -> Swizzle to Y
    m_w = imc.map_key(ia_move, unreal.Key("W"))
    swizzle_y = unreal.InputModifierSwizzleAxis()
    swizzle_y.set_editor_property("order", unreal.InputAxisSwizzle.YXZ)
    m_w.set_editor_property("modifiers", [swizzle_y])

    # S: Backward (-Y in 2D input) -> Swizzle to Y, Negate
    m_s = imc.map_key(ia_move, unreal.Key("S"))
    m_s.set_editor_property("modifiers", [swizzle_y, negate_mod])

    # D: Right (+X in 2D input)
    m_d = imc.map_key(ia_move, unreal.Key("D"))

    # A: Left (-X in 2D input) -> Negate
    m_a = imc.map_key(ia_move, unreal.Key("A"))
    m_a.set_editor_property("modifiers", [negate_mod])

    unreal.log("Mapped IA_Move to W, S, A, D")

    # Save asset
    saved = unreal.EditorAssetLibrary.save_loaded_asset(imc)
    unreal.log(f"=== IMC_DEFAULT CONFIGURED AND SAVED: {saved} ===")

configure_imc_default()
