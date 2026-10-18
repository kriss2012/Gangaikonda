# Zone 5: Gangaikondacholapuram Construction Zone — Greybox Test Map Spec

**Document Reference:** Doc 08 (Vertical Slice Bible), Doc 29 (Environment Production Bible), Doc 34 (Lighting Bible)  
**Map Path:** `/Game/Maps/Test_Zone5_Greybox`

---

## 1. Spatial Layout & Sector Flow (Minutes 0–40)

```
[West] Sector A: Approach Road & Perimeter Gate (Min 0–2)
       │
       ▼
[West-Central] Sector B: Worker Settlement & Scholar's Archive Tent (Min 2–9)
       │
       ├─────────────────────────────────┐
       ▼                                 ▼
[Central] Sector C: Vimana Scaffolding   [North] Sector E: Site Office & Pavilion
(Granite blocks, Climb Volumes) (Min 9–18) (Architect NPC, Ledger investigation) (Min 27–33)
       │                                 │
       ▼                                 ▼
[South-Central] Sector D: Reservoir      [East] Sector F: Ambush Transit Route
(Lion Well sluice gates) (Min 18–23)     (Combat / stealth encounter) (Min 33–37)
                                         │
                                         ▼
                               [Overlook] Sector G: Sunset Archival Vista (Min 38–40)
```

---

## 2. Greybox Actor Placements

### Player Start
- **Location:** `X = -4500.0, Y = 0.0, Z = 50.0`
- **Rotation:** `Yaw = 0.0` (Facing East towards the rising temple silhouette).
- **Spawn Class:** `BP_Arulan` (derived from `AGKPlayerCharacter`).

### Scaffold Climbing Test Rig (`AGKScaffoldVolume`)
- **Actor Class:** `AGKScaffoldVolume`
- **Location:** `X = 0.0, Y = 600.0, Z = 300.0`
- **Box Extents:** `X = 80.0, Y = 160.0, Z = 300.0` (Total height = 600 cm).
- **Facing Normal:** `X = 0.0, Y = -1.0, Z = 0.0` (Facing South towards the staging plaza).
- **Top Platform:** Dressed granite block platform at `Z = 600.0` for testing ledge mantling.

### Foundation Inscription Stone (`AGKTestInvestigatableActor`)
- **Actor Class:** `AGKTestInvestigatableActor`
- **Location:** `X = -500.0, Y = 200.0, Z = 60.0`
- **EvidenceIDToUnlock:** `C1` ("Gangaikondacholapuram was founded as a new imperial capital...")
- **Prompt:** `[E] Inspect Foundation Inscription`

---

## 3. Lighting & Atmosphere (Doc 34 Compliance)
- **Sun / Directional Light:** Motivated late-morning sun (`Pitch = -32.0`, `Yaw = 55.0`), warm 5200K temperature.
- **Sky Light / Lumen:** Indirect diffuse bouncing off warm sandstone/granite surfaces.
- **Atmospheric Fog:** Subtle airborne limestone/granite quarry dust shafts.
- **Zero Fantasy VFX:** Strictly grounded lighting without magical glow or neon highlights.
