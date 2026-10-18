import unreal

def build_temple_compound():
    unreal.log("=== CONSTRUCTING GANGAIKONDACHOLAPURAM ZONE 5 TEMPLE COMPOUND ===")
    level_path = "/Game/Maps/Test_Zone5_Greybox"
    
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    
    level_editor_subsystem.load_level(level_path)
    
    cube_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
    cylinder_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
    cone_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cone.Cone")
    
    def spawn_mesh(label, loc, rot, scale, mesh=cube_mesh):
        actor = editor_actor_subsystem.spawn_actor_from_class(unreal.StaticMeshActor, loc)
        if actor:
            actor.set_actor_label(label)
            actor.set_actor_rotation(rot, False)
            if mesh:
                actor.static_mesh_component.set_static_mesh(mesh)
            actor.set_actor_scale3d(scale)
        return actor

    # =========================================================================
    # 1. TEMPLE VIMANA (Great Pyramidal Tower - 7 Tiers)
    # =========================================================================
    vimana_center = unreal.Vector(0.0, 2000.0, 0.0)
    tier_sizes = [
        (24.0, 24.0, 3.0),   # Base plinth (24m x 24m)
        (20.0, 20.0, 2.5),   # Tier 1
        (16.0, 16.0, 2.5),   # Tier 2
        (12.0, 12.0, 2.5),   # Tier 3
        (9.0, 9.0, 2.0),     # Tier 4
        (6.0, 6.0, 2.0),     # Tier 5
        (4.0, 4.0, 2.0),     # Tier 6
    ]
    
    current_z = 0.0
    for idx, (sx, sy, sz) in enumerate(tier_sizes):
        loc = unreal.Vector(vimana_center.x, vimana_center.y, current_z + (sz * 50.0))
        spawn_mesh(f"Vimana_Tier_{idx+1}", loc, unreal.Rotator(0, 0, 0), unreal.Vector(sx, sy, sz))
        current_z += sz * 100.0

    # Crowning Shikhara (Dome / Finial)
    spawn_mesh("Vimana_Shikhara", unreal.Vector(vimana_center.x, vimana_center.y, current_z + 150.0), 
               unreal.Rotator(0, 0, 0), unreal.Vector(3.0, 3.0, 3.0), cone_mesh)

    # Sanctum Entrance & Pillars (Mukhamandapa)
    entrance_y = vimana_center.y - 1400.0
    spawn_mesh("Sanctum_Lintel", unreal.Vector(0.0, entrance_y, 400.0), unreal.Rotator(0, 0, 0), unreal.Vector(8.0, 1.5, 1.0))
    spawn_mesh("Sanctum_Pillar_L", unreal.Vector(-350.0, entrance_y, 200.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 1.0, 4.0), cylinder_mesh)
    spawn_mesh("Sanctum_Pillar_R", unreal.Vector(350.0, entrance_y, 200.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 1.0, 4.0), cylinder_mesh)

    # =========================================================================
    # 2. COLUMNED MANDAPA CORRIDOR (Processional Pathway)
    # =========================================================================
    for row in range(5):
        y_pos = -200.0 + (row * 300.0)
        # Left column
        spawn_mesh(f"Mandapa_Pillar_L_{row}", unreal.Vector(-500.0, y_pos, 150.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.8, 0.8, 3.0), cylinder_mesh)
        # Right column
        spawn_mesh(f"Mandapa_Pillar_R_{row}", unreal.Vector(500.0, y_pos, 150.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.8, 0.8, 3.0), cylinder_mesh)
        # Cross-beam
        spawn_mesh(f"Mandapa_Beam_{row}", unreal.Vector(0.0, y_pos, 320.0), unreal.Rotator(0, 0, 0), unreal.Vector(11.0, 0.8, 0.5))

    # =========================================================================
    # 3. LION WELL STEPWELL COMPLEX (P04 Hydraulic Sluice Basin)
    # =========================================================================
    well_center = unreal.Vector(1200.0, 500.0, 0.0)
    # Stepped pit basin
    spawn_mesh("LionWell_Rim_North", unreal.Vector(well_center.x, well_center.y + 450.0, 60.0), unreal.Rotator(0, 0, 0), unreal.Vector(10.0, 1.0, 1.2))
    spawn_mesh("LionWell_Rim_South", unreal.Vector(well_center.x, well_center.y - 450.0, 60.0), unreal.Rotator(0, 0, 0), unreal.Vector(10.0, 1.0, 1.2))
    spawn_mesh("LionWell_Rim_East", unreal.Vector(well_center.x + 450.0, well_center.y, 60.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 10.0, 1.2))
    spawn_mesh("LionWell_Rim_West", unreal.Vector(well_center.x - 450.0, well_center.y, 60.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 10.0, 1.2))
    
    # 3 Sluice Gate Stone Portals
    gate_offsets = [(-250.0, "Gate_01_Intake"), (0.0, "Gate_02_Bypass"), (250.0, "Gate_03_Feeder")]
    for offset_x, gate_tag in gate_offsets:
        gate_loc = unreal.Vector(well_center.x + offset_x, well_center.y + 350.0, 120.0)
        spawn_mesh(f"{gate_tag}_Arch_L", unreal.Vector(gate_loc.x - 40.0, gate_loc.y, 80.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.4, 0.4, 1.6))
        spawn_mesh(f"{gate_tag}_Arch_R", unreal.Vector(gate_loc.x + 40.0, gate_loc.y, 80.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.4, 0.4, 1.6))
        spawn_mesh(f"{gate_tag}_Slab", unreal.Vector(gate_loc.x, gate_loc.y, 160.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.2, 0.4, 0.3))

    # Sculpted Lion Head Spout Mockup
    spawn_mesh("LionWell_Head_Pedestal", unreal.Vector(well_center.x, well_center.y + 400.0, 150.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.5, 1.5, 2.0))
    spawn_mesh("LionWell_LionHead_Sculpture", unreal.Vector(well_center.x, well_center.y + 300.0, 220.0), unreal.Rotator(-20, -90, 0), unreal.Vector(1.2, 1.2, 1.2), cone_mesh)

    # =========================================================================
    # 4. COURSE OF FOUR PUZZLE PLATFORM (P01 Stone Alignment Plinths)
    # =========================================================================
    p01_center = unreal.Vector(-1200.0, 500.0, 0.0)
    # Circular puzzle platform
    spawn_mesh("P01_Platform_Base", unreal.Vector(p01_center.x, p01_center.y, 25.0), unreal.Rotator(0, 0, 0), unreal.Vector(10.0, 10.0, 0.5), cylinder_mesh)
    
    # 4 Granite Pillars to Rotate
    stone_positions = [
        (-250.0, -250.0, "Stone_0_G1"),
        (250.0, -250.0, "Stone_1_G2"),
        (-250.0, 250.0, "Stone_2_G3"),
        (250.0, 250.0, "Stone_3_G4")
    ]
    for ox, oy, tag in stone_positions:
        plinth_loc = unreal.Vector(p01_center.x + ox, p01_center.y + oy, 50.0)
        # Stepped plinth
        spawn_mesh(f"{tag}_Plinth", plinth_loc, unreal.Rotator(0, 0, 0), unreal.Vector(1.8, 1.8, 0.6))
        # Inscribed Stone Shaft
        spawn_mesh(f"{tag}_Shaft", unreal.Vector(plinth_loc.x, plinth_loc.y, 140.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 1.0, 2.2), cylinder_mesh)

    # =========================================================================
    # 5. PERIMETER COURTYARD WALLS & GOPURAM ENTRANCE
    # =========================================================================
    wall_z = 200.0
    wall_h = 4.0
    # North wall (behind vimana)
    spawn_mesh("Wall_North", unreal.Vector(0.0, 3200.0, wall_z), unreal.Rotator(0, 0, 0), unreal.Vector(40.0, 1.0, wall_h))
    # East wall
    spawn_mesh("Wall_East", unreal.Vector(2000.0, 800.0, wall_z), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 48.0, wall_h))
    # West wall
    spawn_mesh("Wall_West", unreal.Vector(-2000.0, 800.0, wall_z), unreal.Rotator(0, 0, 0), unreal.Vector(1.0, 48.0, wall_h))
    # South Gate (Gopuram Entrance flanks)
    spawn_mesh("Wall_South_L", unreal.Vector(-1200.0, -1200.0, wall_z), unreal.Rotator(0, 0, 0), unreal.Vector(16.0, 1.0, wall_h))
    spawn_mesh("Wall_South_R", unreal.Vector(1200.0, -1200.0, wall_z), unreal.Rotator(0, 0, 0), unreal.Vector(16.0, 1.0, wall_h))
    # Gopuram Gateway Towers
    spawn_mesh("Gopuram_Tower_L", unreal.Vector(-300.0, -1200.0, 450.0), unreal.Rotator(0, 0, 0), unreal.Vector(3.0, 3.0, 9.0))
    spawn_mesh("Gopuram_Tower_R", unreal.Vector(300.0, -1200.0, 450.0), unreal.Rotator(0, 0, 0), unreal.Vector(3.0, 3.0, 9.0))
    spawn_mesh("Gopuram_Gable", unreal.Vector(0.0, -1200.0, 850.0), unreal.Rotator(0, 0, 0), unreal.Vector(7.0, 3.2, 1.5))

    # =========================================================================
    # 6. ARCHAEOLOGICAL / ROYAL SCHOLAR ARCHIVE TENTS & WORKSTATIONS
    # =========================================================================
    tent_loc = unreal.Vector(-800.0, -400.0, 0.0)
    spawn_mesh("Scholar_Pavilion_Roof", unreal.Vector(tent_loc.x, tent_loc.y, 240.0), unreal.Rotator(0, 45, 0), unreal.Vector(4.5, 4.5, 1.0), cone_mesh)
    spawn_mesh("Scholar_Pavilion_Post1", unreal.Vector(tent_loc.x - 150.0, tent_loc.y - 150.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_mesh("Scholar_Pavilion_Post2", unreal.Vector(tent_loc.x + 150.0, tent_loc.y - 150.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_mesh("Scholar_Pavilion_Post3", unreal.Vector(tent_loc.x - 150.0, tent_loc.y + 150.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_mesh("Scholar_Pavilion_Post4", unreal.Vector(tent_loc.x + 150.0, tent_loc.y + 150.0, 100.0), unreal.Rotator(0, 0, 0), unreal.Vector(0.2, 0.2, 2.0), cylinder_mesh)
    spawn_mesh("Scholar_Scribe_Table", unreal.Vector(tent_loc.x, tent_loc.y, 45.0), unreal.Rotator(0, 0, 0), unreal.Vector(1.8, 1.0, 0.8))

    # Save Level
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== GANGAIKONDACHOLAPURAM TEMPLE COMPOUND BUILT & SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    build_temple_compound()
