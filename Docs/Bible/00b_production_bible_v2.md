# GANGAIKONDA — Production Bible, Volume 2

Covers: Quest Bible (vertical slice) · Puzzle Bible · Art Direction · Audio Bible · UI/UX Guide · Technical Design Document · Unreal Project Structure · Production Roadmap · QA Plan · Localization Plan · Cinematic Script (opening) · Trailer Script

This volume builds directly on the **Foundation Bible (v1)** — historical tags (DOCUMENTED / PLAUSIBLE RECONSTRUCTION / FICTIONAL) carry over unchanged. Where a deliverable below is a *framework* rather than exhaustive content (the Puzzle Bible especially), that's flagged, since some of these are genuinely book-length on their own and deserve a dedicated pass once the team validates direction.

---

## 1. QUEST BIBLE — Vertical Slice

Ten-beat slice, Gangaikondacholapuram construction zone, ~35–40 min target.

### Q1 — Arrival
- **Historical basis:** DOCUMENTED (site location, general nature of an active 11th-c. construction settlement) / FICTIONAL (specific scene)
- **Location:** Approach road into the construction zone
- **Characters:** Arulan (player), background NPCs (surveyors, laborers)
- **Objective:** Traverse to the settlement gate
- **Gameplay:** Open traversal, establishes movement/camera, ambient NPC barks establish world tone
- **Dialogue:** None critical-path; environmental
- **Reward:** None (tutorial beat)

### Q2 — The Inscription
- **Historical basis:** DOCUMENTED (Chola inscriptional practice); FICTIONAL (this specific inscription/object)
- **Location:** Temple foundation site
- **Characters:** Arulan, introduces the Scholar
- **Objective:** Locate and scan a partially buried inscription stone
- **Gameplay:** Investigation system — scan/compare/decode intro
- **Puzzle:** Inscription Decoding Tier 1 (see Puzzle Bible §2.4)
- **Reward:** First Historical Codex entry unlock; Scholar becomes a recurring contact

