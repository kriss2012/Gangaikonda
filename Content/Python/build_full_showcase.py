import unreal

def build_full_showcase():
    unreal.log("==================================================================")
    unreal.log("BUILDING COMPLETE LIVING GAME SHOWCASE — GANGAIKONDA ZONE 5")
    unreal.log("==================================================================")

    level_path = "/Game/Maps/Test_Zone5_Greybox"
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

    level_editor_subsystem.load_level(level_path)

    # 1. Clean up old geometry and static text
    all_actors = editor_actor_subsystem.get_all_level_actors()
    keep_classes = [
        "GKLightingManagerActor", "GKLionWellPuzzleActor", 
        "GKStoneAlignmentPuzzleActor", "SkyAtmosphere", "SkyLight", "ExponentialHeightFog"
    ]
    for act in all_actors:
        if act:
            class_name = act.get_class().get_name()
            if not any(k in class_name for k in keep_classes):
                editor_actor_subsystem.destroy_actor(act)

    unreal.log("Cleared old level geometry.")

    # 2. Create / Load Textured Materials
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    mic_factory = unreal.MaterialInstanceConstantFactoryNew()
    base_mat = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")

    material_defs = {
        "M_Sandstone": unreal.LinearColor(0.82, 0.68, 0.48, 1.0),   # Warm Chola golden granite/sandstone
        "M_Timber": unreal.LinearColor(0.32, 0.18, 0.08, 1.0),      # Dark scaffolding wood
        "M_Terracotta": unreal.LinearColor(0.68, 0.32, 0.18, 1.0),  # Red earth construction ground
        "M_GraniteDark": unreal.LinearColor(0.42, 0.42, 0.40, 1.0), # Carved plinth stone
        "M_Cloth": unreal.LinearColor(0.88, 0.78, 0.58, 1.0),       # Pavilion tent canopy
        "M_Gold": unreal.LinearColor(1.0, 0.80, 0.10, 1.0),         # Finials & golden evidence
        "M_Foliage": unreal.LinearColor(0.18, 0.42, 0.14, 1.0),     # Palm fronds
    }

    materials = {}
    for mat_name, col in material_defs.items():
        mat_path = f"/Game/Materials/{mat_name}"
        mat_obj = unreal.EditorAssetLibrary.load_asset(mat_path)
        if not mat_obj:
            mat_obj = asset_tools.create_asset(mat_name, "/Game/Materials", unreal.MaterialInstanceConstant, mic_factory)
            if mat_obj:
                unreal.MaterialEditingLibrary.set_material_instance_parent(mat_obj, base_mat)
                unreal.MaterialEditingLibrary.set_material_instance_vector_parameter_value(mat_obj, "Color", col)
                unreal.EditorAssetLibrary.save_asset(mat_path)
        materials[mat_name] = mat_obj

    unreal.log("Loaded all architectural materials.")

    # 3. Meshes & Animations
    cube_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    cylinder_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
    cone_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cone.Cone")
    sphere_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Sphere.Sphere")
    manny_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple")
    quinn_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple")

    anim_idle = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/MM_Idle.MM_Idle")
    anim_walk = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/Walk/MF_Unarmed_Walk_Fwd.MF_Unarmed_Walk_Fwd")
    anim_jog = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/Jog/MF_Unarmed_Jog_Fwd.MF_Unarmed_Jog_Fwd")
    anim_work = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/Attack/MM_Attack_01.MM_Attack_01")

    # Helper function for static meshes with materials
    def spawn_mesh(label, loc, rot, scale, mesh=cube_mesh, mat=None):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.StaticMeshActor, loc)
        if actor:
            actor.set_actor_label(label)
            actor.set_actor_rotation(rot, False)
            if mesh:
                actor.static_mesh_component.set_static_mesh(mesh)
            if mat:
                actor.static_mesh_component.set_material(0, mat)
            actor.set_actor_scale3d(scale)
        return actor

    # Helper function for animated living NPCs
    def spawn_animated_npc(label, loc, rot, mesh=manny_mesh, anim=anim_idle):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.SkeletalMeshActor, loc)
        if actor:
            actor.set_actor_label(label)
            actor.set_actor_rotation(rot, False)
            comp = actor.skeletal_mesh_component
            if comp and mesh:
                comp.set_skeletal_mesh_asset(mesh)
                if anim:
                    comp.set_animation_mode(unreal.AnimationMode.ANIMATION_SINGLE_NODE)
                    comp.set_animation(anim)
                    comp.play(True)
            actor.set_actor_scale3d(unreal.Vector(1.0, 1.0, 1.0))
        return actor

    # =========================================================================
    # A. GROUND: RED EARTH CONSTRUCTION TERRAIN (150m x 150m)
    # =========================================================================
    spawn_mesh("Terrain_RedEarth", unreal.Vector(0.0, 800.0, -50.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(180.0, 180.0, 1.0), cube_mesh, materials["M_Terracotta"])

    # Processional stone pathway from Gate to Temple
    spawn_mesh("Road_StoneProcessional", unreal.Vector(0.0, 200.0, -40.0), unreal.Rotator(0, 0, 0),
               unreal.Vector(8.0, 24.0, 1.1), cube_mesh, materials["M_GraniteDark"])

    # =========================================================================
    # B. THE BRIHADISVARA TEMPLE VIMANA (UNDER ACTIVE CONSTRUCTION)
    # =========================================================================
    vx, vy = 0.0, 2000.0

    # Adhisthana Plinth Base (Dark Granite)
    spawn_mesh("Vimana_Plinth", unreal.Vector(vx, vy, 100.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(28.0, 28.0, 2.0), cube_mesh, materials["M_GraniteDark"])

    # Tier 1 Course (Finished Golden Sandstone)
    spawn_mesh("Vimana_Tier1", unreal.Vector(vx, vy, 350.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(24.0, 24.0, 3.0), cube_mesh, materials["M_Sandstone"])

    # Tier 2 Course (Finished with Kudus / Niches)
    spawn_mesh("Vimana_Tier2", unreal.Vector(vx, vy, 700.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(20.0, 20.0, 4.0), cube_mesh, materials["M_Sandstone"])

    # Tier 3 Staging Platform (Where ramp lands)
    spawn_mesh("Vimana_Tier3_StagingPlatform", unreal.Vector(vx, vy, 1150.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(16.0, 16.0, 5.0), cube_mesh, materials["M_Sandstone"])

    # Unfinished Upper Courses (Tier 4 & 5 - raw rough-cut stone)
    spawn_mesh("Vimana_Tier4_Unfinished", unreal.Vector(vx, vy, 1550.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(12.0, 12.0, 3.0), cube_mesh, materials["M_GraniteDark"])

    # Sanctum Entrance Lintel & Pillars (Mukhamandapa)
    spawn_mesh("Sanctum_Lintel", unreal.Vector(vx, vy - 1200.0, 420.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(8.0, 1.5, 1.2), cube_mesh, materials["M_GraniteDark"])
    spawn_mesh("Sanctum_Pillar_L", unreal.Vector(vx - 320.0, vy - 1200.0, 210.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(0.8, 0.8, 4.2), cylinder_mesh, materials["M_GraniteDark"])
    spawn_mesh("Sanctum_Pillar_R", unreal.Vector(vx + 320.0, vy - 1200.0, 210.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(0.8, 0.8, 4.2), cylinder_mesh, materials["M_GraniteDark"])

    # =========================================================================
    # C. MASSIVE TIMBER SCAFFOLDING SUPERSTRUCTURE (Upper courses)
    # =========================================================================
    scaff_z = 1700.0
    sw = 500.0
    sh = 1000.0

    # 4 Vertical Timber Tower Columns (Dark wood)
    for idx, (cx, cy) in enumerate([(-sw, -sw), (sw, -sw), (-sw, sw), (sw, sw)]):
        spawn_mesh(f"Scaffolding_TowerPost_{idx+1}", unreal.Vector(vx + cx, vy + cy, scaff_z + (sh / 2.0)), 
                   unreal.Rotator(0, 0, 0), unreal.Vector(0.35, 0.35, sh / 100.0), cylinder_mesh, materials["M_Timber"])

    # Scaffolding Horizontal Timber Ledgers (3 tiers)
    for t in range(3):
        lz = scaff_z + (t * 320.0)
        spawn_mesh(f"Scaff_Ledger_F_{t}", unreal.Vector(vx, vy - sw, lz), unreal.Rotator(0, 0, 0), unreal.Vector(10.5, 0.2, 0.2), cube_mesh, materials["M_Timber"])
        spawn_mesh(f"Scaff_Ledger_B_{t}", unreal.Vector(vx, vy + sw, lz), unreal.Rotator(0, 0, 0), unreal.Vector(10.5, 0.2, 0.2), cube_mesh, materials["M_Timber"])
        spawn_mesh(f"Scaff_Ledger_L_{t}", unreal.Vector(vx - sw, vy, lz), unreal.Rotator(0, 90, 0), unreal.Vector(10.5, 0.2, 0.2), cube_mesh, materials["M_Timber"])
        spawn_mesh(f"Scaff_Ledger_R_{t}", unreal.Vector(vx + sw, vy, lz), unreal.Rotator(0, 90, 0), unreal.Vector(10.5, 0.2, 0.2), cube_mesh, materials["M_Timber"])

    # Timber Diagonal Cross-Bracing
    spawn_mesh("Scaff_Cross1", unreal.Vector(vx, vy - sw, scaff_z + 300.0), unreal.Rotator(32, 0, 0), unreal.Vector(0.18, 0.18, 12.0), cylinder_mesh, materials["M_Timber"])
    spawn_mesh("Scaff_Cross2", unreal.Vector(vx, vy - sw, scaff_z + 300.0), unreal.Rotator(-32, 0, 0), unreal.Vector(0.18, 0.18, 12.0), cylinder_mesh, materials["M_Timber"])
    spawn_mesh("Scaff_Cross3", unreal.Vector(vx, vy - sw, scaff_z + 750.0), unreal.Rotator(32, 0, 0), unreal.Vector(0.18, 0.18, 12.0), cylinder_mesh, materials["M_Timber"])
    spawn_mesh("Scaff_Cross4", unreal.Vector(vx, vy - sw, scaff_z + 750.0), unreal.Rotator(-32, 0, 0), unreal.Vector(0.18, 0.18, 12.0), cylinder_mesh, materials["M_Timber"])

    # =========================================================================
    # D. INCLINED TIMBER & STONE CONSTRUCTION RAMP
    # =========================================================================
    # Connects ground to Tier 3 platform (Z = 1150)
    rx_start, ry_start = -1800.0, 400.0
    rx_end, ry_end = -850.0, 2000.0
    rc_x = (rx_start + rx_end) / 2.0
    rc_y = (ry_start + ry_end) / 2.0
    rc_z = 580.0

    # Solid Ramp Roadway Deck (Timber surface)
    spawn_mesh("Construction_Ramp_Roadway", unreal.Vector(rc_x, rc_y, rc_z), unreal.Rotator(28, 59, 0), 
               unreal.Vector(20.5, 3.5, 0.6), cube_mesh, materials["M_Timber"])

    # Timber Trestle Support Poles under the ramp
    for p in range(6):
        pct = p / 5.0
        px = rx_start + (pct * (rx_end - rx_start))
        py = ry_start + (pct * (ry_end - ry_start))
        ph = 60.0 + (pct * 1050.0)
        pz = ph / 2.0
        spawn_mesh(f"Ramp_Trestle_L_{p}", unreal.Vector(px - 90.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, ph / 100.0), cylinder_mesh, materials["M_Timber"])
        spawn_mesh(f"Ramp_Trestle_R_{p}", unreal.Vector(px + 90.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, ph / 100.0), cylinder_mesh, materials["M_Timber"])
        spawn_mesh(f"Ramp_Trestle_Beam_{p}", unreal.Vector(px, py, ph), unreal.Rotator(0, 59, 0), unreal.Vector(2.8, 0.3, 0.3), cube_mesh, materials["M_Timber"])

    # =========================================================================
    # E. LIVING, ANIMATED NPCS (AUTOMATED WORKERS & CAST)
    # =========================================================================
    # 1. The Chief Architect: Idle breathing animation atop the ramp surveying the construction!
    arch_loc = unreal.Vector(rx_end + 30.0, ry_end - 40.0, 1160.0)
    spawn_animated_npc("NPC_ChiefArchitect", arch_loc, unreal.Rotator(0, -120, 0), quinn_mesh, anim_idle)
    spawn_mesh("Architect_DraftingDesk", unreal.Vector(arch_loc.x + 70.0, arch_loc.y, arch_loc.z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.4, 0.8, 0.8), cube_mesh, materials["M_Timber"])

    # 2. Worker 1 on Ramp: Animated walking with granite head-load!
    w1_loc = unreal.Vector(rx_start + 0.25 * (rx_end - rx_start), ry_start + 0.25 * (ry_end - ry_start), 320.0)
    spawn_animated_npc("NPC_Worker_Ramp_1", w1_loc, unreal.Rotator(0, 59, 0), manny_mesh, anim_walk)
    spawn_mesh("Stone_Headload_1", unreal.Vector(w1_loc.x, w1_loc.y, w1_loc.z + 185.0), unreal.Rotator(0, 59, 0), 
               unreal.Vector(0.45, 0.45, 0.3), cube_mesh, materials["M_Sandstone"])

    # 3. Worker 2 on Ramp: Animated walking higher up the incline!
    w2_loc = unreal.Vector(rx_start + 0.65 * (rx_end - rx_start), ry_start + 0.65 * (ry_end - ry_start), 780.0)
    spawn_animated_npc("NPC_Worker_Ramp_2", w2_loc, unreal.Rotator(0, 59, 0), manny_mesh, anim_walk)
    spawn_mesh("Stone_Headload_2", unreal.Vector(w2_loc.x, w2_loc.y, w2_loc.z + 185.0), unreal.Rotator(0, 59, 0), 
               unreal.Vector(0.45, 0.45, 0.3), cube_mesh, materials["M_Sandstone"])

    # 4. Stone Mason 1 at Ground Yard: Animated chiseling stone (Attack/strike loop)!
    spawn_animated_npc("NPC_StoneMason_Active1", unreal.Vector(-1500.0, 300.0, 0.0), unreal.Rotator(0, 45, 0), manny_mesh, anim_work)
    spawn_mesh("Stone_ChiselingBlock_1", unreal.Vector(-1460.0, 340.0, 35.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.0, 1.0, 0.7), cube_mesh, materials["M_Sandstone"])

    # 5. Stone Mason 2 at Worktable: Idle breathing inspection!
    spawn_animated_npc("NPC_StoneMason_Active2", unreal.Vector(-1300.0, 350.0, 0.0), unreal.Rotator(0, -90, 0), manny_mesh, anim_idle)

    # 6. Royal Epigraphist Scholar: Idle at archive pavilion!
    tent_x, tent_y = 1000.0, -200.0
    spawn_animated_npc("NPC_RoyalEpigraphist", unreal.Vector(tent_x, tent_y - 60.0, 0.0), unreal.Rotator(0, 90, 0), quinn_mesh, anim_idle)

    # 7. Ambush Soldier (Hostile Enemy at Gate): Combat ready!
    spawn_animated_npc("NPC_AmbushGuard", unreal.Vector(0.0, 400.0, 0.0), unreal.Rotator(0, -90, 0), manny_mesh, anim_idle)

    # =========================================================================
    # F. STONE CUTTER YARDS: DRESSED GRANITE STACKS & HEAVY SLEDGE
    # =========================================================================
    # Stacked dressed granite blocks (Golden sandstone)
    yard_x, yard_y = -1500.0, 100.0
    for r in range(2):
        for c in range(3):
            spawn_mesh(f"Granite_Block_{r}_{c}", unreal.Vector(yard_x + (c * 150.0), yard_y + (r * 150.0), 45.0),
                       unreal.Rotator(0, (r * 12), 0), unreal.Vector(1.3, 1.3, 0.9), cube_mesh, materials["M_Sandstone"])

    # Heavy Stone-Hauling Wooden Sledge
    sledge_x, sledge_y = -1100.0, -100.0
    spawn_mesh("Hauler_Sledge_Runner_L", unreal.Vector(sledge_x - 80.0, sledge_y, 25.0), unreal.Rotator(0, 30, 0), unreal.Vector(4.0, 0.3, 0.5), cube_mesh, materials["M_Timber"])
    spawn_mesh("Hauler_Sledge_Runner_R", unreal.Vector(sledge_x + 80.0, sledge_y, 25.0), unreal.Rotator(0, 30, 0), unreal.Vector(4.0, 0.3, 0.5), cube_mesh, materials["M_Timber"])
    spawn_mesh("Hauler_Sledge_Crossdeck", unreal.Vector(sledge_x, sledge_y, 40.0), unreal.Rotator(0, 30, 0), unreal.Vector(3.8, 1.8, 0.3), cube_mesh, materials["M_Timber"])
    # Giant monolithic stone on sledge
    spawn_mesh("Hauler_Monolith_Stone", unreal.Vector(sledge_x, sledge_y, 110.0), unreal.Rotator(0, 30, 0), unreal.Vector(3.2, 1.4, 1.2), cube_mesh, materials["M_GraniteDark"])

    # =========================================================================
    # G. ROYAL SCHOLAR ARCHIVE TENT & INSCRIPTION RUBBING SLAB
    # =========================================================================
    # Terracotta fabric canopy
    spawn_mesh("Scholar_Tent_Canopy", unreal.Vector(tent_x, tent_y, 230.0), unreal.Rotator(0, 45, 0), 
               unreal.Vector(4.8, 4.8, 1.0), cone_mesh, materials["M_Cloth"])
    # 4 Timber Posts
    for px, py in [(-160, -160), (160, -160), (-160, 160), (160, 160)]:
        spawn_mesh(f"Scholar_Tent_Post_{px}", unreal.Vector(tent_x + px, tent_y + py, 100.0), unreal.Rotator(0, 0, 0),
                   unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh, materials["M_Timber"])
    # Scribe Table
    spawn_mesh("Scholar_Desk", unreal.Vector(tent_x, tent_y, 45.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.8, 1.0, 0.8), cube_mesh, materials["M_Timber"])
    # Inscribed Stone Slab with gold border
    spawn_mesh("P10_Inscription_StoneSlab", unreal.Vector(tent_x, tent_y + 80.0, 65.0), unreal.Rotator(15, 0, 0), 
               unreal.Vector(1.2, 0.15, 1.0), cube_mesh, materials["M_Gold"])

    # =========================================================================
    # H. LION WELL HYDRAULIC STEPWELL (P04 PUZZLE)
    # =========================================================================
    lw_x, lw_y = 1200.0, 600.0
    # Stepped Stone Reservoir Basin
    spawn_mesh("LionWell_Basin_N", unreal.Vector(lw_x, lw_y + 350.0, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.0, 1.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_mesh("LionWell_Basin_S", unreal.Vector(lw_x, lw_y - 350.0, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.0, 1.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_mesh("LionWell_Basin_E", unreal.Vector(lw_x + 350.0, lw_y, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 8.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_mesh("LionWell_Basin_W", unreal.Vector(lw_x - 350.0, lw_y, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 8.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    
    # 3 Sluice Gate Portals
    for s_idx, (s_ox, s_tag) in enumerate([(-180.0, "Gate1_Intake"), (0.0, "Gate2_Bypass"), (180.0, "Gate3_Feeder")]):
        spawn_mesh(f"LionWell_{s_tag}_Arch_L", unreal.Vector(lw_x + s_ox - 30.0, lw_y + 300.0, 75.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.25, 0.25, 1.5), cylinder_mesh, materials["M_GraniteDark"])
        spawn_mesh(f"LionWell_{s_tag}_Arch_R", unreal.Vector(lw_x + s_ox + 30.0, lw_y + 300.0, 75.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.25, 0.25, 1.5), cylinder_mesh, materials["M_GraniteDark"])
        spawn_mesh(f"LionWell_{s_tag}_Slab", unreal.Vector(lw_x + s_ox, lw_y + 300.0, 130.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.8, 0.25, 0.25), cube_mesh, materials["M_Gold"])

    # Carved Lion Head Spout
    spawn_mesh("LionWell_LionPedestal", unreal.Vector(lw_x, lw_y + 320.0, 110.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.2, 1.2, 1.4), cube_mesh, materials["M_GraniteDark"])
    spawn_mesh("LionWell_LionHead_Spout", unreal.Vector(lw_x, lw_y + 240.0, 160.0), unreal.Rotator(-20, -90, 0), unreal.Vector(0.9, 0.9, 0.9), cone_mesh, materials["M_Sandstone"])

    # =========================================================================
    # I. COURSE OF FOUR PUZZLE PLATFORM (P01 STONE ALIGNMENT)
    # =========================================================================
    p01_x, p01_y = 800.0, 1400.0
    spawn_mesh("P01_Platform", unreal.Vector(p01_x, p01_y, 20.0), unreal.Rotator(0, 0, 0), unreal.Vector(7.5, 7.5, 0.4), cylinder_mesh, materials["M_GraniteDark"])
    for p_idx, (p_ox, p_oy, p_tag) in enumerate([(-150.0, -150.0, "G1"), (150.0, -150.0, "G2"), (-150.0, 150.0, "G3"), (150.0, 150.0, "G4")]):
        spawn_mesh(f"P01_Plinth_{p_tag}", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 45.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.2, 1.2, 0.5), cube_mesh, materials["M_GraniteDark"])
        spawn_mesh(f"P01_Shaft_{p_tag}", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 110.0), unreal.Rotator(0, (p_idx * 45), 0), unreal.Vector(0.7, 0.7, 1.6), cylinder_mesh, materials["M_Sandstone"])

    # =========================================================================
    # J. TROPICAL PALM TREES (PERIMETER)
    # =========================================================================
    for idx, (px, py) in enumerate([(1600.0, -300.0), (1700.0, 400.0), (-1600.0, -400.0), (-1800.0, 800.0)]):
        spawn_mesh(f"Palm_Trunk_{idx}", unreal.Vector(px, py, 220.0), unreal.Rotator(3, 0, 0), unreal.Vector(0.35, 0.35, 4.5), cylinder_mesh, materials["M_Timber"])
        spawn_mesh(f"Palm_Crown_{idx}", unreal.Vector(px, py, 460.0), unreal.Rotator(180, 0, 0), unreal.Vector(3.2, 3.2, 0.9), cone_mesh, materials["M_Foliage"])

    # =========================================================================
    # K. PLAYER START & PLAYABLE THIRD PERSON CHARACTER
    # =========================================================================
    player_loc = unreal.Vector(0.0, -700.0, 20.0)
    p_start = editor_actor_subsystem.spawn_actor_from_class(unreal.PlayerStart, player_loc)
    if p_start:
        p_start.set_actor_label("PlayerStart_Main")
        p_start.set_actor_rotation(unreal.Rotator(0, 90, 0), False)

    # Place BP_ThirdPersonCharacter directly in the level
    bp_char_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    if bp_char_cls:
        editor_actor_subsystem.spawn_actor_from_class(bp_char_cls, unreal.Vector(0.0, -650.0, 20.0))
        unreal.log("Spawned playable BP_ThirdPersonCharacter at start.")

    # Save Level
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== FULL LIVING SHOWCASE LEVEL SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    build_full_showcase()
