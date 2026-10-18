import unreal

def build_greybox_level():
    unreal.log("=== POPULATING ZONE 5 GREYBOX LEVEL ===")
    level_path = "/Game/Maps/Test_Zone5_Greybox"
    
    # 1. Load the existing level
    level_editor_subsystem = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    editor_actor_subsystem = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    
    loaded = level_editor_subsystem.load_level(level_path)
    unreal.log(f"Loaded existing level '{level_path}': {loaded}")
    
    # Get existing actor labels to avoid duplicates
    existing_actors = editor_actor_subsystem.get_all_level_actors()
    existing_labels = {actor.get_actor_label() for actor in existing_actors if actor}
    unreal.log(f"Existing actors in level: {len(existing_actors)}")

    # 2. Spawn Floor / Arena Platform
    if not any("Floor" in l or "Cube" in l for l in existing_labels):
        floor = editor_actor_subsystem.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0.0, 0.0, -50.0))
        if floor:
            floor.set_actor_label("Floor_GreyboxArena")
            cube_mesh = unreal.EditorAssetLibrary.load_asset("/Engine/BasicShapes/Cube.Cube")
            if cube_mesh:
                floor.static_mesh_component.set_static_mesh(cube_mesh)
            floor.set_actor_scale3d(unreal.Vector(100.0, 100.0, 1.0)) # 100m x 100m arena
            unreal.log("Spawned 100m arena floor.")

    # 3. Spawn Motivated Sunlight (Directional Light)
    if not any("DirectionalLight" in l or "Sun" in l for l in existing_labels):
        sun = editor_actor_subsystem.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0.0, 0.0, 500.0))
        if sun:
            sun.set_actor_label("DirectionalLight_Sun")
            sun.set_actor_rotation(unreal.Rotator(-45.0, -35.0, 0.0), False)
            sun.light_component.set_editor_property("intensity", 10.0)
            sun.light_component.set_editor_property("atmosphere_sun_light", True)
            unreal.log("Spawned Directional Light (Sun).")

    # 4. Spawn Sky Atmosphere
    if not any("SkyAtmosphere" in l for l in existing_labels):
        sky_atm = editor_actor_subsystem.spawn_actor_from_class(unreal.SkyAtmosphere, unreal.Vector(0.0, 0.0, 500.0))
        if sky_atm:
            sky_atm.set_actor_label("SkyAtmosphere")
            unreal.log("Spawned SkyAtmosphere.")

    # 5. Spawn SkyLight with Real-Time Capture
    if not any("SkyLight" in l for l in existing_labels):
        skylight = editor_actor_subsystem.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0.0, 0.0, 500.0))
        if skylight:
            skylight.set_actor_label("SkyLight_RealTime")
            skylight.light_component.set_editor_property("real_time_capture", True)
            unreal.log("Spawned Real-Time SkyLight.")

    # 6. Spawn Exponential Height Fog
    if not any("ExponentialHeightFog" in l or "Fog" in l for l in existing_labels):
        fog = editor_actor_subsystem.spawn_actor_from_class(unreal.ExponentialHeightFog, unreal.Vector(0.0, 0.0, 100.0))
        if fog:
            fog.set_actor_label("ExponentialHeightFog")
            unreal.log("Spawned ExponentialHeightFog.")

    # 7. Spawn Player Start
    if not any("PlayerStart" in l for l in existing_labels):
        player_start = editor_actor_subsystem.spawn_actor_from_class(unreal.PlayerStart, unreal.Vector(0.0, -800.0, 100.0))
        if player_start:
            player_start.set_actor_label("PlayerStart_Main")
            player_start.set_actor_rotation(unreal.Rotator(0.0, 90.0, 0.0), False)
            unreal.log("Spawned PlayerStart facing North.")

    # 8. Spawn Vertical Slice Gameplay Actors
    # 8a. Lighting Manager Actor
    if not any("GKLightingManager" in l for l in existing_labels):
        lighting_cls = unreal.load_class(None, "/Script/GKWorld.GKLightingManagerActor")
        if lighting_cls:
            light_mgr = editor_actor_subsystem.spawn_actor_from_class(lighting_cls, unreal.Vector(0.0, 0.0, 100.0))
            if light_mgr:
                light_mgr.set_actor_label("GKLightingManagerActor_Zone5")
                unreal.log("Spawned GKLightingManagerActor.")

    # 8b. Lion Well Hydraulic Puzzle Actor
    if not any("GKLionWell" in l for l in existing_labels):
        lion_well_cls = unreal.load_class(None, "/Script/GKPuzzle.GKLionWellPuzzleActor")
        if lion_well_cls:
            lion_well = editor_actor_subsystem.spawn_actor_from_class(lion_well_cls, unreal.Vector(600.0, 400.0, 50.0))
            if lion_well:
                lion_well.set_actor_label("GKLionWellPuzzleActor_P04")
                unreal.log("Spawned GKLionWellPuzzleActor.")

    # 8c. Stone Alignment Course of Four Puzzle Actor
    if not any("GKStoneAlignment" in l for l in existing_labels):
        stone_cls = unreal.load_class(None, "/Script/GKPuzzle.GKStoneAlignmentPuzzleActor")
        if stone_cls:
            stone_align = editor_actor_subsystem.spawn_actor_from_class(stone_cls, unreal.Vector(-600.0, 400.0, 50.0))
            if stone_align:
                stone_align.set_actor_label("GKStoneAlignmentPuzzleActor_P01")
                unreal.log("Spawned GKStoneAlignmentPuzzleActor.")

    # 8d. Ambush Encounter Enemy Character
    if not any("GKEnemyCharacter" in l for l in existing_labels):
        enemy_cls = unreal.load_class(None, "/Script/GKCombat.GKEnemyCharacter")
        if enemy_cls:
            enemy = editor_actor_subsystem.spawn_actor_from_class(enemy_cls, unreal.Vector(0.0, 600.0, 100.0))
            if enemy:
                enemy.set_actor_label("GKEnemyCharacter_AmbushGuard")
                enemy.set_actor_rotation(unreal.Rotator(0.0, -90.0, 0.0), False)
                unreal.log("Spawned GKEnemyCharacter facing player.")

    # 9. Save Level
    saved = level_editor_subsystem.save_current_level()
    unreal.log(f"=== ZONE 5 GREYBOX LEVEL SAVED: {saved} ===")
    return saved

if __name__ == "__main__" or __name__ == "builtins":
    build_greybox_level()