### Q3 — The Architect
- **Historical basis:** PLAUSIBLE RECONSTRUCTION (role existed; individual is fictional)
- **Location:** Site office / planning pavilion
- **Objective:** Meet the Architect, receive the temple construction objective
- **Gameplay:** Dialogue system, first branching choice (trust the Architect's plan vs. question a design decision — cosmetic branch, no lockout)
- **Reward:** Unlocks Act 7 area (temple construction zone)

### Q4 — The Water Puzzle
- **Historical basis:** PLAUSIBLE RECONSTRUCTION (hydraulic system existed; specific mechanism is FICTIONAL gameplay abstraction)
- **Location:** Reservoir / channel network
- **Objective:** Restore water flow to the construction site
- **Puzzle:** Lion Well puzzle, stages 1–4 of 6 (see Puzzle Bible §2.2)
- **Reward:** Access to hidden inscription (feeds Q9)

### Q5 — Temple Construction
- **Historical basis:** DOCUMENTED (Brihadisvara Temple, Gangaikondacholapuram)
- **Location:** Temple superstructure scaffolding
- **Objective:** Observe/assist stone-placement work; establishes Stone Alignment puzzle system
- **Puzzle:** Stone Alignment Tier 1 (see Puzzle Bible §2.1)
- **Gameplay:** Vertical traversal across scaffolding, environmental storytelling (sculptors at work)

### Q6 — The Conspiracy
- **Historical basis:** FICTIONAL
- **Location:** Site office, storage yards
- **Objective:** Investigate irregularities in resource allocation (planted evidence pointing toward the antagonist's faction)
- **Gameplay:** Investigation/deduction puzzle — cross-reference ledgers, witness statements, physical evidence
- **Design note:** This is the moral-ambiguity seed — evidence should be genuinely mixed, not conclusively damning, per your antagonist design brief

### Q7 — The Ambush
- **Historical basis:** FICTIONAL
- **Location:** Transit route back toward the settlement core
- **Objective:** Survive an ambush tied to the conspiracy thread
- **Gameplay:** Combat/stealth hybrid encounter, first real combat gate
- **Design note:** Keep grounded — no supernatural elements, period-appropriate weapons only

### Q8 — Return to the City
- **Location:** Settlement core
- **Objective:** Report findings; second branching choice (report to the Architect immediately vs. gather more evidence first)
- **Gameplay:** Consequence-light branch that colors later relationship state, not a hard fork

### Q9 — The Historical Codex
- **Objective:** Return to the Scholar with all inscription/evidence fragments gathered in Q2/Q4/Q6
- **Gameplay:** Codex assembly — player actively compiles evidence into the Royal Archive UI
- **Reward:** Full Historical Codex entry for Gangaikondacholapuram unlocked, tagged per source type

### Q10 — Cinematic Ending (slice)
- **Objective:** None — cutscene
- **Content:** Player character overlooks the construction site at dusk; the temple silhouette is visible but unfinished, contrasting with the finished vision seeded in the Act 1 opening. Sets up the game's larger arc.

**Vertical slice validates:** investigation/inscription loop, one puzzle type per pillar (stone, water, deduction), one combat encounter, one dialogue branch, codex system, environmental storytelling density — matching your original ten proof points.

---

## 2. PUZZLE BIBLE (framework + fully-specced starter set)

**Scope note:** fifty distinct, non-repetitive, story-serving puzzles is a genuine multi-week design pass on its own — building all fifty at real mechanical depth here would produce shallow, interchangeable filler, which is exactly what your brief says to avoid ("avoid arbitrary video game puzzles"). Below is the *design framework* for all fifteen of your categories, with 8 puzzles fully specced end-to-end as templates. Recommend the Puzzle Designer role expands each category to 3–4 instances using these as the pattern.

### Design framework (applies to every puzzle)
Every puzzle must answer, before it's built:
1. What real historical knowledge or craft does this puzzle simulate?
2. What does solving it teach the player about the Chola world?
3. Why does *this puzzle* sit *here* in the story — what would be lost if it were moved?

If a puzzle can't answer all three, it's filler and should be cut.

### 2.1 Stone Alignment Puzzle (Category 1 & 3: architecture / temple geometry)
- **Simulates:** load-bearing stone-on-stone construction without mortar, a real Dravidian technique
- **Mechanic:** player selects granite blocks and must orient them so weight distributes through contact points rather than tension; wrong placement visibly stresses/cracks the structure
- **Tiers:** Tier 1 (single course, 4 blocks) → Tier 3 (full vimana section, load paths interact across multiple courses)
- **Story placement:** Act 7, escalates with the temple's construction progress — later tiers unlock as more of the temple is "built"

### 2.2 The Lion Well (Category 2: water engineering)
- **Simulates:** gravity-fed irrigation/reservoir hydraulics
- **Mechanic:** identify water source elevation → open/close stone sluice gates in correct sequence → observe flow reach target channel → repeat with added complexity (silt blockage, competing channels)
- **6 stages** as in your original outline; stages 5–6 (reveal hidden inscription) reward full completion
- **Story placement:** Act 8, gated by Q4 in vertical slice

### 2.3 Royal Seal Verification (Category 8: royal seals)
- **Simulates:** how royal grants/inscriptions were authenticated via seal iconography and script conventions
- **Mechanic:** player compares a disputed document's seal against known-authentic reference seals in the archive, spotting era-inconsistent details (anachronistic script forms, wrong regnal titulature)
- **Story placement:** feeds the Q6 conspiracy thread — a forged or altered document becomes a real story clue, not a standalone brain-teaser

### 2.4 Inscription Decoding, Tier 1 (Category 4/5: inscription + Tamil/Sanskrit terminology)
- **Simulates:** epigraphic reading — worn stone, partial characters, period script variation
- **Mechanic:** player reconstructs a damaged inscription line by matching visible character fragments against a reference script chart the Scholar provides; later tiers require cross-referencing multiple partial inscriptions to reconstruct one full record
- **Story placement:** Q2 in the slice; recurring system throughout the game, difficulty scales with region/era

### 2.5 Trade Ledger Reconciliation (Category 10: trade-route puzzles)
- **Simulates:** merchant guild record-keeping (Ainnurruvar-style associations)
- **Mechanic:** player cross-references cargo manifests, port taxes, and guild seals to identify a discrepancy — teaches the player how Chola-era maritime trade was actually administered
- **Story placement:** Act 11, ties into a merchant-character subquest

### 2.6 Star-Sight Navigation (Category 6/7: navigation + astronomy-inspired)
- **Simulates:** pre-compass celestial/coastal navigation
- **Mechanic:** at night, align the ship's heading using named stars and coastline silhouette recognition rather than a modern compass UI
- **Story placement:** Act 11 naval traversal, recurring light mechanic rather than one-off

### 2.7 Map Reconstruction from Fragments (Category 9)
- **Simulates:** how historians piece together historical geography from partial/damaged sources
- **Mechanic:** player assembles a torn regional map from recovered fragments, cross-checking against known landmarks (temples, rivers) to resolve ambiguous pieces
- **Story placement:** unlocks new explorable map regions — mechanically ties puzzle-solving directly to world traversal, not just a reward screen

### 2.8 Elevation & Load Deduction (Category 11/13: mechanical engineering + logic)
- **Simulates:** how period engineers moved multi-ton stone blocks using ramps, levers, and rollers
- **Mechanic:** player sequences a set of period-appropriate tools (no pulleys beyond attested tech, no anachronisms) to move a block from quarry to construction site across obstacles
- **Story placement:** Act 6, construction-phase gameplay loop

**Remaining categories (Environmental, Historical Deduction, Pattern Recognition) should be built as variants of 2.3–2.8 rather than wholly new systems** — deduction and pattern recognition especially should mostly *be* the inscription/ledger/seal systems reskinned to new evidence, so the player's skills compound rather than resetting every act.

---

## 3. ART DIRECTION GUIDE (condensed)

- **Architecture reference:** Dravidian vimana/gopura forms, granite construction, Brihadisvara Thanjavur & Gangaikondacholapuram as primary references — pull directly from ASI/UNESCO photogrammetry where licensable, otherwise build from published academic architectural surveys, not from other games
- **Material palette:** granite grey/rose, weathered bronze-green patina on finished bronzes vs. bright bronze on newly cast pieces (useful gameplay signal for "recently made" vs. "ancient" objects), unbleached cotton/silk textiles, terracotta
- **Lighting doctrine:** motivate every light source in-world (oil lamps, torches, sun angle, monsoon cloud cover) — no unmotivated fantasy glow, including on "magical-feeling" moments like the Ganga cinematic, which should be sold through composition and sound, not VFX
- **Color discipline:** earth/stone/bronze/deep red/gold/water-blue as your base — gold should read as a *material*, used sparingly on finished bronze icons and royal regalia, never as an ambient color wash. This is the single easiest way to visually distance the game from generic "ancient India = everything gold" fantasy aesthetics
- **Scale storytelling:** Gangaikondacholapuram should visually read as *under construction* for most of the game — scaffolding, incomplete gopurams, stone dust — so its Act 12 "living city" state lands as an earned payoff, not a static backdrop

## 4. AUDIO BIBLE (condensed)

- **Instrumentation:** period-appropriate South Indian instrument families — percussion (mridangam/thavil-style), winds (nadaswaram-style), strings — used as motific palette, not literal temple-recording samples, to avoid misrepresenting living religious practice as generic game music
- **Diegetic priority:** market ambience, stonework, metalworking, water, temple bells should carry as much emotional weight as score — Act 4 (The Ganga) explicitly calls for near-silence over score, per your own direction; that should be the audio thesis for the whole game's biggest beats
- **Score restraint rule:** score swells are earned at named landmark reveals and the three ending variants only — everyday exploration should lean on ambience and light motific fragments, not continuous underscore

## 5. UI/UX GUIDE (condensed)

- **HUD minimalism:** health/stamina/map/quest/archive/inventory only, no persistent clutter; historical discovery notifications use the exact template you specified (Source / Date-period / Confidence / Description) as a locked, non-negotiable format across the entire game — this is your core trust mechanic with the player
- **Codex distinction:** DOCUMENTED entries get a solid border treatment; RECONSTRUCTED get a dashed/hatched treatment; FICTIONALIZED get a distinct third visual (e.g., desaturated or differently colored header) — the player should be able to tell the category at a glance without reading

## 6. TECHNICAL DESIGN DOCUMENT (outline)

- **Engine:** UE5 — Nanite for stone/architectural detail density, Lumen for the lighting-doctrine above, World Partition for the open Gangaikondacholapuram + surrounding region streaming, Mass Entity for crowd-scale NPC routines (markets, construction sites), Gameplay Ability System for combat/puzzle-interaction abstraction, Chaos for stone-block physics in the alignment puzzles
- **Modular architecture** per your outline (Character / Combat / Exploration / Puzzle / Quest / Dialogue / Inventory / Historical Codex / World / AI / Navigation / Weather / Maritime / Save / UI / Audio) — recommend Historical Codex be its own top-level module (not folded into UI or Quest) since it's queried by almost every other system
- **Data-driven history:** the Historical Evidence Database should live as structured data (DataTables/DataAssets), not hardcoded strings, so historians/consultants can review and revise entries without engineering involvement — this matters given how much of your design depends on getting the sourcing right

## 7. PRODUCTION ROADMAP (high-level)

| Phase | Focus | Gate to proceed |
|---|---|---|
| 1–4 | Historical research, World/Story/Character bibles | Historical Research Director + consultants sign off on Evidence Database |
| 5–6 | Gameplay prototype → vertical slice | All 10 slice beats playable and prove the 10 pillars listed in the Foundation Bible |
| 7–13 | Environment, quests, combat, naval, puzzles, cinematics, VO | Each system validated against the vertical slice pattern before scaling |
| 14–16 | Optimization, QA, historical review pass | Second full historical accuracy review before content lock |
| 17 | Release | — |

## 8. QA PLAN (condensed)
Beyond standard functional/regression QA: a dedicated **historical-accuracy QA pass**, separate from bug QA, run by the Historical Authenticity Consultant against every Codex entry and every on-screen historical claim, checked against the Evidence Database sourcing — this should be a release-blocking gate, not a nice-to-have.

## 9. LOCALIZATION PLAN (condensed)
Tamil and English as day-one priority languages given subject matter and audience; Sanskrit used only where historically motivated (per your rule against overuse). Recommend Tamil-language historical consultants review localized Codex text specifically, since mistranslation risk is highest in the historical-claim text, not general dialogue.

---

## 10. CINEMATIC SCRIPT — Opening Sequence

**FADE IN.**

EXT. THANJAVUR — DAWN

Mist over stone. The great temple tower rises out of it, gradually resolving as the sun clears the horizon.

SOUND: distant temple bells, the murmur of a waking city, stone chisels beginning their day's work.

We drift low over rooftops — a market being set up, oxen carts, a line of soldiers moving in formation toward the palace gate.

CUT TO: ARULAN, walking into frame from a side street, entering the city proper. We stay behind him — this is our introduction to the world through his eyes, not an omniscient establishing shot.

Arulan passes:
- stone sculptors mid-carving, unbothered by the crowd
- a bronze caster's workshop, heat shimmer visible
- two scribes arguing over a ledger

ARULAN (overhearing, half to himself)
Another shipment delayed. Third this month.

He continues toward the temple square. A group of craftsmen are gathered, talking in low, urgent tones.

CRAFTSMAN 1 (O.S.)
They say the army marches again. North, this time. Further than before.

Arulan slows, listening.

A ROYAL MESSENGER on horseback cuts through the square at speed, scattering pedestrians, heading for the palace.

The camera holds on Arulan's face — curiosity, not certainty — as he watches the messenger go.

SLOW PUSH IN on the temple tower behind him, gold catching the now-full sunlight.

CUT TO BLACK.

TITLE CARD:
**GANGAIKONDA**
गङ्गैकोण्ड

*(hold, fade)*

---

## 11. TRAILER SCRIPT (60–90 sec cut)

0:00–0:10 — Black. Sound only: chisel on stone, water, distant bell. First image: a hand tracing an inscription.

0:10–0:25 — Rapid, quiet montage: temple construction, market life, a ship leaving port, soldiers marching — no dialogue, only ambient sound and a single low string motif entering.

0:25–0:35 — Arulan, in silhouette, looking out over the unfinished Gangaikondacholapuram site. First VO line:

ARULAN (V.O.)
They say an empire is remembered in stone.

0:35–0:50 — Faster cuts: puzzle moment (stone alignment), combat flash, the Ganga cinematic image, a tense dialogue close-up with the Scholar.

0:50–1:05 — Score swells. Title card reveal: **GANGAIKONDA**. Subtitle: *The City of the Conqueror of the Ganges*.

1:05–1:15 — Final beat: the completed temple silhouette against dusk, then a slow dissolve to the *real* modern archaeological ruins of the site.

TEXT ON SCREEN: *"Stone remembers."*

Logo card. Release window TBD.

---

## What's still open

Genuinely deep passes still owed: the full 50-puzzle catalog, the complete Quest Bible beyond the vertical slice, the three branching endings written out, and a full World Bible region-by-region. Say which one and I'll take it as far as it needs to go.
