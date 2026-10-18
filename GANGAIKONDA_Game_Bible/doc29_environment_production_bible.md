# GANGAIKONDA — DOCUMENT 29: ENVIRONMENT PRODUCTION BIBLE

**Document ID:** EPB-29 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Break the World Bible (Doc 02) locations into production zones with modular kit definitions and optimization requirements.
**Dependencies:** Doc 02 (source locations), Doc 16 (architecture detail), Doc 17 (art direction), Doc 18 (World Partition/Nanite/Lumen technical basis).

---

## Production Zone Breakdown

### ZONE 1 — THANJAVUR
- **Biome:** delta urban
- **Architecture:** Doc 16 §2 (established temple architecture)
- **Landmarks:** Rajaraja's Brihadisvara Temple
- **Props:** established/weathered variants only (no "under construction" prop set needed here)
- **NPCs:** Tier 1 (Arulan's Act 1 context), Tier 3 dense background population
- **Lighting:** Doc 17 §5 — established, ceremonial
- **Weather:** dry-season default for Act 1 (narrative timing)
- **Materials:** Doc 17 §3, fully weathered granite finish
- **Sound:** Doc 21 §1 City/Temple categories, "established" acoustic variant
- **Quests:** MQ01–02
- **Puzzles:** Inscription Decoding Tier 0
- **Optimization requirements:** highest NPC density zone outside the living-city state — early Nanite/Mass Entity profiling target (Doc 18 §6 open question)

### ZONE 2 — ROYAL COURT
- **Biome:** interior/courtyard
- **Architecture:** Doc 16 §3
- **Landmarks:** the court audience space (Cinematic 002 setting, pending)
- **Props:** formal furnishings, campaign maps (Act 2 environmental storytelling per Doc 02 §4.2)
- **NPCs:** Tier 1 (Rajendra, court officials), lower Tier 3 density than open city zones
- **Lighting:** filtered courtyard, oil-lamp interior
- **Weather:** not applicable (interior-dominant)
- **Materials:** Doc 17 §3, restrained
- **Sound:** minimal ambient, dialogue-forward acoustic design
- **Quests:** MQ03–04
- **Puzzles:** Royal Seal Verification Tier 0
- **Optimization requirements:** low — small, contained interior space, lower streaming priority than open zones

### ZONE 3 — NORTHERN CORRIDOR
- **Biome:** transitional forest/delta-to-highland, river crossings
- **Architecture:** Doc 16 §9 (temporary military structures)
- **Landmarks:** the river-crossing set-piece (MQ07)
- **Props:** campaign gear, temporary infrastructure
- **NPCs:** Tier 2/3 military population, no dense Tier 1 concentration
- **Lighting:** exterior, full day/night cycle for campaign pacing
- **Weather:** full monsoon-seasonal range — this zone should showcase weather variety most (Doc 17 §6)
- **Materials:** natural terrain-dominant, minimal built material
- **Sound:** Doc 21 §1 Forest/Battle categories
- **Quests:** MQ05–07
- **Puzzles:** river-crossing logistics variant
- **Optimization requirements:** largest linear traversal distance in the game — World Partition streaming is most heavily tested here; recommend early technical spike specifically on this zone's streaming performance

### ZONE 4 — THE GANGA
- **Biome:** riverbank, open
- **Architecture:** none — deliberately unbuilt environment
- **Landmarks:** the river itself
- **Props:** minimal by design (Doc 05 Cinematic 003 restraint principle)
- **NPCs:** minimal, cinematic-only
- **Lighting:** flat overcast (Doc 17 §5's deliberate exception to the motivated-drama-lighting norm)
- **Weather:** overcast, non-dynamic during the cinematic (scripted weather state)
- **Materials:** natural only
- **Sound:** Doc 21 §1 Water category, near-silent mix
- **Quests:** MQ08
- **Puzzles:** none
- **Optimization requirements:** low asset density, but high Lumen/lighting fidelity priority given the scene's visual restraint depends entirely on getting flat-overcast lighting right, not on asset complexity

### ZONE 5 — GANGAIKONDACHOLAPURAM, CONSTRUCTION ZONE
- **Biome:** delta urban, active construction
- **Architecture:** Doc 16 §1 (temple, under construction), §6 (water systems)
- **Landmarks:** the temple construction site, the Lion Well reservoir
- **Props:** the highest-volume prop category in the game — scaffolding, worked/unworked stone at every completion stage (per Doc 17 §9's "props should look used and should change over Acts 6–9" requirement)
- **NPCs:** Tier 1 (Architect, Scholar), Tier 2 (named workers), Tier 3 dense construction-worker population
- **Lighting:** Doc 17 §5, dust/stone-catching light emphasized
- **Weather:** full seasonal range, ties directly to construction-pace narrative pacing (Doc 01 §25)
- **Materials:** Doc 17 §3, mixed weathered/fresh-cut stone per Doc 16 §1's course-age texture requirement
- **Sound:** Doc 21 §1 City (construction-inflected variant)
- **Quests:** MQ11–20 (bulk of main quest content)
- **Puzzles:** Stone Alignment (all tiers), Lion Well (all stages), Elevation & Load Deduction, Royal Seal Verification
- **Optimization requirements:** the single most production-critical zone in the game — needs a dedicated modular kit (§ below) given both its prop volume and its requirement to visually change state across multiple Acts without becoming multiple separate levels

### ZONE 6 — GANGAIKONDACHOLAPURAM, LIVING CITY (same geography as Zone 5, later world-state)
- **Biome/Architecture/Landmarks:** same as Zone 5, completed state
- **Props:** completed-state prop set (scaffolding removed, finished stonework, active market dressing)
- **NPCs:** highest Tier 3 density in the game (Doc 13 §2 living-world showcase)
- **Lighting:** full completed-temple gold-accent treatment (Doc 16 §1)
- **Weather:** full seasonal range
- **Materials:** fully finished granite/bronze
- **Sound:** Doc 21 §1 full City/Temple/Market layering
- **Quests:** MQ26–30
- **Puzzles:** MQ29 capstone, PQ10 optional capstone
- **Optimization requirements:** this zone's technical solution (world-state swap on the same geography, per Doc 18 §6/Doc 19 §3's `UGKWorldStateSubsystem`) is the most technically significant art-production decision in the game — recommend the Technical Artist and World Designer co-own this zone's kit design from day one rather than treating it as "Zone 5 but finished," since asset-swap-at-scale has real implementation cost

### ZONE 7 — PORT (PRIMARY + SECONDARY)
- **Biome:** coastal
- **Architecture:** Doc 16 §10
- **Landmarks:** primary harbor, diplomatic quarter (NQ01), shipyard (NQ06)
- **Props:** cargo, guild office dressing, ship models
- **NPCs:** Tier 1 (Naval Commander, Merchant), Tier 2 (foreign traders), Tier 3 harbor population
- **Lighting:** bright open harbor light
- **Weather:** coastal weather variant, storm state for MQ25
- **Materials:** salt-worn timber/stone
- **Sound:** Doc 21 §1 Ship/Market categories
- **Quests:** MQ23–25, NQ-series
- **Puzzles:** Trade Ledger Reconciliation, Star-Sight Navigation
- **Optimization requirements:** secondary port (NQ07) should reuse Primary port's modular kit with a distinct dressing pass rather than being built as a fully separate asset set — production-cost recommendation

### ZONE 8 — WILDERNESS/TRANSITIONAL
- **Biome:** forest, low-density
- **Architecture:** minimal (SQ12's shrine as the one built landmark)
- **Landmarks:** SQ12 shrine
- **Props:** natural, minimal built
- **NPCs:** none/minimal
- **Lighting:** natural, full dynamic range
- **Weather:** full seasonal range
- **Materials:** natural
- **Sound:** Doc 21 §1 Forest category
- **Quests:** SQ12–13 (optional)
- **Puzzles:** PQ01 (environmental variant)
- **Optimization requirements:** lowest priority zone — good candidate for lower LOD investment given low quest density, per your original "hundreds of villages" scope note from Doc 02 (this zone type is where that recommendation applies)

---

## Modular Environment Kits (production efficiency)

- **Kit A — Delta Urban (Thanjavur base):** reusable for any additional Chola-heartland settlement content
- **Kit B — Construction-in-Progress (Zone 5):** the highest-value kit in the game — scaffolding, stone-course variants at multiple completion stages, worker-camp dressing — should be built with enough modularity to support the Zone 5→6 world-state transition without a full re-build
- **Kit C — Coastal/Port (Zone 7):** reused between primary and secondary ports per the cost recommendation above
- **Kit D — Campaign/Military Temporary (Zone 3):** tents, supply infrastructure, reusable for any additional campaign-context content
- **Kit E — Natural/Wilderness (Zone 8):** lowest-investment kit, high reuse across filler content

---

## Open Questions
- Zone 5→6 world-state transition technical approach (full geometry swap vs. modular piece-by-piece state change) needs a dedicated Technical Artist + Programmer spike — this is the single biggest unresolved production question in the environment art pipeline.
- Whether Zone 3 (Northern Corridor)'s streaming performance needs to be validated before or after the vertical slice, given the vertical slice is scoped to Zone 5 only (Production Bible v2 §1) — recommend after, but flag as a real schedule risk since Zone 3 is structurally very different (large linear traversal vs. Zone 5's contained hub).

## Dependencies on Other Documents
Doc 02 (source locations), Doc 16–17 (architecture/art direction detail per zone), Doc 18 §6 (World Partition, world-state subsystem), Doc 13 §2 (NPC tiering per zone).

## Acceptance Criteria
- All 8 zones (matching Doc 02's location catalog) broken down with all 12 required fields.
- Zone 5/6 relationship explicitly identified as the project's most technically significant environment-production decision, not glossed over.
- Modular kit strategy reduces production cost by explicit reuse (Kit A/C/E) rather than treating every zone as bespoke.
