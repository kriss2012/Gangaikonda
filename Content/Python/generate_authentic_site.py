import unreal

def build_authentic_zone5_site():
    unreal.log("==================================================================")
    unreal.log("GENERATING AUTHENTIC GANGAIKONDACHOLAPURAM ZONE 5 SHOWCASE SITE")
    unreal.log("Brihadisvara Temple Under Active Construction c. 1025 CE")
    unreal.log("Doc 01-39 Historical Alignment & Concept Animatic Parity")
    unreal.log("==================================================================")

    level_path = "/Game/Maps/Test_Zone5_Greybox"
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

    level_editor_subsystem.load_level(level_path)

    # 1. Clean up old geometry, redundant directional lights, and floating text
    all_actors = editor_actor_subsystem.get_all_level_actors()
    keep_classes = [
        "GKLightingManagerActor", "GKLionWellPuzzleActor", 
        "GKStoneAlignmentPuzzleActor", "SkyAtmosphere", "SkyLight", "ExponentialHeightFog"
    ]
    for act in all_actors:
        if act:
            class_name = act.get_class().get_name()
            # Remove standalone DirectionalLights to eliminate lighting conflict warning
            if "DirectionalLight" in class_name and "GKLightingManagerActor" not in class_name:
                editor_actor_subsystem.destroy_actor(act)
                continue
            if not any(k in class_name for k in keep_classes):
                editor_actor_subsystem.destroy_actor(act)

    unreal.log("Cleared old blockout geometry and cleaned lighting actors.")

    # 2. Load Architectural Materials
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    mic_factory = unreal.MaterialInstanceConstantFactoryNew()
    base_mat = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")

    material_defs = {
        "M_Sandstone": unreal.LinearColor(0.82, 0.68, 0.48, 1.0),   # Warm Chola golden granite/sandstone
        "M_Timber": unreal.LinearColor(0.32, 0.18, 0.08, 1.0),      # Dark scaffolding timber
        "M_Terracotta": unreal.LinearColor(0.68, 0.32, 0.18, 1.0),  # Red earth construction ground
        "M_GraniteDark": unreal.LinearColor(0.38, 0.38, 0.36, 1.0), # Carved plinth stone & monoliths
        "M_Cloth": unreal.LinearColor(0.88, 0.78, 0.58, 1.0),       # Pavilion tent canopy
        "M_Gold": unreal.LinearColor(1.0, 0.80, 0.10, 1.0),         # Finials & golden evidence
        "M_Foliage": unreal.LinearColor(0.18, 0.42, 0.14, 1.0),     # Tropical palm fronds
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

    # 3. Meshes & Skeletal Animations
    cube_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    cylinder_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
    cone_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cone.Cone")
    sphere_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Sphere.Sphere")
    manny_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple")
    quinn_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple")

    anim_idle = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/MM_Idle.MM_Idle")
    anim_walk = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/Walk/MF_Unarmed_Walk_Fwd.MF_Unarmed_Walk_Fwd")
    anim_work = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Anims/Unarmed/Attack/MM_Attack_01.MM_Attack_01")

    # Helper function for static textured props
    def spawn_prop(label, loc, rot, scale, mesh=cube_mesh, mat=None):
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

    # Helper function for living animated NPCs
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

    # Helper function for in-world 3D Evidence Tags
    def spawn_evidence_tag(label, text, loc, text_color=unreal.Color(255, 215, 0, 255), size=45.0):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.TextRenderActor, loc)
        if actor:
            actor.set_actor_label(label)
            comp = actor.text_render
            if comp:
                comp.set_text(unreal.Text(text))
                comp.set_text_render_color(text_color)
                comp.set_world_size(size)
                comp.set_horizontal_alignment(unreal.HorizTextAligment.EHTA_CENTER)
            actor.set_actor_rotation(unreal.Rotator(0, -90, 0), False)
        return actor

    # =========================================================================
    # A. GROUND: RED LATERITE CONSTRUCTION TERRAIN (180m x 180m)
    # =========================================================================
    spawn_prop("Terrain_RedEarth", unreal.Vector(0.0, 800.0, -50.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(180.0, 180.0, 1.0), cube_mesh, materials["M_Terracotta"])

    # Processional dressed stone avenue leading from south entrance toward temple
    spawn_prop("Road_StoneProcessional", unreal.Vector(0.0, 200.0, -42.0), unreal.Rotator(0, 0, 0),
               unreal.Vector(8.0, 25.0, 1.1), cube_mesh, materials["M_GraniteDark"])

    # =========================================================================
    # B. BRIHADISVARA TEMPLE VIMANA (UNDER ACTIVE CONSTRUCTION)
    # =========================================================================
    vx, vy = 0.0, 2100.0

    # 1. Adhisthana Plinth Base (Dark granite molded base)
    spawn_prop("Vimana_Adhisthana_Plinth", unreal.Vector(vx, vy, 100.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(28.0, 28.0, 2.0), cube_mesh, materials["M_GraniteDark"])

    # 2. Tier 1 Course (Finished Golden Sandstone Tala)
    t1_z = 350.0
    spawn_prop("Vimana_Course_Tier1", unreal.Vector(vx, vy, t1_z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(24.0, 24.0, 3.0), cube_mesh, materials["M_Sandstone"])

    # Tier 1 Architectural Pilasters & Niches (Devakosthas)
    for i in range(7):
        nx = -900.0 + (i * 300.0)
        spawn_prop(f"Vimana_Niche_T1_{i}", unreal.Vector(nx, vy - 1210.0, t1_z), unreal.Rotator(0, 0, 0),
                   unreal.Vector(0.5, 0.2, 1.8), cube_mesh, materials["M_GraniteDark"])

    # 3. Tier 2 Course (Finished with Kudus and moldings)
    t2_z = 700.0
    spawn_prop("Vimana_Course_Tier2", unreal.Vector(vx, vy, t2_z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(20.0, 20.0, 4.0), cube_mesh, materials["M_Sandstone"])

    for i in range(5):
        nx = -600.0 + (i * 300.0)
        spawn_prop(f"Vimana_Niche_T2_{i}", unreal.Vector(nx, vy - 1010.0, t2_z), unreal.Rotator(0, 0, 0),
                   unreal.Vector(0.5, 0.2, 1.8), cube_mesh, materials["M_GraniteDark"])

    # 4. Tier 3 Staging Platform (Where the 60m construction ramp lands)
    t3_z = 1150.0
    spawn_prop("Vimana_Course_Tier3_StagingPlatform", unreal.Vector(vx, vy, t3_z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(16.0, 16.0, 5.0), cube_mesh, materials["M_Sandstone"])

    # 5. Unfinished Upper Courses (Tier 4 & 5 - raw rough-cut stone ashlar)
    t4_z = 1550.0
    spawn_prop("Vimana_Course_Tier4_Unfinished", unreal.Vector(vx, vy, t4_z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(12.0, 12.0, 3.0), cube_mesh, materials["M_GraniteDark"])

    # 6. Sanctum Entrance Lintel & Mukhamandapa Pillars
    spawn_prop("Sanctum_Lintel", unreal.Vector(vx, vy - 1220.0, 430.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(8.0, 1.6, 1.2), cube_mesh, materials["M_GraniteDark"])
    spawn_prop("Sanctum_Pillar_L", unreal.Vector(vx - 320.0, vy - 1220.0, 215.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(0.9, 0.9, 4.3), cylinder_mesh, materials["M_GraniteDark"])
    spawn_prop("Sanctum_Pillar_R", unreal.Vector(vx + 320.0, vy - 1220.0, 215.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(0.9, 0.9, 4.3), cylinder_mesh, materials["M_GraniteDark"])

    # =========================================================================
    # C. MASSIVE TIMBER SCAFFOLDING SUPERSTRUCTURE (30m LATTICE)
    # =========================================================================
    scaff_base_z = 1700.0
    scaff_w = 550.0
    scaff_h = 1100.0

    # 4 Vertical Timber Tower Columns (Reaching 30 meters high)
    for idx, (cx, cy) in enumerate([(-scaff_w, -scaff_w), (scaff_w, -scaff_w), (-scaff_w, scaff_w), (scaff_w, scaff_w)]):
        spawn_prop(f"Scaffolding_MainPost_{idx+1}", unreal.Vector(vx + cx, vy + cy, scaff_base_z + (scaff_h / 2.0)), 
                   unreal.Rotator(0, 0, 0), unreal.Vector(0.4, 0.4, scaff_h / 100.0), cylinder_mesh, materials["M_Timber"])

    # Horizontal Scaffold Ledgers (4 elevation tiers)
    for t in range(4):
        lz = scaff_base_z + (t * 280.0)
        spawn_prop(f"Scaffold_Ledger_F_{t}", unreal.Vector(vx, vy - scaff_w, lz), unreal.Rotator(0, 0, 0), unreal.Vector(11.5, 0.25, 0.25), cube_mesh, materials["M_Timber"])
        spawn_prop(f"Scaffold_Ledger_B_{t}", unreal.Vector(vx, vy + scaff_w, lz), unreal.Rotator(0, 0, 0), unreal.Vector(11.5, 0.25, 0.25), cube_mesh, materials["M_Timber"])
        spawn_prop(f"Scaffold_Ledger_L_{t}", unreal.Vector(vx - scaff_w, vy, lz), unreal.Rotator(0, 90, 0), unreal.Vector(11.5, 0.25, 0.25), cube_mesh, materials["M_Timber"])
        spawn_prop(f"Scaffold_Ledger_R_{t}", unreal.Vector(vx + scaff_w, vy, lz), unreal.Rotator(0, 90, 0), unreal.Vector(11.5, 0.25, 0.25), cube_mesh, materials["M_Timber"])

    # Diagonal Cross-Bracing on Scaffolding Facade
    spawn_prop("Scaffold_CrossBrace_1", unreal.Vector(vx, vy - scaff_w, scaff_base_z + 300.0), 
               unreal.Rotator(33, 0, 0), unreal.Vector(0.2, 0.2, 13.0), cylinder_mesh, materials["M_Timber"])
    spawn_prop("Scaffold_CrossBrace_2", unreal.Vector(vx, vy - scaff_w, scaff_base_z + 300.0), 
               unreal.Rotator(-33, 0, 0), unreal.Vector(0.2, 0.2, 13.0), cylinder_mesh, materials["M_Timber"])
    spawn_prop("Scaffold_CrossBrace_3", unreal.Vector(vx, vy - scaff_w, scaff_base_z + 800.0), 
               unreal.Rotator(33, 0, 0), unreal.Vector(0.2, 0.2, 13.0), cylinder_mesh, materials["M_Timber"])
    spawn_prop("Scaffold_CrossBrace_4", unreal.Vector(vx, vy - scaff_w, scaff_base_z + 800.0), 
               unreal.Rotator(-33, 0, 0), unreal.Vector(0.2, 0.2, 13.0), cylinder_mesh, materials["M_Timber"])

    # Timber Hoisting Pulley Beam & Granite Block
    spawn_prop("Scaffold_PulleyBeam", unreal.Vector(vx, vy - scaff_w - 60.0, scaff_base_z + scaff_h - 50.0),
               unreal.Rotator(0, 0, 0), unreal.Vector(3.0, 0.3, 0.3), cube_mesh, materials["M_Timber"])
    spawn_prop("Scaffold_Hoisted_Stone", unreal.Vector(vx, vy - scaff_w - 60.0, scaff_base_z + 500.0),
               unreal.Rotator(0, 15, 0), unreal.Vector(1.2, 1.2, 0.9), cube_mesh, materials["M_Sandstone"])

    # =========================================================================
    # D. THE GREAT INCLINED TIMBER & STONE CONSTRUCTION RAMP
    # =========================================================================
    # Rises from ground (Z=20) up to Tier 3 platform (Z=1150)
    rx_start, ry_start = -1900.0, 500.0
    rx_end, ry_end = -850.0, 2100.0
    rc_x = (rx_start + rx_end) / 2.0
    rc_y = (ry_start + ry_end) / 2.0
    rc_z = 590.0

    # Ramp surface roadway (seasoned dark timber deck)
    spawn_prop("Construction_Ramp_Roadway", unreal.Vector(rc_x, rc_y, rc_z), unreal.Rotator(28, 57, 0), 
               unreal.Vector(21.5, 3.8, 0.6), cube_mesh, materials["M_Timber"])

    # Timber Trestle Support Bents
    for p in range(7):
        pct = p / 6.0
        px = rx_start + (pct * (rx_end - rx_start))
        py = ry_start + (pct * (ry_end - ry_start))
        ph = 70.0 + (pct * 1060.0)
        pz = ph / 2.0
        spawn_prop(f"Ramp_Trestle_L_{p}", unreal.Vector(px - 95.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.32, 0.32, ph / 100.0), cylinder_mesh, materials["M_Timber"])
        spawn_prop(f"Ramp_Trestle_R_{p}", unreal.Vector(px + 95.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.32, 0.32, ph / 100.0), cylinder_mesh, materials["M_Timber"])
        spawn_prop(f"Ramp_Trestle_Beam_{p}", unreal.Vector(px, py, ph), unreal.Rotator(0, 57, 0), unreal.Vector(3.0, 0.32, 0.32), cube_mesh, materials["M_Timber"])

    # =========================================================================
    # E. LIVING, ANIMATED NPCS (AUTOMATED CHOLA WORKERS, ARCHITECT, SCHOLAR)
    # =========================================================================
    # 1. The Chief Architect: Surveying construction from top of ramp!
    arch_loc = unreal.Vector(rx_end + 35.0, ry_end - 45.0, 1165.0)
    spawn_animated_npc("NPC_ChiefArchitect", arch_loc, unreal.Rotator(0, -125, 0), quinn_mesh, anim_idle)
    # Drafting desk with palm-leaf scrolls
    spawn_prop("Architect_DraftingDesk", unreal.Vector(arch_loc.x + 75.0, arch_loc.y, arch_loc.z), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.6, 0.9, 0.8), cube_mesh, materials["M_Timber"])

    # 2. Worker 1 on Ramp: Walking up with granite head-load!
    w1_loc = unreal.Vector(rx_start + 0.22 * (rx_end - rx_start), ry_start + 0.22 * (ry_end - ry_start), 310.0)
    spawn_animated_npc("NPC_Worker_Ramp_1", w1_loc, unreal.Rotator(0, 57, 0), manny_mesh, anim_walk)
    spawn_prop("Stone_Headload_1", unreal.Vector(w1_loc.x, w1_loc.y, w1_loc.z + 185.0), unreal.Rotator(0, 57, 0), 
               unreal.Vector(0.45, 0.45, 0.3), cube_mesh, materials["M_Sandstone"])

    # 3. Worker 2 on Ramp: Walking higher up the incline!
    w2_loc = unreal.Vector(rx_start + 0.62 * (rx_end - rx_start), ry_start + 0.62 * (ry_end - ry_start), 770.0)
    spawn_animated_npc("NPC_Worker_Ramp_2", w2_loc, unreal.Rotator(0, 57, 0), manny_mesh, anim_walk)
    spawn_prop("Stone_Headload_2", unreal.Vector(w2_loc.x, w2_loc.y, w2_loc.z + 185.0), unreal.Rotator(0, 57, 0), 
               unreal.Vector(0.45, 0.45, 0.3), cube_mesh, materials["M_Sandstone"])

    # 4. Stone Mason 1 at Ground Yard: Animated chiseling granite (strike loop)!
    spawn_animated_npc("NPC_StoneMason_Active1", unreal.Vector(-1550.0, 320.0, 0.0), unreal.Rotator(0, 45, 0), manny_mesh, anim_work)
    spawn_prop("Stone_ChiselingBlock_1", unreal.Vector(-1510.0, 360.0, 35.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.1, 1.1, 0.7), cube_mesh, materials["M_Sandstone"])

    # 5. Stone Mason 2: Inspection idle
    spawn_animated_npc("NPC_StoneMason_Active2", unreal.Vector(-1350.0, 380.0, 0.0), unreal.Rotator(0, -90, 0), manny_mesh, anim_idle)

    # 6. Royal Epigraphist Scholar: Idle at archive pavilion
    tent_x, tent_y = 1000.0, -200.0
    spawn_animated_npc("NPC_RoyalEpigraphist", unreal.Vector(tent_x, tent_y - 65.0, 0.0), unreal.Rotator(0, 90, 0), quinn_mesh, anim_idle)

    # 7. Ambush Guard / Vanguard Soldier (Combat ready)
    spawn_animated_npc("NPC_AmbushGuard", unreal.Vector(0.0, 450.0, 0.0), unreal.Rotator(0, -90, 0), manny_mesh, anim_idle)

    # =========================================================================
    # F. STONE CUTTER YARDS & MONOLITH HAULING SLEDGE
    # =========================================================================
    yard_x, yard_y = -1550.0, 100.0
    for r in range(2):
        for c in range(3):
            spawn_prop(f"Granite_DressedBlock_{r}_{c}", unreal.Vector(yard_x + (c * 150.0), yard_y + (r * 150.0), 45.0),
                       unreal.Rotator(0, (r * 12), 0), unreal.Vector(1.3, 1.3, 0.9), cube_mesh, materials["M_Sandstone"])

    # Heavy Stone-Hauling Wooden Sledge with 20-ton Monolith
    sledge_x, sledge_y = -1150.0, -100.0
    spawn_prop("Hauler_Sledge_Runner_L", unreal.Vector(sledge_x - 85.0, sledge_y, 25.0), unreal.Rotator(0, 30, 0), unreal.Vector(4.2, 0.35, 0.5), cube_mesh, materials["M_Timber"])
    spawn_prop("Hauler_Sledge_Runner_R", unreal.Vector(sledge_x + 85.0, sledge_y, 25.0), unreal.Rotator(0, 30, 0), unreal.Vector(4.2, 0.35, 0.5), cube_mesh, materials["M_Timber"])
    spawn_prop("Hauler_Sledge_Crossdeck", unreal.Vector(sledge_x, sledge_y, 40.0), unreal.Rotator(0, 30, 0), unreal.Vector(4.0, 1.9, 0.3), cube_mesh, materials["M_Timber"])
    spawn_prop("Hauler_Monolith_Stone", unreal.Vector(sledge_x, sledge_y, 115.0), unreal.Rotator(0, 30, 0), unreal.Vector(3.4, 1.5, 1.3), cube_mesh, materials["M_GraniteDark"])

    # Timber Rollers under Sledge
    for ri in range(4):
        rox = -120.0 + (ri * 80.0)
        spawn_prop(f"Hauler_Roller_{ri}", unreal.Vector(sledge_x + rox, sledge_y, 15.0), unreal.Rotator(0, 120, 90), unreal.Vector(0.3, 0.3, 2.2), cylinder_mesh, materials["M_Timber"])

    # =========================================================================
    # G. ROYAL SCHOLAR ARCHIVE TENT & INSCRIPTION WALL (P10 PUZZLE)
    # =========================================================================
    spawn_prop("Scholar_Tent_Canopy", unreal.Vector(tent_x, tent_y, 235.0), unreal.Rotator(0, 45, 0), 
               unreal.Vector(5.0, 5.0, 1.1), cone_mesh, materials["M_Cloth"])
    for px, py in [(-165, -165), (165, -165), (-165, 165), (165, 165)]:
        spawn_prop(f"Scholar_Tent_Post_{px}", unreal.Vector(tent_x + px, tent_y + py, 100.0), unreal.Rotator(0, 0, 0),
                   unreal.Vector(0.22, 0.22, 2.0), cylinder_mesh, materials["M_Timber"])
    spawn_prop("Scholar_Desk", unreal.Vector(tent_x, tent_y, 45.0), unreal.Rotator(0, 0, 0), 
               unreal.Vector(1.9, 1.1, 0.8), cube_mesh, materials["M_Timber"])
    spawn_prop("P10_Inscription_StoneSlab", unreal.Vector(tent_x, tent_y + 85.0, 68.0), unreal.Rotator(15, 0, 0), 
               unreal.Vector(1.3, 0.18, 1.05), cube_mesh, materials["M_Gold"])

    # =========================================================================
    # H. LION WELL HYDRAULIC STEPWELL (P04 PUZZLE COMPLEX)
    # =========================================================================
    lw_x, lw_y = 1250.0, 650.0
    spawn_prop("LionWell_Basin_N", unreal.Vector(lw_x, lw_y + 360.0, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.5, 1.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_prop("LionWell_Basin_S", unreal.Vector(lw_x, lw_y - 360.0, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.5, 1.0, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_prop("LionWell_Basin_E", unreal.Vector(lw_x + 360.0, lw_y, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 8.5, 0.8), cube_mesh, materials["M_GraniteDark"])
    spawn_prop("LionWell_Basin_W", unreal.Vector(lw_x - 360.0, lw_y, 40.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 8.5, 0.8), cube_mesh, materials["M_GraniteDark"])

    # 3 Sluice Gate Portals with Gold Sluice Plates
    for s_idx, (s_ox, s_tag) in enumerate([(-190.0, "Gate1_Intake"), (0.0, "Gate2_Bypass"), (190.0, "Gate3_Feeder")]):
        spawn_prop(f"LionWell_{s_tag}_Arch_L", unreal.Vector(lw_x + s_ox - 32.0, lw_y + 310.0, 78.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.26, 0.26, 1.55), cylinder_mesh, materials["M_GraniteDark"])
        spawn_prop(f"LionWell_{s_tag}_Arch_R", unreal.Vector(lw_x + s_ox + 32.0, lw_y + 310.0, 78.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.26, 0.26, 1.55), cylinder_mesh, materials["M_GraniteDark"])
        spawn_prop(f"LionWell_{s_tag}_Slab", unreal.Vector(lw_x + s_ox, lw_y + 310.0, 135.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.85, 0.26, 0.26), cube_mesh, materials["M_Gold"])

    # Carved Lion Head Spout
    spawn_prop("LionWell_LionPedestal", unreal.Vector(lw_x, lw_y + 330.0, 115.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.3, 1.3, 1.45), cube_mesh, materials["M_GraniteDark"])
    spawn_prop("LionWell_LionHead_Spout", unreal.Vector(lw_x, lw_y + 245.0, 165.0), unreal.Rotator(-20, -90, 0), unreal.Vector(0.95, 0.95, 0.95), cone_mesh, materials["M_Sandstone"])

    # =========================================================================
    # I. COURSE OF FOUR PUZZLE PLATFORM (P01 STONE ALIGNMENT)
    # =========================================================================
    p01_x, p01_y = 850.0, 1450.0
    spawn_prop("P01_Platform", unreal.Vector(p01_x, p01_y, 20.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.0, 8.0, 0.4), cylinder_mesh, materials["M_GraniteDark"])
    for p_idx, (p_ox, p_oy, p_tag) in enumerate([(-155.0, -155.0, "G1"), (155.0, -155.0, "G2"), (-155.0, 155.0, "G3"), (155.0, 155.0, "G4")]):
        spawn_prop(f"P01_Plinth_{p_tag}", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 45.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.25, 1.25, 0.5), cube_mesh, materials["M_GraniteDark"])
        spawn_prop(f"P01_Shaft_{p_tag}", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 115.0), unreal.Rotator(0, (p_idx * 45), 0), unreal.Vector(0.75, 0.75, 1.65), cylinder_mesh, materials["M_Sandstone"])

    # =========================================================================
    # J. TROPICAL PALM GROVES (PERIMETER)
    # =========================================================================
    palm_coords = [
        (1700.0, -350.0), (1800.0, 350.0), (1750.0, 950.0),
        (-1700.0, -450.0), (-1900.0, 150.0), (-1850.0, 950.0)
    ]
    for idx, (px, py) in enumerate(palm_coords):
        spawn_prop(f"Palm_Trunk_{idx}", unreal.Vector(px, py, 230.0), unreal.Rotator(3, 0, 0), unreal.Vector(0.38, 0.38, 4.6), cylinder_mesh, materials["M_Timber"])
        spawn_prop(f"Palm_Crown_{idx}", unreal.Vector(px, py, 480.0), unreal.Rotator(180, 0, 0), unreal.Vector(3.4, 3.4, 0.95), cone_mesh, materials["M_Foliage"])

    # =========================================================================
    # K. IN-WORLD DOCUMENTARY EVIDENCE CARDS (MATCHING CONCEPT ANIMATIC)
    # =========================================================================
    gold_c = unreal.Color(235, 185, 50, 255)
    silver_c = unreal.Color(210, 215, 220, 255)

    spawn_evidence_tag("EvidenceTag_Scaffolding", 
                       "[RECONSTRUCTED]\nupper courses shown unfinished\n(Scaffolding & Timber Trestles)", 
                       unreal.Vector(vx, vy - scaff_w - 80.0, scaff_base_z + 800.0), silver_c, 60.0)

    spawn_evidence_tag("EvidenceTag_VimanaHistorical", 
                       "[HISTORICALLY ATTESTED]\nBrihadisvara Temple site (Doc 03 C2)\nBuilt c. 1025-1035 CE", 
                       unreal.Vector(vx, vy - 1100.0, 1200.0), gold_c, 70.0)

    spawn_evidence_tag("EvidenceTag_ConstructionRamp", 
                       "[FICTIONALIZED FOR VERTICAL SLICE]\nconstruction-phase earthen ramp layout", 
                       unreal.Vector(rx_start + 250.0, ry_start, 450.0), silver_c, 50.0)

    spawn_evidence_tag("QuestPrompt_MeetArchitect", 
                       "QUEST: Meet the Architect\nQ3 * Historical basis: [FICTIONAL] scene on [DOCUMENTED] site", 
                       unreal.Vector(0.0, -350.0, 280.0), unreal.Color(255, 255, 255, 255), 45.0)

    # =========================================================================
    # L. PLAYABLE CHARACTER WITH AUTOMATIC POSSESSION & THIRD-PERSON CAMERA
    # =========================================================================
    spawn_loc = unreal.Vector(0.0, -700.0, 30.0)

    # PlayerStart
    p_start = editor_actor_subsystem.spawn_actor_from_class(unreal.PlayerStart, spawn_loc)
    if p_start:
        p_start.set_actor_label("PlayerStart_Main")
        p_start.set_actor_rotation(unreal.Rotator(0, 90, 0), False)

    # Place BP_ThirdPersonCharacter and force auto_possess_player to Player0
    bp_char_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    if bp_char_cls:
        char_actor = editor_actor_subsystem.spawn_actor_from_class(bp_char_cls, unreal.Vector(0.0, -650.0, 50.0))
        if char_actor:
            char_actor.set_actor_label("BP_ThirdPersonCharacter_Playable")
            char_actor.set_actor_rotation(unreal.Rotator(0, 90, 0), False)
            char_actor.set_editor_property("auto_possess_player", unreal.AutoReceiveInput.PLAYER0)
            unreal.log("Configured BP_ThirdPersonCharacter with AutoPossessPlayer=Player0.")

    # Save Level
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== AUTHENTIC ZONE 5 SHOWCASE LEVEL SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    build_authentic_zone5_site()
