import unreal

def build_authentic_zone5_site():
    unreal.log("==================================================================")
    unreal.log("GENERATING AUTHENTIC GANGAIKONDACHOLAPURAM ZONE 5 CONSTRUCTION SITE")
    unreal.log("Matching Concept Animatic: Brihadisvara Temple c. 1025-1035 CE")
    unreal.log("==================================================================")

    level_path = "/Game/Maps/Test_Zone5_Greybox"
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

    level_editor_subsystem.load_level(level_path)

    # 1. Clear previous basic blockout actors (keep lighting manager & puzzle logic actors)
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

    unreal.log("Cleared old blockout geometry.")

    # 2. Load standard engine shapes
    cube_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    cylinder_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
    cone_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cone.Cone")
    sphere_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Sphere.Sphere")
    manny_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple")
    quinn_mesh = unreal.EditorAssetLibrary.load_asset("/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple")

    # Helper function for static meshes
    def spawn_prop(label, loc, rot, scale, mesh=cube_mesh):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.StaticMeshActor, loc)
        if actor:
            actor.set_actor_label(label)
            actor.set_actor_rotation(rot, False)
            if mesh:
                actor.static_mesh_component.set_static_mesh(mesh)
            actor.set_actor_scale3d(scale)
        return actor

    # Helper function for skeletal mannequin NPCs
    def spawn_mannequin(label, loc, rot, mesh=manny_mesh):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.SkeletalMeshActor, loc)
        if actor:
            actor.set_actor_label(label)
            actor.set_actor_rotation(rot, False)
            if mesh and actor.skeletal_mesh_component:
                actor.skeletal_mesh_component.set_skeletal_mesh_asset(mesh)
            actor.set_actor_scale3d(unreal.Vector(1.0, 1.0, 1.0))
        return actor

    # Helper function for 3D Documentary Evidence Tags (matching Concept Animatic)
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
            actor.set_actor_rotation(unreal.Rotator(0, -90, 0), False) # Face camera looking North
        return actor

    # =========================================================================
    # A. ARENA GROUND & SURROUNDING RED EARTH
    # =========================================================================
    ground = spawn_prop("Ground_ConstructionPlain", unreal.Vector(0.0, 800.0, -50.0), 
                        unreal.Rotator(0, 0, 0), unreal.Vector(150.0, 150.0, 1.0))
    unreal.log("Spawned 150m construction plain.")

    # =========================================================================
    # B. BRIHADISVARA TEMPLE VIMANA (UNDER CONSTRUCTION)
    # =========================================================================
    # Lower finished stone courses with niches (Doc 16 & Animatic Frame 1)
    vimana_y = 2200.0
    vimana_x = 0.0

    # Base Plinth (Upapitha / Adhisthana)
    spawn_prop("Vimana_Adhisthana_Plinth", unreal.Vector(vimana_x, vimana_y, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(30.0, 30.0, 2.0))

    # Tier 1 Course
    tier1_z = 350.0
    spawn_prop("Vimana_Course_Tier1", unreal.Vector(vimana_x, vimana_y, tier1_z), unreal.Rotator(0, 0, 0), unreal.Vector(26.0, 26.0, 3.0))

    # Tier 2 Course
    tier2_z = 700.0
    spawn_prop("Vimana_Course_Tier2", unreal.Vector(vimana_x, vimana_y, tier2_z), unreal.Rotator(0, 0, 0), unreal.Vector(22.0, 22.0, 4.0))

    # Tier 3 Course (Staging Platform where ramp lands)
    tier3_z = 1150.0
    spawn_prop("Vimana_Course_Tier3_StagingPlatform", unreal.Vector(vimana_x, vimana_y, tier3_z), unreal.Rotator(0, 0, 0), unreal.Vector(18.0, 18.0, 5.0))

    # Upper Unfinished Courses (Tier 4 & 5 - raw stone courses before scaffolding)
    tier4_z = 1600.0
    spawn_prop("Vimana_Course_Tier4_Unfinished", unreal.Vector(vimana_x, vimana_y, tier4_z), unreal.Rotator(0, 0, 0), unreal.Vector(14.0, 14.0, 4.0))

    # Recessed Kudus / Niches on finished lower facade
    for i in range(7):
        n_x = -1000.0 + (i * 330.0)
        spawn_prop(f"Vimana_Facade_Niche_T1_{i}", unreal.Vector(n_x, vimana_y - 1310.0, tier1_z), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.2, 1.8))
        spawn_prop(f"Vimana_Facade_Niche_T2_{i}", unreal.Vector(n_x * 0.8, vimana_y - 1110.0, tier2_z), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.2, 1.8))

    # =========================================================================
    # C. MASSIVE TIMBER SCAFFOLDING SUPERSTRUCTURE (Upper Unfinished Courses)
    # =========================================================================
    scaffold_base_z = 1800.0
    scaffold_w = 600.0
    scaffold_h = 1200.0

    # 4 Vertical Timber Tower Columns (Reaching 30 meters high)
    col_coords = [(-scaffold_w, -scaffold_w), (scaffold_w, -scaffold_w), (-scaffold_w, scaffold_w), (scaffold_w, scaffold_w)]
    for idx, (cx, cy) in enumerate(col_coords):
        spawn_prop(f"Scaffolding_MainPost_{idx+1}", unreal.Vector(vimana_x + cx, vimana_y + cy, scaffold_base_z + (scaffold_h / 2.0)), 
                   unreal.Rotator(0, 0, 0), unreal.Vector(0.4, 0.4, scaffold_h / 100.0), cylinder_mesh)

    # Horizontal Scaffold Ledgers (4 elevation tiers)
    for t in range(4):
        lz = scaffold_base_z + (t * 300.0)
        # Front ledger
        spawn_prop(f"Scaffold_Ledger_Front_{t}", unreal.Vector(vimana_x, vimana_y - scaffold_w, lz), unreal.Rotator(0, 0, 0), unreal.Vector(12.5, 0.25, 0.25))
        # Back ledger
        spawn_prop(f"Scaffold_Ledger_Back_{t}", unreal.Vector(vimana_x, vimana_y + scaffold_w, lz), unreal.Rotator(0, 0, 0), unreal.Vector(12.5, 0.25, 0.25))
        # Left ledger
        spawn_prop(f"Scaffold_Ledger_Left_{t}", unreal.Vector(vimana_x - scaffold_w, vimana_y, lz), unreal.Rotator(0, 90, 0), unreal.Vector(12.5, 0.25, 0.25))
        # Right ledger
        spawn_prop(f"Scaffold_Ledger_Right_{t}", unreal.Vector(vimana_x + scaffold_w, vimana_y, lz), unreal.Rotator(0, 90, 0), unreal.Vector(12.5, 0.25, 0.25))

    # Diagonal Cross-Bracing on Scaffolding Facade (Iconic timber lattice from animatic)
    spawn_prop("Scaffold_CrossBrace_1", unreal.Vector(vimana_x, vimana_y - scaffold_w, scaffold_base_z + 300.0), 
               unreal.Rotator(35, 0, 0), unreal.Vector(0.2, 0.2, 14.5), cylinder_mesh)
    spawn_prop("Scaffold_CrossBrace_2", unreal.Vector(vimana_x, vimana_y - scaffold_w, scaffold_base_z + 300.0), 
               unreal.Rotator(-35, 0, 0), unreal.Vector(0.2, 0.2, 14.5), cylinder_mesh)
    spawn_prop("Scaffold_CrossBrace_3", unreal.Vector(vimana_x, vimana_y - scaffold_w, scaffold_base_z + 900.0), 
               unreal.Rotator(35, 0, 0), unreal.Vector(0.2, 0.2, 14.5), cylinder_mesh)
    spawn_prop("Scaffold_CrossBrace_4", unreal.Vector(vimana_x, vimana_y - scaffold_w, scaffold_base_z + 900.0), 
               unreal.Rotator(-35, 0, 0), unreal.Vector(0.2, 0.2, 14.5), cylinder_mesh)

    # =========================================================================
    # D. THE GREAT INCLINED EARTHEN & TIMBER CONSTRUCTION RAMP
    # =========================================================================
    # Rises from ground (Z=20) up to Tier 3 staging platform (Z=1150)
    ramp_start_x = -2200.0
    ramp_start_y = 600.0
    ramp_end_x = -900.0
    ramp_end_y = 2200.0
    ramp_len = 2100.0

    # Ramp surface platform (angled incline)
    ramp_center_x = (ramp_start_x + ramp_end_x) / 2.0
    ramp_center_y = (ramp_start_y + ramp_end_y) / 2.0
    ramp_center_z = 600.0

    # Ramp incline slab
    spawn_prop("Construction_Ramp_Deck", unreal.Vector(ramp_center_x, ramp_center_y, ramp_center_z), 
               unreal.Rotator(28, 51, 0), unreal.Vector(22.0, 4.0, 0.5))

    # Timber Trestle Support Poles (holding up the ramp every 3.5m)
    for p in range(7):
        t_factor = p / 6.0
        px = ramp_start_x + (t_factor * (ramp_end_x - ramp_start_x))
        py = ramp_start_y + (t_factor * (ramp_end_y - ramp_start_y))
        pole_h = 80.0 + (t_factor * 1050.0)
        pz = pole_h / 2.0

        spawn_prop(f"Ramp_TrestlePole_L_{p}", unreal.Vector(px - 100.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, pole_h / 100.0), cylinder_mesh)
        spawn_prop(f"Ramp_TrestlePole_R_{p}", unreal.Vector(px + 100.0, py, pz), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, pole_h / 100.0), cylinder_mesh)
        spawn_prop(f"Ramp_CrossBeam_{p}", unreal.Vector(px, py, pole_h), unreal.Rotator(0, 51, 0), unreal.Vector(3.0, 0.3, 0.3))

    # =========================================================================
    # E. WORKER MANNEQUINS & CHARACTERS (VISUALLY ACTIVE IN SCENE)
    # =========================================================================
    # 1. The Chief Architect (Doc 08 Beat 05 / Animatic Frame 1)
    architect_loc = unreal.Vector(ramp_end_x + 50.0, ramp_end_y - 50.0, 1150.0)
    architect = spawn_mannequin("NPC_ChiefArchitect", architect_loc, unreal.Rotator(0, -120, 0), quinn_mesh)
    # Head-load / stone prop on architect's platform
    spawn_prop("Architect_Surveyor_TheodolitePedestal", unreal.Vector(architect_loc.x + 80.0, architect_loc.y, architect_loc.z), 
               unreal.Rotator(0, 0, 0), unreal.Vector(0.4, 0.4, 0.9))

    # 2. Workers carrying stone blocks up the ramp (matching animatic figures)
    worker_offsets = [0.15, 0.40, 0.70]
    for w_idx, w_t in enumerate(worker_offsets):
        wx = ramp_start_x + (w_t * (ramp_end_x - ramp_start_x))
        wy = ramp_start_y + (w_t * (ramp_end_y - ramp_start_y))
        wz = 50.0 + (w_t * 1100.0)
        w_actor = spawn_mannequin(f"NPC_RampWorker_{w_idx+1}", unreal.Vector(wx, wy, wz), unreal.Rotator(0, 51, 0), manny_mesh)
        # Stone block on worker's head
        spawn_prop(f"Stone_HeadLoad_{w_idx+1}", unreal.Vector(wx, wy, wz + 185.0), unreal.Rotator(0, 51, 0), unreal.Vector(0.5, 0.5, 0.3))

    # 3. Ground Stone Carvers / Cutters
    spawn_mannequin("NPC_StoneMason_1", unreal.Vector(-1800.0, 400.0, 0.0), unreal.Rotator(0, 90, 0), manny_mesh)
    spawn_mannequin("NPC_StoneMason_2", unreal.Vector(-1600.0, 350.0, 0.0), unreal.Rotator(0, -90, 0), manny_mesh)

    # 4. Working Elephant Haulers (Sculpted Blockout Representations)
    elephant_loc = unreal.Vector(-1400.0, -200.0, 0.0)
    # Body
    spawn_prop("Elephant_Body", unreal.Vector(elephant_loc.x, elephant_loc.y, 180.0), unreal.Rotator(0, 45, 0), unreal.Vector(3.5, 2.2, 2.2), sphere_mesh)
    # Head & Trunk
    spawn_prop("Elephant_Head", unreal.Vector(elephant_loc.x + 180.0, elephant_loc.y + 180.0, 220.0), unreal.Rotator(0, 45, 0), unreal.Vector(1.4, 1.4, 1.4), sphere_mesh)
    spawn_prop("Elephant_Trunk", unreal.Vector(elephant_loc.x + 260.0, elephant_loc.y + 260.0, 140.0), unreal.Rotator(45, 45, 0), unreal.Vector(0.4, 0.4, 1.6), cylinder_mesh)
    # 4 Legs
    spawn_prop("Elephant_Leg_FL", unreal.Vector(elephant_loc.x + 100.0, elephant_loc.y + 50.0, 70.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.5, 1.4), cylinder_mesh)
    spawn_prop("Elephant_Leg_FR", unreal.Vector(elephant_loc.x + 50.0, elephant_loc.y + 100.0, 70.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.5, 1.4), cylinder_mesh)
    spawn_prop("Elephant_Leg_BL", unreal.Vector(elephant_loc.x - 100.0, elephant_loc.y - 50.0, 70.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.5, 1.4), cylinder_mesh)
    spawn_prop("Elephant_Leg_BR", unreal.Vector(elephant_loc.x - 50.0, elephant_loc.y - 100.0, 70.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.5, 0.5, 1.4), cylinder_mesh)

    # =========================================================================
    # F. STONE CUTTER YARDS & QUARRIED GRANITE BLOCKS
    # =========================================================================
    yard_x = -1700.0
    yard_y = 200.0
    for row in range(3):
        for col in range(4):
            bx = yard_x + (col * 140.0)
            by = yard_y + (row * 140.0)
            spawn_prop(f"Granite_DressedBlock_{row}_{col}", unreal.Vector(bx, by, 40.0), unreal.Rotator(0, (row * 15), 0), unreal.Vector(1.2, 1.2, 0.8))

    # Masonry Workbench
    spawn_prop("Mason_Worktable", unreal.Vector(-1700.0, 380.0, 45.0), unreal.Rotator(0, 0, 0), unreal.Vector(2.5, 1.2, 0.7))

    # =========================================================================
    # G. ROYAL SCHOLAR EPIGRAPHIST PAVILION (Doc 08 Beat 03)
    # =========================================================================
    tent_x = 900.0
    tent_y = -300.0
    # Canopy
    spawn_prop("Scholar_Pavilion_Roof", unreal.Vector(tent_x, tent_y, 250.0), unreal.Rotator(0, 45, 0), unreal.Vector(5.0, 5.0, 1.2), cone_mesh)
    # Posts
    spawn_prop("Scholar_Post_1", unreal.Vector(tent_x - 180.0, tent_y - 180.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_prop("Scholar_Post_2", unreal.Vector(tent_x + 180.0, tent_y - 180.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_prop("Scholar_Post_3", unreal.Vector(tent_x - 180.0, tent_y + 180.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_prop("Scholar_Post_4", unreal.Vector(tent_x + 180.0, tent_y + 180.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    # Scribe Desk & Epigraphist Scholar
    spawn_prop("Scholar_ScribeDesk", unreal.Vector(tent_x, tent_y, 45.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.8, 1.0, 0.8))
    spawn_mannequin("NPC_RoyalEpigraphistScholar", unreal.Vector(tent_x, tent_y - 80.0, 0.0), unreal.Rotator(0, 90, 0), quinn_mesh)

    # Inscription Rubbing Stone Slab (P10 Scratched Stone Puzzle)
    spawn_prop("P10_Inscription_RubbingSlab", unreal.Vector(tent_x, tent_y + 80.0, 70.0), unreal.Rotator(15, 0, 0), unreal.Vector(1.4, 0.2, 1.2))

    # =========================================================================
    # H. LION WELL STEPWELL (P04 Hydraulic Puzzle Complex)
    # =========================================================================
    well_x = 1200.0
    well_y = 600.0
    # Stepped reservoir rim
    spawn_prop("LionWell_Rim_N", unreal.Vector(well_x, well_y + 400.0, 50.0), unreal.Rotator(0, 0, 0), unreal.Vector(9.0, 1.0, 1.0))
    spawn_prop("LionWell_Rim_S", unreal.Vector(well_x, well_y - 400.0, 50.0), unreal.Rotator(0, 0, 0), unreal.Vector(9.0, 1.0, 1.0))
    spawn_prop("LionWell_Rim_E", unreal.Vector(well_x + 400.0, well_y, 50.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 9.0, 1.0))
    spawn_prop("LionWell_Rim_W", unreal.Vector(well_x - 400.0, well_y, 50.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 9.0, 1.0))
    # Sluice Gate Portals
    for s_idx, (s_ox, s_tag) in enumerate([(-220.0, "Gate1_Intake"), (0.0, "Gate2_Bypass"), (220.0, "Gate3_Feeder")]):
        spawn_prop(f"LionWell_{s_tag}_Arch_L", unreal.Vector(well_x + s_ox - 35.0, well_y + 350.0, 90.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, 1.8))
        spawn_prop(f"LionWell_{s_tag}_Arch_R", unreal.Vector(well_x + s_ox + 35.0, well_y + 350.0, 90.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.3, 0.3, 1.8))
        spawn_prop(f"LionWell_{s_tag}_Slab", unreal.Vector(well_x + s_ox, well_y + 350.0, 150.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 0.3, 0.3))
    # Lion Head Fountain Spout
    spawn_prop("LionWell_Pedestal", unreal.Vector(well_x, well_y + 380.0, 120.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.4, 1.4, 1.6))
    spawn_prop("LionWell_LionHead_Spout", unreal.Vector(well_x, well_y + 300.0, 180.0), unreal.Rotator(-20, -90, 0), unreal.Vector(1.0, 1.0, 1.0), cone_mesh)

    # =========================================================================
    # I. COURSE OF FOUR PUZZLE PLATFORM (P01 Stone Alignment)
    # =========================================================================
    p01_x = 800.0
    p01_y = 1500.0
    spawn_prop("P01_Platform", unreal.Vector(p01_x, p01_y, 25.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.0, 8.0, 0.5), cylinder_mesh)
    for p_idx, (p_ox, p_oy, p_tag) in enumerate([(-180.0, -180.0, "G1"), (180.0, -180.0, "G2"), (-180.0, 180.0, "G3"), (180.0, 180.0, "G4")]):
        spawn_prop(f"P01_Stone_{p_tag}_Plinth", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 50.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.4, 1.4, 0.5))
        spawn_prop(f"P01_Stone_{p_tag}_Shaft", unreal.Vector(p01_x + p_ox, p01_y + p_oy, 120.0), unreal.Rotator(0, (p_idx * 45), 0), unreal.Vector(0.8, 0.8, 1.8), cylinder_mesh)

    # =========================================================================
    # J. TROPICAL PALM TREES (PERIMETER & GREENERY)
    # =========================================================================
    palm_locations = [
        (1800.0, -400.0), (1900.0, 200.0), (1850.0, 800.0), 
        (-1800.0, -600.0), (-2000.0, 0.0), (-1900.0, 1000.0)
    ]
    for p_idx, (px, py) in enumerate(palm_locations):
        # Trunk
        spawn_prop(f"Palm_Trunk_{p_idx+1}", unreal.Vector(px, py, 250.0), unreal.Rotator(4, 0, 0), unreal.Vector(0.4, 0.4, 5.0), cylinder_mesh)
        # Palm Canopy Fronds
        spawn_prop(f"Palm_Canopy_{p_idx+1}", unreal.Vector(px, py, 500.0), unreal.Rotator(180, 0, 0), unreal.Vector(3.5, 3.5, 1.2), cone_mesh)

    # =========================================================================
    # K. IN-WORLD DOCUMENTARY EVIDENCE CARDS (MATCHING CONCEPT ANIMATIC EXACTLY!)
    # =========================================================================
    gold_color = unreal.Color(235, 185, 50, 255)
    silver_color = unreal.Color(210, 215, 220, 255)

    # 1. Scaffolding Evidence Tag
    spawn_evidence_tag("EvidenceTag_Scaffolding", 
                       "[RECONSTRUCTED]\nupper courses shown unfinished\n(Scaffolding & Timber Trestles)", 
                       unreal.Vector(vimana_x, vimana_y - scaffold_w - 100.0, scaffold_base_z + 800.0), silver_color, 65.0)

    # 2. Main Temple Historical Attestation Tag
    spawn_evidence_tag("EvidenceTag_VimanaHistorical", 
                       "[HISTORICALLY ATTESTED]\nBrihadisvara Temple site (Doc 03 C2)\nBuilt c. 1025-1035 CE", 
                       unreal.Vector(vimana_x, vimana_y - 1200.0, 1200.0), gold_color, 75.0)

    # 3. Construction Ramp Layout Tag
    spawn_evidence_tag("EvidenceTag_ConstructionRamp", 
                       "[FICTIONALIZED FOR VERTICAL SLICE]\nconstruction-phase earthen ramp layout", 
                       unreal.Vector(ramp_start_x + 300.0, ramp_start_y, 450.0), silver_color, 55.0)

    # 4. Quest Objective floating in world
    spawn_evidence_tag("QuestPrompt_MeetArchitect", 
                       "QUEST: Meet the Architect\nQ3 * Historical basis: [FICTIONAL] scene on [DOCUMENTED] site", 
                       unreal.Vector(0.0, -400.0, 300.0), unreal.Color(255, 255, 255, 255), 50.0)

    # =========================================================================
    # L. PLAYER START & ENTRANCE GUEST CHARACTER
    # =========================================================================
    player_loc = unreal.Vector(0.0, -800.0, 20.0)
    player_start = editor_actor_subsystem.spawn_actor_from_class(unreal.PlayerStart, player_loc)
    if player_start:
        player_start.set_actor_label("PlayerStart_Main")
        player_start.set_actor_rotation(unreal.Rotator(0, 90, 0), False) # Facing North toward Temple & Ramp

    # Place a 3D animated character actor right at PlayerStart so it's visible in editor viewport!
    bp_char_cls = unreal.load_class(None, "/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C")
    if bp_char_cls:
        editor_actor_subsystem.spawn_actor_from_class(bp_char_cls, unreal.Vector(0.0, -750.0, 20.0))
        unreal.log("Spawned BP_ThirdPersonCharacter at start position.")
    else:
        spawn_mannequin("Player_Mannequin_Preview", unreal.Vector(0.0, -750.0, 20.0), unreal.Rotator(0, 90, 0), manny_mesh)

    # Save Level
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== AUTHENTIC ZONE 5 SITE SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    build_authentic_zone5_site()
