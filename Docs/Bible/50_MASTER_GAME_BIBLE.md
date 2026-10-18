# GANGAIKONDA — DOCUMENT 50: MASTER GAME BIBLE

**The City of the Conqueror of the Ganges** · *"An Empire Is Remembered. A Legacy Is Built."*

**Version:** 1.0 · **Status:** Consolidated source of truth (compiled from all documents below)

## How to use this
This master file contains the full text of every document in this package, in order. Individual files are also provided separately. Where documents differ in depth, the Open Questions in each file mark what still needs expansion by the owning department.

## Canonical Principles
- Historical spine unchanged: Rajaraja I → Rajendra I → Northern Expedition → Gangaikonda Chola identity → Gangaikondacholapuram → Brihadisvara Temple → water systems → administration → trade/maritime → legacy.
- Every claim tagged [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL]; confidence tiers KNOWN/LIKELY/UNCERTAIN/UNKNOWN.
- No fabricated quotes, inscriptions, or fictional-as-historical content. Position statement: *historically grounded historical fiction.*
- Player choices change Arulan's story only; history never changes.

## Known Open Items (cross-document)
1. Tamil linguistic authenticity review of all fictional names (blocks Docs 22, VO casting).
2. Evidence gaps: ships (Doc 03 E4), armor (I3), city layout (C4), festivals, clothing/material culture.
3. Zone 5→6 world-state swap and NPC memory serialization technical spikes.
4. Remaining content volume: full 50 puzzles (20 specified), side/discovery/puzzle/naval/scholar quest counts (partial), cinematics 2/5/6/8/9/11/endings 2–3 shot lists.
5. Cultural Sensitivity review: clothing, temple/religious audio, foreign-trader depiction.

## Table of Contents
1. 00_foundation_bible_v1.md
2. 00b_production_bible_v2.md
3. doc01_game_design_document.md
4. doc02_world_bible.md
5. doc03_historical_research_bible.md
6. doc04_story_bible.md
7. doc05_cinematic_script.md
8. doc06_character_bible.md
9. doc07a_quest_bible_main_quests.md
10. doc07b_quest_bible_side_quests.md
11. doc07c_quest_bible_historical_discovery.md
12. doc07d_quest_bible_puzzle_quests.md
13. doc07e_quest_bible_naval_quests.md
14. doc07f_quest_bible_scholar_archive_quests.md
15. doc08_vertical_slice_bible.md
16. doc09_puzzle_bible.md
17. doc10_combat_design_bible.md
18. doc11_stealth_investigation_bible.md
19. doc12_naval_design_bible.md
20. doc13_npc_ai_bible.md
21. doc14_faction_bible.md
22. doc15_economy_bible.md
23. doc16_architecture_bible.md
24. doc17_art_direction_bible.md
25. doc18_technical_design_document.md
26. doc19_ue5_implementation_bible.md
27. doc20_ui_ux_bible.md
28. doc21_audio_bible.md
29. doc22_voice_dialogue_bible.md
30. doc23_historical_codex.md
31. doc24_world_event_system.md
32. doc25_progression_bible.md
33. doc26_inventory_crafting_bible.md
34. doc27_artifact_relic_bible.md
35. doc28_cinematic_storyboard_bible.md
36. doc29_environment_production_bible.md
37. doc30_prop_bible.md
38. doc31_character_art_bible.md
39. doc32_animation_bible.md
40. doc33_vfx_bible.md
41. doc34_lighting_bible.md
42. doc35_quest_flowchart.md
43. doc36_save_load_design.md
44. doc37_accessibility_bible.md
45. doc38_qa_test_plan.md
46. doc39_historical_authenticity_qa.md
47. doc40_localization_bible.md
48. doc41_marketing_bible.md
49. doc42_trailer_scripts.md
50. doc43_developer_diary_series.md
51. doc44_production_roadmap.md
52. doc45_team_structure.md
53. doc46_risk_register.md
54. doc47_vertical_slice_production_plan.md
55. doc48_asset_production_tracker.md
56. doc49_bug_database.md

---



<!-- ===== 00_foundation_bible_v1.md ===== -->

# GANGAIKONDA — Foundation Bible (v1)
### *The City of the Conqueror of the Ganges*
**"An Empire Is Remembered. A Legacy Is Built."**

---

## 0. What this document is

This is Phase 1–3 of the production pipeline you outlined: **Historical Research → World Bible → Character Bible**, compressed into one founding reference. Every later deliverable (Quest Bible, Puzzle Bible, Technical Design Doc, Cinematic Script) should cite back to the evidence entries here rather than inventing new historical claims independently.

Everything below is tagged:

- **[DOCUMENTED]** — supported by inscriptions, archaeology, or scholarly consensus
- **[PLAUSIBLE RECONSTRUCTION]** — a reasonable inference from documented context, not itself attested
- **[FICTIONAL]** — invented for gameplay, never to be presented as history in-game

---

## 1. Historical Evidence Database (seed entries)

This is a starter set. The full database should grow to hundreds of entries as research continues, but this establishes the format and anchors the biggest story beats.

| # | Claim | Category | Source Type | Confidence | Gameplay Use |
|---|---|---|---|---|---|
| 1 | Rajendra Chola I ruled as co-regent from c. 1012 CE and as sole emperor from c. 1014–1044 CE, son of Rajaraja I | DOCUMENTED | Chola copper-plate inscriptions (e.g. Tiruvalangadu plates); temple inscriptions at Thanjavur & Gangaikondacholapuram | High | Codex entry, opening cinematic framing |
| 2 | Rajendra led a military expedition into the Gangetic plain, and following it adopted the title "Gangaikonda Chola" ("the Chola who took the Ganga") | DOCUMENTED | Tiruvalangadu copper plates; multiple royal inscriptions using the title | High | Act 3–5 campaign arc, title unlock moment |
| 3 | The exact route, battles, and rulers defeated during the northern campaign are known only through the laudatory (praśasti) language of inscriptions, which list kingdoms/rulers overcome but not detailed tactical narrative | DOCUMENTED (existence of the list) / UNCERTAIN (military specifics) | Inscriptional praśasti passages | Medium | Must label as "HISTORICAL RECONSTRUCTION" per your Act 3 instruction — do not invent specific battles |
| 4 | Rajendra founded a new capital, Gangaikondacholapuram, north of Thanjavur, to commemorate the expedition | DOCUMENTED | Inscriptions naming the new capital; archaeological remains at the site (Jayankondam, Tamil Nadu) | High | Act 6 core premise |
| 5 | Rajendra built the Brihadisvara Temple at Gangaikondacholapuram as a Shiva temple, architecturally related to but distinct from his father's Thanjavur temple | DOCUMENTED | Temple inscriptions; ASI archaeological survey; UNESCO World Heritage documentation ("Great Living Chola Temples") | High | Act 7 centerpiece |
| 6 | A large water tank/reservoir system (the Cholagangam) was constructed at the new capital, reportedly filled with water brought from the Ganga campaign as a symbolic and functional act | PLAUSIBLE RECONSTRUCTION (symbolic "Ganga water" claim is traditional/near-contemporary, not independently verifiable) | Later inscriptions, regional tradition, hydraulic archaeological remains | Medium | Act 8 "Lion Well" puzzle — frame the water-from-the-Ganga element as tradition, not proven fact |
| 7 | The Chola state maintained an extensive maritime and trade network across the Bay of Bengal, including diplomatic/trade missions to Srivijaya and China | DOCUMENTED | Chinese Song dynasty records of Chola missions; Tamil merchant guild inscriptions (e.g. Ainnurruvar) | High | Act 11 maritime world design |
| 8 | The Chola bronze-casting tradition (lost-wax / cire perdue) reached a technical and artistic peak under Rajaraja I and Rajendra I | DOCUMENTED | Surviving bronzes, temple records | High | Craftsman NPC systems, artisan character role |
| 9 | Chola inscriptions record detailed local self-government structures (e.g., village assemblies/sabhas) alongside royal administration | DOCUMENTED | Uttaramerur inscriptions (slightly earlier but relevant administrative continuity) | High | Kingdom management systems, political intrigue framing |
| 10 | Any specific private conversations, court intrigue dialogue, or the antagonist's personal ideology | FICTIONAL | — | N/A | Must always render as clearly dramatized fiction, never codex-logged as history |

**Research note for the Historical Research Director role:** entries 3 and 6 are the two biggest risk points for overclaiming. The praśasti-style inscriptions are propagandistic by genre — they list conquered rulers/regions but weren't written as military reportage. The game should dramatize this ambiguity rather than paper over it (e.g., the fictional scholar character can explicitly say "the inscriptions tell us *that* it happened and *how it was meant to be remembered* — not exactly *how* it happened").

---

## 2. Story Bible — Act Structure (your outline, annotated for production)

Your 12-act structure is sound and maps cleanly onto documented history without requiring invention of major events. Two production notes:

- **Acts 3–4 (Northern Expedition / The Ganga)** are your highest historical-risk content. Recommend every mission in this stretch opens with an explicit on-screen "HISTORICAL RECONSTRUCTION" tag per your own rule, and the fictional scholar character periodically reminds the player what is and isn't attested — this becomes a recurring narrative device rather than a one-time disclaimer.
- **Acts 6–9 (city founding through inscription system)** are your safest and richest ground — this is where documented archaeology, architecture, and epigraphy give you the most concrete material to build real puzzles from. This is likely where the vertical slice should live, as you already specified.

---

## 3. Character Bible (draft)

| Role | Name (working) | Status | Notes |
|---|---|---|---|
| Historical ruler | Rajendra Chola I | Historical | Dialogue is dramatized reconstruction; no invented quotes presented as verbatim historical record |
| Protagonist | Arulan | Fictional | Player's window into the world; requires linguistic authenticity check on the name before lock (Tamil onomastics consultant) |
| Scholar | TBD | Fictional | Embodies the "documented vs. reconstructed vs. fictional" tension directly in dialogue; primary source of Historical Codex entries |
| Architect | TBD | Fictional | Drives Act 6–7 construction gameplay |
| Naval commander | TBD | Fictional | Drives Act 11 maritime arc |
| Merchant | TBD | Fictional | Anchors trade-network systems, Ainnurruvar-style guild flavor |
| Artisan (bronze/stone) | TBD | Fictional | Anchors craftsmanship systems and Act 7/8 puzzle framing |
| Antagonist | TBD | Fictional | Administrative-overreach ideology, as you specified — needs investigation gameplay where the player can find evidence supporting *or* undermining his claims, avoiding a simple villain arc |
| Political rival | TBD | Fictional | Court-intrigue counterweight to the antagonist |
| Messenger | TBD | Fictional | Recurring structural device tying Acts 3–6 together |

Naming for all fictional Tamil/Sanskrit characters should go through a linguistic authenticity pass before final lock — this is a good task for the Historical Authenticity Consultant and Cultural Sensitivity Consultant roles jointly.

---

## 4. Recommended next deliverable

Given the scope, I'd suggest we go one of two directions next — tell me which, or pick a different priority entirely:

1. **Puzzle Bible (Acts 7–9 first)** — design the Stone Alignment, Lion Well, and Inscription Decoding puzzle systems in mechanical detail, since these are your most gameplay-defining systems and sit on your safest historical ground.
2. **Quest Bible for the Vertical Slice** — fully spec the 10-beat vertical slice you outlined (arrival → inscription → architect → water puzzle → temple → conspiracy → ambush → return → codex → cinematic) with dialogue, objectives, and historical sourcing per quest.

Either can be turned into a Word doc, a slide-style pitch deck, or kept as a living markdown reference — whichever suits how your team will actually use it.


---



<!-- ===== 00b_production_bible_v2.md ===== -->

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


---



<!-- ===== doc01_game_design_document.md ===== -->

# GANGAIKONDA — DOCUMENT 01: GAME DESIGN DOCUMENT

**Document ID:** GDD-01 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Define every core gameplay system at implementable depth.
**Scope:** Full game (not limited to vertical slice).
**Dependencies:** Foundation Bible v1 (evidence categories, act structure), Production Bible v2 (Quest/Puzzle frameworks).
**Canonical assumptions:** Evidence tags [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply to every historical reference in this document. No contradiction of Foundation Bible v1 occurs here; where this document adds detail not present in v1, it is marked **NEW**.

---

## 1. Executive Summary

GANGAIKONDA is a single-player, third-person historical action-adventure set in the Chola Empire under Rajendra Chola I, in which the player — a fictional protagonist, Arulan — moves through the founding of Gangaikondacholapuram as courier, investigator, and eventually participant in the new capital's construction. The game's differentiator is structural, not cosmetic: every historical claim on screen is explicitly sourced and confidence-rated in-fiction, and gameplay systems (puzzles, investigation, construction) are built to simulate real period crafts rather than abstract "video game" mechanics.

## 2. Vision

"Walk through an intelligently reconstructed 11th-century Chola world, and always know what you actually know." The game succeeds if a player finishes it able to explain the difference between what historians know about Rajendra Chola I and what the game invented for drama — and wants to look the real history up afterward.

## 3. Game Pillars

1. **Evidence-honest historical fiction** — every claim tagged, never blurred.
2. **Craft-simulating puzzles** — puzzles teach real period engineering/epigraphy/trade logic.
3. **A capital that grows** — Gangaikondacholapuram visibly transforms from construction site to living city as the story progresses; world-state is a narrative device, not just a backdrop.
4. **Grounded stakes** — no fantasy elements; conflict is political, logistical, and personal.

## 4. Genre
Historical open-world action-adventure. Secondary: investigation, puzzle-adventure, light stealth, naval exploration.

## 5. Target Audience
Players of narrative-driven open-world adventures (25–45 core) interested in history, archaeology, or world cultures currently underrepresented in AAA games; secondary audience in South/Southeast Asia specifically invested in Chola history.

## 6. Platforms
PC and current-gen console (UE5-class hardware) as baseline target; scalability required given Nanite/Lumen use (see Doc 18).

## 7. Camera
Third-person exploration camera (dynamic follow, collision-aware); dedicated dialogue close-up framing; cinematic camera for landmark reveals and cutscenes; free-look puzzle camera for architectural/water puzzles; naval camera with horizon-lock option for readability at sea.

## 8. Player Experience
Target emotional arc: curiosity (Act 1–2) → awe and logistical grounding (Act 3–5) → ownership and craft (Act 6–9) → complexity/moral ambiguity (political conspiracy thread) → earned civic pride (Act 12, endings). The player should never feel like a tourist in a museum diorama — NPCs, economy, and construction should visibly respond to their actions.

## 9. Core Gameplay Loop

**Purpose:** give the player a repeatable, legible loop that scales from tutorial to endgame.
**Loop:** EXPLORE → DISCOVER → INVESTIGATE → SOLVE → DECIDE → TRAVEL → BUILD → CONFRONT → DOCUMENT → UNLOCK HISTORY (per Foundation Bible).
**Player action:** move through world, interact with points of interest.
**System response:** world surfaces investigation threads (inscriptions, ledgers, NPC dialogue hooks) contextually near relevant locations.
**Inputs:** movement, interact, scan (inscription/evidence mode), dialogue choice, inventory/tool select.
**Outputs:** Codex entries, quest updates, world-state changes (construction progress, NPC relationship deltas).
**Dependencies:** Historical Codex module, Quest module, World Simulation module.
**Failure states:** none at the loop level (exploration/investigation are non-lethal); local failure states live inside individual systems (combat death, puzzle failure).
**Rewards:** Codex entries, quest progression, world visibly changing.
**Edge cases:** player skips major discovery — later quests must gracefully degrade (reduced context, not a hard block) rather than soft-locking.

## 10. Progression
No numeric RPG leveling. Progression is unlocked *capability* (new tools: inscription-scan tier, construction access, ship access) and *world-state* (more of Gangaikondacholapuram built, more codex entries). See Doc 25 (Progression Bible) for full detail — this section defines the principle only: progression must always be narratively legible, never a naked stat increase.

## 11. Exploration

**Purpose:** let the player read the world as evidence.
**Player action:** free traversal, climbing on period-appropriate structures (scaffolding, temple exteriors, ship rigging), swimming, riding period transport (cart, horse) where historically supported.
**System response:** points of interest surface via diegetic cues (NPC dialogue, visible activity, environmental storytelling) rather than a minimap icon soup.
**Inputs:** movement, climb, swim, ride, scan.
**Outputs:** discovery triggers, ambient NPC reactions, Codex candidate flags.
**Dependencies:** Navigation module, World Simulation.
**Failure states:** fall damage from unsafe climbing heights (grounded, not punishing).
**Rewards:** vistas/landmark reveals, discovery triggers.
**Edge cases:** sequence-breaking into a not-yet-built area of the capital — must either be geometrically blocked in a diegetic way (scaffolding, guards) or gracefully handled if reached.

## 12. Combat
See Doc 10 (Combat Design Bible) for full spec. Principle for this GDD: combat is a **consequence system**, not a primary pillar — it exists to punctuate the investigation/conspiracy thread (ambushes, guard encounters), not to carry the moment-to-moment loop. Grounded period weapons only; no supernatural abilities.

## 13. Stealth
See Doc 11. Principle: social stealth (disguise, crowd blending in markets/temple festivals) is as important as line-of-sight stealth, reflecting a densely populated capital rather than empty patrol corridors.

## 14. Investigation

**Purpose:** the game's primary verb — this is what most playtime should consist of.
**Player action:** scan inscriptions/documents, compare evidence, question NPCs, cross-reference Codex entries.
**System response:** evidence chains resolve into new dialogue options, location unlocks, or Codex entries; contradictory evidence is surfaced explicitly rather than auto-resolved by the game.
**Inputs:** scan, compare (in Codex UI), dialogue選択.
**Outputs:** Codex entries with confidence tags, new quest branches.
**Dependencies:** Historical Codex module, Dialogue module.
**Failure states:** none punitive; a missed thread simply narrows later dialogue options.
**Rewards:** narrative context, quest unlocks, world understanding.
**Edge cases:** player who ignores investigation entirely and rushes combat/exploration — main quest must remain completable on a reduced-context path (design constraint, not full open removal of investigation).

## 15. Puzzle Systems
See Doc 09 (Puzzle Bible) for full catalog framework. Principle for this GDD: every puzzle must pass the three-question test from the Production Bible v2 (what craft does it simulate / what does it teach / why here) before entering production.

## 16. Naval Gameplay
See Doc 12. Principle: Act 11 introduces it, but light naval traversal (coastal transport, not just a gated setpiece) should be available earlier once the player has established trade-network context, so it doesn't feel bolted on.

## 17. NPC Systems
See Doc 13. Principle for GDD: every named NPC needs a daily schedule and at least one piece of persistent memory of player action (per your original "merchant remembers" example) — this is a hard requirement, not aspirational flavor text.

## 18. Quest Systems
See Doc 07 for the quest catalog itself. This section defines the *system*: quests are data-driven (Quest module, Doc 18/19), branch via Dialogue module outcomes, and always declare Historical category (per Foundation Bible tags) at the quest-data level so QA (Doc 39) can audit systematically rather than manually.

## 19. Dialogue

**Purpose:** deliver character, deliver investigation threads, deliver branching consequence.
**Player action:** select dialogue option (no full voice-input; text/branch selection).
**System response:** NPC reacts per personality profile (Doc 06) and memory state (Doc 13); dialogue can gate/ungate quest branches.
**Inputs:** dialogue choice selection.
**Outputs:** relationship deltas, quest state changes, Codex unlocks (via NPC-delivered information).
**Dependencies:** NPC/AI module, Quest module.
**Failure states:** none hard-blocking; a "burned" relationship narrows future options rather than ending content.
**Rewards:** narrative depth, new quest branches.
**Edge cases:** player who is hostile/dismissive to every NPC — must still be able to complete main story via the harder, more adversarial path rather than getting stuck.

## 20. Inventory
See Doc 26. Principle: inventory is a narrative and puzzle-support tool (evidence fragments, tools, trade goods), not a loot-treadmill.

## 21. Crafting
Light craft-adjacent gameplay only (assisting artisan NPCs in specific quests), not a full crafting-and-equipment economy — keeps scope proportionate and avoids "generic RPG crafting bolted onto history game."

## 22. Economy
See Doc 15. Principle: economy is primarily a **narrative/world-simulation layer** (construction resource flow, market activity) that the player observes and occasionally participates in, not a deep player-facing trading minigame.

## 23. Reputation
Tracked per faction (Doc 14) and per key NPC (Doc 13), surfaced narratively (how NPCs greet/react to the player) rather than as a numeric HUD meter — consistent with the minimal-HUD principle in Doc 20/Foundation Bible UI guide.

## 24. Factions
See Doc 14 for full definitions. GDD principle: faction conflict (royal administration vs. the antagonist's administrative-overreach position) must remain genuinely arguable — reputation systems should let the player side meaningfully with either position without the game telegraphing a "correct" answer.

## 25. World Simulation

**Purpose:** make Gangaikondacholapuram's construction and daily life feel systemic, not scripted set-dressing.
**System response:** construction progress advances on story beats (not real-time ticking); NPC daily schedules run continuously (Mass Entity-driven, Doc 18); weather/season affects available activities and travel.
**Dependencies:** AI module, World module, Weather module.
**Edge cases:** player revisiting an early area late-game must see it reflect current world-state (finished temple sections, more active market), not a static snapshot — this is a scope/production risk, flagged in Doc 46.

## 26. Historical Codex
Format locked per Foundation Bible/Production Bible v2 UI spec: Source / Date-period / Confidence / Description, with visual distinction by evidence category. Full entry catalog lives in Doc 23.

## 27. Save System
See Doc 36. Principle for GDD: save state must capture world-simulation state (construction progress, NPC relationship/memory) in addition to standard quest/inventory state — this is non-trivial given the living-world pillar and should be flagged early to engineering (Doc 18/36).

## 28. Difficulty
Combat/stealth difficulty is adjustable; investigation/puzzle difficulty is not gated behind a "difficulty slider" in the traditional sense — instead, hint depth is adjustable (see Doc 37 Accessibility) so puzzles remain intellectually intact at every setting rather than being trivialized.

## 29. Accessibility
See Doc 37. GDD requirement: puzzle hint system, full subtitle/text scaling, combat assist options, motion-reduction options for cinematic camera moves.

## 30. UI/UX
See Doc 20. GDD requirement: minimal HUD, locked Codex notification format, evidence-category visual language consistent across all UI surfaces (map markers, quest journal, Codex).

## 31. Audio
See Doc 21. GDD requirement: diegetic sound and score-restraint principle from Production Bible v2 apply system-wide, not just to named cinematics.

## 32. Cinematics
See Doc 05/28. GDD requirement: every cinematic must be classifiable under the evidence-tag system where it depicts historical events (per Act 3/4 "HISTORICAL RECONSTRUCTION" labeling rule).

## 33. Multiplayer Decision
**Decision: single-player only.** Rationale: the evidence-honesty pillar and living-world-as-narrative-device design depend on tight authorial control over pacing and world-state; multiplayer would fragment both without clear design benefit. This is a design decision, not a technical limitation — revisit only if a clearly scoped competitive/co-op mode is proposed separately.

## 34. Technical Constraints
UE5, Nanite/Lumen/World Partition/Mass Entity as specified in Doc 18. Open-world streaming budget must account for dense NPC simulation (living-world pillar) — early profiling recommended before scope lock on city population density.

## 35. Performance Targets
Target: 30fps min / 60fps target on current-gen console equivalent hardware, with Nanite/Lumen scalability options for PC. Specific frame budgets deferred to Doc 18 technical profiling once vertical slice is built — do not lock numeric targets before the slice proves NPC-density and construction-simulation cost.

---

## Open Questions
- Exact NPC population density for Gangaikondacholapuram (living-world pillar vs. performance budget) — needs vertical slice profiling.
- Whether light naval traversal should be available before Act 11 (recommended above) — needs pacing review with Narrative Director.
- Save system scope for world-simulation state — needs early technical spike, not deferred to Doc 36 alone.

## Dependencies on Other Documents
Doc 02 (World Bible), Doc 06 (Character Bible), Doc 07 (Quest Bible), Doc 09 (Puzzle Bible), Doc 10–15 (system bibles), Doc 18–20 (technical/UI), Doc 23 (Codex), Doc 36–37 (save/accessibility).

## Acceptance Criteria
- All 35 sections present with Purpose/Player action/System response/Inputs/Outputs/Dependencies/Failure states/Rewards/Edge cases wherever the section defines a player-facing system (satisfied above for core systems; supporting sections correctly deferred to their dedicated bibles rather than duplicated).
- No contradiction of Foundation Bible v1 evidence categories or act structure.
- Every deferred section names the document that owns full detail.


---



<!-- ===== doc02_world_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 02: WORLD BIBLE

**Document ID:** WB-02 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Define the game's world geography, regions, and key locations at production depth.
**Scope:** Core playable world for the full game (Thanjavur region → northern campaign corridor → Gangaikondacholapuram → maritime network).
**Dependencies:** Foundation Bible v1 (Evidence Database, Act structure), Doc 01 GDD (Exploration/World Simulation systems).
**Canonical assumptions:** Evidence tags apply per location. Geography follows real Tamil Nadu / Gangetic-corridor topography as the reference frame — the game does not invent fictional geopolitical borders and present them as historical (per your instruction).

**Scope note on "every location":** your brief asks for full-template treatment of every city, village, port, temple, market, workshop, residential area, and wilderness zone in the world — that's genuinely a full open-world level-design document, hundreds of entries. Below is the complete world-level framework (geography/climate/routes) plus full-template treatment of the locations that actually carry story weight — the hub, the capital's major districts, one representative port, one representative wilderness zone, and the northern corridor. Minor/filler locations (generic villages along trade routes, etc.) should be generated by the World Designer role using this document's templates once region layout is locked, rather than hand-authored here one by one.

---

## 1. Historical Period
Early-to-mid 11th century CE, centered on Rajendra Chola I's reign (c. 1014–1044 CE) — [DOCUMENTED] per Foundation Bible entry #1.

## 2. Geography, Climate, Terrain (world framework)

- **Core region:** Kaveri river delta (Chola heartland, around Thanjavur) — [DOCUMENTED] as the historical Chola core territory.
- **Northern corridor:** the overland/river route associated with the Gangetic expedition — [PLAUSIBLE RECONSTRUCTION] for specific path, since exact route is not fully attested (per Foundation Bible entry #3).
- **Climate:** tropical, monsoon-seasonal — wet season (construction/travel slowdowns, flooded rivers) vs. dry season (campaign season, active construction) should drive world-simulation pacing (Doc 01 §25).
- **Terrain variety:** delta farmland (flat, irrigated), forested transitional zones along the northern corridor, coastal/port terrain for the maritime network, and the specifically engineered terrain of Gangaikondacholapuram itself (reservoir, canals, temple platform).
- **Rivers:** Kaveri (Chola heartland) [DOCUMENTED]; northern river systems associated with the expedition corridor [PLAUSIBLE RECONSTRUCTION for specific crossings, DOCUMENTED for general historical geography of the region].
- **Agriculture:** rice paddy delta agriculture as the economic base of the Chola heartland — [DOCUMENTED] general pattern; specific field layouts in-game are [FICTIONAL] set dressing built on documented agricultural practice.

## 3. Route Network

- **Trade routes:** inland riverine/road trade linking Thanjavur to ports; maritime routes linking Chola ports to Southeast Asia (Srivijaya) and China — [DOCUMENTED] general existence per Foundation Bible entry #7; specific in-game route geometry is [FICTIONAL] gameplay abstraction.
- **Military routes:** the northern campaign corridor — [PLAUSIBLE RECONSTRUCTION], explicitly labeled in-game per the Act 3 rule.
- **Administrative routes:** road network connecting royal administrative centers, consistent with documented local self-governance structures (Foundation Bible entry #9).

---

## 4. LOCATION CATALOG (full template)

### 4.1 THANJAVUR (starting hub)
- **Historical status:** [DOCUMENTED] — Chola capital under Rajaraja I, major urban and temple center at game start.
- **Approximate location:** Kaveri delta, Chola heartland.
- **Historical evidence:** Brihadisvara Temple inscriptions, temple administrative records.
- **Visual identity:** established, "finished" imperial city — contrast deliberately against Gangaikondacholapuram's construction-in-progress state (Art Direction principle, Production Bible v2 §3).
- **Architecture:** mature Dravidian temple complex, dense urban fabric around it.
- **NPC population:** high density — craftsmen, temple officials, scribes, soldiers, merchants (per Act 1 opening).
- **Economy:** temple economy, established craft guilds (stone, bronze).
- **Activities:** market trade, temple ceremony, craft production — establishes world "normal" before the expedition disrupts it.
- **Quests:** Act 1–2 opening quests, royal court introduction (Q-equivalent of Act 2 in Story Bible).
- **Enemies:** none (safe hub for Act 1–2); low-threat later if political conspiracy thread reaches here.
- **Secrets:** early optional inscriptions establishing the investigation/Codex system before the player leaves for the capital site.
- **Puzzles:** low-tier tutorial versions of Inscription Decoding (Production Bible v2 §2.4).
- **Environmental storytelling:** temple construction from the *previous* generation (Rajaraja's temple) visible as a "finished" counterpoint to what the player will later help build.

### 4.2 THE ROYAL COURT (district within Thanjavur)
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] — court existed and functioned per documented administrative structure; specific physical layout is [FICTIONAL].
- **Visual identity:** formal architecture, restrained ornamentation matching Art Direction gold-as-material-not-wash principle.
- **NPC population:** generals, scribes, poets, merchant representatives, temple officials, engineers, architects, envoys, naval commanders (per your Act 2 list).
- **Activities:** conversation system, document investigation, map examination.
- **Quests:** Act 2 court intrigue setup quests.
- **Secrets:** first seeds of the antagonist's political position, introduced ambiguously.
- **Environmental storytelling:** maps and campaign preparations visible before the player is told the expedition is happening — reward attentive exploration.

### 4.3 THE NORTHERN CORRIDOR (campaign route, Acts 3–5)
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] — labeled "HISTORICAL RECONSTRUCTION" on-screen per your explicit Act 3 rule.
- **Visual identity:** shifting terrain (delta → forest/transitional → river crossings), deliberately less architecturally dense than the Chola heartland to read as "away from home."
- **Architecture:** temporary military camps, river-crossing infrastructure — [FICTIONAL] specifics built on [PLAUSIBLE RECONSTRUCTION] logistics.
- **NPC population:** soldiers, scouts, messengers, local populations encountered along the route (diplomacy gameplay).
- **Economy:** supply logistics (food/water/road quality) as an explicit gameplay system per your Act 3 direction — not abstracted away.
- **Activities:** scouting, river crossings, supply management, diplomacy, strategic decisions.
- **Quests:** the northern-expedition quest chain (Act 3–5 main quests).
- **Enemies:** period-appropriate military encounters — combat here should be logistics-driven (supply state affects encounter difficulty) rather than arcade combat.
- **Secrets:** environmental storytelling around what real campaigns depended on (per your explicit list: food, water, roads, rivers, horses, elephants, soldiers, messengers, terrain, weather).
- **Puzzles:** river-crossing/elevation logistics puzzles (variant of Production Bible v2 §2.8).
- **Environmental storytelling:** avoid turning the expedition into a battle-of-the-week structure — most of this corridor should read as *logistics under pressure*, consistent with your "do not turn the expedition into fantasy" instruction.

### 4.4 THE GANGA (Act 4 set-piece location)
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] / symbolic cinematic explicitly labeled "INSPIRED BY THE HISTORICAL EXPEDITION" per your instruction — not presented as a literal reenactment.
- **Visual identity:** minimal, open, sound-design-led (per Production Bible v2 §4 audio doctrine) — this is the one location where restraint *is* the art direction.
- **Activities:** primarily cinematic; light exploration before the cutscene.
- **Environmental storytelling:** the river itself is the environmental storytelling — deliberately avoid overbuilding this location with gameplay systems that would undercut its restraint.

### 4.5 GANGAIKONDACHOLAPURAM — CONSTRUCTION ZONE (Acts 6–9, vertical slice location)
- **Historical status:** [DOCUMENTED] site and general nature; specific building-by-building state during construction is [FICTIONAL] extrapolation from [DOCUMENTED] final forms.
- **Visual identity:** active construction — scaffolding, stone dust, incomplete gopurams (per Art Direction §3 "scale storytelling" principle).
- **Sub-districts (each needs its own pass at this template once locked; framework given here):**
  - **Temple construction zone** — Stone Alignment puzzle home (Production Bible v2 §2.1), Architect NPC hub.
  - **Reservoir/canal zone ("Lion Well")** — Water Engineering puzzle home (§2.2).
  - **Site office / administrative zone** — conspiracy-thread quests (Q6 in vertical slice), ledger/seal puzzles (§2.3, §2.5).
  - **Worker settlement** — NPC daily-cycle showcase (market/craft/temple/night per Foundation Bible NPC routine spec).
- **NPC population:** surveyors, architects, stone workers, sculptors, engineers, water engineers, royal officers, farmers, merchants, soldiers (per your Act 6 list).
- **Economy:** resource management gameplay — stone, timber, metal, food, water, labor, transport, tools (per your Act 6 list); this is where Doc 01 §21 economy principle ("primarily observed, occasionally participated in") is most active.
- **Quests:** bulk of the main quest chain lives here (Acts 6–9).
- **Enemies:** conspiracy-thread encounters (ambush per vertical slice Q7).
- **Secrets:** hidden inscriptions gated behind water-puzzle completion (per vertical slice Q4).
- **Puzzles:** full puzzle-pillar showcase — stone, water, inscription, ledger/seal.
- **Environmental storytelling:** the site should visibly progress across the Act 6–9 span as the player completes major quests — construction-state-tied-to-story-progress is this location's core identity.

### 4.6 GANGAIKONDACHOLAPURAM — LIVING CITY (Act 12, post-construction state)
- **Historical status:** same site as 4.5, [DOCUMENTED], shown in its "complete" state.
- **Visual identity:** the payoff of 4.5's incompleteness — finished gopurams, active markets, full NPC routine cycle (morning/afternoon/evening/night per your Act 12 spec).
- **Activities:** the full living-world showcase — market, craft, temple activity, night routines, dynamic weather/season.
- **Quests:** endgame/epilogue content, ending-variant reflection content.

### 4.7 A REPRESENTATIVE PORT (Act 11 maritime network)
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] — composite port built from [DOCUMENTED] general Chola maritime/trade evidence (Foundation Bible entry #7), not presented as one specific attested port unless a specific one is chosen and separately sourced by the Historical Research Director.
- **Visual identity:** working harbor — cargo, guild activity, foreign traders.
- **NPC population:** merchants, foreign visitors, naval commanders, guild representatives (Ainnurruvar-style, per Foundation Bible entry #7).
- **Economy:** Trade Ledger Reconciliation puzzle home (Production Bible v2 §2.5).
- **Quests:** naval/scholar quest chains, merchant subquests.
- **Puzzles:** Star-Sight Navigation (§2.6) staged from here.
- **Environmental storytelling:** foreign goods/visitors should read as evidence of the documented trade network, not generic "exotic bazaar" set dressing.

### 4.8 REPRESENTATIVE WILDERNESS ZONE (transitional/forest terrain)
- **Historical status:** [FICTIONAL] specific terrain, built on [DOCUMENTED] general regional geography.
- **Visual identity:** low NPC density, used for pacing contrast between dense narrative locations.
- **Activities:** light exploration, optional Codex content (flora/fauna/agriculture-adjacent lore), transitional travel.
- **Quests:** optional exploration quests only — no main-quest gating here, per pacing principle (keep the spine moving through named locations).

---

## 5. Water Infrastructure (dedicated cross-reference)
Ties directly to Foundation Bible entry #6 — the Cholagangam reservoir tradition. In-world, water infrastructure should be legible as a *system* connecting reservoir → canal → temple/city distribution, not isolated puzzle set-pieces; this supports both the Lion Well puzzle chain and the Act 8 environmental storytelling goal.

## 6. Open Questions
- Whether to name the representative port after a specific attested Chola-era port (requires dedicated Historical Research Director sourcing pass) or keep it explicitly composite/fictionalized.
- Exact sub-district boundaries for Gangaikondacholapuram pending level-design blockout.
- How many "filler" villages the open-world scale actually requires — recommend deferring to a production-scope decision (Doc 44/46) rather than over-authoring here.

## Dependencies on Other Documents
Doc 01 (Exploration/World Simulation systems), Doc 03 (Historical Research Bible — sourcing for any location claims not already covered by Foundation Bible), Doc 09 (Puzzle Bible), Doc 29 (Environment Production Bible — zone breakdown for production).

## Acceptance Criteria
- Every named location has Name / Historical status / Location / Historical evidence / Visual identity / Architecture / NPC population / Economy / Activities / Quests / Enemies / Secrets / Puzzles / Environmental storytelling.
- No fictional geopolitical borders presented as historical.
- All uncertain geography explicitly tagged [PLAUSIBLE RECONSTRUCTION], not asserted as fact.


---



<!-- ===== doc03_historical_research_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 03: HISTORICAL RESEARCH BIBLE

**Document ID:** HRB-03 · **Version:** 1.0 · **Status:** Draft for review — requires Historical Research Director + consultant sign-off before content lock
**Purpose:** Expand the Foundation Bible v1 seed evidence database (10 entries) into a working research bible covering the full topic list from your brief, in the specified column format.
**Scope:** Evidence entries supporting Docs 01–02 and all subsequent quest/puzzle/character/art documents.
**Dependencies:** Foundation Bible v1 (entries #1–10 remain canonical and are not duplicated here, only cross-referenced).

**Scope note:** a genuinely complete database for a project this size runs to hundreds of entries and is properly a living, continuously-updated research artifact, not a one-time document — real academic literature on the Cholas is extensive and contested in places (especially military specifics and some social-history questions), and a document like this should be revised as the Historical Research Director's team does primary-source work. What follows is a solid working seed: 4–5 entries per topic area, correctly tagged and confidence-rated, sufficient to unblock Docs 06–17 without overclaiming anywhere. Treat this as v1 of a document that should keep growing.

**Confidence scale used below:** KNOWN (strong scholarly consensus, direct primary evidence) · LIKELY (well-supported inference, some scholarly debate on specifics) · UNCERTAIN (plausible but weakly evidenced, or debated) · UNKNOWN (genuine gap — do not fill with invention).

---

## A. Rajendra Chola I & Rajaraja Chola I

| ID | Claim | Evidence Category | Source | Source Type | Date | Orig. Language | Confidence | Historical Debate | Game Usage | Misinterpretation Risk | Required Disclaimer |
|---|---|---|---|---|---|---|---|---|---|---|---|
| A1 | Rajaraja Chola I (r. c. 985–1014 CE) built the Brihadisvara Temple at Thanjavur and was Rajendra's father and predecessor | DOCUMENTED | Thanjavur temple inscriptions | Epigraphic | c. 1010 CE | Tamil | KNOWN | None significant | Act 1 environmental storytelling | Low | None needed beyond standard codex sourcing |
| A2 | Rajendra I co-ruled with Rajaraja before becoming sole emperor | DOCUMENTED | Copper-plate inscriptions | Epigraphic | c. 1012–1014 CE | Tamil/Sanskrit | KNOWN | Minor debate on exact co-regency start date | Act 2 court context | Low | Date given as approximate |
| A3 | Rajendra I's reign involved extensive military activity beyond the Gangetic expedition, including campaigns in Sri Lanka and against Southeast Asian polities (notably a naval expedition associated with Srivijaya) | DOCUMENTED (existence) / UNCERTAIN (full extent and motive) | Inscriptions; Chinese and Southeast Asian records | Epigraphic + foreign chronicle | c. 1017–1025 CE | Tamil, Sanskrit, Chinese | LIKELY | Scholars debate whether the Srivijaya campaign was primarily about trade-route control or prestige/conquest | Background context only — not the game's main campaign focus (Ganga expedition is) | Medium — easy to conflate with the Ganga campaign | Codex should clearly separate the two campaigns |
| A4 | Rajendra's personal character, private motivations, or inner thoughts | FICTIONAL if dramatized | — | — | — | — | UNKNOWN | N/A — inscriptions do not record private thought | Dialogue/cinematic dramatization only | High if presented as fact | Every scene with Rajendra's interiority must be clearly dramatized fiction |

## B. The Northern (Gangetic) Expedition

| ID | Claim | Evidence Category | Source | Source Type | Date | Confidence | Historical Debate | Game Usage | Misinterpretation Risk | Required Disclaimer |
|---|---|---|---|---|---|---|---|---|---|---|
| B1 | Rajendra adopted the title "Gangaikonda Chola" following a northern military expedition | DOCUMENTED | Tiruvalangadu copper plates and other royal inscriptions | Epigraphic | c. 1023–1025 CE | KNOWN | None on the title's existence | Central Act 3–5 premise | Low | None |
| B2 | The specific route taken, rulers/kingdoms defeated in sequence, and tactical details of the campaign | UNCERTAIN | Inscriptional praśasti lists | Epigraphic (laudatory genre) | Contemporary/near-contemporary | UNCERTAIN | Significant — praśasti inscriptions are propagandistic, listing conquered rulers without narrative detail; historians reconstruct the likely route from listed place-names with real disagreement on specifics | Labeled "HISTORICAL RECONSTRUCTION" on-screen throughout Acts 3–5 | High if not labeled | Mandatory on-screen label per Foundation Bible Act 3 rule |
| B3 | The campaign reached the Ganga river region | DOCUMENTED (claim made in inscriptions) / LIKELY (as a real historical event, given corroborating title adoption) | Royal inscriptions | Epigraphic | Contemporary | LIKELY | Some scholarly caution about how literally to read inscriptional claims of reaching a specific point, standard for the genre | Act 4 centerpiece, explicitly framed as "INSPIRED BY" | Medium | On-screen framing per Foundation Bible Act 4 rule |
| B4 | Logistics (supply, terrain, seasonal constraints) that any pre-modern army of this scale would have faced on such a route | LIKELY (general historical/military-logistics inference, not campaign-specific evidence) | Comparative historical/military scholarship on pre-modern South Asian campaigns | Secondary scholarship | N/A | LIKELY | Applied generically, not documenting this specific campaign's logistics | Act 3 logistics gameplay systems | Medium — could read as more specific than it is | Codex should note this is general period logistics, not documented specifics of this campaign |

## C. Gangaikondacholapuram & the Brihadisvara Temple (there)

| ID | Claim | Evidence Category | Source | Source Type | Date | Confidence | Historical Debate | Game Usage | Misinterpretation Risk | Required Disclaimer |
|---|---|---|---|---|---|---|---|---|---|---|
| C1 | Gangaikondacholapuram was founded as a new imperial capital, distinct from Thanjavur | DOCUMENTED | Inscriptions naming the capital; ASI archaeological survey | Epigraphic + archaeological | c. 1025 CE onward | KNOWN | None on existence; some debate on exact founding chronology relative to campaign end | Act 6 premise | Low | None |
| C2 | The Brihadisvara Temple at Gangaikondacholapuram (distinct from the Thanjavur temple of the same name) was built under Rajendra I | DOCUMENTED | Temple inscriptions; UNESCO "Great Living Chola Temples" documentation | Epigraphic + UNESCO | c. 1025–1035 CE | KNOWN | Some debate on exact completion date | Act 7 centerpiece | Low | None |
| C3 | The temple is architecturally related to but smaller/different in specific execution from the Thanjavur temple | DOCUMENTED | ASI architectural survey, comparative scholarship | Archaeological | — | KNOWN | Ongoing scholarly discussion of stylistic evolution between the two temples | Art Direction reference | Low | Codex should note it as a related but distinct building, not a copy |
| C4 | The city's full urban layout (residential zones, markets, administrative buildings) beyond the temple and major reservoir | UNCERTAIN/UNKNOWN | Partial archaeological remains | Archaeological | — | UNCERTAIN | Much of the city's non-monumental fabric has not survived or been fully excavated | World Bible §4.5/4.6 in-game layout | High if presented as excavated fact | Explicitly tagged [FICTIONAL] extrapolation in Codex for non-monumental city layout |

## D. Water Management / The Reservoir Tradition

| ID | Claim | Evidence Category | Source | Confidence | Historical Debate | Game Usage | Required Disclaimer |
|---|---|---|---|---|---|---|---|
| D1 | A large reservoir (associated with the name "Cholagangam") was constructed at Gangaikondacholapuram | DOCUMENTED (reservoir existence) | Archaeological remains, later inscriptions/tradition | LIKELY–KNOWN on existence | Scale and exact original extent debated by archaeologists | Act 8 Lion Well puzzle location | Codex separates "reservoir existed" (solid) from "filled with Ganga water" (tradition) |
| D2 | The reservoir was symbolically associated with water carried from the Ganga campaign | PLAUSIBLE RECONSTRUCTION / tradition | Later textual tradition, not a contemporary engineering record | UNCERTAIN | This is a well-known traditional claim but not independently verifiable as literal historical fact | Central to Lion Well puzzle narrative framing | Must be framed as "tradition holds that..." not asserted fact |
| D3 | Chola-era water management generally included canal/sluice engineering supporting agriculture and urban water supply | DOCUMENTED (general pattern across Chola territory) | Inscriptions recording irrigation grants/management; archaeological remains elsewhere in Chola territory | KNOWN (general pattern) / UNCERTAIN (specific mechanism at this site) | Specific mechanical details of any one system are reconstructed, not directly attested at engineering-diagram level | Lion Well puzzle mechanics | Puzzle mechanics are [FICTIONAL] gameplay abstraction of a [DOCUMENTED] general practice |

## E. Trade, Merchant Guilds, Maritime/Navy

| ID | Claim | Evidence Category | Source | Confidence | Historical Debate | Game Usage | Required Disclaimer |
|---|---|---|---|---|---|---|---|
| E1 | Organized merchant guilds (e.g., the Ainnurruvar) operated across South India and into Southeast Asia during this period | DOCUMENTED | Guild inscriptions found across South India and Southeast Asia | KNOWN | Some debate on the precise organizational structure and reach | Port location, merchant NPCs, Trade Ledger puzzle | None significant |
| E2 | The Chola state sent official missions to Song-dynasty China | DOCUMENTED | Chinese Song dynastic records | KNOWN | Some debate on frequency/motive framing (tribute vs. trade diplomacy) | Codex/background lore | Frame as diplomatic-trade mission, not "tribute" without nuance |
| E3 | The Chola navy was capable of significant overseas projection (per the Srivijaya campaign, entry A3) | DOCUMENTED (capability demonstrated) | Inscriptions, foreign records | LIKELY–KNOWN | Fleet size/composition specifics are UNCERTAIN | Naval Design Bible (Doc 12) baseline | Do not invent specific ship counts/tonnage and present as historical |
| E4 | Specific ship construction techniques/designs used by the Chola navy | UNCERTAIN/UNKNOWN | Limited direct archaeological evidence; inference from regional shipbuilding traditions | UNCERTAIN | Genuine evidentiary gap | Ship art/design (Doc 12) | Must be tagged [PLAUSIBLE RECONSTRUCTION], built from regional maritime tradition, not asserted as documented fact |

## F. Administration, Social Organization

| ID | Claim | Evidence Category | Source | Confidence | Historical Debate | Game Usage | Required Disclaimer |
|---|---|---|---|---|---|---|---|
| F1 | Local self-governing village assemblies (sabhas) with documented administrative procedures existed in Chola territory | DOCUMENTED | Uttaramerur inscriptions (slightly predate Rajendra but reflect continuous administrative culture) | KNOWN | Some debate on how uniformly this model applied across all Chola territory | Faction Bible (Doc 14) administrative faction | Note inscriptions are from a specific locality, generalized carefully |
| F2 | Temple institutions functioned as significant economic and administrative actors (land grants, employment, redistribution) | DOCUMENTED | Temple inscriptions recording grants and administration | KNOWN | None significant | Economy Bible (Doc 15), temple faction | None |
| F3 | Detailed social stratification and daily social organization beyond administrative/temple records | UNCERTAIN | Inference from inscriptions, limited by what inscriptions typically record (land, grants, donations) | UNCERTAIN | Significant gaps in evidence for non-elite daily life | NPC Bible (Doc 13) — many NPC "ordinary life" details are necessarily [FICTIONAL] built on general regional/period scholarship, not site-specific evidence | Codex should not claim ordinary-NPC daily life details are directly attested |

## G. Craft, Material Culture, Bronze Casting

| ID | Claim | Evidence Category | Source | Confidence | Historical Debate | Game Usage | Required Disclaimer |
|---|---|---|---|---|---|---|---|
| G1 | Chola-era bronze casting via lost-wax (cire perdue) technique reached a recognized artistic peak in this period | DOCUMENTED | Surviving bronzes (museum collections), temple inventory inscriptions | KNOWN | None significant | Artisan character, craft NPC systems | None |
| G2 | Stone temple construction techniques (load-bearing granite, minimal mortar use) as generally practiced in Dravidian temple architecture of this period | DOCUMENTED | Archaeological/architectural scholarship | KNOWN | Some technical debate on specific load/lifting methods used for the largest stones (e.g., the Thanjavur temple's capstone) | Stone Alignment puzzle basis | Puzzle is a gameplay abstraction, not a literal engineering reconstruction |
| G3 | Specific clothing, jewelry, and everyday material culture details for non-elite Chola-era people | UNCERTAIN | Limited direct evidence (organic materials rarely survive); inference from sculpture/temple imagery | UNCERTAIN | Sculptural depictions are stylized/idealized, not photographic | Character Art Bible (Doc 31) | Must note sculptural sources are stylized, not literal documentary evidence |

## H. Language & Writing

| ID | Claim | Evidence Category | Source | Confidence | Historical Debate | Game Usage | Required Disclaimer |
|---|---|---|---|---|---|---|---|
| H1 | Tamil was the primary administrative/inscriptional language of the Chola state, with Sanskrit used in specific formal/religious/literary contexts | DOCUMENTED | Corpus of surviving Chola inscriptions (predominantly Tamil, with Sanskrit portions in some) | KNOWN | Some scholarly discussion of bilingual inscription conventions and their significance | Voice & Dialogue Bible (Doc 22) language split | None |
| H2 | The specific script forms used evolved over the period and can help date inscriptions | DOCUMENTED | Epigraphic paleography scholarship | KNOWN | Technical scholarly debate on fine-grained dating by script form | Inscription Decoding puzzle mechanic (script matching) | Puzzle simplifies real paleographic method for gameplay — note as abstraction |

---

## Open Questions
- Full sourcing pass still owed for: specific weapons/armament typical of Chola-era soldiers (Doc 10 needs this before final lock), specific festival practices (only include if separately sourced, per Foundation Bible caution on inventing festivals), and detailed regional cuisine.
- E4 (ship construction specifics) is the single largest evidentiary gap directly blocking Doc 12 — flag to Historical Research Director as priority research task.
- F3/G3 (everyday non-elite material culture) will always carry higher uncertainty than elite/royal/temple material — Character Art Bible and NPC Bible should be written with this asymmetry in mind rather than treated as equally well-evidenced.

## Dependencies on Other Documents
Feeds Docs 06 (Character Bible), 09 (Puzzle Bible), 10 (Combat), 12 (Naval), 13 (NPC/AI), 14 (Factions), 16 (Architecture), 22 (Voice/Dialogue), 23 (Codex), 31 (Character Art).

## Acceptance Criteria
- Every entry carries all required columns.
- Confidence ratings distinguish KNOWN/LIKELY/UNCERTAIN/UNKNOWN, not just DOCUMENTED/FICTIONAL binary.
- Every UNCERTAIN/UNKNOWN entry has an explicit disclaimer requirement carried through to Codex implementation (Doc 23).


---



<!-- ===== doc04_story_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 04: STORY BIBLE

**Document ID:** SB-04 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Complete narrative spine, Prologue through Epilogue, at production depth.
**Scope:** Full main story. Side/faction/scholar quest content lives in Doc 07 and hangs off this spine.
**Dependencies:** Foundation Bible v1 (Act structure, evidence tags), Doc 02 (locations), Doc 03 (evidence), Doc 06 (characters, referenced by role until Doc 06 is authored in full).
**Canonical assumptions:** History does not change based on player choice (per your Ending rule) — only Arulan's personal arc, relationships, and reputation branch.

---

## PROLOGUE — "STONE REMEMBERS" (framing device)

- **Location:** Modern-day archaeological ruins of Gangaikondacholapuram (brief cold open)
- **Time:** Present day, then cut to 11th century
- **Historical context:** [DOCUMENTED] — the site exists today as a UNESCO-recognized ruin
- **Story purpose:** frame the entire game as historical memory being reconstructed, set up the closing line ("Stone remembers") as bookend
- **Characters:** none named — unseen narrator only
- **Main conflict:** none yet — pure framing
- **Player objective:** none (non-interactive cold open, kept under 60 seconds)
- **Gameplay:** none
- **Puzzle / Combat:** none
- **Dialogue:** single narrator line establishing tone, then silence
- **Cutscenes:** yes — the only fully non-interactive cold open in the game
- **Historical evidence:** modern ruins are [DOCUMENTED]; the transition into "11th century" is clearly a fictional device, not a claim of time travel or literal reenactment
- **Fictional elements:** the narrative device itself
- **Transition:** hard cut to Act 1, Thanjavur, dawn

---

## ACT 1 — THE SHADOW OF RAJARAJA

- **Location:** Thanjavur (World Bible §4.1)
- **Time:** Early 11th century, shortly before the northern expedition is announced
- **Historical context:** [DOCUMENTED] Thanjavur as established Chola capital under the legacy of Rajaraja I
- **Story purpose:** establish ordinary-world stakes before scale escalates; introduce Arulan as the player's window character
- **Characters:** Arulan (introduced), background craftsmen/soldiers/merchants (unnamed)
- **Main conflict:** none yet — Arulan is an observer; the seed conflict is the *coming disruption* to a stable world
- **Player objective:** traverse Thanjavur, absorb the world, reach the temple square in time for the royal messenger scene
- **Gameplay:** pure exploration/traversal, tutorial-weight investigation (first inscription-scan prompt, low stakes)
- **Puzzle:** Inscription Decoding Tier 0 (tutorial variant, optional)
- **Combat:** none
- **Dialogue:** ambient NPC barks only; no named-character dialogue tree yet
- **Cutscenes:** opening cinematic per Production Bible v2 §10 (already scripted)
- **Historical evidence:** environment grounded in Thanjavur temple/city evidence (Doc 03 entry A1)
- **Fictional elements:** Arulan and his specific path through the city
- **Transition:** title card → Act 2, Royal Court

## ACT 2 — THE ROYAL COURT

- **Location:** Royal Court district (World Bible §4.2)
- **Time:** Days after Act 1
- **Historical context:** [PLAUSIBLE RECONSTRUCTION] court function; [DOCUMENTED] that Rajendra I was preparing major campaign activity in this period
- **Story purpose:** introduce Rajendra Chola I (historical), establish the political ensemble, plant the antagonist's ideological position as background texture (not yet confrontational)
- **Characters:** Rajendra Chola I (historical, dramatized), Arulan, first appearances of Scholar/Architect/Political Rival in court context
- **Main conflict:** implicit — the empire is expanding faster than some in the court believe it can administer (antagonist's position, seeded not stated)
- **Player objective:** navigate the court, learn of the coming expedition through investigation rather than exposition dump
- **Gameplay:** dialogue system introduction, document investigation, map examination
- **Puzzle:** first Royal Seal Verification puzzle (low stakes — a training example, not yet plot-critical)
- **Combat:** none
- **Dialogue:** first major dialogue trees; player's first branching choice (cosmetic — how Arulan is perceived by the court, not a hard story fork)
- **Cutscenes:** Rajendra's court introduction cinematic
- **Historical evidence:** Doc 03 entries A1–A2, B1
- **Fictional elements:** all specific court dialogue (never presented as authentic quotation, per your critical rule)
- **Transition:** army mobilization order given → Act 3

## ACT 3 — THE NORTHERN EXPEDITION

- **Location:** Northern corridor (World Bible §4.3)
- **Time:** Campaign season, historically situated c. 1023–1025 CE per Doc 03 entry B1
- **Historical context:** [DOCUMENTED] that the expedition happened and led to the "Gangaikonda" title; [UNCERTAIN/PLAUSIBLE RECONSTRUCTION] for route/tactical specifics — **on-screen label "HISTORICAL RECONSTRUCTION" active throughout this Act**
- **Story purpose:** establish logistics-driven stakes; deepen Arulan's role from observer to active participant (he travels with the army in a support capacity — courier/scout, not a soldier of rank)
- **Characters:** Rajendra (present but at a command remove from Arulan), Naval/military NPCs, first meaningful antagonist-adjacent scene (a rival officer voicing the "overextension" concern openly)
- **Main conflict:** external (campaign hardship) and internal (the overextension question becomes explicit)
- **Player objective:** scout, manage supply, navigate diplomacy with local populations encountered en route
- **Gameplay:** logistics systems (Doc 01 §11 principle — combat is a consequence system, not the loop here)
- **Puzzle:** river-crossing/elevation logistics puzzle (Production Bible v2 §2.8 variant)
- **Combat:** first real combat encounters, framed as consequences of logistics failure or diplomatic breakdown, not random encounters
- **Dialogue:** the antagonist-adjacent rival officer's first ideological confrontation with Arulan
- **Cutscenes:** none major — Act 3 is gameplay-forward
- **Historical evidence:** Doc 03 entries B1–B4
- **Fictional elements:** all specific incidents; battles are not asserted as documented per your explicit rule
- **Transition:** the army reaches the northern river region → Act 4

## ACT 4 — THE GANGA

- **Location:** The Ganga set-piece (World Bible §4.4)
- **Time:** Climax of the expedition
- **Historical context:** [PLAUSIBLE RECONSTRUCTION] — explicitly framed "INSPIRED BY THE HISTORICAL EXPEDITION" on-screen, per your instruction
- **Story purpose:** emotional peak; reframe the expedition from conquest to identity-forming moment for the empire and for Arulan personally
- **Characters:** Rajendra (present, minimal dialogue — this scene is deliberately non-verbal per your direction), Arulan
- **Main conflict:** internal — Arulan reckons with what he has seen the campaign cost
- **Player objective:** minimal — walk to the riverbank, witness the cinematic
- **Gameplay:** near-none; this act is intentionally the game's quietest moment
- **Puzzle / Combat:** none
- **Dialogue:** minimal, sound-design-led per Production Bible v2 §4
- **Cutscenes:** the Ganga cinematic (river, minimal sound, camera to horizon, cut to messenger, "THE JOURNEY HOME BEGINS")
- **Historical evidence:** Doc 03 entry B3
- **Fictional elements:** the specific staging of the scene
- **Transition:** hard cut, messenger departs south → Act 5

## ACT 5 — THE RETURN

- **Location:** Northern corridor (return leg) → approach to the Chola heartland
- **Time:** Following months, per campaign duration
- **Historical context:** [PLAUSIBLE RECONSTRUCTION] return logistics
- **Story purpose:** victory creates a new problem (building the capital) — pivot the player from military to civic stakes
- **Characters:** Arulan, returning army, first explicit political consequence scene (the antagonist's faction gains a hearing at court over the campaign's cost)
- **Main conflict:** political — what does the empire do with this victory
- **Player objective:** manage the return journey, arrive to learn of Rajendra's decision to found a new capital
- **Gameplay:** logistics/diplomacy systems continue, lighter combat than Act 3
- **Puzzle:** Map Reconstruction (Production Bible v2 §2.7) — reassembling reports from the campaign into a coherent account, doubling as an investigation-system teaching moment
- **Combat:** minor, tapering off
- **Dialogue:** political consequence dialogue at court (remote, reported to Arulan rather than fully dramatized on-screen, to keep pacing tight)
- **Cutscenes:** brief — Rajendra's decree founding the new capital
- **Historical evidence:** Doc 03 entry C1
- **Fictional elements:** the specific political maneuvering
- **Transition:** decree issued → Act 6

## ACT 6 — THE BIRTH OF GANGAIKONDACHOLAPURAM

- **Location:** Gangaikondacholapuram construction zone (World Bible §4.5)
- **Time:** Beginning of the construction period, c. 1025 CE onward
- **Historical context:** [DOCUMENTED] founding; [FICTIONAL] specific construction-phase incident
- **Story purpose:** the game's structural pivot — from campaign narrative to civic-building narrative; Arulan is reassigned here in a new role (liaison/investigator, setting up the rest of the game)
- **Characters:** Architect (introduced), Scholar (introduced), site workers, first direct antagonist scene
- **Main conflict:** resource/administrative pressure — is the new capital being built sustainably or too fast
- **Player objective:** establish presence at the site, meet key NPCs, begin resource-management gameplay
- **Gameplay:** resource management (stone/timber/metal/food/water/labor/transport/tools) and architectural planning systems introduced
- **Puzzle:** Elevation & Load Deduction (Production Bible v2 §2.8)
- **Combat:** none yet — this act re-establishes a "safe hub" tone before the conspiracy thread escalates
- **Dialogue:** Architect and Scholar relationship-building dialogue
- **Cutscenes:** site-arrival cinematic
- **Historical evidence:** Doc 03 entries C1, C4
- **Fictional elements:** all named site personnel and specific incidents
- **Transition:** construction underway → Act 7

## ACT 7 — THE GREAT TEMPLE

- **Location:** Temple construction zone
- **Time:** Concurrent with Act 6–8 (temple construction spans multiple acts)
- **Historical context:** [DOCUMENTED] — Brihadisvara Temple, Gangaikondacholapuram (Doc 03 entry C2)
- **Story purpose:** establish craft/architecture as a core value of the world, deepen Architect relationship
- **Characters:** Architect, sculptors/stone workers
- **Main conflict:** craft pressure — deadlines vs. quality, echoing the larger overextension theme at a human scale
- **Player objective:** assist temple construction, solve architectural puzzles
- **Gameplay:** Stone Alignment system (all tiers, escalating across this and later visits)
- **Puzzle:** Stone Alignment Tiers 1–3 (Production Bible v2 §2.1)
- **Combat:** none
- **Dialogue:** craft-focused, deepens Architect character arc
- **Cutscenes:** none major
- **Historical evidence:** Doc 03 entries C2–C3, G2
- **Fictional elements:** all specific construction incidents
- **Transition:** temple construction advances → Act 8 (water systems, concurrent thread)

## ACT 8 — THE LION WELL

- **Location:** Reservoir/canal zone
- **Time:** Concurrent with Act 7
- **Historical context:** [DOCUMENTED] reservoir existence; [PLAUSIBLE RECONSTRUCTION]/tradition for the Ganga-water symbolism (Doc 03 entries D1–D2)
- **Story purpose:** pay off the Act 4 Ganga cinematic thematically — the water carried home becomes literal civic infrastructure
- **Characters:** water engineer NPCs, Scholar (interprets the symbolic significance)
- **Main conflict:** technical — restoring flow to a system that isn't yet complete
- **Player objective:** solve the Lion Well puzzle chain, restore water flow
- **Gameplay:** water engineering puzzle system, full 6 stages
- **Puzzle:** Lion Well (Production Bible v2 §2.2), complete
- **Combat:** none
- **Dialogue:** Scholar's reflection on the tradition vs. documented-fact distinction (in-fiction reinforcement of the game's evidence-honesty pillar)
- **Cutscenes:** hidden inscription reveal (stage 6)
- **Historical evidence:** Doc 03 entries D1–D3
- **Fictional elements:** specific puzzle mechanism
- **Transition:** water restored, hidden inscription found → feeds Act 9

## ACT 9 — THE INSCRIPTION SYSTEM

- **Location:** Site office / archive (new sub-location)
- **Time:** Concurrent with Act 6–8, culminating here
- **Historical context:** [DOCUMENTED] general inscriptional practice (Doc 03 entry H1–H2)
- **Story purpose:** formalize the investigation/Codex system as a core pillar; escalate the conspiracy thread using evidence gathered across Acts 6–8
- **Characters:** Scholar (central), Architect and site officials (conspiracy-adjacent)
- **Main conflict:** the resource irregularities from Act 6 resolve into a genuine political conspiracy thread — is the antagonist sabotaging the project, or exposing real overreach?
- **Player objective:** compile evidence, build the Royal Archive, confront the emerging conspiracy
- **Gameplay:** full investigation chain (Doc 11 pattern: discover → translate → cross-reference → locate → question → find contradiction → investigate → resolve)
- **Puzzle:** Inscription Decoding higher tiers, Royal Seal Verification (plot-critical instance)
- **Combat:** first ambush encounter tied to the conspiracy (mirrors vertical-slice Q7)
- **Dialogue:** major branching dialogue — how Arulan handles the evidence (confront the Architect, go to Rajendra directly, or investigate further first)
- **Cutscenes:** ambush sequence
- **Historical evidence:** Doc 03 entries H1–H2; the conspiracy content itself is [FICTIONAL]
- **Fictional elements:** the entire conspiracy plot
- **Transition:** evidence compiled → Act 10

## ACT 10 — THE IMPERIAL MAP

- **Location:** Imperial map / archive room, then travel unlocked to broader regions
- **Time:** Following the Act 9 confrontation
- **Historical context:** [DOCUMENTED] general Chola administrative/territorial framework (Doc 03 entry F1)
- **Story purpose:** widen the player's world after the tightly-scoped construction-zone acts; set up the maritime act
- **Characters:** Political Rival (fuller introduction), Rajendra (remote, via correspondence)
- **Main conflict:** the political consequences of Act 9's confrontation ripple outward
- **Player objective:** use the imperial map system to plan and unlock new regions (political/trade/military/maritime/temple/agriculture/water/cultural layers)
- **Gameplay:** map system as a mechanical and narrative device simultaneously
- **Puzzle:** Map Reconstruction (further use, now at higher stakes)
- **Combat:** none
- **Dialogue:** Political Rival introduction
- **Cutscenes:** none major
- **Historical evidence:** Doc 03 entry F1
- **Fictional elements:** the specific map/region content beyond documented core geography
- **Transition:** maritime region unlocked → Act 11

## ACT 11 — THE MARITIME WORLD

- **Location:** Representative port (World Bible §4.7) and surrounding maritime network
- **Time:** Concurrent with late construction period
- **Historical context:** [DOCUMENTED] Chola maritime trade network (Doc 03 entries E1–E3)
- **Story purpose:** broaden scope to the empire's international dimension; give the Naval Commander and Merchant characters their arcs
- **Characters:** Naval Commander, Merchant, foreign traders
- **Main conflict:** external (navigation/weather/diplomacy challenges), and a subplot tying trade-network irregularities back to the Act 9 conspiracy
- **Player objective:** navigate, trade, resolve port-level political/economic tension
- **Gameplay:** naval navigation, cargo/diplomacy systems
- **Puzzle:** Star-Sight Navigation, Trade Ledger Reconciliation
- **Combat:** light naval encounters (grounded — no impossible ship technology, per your rule)
- **Dialogue:** Naval Commander and Merchant arcs deepen
- **Cutscenes:** port arrival/landmark reveals
- **Historical evidence:** Doc 03 entries E1–E4
- **Fictional elements:** specific port incidents, ship-design specifics (flagged per Doc 03 entry E4 gap)
- **Transition:** conspiracy thread resolves via maritime evidence → Act 12

## ACT 12 — THE LIVING CITY

- **Location:** Gangaikondacholapuram, living-city state (World Bible §4.6)
- **Time:** Near-completion of the capital
- **Historical context:** [DOCUMENTED] final built state of the city and temple
- **Story purpose:** payoff — the city the player has watched under construction for most of the game is now alive; resolve the conspiracy/antagonist arc; final choices before the ending
- **Characters:** full cast returns; final confrontation with the antagonist
- **Main conflict:** climax of the administrative-overreach question — the game should not resolve this as simply "right" or "wrong" per your antagonist design note
- **Player objective:** final investigation/confrontation sequence, then free time in the living city before the ending triggers
- **Gameplay:** full living-world showcase (NPC routines, festivals where separately sourced, dynamic weather/season)
- **Puzzle:** capstone puzzle combining systems from multiple pillars (stone + water + inscription), used as the final gate before the ending
- **Combat:** final confrontation, grounded (no boss-fight fantasy escalation)
- **Dialogue:** major branching — determines which of the three endings triggers
- **Cutscenes:** ending cinematic (three variants, Doc 27/Epilogue below)
- **Historical evidence:** Doc 03 entries C1–C3
- **Fictional elements:** the antagonist arc resolution, entirely fictional
- **Transition:** → Epilogue

---

## EPILOGUE — THE LEGACY

- **Location:** Gangaikondacholapuram (living city) → modern ruins (bookend to Prologue)
- **Time:** Some time after Act 12's resolution, then present day
- **Historical context:** [DOCUMENTED] that the city and empire eventually declined; modern ruins are [DOCUMENTED] present-day fact
- **Story purpose:** close the "empires disappear, cities change, stone remembers" theme; make clear that history continued beyond the fictional story regardless of player choice
- **Characters:** Arulan (aged, per ending variant), narrator (bookend device)
- **Main conflict:** none — resolution
- **Player objective:** final walk through the completed city (ending-variant-specific framing), non-interactive closing cinematic
- **Gameplay:** minimal/none
- **Puzzle / Combat:** none
- **Dialogue:** narrator closing line ("Empires disappear. Cities change. Stone remembers.")
- **Cutscenes:** yes — bookends the Prologue's modern-ruins framing
- **Historical evidence:** the fact of eventual imperial decline and the site's survival into the present as a ruin is [DOCUMENTED]
- **Fictional elements:** none in this closing frame — deliberately, to land the theme
- **Transition:** end credits

---

## Ending Variants (summary — full detail owed in a dedicated Doc 04b if prioritized)
Per your Ending rule: history does not change. All three variants show the same historical city and the same eventual fate of the empire; they differ only in:
1. **The Builder's Path** — Arulan is remembered locally as a builder/administrator; relationship-heavy ending (Architect/Scholar bonds emphasized).
2. **The Investigator's Path** — Arulan is remembered as the one who exposed or clarified the conspiracy; codex/evidence-heavy ending.
3. **The Quiet Path** — Arulan steps back from public life; a more personal, understated ending emphasizing what he witnessed rather than public legacy.

## Open Questions
- Whether the antagonist's arc should permit a fourth "reconciliation" outcome distinct from the three endings, or remain folded into all three as a resolved subplot — needs Narrative Director decision.
- Exact triggers determining which ending variant fires — needs Quest Bible (Doc 07) branching-flag design.
- Whether Act 10's Political Rival deserves earlier introduction (currently first full appearance is late) — flagged as a pacing risk.

## Dependencies on Other Documents
Doc 02 (locations), Doc 03 (evidence), Doc 06 (full character bible — many characters here are referenced by role pending that document), Doc 07 (quest-level implementation of every beat above), Doc 09 (puzzle placements referenced throughout).

## Acceptance Criteria
- All 14 sections (Prologue, Acts 1–12, Epilogue) present with all 15 required fields.
- No historical event altered by player choice; only personal/relationship/legacy content branches.
- Every act's evidence tags trace back to a Doc 03 entry ID or are explicitly marked [FICTIONAL].


---



<!-- ===== doc05_cinematic_script.md ===== -->

# GANGAIKONDA — DOCUMENT 05: CINEMATIC SCRIPT

**Document ID:** CS-05 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full shot-level screenplay for the game's cinematics.
**Scope:** Story Bible (Doc 04) identifies cinematics in: Prologue, Act 1, Act 2, Act 4, Act 5, Act 6, Act 8, Act 9, Act 11, Act 12 (×3 endings), Epilogue — 12 cinematic sequences total.
**Dependencies:** Doc 04 (Story Bible beats), Doc 03 (evidence tags for any historically-referential content), Doc 06 (character voice, referenced pending full authoring).

**Scope note:** shot-by-shot screenplay for all twelve at once, done honestly, is a feature-film-length screenwriting pass. Below are the five structurally load-bearing cinematics fully realized at shot level — the two bookends (Prologue/Epilogue), the two tonal extremes (Act 1 establishing vs. Act 4 restraint), and one full ending variant as a template for the other two. The remaining seven (Act 2, 5, 6, 8, 9, 11, and endings 2–3) follow the identical shot-list format demonstrated here and should be scripted next once dialogue for Doc 06's full character voices is locked — writing their dialogue now, ahead of that, risks contradicting character voice work not yet done.

**Format key per shot:** Shot # · Camera · Lens · Movement · Environment · Lighting · Action · Expression · Dialogue · Sound · Music · VFX · Transition.

---

## CINEMATIC 001 — PROLOGUE ("Stone Remembers" cold open)
**Location:** Modern ruins of Gangaikondacholapuram, then 11th-c. Thanjavur · **Time:** Present day → dawn, 11th c. · **Characters:** none named (V.O. narrator only) · **Gameplay handoff:** hard cut to player control at start of Act 1, Thanjavur streets.

**SHOT 001** — Wide, 35mm equiv., static. Environment: sunlit stone ruins, temple base visible, modern tourists blurred/absent from frame (empty-of-people framing preferred). Lighting: harsh midday sun, high contrast. Action: none — pure environment. Expression: N/A. Dialogue: none. Sound: wind, distant birdsong. Music: none. VFX: subtle heat shimmer. Transition: hold 3 sec.

**SHOT 002** — Slow push-in, 50mm, dolly. Environment: same ruins, camera moves toward a single worn inscription stone. Lighting: same. Sound: wind fades under. Music: single low string note enters. VFX: none. Transition: hard cut.

NARRATOR (V.O.)
Every empire believes it will be remembered exactly as it was.

**SHOT 003** — Match cut: the same stone, now unweathered, being carved — we have jumped to the 11th century. Camera: static wide, low angle. Lens: 28mm. Lighting: dawn, warm low sun. Action: a sculptor's hands carving. Expression: N/A (hands only). Sound: chisel on stone, fades up. Music: motif continues, instrumentation grows (per Production Bible v2 audio doctrine). VFX: stone dust in light shaft. Transition: cut to wide of Thanjavur waking.

**SHOT 004** — Wide establishing, 24mm, slow crane up. Environment: Thanjavur at dawn, temple tower, city waking. Lighting: golden hour. Sound: bells, city murmur rising. Music: full motif. VFX: mist/dust atmospherics. Transition: dissolve into Act 1 gameplay space; camera settles behind Arulan as player control begins.

**Gameplay handoff note:** control hands to the player mid-crane, camera settling into the Act 1 exploration follow-cam without a hard cut — minimizes the seam between cinematic and gameplay per Doc 01 camera principles.

---

## CINEMATIC 002 — ACT 1 OPENING (full shot expansion of Production Bible v2 §10)
**Location:** Thanjavur · **Time:** Dawn, continuing from Cinematic 001 · **Characters:** Arulan, background craftsmen/soldiers/merchants · **Gameplay handoff:** ends on title card, then player control resumes for Act 1 free exploration.

**SHOT 001** — Over-the-shoulder follow, 35mm, handheld-light (period-appropriate subtle sway, not shaky-cam). Environment: side street into main square. Lighting: warm dawn. Action: Arulan walking. Expression: neutral, alert, curious. Sound: footsteps, waking city. Music: motif continues low. VFX: none. Transition: continuous.

**SHOT 002** — Push past Arulan to reveal stone sculptors mid-carving. Lens: 40mm. Lighting: warm, directional. Action: sculptors working, unbothered by passersby. Sound: chisel work layered with ambient. Music: unchanged. VFX: stone dust. Transition: cut.

**SHOT 003** — Medium, static. Environment: bronze caster's workshop. Lighting: warm fire-glow contrast against cool morning light. Action: pouring/working bronze, heat shimmer. Sound: metal, fire. Music: unchanged. VFX: heat shimmer, sparks. Transition: cut.

**SHOT 004** — Medium two-shot. Environment: two scribes at a stall. Action: gesturing over a ledger, visibly frustrated. Expression: irritation, urgency. Dialogue:

CRAFTSMAN/SCRIBE 1
Another shipment delayed. Third this month.

Sound: market ambience under. Music: unchanged. VFX: none. Transition: cut, following Arulan again.

**SHOT 005** — Wide, temple square. Environment: gathered craftsmen. Lighting: full morning sun. Action: group conversation, Arulan slowing to listen at frame edge. Dialogue:

CRAFTSMAN 2 (O.S.)
They say the army marches again. North, this time. Further than before.

Sound: crowd murmur ducks under dialogue. Music: subtle rise. VFX: none. Transition: cut.

**SHOT 006** — Fast tracking shot, low angle, 24mm. Environment: square, crowd scattering. Action: royal messenger on horseback cutting through at speed. Sound: hooves, crowd reaction. Music: sting, brief. VFX: dust kicked up. Transition: cut to Arulan's face.

**SHOT 007** — Close-up, 85mm, static. Environment: shallow DOF, temple blurred behind. Action: Arulan watching the messenger go. Expression: curiosity, not alarm — deliberately underplayed per Doc 01 tonal target (Act 1 = curiosity, not yet awe/dread). Sound: ambient settles. Music: motif softens. VFX: none. Transition: cut.

**SHOT 008** — Slow push-in on temple tower behind Arulan, gold catching full sun. Lens: 50mm. Lighting: full morning, warm gold highlight on the tower specifically (Art Direction principle: gold as material accent, not wash). Sound: bells. Music: swells briefly, then cuts to silence. VFX: none. Transition: cut to black.

**TITLE CARD:** GANGAIKONDA / गङ्गैकोण्ड — hold 3 sec, fade.

**Gameplay handoff:** fade in on the same temple-square framing, player control active, no camera cut — the world the player now explores is the same space just shown.

---

## CINEMATIC 003 — ACT 4, "THE GANGA" (restraint set-piece)
**Location:** The Ganga (World Bible §4.4) · **Time:** Climax of the northern expedition · **Characters:** Rajendra Chola I (dramatized), Arulan · **Historical framing:** on-screen text "INSPIRED BY THE HISTORICAL EXPEDITION" precedes Shot 001, per Foundation Bible Act 4 rule. **Gameplay handoff:** hard cut to black, then Act 5 gameplay begins on the return journey — no gradual handoff here, deliberately, to preserve the scene's finality.

**PRE-TEXT CARD:** "INSPIRED BY THE HISTORICAL EXPEDITION" — hold 2 sec, fade.

**SHOT 001** — Extreme wide, static, 24mm. Environment: army assembled at the riverbank, seen small against the landscape. Lighting: overcast, diffuse — no dramatic gold-hour lighting here, deliberately flat per audio-doctrine restraint principle extended to visuals. Sound: near-silence — wind, water only, all crowd/ambient sound reduced far below Act 1–3 levels. Music: none. VFX: none. Transition: slow cut.

**SHOT 002** — Medium, Rajendra alone at the water's edge, seen from behind/side, not front-on hero framing. Lens: 50mm. Action: standing, still. Expression: not shown in detail — camera deliberately does not push in for a legible emotional read, avoiding the invented-inner-thought problem at the visual level, not just the dialogue level. Sound: water. Music: none. Dialogue: none. VFX: none. Transition: cut.

**SHOT 003** — Close on water moving over stones. Lens: macro-ish, 100mm equiv. Lighting: flat overcast. Sound: water only, isolated. Music: single sustained low tone enters, barely audible. VFX: none. Transition: slow cut.

**SHOT 004** — Wide, camera drifts laterally past the assembled army toward the horizon, no one addressed directly. Lens: 28mm, slow dolly. Sound: wind rises slightly. Music: tone sustains, no melodic development. VFX: none. Transition: match cut.

**SHOT 005** — Cut to a royal messenger already riding south, wide tracking shot. Lens: 35mm. Lighting: shifts warmer — we are narratively already moving toward home. Sound: hooves, wind. Music: tone resolves into a simple two-note motif (callback to Cinematic 001's opening note). Transition: cut to black.

**TEXT CARD:** "THE JOURNEY HOME BEGINS." — hold, fade.

---

## CINEMATIC 004 — ACT 12 ENDING, VARIANT 1: "THE BUILDER'S PATH"
**Location:** Gangaikondacholapuram, living city → modern ruins (bookend to Prologue) · **Time:** Near-completion, then epilogue timeskip · **Characters:** Arulan (aged), Architect, Scholar (if relationship maintained), narrator · **Trigger condition:** per Doc 04, fires when player's relationship/reputation state favors civic-building/relationship resolution over investigation-focused resolution — exact flag logic owed to Doc 07.

**SHOT 001** — Wide, dusk, full city visible and complete (payoff of construction-state progression across the game). Lens: 24mm, slow crane. Lighting: warm dusk, temple gold catching last light (Art Direction gold-accent principle, full payoff here). Action: city fully alive — market closing, temple lamps lighting, NPCs in full evening routine. Sound: full living-city ambience (temple bells, market, water). Music: full thematic statement, first time the main theme plays unrestrained. VFX: lamp-lighting practical-light bloom. Transition: cut.

**SHOT 002** — Medium, Arulan on a rooftop/vantage point overlooking the city, Architect beside him. Lens: 50mm. Action: standing together, looking out, not speaking at first. Expression: quiet satisfaction, not triumphant grinning — tonally consistent with the game's restraint elsewhere. Dialogue:

ARCHITECT
It doesn't look like the drawings anymore.

ARULAN
Good.

Sound: ambient city below. Music: continues, softer under dialogue. VFX: none. Transition: cut.

**SHOT 003** — Close on the temple silhouette against the dusk sky, camera holds. Lens: 85mm. Lighting: silhouette, no fill — pure shape. Sound: bells. Music: swells. VFX: none. Transition: slow dissolve.

**SHOT 004** — Dissolve from the 11th-century temple silhouette to the same silhouette in its modern ruined state (direct visual rhyme with Prologue Shot 001/002). Lens: matched framing to Prologue. Lighting: matches Prologue's harsh midday sun. Sound: wind, birdsong — matches Prologue's sound bed exactly. Music: resolves to the same single low string note that opened Cinematic 001. VFX: none. Transition: hold.

NARRATOR (V.O.)
Empires disappear. Cities change. Stone remembers.

**TITLE CARD:** GANGAIKONDA — hold, fade to credits.

**Note for Variants 2 & 3:** both should end on the identical Shot 003–004 dissolve-to-ruins beat and identical closing narration — per Doc 04's rule that history and the closing theme never change, only what precedes it (the Investigator's Path substitutes Shot 002's dialogue/vantage with a Scholar/Codex-focused beat; the Quiet Path substitutes it with a solitary, dialogue-free version of Shot 002).

---

## CINEMATIC 005 — EPILOGUE (shares structure with Cinematic 004's closing beat)
Per the note above, the Epilogue cinematic is mechanically the same dissolve-to-ruins sequence that closes each ending variant, extended by the framing device's full bookend: this is not a separate shot list but confirmation that Cinematics 001 and 004(/005/006 for the other variants) are designed as a matched pair. No additional shots required beyond what's specified in Cinematic 004 Shots 003–004.

---

## Remaining Cinematics (framework only — pending Doc 06 character-voice lock)
Act 2 (Rajendra's court introduction), Act 5 (capital-founding decree), Act 6 (site-arrival), Act 8 (hidden inscription reveal), Act 9 (ambush sequence), Act 11 (port arrival), and Ending Variants 2–3 all follow the exact shot-field format demonstrated above. Recommend scripting these immediately after Doc 06 (Character Bible) is completed, so Rajendra's, the Scholar's, and the Political Rival's dialogue voices are consistent from first appearance rather than needing a rewrite pass.

## Open Questions
- Exact ending-trigger flag logic (Doc 07 dependency, noted above).
- Whether Cinematic 002 (Act 1) should have a fully non-interactive title card or a very short (1–2 sec) player-input-skippable version — accessibility consideration for Doc 37.

## Dependencies on Other Documents
Doc 04 (Story Bible beats), Doc 06 (character voice — blocking remaining cinematics), Doc 21 (music cues), Doc 07 (ending trigger logic).

## Acceptance Criteria
- Every scripted cinematic includes all required shot-level fields.
- No dialogue attributed to Rajendra Chola I is presented as an authentic historical quotation (confirmed — all dialogue here is explicitly dramatized).
- Historical framing text cards appear exactly where Foundation Bible/Story Bible require them (Act 4 confirmed above).


---



<!-- ===== doc06_character_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 06: CHARACTER BIBLE

**Document ID:** CB-06 · **Version:** 1.0 · **Status:** Draft — all fictional names below are WORKING NAMES pending linguistic authenticity review (Tamil onomastics consultant) before final lock, per Foundation Bible v1 §3 note on Arulan.
**Purpose:** Full specification for every named character.
**Dependencies:** Foundation Bible v1 §3, Doc 03 (evidence for Rajendra), Doc 04 (arc placement).
**Canonical rule carried through every entry below:** historical figures never receive fabricated quotations presented as authentic; all dialogue for Rajendra is explicitly dramatized fiction built on a documented historical frame.

---

## 1. RAJENDRA CHOLA I
- **Historical/Fictional:** Historical
- **Meaning:** regnal name/title, not to be treated as a personal nickname in dialogue
- **Age:** early-to-mid 30s at game start (c. 1014 CE accession context, per Doc 03 entry A2), aging across the story's multi-year span
- **Occupation:** Chola Emperor
- **Background:** [DOCUMENTED] son of Rajaraja Chola I; co-regent then sole ruler (Doc 03 A2)
- **Appearance:** designed from period sculpture/relief conventions (Doc 03 entry G3 caveat applies — sculptural sources are stylized, not photographic); royal regalia per Art Direction gold-as-material principle, not fantasy ornamentation
- **Clothing:** royal Chola court dress reconstructed from temple sculpture and inscriptional description, reviewed by Cultural Sensitivity Consultant before lock
- **Personality:** written as decisive, controlled, rarely fully legible to the player — deliberately kept at a slight remove (see Cinematic 003 direction: camera does not push in on his face) so the game never overclaims insight into his private character
- **Motivation:** [FICTIONAL dramatization] framed around legacy and consolidation — never stated as documented psychological fact in the Codex
- **Fear:** not dramatized explicitly — consistent with the "no invented private thoughts as historical fact" rule; if implied, only through action, never narrated
- **Values:** dramatized as valuing the empire's permanence (temple/capital-building as an expression of this) — again, inference dramatized as character writing, not asserted history
- **Relationships:** distant-but-respectful with Arulan; ideological friction with the Political Rival and (by extension) the Antagonist's position
- **Skills:** command, statecraft (dramatized)
- **Combat style:** not player-fought; if shown in combat (unlikely per grounded-conflict design), never in a stylized "boss" register
- **Dialogue style:** formal, economical — Rajendra speaks less than any other named character, by design
- **Character arc:** static relative to Arulan — he is the fixed historical frame the fictional story moves around, not a character who "develops" in the player-facing sense
- **Quest involvement:** Acts 2, 4, 5 (remote in 9–12)
- **Historical constraints:** no invented quotations presented as authentic (hard rule); every scene involving him needs a Historical Authenticity Consultant pass before lock
- **Voice direction:** restrained, low registered delivery, minimal emotional coloring — let the writing and staging carry weight, not vocal performance flourish
- **Animation direction:** economical gesture, formal posture; avoid modern "expressive" mocap tics that would read anachronistically casual

## 2. ARULAN (protagonist)
- **Historical/Fictional:** Fictional
- **Meaning:** working name, pending Tamil linguistic authenticity review (per Foundation Bible v1)
- **Age:** early-to-mid 20s at game start
- **Occupation:** starts as a minor court-adjacent figure (exact starting role TBD — courier/junior scribe is a strong candidate, pending Narrative Director decision), becomes site liaison/investigator by Act 6
- **Background:** [FICTIONAL] — deliberately kept somewhat open (modest origin, connected enough to the court to plausibly move through it) so he functions as a believable "window character" rather than an implausible insider
- **Appearance:** period-appropriate, non-elite-adjacent styling that reads as "moves between worlds" (market, court, construction site)
- **Clothing:** evolves visibly across acts — court-adjacent dress in Act 1–2, practical campaign gear in Act 3–5, site-worker-adjacent practical dress by Act 6+ (visual storytelling of his role shift)
- **Personality:** observant, quietly principled, initially conflict-avoidant, grows more willing to take political risk across the story
- **Motivation:** starts as simple duty/curiosity, deepens into genuine investment in the capital's fate and the conspiracy's resolution
- **Fear:** being complicit in covering up wrongdoing (thematically ties to the antagonist conflict) — can be dramatized more freely than Rajendra's, since Arulan is fully fictional
- **Values:** honesty, craft, loyalty complicated by conscience
- **Relationships:** central hub — meaningful arcs with Scholar, Architect, and (adversarially) the Antagonist and Political Rival; the three ending variants are essentially three different resolutions of these relationships
- **Skills:** investigation/inscription literacy (grows across the game), light combat competence (not a trained soldier — combat should read as capable-but-not-superhuman)
- **Combat style:** practical, defensive-leaning, period weapons (see Doc 10 for full spec)
- **Dialogue style:** player-selected tone (per Doc 01 §19 dialogue branching), but baseline voice is measured and curious rather than quippy
- **Character arc:** observer → participant → investigator → (branch) builder/investigator/quiet legacy, per the three endings
- **Quest involvement:** every act — player character
- **Historical constraints:** none (fully fictional), but must never be confused in marketing/UI with a documented historical figure
- **Voice direction:** grounded, naturalistic, avoid overly modern idiom
- **Animation direction:** full player-character locomotion/combat/interaction set (see Doc 32)

## 3. THE SCHOLAR
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending linguistic review
- **Age:** older (50s+), read as a mentor figure
- **Occupation:** epigrapher/archivist attached to the royal administration
- **Background:** [FICTIONAL], built on [DOCUMENTED] general existence of scribal/epigraphic professional classes (Doc 03 H1–H2 context)
- **Appearance:** scholarly, practical dress, visibly weathered from fieldwork rather than purely cloistered
- **Clothing:** administrative/scribal dress appropriate to the period, reviewed by Cultural Sensitivity Consultant
- **Personality:** precise, occasionally dryly funny, the game's explicit voice for the evidence-honesty theme — this character should be the one who says "the inscriptions tell us that it happened, not exactly how" (per Doc 03 note)
- **Motivation:** genuine love of the historical record for its own sake; increasingly drawn into the conspiracy thread reluctantly
- **Fear:** that the record will be distorted or destroyed (ties directly into the conspiracy stakes)
- **Values:** rigor, honesty, patience
- **Relationships:** primary mentor figure to Arulan; professionally entangled with the Architect and site administration
- **Skills:** epigraphy, translation, cross-referencing (mechanically the Codex/investigation system's in-fiction embodiment)
- **Combat style:** none — non-combatant
- **Dialogue style:** precise, teacherly without being condescending
- **Character arc:** from institutional caution to active whistleblower-adjacent role in the conspiracy resolution
- **Quest involvement:** Acts 2, 6, 8, 9 (central), 10, 12
- **Historical constraints:** fully fictional but their *method* (how they read inscriptions) must be accurate to real epigraphic practice
- **Voice direction:** warm but exacting
- **Animation direction:** deliberate, careful hand-work animations for inscription-handling scenes

## 4. THE ARCHITECT
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 40s
- **Occupation:** lead architect/engineer for the new capital's temple and construction
- **Background:** [FICTIONAL], built on [DOCUMENTED] general existence of the architectural/engineering profession implied by the temple's construction (Doc 03 C2, G2)
- **Appearance:** practical, site-worn, visibly a craftsperson rather than a courtier
- **Clothing:** craftsman/engineer dress, tools visibly carried
- **Personality:** proud of the work, defensive about deadline pressure, genuinely conflicted when evidence points toward wrongdoing under their nominal authority
- **Motivation:** wants the temple built right, caught between Rajendra's schedule and the Scholar/Arulan's investigation
- **Fear:** the temple (and their legacy) being compromised by corruption they may not have fully seen
- **Values:** craft integrity
- **Relationships:** professional-then-personal bond with Arulan (Act 6 onward), tension with the Antagonist depending on how the conspiracy resolves
- **Skills:** architecture, structural engineering (period-appropriate)
- **Combat style:** none / minimal, non-combatant by default
- **Dialogue style:** direct, craftsperson's vocabulary, impatient with abstraction
- **Character arc:** pride → doubt → (branch-dependent) vindication or complicity reckoning
- **Quest involvement:** Acts 6, 7, 9, 12 (central to "Builder's Path" ending)
- **Historical constraints:** fully fictional, but structural/engineering dialogue must be accurate to real Dravidian construction technique (Doc 03 G2)
- **Voice direction:** grounded, working-professional cadence
- **Animation direction:** hands-on gesture vocabulary (pointing at structures, demonstrating load logic)

## 5. THE NAVAL COMMANDER
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 30s–40s
- **Occupation:** commands a Chola naval vessel/fleet element
- **Background:** [FICTIONAL], built on [DOCUMENTED] Chola naval capability (Doc 03 E3)
- **Appearance:** maritime-practical dress, visibly weathered by sea service
- **Clothing:** naval/maritime period dress, distinct from land-military
- **Personality:** pragmatic, well-traveled, less politically naive than the land-bound characters — has seen the wider trade network firsthand
- **Motivation:** protecting crew and trade network integrity
- **Fear:** losing a ship/crew to negligence (ties into Act 11 stakes)
- **Values:** competence, loyalty to crew over abstract politics
- **Relationships:** professional respect for the Merchant, wary of court politics reaching the fleet
- **Skills:** navigation, naval command, diplomacy with foreign traders
- **Combat style:** naval combat specialist (Doc 12)
- **Dialogue style:** blunt, economical, dry humor
- **Character arc:** minor but complete — introduced and resolved within Act 11
- **Quest involvement:** Act 11 (primary)
- **Historical constraints:** ship-design/tactics dialogue must flag [PLAUSIBLE RECONSTRUCTION] per Doc 03 E4's evidentiary gap — the character can express in-fiction uncertainty about exact ship specs without breaking immersion
- **Voice direction:** weathered, confident
- **Animation direction:** sea-legs physicality, distinct from land-NPC locomotion

## 6. THE MERCHANT
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 40s
- **Occupation:** guild-affiliated trader (Ainnurruvar-style, per Doc 03 E1)
- **Background:** [FICTIONAL], guild context [DOCUMENTED]
- **Appearance:** prosperous but not ostentatious — status shown through material quality (fine but not excessive textiles), consistent with Art Direction restraint principle
- **Clothing:** merchant-class dress reflecting guild status
- **Personality:** networked, information-savvy, transactional but not villainous — a source of both gameplay economy content and conspiracy-adjacent information
- **Motivation:** protecting trade interests, which sometimes aligns and sometimes conflicts with Arulan's investigation
- **Fear:** guild reputation damage
- **Values:** reciprocity — "remembers whether the player helped him," per your original NPC memory example
- **Relationships:** transactional-turning-genuine with Arulan depending on player choices
- **Skills:** trade negotiation, information networks
- **Combat style:** none — non-combatant, relies on hired guards if threatened
- **Dialogue style:** persuasive, quick
- **Character arc:** transactional acquaintance → genuine ally or wary distance, branch-dependent
- **Quest involvement:** Act 11 (primary), light presence earlier via trade-thread quests
- **Historical constraints:** guild structure/practice dialogue sourced to Doc 03 E1
- **Voice direction:** quick, warm-but-guarded
- **Animation direction:** expressive hand gestures typical of negotiation

## 7. THE ARTISAN
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 30s
- **Occupation:** bronze-caster/sculptor
- **Background:** [FICTIONAL], craft context [DOCUMENTED] (Doc 03 G1)
- **Appearance:** working craftsperson, marked by trade (burn scars, tool-worn hands)
- **Clothing:** practical craft dress
- **Personality:** quietly obsessive about the work, a grounding "ordinary life" presence against the political plot
- **Motivation:** mastery of craft, providing for family/apprentices
- **Fear:** losing commission/livelihood if the project's troubles worsen
- **Values:** craftsmanship as its own reward
- **Relationships:** warm, uncomplicated friendship with Arulan — deliberately the least political major character, a narrative pressure valve
- **Skills:** lost-wax bronze casting (Doc 03 G1)
- **Combat style:** none
- **Dialogue style:** plain-spoken, technical when discussing craft
- **Character arc:** stable throughout — provides continuity/comfort rather than dramatic change
- **Quest involvement:** recurring optional content across Acts 6–12, not main-quest-critical
- **Historical constraints:** casting-process dialogue must be accurate to real lost-wax technique
- **Voice direction:** calm, warm
- **Animation direction:** detailed hand-craft animation set (casting, finishing work)

## 8. THE ANTAGONIST
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 40s–50s
- **Occupation:** senior administrative/military official
- **Background:** [FICTIONAL], ideological position (administrative overreach concern) built on [DOCUMENTED] general tensions plausible in a rapidly expanding pre-modern state, per your original design note
- **Appearance:** authoritative, understated rather than villain-coded — no visual signaling of "evil" (per your "not a simplistic evil king" instruction, extended to this character)
- **Clothing:** senior official dress, restrained
- **Personality:** genuinely believes the empire is overextending; methods become ethically compromised as the story progresses, but the underlying critique should remain arguable even after the player opposes his methods
- **Motivation:** [FICTIONAL] prevent what he sees as administrative collapse from overexpansion
- **Fear:** the empire fracturing under its own ambition
- **Values:** stability, sustainability — genuinely held, not a mask
- **Relationships:** ideological ally of the Political Rival (though methods may diverge), adversarial with Arulan/Scholar as the conspiracy unfolds
- **Skills:** administration, political maneuvering
- **Combat style:** commands hired/loyal forces rather than personally fighting as a "boss" — keeps the grounded-conflict design intact
- **Dialogue style:** measured, persuasive — should be genuinely convincing in at least one full scene, not obviously coded as wrong
- **Character arc:** conviction → compromised methods → confrontation, resolution branch-dependent (per Doc 04 Act 12)
- **Quest involvement:** seeded Act 2, active Act 6 onward, central Act 9 and 12
- **Historical constraints:** entirely fictional; Codex must never imply this character or his specific claims are documented history
- **Voice direction:** calm, persuasive, avoid mustache-twirling register entirely
- **Animation direction:** controlled, minimal-gesture — physical restraint as a character trait

## 9. THE POLITICAL RIVAL
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review
- **Age:** 30s
- **Occupation:** court official/rival power center
- **Background:** [FICTIONAL]
- **Appearance:** court dress, sharper/more overtly ambitious styling than the Antagonist's restraint
- **Clothing:** court official dress
- **Personality:** ambitious, opportunistic — distinct from the Antagonist's genuine conviction; uses the overreach debate for personal advancement rather than principle
- **Motivation:** personal power/position
- **Fear:** irrelevance
- **Values:** self-advancement, dressed in the language of loyalty to the throne
- **Relationships:** uneasy alliance-of-convenience with the Antagonist; antagonistic toward Arulan mainly when Arulan threatens his position
- **Skills:** court politics, rhetoric
- **Combat style:** none — political operator, not a combatant
- **Dialogue style:** smooth, plausible, subtly self-serving
- **Character arc:** consistent throughout — a foil showing what the Antagonist's position looks like *without* genuine conviction behind it
- **Quest involvement:** flagged as underdeveloped/late-introduced in Doc 04 Act 10 — recommend moving first appearance earlier (Act 2 or 5) per that document's Open Questions
- **Historical constraints:** entirely fictional
- **Voice direction:** polished, faintly insincere
- **Animation direction:** performative court gesture, slightly too practiced

## 10. THE MESSENGER
- **Historical/Fictional:** Fictional
- **Meaning:** working name pending review; functions partly as a structural/recurring device (per Doc 04's use across Acts 3–6) more than a single fixed individual — recommend deciding whether this is one recurring named character or a rotating role before Doc 07 quest-writing locks
- **Age:** 20s
- **Occupation:** royal courier
- **Background:** [FICTIONAL]
- **Appearance:** practical travel dress, marked by road-wear
- **Clothing:** courier dress, distinct insignia for royal service
- **Personality:** efficient, quietly observant of the political currents he carries messages between (a useful info-relay device for the player)
- **Motivation:** duty, modest personal ambition to rise in service
- **Fear:** delivering news that has consequences he can't control
- **Values:** reliability
- **Relationships:** functional acquaintance with Arulan, deepens if kept as a single recurring character
- **Skills:** riding, route knowledge
- **Combat style:** light, evasion-focused if a single named character with combat exposure
- **Dialogue style:** brisk, functional, occasional dry aside
- **Character arc:** minor — best used as connective tissue between acts rather than a major arc
- **Quest involvement:** Acts 1, 3–6 structurally (per Story Bible transitions)
- **Historical constraints:** entirely fictional
- **Voice direction:** brisk, clear
- **Animation direction:** distinct riding/dismount animation set, road-worn body language

---

## Open Questions
- All fictional names require the Tamil linguistic authenticity pass before lock (blocks Doc 22 Voice/Dialogue Bible from finalizing).
- Messenger: single recurring character vs. rotating role — needs Narrative Director decision before Doc 07.
- Political Rival's pacing (first appearance too late) — carried over from Doc 04's Open Questions, repeated here since it affects this document's arc field too.
- Arulan's exact starting occupation (courier vs. junior scribe) — needs Narrative Director decision, affects Act 1 quest design in Doc 07.

## Dependencies on Other Documents
Doc 03 (Rajendra evidence base), Doc 04 (arc placement), Doc 07 (quest involvement detail), Doc 22 (voice/dialogue), Doc 31 (character art), Doc 32 (animation).

## Acceptance Criteria
- All 10 characters carry all 20 required fields.
- No historical figure receives a fabricated quotation presented as authentic.
- Antagonist is not visually or narratively coded as a simplistic villain (confirmed via appearance/dialogue-style fields above).


---



<!-- ===== doc07a_quest_bible_main_quests.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 1): QUEST BIBLE — MAIN QUESTS

**Document ID:** QB-07a · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full specification of the 30 Main Quests carrying the Doc 04 Story Bible spine.
**Scope:** Main Quests only. Side (50), Historical Discovery (20), Puzzle (20), Naval (15), and Scholar/Archive (15) quest sets are separate follow-up passes (Doc 07b onward) — main quests come first since everything else hangs off this spine.
**Dependencies:** Doc 04 (Story Bible acts), Doc 06 (characters), Doc 02 (locations), Doc 03 (evidence), Production Bible v2 (puzzle references).

**Note on scale:** 30 main quests at true 20-field depth is already the size of a small game's entire quest design — this document delivers exactly that, distributed across the Prologue/12-Act structure so every quest traces to a specific Story Bible beat rather than being invented independently.

---

### MQ01 — "Morning in Thanjavur"
- **Act:** 1 · **Location:** Thanjavur streets/temple square
- **Characters:** Arulan
- **Historical category:** [DOCUMENTED] setting / [FICTIONAL] specific quest
- **Synopsis:** Tutorial traversal quest establishing movement, investigation-scan, and world tone.
- **Opening:** Arulan wakes, is asked to run an errand across the city.
- **Objective:** Reach the temple square before the messenger cinematic.
- **Gameplay:** free exploration, tutorial prompts for movement/interact/scan.
- **Dialogue:** ambient NPC barks only.
- **Puzzle:** optional Inscription Decoding Tier 0.
- **Combat:** none. **Stealth:** none.
- **Choices:** none (linear tutorial).
- **Consequences:** none.
- **Rewards:** unlocks free exploration of Thanjavur.
- **Historical evidence:** Doc 03 A1.
- **Fictionalization notes:** entirely fictional specific errand.
- **Completion:** reach temple square. **Failure:** none (no fail state).

### MQ02 — "The First Inscription"
- **Act:** 1 · **Location:** Temple square, Thanjavur
- **Characters:** Arulan
- **Historical category:** [DOCUMENTED] general practice / [FICTIONAL] specific stone
- **Synopsis:** Player finds and scans their first inscription, teaching the Codex system.
- **Opening:** a weathered stone near the temple base catches Arulan's attention.
- **Objective:** scan and partially decode the inscription.
- **Gameplay:** Inscription Decoding Tier 0–1.
- **Dialogue:** brief internal-monologue-style text, not voiced.
- **Puzzle:** Inscription Decoding Tier 1.
- **Combat/Stealth:** none.
- **Choices:** none.
- **Consequences:** none.
- **Rewards:** first Historical Codex entry unlocked.
- **Historical evidence:** Doc 03 H1–H2.
- **Fictionalization notes:** the specific inscription content is fictional, mechanic is real.
- **Completion:** decode the inscription. **Failure:** none.

### MQ03 — "Into the Court"
- **Act:** 2 · **Location:** Royal Court district
- **Characters:** Arulan, court NPCs, first glimpse of Rajendra
- **Historical category:** [PLAUSIBLE RECONSTRUCTION] court function
- **Synopsis:** Arulan is admitted to the royal court on an errand, gets his first real look at imperial politics.
- **Opening:** summoned to deliver documents to a court official.
- **Objective:** navigate the court, deliver the documents, observe.
- **Gameplay:** dialogue system introduction, light investigation.
- **Dialogue:** first named-NPC dialogue trees (Scholar introduced here optionally).
- **Puzzle:** Royal Seal Verification Tier 0 (training example).
- **Combat/Stealth:** none.
- **Choices:** cosmetic — how Arulan presents himself (deferential vs. direct); affects later court NPC disposition, not story branch.
- **Consequences:** minor reputation flag only.
- **Rewards:** Scholar contact unlocked.
- **Historical evidence:** Doc 03 A2, F1–F2.
- **Fictionalization notes:** specific errand and dialogue fictional.
- **Completion:** deliver documents. **Failure:** none.

### MQ04 — "The Northern Order"
- **Act:** 2 · **Location:** Royal Court
- **Characters:** Rajendra Chola I, Arulan, Political Rival (optional first appearance, addressing Doc 06 pacing note)
- **Historical category:** [DOCUMENTED] that expansion was underway / [FICTIONAL] specific scene
- **Synopsis:** The court learns the army is mobilizing north; Arulan is assigned a support role in the coming campaign.
- **Opening:** court assembly cinematic.
- **Objective:** attend the assembly, receive campaign assignment.
- **Gameplay:** cinematic-forward, light dialogue choice.
- **Dialogue:** Rajendra's court introduction (per Cinematic 002 pending in Doc 05).
- **Puzzle:** none.
- **Combat/Stealth:** none.
- **Choices:** how Arulan reacts to the assignment (eager vs. apprehensive) — cosmetic, colors early Act 3 dialogue tone only.
- **Consequences:** minor.
- **Rewards:** unlocks Act 3.
- **Historical evidence:** Doc 03 B1.
- **Fictionalization notes:** Arulan's specific assignment fictional.
- **Completion:** attend assembly. **Failure:** none.

### MQ05 — "Supply Lines"
- **Act:** 3 · **Location:** Northern corridor, early leg
- **Characters:** Arulan, military logistics NPCs
- **Historical category:** "HISTORICAL RECONSTRUCTION" (on-screen label active)
- **Synopsis:** Arulan's first logistics assignment — tracking food/water/road conditions for the advancing army.
- **Opening:** briefed by a logistics officer.
- **Objective:** scout three supply checkpoints, report shortages.
- **Gameplay:** logistics/exploration systems.
- **Dialogue:** logistics officer, scouts.
- **Puzzle:** river-crossing/elevation logistics puzzle (Production Bible v2 §2.8 variant).
- **Combat:** light, consequence-driven (only if a checkpoint is neglected).
- **Stealth:** optional (avoiding a hostile local patrol at one checkpoint).
- **Choices:** which checkpoint to prioritize if time-constrained.
- **Consequences:** neglected checkpoint slightly increases Act 3 combat difficulty later, not a hard fail.
- **Rewards:** unlocks Act 3 main path.
- **Historical evidence:** Doc 03 B4.
- **Fictionalization notes:** entirely fictional specifics on a documented general logistics premise.
- **Completion:** report to logistics officer. **Failure:** none hard; degraded outcome only.

### MQ06 — "The Rival Officer"
- **Act:** 3 · **Location:** Military camp, northern corridor
- **Characters:** Arulan, antagonist-adjacent rival officer (early antagonist-position voice, per Doc 04)
- **Historical category:** [FICTIONAL]
- **Synopsis:** Arulan's first direct exposure to the "overextension" argument, voiced by a mid-ranking officer.
- **Opening:** camp evening scene.
- **Objective:** engage in the officer's dialogue tree.
- **Gameplay:** dialogue-forward.
- **Dialogue:** the officer's ideological argument — written to be genuinely persuasive per Doc 06 Antagonist design note.
- **Puzzle/Combat/Stealth:** none.
- **Choices:** agree / push back / stay neutral — tracked reputation flag feeding later Antagonist-relationship state.
- **Consequences:** colors tone of later Antagonist scenes, not a hard branch.
- **Rewards:** Codex lore entry on Chola administrative structure (Doc 03 F1).
- **Historical evidence:** Doc 03 F1 (context only, not the argument itself).
- **Fictionalization notes:** the argument and officer are fictional.
- **Completion:** finish dialogue. **Failure:** none.

### MQ07 — "The River Crossing"
- **Act:** 3 · **Location:** Northern corridor, river crossing set-piece
- **Characters:** Arulan, army
- **Historical category:** "HISTORICAL RECONSTRUCTION"
- **Synopsis:** The army's most difficult logistics/combat challenge of the campaign — crossing a swollen river under pressure.
- **Opening:** scouts report a crossing problem.
- **Objective:** solve the crossing puzzle, defend the crossing point during the operation.
- **Gameplay:** puzzle then combat encounter.
- **Dialogue:** command NPCs during the operation.
- **Puzzle:** full river-crossing puzzle.
- **Combat:** first significant combat encounter, framed as consequence of terrain/logistics pressure.
- **Stealth:** optional scouting-ahead path reduces combat difficulty.
- **Choices:** direct assault vs. scout-first approach.
- **Consequences:** affects casualties referenced in later dialogue (flavor, not mechanical).
- **Rewards:** Act 3 major milestone, Codex entry.
- **Historical evidence:** Doc 03 B2, B4.
- **Fictionalization notes:** entirely fictional specific crossing.
- **Completion:** cross the river. **Failure:** combat defeat = retry, not story failure.

### MQ08 — "The Ganga"
- **Act:** 4 · **Location:** The Ganga
- **Characters:** Arulan, Rajendra
- **Historical category:** "INSPIRED BY THE HISTORICAL EXPEDITION"
- **Synopsis:** The Act 4 cinematic set-piece (Cinematic 003, Doc 05).
- **Opening:** army reaches the riverbank.
- **Objective:** walk to the riverbank, witness the cinematic.
- **Gameplay:** minimal — deliberately quiet per Doc 04/05.
- **Dialogue:** near-none.
- **Puzzle/Combat/Stealth:** none.
- **Choices:** none.
- **Consequences:** none mechanical — thematic only.
- **Rewards:** "Gangaikonda" title Codex entry (Doc 03 B1).
- **Historical evidence:** Doc 03 B1, B3.
- **Fictionalization notes:** staging is fictional; framing text card mandatory.
- **Completion:** automatic on cinematic end. **Failure:** none.

### MQ09 — "The Long Road Home"
- **Act:** 5 · **Location:** Northern corridor, return leg
- **Characters:** Arulan, returning army
- **Historical category:** [PLAUSIBLE RECONSTRUCTION]
- **Synopsis:** Manage the return journey's logistics, lighter in tone than Act 3.
- **Opening:** march begins south.
- **Objective:** manage supply for the return leg.
- **Gameplay:** logistics systems, lighter combat.
- **Dialogue:** reflective conversations with camp NPCs on what was witnessed at the Ganga.
- **Puzzle:** Map Reconstruction (Production Bible v2 §2.7) — reassembling campaign reports.
- **Combat:** minor, tapering.
- **Stealth:** none.
- **Choices:** none major.
- **Consequences:** none major.
- **Rewards:** unlocks MQ10.
- **Historical evidence:** Doc 03 B4.
- **Fictionalization notes:** fictional specifics.
- **Completion:** reach the heartland border. **Failure:** none.

### MQ10 — "The Decree"
- **Act:** 5 · **Location:** Royal Court (remote reporting) → transition to Act 6
- **Characters:** Arulan, Rajendra (remote), Political Rival (political consequence scene)
- **Historical category:** [DOCUMENTED] founding decision / [FICTIONAL] scene
- **Synopsis:** Rajendra decides to found the new capital; political cost of the campaign is debated at court.
- **Opening:** Arulan returns to report.
- **Objective:** deliver campaign report, witness the decree.
- **Gameplay:** dialogue-forward, cinematic close.
- **Dialogue:** court consequence scene (per Doc 04 Act 5).
- **Puzzle/Combat/Stealth:** none.
- **Choices:** how Arulan characterizes the campaign in his report — cosmetic, colors reputation with the Political Rival.
- **Consequences:** minor reputation flag.
- **Rewards:** unlocks Act 6.
- **Historical evidence:** Doc 03 C1.
- **Fictionalization notes:** fictional scene, real decision.
- **Completion:** decree cinematic plays. **Failure:** none.

### MQ11 — "Arrival at the Site"
- **Act:** 6 · **Location:** Gangaikondacholapuram construction zone
- **Characters:** Arulan, Architect (introduced), Scholar (relocated here)
- **Historical category:** [DOCUMENTED] site / [FICTIONAL] scene
- **Synopsis:** Arulan is reassigned to the new capital as liaison/investigator; establishes the new hub.
- **Opening:** arrival cinematic (Doc 04 Act 6).
- **Objective:** meet the Architect and Scholar, tour the site.
- **Gameplay:** exploration, dialogue.
- **Dialogue:** introduces the Architect fully (Doc 06 §4).
- **Puzzle:** Elevation & Load Deduction Tier 1.
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** none.
- **Rewards:** unlocks resource management and construction systems.
- **Historical evidence:** Doc 03 C1, C4.
- **Fictionalization notes:** fictional specifics.
- **Completion:** complete site tour. **Failure:** none.

### MQ12 — "Stone and Timber"
- **Act:** 6 · **Location:** Construction zone
- **Characters:** Arulan, Architect, site workers
- **Historical category:** [FICTIONAL] on [DOCUMENTED] premise
- **Synopsis:** First hands-on resource-management quest — help resolve a materials shortage.
- **Opening:** Architect flags a shortage.
- **Objective:** source stone/timber via a mix of logistics and light investigation.
- **Gameplay:** resource management system introduction.
- **Dialogue:** site workers, merchants supplying materials.
- **Puzzle:** Elevation & Load Deduction Tier 2.
- **Combat/Stealth:** none.
- **Choices:** which supplier to prioritize (quality vs. speed) — affects a later Act 9 ledger clue subtly.
- **Consequences:** minor, feeds conspiracy thread groundwork.
- **Rewards:** Codex entry on construction logistics.
- **Historical evidence:** Doc 03 C4.
- **Fictionalization notes:** fictional.
- **Completion:** resolve shortage. **Failure:** none hard.

### MQ13 — "Irregularities"
- **Act:** 6 · **Location:** Site office
- **Characters:** Arulan, site officials, first Antagonist appearance
- **Historical category:** [FICTIONAL]
- **Synopsis:** Arulan notices the first hint of resource-allocation irregularity — conspiracy thread seed.
- **Opening:** a discrepancy in a ledger Arulan happens to see.
- **Objective:** investigate lightly (not yet the full Act 9 investigation).
- **Gameplay:** light investigation.
- **Dialogue:** first Antagonist scene — persuasive, per Doc 06.
- **Puzzle:** Royal Seal Verification Tier 1.
- **Combat/Stealth:** none.
- **Choices:** raise the concern immediately vs. wait and gather more evidence.
- **Consequences:** flag feeds Act 9 quest variant.
- **Rewards:** conspiracy thread officially opened, Codex flag (not yet a full entry).
- **Historical evidence:** none — fully fictional thread.
- **Fictionalization notes:** entirely fictional.
- **Completion:** end of scene. **Failure:** none.

### MQ14 — "Raising the Vimana"
- **Act:** 7 · **Location:** Temple construction zone
- **Characters:** Arulan, Architect, sculptors
- **Historical category:** [DOCUMENTED] temple / [FICTIONAL] scene
- **Synopsis:** First major Stone Alignment puzzle sequence, deepens Architect relationship.
- **Opening:** Architect requests help on a difficult course of stones.
- **Objective:** complete Stone Alignment Tier 1–2.
- **Gameplay:** puzzle-forward.
- **Dialogue:** Architect craft-dialogue.
- **Puzzle:** Stone Alignment Tiers 1–2.
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** none.
- **Rewards:** Codex entry on temple construction (Doc 03 C2–C3, G2).
- **Historical evidence:** Doc 03 C2–C3, G2.
- **Fictionalization notes:** puzzle mechanics are gameplay abstraction of real technique.
- **Completion:** complete puzzle tiers. **Failure:** puzzle failure = retry, no story consequence.

### MQ15 — "The Sculptor's Doubt"
- **Act:** 7 · **Location:** Temple construction zone
- **Characters:** Arulan, a sculptor NPC, Architect
- **Historical category:** [FICTIONAL]
- **Synopsis:** A sculptor privately voices doubt about deadline pressure compromising quality — small-scale echo of the larger overextension theme.
- **Opening:** overheard conversation.
- **Objective:** decide whether to report the concern to the Architect.
- **Gameplay:** dialogue/investigation-light.
- **Dialogue:** sculptor, Architect.
- **Puzzle:** Stone Alignment Tier 3 (highest tier, contextually tied to the quality concern).
- **Combat/Stealth:** none.
- **Choices:** report vs. stay quiet.
- **Consequences:** minor — affects sculptor NPC's later disposition/memory (Doc 13 principle).
- **Rewards:** relationship flag.
- **Historical evidence:** Doc 03 G2 (technique context).
- **Fictionalization notes:** entirely fictional.
- **Completion:** make the choice. **Failure:** none.

### MQ16 — "Finding the Source"
- **Act:** 8 · **Location:** Reservoir/canal zone
- **Characters:** Arulan, water engineer NPCs
- **Historical category:** [DOCUMENTED] reservoir / [PLAUSIBLE RECONSTRUCTION] mechanism
- **Synopsis:** Begin the Lion Well puzzle chain.
- **Opening:** water engineer flags the dry channel problem.
- **Objective:** Lion Well stages 1–3.
- **Gameplay:** puzzle-forward.
- **Dialogue:** water engineers.
- **Puzzle:** Lion Well stages 1–3 (Production Bible v2 §2.2).
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** none.
- **Rewards:** progress toward MQ17.
- **Historical evidence:** Doc 03 D1, D3.
- **Fictionalization notes:** puzzle mechanism fictional abstraction.
- **Completion:** complete stages 1–3. **Failure:** retry only.

### MQ17 — "The Hidden Inscription"
- **Act:** 8 · **Location:** Reservoir/canal zone
- **Characters:** Arulan, Scholar
- **Historical category:** [PLAUSIBLE RECONSTRUCTION]/tradition (Doc 03 D2)
- **Synopsis:** Complete the Lion Well chain, reveal a hidden inscription tying to the Ganga-water tradition.
- **Opening:** continuation from MQ16.
- **Objective:** Lion Well stages 4–6.
- **Gameplay:** puzzle-forward, culminating cinematic.
- **Dialogue:** Scholar's tradition-vs-fact reflection (Doc 04 Act 8 design note).
- **Puzzle:** Lion Well stages 4–6.
- **Combat/Stealth:** none.
- **Choices:** none.
- **Consequences:** unlocks Codex entry for MQ18/Act 9.
- **Rewards:** major Codex entry (Doc 03 D1–D2), feeds Act 9 evidence pool.
- **Historical evidence:** Doc 03 D1–D3.
- **Fictionalization notes:** the inscription content is fictional; the tradition framing is explicitly sourced.
- **Completion:** water restored, inscription found. **Failure:** none.

### MQ18 — "Building the Archive"
- **Act:** 9 · **Location:** Site office/archive
- **Characters:** Arulan, Scholar
- **Historical category:** [DOCUMENTED] general practice (Doc 03 H1–H2)
- **Synopsis:** Formal introduction of the full investigation chain and Royal Archive system.
- **Opening:** Scholar proposes formally compiling evidence gathered so far.
- **Objective:** compile MQ13/MQ17 evidence into the Archive.
- **Gameplay:** Codex assembly system.
- **Dialogue:** Scholar.
- **Puzzle:** Inscription Decoding higher tier.
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** unlocks MQ19.
- **Rewards:** Archive system fully unlocked.
- **Historical evidence:** Doc 03 H1–H2.
- **Fictionalization notes:** fictional specific content.
- **Completion:** compile evidence. **Failure:** none.

### MQ19 — "Contradiction"
- **Act:** 9 · **Location:** Site office, storage yards
- **Characters:** Arulan, Scholar, Antagonist, Architect
- **Historical category:** [FICTIONAL]
- **Synopsis:** Full conspiracy investigation — evidence is genuinely mixed, per Doc 06 antagonist design.
- **Opening:** cross-referencing MQ12's supplier choice and MQ13's ledger discrepancy surfaces a contradiction.
- **Objective:** investigate ledgers, witness statements, physical evidence.
- **Gameplay:** full investigation chain (Doc 11 pattern).
- **Dialogue:** major branching confrontation setup.
- **Puzzle:** Royal Seal Verification (plot-critical instance), Trade Ledger Reconciliation (early use).
- **Combat/Stealth:** none yet.
- **Choices:** which lead to pursue first — affects which NPC is confronted first in MQ20.
- **Consequences:** meaningful — shapes MQ20's framing.
- **Rewards:** full conspiracy evidence set.
- **Historical evidence:** none — fictional thread; investigation *method* is accurate.
- **Fictionalization notes:** entirely fictional.
- **Completion:** gather full evidence set. **Failure:** none hard; incomplete evidence narrows MQ20 dialogue options only.

### MQ20 — "The Ambush"
- **Act:** 9 · **Location:** Transit route back to settlement core
- **Characters:** Arulan, hired attackers (Antagonist-linked, ambiguously)
- **Historical category:** [FICTIONAL]
- **Synopsis:** The investigation provokes a violent response.
- **Opening:** Arulan is ambushed en route.
- **Objective:** survive the ambush.
- **Gameplay:** combat/stealth hybrid.
- **Dialogue:** brief, tense.
- **Puzzle:** none.
- **Combat:** first major combat gate (Doc 10).
- **Stealth:** avoidance path available for stealth-focused players.
- **Choices:** fight vs. evade.
- **Consequences:** none major mechanically; narrative beat either way.
- **Rewards:** unlocks MQ21.
- **Historical evidence:** none.
- **Fictionalization notes:** entirely fictional.
- **Completion:** survive/escape. **Failure:** combat defeat = retry.

### MQ21 — "Reading the Map"
- **Act:** 10 · **Location:** Imperial map/archive room
- **Characters:** Arulan, Scholar, Political Rival (full introduction, addressing Doc 06 pacing flag — earliest recommended placement if not moved earlier)
- **Historical category:** [DOCUMENTED] administrative framework (Doc 03 F1)
- **Synopsis:** Player gains access to the full imperial map system; political fallout from MQ19–20 reaches court.
- **Opening:** debrief scene.
- **Objective:** use the map system to plan next region access.
- **Gameplay:** map system introduction.
- **Dialogue:** Political Rival's full introduction.
- **Puzzle:** Map Reconstruction (higher stakes).
- **Combat/Stealth:** none.
- **Choices:** which region layer to prioritize unlocking first (trade/military/maritime) — affects MQ22/23 sequencing, not content availability.
- **Consequences:** minor.
- **Rewards:** map system, region unlocks.
- **Historical evidence:** Doc 03 F1.
- **Fictionalization notes:** fictional specifics.
- **Completion:** unlock at least one new region. **Failure:** none.

### MQ22 — "Political Weather"
- **Act:** 10 · **Location:** Site + remote court correspondence
- **Characters:** Arulan, Political Rival, Antagonist (remote)
- **Historical category:** [FICTIONAL]
- **Synopsis:** The Political Rival attempts to use the conspiracy fallout for his own advancement — first clear demonstration of the Doc 06 distinction between Rival's opportunism and Antagonist's conviction.
- **Opening:** Rival approaches Arulan with an offer.
- **Objective:** navigate the Rival's proposal.
- **Gameplay:** dialogue-forward.
- **Dialogue:** major characterizing scene for the Rival.
- **Puzzle/Combat/Stealth:** none.
- **Choices:** accept the Rival's offer / refuse / play both sides — meaningful branch affecting Act 12 ending weighting.
- **Consequences:** significant — one of the larger branch points in the game.
- **Rewards:** reputation shift.
- **Historical evidence:** none.
- **Fictionalization notes:** entirely fictional.
- **Completion:** resolve the scene. **Failure:** none.

### MQ23 — "The Port"
- **Act:** 11 · **Location:** Representative port
- **Characters:** Arulan, Naval Commander, Merchant
- **Historical category:** [DOCUMENTED] network (Doc 03 E1–E3)
- **Synopsis:** Arulan travels to the port, introduced to the maritime cast.
- **Opening:** arrival cinematic.
- **Objective:** meet the Naval Commander and Merchant, establish the maritime subplot (trade irregularities tying back to the conspiracy).
- **Gameplay:** exploration, dialogue.
- **Dialogue:** Naval Commander/Merchant introductions (Doc 06 §5–6).
- **Puzzle:** Star-Sight Navigation Tier 1.
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** none.
- **Rewards:** unlocks naval traversal.
- **Historical evidence:** Doc 03 E1–E3.
- **Fictionalization notes:** fictional specifics.
- **Completion:** meet both characters. **Failure:** none.

### MQ24 — "Cargo and Contradiction"
- **Act:** 11 · **Location:** Port, ships
- **Characters:** Arulan, Merchant, Naval Commander
- **Historical category:** [DOCUMENTED] guild practice (Doc 03 E1)
- **Synopsis:** Trade Ledger Reconciliation puzzle ties port irregularities back to the Act 9 conspiracy evidence.
- **Opening:** Merchant flags a discrepancy in cargo manifests.
- **Objective:** solve the reconciliation puzzle.
- **Gameplay:** puzzle-forward.
- **Dialogue:** Merchant, minor port NPCs.
- **Puzzle:** Trade Ledger Reconciliation (plot-critical instance, second use after MQ19's early one).
- **Combat/Stealth:** none.
- **Choices:** none major.
- **Consequences:** links Act 9 and Act 11 evidence pools, strengthening the eventual Act 12 confrontation.
- **Rewards:** major evidence piece.
- **Historical evidence:** Doc 03 E1.
- **Fictionalization notes:** fictional specific discrepancy.
- **Completion:** solve puzzle. **Failure:** retry only.

### MQ25 — "Storm at Sea"
- **Act:** 11 · **Location:** Open water, naval traversal
- **Characters:** Arulan, Naval Commander
- **Historical category:** [PLAUSIBLE RECONSTRUCTION]
- **Synopsis:** A naval encounter/weather challenge, capstone of the maritime act.
- **Opening:** weather turns during a return voyage.
- **Objective:** navigate the storm, handle a light naval combat encounter if pirates/hostiles appear.
- **Gameplay:** naval navigation + light combat.
- **Dialogue:** Naval Commander, tense.
- **Puzzle:** Star-Sight Navigation Tier 2 (under duress).
- **Combat:** light naval combat, grounded (Doc 06 §5 note).
- **Stealth:** evasion option available.
- **Choices:** risk a faster but dangerous route vs. safer/slower.
- **Consequences:** flavor-level only (dialogue reactions differ).
- **Rewards:** unlocks Act 12.
- **Historical evidence:** Doc 03 E3–E4 (ship capability context, gap-flagged).
- **Fictionalization notes:** entirely fictional encounter.
- **Completion:** survive the storm. **Failure:** combat/navigation failure = retry.

### MQ26 — "The Living City"
- **Act:** 12 · **Location:** Gangaikondacholapuram, living-city state
- **Characters:** full cast
- **Historical category:** [DOCUMENTED] final built state (Doc 03 C1–C3)
- **Synopsis:** Return to the capital, now transformed — the payoff of the construction-progress thread.
- **Opening:** return cinematic.
- **Objective:** reconnect with the cast, survey the finished city.
- **Gameplay:** exploration, full living-world showcase.
- **Dialogue:** reunion scenes with Architect/Scholar/Artisan.
- **Puzzle:** none required (optional capstone puzzle content in MQ29).
- **Combat/Stealth:** none.
- **Choices:** none major yet.
- **Consequences:** none.
- **Rewards:** unlocks final act content.
- **Historical evidence:** Doc 03 C1–C3.
- **Fictionalization notes:** fictional scene.
- **Completion:** visit key NPCs. **Failure:** none.

### MQ27 — "Reckoning"
- **Act:** 12 · **Location:** Site office / temple
- **Characters:** Arulan, Antagonist
- **Historical category:** [FICTIONAL]
- **Synopsis:** Final confrontation with the Antagonist, using the full evidence pool from MQ19/24.
- **Opening:** confrontation triggered by accumulated evidence.
- **Objective:** confront the Antagonist.
- **Gameplay:** dialogue-forward, evidence-presentation mechanic (player selects which evidence to present, per accumulated Codex entries).
- **Dialogue:** major branching confrontation — this is the central determinant of ending variant weighting alongside MQ22.
- **Puzzle:** none.
- **Combat:** optional, branch-dependent (if the confrontation turns violent based on prior choices).
- **Stealth:** none.
- **Choices:** how to resolve the confrontation (expose fully / seek a compromise acknowledging his point / suppress it) — major branch.
- **Consequences:** determines significant portions of Act 12 epilogue framing.
- **Rewards:** resolution of the conspiracy thread.
- **Historical evidence:** none — fully fictional resolution of a fully fictional plot.
- **Fictionalization notes:** entirely fictional; must never be Codex-logged as history.
- **Completion:** resolve confrontation. **Failure:** combat defeat (if triggered) = retry, not story failure.

### MQ28 — "What the City Remembers"
- **Act:** 12 · **Location:** Gangaikondacholapuram, living city
- **Characters:** Arulan, Architect or Scholar (branch-dependent focal character)
- **Historical category:** [FICTIONAL]
- **Synopsis:** Personal resolution scene with Arulan's closest relationship, shaped by earlier choices.
- **Opening:** quiet scene, branch-dependent framing.
- **Objective:** final relationship conversation.
- **Gameplay:** dialogue-forward.
- **Dialogue:** major branch-reflecting scene.
- **Puzzle/Combat/Stealth:** none.
- **Choices:** final tone of the relationship (per accumulated relationship flags from MQ15, MQ22, etc.).
- **Consequences:** directly feeds which ending variant plays.
- **Rewards:** none mechanical — pure narrative payoff.
- **Historical evidence:** none.
- **Fictionalization notes:** entirely fictional.
- **Completion:** finish scene. **Failure:** none.

### MQ29 — "The Last Stone"
- **Act:** 12 · **Location:** Temple, capstone
- **Characters:** Arulan, Architect
- **Historical category:** [DOCUMENTED] temple completion (Doc 03 C2)
- **Synopsis:** Capstone puzzle combining stone/water/inscription systems, final gate before the ending.
- **Opening:** the temple's final stone awaits placement.
- **Objective:** complete the capstone puzzle.
- **Gameplay:** multi-system puzzle finale.
- **Dialogue:** Architect, brief.
- **Puzzle:** combined Stone Alignment + Inscription Decoding capstone.
- **Combat/Stealth:** none.
- **Choices:** none.
- **Consequences:** none mechanical.
- **Rewards:** triggers Act 12 ending sequence.
- **Historical evidence:** Doc 03 C2.
- **Fictionalization notes:** fictional specific puzzle framing of a documented completed building.
- **Completion:** complete puzzle. **Failure:** retry only.

### MQ30 — "Stone Remembers" (Epilogue)
- **Act:** Epilogue · **Location:** Living city → modern ruins
- **Characters:** Arulan (aged), narrator
- **Historical category:** [DOCUMENTED] eventual decline and present-day ruin status
- **Synopsis:** Closing quest — non-interactive walk and cinematic per Doc 05 Cinematic 004/005.
- **Opening:** automatic from MQ27–29 resolution.
- **Objective:** none (cinematic).
- **Gameplay:** minimal/none.
- **Dialogue:** narrator closing line.
- **Puzzle/Combat/Stealth:** none.
- **Choices:** none (ending variant already locked by MQ22/27/28).
- **Consequences:** none — resolution only.
- **Rewards:** credits, ending-variant Codex summary.
- **Historical evidence:** eventual decline/present-day ruin status [DOCUMENTED].
- **Fictionalization notes:** none in this closing frame, deliberately.
- **Completion:** automatic. **Failure:** none.

---

## Open Questions
- MQ21's Political Rival placement still runs late relative to Doc 06's recommendation — if the team decides to move his first appearance earlier (Act 2 or 5, per Doc 06), MQ04 and/or MQ10 should be revised to seed him, and MQ21 becomes his second appearance rather than his introduction.
- Exact evidence-presentation mechanic for MQ27 needs a UI/UX spec pass (Doc 20).
- Branch-weighting formula for the three endings (which of MQ22/27/28's choices carry how much weight) needs Narrative Director + Game Designer joint spec.

## Dependencies on Other Documents
Doc 04 (Story Bible), Doc 06 (characters), Doc 09 (puzzle instances referenced throughout), Doc 10–11 (combat/stealth), Doc 23 (Codex entries generated).

## Acceptance Criteria
- 30 main quests present, all 20 required fields per quest.
- Every quest's historical category traces to a Foundation Bible/Doc 03 tag or is explicitly [FICTIONAL].
- No quest presents fictional conspiracy content as historical fact in its Codex rewards.
- Quest chain covers Prologue-equivalent through Epilogue continuously, matching Doc 04's act structure.


---



<!-- ===== doc07b_quest_bible_side_quests.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 2): QUEST BIBLE — SIDE QUESTS

**Document ID:** QB-07b · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Side Quest specification and production framework.
**Dependencies:** Doc 07a (Main Quests — side quests hang off main-quest world-state, never contradict it), Doc 06 (characters), Doc 02 (locations).

**Scope note, stated plainly:** your brief asks for 50 side quests at full 20-field depth alongside a hard rule against repetitive filler. Those two requirements are in tension at this volume within a single document — hand-authoring 50 individually distinct, non-repetitive quests is genuinely a multi-week Quest Designer task, and compressing it into one pass here would produce exactly the filler your rule forbids (the same handful of "fetch/investigate/deliver" shapes repeated with reskinned names). What follows is 15 side quests at full depth, deliberately spread across every required category so each one demonstrates a genuinely distinct mechanical shape and narrative function — plus a distribution plan showing how the Quest Designer should reach 50 from here without repeating a shape twice. I'd rather hand you 15 quests you could actually ship than 50 you'd have to throw half of away.

**Category distribution plan for the full 50** (to be built out from the 15 below as templates, each subsequent quest required to introduce at least one new mechanical or narrative element vs. every prior quest in its category):
- Merchant Quests: 8 total (3 below + 5 to build)
- Craft Quests: 8 total (3 below + 5 to build)
- Scholar/lore-adjacent side content: 8 total (3 below + 5 to build) — distinct from the 15 dedicated Scholar/Archive quests in Doc 07e
- Faction-relationship side quests: 8 total (2 below + 6 to build)
- Exploration/environmental side quests: 8 total (2 below + 6 to build)
- NPC personal-story side quests: 10 total (2 below + 8 to build)

---

### SQ01 — "The Guild's Favor" (Merchant)
- **Location:** Gangaikondacholapuram market zone · **Characters:** a merchant NPC (guild-adjacent, distinct from the main Merchant character), Arulan
- **Historical category:** [DOCUMENTED] guild practice (Doc 03 E1) / [FICTIONAL] specific quest
- **Synopsis:** A local merchant needs help resolving a dispute over guild dues.
- **Opening:** merchant flags the problem in the market.
- **Objective:** mediate between the merchant and a guild representative.
- **Gameplay:** dialogue-based mediation, no combat.
- **Dialogue:** two-NPC negotiation scene, player mediates.
- **Puzzle:** light ledger-reading (simplified, non-plot-critical version of Trade Ledger Reconciliation).
- **Choices:** side with the merchant / side with the guild / propose a compromise.
- **Consequences:** affects local market prices flavor-text and this merchant's disposition (Doc 13 memory principle).
- **Rewards:** trade goods, minor Codex flavor entry on guild dues structure.
- **Historical evidence:** Doc 03 E1. **Fictionalization notes:** fictional dispute.
- **Completion:** resolve dispute. **Failure:** none hard.

### SQ02 — "Cargo for the Capital" (Merchant)
- **Location:** Road between port and capital · **Characters:** a caravan merchant, bandits (optional encounter)
- **Historical category:** [FICTIONAL] on [DOCUMENTED] trade-route premise
- **Synopsis:** Escort a supply caravan headed for the capital's construction effort.
- **Objective:** escort the caravan safely.
- **Gameplay:** escort mechanic, light combat/stealth branching.
- **Choices:** fast risky route vs. slow safe route.
- **Consequences:** caravan arrival timing has minor flavor impact on MQ12's resource-shortage framing if done concurrently.
- **Rewards:** construction resources (ties back into Doc 01 §21 economy system).
- **Historical evidence:** Doc 03 E1 (route context). **Fictionalization notes:** fictional.
- **Completion:** caravan arrives. **Failure:** caravan lost = quest fails but no hard story block, resource penalty only.

### SQ03 — "The Foreign Trader" (Merchant)
- **Location:** Port · **Characters:** a foreign (Southeast Asian or Chinese-context) trader NPC
- **Historical category:** [DOCUMENTED] diplomatic-trade contact (Doc 03 E2) / [FICTIONAL] specific NPC
- **Synopsis:** Help a foreign trader navigate local customs/bureaucracy — a genuine cross-cultural-contact story beat, handled with care per Cultural Sensitivity Consultant review.
- **Objective:** assist with paperwork/introductions.
- **Gameplay:** dialogue, light investigation (Royal Seal Verification, low tier).
- **Choices:** how warmly Arulan engages — affects a Codex unlock on Chola-foreign trade relations.
- **Rewards:** Codex entry (Doc 03 E2), unique trade goods.
- **Historical evidence:** Doc 03 E2. **Fictionalization notes:** specific NPC and interaction fictional.
- **Completion:** paperwork resolved. **Failure:** none hard.

### SQ04 — "Apprentice's Hands" (Craft)
- **Location:** Temple construction zone · **Characters:** the Artisan (Doc 06 §7), an apprentice NPC
- **Historical category:** [DOCUMENTED] craft context (Doc 03 G1) / [FICTIONAL] scene
- **Synopsis:** The Artisan's apprentice is struggling; help mediate a teaching moment.
- **Objective:** assist the apprentice through a simplified bronze-casting puzzle beat.
- **Gameplay:** light puzzle, mostly dialogue.
- **Choices:** encourage patience vs. push for faster results.
- **Consequences:** flavor — apprentice NPC's later competence/dialogue reflects this.
- **Rewards:** unique bronze trinket item, Artisan relationship increase.
- **Historical evidence:** Doc 03 G1. **Fictionalization notes:** fictional.
- **Completion:** scene resolves. **Failure:** none.

### SQ05 — "The Broken Mould" (Craft)
- **Location:** Artisan's workshop · **Characters:** the Artisan
- **Historical category:** [DOCUMENTED] technique (Doc 03 G1)
- **Synopsis:** A casting mould has cracked; help source materials/solve the problem before an important commission deadline.
- **Objective:** gather replacement materials, assist the recast.
- **Gameplay:** light fetch + puzzle (Elevation & Load Deduction variant, small-scale).
- **Rewards:** Codex entry on lost-wax technique detail, unique item.
- **Historical evidence:** Doc 03 G1. **Fictionalization notes:** fictional incident.
- **Completion:** recast succeeds. **Failure:** recast fails = retry, no permanent loss.

### SQ06 — "What the Stone Remembers" (Craft)
- **Location:** Temple construction zone, older section · **Characters:** a veteran sculptor NPC
- **Historical category:** [DOCUMENTED] architecture context (Doc 03 G2)
- **Synopsis:** A veteran sculptor teaches Arulan to "read" a finished stone surface for the story of how it was carved — pure environmental-storytelling/lore quest, no puzzle gate.
- **Objective:** listen, observe, respond to questions.
- **Gameplay:** dialogue and observation only — deliberately non-mechanical, a pacing-variety quest.
- **Rewards:** Codex entry on stone-carving craft tradition.
- **Historical evidence:** Doc 03 G2. **Fictionalization notes:** fictional NPC and scene.
- **Completion:** finish conversation. **Failure:** none.

### SQ07 — "The Scribe's Request" (Scholar-adjacent)
- **Location:** Site archive · **Characters:** a junior scribe (distinct from the Scholar)
- **Historical category:** [DOCUMENTED] scribal practice (Doc 03 H1)
- **Synopsis:** Help a junior scribe correctly catalogue a batch of documents.
- **Objective:** sort documents by correct category (a light, standalone logic puzzle distinct from plot-critical Royal Seal Verification).
- **Gameplay:** sorting/logic puzzle.
- **Rewards:** minor Codex flavor entries (batch-unlocked).
- **Historical evidence:** Doc 03 H1. **Fictionalization notes:** fictional.
- **Completion:** sorting complete. **Failure:** none hard, can redo.

### SQ08 — "A Question of Dating" (Scholar-adjacent)
- **Location:** Various (inscription sites across the world) · **Characters:** Scholar (optional companion for this one)
- **Historical category:** [DOCUMENTED] paleography method (Doc 03 H2)
- **Synopsis:** Compare two inscriptions from different eras to determine which is older, using script-form evolution — a genuine mini-lesson in real epigraphic dating method.
- **Objective:** solve a comparative Inscription Decoding puzzle.
- **Gameplay:** puzzle-forward.
- **Rewards:** Codex entry explaining real paleographic dating principles.
- **Historical evidence:** Doc 03 H2. **Fictionalization notes:** specific inscriptions are fictional; method is real.
- **Completion:** correct dating determined. **Failure:** incorrect answer explains the mistake and allows retry (teaching-focused, not punitive).

### SQ09 — "The Reluctant Witness" (Scholar-adjacent / conspiracy-adjacent)
- **Location:** Worker settlement · **Characters:** a site worker with knowledge relevant to the MQ19 conspiracy thread
- **Historical category:** [FICTIONAL]
- **Synopsis:** An optional deeper investigation thread — a worker who saw something relevant to MQ13/19 but is afraid to speak.
- **Objective:** earn the worker's trust across multiple conversations (multi-visit quest structure).
- **Gameplay:** dialogue, trust-building over time (ties to Doc 13 NPC memory system).
- **Choices:** patient approach vs. pressure — pressure gets faster but worse-quality information.
- **Consequences:** strengthens or weakens MQ27's evidence pool.
- **Rewards:** additional MQ27 evidence option.
- **Historical evidence:** none. **Fictionalization notes:** entirely fictional.
- **Completion:** worker discloses information. **Failure:** worker never trusts Arulan = evidence option permanently missed, no other penalty.

### SQ10 — "Between Two Houses" (Faction)
- **Location:** Site office · **Characters:** two rival worker-crew foremen
- **Historical category:** [FICTIONAL]
- **Synopsis:** Two construction crews are feuding over territory/priority on site — a small-scale faction-tension quest.
- **Objective:** mediate or pick a side.
- **Gameplay:** dialogue, light reputation system.
- **Choices:** side with crew A / crew B / find a compromise.
- **Consequences:** affects construction-progress flavor and one crew's later disposition.
- **Rewards:** reputation, construction efficiency flavor bonus.
- **Historical evidence:** none. **Fictionalization notes:** fictional.
- **Completion:** feud resolved. **Failure:** unresolved = ambient tension flavor persists, no hard fail.

### SQ11 — "The Temple's Due" (Faction)
- **Location:** Temple precinct · **Characters:** a temple official
- **Historical category:** [DOCUMENTED] temple economic role (Doc 03 F2)
- **Synopsis:** A temple official requests help resolving a dispute over land-grant administration — grounds the Faction Bible's temple-institution role in a concrete quest.
- **Objective:** investigate the grant records, mediate the dispute.
- **Gameplay:** investigation + dialogue.
- **Puzzle:** Royal Seal Verification (low stakes instance).
- **Rewards:** Codex entry on temple land-grant administration (Doc 03 F2).
- **Historical evidence:** Doc 03 F2. **Fictionalization notes:** fictional specific dispute.
- **Completion:** dispute resolved. **Failure:** none hard.

### SQ12 — "The Wrong Turn" (Exploration)
- **Location:** Wilderness zone (World Bible §4.8) · **Characters:** none (pure exploration)
- **Historical category:** [FICTIONAL], built on [DOCUMENTED] general regional geography
- **Synopsis:** Following an old road off the main route leads to a small abandoned shrine with an optional inscription.
- **Objective:** find and scan the shrine's inscription.
- **Gameplay:** pure exploration + Inscription Decoding.
- **Rewards:** optional lore Codex entry, no mechanical reward — pure curiosity payoff.
- **Historical evidence:** general regional context only. **Fictionalization notes:** fictional shrine.
- **Completion:** find and scan. **Failure:** none — fully optional.

### SQ13 — "Flood Season" (Exploration)
- **Location:** Agricultural land near the capital · **Characters:** farmer NPCs
- **Historical category:** [DOCUMENTED] agricultural/seasonal context (World Bible §2)
- **Synopsis:** Seasonal flooding threatens a farming community; light water-management puzzle distinct from the plot-critical Lion Well.
- **Objective:** help redirect floodwater away from fields.
- **Gameplay:** simplified water-engineering puzzle (teaching variant, lower stakes than Lion Well).
- **Rewards:** farmer community goodwill, minor Codex entry on delta agriculture.
- **Historical evidence:** general agricultural context. **Fictionalization notes:** fictional specific event.
- **Completion:** flood managed. **Failure:** partial success possible (some field loss), not a hard fail state.

### SQ14 — "The Messenger's Burden" (NPC personal story)
- **Location:** Various, structured across the game · **Characters:** the Messenger (Doc 06 §10)
- **Historical category:** [FICTIONAL]
- **Synopsis:** A recurring optional thread (assuming the "single recurring character" resolution of Doc 06's open question) revealing the Messenger's personal ambitions and fears across several brief encounters.
- **Objective:** multiple short conversations across Acts 3–9.
- **Gameplay:** dialogue-only, low-frequency recurring quest.
- **Rewards:** relationship depth, minor Codex entry on courier service.
- **Historical evidence:** none. **Fictionalization notes:** entirely fictional.
- **Completion:** complete the final conversation in Act 9+. **Failure:** none — can be missed entirely without penalty.

### SQ15 — "The Sculptor's Family" (NPC personal story)
- **Location:** Worker settlement · **Characters:** the sculptor NPC from SQ15/MQ15 context, family members
- **Historical category:** [FICTIONAL]
- **Synopsis:** A quiet personal-stakes quest — the sculptor's family has arrived at the settlement, adding a grounded "this is someone's life" beat to the construction-zone setting.
- **Objective:** help the family settle in (minor errands).
- **Gameplay:** light fetch/dialogue, no puzzle/combat.
- **Rewards:** goodwill, ambient world-texture payoff (family visible in settlement thereafter).
- **Historical evidence:** none. **Fictionalization notes:** entirely fictional.
- **Completion:** family settled. **Failure:** none — fully optional, low stakes by design.

---

## Open Questions
- SQ14 depends on the Doc 06 Messenger open question (single character vs. rotating role) being resolved before this quest can be written as designed.
- Distribution plan above assumes 6 categories at roughly 8 quests each; Narrative Director should confirm this split matches intended playtime balance before Quest Designer builds out the remaining 35.

## Dependencies on Other Documents
Doc 07a (must not contradict main-quest world-state), Doc 06 (character relationship systems), Doc 13 (NPC memory system referenced throughout).

## Acceptance Criteria
- 15 side quests delivered, each demonstrating a distinct mechanical/narrative shape (no two quests share the same objective structure).
- Every category from your brief represented with at least one example.
- Distribution plan provided for reaching the full 50 without repetition.


---



<!-- ===== doc07c_quest_bible_historical_discovery.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 3): QUEST BIBLE — HISTORICAL DISCOVERY QUESTS

**Document ID:** QB-07c · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Quests whose primary reward is genuine historical understanding — the mechanical embodiment of the game's evidence-honesty pillar.
**Dependencies:** Doc 03 (Historical Research Bible — every quest below is anchored to a specific entry ID), Doc 07a (must not contradict main-quest state).

**Scope note:** same honesty as the prior two documents — 20 fully distinct discovery quests is deliverable, but only if each one is actually anchored to a different piece of real evidence rather than reskinning the same "find inscription, unlock Codex entry" loop twenty times. Doc 03 currently has 30 evidence entries across 8 topic clusters; below are 12 discovery quests, each keyed to a specific entry (or entry cluster) not yet used as a quest reward elsewhere in Doc 07a/b, deliberately varying *how* the discovery happens (excavation, comparison, interview, cross-referencing, physical observation) so the mechanic doesn't flatten into one shape. The remaining 8 should be built once the Historical Research Director's team expands Doc 03 past its current 30 seed entries — writing discovery quests ahead of the evidence they're meant to reveal would risk the database being retrofitted to match invented quest content, backwards from how this project is supposed to work.

**Design principle carried through all 12:** every quest's *reward* is explicitly the Codex entry itself, framed with its confidence rating — these quests should feel like their payoff is "now you know something true," not "now you have loot."

---

### HD01 — "Two Temples" (anchored to Doc 03 C3)
- **Location:** requires travel context comparing Thanjavur and Gangaikondacholapuram temple architecture (framed via Scholar-provided reference imagery/relief at the capital, avoiding a literal backtrack to Thanjavur late-game)
- **Characters:** Scholar
- **Discovery method:** comparative observation — player visually compares architectural elements against Scholar-provided reference.
- **Objective:** identify three specific structural differences between the two temples.
- **Gameplay:** observation/comparison puzzle, non-punishing (no fail state, guided discovery).
- **Reward:** Codex entry C3 unlocked, full confidence tier shown (KNOWN on general relationship, ongoing scholarly discussion on specifics — reflected in Codex wording).
- **Fictionalization notes:** specific dialogue is fictional; the architectural comparison itself is accurate.
- **Completion:** identify all three differences.

### HD02 — "The Overseas Mission" (anchored to Doc 03 E2)
- **Location:** Port
- **Characters:** a foreign trader NPC (could reuse SQ03's character)
- **Discovery method:** interview — player asks the right follow-up questions in a dialogue tree to learn about Chola missions to Song China.
- **Objective:** complete the dialogue tree, arriving at the correct historical framing (diplomatic-trade mission, not simple "tribute").
- **Gameplay:** dialogue tree with a genuine wrong-turn branch (an oversimplified framing the NPC can be steered toward correcting) — teaches the player that even in-world characters can hold imprecise views, modeling healthy skepticism.
- **Reward:** Codex entry E2.
- **Fictionalization notes:** the NPC and specific conversation are fictional; historical framing is accurate.
- **Completion:** reach the corrected framing in dialogue.

### HD03 — "What the Praśasti Says" (anchored to Doc 03 B2)
- **Location:** Site archive
- **Characters:** Scholar
- **Discovery method:** direct textual engagement — player reads (in translated form) an excerpt-style inscription passage and discusses its genre conventions with the Scholar.
- **Objective:** understand why praśasti inscriptions list conquered rulers without battle narrative.
- **Gameplay:** dialogue + Inscription Decoding puzzle combined.
- **Reward:** Codex entry B2 — this is arguably the single most important discovery quest in the game, since it directly explains why Acts 3–5 are labeled "HISTORICAL RECONSTRUCTION."
- **Fictionalization notes:** the specific passage shown is a fictional composite, clearly noted as such, illustrating a real genre convention.
- **Completion:** finish the Scholar dialogue.

### HD04 — "Water from the North" (anchored to Doc 03 D2)
- **Location:** Reservoir zone (post-Lion Well)
- **Characters:** Scholar
- **Discovery method:** guided reflection — this is deliberately the quest that most explicitly separates "tradition" from "documented fact" in the whole game.
- **Objective:** discuss the Ganga-water tradition with the Scholar after completing MQ17.
- **Gameplay:** dialogue only.
- **Reward:** Codex entry D2, explicitly worded "tradition holds that..." per Doc 03's required disclaimer.
- **Fictionalization notes:** none beyond the dialogue framing itself.
- **Completion:** finish dialogue.

### HD05 — "The Village Assembly" (anchored to Doc 03 F1)
- **Location:** A village near the capital
- **Characters:** village assembly members (background NPCs given brief speaking roles)
- **Discovery method:** observation — player watches a (fictionalized, clearly framed) assembly meeting in progress.
- **Objective:** observe the meeting, then discuss with the Scholar what's historically attested vs. dramatized.
- **Gameplay:** observation sequence + follow-up dialogue.
- **Reward:** Codex entry F1.
- **Fictionalization notes:** the specific meeting content is fictional dramatization of a real administrative pattern (careful generalization per Doc 03's disclaimer on locality-specific sourcing).
- **Completion:** finish follow-up dialogue.

### HD06 — "The Song Mission's Return" (anchored to Doc 03 E2/E3)
- **Location:** Port
- **Characters:** Naval Commander
- **Discovery method:** firsthand account — Naval Commander describes what such a mission would have required.
- **Objective:** listen to the account, ask clarifying questions.
- **Gameplay:** dialogue, distinguishes documented outcome (missions occurred) from reconstructed logistics detail.
- **Reward:** Codex entries E2 and E3 cross-referenced.
- **Fictionalization notes:** the Naval Commander's specific account is fictional but built on real logistics inference.
- **Completion:** finish dialogue.

### HD07 — "A Caster's Peak" (anchored to Doc 03 G1)
- **Location:** Artisan's workshop
- **Characters:** the Artisan
- **Discovery method:** hands-on demonstration — Artisan walks the player through the lost-wax process step by step.
- **Objective:** follow the demonstration, correctly sequence the casting steps (light puzzle).
- **Gameplay:** sequencing puzzle mirroring real cire perdue steps.
- **Reward:** Codex entry G1, detailed process explanation.
- **Fictionalization notes:** the specific object cast is fictional; the process is accurate.
- **Completion:** correct sequence completed.

### HD08 — "Reading Stone Age" (anchored to Doc 03 H2)
- **Location:** Multiple inscription sites (light travel quest)
- **Characters:** Scholar
- **Discovery method:** paleographic comparison across three inscriptions of different periods.
- **Objective:** correctly order the three inscriptions from oldest to newest using script-form cues.
- **Gameplay:** comparison puzzle (shares design DNA with SQ08 but plot-integrated with the Scholar's teaching arc rather than a standalone side quest).
- **Reward:** Codex entry H2.
- **Fictionalization notes:** specific inscriptions fictional; method accurate.
- **Completion:** correct ordering achieved.

### HD09 — "The Land Grant" (anchored to Doc 03 F2)
- **Location:** Temple precinct
- **Characters:** a temple official
- **Discovery method:** document investigation — player examines a (fictional, representative) land-grant record.
- **Objective:** interpret what the grant records about temple economic role.
- **Gameplay:** document-reading investigation, no combat.
- **Reward:** Codex entry F2.
- **Fictionalization notes:** the specific grant is fictional, representative of documented patterns.
- **Completion:** correct interpretation reached in dialogue with the official.

### HD10 — "What the Bronzes Show" (anchored to Doc 03 G1, different facet than HD07)
- **Location:** Temple treasury/storage (a new sub-location)
- **Characters:** temple official, Artisan (optional companion)
- **Discovery method:** direct object examination — player examines several finished bronzes, noting stylistic evolution.
- **Objective:** identify stylistic markers of the period's bronze casting peak.
- **Gameplay:** observation puzzle, similar shape to HD01 but applied to portable objects rather than architecture.
- **Reward:** Codex entry G1 (artistic/stylistic facet, distinct wording from HD07's process facet).
- **Fictionalization notes:** specific bronzes shown are fictional but styled accurately.
- **Completion:** identify markers correctly.

### HD11 — "The Co-Regency Question" (anchored to Doc 03 A2)
- **Location:** Site archive
- **Characters:** Scholar
- **Discovery method:** cross-referencing two documents with slightly different dates for Rajendra's co-regency start.
- **Objective:** understand why historians treat the exact date as approximate rather than fixed.
- **Gameplay:** cross-referencing puzzle, teaches how historians handle minor source disagreement without treating it as a crisis.
- **Reward:** Codex entry A2, worded to show the approximate-date handling explicitly.
- **Fictionalization notes:** the two "documents" shown are fictional composites illustrating a real category of source problem.
- **Completion:** finish the Scholar discussion.

### HD12 — "Beyond the Ganga" (anchored to Doc 03 A3)
- **Location:** Port, or site archive
- **Characters:** Scholar or Naval Commander
- **Discovery method:** dialogue distinguishing the Ganga campaign from the separate, less-emphasized Srivijaya campaign — directly addresses the Doc 03 A3 conflation risk.
- **Objective:** correctly distinguish the two campaigns in a follow-up quiz-style dialogue check.
- **Gameplay:** dialogue with a genuine correctness check (not just flavor — the game explicitly tests whether the player has absorbed the distinction, low stakes, retryable).
- **Reward:** Codex entry A3, explicitly separated from the B-cluster (Ganga) entries.
- **Fictionalization notes:** none beyond framing.
- **Completion:** correct distinction reached.

---

## Open Questions
- The remaining 8 discovery quests should be built from new Doc 03 entries once the Historical Research Director's team expands the database past its current 30 — recommend prioritizing entries on Chola-era religion/festivals and specific weapons/armament (both currently underrepresented in Doc 03) as the next research targets, since Docs 10 (Combat) and 17 (Art Direction) will need that evidence regardless.
- Whether HD01 (temple comparison) should instead be relocated to an actual Thanjavur revisit late-game rather than reference imagery — a scope/pacing tradeoff for the Level Designer.

## Dependencies on Other Documents
Doc 03 (every quest keyed to a specific entry), Doc 06 (Scholar as primary discovery-quest NPC), Doc 23 (Codex entries these quests unlock).

## Acceptance Criteria
- 12 discovery quests delivered, each keyed to a distinct Doc 03 evidence entry.
- No two quests use an identical discovery mechanic (observation, interview, document reading, sequencing, comparison, cross-referencing, and correctness-check are each used at least once).
- Every reward is explicitly a Codex entry with its confidence tier surfaced to the player.


---



<!-- ===== doc07d_quest_bible_puzzle_quests.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 4): QUEST BIBLE — PUZZLE QUESTS

**Document ID:** QB-07d · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Standalone/optional puzzle-focused quests, distinct from puzzle-bearing main/side/discovery quests already specified.
**Dependencies:** Production Bible v2 §2 (Puzzle Bible framework), Doc 07a–c (must not duplicate puzzle instances already used).

**Scope note:** cross-checking against Doc 07a–c, the plot-critical puzzle categories (Stone Alignment, Lion Well, Royal Seal, Inscription Decoding, Trade Ledger, Star-Sight Navigation, Map Reconstruction, Elevation & Load Deduction) are already load-bearing inside main/side/discovery quests. This document's honest job is different: it's where the four categories the Puzzle Bible flagged as "build as variants, not new systems" (Environmental, Logic, Historical Deduction, Pattern Recognition) actually get built as concrete instances, plus a handful of optional harder/standalone versions of the core systems for players who want more puzzle content than the main path requires. 10 quests below, each a genuinely distinct puzzle instance; remaining 10 should extend this same variant approach once the team sees which puzzle types playtest best — building all 20 before any playtesting data exists risks over-investing in a puzzle type that turns out not to land.

---

### PQ01 — "The Silted Channel" (Environmental, variant of Water Engineering)
- **Location:** A secondary, smaller canal near the capital, unrelated to the plot-critical Lion Well
- **Discovery/setup:** a side channel has silted up, affecting a small farm's water access — same underlying system as Lion Well but reframed as an environmental-observation puzzle (identify the blockage by reading the landscape, not a mechanical gate-sequence).
- **Objective:** locate the blockage using visual/environmental cues (sediment patterns, dying vegetation, altered water sound) rather than a UI hint.
- **Mechanics:** pure environmental reading, no interface overlay — rewards attentive exploration specifically.
- **Reward:** minor Codex flavor entry, farmer goodwill.
- **Historical basis:** [DOCUMENTED] general water-management context (Doc 03 D3). **Completion:** blockage cleared.

### PQ02 — "The Impossible Ledger" (Logic, variant of Trade Ledger Reconciliation)
- **Location:** Port archive
- **Setup:** a merchant's records contain a genuine logical contradiction (not a hidden villain — an honest bookkeeping error) that must be resolved through pure deduction, no new evidence to gather.
- **Objective:** solve the contradiction using only the information already provided (closed-logic puzzle, distinct from the evidence-gathering Trade Ledger instances elsewhere).
- **Mechanics:** self-contained logic puzzle — all information given upfront, solvable through reasoning alone.
- **Reward:** merchant goodwill, minor Codex entry on how period bookkeeping errors were actually caught and corrected.
- **Historical basis:** [DOCUMENTED] guild record-keeping context (Doc 03 E1). **Completion:** contradiction resolved.

### PQ03 — "Two Accounts" (Historical Deduction)
- **Location:** Site archive
- **Setup:** two NPC accounts of the same minor site event (e.g., a delivery mishap) conflict in a small detail; player must determine which is more reliable using the Scholar's evidence-evaluation principles (recency, motive, corroboration) rather than assuming one NPC is simply lying.
- **Objective:** determine the more reliable account and explain why.
- **Mechanics:** reasoning-based, explicitly teaches historical-source evaluation skills the player will need to use on real evidence elsewhere in the game (Doc 03's praśasti caution, applied at toy scale).
- **Reward:** Codex flavor entry on how historians weigh conflicting sources.
- **Historical basis:** method is [DOCUMENTED] historiographical practice; the specific event is [FICTIONAL]. **Completion:** correct account identified with correct reasoning given.

### PQ04 — "The Sculptor's Signature" (Pattern Recognition, variant of Inscription Decoding)
- **Location:** Temple, multiple sculptural panels
- **Setup:** individual sculptors left subtle stylistic "signatures" in their carving style (a real documented phenomenon in temple sculpture scholarship); player identifies which panels share a carver by pattern-matching style rather than reading text.
- **Objective:** correctly group panels by carver.
- **Mechanics:** visual pattern-matching, distinct from the text-based Inscription Decoding puzzles.
- **Reward:** Codex entry on individual craftsmanship visible in period sculpture — a genuinely interesting real art-historical fact.
- **Historical basis:** [DOCUMENTED] general phenomenon (comparative art-historical scholarship); specific panels are [FICTIONAL]. **Completion:** correct grouping achieved.

### PQ05 — "The Difficult Course" (Stone Alignment, optional hard variant)
- **Location:** An unfinished section of the temple, off the main path
- **Setup:** an optional, harder Stone Alignment challenge beyond the plot-critical Tier 1–3 progression, for players who want more.
- **Objective:** complete a Tier 4 "master course" with tighter tolerances and interacting load paths across more stones than any main-quest instance.
- **Reward:** cosmetic item (a craftsman's tool, no mechanical advantage — consistent with the no-arbitrary-RPG-stats principle from Doc 01 §24).
- **Historical basis:** [DOCUMENTED]/[FICTIONAL] as per base Stone Alignment system. **Completion:** puzzle solved.

### PQ06 — "Old Gates" (Water Engineering, optional hard variant)
- **Location:** A disused section of the reservoir system, separate from the Lion Well
- **Setup:** an older, partially collapsed section of the water system, offered as an optional harder puzzle after MQ17.
- **Objective:** restore flow through a more complex gate network than the main Lion Well chain.
- **Reward:** a hidden Codex entry on an earlier, undocumented phase of water infrastructure at the site — framed explicitly as [FICTIONAL] speculative content clearly distinguished from Doc 03 D1's documented reservoir.
- **Completion:** puzzle solved.

### PQ07 — "Reading the Sky Twice" (Astronomy-inspired, variant of Star-Sight Navigation)
- **Location:** Port, a rooftop observation point, land-based (not shipboard)
- **Setup:** rather than ship navigation, this is a standalone astronomy puzzle — cross-referencing star positions with a seasonal calendar to determine the correct date for an upcoming festival or tide event.
- **Objective:** determine the correct date using star-position and seasonal cues.
- **Mechanics:** land-based variant, distinct context from the naval Star-Sight puzzles.
- **Reward:** Codex flavor entry on period astronomical/calendrical knowledge.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION] of period astronomical practice. **Completion:** correct date determined.

### PQ08 — "The Stubborn Block" (Mechanical Engineering, variant of Elevation & Load Deduction)
- **Location:** Quarry road
- **Setup:** a single enormous stone block is stuck partway along the transport route; unlike MQ11/12's tool-sequencing puzzles, this one requires diagnosing *why* it's stuck (uneven ground, wrong roller placement) before applying a fix.
- **Objective:** diagnose and correct the problem.
- **Mechanics:** diagnostic-then-solve structure, distinct two-phase shape from the base puzzle's straightforward sequencing.
- **Reward:** construction-resource flavor bonus.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION] period engineering method. **Completion:** block moved.

### PQ09 — "The Merchant's Detour" (Map Reconstruction, optional variant)
- **Location:** Various, treasure-hunt structure
- **Setup:** a torn map fragment found in SQ02 (caravan escort) leads to a small optional location with a minor reward, structured as an optional side-treasure-hunt rather than a main-path region-unlock.
- **Objective:** assemble the fragment set, find the location.
- **Reward:** cosmetic item, minor Codex flavor entry.
- **Historical basis:** [FICTIONAL], built on documented general geography. **Completion:** location found.

### PQ10 — "The Final Course" (multi-system capstone, optional)
- **Location:** Temple, late-game
- **Setup:** an optional, harder alternative/companion to MQ29's capstone puzzle, combining Stone Alignment + Water routing + Inscription Decoding at their hardest tiers, offered to players who engaged deeply with all three systems across the game.
- **Objective:** complete the combined challenge.
- **Reward:** a unique Codex "completionist" entry reflecting on the craftsmanship themes of the whole game — narrative payoff, not a gameplay-advantage reward.
- **Historical basis:** as per component systems. **Completion:** puzzle solved.

---

## Open Questions
- Whether optional hard variants (PQ05, PQ06, PQ10) should be gated behind completing their main-quest counterparts first, to avoid difficulty-spiking a player who stumbles onto them early — Game Designer decision.
- Remaining 10 puzzle quests should be prioritized based on vertical-slice playtesting data on which of the four "variant" categories (Environmental, Logic, Historical Deduction, Pattern Recognition) players respond to best, rather than split evenly by default.

## Dependencies on Other Documents
Production Bible v2 §2 (base puzzle systems), Doc 07a–c (avoiding duplicate instances), Doc 25 (Progression Bible — confirms these carry no numeric reward, consistent with no-arbitrary-stats principle).

## Acceptance Criteria
- 10 puzzle quests delivered, none duplicating a puzzle instance already used in Doc 07a–c.
- All four "variant-only" categories from the Puzzle Bible (Environmental, Logic, Historical Deduction, Pattern Recognition) represented at least once.
- No puzzle quest reward is a numeric/mechanical power advantage, consistent with Doc 01's progression principle.


---



<!-- ===== doc07e_quest_bible_naval_quests.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 5): QUEST BIBLE — NAVAL QUESTS

**Document ID:** QB-07e · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Maritime-focused quest content, extending Act 11's Naval Commander/Merchant arcs beyond the three main quests (MQ23–25) already specified.
**Dependencies:** Doc 03 (E1–E4 evidence cluster), Doc 06 (Naval Commander, Merchant), Doc 12 (Naval Design Bible — referenced, not yet authored in full), World Bible §4.7 (port).

**Scope note:** 15 distinct naval quests is achievable without repetition, but several of the "obvious" ones (basic cargo runs, basic navigation puzzles) are already covered by MQ23–25 and PQ07/PQ09. Below are 10 that each explore a different facet of the maritime world your brief calls for — diplomacy, crew welfare, the ship-design evidentiary gap turned into an actual story beat rather than hidden, piracy, and multi-port geography — plus a note on the remaining 5.

---

### NQ01 — "The Srivijaya Question" (anchored to Doc 03 A3)
- **Location:** Port, diplomatic quarter
- **Characters:** Naval Commander, a Southeast Asian envoy NPC
- **Synopsis:** A diplomatic envoy arrives referencing the earlier (historically separate) Chola campaign near Srivijaya — gives the player a chance to see how that documented but under-emphasized campaign echoes into the present of the story.
- **Objective:** navigate a diplomatic reception, avoid conflating this with the Ganga campaign (mirrors HD12's teaching point in live gameplay).
- **Gameplay:** dialogue-forward diplomacy, reputation-tracked.
- **Choices:** tone of the reception (formal/warm/cautious) — affects a later trade-agreement quest (NQ05).
- **Historical basis:** Doc 03 A3. **Fictionalization notes:** envoy and specific meeting fictional.
- **Completion:** reception concludes without diplomatic incident.

### NQ02 — "Crew's Due" (crew welfare)
- **Location:** Ship, at sea
- **Characters:** Naval Commander, crew NPCs
- **Synopsis:** A dispute over pay/provisions among the crew — grounds the "morale" system your brief calls for in a concrete quest rather than an abstract meter.
- **Objective:** resolve the dispute before it affects the voyage.
- **Gameplay:** dialogue mediation, light morale-system tutorial.
- **Choices:** side with the crew's demands / side with strict discipline / compromise.
- **Consequences:** morale state affects ambient crew dialogue and, narratively, how NQ03 plays out.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION] general maritime labor conditions. **Completion:** dispute resolved.

### NQ03 — "Becalmed" (weather/patience)
- **Location:** Open water
- **Characters:** Naval Commander, crew
- **Synopsis:** The ship is stuck without wind — a deliberately slow, low-tension quest exploring the unglamorous reality of pre-modern sea travel, tonally distinct from the Act 11 storm set-piece.
- **Objective:** wait out the calm, manage dwindling supplies.
- **Gameplay:** light resource management under time pressure, no combat.
- **Consequences:** crew morale from NQ02 affects how tense this quest feels narratively (dialogue variation only).
- **Historical basis:** [LIKELY] general sailing-era experience. **Completion:** wind returns.

### NQ04 — "The Unmarked Ship" (piracy, grounded)
- **Location:** Open water, coastal
- **Characters:** Naval Commander, hostile crew (grounded pirates/raiders, not fantastical)
- **Synopsis:** A genuine naval threat encounter, distinct in framing from Act 11's storm-adjacent combat — this one is a deliberate raid, not an accident of weather.
- **Objective:** defend the ship or evade.
- **Gameplay:** naval combat (Doc 10/12), with a stealth-evasion alternative.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION] — piracy/raiding as a general maritime-era risk, not documenting a specific attested incident. **Completion:** survive the encounter.

### NQ05 — "Terms of Trade" (payoff of NQ01)
- **Location:** Port
- **Characters:** the envoy from NQ01, Merchant
- **Synopsis:** Formalize a trade arrangement building on NQ01's diplomatic tone.
- **Objective:** negotiate terms.
- **Gameplay:** Trade Ledger Reconciliation-adjacent negotiation puzzle (new numbers, new stakes — not a straight reuse).
- **Consequences:** affects port prosperity flavor content in Act 12's living-city state.
- **Historical basis:** Doc 03 E1–E2. **Completion:** terms agreed.

### NQ06 — "What the Shipwright Knows" (directly engages the Doc 03 E4 evidence gap)
- **Location:** Port, shipyard
- **Characters:** a shipwright NPC, Scholar (optional)
- **Synopsis:** Rather than hiding the fact that we don't have strong direct evidence for exact Chola ship construction, this quest makes that gap the actual subject — the shipwright explains what's built from regional tradition and inference vs. what nobody can say for certain.
- **Objective:** tour the shipyard, discuss construction methods.
- **Gameplay:** dialogue-forward, explicitly Codex-flagged as [PLAUSIBLE RECONSTRUCTION] throughout.
- **Reward:** Codex entry E4, honestly framed as the game's most speculative maritime content.
- **Historical basis:** Doc 03 E4 (the gap itself). **Completion:** tour finished.

### NQ07 — "The Second Port" (new location introduction)
- **Location:** A second, smaller port distinct from World Bible §4.7's main representative port
- **Characters:** local port officials, minor merchants
- **Synopsis:** Expands the maritime map beyond the single hub port, showing the network is more than one location per your brief's "large-scale world design" pillar.
- **Objective:** establish first contact, resolve a small local problem (e.g., a tax dispute, echoing SQ01 but at a different location/stakes).
- **Gameplay:** exploration, light dialogue.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION] general network extent (Doc 03 E1). **Completion:** local problem resolved.

### NQ08 — "Lost Cargo" (investigation crossover)
- **Location:** Between ports
- **Characters:** Merchant, Naval Commander
- **Synopsis:** A shipment goes missing — ties the naval thread back to the investigation system rather than treating maritime content as mechanically separate from the game's core verb.
- **Objective:** investigate what happened (theft, wreck, or diverted route — player determines via evidence).
- **Gameplay:** investigation chain (Doc 11 pattern) applied to a maritime context.
- **Puzzle:** Trade Ledger Reconciliation + light Historical-Deduction-style reasoning.
- **Historical basis:** [FICTIONAL]. **Completion:** mystery resolved, cargo's fate determined.

### NQ09 — "The Tide Calendar" (astronomy/navigation, standalone)
- **Location:** Port
- **Characters:** a local navigator NPC
- **Synopsis:** Learn how tidal/seasonal timing was tracked for safe departures — distinct from PQ07's calendrical puzzle by focusing specifically on tide/departure-window planning rather than festival dating.
- **Objective:** determine the correct departure window.
- **Gameplay:** Star-Sight Navigation variant, land-based planning phase before a voyage.
- **Historical basis:** [PLAUSIBLE RECONSTRUCTION]. **Completion:** correct window chosen; voyage safety reflects choice quality (not a hard fail state).

### NQ10 — "Home Waters" (capstone, ties into Act 12)
- **Location:** Coastal approach to the capital region
- **Characters:** Naval Commander, full returning crew
- **Synopsis:** The final naval quest — the fleet returns richer in trade relationships (if NQ01/05/07 went well) as part of the Act 12 living-city payoff.
- **Objective:** final voyage home.
- **Gameplay:** mostly cinematic/exploration, reflecting accumulated naval-thread choices in dialogue and port prosperity flavor.
- **Historical basis:** as per component systems. **Completion:** arrival at Act 12 content.

---

## Open Questions
- Remaining 5 naval quests: recommend these be built once Doc 12 (Naval Design Bible) is fully authored, since several of the above (NQ04, NQ09) are already pushing against ship-combat/navigation mechanics that document doesn't fully specify yet — writing more naval quests before Doc 12 locks risks quest design driving mechanical design backwards.
- Whether NQ07's second port deserves full World Bible §4-style location treatment — Level Designer/World Designer call.

## Dependencies on Other Documents
Doc 03 (E1–E4), Doc 06 (Naval Commander/Merchant), Doc 12 (Naval Design Bible, pending), Doc 11 (investigation pattern reused in NQ08).

## Acceptance Criteria
- 10 naval quests delivered, none duplicating MQ23–25 or PQ07/PQ09 content.
- The Doc 03 E4 evidentiary gap is addressed directly in-fiction (NQ06) rather than silently smoothed over.
- At least one quest (NQ08) connects the maritime thread back to the game's core investigation verb rather than treating it as an isolated minigame.


---



<!-- ===== doc07f_quest_bible_scholar_archive_quests.md ===== -->

# GANGAIKONDA — DOCUMENT 07 (PART 6): QUEST BIBLE — SCHOLAR/ARCHIVE QUESTS

**Document ID:** QB-07f · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Quests centered on the Scholar's personal arc and the Royal Archive system itself — distinct from Historical Discovery Quests (Doc 07c), which are keyed to specific historical evidence content. This set is about the *institution and relationship* of scholarship, not any one fact.
**Dependencies:** Doc 06 (Scholar full profile), Doc 04 (Scholar's arc: institutional caution → active whistleblower-adjacent role).

**Scope note:** same approach as the prior sets — 10 quests below tracing the Scholar's full arc end to end (this is the one category where completeness of the *arc*, not raw count, is what matters, since a partial character arc is worse than a shorter complete one), with the remaining 5 left as optional deepening content once the team sees how players respond to the Scholar relationship in playtesting.

---

### SA01 — "The Archive Room" (introduction)
- **Location:** Site archive (first establishment as a real space, expanding on MQ18's system intro)
- **Characters:** Scholar
- **Synopsis:** The Scholar formally shows Arulan the physical/institutional Archive — not just the UI system, but what it represents to her/him.
- **Objective:** tour the Archive, learn its organizational logic (by evidence category, per the Foundation Bible tags).
- **Gameplay:** dialogue-forward, light UI-teaching.
- **Reward:** Archive organization tools unlocked (sort/filter by confidence tier).
- **Completion:** tour finished.

### SA02 — "Before the Capital" (Scholar backstory)
- **Location:** Archive
- **Characters:** Scholar
- **Synopsis:** The Scholar shares why they became an epigrapher — a personal-history quest establishing their institutional caution as earned, not just a personality trait.
- **Objective:** dialogue tree, player can ask follow-up questions.
- **Gameplay:** pure dialogue.
- **Consequences:** relationship depth flag, affects tone of later Scholar scenes.
- **Completion:** conversation concludes.

### SA03 — "What Belongs in the Record" (institutional ethics, early)
- **Location:** Archive
- **Characters:** Scholar
- **Synopsis:** A minor disagreement over whether an ambiguous finding should be recorded as fact or flagged uncertain — directly dramatizes the game's evidence-honesty pillar as a character conflict rather than just a UI rule.
- **Objective:** weigh in on the debate.
- **Choices:** argue for recording it as fact (Scholar pushes back) / argue for flagging it uncertain (Scholar agrees, reinforcing the theme) / stay neutral.
- **Consequences:** the correct-per-theme choice (flag as uncertain) modestly deepens relationship; the "record as fact" choice isn't punished but the Scholar visibly, respectfully disagrees — the game doesn't force the "right" answer, but doesn't hide its values either.
- **Completion:** debate resolved.

### SA04 — "Conflicting Sources" (skill-building, ties to HD11's method)
- **Location:** Archive
- **Characters:** Scholar
- **Synopsis:** A harder cross-referencing exercise than HD11, applying the co-regency-dating lesson to a new, higher-stakes case relevant to the conspiracy thread's evidence pool.
- **Objective:** resolve the source conflict.
- **Gameplay:** cross-referencing puzzle.
- **Consequences:** strengthens MQ19's evidence quality if completed before that quest.
- **Completion:** conflict resolved.

### SA05 — "The Scholar's Caution" (arc midpoint)
- **Location:** Site office
- **Characters:** Scholar, Architect (background)
- **Synopsis:** As conspiracy evidence mounts (post-MQ13), the Scholar is reluctant to formally record findings that could implicate the administration — dramatizes the "institutional caution" half of their arc directly.
- **Objective:** persuade the Scholar to help formally investigate (or respect their hesitation and proceed without them, a genuine choice).
- **Choices:** push the Scholar to act / respect their caution and proceed alone.
- **Consequences:** meaningfully affects Scholar's role in MQ19/27 — if pushed too hard too early, Scholar is less trusting later; if respected, they come around more slowly but more fully.
- **Completion:** scene resolved either way.

### SA06 — "Teaching the Apprentice" (mentorship, mirrors SA01/02 in reverse)
- **Location:** Archive
- **Characters:** Scholar, a new junior scribe NPC (possibly SQ07's character)
- **Synopsis:** The Scholar asks Arulan to help train a new archive assistant — Arulan, now experienced, teaches what he learned in Act 1–2's tutorial quests back to someone else, a structural callback.
- **Objective:** guide the junior scribe through a simplified Inscription Decoding puzzle, coaching rather than solving it yourself.
- **Gameplay:** unique "teach, don't solve" puzzle framing.
- **Reward:** Codex reflection entry, Scholar relationship deepens.
- **Completion:** junior scribe successfully completes the puzzle with Arulan's guidance.

### SA07 — "The Archive Speaks" (conspiracy climax tie-in, concurrent with MQ19)
- **Location:** Archive
- **Characters:** Scholar
- **Synopsis:** The Scholar, now committed (per SA05's resolution), formally helps compile the MQ19 evidence into an official record — the arc's turning point into active whistleblower-adjacent territory.
- **Objective:** work with the Scholar to formalize the conspiracy evidence.
- **Gameplay:** Codex assembly, dialogue.
- **Consequences:** directly strengthens MQ27's evidence-presentation options.
- **Completion:** formal record compiled.

### SA08 — "What It Will Cost" (ethical dilemma, late)
- **Location:** Archive
- **Characters:** Scholar
- **Synopsis:** The Scholar voices genuine fear about what formally recording the conspiracy findings will cost them personally/institutionally — this is the moment their earlier caution is shown to have been reasonable, not just an obstacle to route around.
- **Objective:** support the Scholar through this scene.
- **Choices:** offer to shield them from consequences / acknowledge the risk honestly without false promises / offer to proceed without their name attached.
- **Consequences:** meaningfully feeds MQ28's relationship resolution and the ending-variant weighting.
- **Completion:** scene resolved.

### SA09 — "The Larger Archive" (system expansion, optional)
- **Location:** Archive, expanded wing
- **Characters:** Scholar
- **Synopsis:** With the conspiracy resolving, the Scholar proposes expanding the Archive to properly house everything discovered across the whole game — a satisfying systems-payoff quest that also reinforces the "this is a real institution, not just a menu" framing from SA01.
- **Objective:** help organize the expanded space (light puzzle: correctly categorize a batch of mixed-confidence-tier findings).
- **Reward:** cosmetic Archive upgrade, full-game Codex review unlocked as a browsable space.
- **Completion:** expansion organized.

### SA10 — "What the Scholar Leaves Behind" (arc capstone, feeds Investigator's Path ending)
- **Location:** Archive, Act 12
- **Characters:** Scholar
- **Synopsis:** Final Scholar scene — reflects on the whole arc from institutional caution to active participation in exposing the truth; this is the quest most directly feeding the "Investigator's Path" ending variant from Doc 04.
- **Objective:** final conversation.
- **Choices:** determined largely by accumulated SA03/05/08 choices rather than a fresh choice here — this quest mostly pays off prior decisions rather than introducing new ones.
- **Consequences:** directly determines whether the Investigator's Path ending is available/how it's framed.
- **Completion:** conversation concludes, feeds into MQ28/30.

---

## Open Questions
- Remaining 5 quests are genuinely optional deepening content (additional cross-referencing exercises, additional apprentice-teaching scenes) — recommend building only if playtesting shows players are engaging deeply with the Scholar relationship; if not, that design effort is better spent elsewhere.
- Whether SA08's "shield them from consequences" choice should have a mechanical cost (e.g., weaker MQ27 evidence) or remain purely a character-trust choice — Narrative Director decision.

## Dependencies on Other Documents
Doc 06 (Scholar full profile — this document is essentially that profile's arc, quest-by-quest), Doc 04 (Act 8/9/12 placement), Doc 07a (MQ13/18/19/27/28 cross-references throughout).

## Acceptance Criteria
- 10 quests delivered, tracing the Scholar's complete arc (institutional caution → active participation) start to finish with no gap.
- SA08 explicitly validates the Scholar's earlier caution rather than treating it as a flaw to be overcome — consistent with not writing institutional caution as simple cowardice.
- SA10 explicitly connects to the Doc 04 ending-variant system.


---



<!-- ===== doc08_vertical_slice_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 08: VERTICAL SLICE BIBLE

**Document ID:** VSB-08 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Minute-by-minute plan for the 30–45 minute vertical slice (Gangaikondacholapuram construction zone).
**Dependencies:** Docs 02, 07a, 09, 13, Production Bible v2 §1
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Slice Timeline (40 min target)

| Min | Beat | Location / NPC | Objective & Gameplay | Camera / Audio / UI | Trigger / Save / Transition |
|---|---|---|---|---|---|
| 0–2 | Arrival | Approach road; background workers | Traverse to gate; movement tutorial | Follow-cam; wind + distant chisels; minimal HUD | Gate trigger → autosave |
| 2–6 | City exploration | Worker settlement; Tier 3 crowd | Free explore; ambient barks; first scan prompt | Follow-cam; market/construction ambience | Interact with scan point |
| 6–9 | Meet Scholar | Archive tent; Scholar | Dialogue (Doc 06 §3); receive scan tool | Dialogue close-ups; Codex UI intro | Dialogue end → autosave |
| 9–14 | Discover inscription | Foundation stone | Inscription Decoding Tier 1 (MQ02 pattern) | Puzzle cam; scan UI | Solve → Codex entry "HISTORICAL RECORD DISCOVERED" |
| 14–18 | Meet architect | Planning pavilion; Architect | Dialogue + first branching choice (cosmetic) | Dialogue UI; evidence-category indicator | Choice flag set; save |
| 18–23 | Water puzzle | Reservoir/canal | Lion Well stages 1–4 | Puzzle cam; water audio feedback | Stage 4 → hidden-inscription flag |
| 23–27 | Temple construction | Scaffolding | Stone Alignment Tier 1; vertical traversal | Wide architectural shots | Solve → save |
| 27–31 | Investigation | Site office | Ledger discrepancy; Royal Seal Verification Tier 1 (MQ13/19 pattern) | Evidence-compare UI | Contradiction found |
| 31–33 | Political conspiracy | Site office; Antagonist cameo | Persuasive scene; choice to raise concern now/later | Dialogue UI; Conspiracy theme (sparse) | Choice flag; autosave |
| 33–37 | Ambush | Transit route | Combat/stealth hybrid (Doc 10/11) | Combat HUD (health/stamina only) | Survive/evade → save |
| 37–38 | Return | Settlement core | Report; second branch (cosmetic) | Follow-cam | Flag set |
| 38–40 | Historical Codex + cinematic | Archive; dusk overlook | Codex assembly; closing cinematic (Doc 05 style) | Cinematic cam; score swell earned here | End of slice |

## Proof Points
Graphics (Nanite/Lumen at construction-zone density), gameplay, story, puzzles, NPC AI (Tier 1–3), dialogue, environment, UI, audio, historical presentation (Codex format + confidence tiers).


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc09_puzzle_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 09: PUZZLE BIBLE

**Document ID:** PB-09 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Puzzle catalog with rules, hints, solutions, accessibility alternatives.
**Dependencies:** Production Bible v2 §2, Doc 07d
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Scope note (honest)
The brief asks for 50 puzzles with full fields. Below are **20 puzzles specified at working depth** across all 13 categories, covering every puzzle instance referenced in Docs 07a–f. The remaining 30 should be authored by the Puzzle Designer as *instances* of these systems after vertical-slice playtesting shows which systems land. Each entry: ID · Title · Location · Narrative purpose · Historical basis · Rules/Mechanics · Hints · Solution logic · Failure/Reset · Accessibility · Reward · Codex.

| ID | Title (Category) | Location | Core rules & solution logic | Failure / Reset / Accessibility | Reward / Codex |
|---|---|---|---|---|---|
| P01 | Course of Four (Stone Alignment T1) | Temple scaffold | Orient 4 granite blocks so load paths bear on contact points; stress visibly cracks wrong placement | Soft fail: re-lift block; hint depth setting; highlight contact points | Codex C3/G2 |
| P02 | Rising Courses (Stone Alignment T2) | Temple | Multi-course; upper loads feed lower | Same | Codex |
| P03 | Master Course (Stone Alignment T3/T4) | Temple / unfinished wing | Interacting load paths, tighter tolerance | Same | Cosmetic tool |
| P04 | Dry Channel (Lion Well 1–3) | Reservoir | Identify source elevation; sequence 3 sluice gates | Reset gates; flow-preview toggle | Progress |
| P05 | The Hidden Flow (Lion Well 4–6) | Reservoir | Silt blockage + competing channels; restore full flow → reveal inscription | Reset; colorblind-safe flow indicators | Codex D1/D2 (tradition-labelled) |
| P06 | Old Gates (Water, optional) | Disused wing | Larger gate network | Reset | Speculative Codex [FICTIONAL] |
| P07 | Silted Channel (Environmental) | Secondary canal | Read sediment/vegetation/sound to locate blockage; no UI overlay | Audio/visual cue alternatives | Farmer goodwill |
| P08 | Training Seal (Royal Seals T0) | Court | Compare seal against reference set | Hint highlights differences | Codex |
| P09 | Forged Grant (Royal Seals, plot) | Site office | Spot anachronistic script/titulature | Reset; hint tiers | MQ19 evidence |
| P10 | Scratched Stone (Inscription T1) | Foundation stone | Match fragments to Scholar's chart | Chart always visible at easy | Codex H1/H2 |
| P11 | Three Eras (Inscription dating) | Archive | Order 3 inscriptions by script evolution | Retry w/ explanation | Codex H2 |
| P12 | Conflicting Sources (Cross-reference) | Archive | Reconcile two sources (HD11/SA04 pattern) | Retry | Codex A2 |
| P13 | Lost Cargo (Trade Ledger) | Port | Reconcile manifests/taxes/seals | Reset; highlight mismatches | MQ24 evidence |
| P14 | Impossible Ledger (Logic) | Port archive | Closed-logic deduction, all info given | Hint tiers | Merchant goodwill |
| P15 | Star Sight T1/T2 (Navigation) | Ship / port | Align heading via named stars + coastline silhouette | Assist: heading guide | Naval unlock |
| P16 | Tide Window (Astronomy) | Port | Choose departure window from calendar+tide cues | Retry | Codex |
| P17 | Torn Chart (Map Reconstruction) | Archive | Assemble fragments by landmark | Snap-assist | Region unlock |
| P18 | Stubborn Block (Mechanical) | Quarry road | Diagnose then fix transport blockage | Reset | Resource flavor |
| P19 | Two Accounts (Historical Deduction) | Archive | Weigh recency/motive/corroboration | Hint tiers | Codex flavor |
| P20 | Sculptor's Signature (Pattern) | Temple panels | Group panels by carver style | Zoom/compare assist | Codex art entry |

**Capstone (P21):** combined Stone + Water + Inscription (MQ29/PQ10).

## Design Test (every puzzle)
1) Which real craft does it simulate? 2) What does it teach? 3) Why here in the story? Fail any → cut.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc10_combat_design_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 10: COMBAT DESIGN BIBLE

**Document ID:** CDB-10 · **Version:** 1.0 · **Status:** Draft — weapons/armament evidence gap flagged in Doc 03's Open Questions is partially addressed below; full lock requires Historical Research Director sign-off on the weapons table specifically.
**Purpose:** Full combat system specification, grounded in period-appropriate equipment and a "consequence system, not core loop" design philosophy per Doc 01 §12.
**Dependencies:** Doc 01 §12 (combat principle), Doc 06 (character combat styles), Doc 03 (evidence — see new entries below).

---

## 0. New Historical Evidence (addressing Doc 03's flagged gap)

| ID | Claim | Category | Source Type | Confidence | Notes |
|---|---|---|---|---|---|
| I1 | South Indian militaries of this general period used sword, spear, bow, shield, and dagger as standard infantry equipment, per sculptural depictions and comparative regional military history | PLAUSIBLE RECONSTRUCTION | Temple sculpture/relief, comparative regional scholarship | LIKELY | Sculptural sources are stylized (per Doc 03 G3 caveat) — exact metallurgy/construction details are not independently attested at engineering-diagram precision |
| I2 | The Chola military included cavalry and war elephants as part of its documented military capability | DOCUMENTED (general capability) | Inscriptions referencing military campaigns; comparative South Indian military history | LIKELY | Specific unit composition/ratios are UNCERTAIN |
| I3 | Specific armor construction (materials, coverage) for Chola-era soldiers | UNCERTAIN/UNKNOWN | Very limited direct evidence — organic/metal armor components rarely survive intact | UNCERTAIN | Genuine evidentiary gap — in-game armor design must be tagged [PLAUSIBLE RECONSTRUCTION] throughout, built from regional comparative scholarship, not asserted as documented |

**This document proceeds on I1–I3, all explicitly [PLAUSIBLE RECONSTRUCTION]. No specific weapon or armor piece in this document should be Codex-logged as documented archaeological fact.**

---

## 1. Combat Design Philosophy
Per Doc 01 §12: combat is a **consequence system**, punctuating the investigation/conspiracy thread and campaign logistics, not the moment-to-moment core loop. Design target: functional, grounded, occasionally tense — never a power-fantasy escalation. No supernatural abilities, no anachronistic weapon technology.

## 2. Weapons

| Weapon | Historical basis | Role | Notes |
|---|---|---|---|
| Sword (curved single-edge, period-typical) | Doc 03 I1 | Arulan's primary weapon | Balanced speed/damage |
| Spear | Doc 03 I1 | Common enemy weapon, reach advantage | Effective vs. shielded enemies |
| Bow | Doc 03 I1 | Ranged, used by scouts/skirmishers | No modern draw-weight claims; treated as period-plausible ranged option |
| Shield | Doc 03 I1 | Core of the blocking system (§4) | Paired with sword/spear |
| Dagger | Doc 03 I1 | Stealth-attack weapon (§8), secondary sidearm | |
| Staff | your brief's list | Non-lethal option for some encounters (guards, non-fatal resolution paths) | Supports non-lethal playstyle without breaking grounded tone |

**Explicitly excluded:** no exotic/impossible weapon types, no magic-infused equipment, no anachronistic metallurgy claims.

## 3. Combat Styles & Enemy Classes

- **Arulan's style:** practical, defensive-leaning, capable-but-not-superhuman (Doc 06 §2) — sword-and-shield baseline, dagger for stealth, staff for non-lethal resolution.
- **Enemy classes:**
  - **Bandits/raiders** (Act 3, Act 9 ambush, NQ04) — lightly equipped, opportunistic, will flee if outmatched (grounded AI behavior, not fight-to-the-death default).
  - **Hostile local skirmishers** (Act 3 campaign context) — organized, spear/bow mix, terrain-aware.
  - **Hired antagonist-linked attackers** (MQ20) — better equipped than bandits, disciplined, but still mortal/grounded — no armor-class power creep into fantasy territory.
  - **Naval raiders** (NQ04, Doc 12 cross-reference) — ship-boarding combat variant.

## 4. Armor
Per Doc 03 I3's evidentiary gap: armor is light/practical (padded or minimal metal reinforcement for common soldiers, per regional comparative scholarship), tagged [PLAUSIBLE RECONSTRUCTION] throughout. No heavy-plate fantasy armor. Arulan wears practical, unarmored-to-lightly-protected clothing consistent with his non-soldier role (Doc 06 §2).

## 5. Blocking & Parrying
- **Block:** shield-raise, reduces damage, has a stamina cost, can be broken by heavy attacks (spear thrusts from multiple enemies).
- **Parry:** timing-window deflect with sword, opens a brief enemy vulnerability window — rewards read-and-react play over button-mashing.

## 6. Dodging
Stamina-costed directional dodge, primary defense against spear-reach enemies and multi-enemy encounters (positioning matters more than raw damage output).

## 7. Stamina
Shared resource across block/parry/dodge/heavy-attack — prevents combat from becoming a stamina-free spam-fest, keeps encounters short and tense rather than attritional, consistent with the "consequence system, not core loop" philosophy (fewer, more meaningful fights rather than constant combat).

## 8. Damage & Stealth Attacks
- **Damage model:** grounded — a small number of hits is lethal/incapacitating in both directions, reinforcing that Arulan is not a superhuman warrior (no regenerating-health-through-dozens-of-hits design).
- **Stealth attacks:** dagger-based takedown from concealment, primary tool for the social-stealth-heavy design (Doc 01 §13) — favors avoiding open combat where the narrative supports it (e.g., MQ20's evade option).

## 9. Status Effects
Minimal and grounded — no exotic elemental status effects. Limited to: bleeding (from certain hits, minor DOT), staggered (from parries/heavy blocks), and fatigued (low-stamina state reducing action options). No poison/fire/ice fantasy tropes.

## 10. Mounted Combat
Historically plausible given Doc 03 I2 (cavalry existed) — limited mounted combat sequences possible during Act 3 campaign content specifically (not a full mounted-combat system used throughout the game, to keep scope proportionate). Recommend restricting to scripted campaign sequences rather than free-roam mounted combat.

## 11. Sieges
Not recommended as a core system given project scope and the game's civic-building/investigation focus rather than large-scale warfare focus — if a siege-adjacent sequence is wanted narratively (e.g., a campaign set-piece in Act 3), it should be built as a scripted sequence using existing combat/logistics systems rather than a dedicated new siege system, to avoid unnecessary scope growth.

## 12. Naval Combat
See Doc 12 (Naval Design Bible) for full specification — this document's role is to confirm naval combat uses the same grounded weapon/damage philosophy (boarding actions use the same sword/spear/bow/dagger kit as land combat; no naval-specific fantasy weaponry), per NQ04's design.

---

## Open Questions
- Exact stamina numbers/damage values need playtesting once the vertical slice is built — this document specifies systems and philosophy, not final tuning numbers.
- Whether mounted combat sequences (§10) are worth the animation/production cost given their limited scope — Production Manager/Technical Director call, flag for Doc 46 Risk Register.
- Full weapons table (§2) should be reviewed by the Historical Authenticity Consultant against any newer research the Historical Research Director's team produces on Doc 03's I1–I3 gap.

## Dependencies on Other Documents
Doc 01 §12–13 (combat/stealth principles), Doc 03 (new I1–I3 evidence), Doc 06 (character combat styles), Doc 11 (stealth system detail), Doc 12 (naval combat detail).

## Acceptance Criteria
- No weapon, armor, or combat mechanic presented as more historically certain than Doc 03 I1–I3 support.
- Combat remains a "consequence system" per Doc 01 §12 — no design element here pushes it toward becoming the core gameplay loop.
- No modern combat mechanics disguised as historical weapons (per your explicit rule) — confirmed via §2's explicit exclusion list.


---



<!-- ===== doc11_stealth_investigation_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 11: STEALTH & INVESTIGATION BIBLE

**Document ID:** SIB-11 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full specification of the game's two most heavily-used systems — investigation (the primary verb, per Doc 01 §14) and stealth (secondary, social-stealth-weighted per Doc 01 §13).
**Dependencies:** Doc 01 §13–14, Doc 06 (character skills), Doc 07 (quests using these systems extensively — MQ19/20, SA-series, HD-series).

---

## PART A — STEALTH

### 1. Visibility
Line-of-sight based detection, modulated by lighting (ties to Doc 34 Lighting Bible — shadowed areas reduce detection range) and cover (structures, crowds, scaffolding at construction sites).

### 2. Sound
Footstep/action noise attracts NPC attention within a radius modulated by ambient noise level (a busy market masks more sound than a quiet archive at night) — this directly rewards the living-world pillar: the same stealth action is easier or harder depending on time-of-day/location activity level (Doc 01 §25 world simulation).

### 3. NPC Suspicion
Graduated (not binary) suspicion state: **Unaware → Alert → Searching → Hostile**, with a cooldown/de-escalation path if the player breaks line of sight and suspicion isn't confirmed — avoids the frustration of instant-restart stealth failure, consistent with the game's generally non-punitive failure-state philosophy (Doc 01 §14 investigation failure states).

### 4. Disguises
Period-appropriate role-based disguises (worker's dress, scribe's dress, merchant's dress) grant contextual access rather than full invisibility — a disguise gets Arulan into a restricted area without automatic suspicion, but behaving inconsistently with the role (running, entering off-limits sub-areas) still raises suspicion. This keeps disguises a narrative/access tool rather than a stealth-trivializing cheat.

### 5. Social Stealth
Given the capital's population density (living-world pillar), **crowd-blending is as important as line-of-sight stealth** per Doc 01 §13 — moving through market crowds or temple festival gatherings reduces detection range significantly, reflecting a dense urban environment rather than empty patrol corridors typical of stealth games set in isolated environments.

---

## PART B — INVESTIGATION

### 6. Evidence Gathering
Core interaction: scan (inscriptions/documents/objects), observe (environmental storytelling cues), and collect (portable evidence items feeding the Codex/Archive system per Doc 07f).

### 7. Tracking
Environmental tracking (footprints, disturbed materials, cart-wheel ruts) used sparingly — primarily in MQ19/20 (conspiracy investigation, ambush aftermath) rather than as a constant mechanic, keeping it meaningful when it appears.

### 8. Interrogation
Not a forceful "interrogation" system in the crime-thriller sense — consistent with the game's grounded, non-punitive tone, this is dialogue-tree-based questioning with a trust/rapport variable (per Doc 13 NPC memory principle) rather than a pressure meter. SQ09 ("The Reluctant Witness") is the fullest example of this system in practice.

### 9. Document Discovery
Physical documents (ledgers, letters, grants) function alongside inscriptions as evidence — introduced via MQ13's ledger and expanded through the conspiracy thread; document evidence and inscription evidence share the same Codex/confidence-tagging system (Doc 03 format) so the player doesn't need to learn two separate evidence languages.

### 10. Inscription Investigation
The signature system (per your original Act 9 design and HD03/HD08/HD11's full treatment) — scan → decode → compare → cross-reference, mechanically detailed in Production Bible v2 §2.4.

### 11. Witness Systems
NPCs carry persistent memory of what they've witnessed (Doc 13 principle extended specifically to investigation-relevant events) — a witness who saw something relevant to the conspiracy remembers it whether or not the player has discovered that they're a witness yet, so the world doesn't feel like it's waiting for the player to trigger content.

---

## 12. The Investigation Chain (full worked example)

Per your specified chain, worked through using the MQ19 conspiracy thread as the concrete case:

```
DISCOVER INSCRIPTION/DOCUMENT
  → (MQ13: ledger discrepancy noticed)
TRANSLATE / DECODE
  → (Inscription Decoding or document-reading interaction)
CROSS-REFERENCE
  → (SA04: compare against other Archive holdings, surfaces a contradiction)
FIND LOCATION
  → (evidence points to the storage yards)
QUESTION NPC
  → (SQ09: the reluctant witness, or direct site officials)
DISCOVER CONTRADICTION
  → (MQ19: witness account conflicts with official ledger)
INVESTIGATE FURTHER
  → (gather corroborating evidence — Trade Ledger Reconciliation, Royal Seal Verification)
RESOLVE
  → (MQ27: confrontation, evidence-presentation mechanic)
```

**Design rule:** every major investigation thread in the game should be traceable through this exact chain shape — it's the mechanical backbone the Quest Bible's investigation-tagged quests should be checked against during production, not just a one-time illustrative example.

## 13. Failure States (system-wide principle)
Consistent with Doc 01 §14: investigation has no hard failure states. A missed clue narrows later dialogue/evidence options (as documented throughout Doc 07's quest specs) but never soft-locks main-quest completion — per the explicit edge-case requirement in Doc 01 §14, the main quest must remain completable on a reduced-context path.

---

## Open Questions
- Exact suspicion de-escalation timing (§3) needs playtesting tuning, not a fixed number here.
- Whether disguise-inconsistency detection (§4) should be a hard mechanical trigger or a soft narrative one (NPCs commenting but not immediately escalating) — leans soft-narrative for tonal consistency, but needs Game Designer confirmation.

## Dependencies on Other Documents
Doc 01 §13–14, Doc 06 (character skills), Doc 07 (quests exercising this system throughout, especially MQ19/20, SA04/07, HD03/08/11, SQ09), Doc 13 (NPC memory system this leans on heavily), Doc 34 (lighting affects visibility).

## Acceptance Criteria
- Full stealth system (visibility, sound, suspicion, disguise, social stealth) specified.
- Full investigation system (evidence gathering, tracking, interrogation, document discovery, inscription investigation, witness systems) specified.
- Worked investigation-chain example ties directly to an actual quest (MQ19), not a generic hypothetical.
- No hard investigation failure state, consistent with Doc 01.


---



<!-- ===== doc12_naval_design_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 12: NAVAL DESIGN BIBLE

**Document ID:** NDB-12 · **Version:** 1.0 · **Status:** Draft — ship construction specifics remain the largest evidence gap in the project (Doc 03 E4); this document is written to be honest about that gap rather than papering over it.
**Purpose:** Full maritime system specification.
**Dependencies:** Doc 03 (E1–E4), Doc 06 (Naval Commander, Merchant), Doc 07e (Naval Quests), Doc 10 §12 (naval combat cross-reference).

---

## 1. Ships

**Historical basis:** Doc 03 E3 confirms the Chola navy had genuine overseas projection capability (LIKELY–KNOWN); Doc 03 E4 confirms specific construction/design details are UNCERTAIN/UNKNOWN. Ship models in-game are therefore built from regional comparative shipbuilding tradition and general period maritime engineering principles, explicitly tagged [PLAUSIBLE RECONSTRUCTION] — and per NQ06 (Doc 07e), this gap is addressed directly in-fiction through the shipwright NPC rather than hidden.

**Ship classes (all fictionalized designs on a plausible-reconstruction basis):**
- **Coastal transport** — smaller, used for early/light naval traversal (per Doc 01 §16's recommendation that light naval traversal be available before Act 11).
- **Trade vessel** — cargo-capacity focused, central to Act 11 economy gameplay.
- **Naval Commander's vessel** — the player's primary Act 11 ship, balances cargo and combat capability.

## 2. Navigation
Star-Sight Navigation system (Production Bible v2 §2.6) as the core mechanic — celestial/coastal-silhouette based, no anachronistic compass-first UI. Land-based planning variant exists via NQ09 (tide/departure timing).

## 3. Wind & Weather
Wind direction affects travel speed/routing (a genuine navigation variable, not just flavor) — ties into NQ03's becalmed-ship quest and the Act 11 storm set-piece (MQ25). Weather forecasting is imperfect by design (period-appropriate uncertainty), creating genuine risk/reward routing decisions (per MQ25's fast-risky vs. safe-slow choice).

## 4. Cargo
Cargo capacity/type affects trade outcomes (Trade Ledger Reconciliation puzzle, Doc 07e NQ05/NQ08) — cargo is a narrative/economic variable (Doc 01 §22 economy principle: primarily observed/occasionally participated in) rather than a deep inventory-management minigame.

## 5. Ports
World Bible §4.7 (primary representative port) plus NQ07's second port — the network should read as genuinely plural per your "large-scale world design" pillar, not a single hub dressed up as a network.

## 6. Trade
Guild-based trade system (Doc 03 E1, Ainnurruvar context) — Merchant character and port NPCs are the primary trade-gameplay interface; mechanically expressed through Trade Ledger Reconciliation puzzles at increasing stakes (SQ01 → MQ19/24 → NQ05/08).

## 7. Crew
Named/semi-named crew NPCs under the Naval Commander, with the same memory/relationship principles as land NPCs (Doc 13) — NQ02 (crew welfare) is the primary system-establishing quest.

## 8. Morale
Not a numeric HUD meter (consistent with Doc 01 §23 reputation principle) — expressed through crew dialogue variation and quest-availability flavor (NQ02's outcome coloring NQ03's tone), not a bar the player watches.

## 9. Supplies
Shares the resource-management philosophy from Doc 01 §21/§25 — supply state affects narrative tension (NQ03) rather than being a separate hardcore survival-management system layered on top of the existing construction-zone resource system.

## 10. Diplomacy
Dialogue-tree based, reputation-tracked (NQ01/NQ05) — the Srivijaya-campaign distinction (Doc 03 A3) is explicitly threaded through here so the naval diplomacy content reinforces rather than contradicts the game's evidence-honesty pillar.

## 11. Sea Encounters
Grounded naval combat (Doc 10 §12) — raiders/pirates (NQ04), never fantastical threats (no sea monsters, no supernatural storms beyond real weather severity). Combat uses the same weapon kit as land combat (sword/spear/bow/dagger) in a boarding-action context.

## 12. Exploration
Coastal/open-water traversal unlocked progressively via the Imperial Map system (Doc 04 Act 10) — naval exploration should feel like an extension of the same world, not a separate minigame mode.

## 13. Navigation Puzzles
Star-Sight Navigation (core), plus PQ07's land-based astronomy variant and NQ09's tide-timing variant — three distinct instances of the same underlying historical-astronomy-and-calendar system (Doc 03, [PLAUSIBLE RECONSTRUCTION] tag), avoiding mechanical repetition while keeping thematic consistency.

---

## Open Questions
- Exact ship handling/physics model (arcade-accessible vs. more simulation-weighted) — Technical Director + Game Designer call, affects Doc 18 implementation scope significantly.
- Whether a third ship class is warranted, or the three above cover the design space adequately — defer to vertical-slice-adjacent naval prototype feedback.
- NQ06's shipwright dialogue should be reviewed against any updates to Doc 03 E4 before final voice-recording lock (Doc 22).

## Dependencies on Other Documents
Doc 03 (E1–E4, the central evidence constraint on this entire document), Doc 06 (Naval Commander/Merchant), Doc 07e (all naval quest content), Doc 10 §12 (combat), Doc 15 (Economy Bible — cargo/trade economic integration).

## Acceptance Criteria
- No ship design or naval capability claim exceeds Doc 03 E3/E4's actual confidence level.
- The E4 evidence gap is explicitly acknowledged in this document rather than smoothed over with confident-sounding but unsupported specification.
- Naval combat, morale, and cargo systems are shown to reuse rather than duplicate the game's existing combat/reputation/economy design philosophy.


---



<!-- ===== doc13_npc_ai_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 13: NPC & AI BIBLE

**Document ID:** NAI-13 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Living-world NPC system specification — the mechanical backbone of the "living city" pillar (Doc 01 Pillar 3) and the memory/relationship principle referenced throughout Docs 06, 07, and 11.
**Dependencies:** Doc 01 §17/§25, Doc 18 (Mass Entity as the underlying tech), Doc 03 F3 (evidence caveat on ordinary daily life).

---

## 1. NPC Data Model (per-NPC attributes)

Every named or semi-named NPC carries:
- **Name, Occupation, Faction** (Doc 14 cross-reference)
- **Schedule** — a daily-cycle routine (§3)
- **Location** — current position, resolved by schedule + world-state
- **Relationships** — disposition toward Arulan and toward other NPCs (feeds dialogue tone and quest availability)
- **Memory** — a bounded set of remembered player actions (see §4 — bounded deliberately, not infinite, for both design clarity and technical cost reasons)
- **Reputation** — how this NPC's faction/social circle regards Arulan (aggregated from Doc 01 §23's non-numeric reputation principle)
- **Economic status** — coarse tier (subsistence / stable / prosperous), affects dialogue flavor and what goods/services they can offer
- **Knowledge** — what this NPC knows that's relevant to investigation threads (ties directly to Doc 11 §11 witness system)
- **Dialogue state** — current branch/flag state in their dialogue tree

**Historical caveat (per Doc 03 F3):** ordinary-NPC daily-life specifics (diet, exact social behaviors) are built on general regional/period scholarship, not site-specific attested evidence — the Codex should never imply a specific NPC's routine is documented fact.

## 2. Population Tiers

To manage the tension between the living-world pillar and technical/production cost (flagged as an open risk in Doc 01 §25 and §34):
- **Tier 1 — Named characters** (Doc 06's 10, plus quest-specific NPCs like the Artisan's apprentice, the sculptor, site officials): full data model above, hand-authored schedules and dialogue.
- **Tier 2 — Semi-named recurring NPCs** (guild representatives, specific workers referenced across multiple quests): full data model, but schedule/dialogue generated from templates rather than fully hand-authored.
- **Tier 3 — Background population** (market crowds, generic workers, soldiers): Mass Entity-driven, schedule-only, no individual memory/relationship tracking, contributes to the world's density and ambient barks without per-NPC authored content.

This tiering is what makes the living-world pillar achievable at production scale — recommend treating it as a hard architectural decision, not a fallback.

## 3. Daily Cycle

- **Morning:** markets open, workers arrive at construction zone, temple morning activity.
- **Afternoon:** peak craft/trade activity, administrative work at site office.
- **Evening:** temple activity increases, markets wind down, social gathering begins.
- **Night:** guards posted, lanterns lit, private conversations become available (investigation-relevant — some witness NPCs are only approachable at night, per Doc 11 §11), most Tier 3 population sleeps/thins out.

Schedule shifts with season/weather (Doc 01 §25) — wet season reduces outdoor activity, dry season increases construction-zone activity.

## 4. Memory System

**Design principle:** memory is meaningful but bounded — each Tier 1/2 NPC remembers a small number of *significant* player interactions (quest outcomes, major dialogue choices affecting them directly), not a full transcript log. This keeps the system both technically tractable and dramatically legible (per your original "a merchant remembers whether the player helped him" example).

**Worked example (Merchant, per your brief):**
- Player helps the Merchant resolve SQ01's guild dispute in the Merchant's favor → Merchant's memory flag `sq01_sided_merchant = true` → later dialogue in NQ05 references this specifically ("You're the one who spoke up for me with the guild.") → NQ05's negotiation opens with slightly better starting terms.

**Worked example (Guard):**
- Player is caught trespassing once but talks their way out → Guard's memory flag `arulan_suspicious = true` → subsequent encounters with that specific guard have a reduced trust baseline, without escalating to permanent hostility (consistent with the non-punitive failure philosophy in Doc 11 §3).

**Worked example (Scholar):**
- Scholar remembers every SA-series choice (Doc 07f) — this is the one character whose memory system is closest to a full relationship-arc tracker rather than a handful of flags, reflecting their central narrative role.

## 5. AI Behaviors

Standard behavior set per Tier: Work, Trade, Travel, Eat, Socialize, Worship, Guard, Sleep — driven by the daily-cycle schedule (§3) via Mass Entity behavior trees (Doc 18).

**React to player:** proximity/action-based reactions (greeting, suspicion per Doc 11 §3, market NPCs offering goods) — Tier 1/2 reactions reference memory state; Tier 3 reactions are generic/ambient.

**React to events:** world-state changes (construction milestones, weather, the conspiracy thread becoming public knowledge post-MQ27) should visibly ripple through NPC dialogue/behavior — e.g., after MQ27 resolves, site workers' ambient dialogue should reflect whichever resolution occurred, reinforcing that player choices actually landed (ties to the "world revisited late-game must reflect current world-state" edge case flagged in Doc 01 §25).

## 6. Faction AI
See Doc 14 for full faction definitions. At the NPC-AI level: an NPC's faction membership modulates their default disposition toward Arulan (a temple-affiliated NPC starts more favorably disposed if Arulan has done well by temple-related quests like SQ11/HD09) and gates which Tier 1/2 NPCs will share investigation-relevant knowledge without a trust-building quest first (per SQ09's model).

---

## Open Questions
- Exact bounded-memory size (how many flags per NPC) needs a technical budget decision from Doc 18 — this document specifies the principle, not the number.
- Whether Tier 2 NPCs should have any procedurally-generated dialogue variation beyond templates, or remain fully templated — Technical Artist/AI Programmer call.

## Dependencies on Other Documents
Doc 01 §17/§25, Doc 03 F3 (evidence caveat), Doc 06 (Tier 1 NPCs), Doc 07 (quests that set memory flags — extensive cross-references throughout, especially SQ01/09, MQ13/19/27, SA-series), Doc 14 (factions), Doc 18 (Mass Entity implementation).

## Acceptance Criteria
- Full NPC data model, daily cycle, memory system, and AI behavior set specified.
- Population tiering explicitly reconciles the living-world pillar with production/technical feasibility (addresses the Doc 01 §25/§34 open risk directly).
- Memory system worked examples trace to actual quests already specified in Doc 07, not hypothetical placeholder content.


---



<!-- ===== doc14_faction_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 14: FACTION BIBLE

**Document ID:** FB-14 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full specification of the game's ten factions.
**Dependencies:** Doc 03 (F1–F2, E1), Doc 06 (Antagonist/Political Rival as faction-adjacent figures), Doc 13 (faction AI modulation).
**Critical rule carried through every entry:** categories with real historical basis (Royal Administration, Military, Temple Institutions, Merchants, Farmers, Naval groups, Foreign Traders) are [DOCUMENTED] as general institutional categories — specific in-game faction leadership, internal politics, and named goals are [FICTIONAL] dramatization layered on top. The two explicitly political factions (Overreach Concern faction, Court Advancement faction) are entirely [FICTIONAL] and must never be Codex-logged as documented historical organizations.

---

## 1. ROYAL ADMINISTRATION
- **Historical status:** [DOCUMENTED] general category (Doc 03 F1)
- **Ideology:** imperial continuity and consolidation
- **Goals:** successful completion of the new capital, stable succession of authority
- **Resources:** state treasury, labor levy, military backing
- **Leadership:** Rajendra Chola I (historical, dramatized)
- **Relationships:** nominally authoritative over all other factions; increasingly strained with the Overreach Concern faction across the story
- **Territories:** the whole Chola state, nominally
- **Reputation:** default respectful/deferential from most NPCs, per period administrative culture
- **Quest types:** court quests (MQ03/04/10), decree-related content
- **Conflict:** internal — how much dissent it can absorb before administrative strain becomes crisis (the story's central political question)
- **Dialogue:** formal register
- **Visual identity:** restrained gold-accent regalia per Art Direction principle

## 2. MILITARY
- **Historical status:** [DOCUMENTED] general category (Doc 03 A3, I2)
- **Ideology:** service to the crown, campaign discipline
- **Goals:** successful campaign execution, garrison duty at the new capital
- **Resources:** soldiers, cavalry/elephants (Doc 03 I2), logistics infrastructure
- **Leadership:** campaign officers (fictional individuals within a documented institutional category)
- **Relationships:** subordinate to Royal Administration; the rival officer of MQ06 represents internal dissent within this faction specifically
- **Territories:** campaign corridor, capital garrison
- **Reputation:** respected but not uncritically — MQ06 establishes that soldiers themselves can hold the overreach concern
- **Quest types:** Act 3 campaign quests, MQ20 ambush response
- **Conflict:** logistics strain, the overreach question voiced from within
- **Dialogue:** blunt, practical
- **Visual identity:** practical campaign gear, distinct from ceremonial court dress

## 3. TEMPLE INSTITUTIONS
- **Historical status:** [DOCUMENTED] (Doc 03 F2)
- **Ideology:** religious/civic continuity through monumental building and endowment
- **Goals:** successful temple construction and consecration, land-grant administration
- **Resources:** temple land grants, craft labor, donations
- **Leadership:** temple officials (fictional individuals within a documented institutional category)
- **Relationships:** closely tied to the Architect and craft factions; land-grant disputes (SQ11) show friction with local administration
- **Territories:** temple precincts (Thanjavur, Gangaikondacholapuram)
- **Reputation:** high — central to civic identity per Doc 03 F2
- **Quest types:** SQ11, HD09, Act 7 temple-construction content
- **Conflict:** administrative disputes over grant/resource allocation
- **Dialogue:** formal, occasionally ceremonial register
- **Visual identity:** temple official dress, distinct from both court and craft dress

## 4. MERCHANTS (Guild Network)
- **Historical status:** [DOCUMENTED] (Doc 03 E1)
- **Ideology:** trade network stability and guild reciprocity
- **Goals:** protect trade routes and guild reputation, expand into new markets (NQ05/07)
- **Resources:** capital, trade goods, information networks
- **Leadership:** guild representatives (fictional individuals, Ainnurruvar-style institutional category)
- **Relationships:** transactional with Royal Administration (taxes/dues, SQ01), increasingly entangled with the conspiracy thread via trade-ledger evidence (MQ24)
- **Territories:** market zones, ports
- **Reputation:** pragmatic, networked — "remembers whether you helped"
- **Quest types:** SQ01–03, NQ01/05/08
- **Conflict:** internal guild disputes (SQ01), external pressure from conspiracy-linked irregularities
- **Dialogue:** persuasive, transactional
- **Visual identity:** prosperous-but-restrained dress (Doc 06 §6)

## 5. ARTISANS (Craft Guilds)
- **Historical status:** [DOCUMENTED] (Doc 03 G1–G2)
- **Ideology:** craft integrity and mastery
- **Goals:** complete commissioned work to a high standard despite deadline pressure
- **Resources:** skilled labor, workshops, materials
- **Leadership:** senior craftspeople (the Artisan character, Doc 06 §7, as a representative figure)
- **Relationships:** closely tied to Temple Institutions and the Architect; MQ15's sculptor's-doubt thread shows internal tension over quality-vs-deadline
- **Territories:** workshops, construction zone
- **Reputation:** widely respected — grounding, non-political presence in the world
- **Quest types:** SQ04–06, MQ14–15
- **Conflict:** quality vs. schedule pressure (echoes the larger overextension theme at human scale)
- **Dialogue:** plain-spoken, technical
- **Visual identity:** practical craft dress, tool-marked

## 6. FARMERS
- **Historical status:** [DOCUMENTED] general agricultural base of the delta economy (World Bible §2)
- **Ideology:** subsistence and seasonal continuity
- **Goals:** successful harvests, reliable water access
- **Resources:** land, seasonal labor
- **Leadership:** no single figure — village assembly structures per Doc 03 F1
- **Relationships:** dependent on water-infrastructure decisions (SQ13 flood quest ties directly here)
- **Territories:** agricultural land surrounding the capital
- **Reputation:** largely outside the political conspiracy, a grounding presence like the Artisans
- **Quest types:** SQ13, HD05
- **Conflict:** seasonal/environmental (flooding), minor administrative friction (village assembly content)
- **Dialogue:** plain, practical
- **Visual identity:** simple, practical agricultural dress

## 7. SCHOLARS
- **Historical status:** [DOCUMENTED] general scribal/epigraphic professional category (Doc 03 H1–H2)
- **Ideology:** rigor, preservation of the record
- **Goals:** accurate documentation, resisting distortion of the historical record
- **Resources:** archive access, literacy/epigraphic expertise
- **Leadership:** the Scholar character (Doc 06 §3) as representative figure
- **Relationships:** increasingly central to the conspiracy resolution (Doc 07f's full arc)
- **Territories:** archives, inscription sites
- **Reputation:** trusted but institutionally cautious by default
- **Quest types:** the entire SA-series (Doc 07f), HD-series (Doc 07c)
- **Conflict:** institutional caution vs. the moral pull to expose wrongdoing — this faction's central conflict is Doc 06/07f's Scholar arc writ at faction scale
- **Dialogue:** precise, teacherly
- **Visual identity:** scholarly/administrative dress, fieldwork-weathered

## 8. NAVAL GROUPS
- **Historical status:** [DOCUMENTED] (Doc 03 E3)
- **Ideology:** operational pragmatism, crew loyalty over abstract politics
- **Goals:** safe, profitable voyages; protecting the trade network
- **Resources:** ships, crew, navigational knowledge
- **Leadership:** the Naval Commander (Doc 06 §5)
- **Relationships:** professionally respectful of Merchants, wary of court politics reaching the fleet (per Doc 06 §5)
- **Territories:** ports, open water
- **Reputation:** weathered, competent
- **Quest types:** NQ-series (Doc 07e)
- **Conflict:** external (weather, piracy) more than internal politics
- **Dialogue:** blunt, dry
- **Visual identity:** maritime-practical dress

## 9. FOREIGN TRADERS
- **Historical status:** [DOCUMENTED] (Doc 03 E2)
- **Ideology:** varies by origin polity — treated with individual specificity rather than a monolithic "foreigner" characterization, per Cultural Sensitivity Consultant guidance
- **Goals:** favorable trade terms, safe passage
- **Resources:** foreign goods, diplomatic standing
- **Leadership:** individual envoys/traders (e.g., NQ01's envoy) rather than a single faction leader
- **Relationships:** diplomatic, mediated through the Naval Commander/Merchant
- **Territories:** ports, diplomatic quarters
- **Reputation:** respect contingent on how Act 11 diplomacy is handled
- **Quest types:** NQ01/05, SQ03
- **Conflict:** none inherent — conflict only arises from how the player/administration handles diplomacy
- **Dialogue:** varies genuinely by individual/origin, not a single "exotic foreigner" register
- **Visual identity:** origin-appropriate dress, researched per polity rather than generic "foreign" markers

## 10. POLITICAL FACTIONS (entirely fictional — two sub-factions)

### 10a. The Overreach Concern (Antagonist's faction)
- **Historical status:** [FICTIONAL] — must never be Codex-logged as a documented historical organization
- **Ideology:** genuine belief the empire is expanding beyond sustainable administration (Doc 06 §8)
- **Goals:** slow/reform imperial expansion, expose administrative strain
- **Resources:** insider administrative knowledge, some military/officer sympathy (MQ06)
- **Leadership:** the Antagonist
- **Relationships:** uneasy alliance-of-convenience with 10b; adversarial with Royal Administration and (once the conspiracy surfaces) Arulan/Scholar
- **Territories:** none formal — an ideological current within existing institutions, not a separate territorial power
- **Reputation:** genuinely contested — the game should not resolve whether this faction's underlying critique was right
- **Quest types:** MQ13/19/27, MQ06
- **Conflict:** conviction compromised by increasingly ethically fraught methods
- **Dialogue:** measured, persuasive
- **Visual identity:** understated senior-official dress, no villain-coding

### 10b. Court Advancement (Political Rival's faction)
- **Historical status:** [FICTIONAL]
- **Ideology:** personal advancement dressed in loyalty rhetoric
- **Goals:** the Rival's own rise, using the overreach debate opportunistically
- **Resources:** court connections, rhetoric
- **Leadership:** the Political Rival
- **Relationships:** convenience-alliance with 10a; the two factions' relationship should visibly strain as the story progresses, since 10a's conviction and 10b's opportunism are fundamentally different motivations (Doc 06 design note)
- **Territories:** court, none formal beyond that
- **Reputation:** polished but untrustworthy on close examination
- **Quest types:** MQ21/22
- **Conflict:** self-interest masquerading as principle — the deliberate foil to 10a
- **Dialogue:** smooth, subtly self-serving
- **Visual identity:** sharper, more overtly ambitious court dress than the Antagonist's restraint

---

## Open Questions
- Whether 10a and 10b should have a scripted falling-out scene once their alliance-of-convenience strains (per the relationship note above) — Narrative Director/Quest Designer decision, would be a good addition to the Act 12 quest set.
- Foreign Traders (#9): which specific origin polities to research and represent needs a dedicated Historical Research Director + Cultural Sensitivity Consultant pass before art/dialogue production, per Doc 03 E2's documented China/Southeast Asia contact.

## Dependencies on Other Documents
Doc 03 (evidence basis for documented factions), Doc 06 (Antagonist/Rival/Scholar/Naval Commander/Merchant as faction representatives), Doc 13 (faction AI modulation), Doc 07 (quest cross-references throughout).

## Acceptance Criteria
- All 10 factions (documented categories + 2 fictional political factions) fully specified.
- Fictional factions (10a/10b) never presented as documented historical organizations.
- The Antagonist's faction (10a) remains genuinely distinct in motivation from the Rival's faction (10b), consistent with Doc 06's design requirement.


---



<!-- ===== doc15_economy_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 15: ECONOMY BIBLE

**Document ID:** EB-15 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full economy system specification.
**Dependencies:** Doc 01 §21–22 (crafting/economy principles: observed more than played, no arbitrary RPG systems), Doc 03 (D3, E1, F2, G1), Doc 14 (Merchants/Artisans/Farmers/Temple factions).
**Core design constraint carried throughout:** per Doc 01, economy is primarily a **narrative and world-simulation layer** the player observes and occasionally participates in — not a deep trading/crafting minigame. Every system below is scoped to that constraint.

---

## 1. Resources

| Resource | Role | Historical basis |
|---|---|---|
| Grain/Food | Baseline subsistence resource, visible in construction-zone logistics (Act 6) and campaign logistics (Act 3) | [DOCUMENTED] delta agricultural base |
| Stone | Primary construction resource, central to Stone Alignment puzzle chain | [DOCUMENTED] (Doc 03 C2, G2) |
| Timber | Secondary construction resource, scaffolding/tooling | [PLAUSIBLE RECONSTRUCTION] general use |
| Metal | Tools, weapons (Doc 10), bronze-casting input | [DOCUMENTED] (Doc 03 G1) |
| Textiles | Trade good, clothing production (flavor-level) | [PLAUSIBLE RECONSTRUCTION] |
| Bronze | Artisan craft output, temple donation items | [DOCUMENTED] (Doc 03 G1) |
| Tools | Craft/construction enabler | [PLAUSIBLE RECONSTRUCTION] |
| Trade goods (general) | Port/maritime economy driver | [DOCUMENTED] general trade network (Doc 03 E1) |

## 2. Markets
Represented as living-world set-dressing (Doc 13 daily cycle — markets open Morning, peak Afternoon, wind down Evening) with light player interaction (buying flavor/quest items, no deep inventory-management shopping system) — consistent with Doc 01 §20's inventory-as-narrative-tool principle.

## 3. Prices
Abstracted — prices shift narratively (a shortage referenced in dialogue, a good harvest reflected in market abundance) rather than through a simulated numeric supply/demand curve the player must optimize against. This avoids importing a modern trading-game economic layer the brief explicitly warns against.

## 4. Supply & Demand
Modeled narratively at the *system* level (construction-zone resource shortages driving MQ12, campaign supply driving Act 3) rather than as a player-facing numeric economy the player actively arbitrages — per the "avoid modern economic concepts unless abstracted for gameplay" instruction.

## 5. Trade Routes
World Bible §3 (route network) plus the port network (§4.7, NQ07) — trade routes are primarily a narrative/exploration structure (where can Arulan travel, what does that unlock) rather than a route-optimization economic puzzle, though the Trade Ledger Reconciliation puzzle (Production Bible v2 §2.5) gives players one concrete, bounded mechanical expression of trade-economy engagement.

## 6. Craftsmanship
The Artisan's bronze-casting (HD07/HD10) and the Architect's stone construction (Stone Alignment puzzle chain) are the game's two fully-realized craft-economy expressions — deliberately deep in these two areas rather than shallow across many, consistent with quality-over-breadth design throughout this project.

## 7. Merchant Guild Systems
Ainnurruvar-style guild structure (Doc 03 E1) expressed through the Merchant character, SQ01's dues dispute, and the full NQ-series trade content — guild reputation is tracked narratively (Doc 13 memory system), not as a numeric faction-standing meter.

## 8. Construction Resources
The most mechanically deep economic system in the game, per Doc 01 §25/Act 6: stone/timber/metal/food/water/labor/transport/tools flow visibly into the construction-zone's progressing world-state (per Doc 13 §5's "world reflects choices" principle) — this is where "economy" earns actual gameplay weight, everywhere else in this document is comparatively light-touch by design.

---

## Open Questions
- Exact resource-flow visualization (how the player sees construction progress tied to resources) needs a UI/UX pass (Doc 20) and Technical Design input (Doc 18) on how world-state art assets respond to resource thresholds.
- Whether SQ02's caravan-escort resource delivery should have any numeric player-facing economy beyond flavor — leans no, for consistency, but Game Designer should confirm.

## Dependencies on Other Documents
Doc 01 §21–22, Doc 03 (evidence basis per resource), Doc 13 (market/NPC daily cycle), Doc 14 (Merchant/Artisan/Farmer/Temple factions), Production Bible v2 §2.5 (Trade Ledger puzzle).

## Acceptance Criteria
- No modern economic simulation layer (numeric supply/demand curves, player-optimized trading) introduced without explicit gameplay abstraction justification.
- Construction-zone resource management confirmed as the one area of genuine mechanical depth, consistent with Doc 01's design philosophy.
- Every resource traced to a historical basis tag.


---



<!-- ===== doc16_architecture_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 16: ARCHITECTURE BIBLE

**Document ID:** AB-16 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full architectural reference for every built-environment category in the game.
**Dependencies:** Doc 03 (C1–C3, D1, G2), Doc 02 (World Bible locations), Art Direction Guide (Production Bible v2 §3).

---

## 1. BRIHADISVARA TEMPLE, GANGAIKONDACHOLAPURAM (dedicated section, per your explicit requirement)
- **Historical reference:** [DOCUMENTED] — Doc 03 C2–C3; ASI architectural survey and UNESCO "Great Living Chola Temples" documentation are the primary reference sources. Architecturally related to but distinct from Rajaraja I's Thanjavur temple (Doc 03 C3) — this distinction should be visually legible in-game (HD01), not just stated in the Codex.
- **Geometry:** Dravidian vimana form — stepped pyramidal tower over the sanctum, distinct proportions from the taller, more vertically dominant Thanjavur tower (per real scholarly comparison of the two structures).
- **Materials:** granite construction, consistent with Art Direction's material palette (Production Bible v2 §3).
- **Scale:** large but proportioned differently from Thanjavur — the in-game model should not simply be a resized copy of the Thanjavur temple asset; distinct massing per the real architectural relationship.
- **Construction method:** load-bearing stone-on-stone technique (Doc 03 G2), directly embodied in the Stone Alignment puzzle system (Production Bible v2 §2.1) — the puzzle mechanics and the final building's structural logic should visibly correspond.
- **Texture:** worked granite, weathering variation between older (lower, earlier-built) and newer (upper, later-built) courses during the Act 7–9 construction period — a subtle but real visual cue reinforcing the "under construction" state.
- **Lighting:** per Art Direction's motivated-light doctrine — interior sanctum lit primarily by oil lamps/torches even after completion; exterior catches full sun with the gold-as-material-accent principle applied specifically to finished bronze temple fittings, not the stone itself.
- **Environmental storytelling:** incomplete upper courses, visible scaffolding, and stone dust throughout most of the game (Art Direction "scale storytelling" principle) — the completed state (Act 12) should be visually striking specifically because the player has watched every course go up.

## 2. TEMPLE ARCHITECTURE (general category, Thanjavur + other temple sites)
- **Historical reference:** [DOCUMENTED] (Doc 03 A1, C3)
- **Geometry:** Dravidian vimana/gopura forms generally
- **Materials:** granite
- **Scale:** varies by site — Thanjavur's temple should read as taller/more vertically dominant per real comparative scholarship, establishing visual contrast with Gangaikondacholapuram's temple before the player ever reads a Codex entry about it
- **Construction method:** as §1
- **Texture:** fully weathered/settled (Thanjavur is complete and established at game start, unlike the new capital's temple)
- **Lighting:** established, ceremonial lighting — contrasts with Gangaikondacholapuram's construction-lit environment
- **Environmental storytelling:** Thanjavur's temple functions as the "finished, inherited" counterpoint to the player's construction-zone experience throughout the game (per World Bible §4.1)

## 3. ROYAL ARCHITECTURE
- **Historical reference:** [PLAUSIBLE RECONSTRUCTION] specific layout; [DOCUMENTED] general administrative function (Doc 03 F1)
- **Geometry:** formal courtyard-based layout, restrained ornamentation
- **Materials:** stone with wood elements, textile furnishings
- **Scale:** large but not monumentally taller than temple architecture — per Art Direction restraint, royal architecture should not visually compete with or exceed the temple's symbolic centrality
- **Construction method:** conventional period construction, not the specialized load-bearing temple technique
- **Texture:** formal, maintained
- **Lighting:** filtered courtyard light, oil-lamp interior lighting for evening court scenes
- **Environmental storytelling:** maps/campaign preparation visible in Act 2 before being explained (per World Bible §4.2)

## 4. RESIDENTIAL ARCHITECTURE
- **Historical reference:** [UNCERTAIN/UNKNOWN] specific non-monumental layout (Doc 03 C4) — explicitly [FICTIONAL] extrapolation
- **Geometry:** varies by economic tier (Doc 15 §1) — simple structures for worker settlement, more elaborate for merchant/official housing
- **Materials:** timber, thatch, mudbrick for common housing; stone elements for wealthier residences
- **Scale:** human-scale, modest
- **Construction method:** conventional, non-monumental
- **Texture:** lived-in, varied by economic tier
- **Lighting:** oil lamps, cooking-fire light in the evening/night cycle
- **Environmental storytelling:** primary carrier of the living-city NPC-density pillar (Doc 13) — should read as genuinely inhabited, not stage-dressing

## 5. MARKETS
- **Historical reference:** [DOCUMENTED] general economic activity (Doc 03 E1, F2)
- **Geometry:** open-air stall layout, central to settlement design
- **Materials:** timber stalls, textile awnings
- **Scale:** scales with settlement size — larger at the port (World Bible §4.7) than at the construction-zone worker settlement
- **Construction method:** temporary/semi-permanent structures
- **Texture:** busy, goods-laden
- **Lighting:** full daylight during peak hours, lantern-lit for any evening activity
- **Environmental storytelling:** the Doc 15 economy system's primary visual expression

## 6. WATER SYSTEMS
- **Historical reference:** [DOCUMENTED] reservoir existence, [PLAUSIBLE RECONSTRUCTION] specific mechanism (Doc 03 D1, D3)
- **Geometry:** reservoir, canal network, sluice-gate structures (Lion Well puzzle geometry, Production Bible v2 §2.2)
- **Materials:** stone channel construction
- **Scale:** the reservoir is a major landmark-scale structure, canals scale down to human-scale detail work
- **Construction method:** as documented general practice (Doc 03 D3)
- **Texture:** wet stone, algae/mineral staining variation by channel age
- **Lighting:** open-sky reflection on water surfaces, important for the Lion Well puzzle's visual legibility
- **Environmental storytelling:** central to Act 8's thematic payoff of the Act 4 Ganga cinematic (Doc 04 Act 8 design note)

## 7. ROADS
- **Historical reference:** [DOCUMENTED] general route network existence (World Bible §3)
- **Geometry:** vary from major administrative roads to informal paths
- **Materials:** packed earth, some stone paving near major sites
- **Scale:** connects all major World Bible locations
- **Construction method:** conventional period road-building
- **Texture:** worn, cart-rutted near high-traffic areas (supports Doc 11 §7 tracking mechanic)
- **Lighting:** exterior, full weather/time-of-day variation
- **Environmental storytelling:** road condition/traffic density signals settlement importance without needing UI labels

## 8. WORKSHOPS
- **Historical reference:** [DOCUMENTED] craft context (Doc 03 G1–G2)
- **Geometry:** open-sided or partially enclosed working spaces
- **Materials:** timber structure, stone forge/kiln elements for bronze-casting workshops specifically
- **Scale:** human-scale, craft-appropriate
- **Construction method:** conventional
- **Texture:** tool-worn, material-stained (stone dust near sculptors, soot near bronze casters)
- **Lighting:** forge-fire glow for bronze workshops (per Cinematic 002 Shot 003's established look), natural light for stone-working
- **Environmental storytelling:** primary setting for HD07/HD10 and SQ04–06

## 9. MILITARY STRUCTURES
- **Historical reference:** [DOCUMENTED] general capability (Doc 03 A3, I2), [PLAUSIBLE RECONSTRUCTION] specific structures
- **Geometry:** temporary campaign camps (Act 3), garrison structures at the capital
- **Materials:** timber/canvas for campaign camps, stone/timber for permanent garrison
- **Scale:** campaign camps are sprawling but temporary; garrison structures are modest relative to temple/royal architecture (per Art Direction restraint — military structures should not visually dominate)
- **Construction method:** rapid/temporary for campaign, conventional for permanent
- **Texture:** functional, weathered by campaign conditions
- **Lighting:** campfire-lit at night for Act 3 camps
- **Environmental storytelling:** Act 3's logistics-driven design (Doc 01 §12) should be visible in camp layout — supply stores, muster areas, not just tents

## 10. PORTS
- **Historical reference:** [DOCUMENTED] general network (Doc 03 E1–E3)
- **Geometry:** working harbor layout — docks, cargo storage, guild offices, diplomatic quarter (NQ01)
- **Materials:** timber dock construction, stone harbor elements
- **Scale:** the primary port (World Bible §4.7) is a major hub; the second port (NQ07) is deliberately smaller
- **Construction method:** conventional maritime construction
- **Texture:** salt-worn, cargo-laden, weathered by sea exposure
- **Lighting:** bright open harbor light, contrasted with the diplomatic quarter's more formal interior lighting
- **Environmental storytelling:** foreign goods/visitors read as evidence of the documented trade network (World Bible §4.7 principle), not generic "exotic bazaar" dressing

---

## Open Questions
- Residential architecture (§4) carries the highest historical uncertainty of any category — recommend the Historical Authenticity Consultant specifically review this section before asset production, since it's also the highest-volume asset category (living-city density).
- Whether military structures (§9) need more detail for the Act 3 campaign-camp sequence specifically — may warrant a short dedicated addendum once Level Design blocks out that Act.

## Dependencies on Other Documents
Doc 02 (World Bible location context), Doc 03 (evidence basis per category), Production Bible v2 §3 (Art Direction principles this document applies), Doc 29 (Environment Production Bible — production zone breakdown).

## Acceptance Criteria
- All 10 categories specified with all 8 required fields.
- Brihadisvara Temple receives its dedicated section, distinguished architecturally (not just narratively) from the Thanjavur temple.
- Every category's historical reference tag is consistent with its Doc 03 evidence basis, with residential architecture's higher uncertainty explicitly flagged rather than smoothed over.


---



<!-- ===== doc17_art_direction_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 17: ART DIRECTION BIBLE

**Document ID:** ADB-17 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Complete visual-identity specification. Consolidates and expands Production Bible v2 §3 and Doc 16 rather than duplicating them — cross-referenced below.
**Dependencies:** Production Bible v2 §3 (base Art Direction principles, carried forward unchanged), Doc 16 (Architecture — full detail lives there), Doc 03 (G3 caveat on stylized sculptural sources), Doc 06 (character appearance fields).
**Visual goal, restated:** AAA historical realism. No generic fantasy architecture or costuming. Every visual decision should be defensible against a real reference, or explicitly flagged as a fictionalized extrapolation.

---

## 1. Character Art
Builds on Doc 06's per-character appearance/clothing fields. Core principle: designed from period sculpture and relief conventions, with the explicit caveat (Doc 03 G3) that sculptural sources are stylized and idealized, not photographic — Character Artists should treat sculpture as a style reference, not a literal documentary source, and should cross-check against comparative regional material-culture scholarship where available. Status differentiation (royal/court/craft/farmer/foreign) should read primarily through material quality and silhouette, not through exaggerated "fantasy class" visual coding.

## 2. Environment Art
Governed by Doc 16 (full per-category architectural detail) and the World Bible (Doc 02) location catalog. This document's role: confirm that environment art direction distinguishes "finished, established" spaces (Thanjavur) from "under construction" spaces (Gangaikondacholapuram through Act 11) as a *primary* visual language, not a secondary detail — this distinction should be legible from a single establishing shot of either location.

## 3. Materials
Per Production Bible v2 §3: granite grey/rose, weathered bronze-green patina vs. bright new-cast bronze (a deliberate, consistent in-world signal distinguishing "old" from "recently made" objects across every asset category — props, jewelry, temple fittings alike), unbleached cotton/silk textiles, terracotta. This material language should be applied consistently enough that a player can learn to "read" object age/origin without a UI label.

## 4. Textures
Weathering variation is a storytelling tool, not just a realism checkbox — per Doc 16 §1, the temple's lower/older construction courses should be texturally distinguishable from upper/newer courses during the Act 7–9 build period.

## 5. Lighting
Per Production Bible v2 §3's motivated-light doctrine: every light source justified in-world. Extended specifically for Act 4 (Doc 05 Cinematic 003): flat, unglamorous overcast lighting is itself a deliberate art-direction choice at the game's most important emotional beat, not a lighting failure to be "fixed" with dramatic backlighting.

## 6. Weather
Monsoon-seasonal system (World Bible §2) drives both gameplay pacing (Doc 01 §25) and visual variety — wet-season environments (rain-slicked stone, flooded paddy fields per SQ13, muted palette) vs. dry-season (dust, harsher shadow, active-construction visual energy) should be art-directed as genuinely distinct moods, not a simple particle-effect toggle.

## 7. Vegetation
Delta agricultural vegetation (rice paddy, palm) for the Chola heartland; denser forest/transitional vegetation for the northern corridor (World Bible §4.3) and representative wilderness zone (§4.8) — vegetation should be a primary tool for signaling "we have left the heartland" during Act 3, reinforcing the geographic/tonal shift without relying on UI region labels.

## 8. Architecture
Full detail in Doc 16 — this document's contribution is the cross-cutting rule: **gold is a material accent, never an ambient color wash** (Production Bible v2 §3), applied consistently across every architecture category so the game visually distances itself from generic "ancient India = everything gold" fantasy aesthetics, per your explicit direction.

## 9. Props
Prop density and dressing should reinforce the living-world pillar (Doc 13) — construction-zone props (tools, partially-worked stone, scaffolding materials) should visibly accumulate/change as Acts 6–9 progress, giving players a prop-level read on world-state alongside the larger architectural progression. Full prop-by-prop production list is Doc 30's responsibility; this document sets the direction: props should look *used*, not staged.

## 10. Weapons
Cross-reference Doc 10 §2 — visual design follows the same [PLAUSIBLE RECONSTRUCTION] evidence basis (Doc 03 I1), built from sculptural/comparative-regional reference rather than invented fantasy weapon silhouettes. No exotic ornamentation implying magical properties.

## 11. Clothing
Per-character detail in Doc 06; general principle: clothing is the primary and most reliable visual signal of social/economic tier (Doc 15 §1's economic tiers) and occupation (Doc 13's faction/occupation data), researched from sculptural and comparative regional textile-history sources, reviewed by the Cultural Sensitivity Consultant before final lock — this is one of the highest cultural-sensitivity-risk asset categories in the whole project and should not be finalized without that review.

## 12. Jewelry
Status-signaling detail, concentrated on royal/court/temple/merchant characters per Doc 06; deliberately restrained on common/craft/farmer characters, consistent with realistic economic-tier differentiation rather than uniformly ornamented "exotic" costuming.

## 13. UI
Full detail in Doc 20/Production Bible v2 §5. This document's contribution: UI visual language should borrow directly from the material palette (§3) — stone/bronze-inspired frame elements, restrained gold accents on Codex confidence-tier borders — so the interface feels continuous with the world rather than a modern overlay bolted onto a historical setting.

---

## Open Questions
- Clothing (§11) is the category most in need of dedicated Cultural Sensitivity Consultant time before any asset production begins — recommend scheduling this review before Doc 31 (Character Art Bible) locks, not after.
- Whether prop-level world-state changes (§9) are technically feasible at the granularity described, given the World Partition streaming approach (Doc 18) — needs an early technical spike.

## Dependencies on Other Documents
Production Bible v2 §3 (base principles, unchanged), Doc 03 (G3 caveat), Doc 06 (character appearance), Doc 10 §2 (weapons), Doc 13 (living-world prop/NPC density), Doc 16 (full architectural detail), Doc 20 (UI detail).

## Acceptance Criteria
- All 13 categories specified, each either extending a prior document (cross-referenced, not duplicated) or adding genuinely new direction.
- The "finished vs. under construction" visual distinction and the "gold as accent not wash" rule are confirmed as cross-cutting principles applied consistently across every relevant category.
- Clothing flagged as requiring Cultural Sensitivity Consultant review prior to asset production.


---



<!-- ===== doc18_technical_design_document.md ===== -->

# GANGAIKONDA — DOCUMENT 18: TECHNICAL DESIGN DOCUMENT

**Document ID:** TDD-18 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full engineering architecture specification, expanding Production Bible v2 §6.
**Dependencies:** Doc 01 (all system requirements), Doc 13 (NPC/AI — Mass Entity requirements), Doc 36 (Save/Load — referenced, detailed here as the authoritative source).
**Engine:** Unreal Engine 5. **Multiplayer:** none (Doc 01 §33 decision — no network architecture required).

---

## 1. Module Architecture

Per Doc 01's modular requirement, sixteen top-level modules:

```
Core Gameplay
├── Character          (Arulan locomotion/combat/interaction; NPC shared base)
├── Combat              (Doc 10 systems)
├── Exploration          (movement, climb, swim per Doc 01 §11)
├── Puzzle               (shared puzzle framework, Doc 09/Production Bible v2 §2)
├── Quest                (data-driven quest state machine, Doc 07)
├── Dialogue             (branching dialogue + memory hooks, Doc 01 §19)
├── Inventory            (Doc 01 §20)
├── HistoricalCodex      (own top-level module per Doc 01 §6 — queried by nearly every other module)
├── World                (locations, world-state progression, Doc 02/13 §5)
├── AI                   (Mass Entity-driven NPC behavior, Doc 13)
├── Navigation            (pathfinding, EQS)
├── Weather               (Doc 17 §6)
├── Maritime               (Doc 12)
├── Save                  (§6 below)
├── UI                     (Doc 20)
└── Audio                  (Doc 21)
```

**Rationale for HistoricalCodex as a standalone module (not folded into UI or Quest, per Doc 01 §6):** Quest, Dialogue, Puzzle, and World all write to it; UI, Save, and Localization all read from it. A dependency graph with Codex embedded inside any one of those would create circular dependencies.

## 2. Class/Component Structure (representative, not exhaustive)

- `AGKCharacterBase` (C++) — shared base for Arulan and Tier 1/2 NPCs (Doc 13 §2), holds Health/Stamina/Combat components.
- `UGKCombatComponent` (C++, Actor Component) — GAS-integrated (Gameplay Ability System), attached to combat-capable characters.
- `UGKDialogueComponent` (C++) — holds current dialogue state, memory-flag references (Doc 13 §4).
- `UGKQuestSubsystem` (C++, GameInstanceSubsystem) — global quest state, drives Quest module.
- `UGKCodexSubsystem` (C++, GameInstanceSubsystem) — global Codex entry state, exposed to Blueprint for UI binding.
- `AGKPuzzleActor` (C++ base, Blueprint-extended per puzzle type) — shared puzzle-state interface (§4 below), so Save/UI/Quest modules can interact with any puzzle generically rather than needing per-puzzle-type integration code.
- NPC schedule/behavior: `UGKScheduleComponent` (C++) driving Mass Entity fragments for Tier 3 population, Blueprint-authored schedule data assets for Tier 1/2 (Doc 13 §2).

## 3. Data Models (Data Assets / Data Tables)

**Per Doc 01 §26 and the Foundation Bible's explicit requirement:** the Historical Evidence Database (Doc 03) must be structured data, not hardcoded strings, so non-engineers can review/revise it.

```
DataTable: DT_HistoricalEvidence
  Row: EvidenceID (matches Doc 03 ID, e.g. "B2")
  Fields: Claim (Text), EvidenceCategory (Enum: Documented/Plausible/Fictional),
          Source (Text), SourceType (Enum), Date (Text), Confidence (Enum: Known/Likely/Uncertain/Unknown),
          GameUsage (Text), Disclaimer (Text)

DataAsset: DA_Quest_<QuestID>
  Fields: Act, Location (SoftObjectPtr to level), Characters (array), HistoricalCategory,
          ObjectiveGraph (reference to Quest module's state machine graph),
          CodexRewardIDs (array of EvidenceID references into DT_HistoricalEvidence)

DataAsset: DA_NPC_<NPCID>
  Fields: Faction (reference into DT_Factions), ScheduleAsset, MemoryFlagSchema (array of flag keys this NPC can hold),
          Tier (Enum: 1/2/3 per Doc 13 §2)
```

Designers/Historical Research Director edit `DT_HistoricalEvidence` directly; Quest module references entries by `EvidenceID` rather than duplicating claim text anywhere else in the codebase — single source of truth, per the Foundation Bible's data-driven-history requirement.

## 4. Interfaces

- `IGKInvestigatable` — implemented by any actor that can be scanned/investigated (inscriptions, documents, evidence objects per Doc 11 §6), exposes `OnInvestigate()`, decoupling the investigation system from needing to know concrete object types.
- `IGKPuzzleInterface` — implemented by all puzzle actor types, exposes `GetPuzzleState()`, `AttemptSolve()`, `ResetPuzzle()` — lets Save/Quest/UI modules interact generically with any of the puzzle types from Doc 09/Production Bible v2 §2 without per-type branching.
- `IGKMemoryHolder` — implemented by NPCs, exposes `GetMemoryFlag(FName)`/`SetMemoryFlag(FName, bool)` (Doc 13 §4).

## 5. Events
Gameplay Message Subsystem (or equivalent pub/sub) for cross-module communication — e.g., Quest module broadcasts `OnQuestCompleted(QuestID)`, consumed independently by Codex (unlock rewards), AI (NPCs react per Doc 13 §5 "react to events"), and Audio (music-cue triggers, Doc 21) without those modules needing direct references to Quest module internals. This is the concrete mechanism behind Doc 13 §5's "world ripples from player choices" requirement.

## 6. Save Architecture

Per Doc 01 §27's flagged risk: world-simulation state (construction progress, NPC relationship/memory) must be captured alongside standard quest/inventory state.

```
USaveGame subclass: UGKSaveGame
  QuestState: Map<QuestID, QuestStateEnum>
  CodexUnlocked: Set<EvidenceID>
  NPCMemory: Map<NPCID, Map<FlagName, bool>>          <- Doc 13 §4
  WorldState: Map<LocationID, WorldStateEnum>          <- construction progress etc, Doc 13 §5
  PuzzleState: Map<PuzzleID, PuzzleStateStruct>
  FactionReputation: Map<FactionID, ReputationEnum>     <- Doc 14, non-numeric per Doc 01 §23
  ShipState: (if applicable, Doc 12)
```

**Autosave:** on quest-state-changing events and major location transitions. **Manual save:** available at any non-combat moment. Recommend an early technical spike specifically on `NPCMemory` and `WorldState` serialization cost, given the living-world NPC density target (Doc 13 §2) — this was flagged as an open risk in Doc 01 and remains the save system's biggest unknown.

## 7. Logging, Debugging, Profiling
Standard UE5 logging categories per module (`LogGKQuest`, `LogGKCodex`, `LogGKAI`, etc.) for isolated debugging. Recommend a custom in-editor debug overlay showing live NPC memory-flag state and current world-state values (Doc 13 §5), given how much of the game's "did my choice matter" feedback depends on those systems working correctly — this is a good early tools investment, not a nice-to-have.

## 8. Build Pipeline
Standard UE5 build pipeline (not detailed here — Production Manager/Technical Director to specify CI/build-server setup per team infrastructure, outside this document's scope).

---

## Open Questions
- `NPCMemory`/`WorldState` serialization cost — needs the technical spike flagged in §6 before the vertical slice locks its NPC population target (Doc 13 §2 tiering decision).
- Whether `IGKPuzzleInterface` is sufficient abstraction for all 8+ puzzle categories from Production Bible v2 §2, or whether some (e.g., Star-Sight Navigation's ship-context version) need a specialized sub-interface — Tools Programmer to evaluate once more puzzle types are implemented.

## Dependencies on Other Documents
Doc 01 (system requirements this architecture serves), Doc 03 (DT_HistoricalEvidence schema), Doc 07 (DA_Quest schema), Doc 13 (DA_NPC schema, Mass Entity requirements), Doc 36 (Save/Load, detailed here as authoritative).

## Acceptance Criteria
- All 16 modules specified with clear ownership boundaries.
- HistoricalCodex confirmed as standalone module with explicit dependency rationale.
- Historical Evidence Database confirmed as structured data (DT_HistoricalEvidence), not hardcoded strings, satisfying the Foundation Bible's explicit requirement.
- Save architecture explicitly addresses the world-simulation-state risk flagged in Doc 01 §27.


---



<!-- ===== doc19_ue5_implementation_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 19: UNREAL ENGINE 5 IMPLEMENTATION BIBLE

**Document ID:** UE5-19 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Concrete production implementation specification — folder structure and the C++/Blueprint/Data Asset/Data Table/Subsystem allocation for every module defined in Doc 18.
**Dependencies:** Doc 18 (module architecture, class list, data model schemas — this document makes them concrete and buildable).

---

## 1. Folder Structure

```
/Game
 /Characters
   /Arulan
   /NPCs
     /Tier1_Named        <- Doc 13 §2
     /Tier2_SemiNamed
     /Tier3_Background
 /World
   /Thanjavur
   /RoyalCourt
   /NorthernCorridor
   /Ganga
   /Gangaikondacholapuram
     /ConstructionZone
     /LivingCity
   /Port_Primary
   /Port_Secondary
   /Wilderness
 /Maps                     <- level assets per World Bible §4 locations
 /Quests
   /MainQuests              <- DA_Quest_MQ01 etc, Doc 07a
   /SideQuests               <- Doc 07b
   /HistoricalDiscovery        <- Doc 07c
   /PuzzleQuests                 <- Doc 07d
   /NavalQuests                   <- Doc 07e
   /ScholarArchiveQuests            <- Doc 07f
 /Puzzles
   /StoneAlignment
   /LionWell
   /RoyalSeal
   /InscriptionDecoding
   /TradeLedger
   /StarSightNavigation
   /MapReconstruction
   /ElevationLoadDeduction
   /Variants                    <- Environmental/Logic/HistoricalDeduction/PatternRecognition, Doc 07d
 /Combat                            <- Doc 10
 /AI                                   <- Doc 13, Mass Entity fragments/processors
 /UI                                     <- Doc 20
 /Audio                                    <- Doc 21
 /Cinematics                                 <- Doc 05
 /HistoricalCodex                              <- DT_HistoricalEvidence and Codex UI-facing assets
 /Items                                          <- Doc 26
 /Ships                                             <- Doc 12
 /Data
   /DataTables                                        <- DT_HistoricalEvidence, DT_Factions, DT_NPCSchedules
   /DataAssets                                            <- DA_Quest_*, DA_NPC_*, DA_Puzzle_*
 /Blueprints
   /Gameplay
   /UI
 /Materials
 /VFX
```

## 2. C++ / Blueprint / Data Asset / Data Table / Subsystem Allocation

**Principle:** performance-critical, deeply-shared, or systemically-central logic lives in C++; content-specific configuration and one-off scripted behavior lives in Blueprint or Data Assets; anything a non-engineer (Historical Research Director, Quest Designer, Narrative Director) needs to edit directly lives in a Data Table.

| System element | Lives in | Rationale |
|---|---|---|
| `AGKCharacterBase`, `UGKCombatComponent`, `UGKDialogueComponent` | C++ | Shared across every character, performance-relevant (Doc 18 §2) |
| Individual NPC schedule content | Data Asset (`DA_NPC_<ID>`) | Designer-editable per Doc 18 §3, no engineering needed to add/edit an NPC's day |
| Historical Evidence Database | Data Table (`DT_HistoricalEvidence`) | Must be directly editable by Historical Research Director without engineering involvement (Foundation Bible requirement, Doc 18 §3) |
| Individual quest logic/branching | Blueprint (`BP_Quest_<ID>`), referencing `DA_Quest_<ID>` for data | Quest Designers need to iterate on branching without C++ recompiles; underlying state-machine framework is C++ |
| Puzzle-type base logic (e.g., Stone Alignment load-path calculation) | C++ (`AGKPuzzleActor` subclasses per type) | Physics/logic-heavy, performance-relevant, shared across all instances of a puzzle type |
| Individual puzzle instance configuration (which stones, what solution) | Data Asset (`DA_Puzzle_<InstanceID>`) | Level/Puzzle Designers configure instances without touching puzzle-type C++ |
| Faction definitions (Doc 14) | Data Table (`DT_Factions`) | Directly editable reference data |
| Dialogue tree content | Blueprint-based dialogue graph (Dialogue module tooling) referencing localization keys | Writers/Narrative Designers need direct iteration; underlying branching engine is C++ |
| Save/Load serialization logic | C++ (`UGKSaveGame` and subsystem logic, Doc 18 §6) | Correctness-critical, not content |
| Global quest/Codex/faction-reputation state | GameInstanceSubsystem (C++: `UGKQuestSubsystem`, `UGKCodexSubsystem`) | Needs to persist across level streaming, accessible game-wide |
| NPC daily-cycle behavior (Tier 3 background population) | C++ Mass Entity fragments/processors | Performance-critical at population scale (Doc 13 §2) |
| NPC daily-cycle behavior (Tier 1/2) | Blueprint-authored schedule + C++ `UGKScheduleComponent` driving it | Balances designer iteration with shared underlying logic |
| UI widgets (Codex, Quest Journal, Map, etc.) | UMG Blueprint (widgets), C++ (data-binding subsystems) | Standard UE5 UI pattern; visual iteration in Blueprint, data plumbing in C++ |
| Cinematic sequences | Sequencer assets (per Doc 05 shot lists) | Standard UE5 cinematic tooling |

## 3. Subsystems (GameInstanceSubsystem / WorldSubsystem)

- `UGKQuestSubsystem` — global quest state (persists across level streaming via World Partition, Doc 18).
- `UGKCodexSubsystem` — global Codex unlock state, exposed to UI.
- `UGKWorldStateSubsystem` — construction-progress and other Doc 13 §5 world-state flags, the mechanism behind "revisited areas reflect current progress."
- `UGKReputationSubsystem` — faction/NPC reputation aggregation (Doc 01 §23, Doc 14), non-numeric-facing but internally tracked as structured state for UI/dialogue queries.

## 4. Implementation Note on Data-Driven History (worked example)

```
// Pseudocode: Quest module unlocking a Codex entry on quest completion,
// reading directly from DT_HistoricalEvidence rather than hardcoded text

void UGKQuestSubsystem::OnQuestCompleted(FName QuestID)
{
    UDataTable* QuestTable = LoadQuestDataTable();
    FGKQuestData* QuestData = QuestTable->FindRow<FGKQuestData>(QuestID, TEXT("QuestComplete"));

    for (const FName& EvidenceID : QuestData->CodexRewardIDs)
    {
        UGKCodexSubsystem::Get(this)->UnlockEntry(EvidenceID);
        // UnlockEntry looks up EvidenceID in DT_HistoricalEvidence directly —
        // no claim text, source, or confidence rating is duplicated in quest code.
    }

    FGKQuestCompletedMessage Message{QuestID};
    UGameplayMessageSubsystem::Get(this).BroadcastMessage(TAG_QuestCompleted, Message);
    // Doc 18 §5 event system — AI/Audio/World modules react independently
}
```

This is the concrete implementation of the Foundation Bible's data-driven-history requirement — worth keeping as a reference pattern since several other systems (Faction reputation, NPC memory) should follow the same "reference by ID into a Data Table, never duplicate the content" shape.

---

## Open Questions
- Whether dialogue tree tooling should be a custom UMG-based graph editor or a third-party dialogue plugin — Tools Programmer evaluation needed, affects Doc 22 production timeline.
- Mass Entity fragment/processor design for Tier 3 NPCs (§2) needs a dedicated technical design pass once the vertical slice's population density target is confirmed (Doc 13 §2, Doc 18 §6 open question).

## Dependencies on Other Documents
Doc 18 (module architecture and data schemas this document implements), Doc 07 (quest folder structure and DA_Quest references), Doc 13 (NPC tiering and Mass Entity requirements), Doc 03 (DT_HistoricalEvidence content).

## Acceptance Criteria
- Full `/Game` folder structure specified, matching your brief's example structure and extended per this project's specific module needs.
- Every system element explicitly allocated to C++, Blueprint, Data Asset, Data Table, or Subsystem, with rationale.
- Worked pseudocode example demonstrates the data-driven-history pattern concretely, not just asserted in principle.


---



<!-- ===== doc20_ui_ux_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 20: UI/UX BIBLE

**Document ID:** UIB-20 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full screen-by-screen UI specification, expanding Production Bible v2 §5 and Doc 17 §13.
**Dependencies:** Doc 01 §29–30 (minimal HUD principle, accessibility requirement), Doc 03 (Codex format, locked), Doc 17 §13 (material-driven visual language), Doc 37 (Accessibility, cross-referenced throughout).
**Design language, restated:** historical, minimal, elegant, stone/bronze inspired. UI frame elements borrow the material palette from Doc 17 §3 rather than a modern flat-design or fantasy-ornate aesthetic. No anachronistic iconography (no generic "RPG fantasy" icon sets).

---

## 1. Main Menu
Restrained — title treatment per Cinematic 002's title card style (Doc 05), stone/bronze-textured background panel, no animated fantasy particle effects. Options: Continue, New Game, Load, Settings, Credits.

## 2. Pause Menu
Minimal overlay, does not fully obscure the game world (subtle blur/darken only) — Map, Quest Journal, Inventory, Codex, Settings accessible from here, plus Resume/Quit.

## 3. Map
Per Doc 04 Act 10's Imperial Map system — this is both a narrative device and the primary navigation UI. Layered per your original spec (Political/Trade/Military/Maritime/Temple/Agriculture/Water/Cultural), zoomable Empire → Region → City → Temple → Street → Interior. Visual style: hand-drawn-map aesthetic consistent with period cartographic convention rather than a modern GPS-style overlay — markers use restrained iconography matching the material palette.

## 4. Quest Journal
Organized by the six Doc 07 categories (Main/Side/Historical Discovery/Puzzle/Naval/Scholar-Archive), each quest entry showing current objective and — notably — its Historical category tag (Doc 04/07 format) directly in the journal, not hidden behind a separate menu, since the evidence-honesty pillar should be visible everywhere the player encounters quest content, not just in the Codex.

## 5. Inventory
Minimal per Doc 01 §20 (narrative/puzzle-support tool, not a loot system) — evidence fragments, tools, trade goods, cosmetic items (per PQ05/PQ10 rewards) organized simply, no complex grid/weight system.

## 6. Codex
The game's signature UI surface. Locked format per Foundation Bible/Doc 03: **Source / Date-period / Confidence / Description** for every entry, organized by the categories from your original spec (People/Places/Architecture/Military/Trade/Religion/Technology/Water/Culture/Language/Art). Visual evidence-category distinction (Doc 01 §29, restated here as the authoritative UI spec):
- **[DOCUMENTED]** entries: solid border treatment, full-color.
- **[PLAUSIBLE RECONSTRUCTION]** entries: dashed/hatched border treatment.
- **[FICTIONAL]** entries: desaturated treatment with a distinct header color, clearly separated visually even from across the room on a screenshot.
Confidence tier (KNOWN/LIKELY/UNCERTAIN/UNKNOWN, per Doc 03's expanded scale) shown as explicit text, not just implied by the border style — redundant coding for accessibility (Doc 37 color-blind support requirement).

## 7. Puzzle UI
Minimal, diegetic where possible (e.g., Stone Alignment's load-stress visualization happens on the stones themselves, not a separate meter; Inscription Decoding's script-reference chart is presented as an in-world scholar's document, not a floating UI panel) — consistent with the "puzzles simulate real craft" design philosophy (Production Bible v2 §2).

## 8. Dialogue UI
Text-based branch selection (no full voice-input), subtitle-integrated for voiced lines, NPC name/portrait shown with restrained framing. Evidence-category indicator shown when a dialogue option would reveal or discuss historical content, so the player has a sense of "this is where the real history comes in" during conversation, not just after.

## 9. Combat UI
Minimal HUD per Doc 01 §29: health, stamina, equipped weapon only. No damage-number floating text (breaks grounded tone) — hit feedback communicated through animation/audio (Doc 21) rather than numeric pop-ups.

## 10. Navigation
Waypoint/compass elements minimal and diegetic-leaning where feasible — consistent with the Map's hand-drawn aesthetic rather than a modern minimap HUD element cluttering the main view.

## 11. Settings
Standard graphics/audio/control settings, plus: subtitle size, hint depth (Doc 01 §28 — puzzle hint adjustability, not puzzle-trivializing difficulty), combat assist toggles, motion-reduction toggle (Doc 37).

## 12. Accessibility
Full detail in Doc 37 — this document's UI-specific commitments: color-blind-safe Codex evidence-category coding (§6, redundant text + border style, not color alone), full subtitle text scaling, controller remapping, and a puzzle hint system that preserves intellectual content at every setting rather than trivializing puzzles (Doc 01 §28 principle, made concrete here as a settings-menu requirement).

---

## Open Questions
- Whether the Quest Journal (§4) should allow filtering by Historical category (e.g., "show only Historical Discovery quests") as a player-facing feature, or keep the six-category organization fixed — UX Designer playtesting call.
- Exact diegetic-vs-UI-panel balance for Puzzle UI (§7) needs prototyping per puzzle type before final lock.

## Dependencies on Other Documents
Doc 01 §29–30, Doc 03 (Codex format, locked), Doc 04/07 (quest category structure for Journal), Doc 17 §13 (material-driven UI visual language), Doc 37 (Accessibility, full detail).

## Acceptance Criteria
- All 12 screens/systems specified.
- Codex evidence-category visual distinction confirmed as the authoritative spec (matches Doc 01 §29's principle, now made concrete with actual border/color/text treatment).
- No UI element uses color alone to carry evidence-category meaning (accessibility requirement satisfied).
- Combat UI confirmed free of damage-number floating text, consistent with grounded-tone design throughout.


---



<!-- ===== doc21_audio_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 21: AUDIO BIBLE

**Document ID:** AUB-21 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full sound design and music specification, expanding Production Bible v2 §4.
**Dependencies:** Production Bible v2 §4 (base doctrine, carried forward), Doc 05 (cinematic sound cues already specified for key scenes), Doc 18 §5 (event system driving music-cue triggers).
**Core doctrine, restated:** diegetic sound carries as much weight as score; restraint is deliberate art direction, not absence of production value (Act 4 as the clearest example, per Doc 05 Cinematic 003).

---

## 1. Ambient Sound Categories

| Category | Content | Notes |
|---|---|---|
| City | crowd murmur, footsteps, distant activity, varies by time-of-day (Doc 13 §3 daily cycle) | Thanjavur (established, denser) vs. Gangaikondacholapuram (construction-inflected — stone dust, tools) should be acoustically distinguishable |
| Temple | bells, chanting (researched respectfully, reviewed by Cultural Sensitivity Consultant, not generic "mystical" temple drone), stone footsteps in enclosed spaces | Reverb model distinct per temple (Thanjavur's more resonant/established acoustic space vs. Gangaikondacholapuram's construction-affected acoustics) |
| Market | vendor calls, haggling murmur, goods handling (textile rustle, pottery, metal) | Ties to Doc 15 §2 — market audio density should reflect the economy system's narrative state (a shortage referenced in dialogue can be reinforced by a quieter, thinner market soundscape) |
| Forest/Wilderness | wind, birdsong, insect layers, distinct from delta agricultural ambience | Northern corridor (§4.3) needs a distinct acoustic identity signaling "away from home" per Art Direction's vegetation principle (Doc 17 §7) |
| Water | river, reservoir, canal-flow (central to Act 8 Lion Well puzzle audio feedback), open sea | River/reservoir/sea should be acoustically distinct, not one generic "water" loop reused everywhere |
| Battle | weapon impacts, movement, vocal effort — grounded, not stylized "epic" battle-horn stingers (per Doc 10's no-power-fantasy-escalation principle) | |
| Ship | rigging, hull creak, water against hull, distinct from land ambience entirely when at sea | |
| UI | minimal, restrained interaction sounds (menu navigation, Codex unlock chime) — bronze/stone-adjacent timbre consistent with Doc 20's material-driven UI visual language, translated to audio | |
| Cinematic | scene-specific, per Doc 05's individual shot-level sound notes | |

## 2. Music Themes

All original composition, South Indian instrument palette per Production Bible v2 §4 (percussion, winds, strings as motific palette, not literal sampled religious recordings).

| Theme | Character | Narrative use | Instrumentation emphasis |
|---|---|---|---|
| **Rajendra Theme** | Restrained, formal, low registered | Court scenes, campaign command moments — matches Doc 06 §1's "camera doesn't push in" restraint principle in musical form | Low strings, sparse percussion, minimal melodic ornamentation (mirrors his character's deliberate opacity) |
| **Arulan Theme** | Grounded, curious, develops across the game | Player-character motific identity, evolves in instrumentation/complexity as Arulan's role grows (Act 1 simple statement → Act 12 fuller arrangement) | Single melodic instrument (flute-family) at first, layered with strings/percussion as the game progresses |
| **Ganga Theme** | Near-absent by design | Act 4 — per Doc 05 Cinematic 003, this is mostly a single sustained tone, not a full theme statement; the "theme" is really the two-note motif that resolves at the scene's end | Single sustained tone, resolving to a simple two-note phrase |
| **Capital Theme** | Grows across the game | Gangaikondacholapuram's construction-to-living-city arc — deliberately incomplete/sparse in Acts 6–9, fully orchestrated only in Act 12 (mirrors the visual "under construction" principle from Doc 17 §2) | Percussion-forward early (construction sounds doubling as rhythmic texture), full ensemble by Act 12 |
| **Temple Theme** | Ceremonial, resonant | Temple-specific scenes, distinct from the broader Capital Theme | Winds and voice-adjacent textures (researched respectfully), temple bell motifs |
| **Conspiracy Theme** | Tense, understated — no cliché "villain" stinger | MQ13/19/20/27 — tension should read through rhythmic irregularity and low dynamic range, not bombastic minor-key melodrama, consistent with the Antagonist's non-villain-coded design (Doc 06 §8) | Low strings, irregular percussion, sparse |
| **Naval Theme** | Open, weathered, pragmatic | Act 11 and Doc 07e naval quest content | Winds evoking open water, moderate percussion for sailing rhythm |
| **Final Legacy Theme** | Full statement of accumulated motifs | Act 12/Epilogue — the only place the game's various themes combine into one full arrangement, deliberately held back until here for maximum payoff (per Production Bible v2 §4's score-restraint rule) | Full ensemble, callbacks to Arulan Theme and Capital Theme specifically |

## 3. Score Restraint Rule (reaffirmed)
Per Production Bible v2 §4: score swells are earned at named landmark reveals and the three ending variants only. Everyday exploration leans on ambience (§1) and light motific fragments (§2), not continuous underscore. This document's music-theme table exists to give composers a full thematic palette — restraint governs *when* these themes are deployed, not whether they're written with full craft.

## 4. Event-Driven Cue Triggers
Per Doc 18 §5's event system: music cues subscribe to gameplay messages (`OnQuestCompleted`, `OnLocationEntered`, `OnCombatStarted`) rather than being hardcoded to specific levels — this lets the Conspiracy Theme, for instance, follow the conspiracy thread across multiple locations (site office, storage yards, ambush site) consistently rather than needing per-level manual placement.

---

## Open Questions
- Temple chanting/vocal content (§1) needs Cultural Sensitivity Consultant sign-off before recording — flagged as high-priority given the live religious tradition this draws from.
- Whether the Arulan Theme's instrumentation evolution (§2) should be tied to specific story beats or gradual/continuous — Music Director call, needs Composer prototyping.

## Dependencies on Other Documents
Production Bible v2 §4 (base doctrine), Doc 05 (cinematic-specific cues), Doc 06 (character-theme alignment, especially Rajendra/Antagonist restraint), Doc 17 §7 (vegetation/acoustic identity alignment), Doc 18 §5 (event-driven cue system).

## Acceptance Criteria
- All 9 ambient categories and all 8 music themes specified.
- Score-restraint rule reaffirmed as governing deployment, not composition quality/depth.
- Conspiracy Theme confirmed to avoid villain-cliché scoring, consistent with the Antagonist's non-villain-coded character design.
- Temple/religious audio content flagged for Cultural Sensitivity Consultant review before production.


---



<!-- ===== doc22_voice_dialogue_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 22: VOICE & DIALOGUE BIBLE

**Document ID:** VDB-22 · **Version:** 1.0 · **Status:** Draft — blocked from full lock pending the Tamil linguistic authenticity review flagged in Doc 06 (all character names remain working names)
**Purpose:** Full language and voice-performance specification.
**Dependencies:** Doc 03 (H1–H2, language evidence), Doc 06 (per-character voice direction fields, referenced and expanded below), Doc 05 (cinematic dialogue already scripted for several scenes).

---

## 1. Tamil Dialogue
Primary spoken/inscriptional language per Doc 03 H1 (KNOWN — Tamil as the primary administrative/inscriptional language of the Chola state). Used for the majority of in-world dialogue among Tamil-speaking characters (nearly the entire named cast). Full Tamil voice track as the authentic performance layer, with English subtitles as the default UI language (per Doc 01 §16 language spec).

## 2. Sanskrit Usage
Restricted to specific formal/religious/literary contexts per Doc 03 H1's explicit finding — **not** used as generic "ancient-sounding" flavor dialogue. Appropriate uses: certain formal court/ceremonial phrases, specific religious/temple contexts, inscriptional formulae the Scholar might read aloud. Recommend the Historical Authenticity Consultant provide a specific approved-context list before any Sanskrit dialogue is written, rather than leaving it to writer discretion — this is a rule easy to violate by accident (defaulting to Sanskrit whenever something needs to "sound old").

## 3. English Subtitles
Default UI language (Doc 01 §16) — translation should preserve register distinctions between characters (§7 below) rather than flattening everyone into similar-sounding subtitle prose. Historical/technical terms (place names, titles, craft vocabulary) handled per Doc 03's terminology consistency requirement — a glossary should be maintained alongside this document once translation begins.

## 4. Pronunciation
Tamil/Sanskrit proper nouns and terms require a pronunciation guide for the English voice/subtitle-reading audience and for any English-language voice direction notes — recommend a dedicated pronunciation reference document (addendum to this bible) compiled with the linguistic consultant during the Doc 06 name-lock process, covering every named character and place.

## 5. Voice Personality (per Doc 06, consolidated here)
- **Rajendra:** restrained, low registered, minimal emotional coloring (Doc 06 §1)
- **Arulan:** grounded, naturalistic, avoids overly modern idiom (Doc 06 §2)
- **Scholar:** warm but exacting (Doc 06 §3)
- **Architect:** grounded, working-professional cadence (Doc 06 §4)
- **Naval Commander:** weathered, confident (Doc 06 §5)
- **Merchant:** quick, warm-but-guarded (Doc 06 §6)
- **Artisan:** calm, warm (Doc 06 §7)
- **Antagonist:** calm, persuasive, explicitly not mustache-twirling (Doc 06 §8)
- **Political Rival:** polished, faintly insincere (Doc 06 §9)
- **Messenger:** brisk, clear (Doc 06 §10)

## 6. Speech Rhythm
Formal characters (Rajendra, court NPCs, temple officials) use longer, more structured sentence rhythm; craft/working characters (Artisan, sculptors, farmers) use shorter, more direct rhythm; the Scholar sits deliberately in between — precise but not stiffly formal, reflecting an educated-but-not-courtly register.

## 7. Register by Faction (expanding Doc 14's per-faction dialogue-style fields into concrete direction)
- **Royal Speech:** formal, economical, indirect where politically necessary (court characters rarely say the blunt version of anything)
- **Merchant Speech:** transactional, quick, persuasive without being untrustworthy-sounding by default (avoid coding all merchant dialogue as "shifty," per the non-villain-coding principle extended to whole factions, not just named characters)
- **Military Speech:** blunt, practical, terse — MQ06's rival officer should sound authentically military-pragmatic even while voicing a politically loaded argument, not like a court character in armor
- **Scholar Speech:** precise, teacherly, occasionally dryly funny — the one register allowed genuine warmth without formality, per Doc 06 §3

## 8. Historical Figures — Hard Rule
Per the Foundation Bible's critical rule, reaffirmed here as this document's most important constraint: **no dialogue attributed to Rajendra Chola I (or any historical figure) may be presented as an authentic historical quotation.** Every line is dramatized fiction built on a documented historical frame. This should be enforced at the production level — recommend a script-review checklist item specifically verifying no Rajendra line in any script, marketing material, or Codex entry is ever formatted or worded in a way that implies direct historical sourcing.

---

## Open Questions
- Full lock blocked on Doc 06's linguistic authenticity review — recommend prioritizing this specifically because it also blocks pronunciation-guide production (§4) and therefore blocks voice casting/direction prep.
- Sanskrit approved-context list (§2) needs Historical Authenticity Consultant input before any dialogue writing in that language begins.

## Dependencies on Other Documents
Doc 03 (H1–H2), Doc 06 (per-character voice fields, blocked pending name lock), Doc 14 (faction dialogue-style baseline), Doc 05 (existing scripted dialogue to be reviewed against this document's register rules once both are locked).

## Acceptance Criteria
- Tamil/Sanskrit/English usage rules specified with explicit, non-accidental Sanskrit-usage boundaries.
- Voice personality and speech rhythm specified per character and per faction register.
- Hard rule against presenting fictional historical-figure dialogue as authentic quotation restated and given a concrete production-process enforcement mechanism (script-review checklist).


---



<!-- ===== doc23_historical_codex.md ===== -->

# GANGAIKONDA — DOCUMENT 23: HISTORICAL CODEX

**Document ID:** HC-23 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** The player-facing in-game encyclopedia — distinct from Doc 03 (the research team's working database). This document specifies how Doc 03 entries get *translated* into player-facing Codex entries, plus a full worked set across all 11 categories.
**Dependencies:** Doc 03 (source data), Doc 20 §6 (UI format, locked), Doc 18 §3 (technical implementation — `DT_HistoricalEvidence`).

**Relationship to Doc 03:** Doc 03 is written for the research/design team (columns: ID, Claim, Evidence Category, Source, Source Type, Date, Language, Confidence, Debate, Game Usage, Misinterpretation Risk, Disclaimer). The Codex is written for the *player* — same underlying facts, translated into the simpler locked format: **Title, Period, Category, Evidence, Source, Summary, Uncertainty, Gameplay connection.** Every Codex entry must trace to a specific Doc 03 ID; no Codex entry should introduce a claim not already vetted in Doc 03.

---

## Category: PEOPLE

### "Rajendra Chola I" (traces to Doc 03 A1–A2)
- **Period:** r. c. 1014–1044 CE
- **Category:** People
- **Evidence:** DOCUMENTED
- **Source:** Copper-plate inscriptions (e.g. Tiruvalangadu plates), temple inscriptions
- **Summary:** Chola emperor, son and successor of Rajaraja I, whose reign included a major military expedition into the Gangetic region and the founding of a new imperial capital.
- **Uncertainty:** Reign dates are well-established; exact co-regency start date is approximate.
- **Gameplay connection:** Unlocked at Act 2 (MQ04).

## Category: PLACES

### "Gangaikondacholapuram" (traces to Doc 03 C1)
- **Period:** founded c. 1025 CE onward
- **Category:** Places
- **Evidence:** DOCUMENTED
- **Source:** Royal inscriptions naming the capital; ASI archaeological survey
- **Summary:** The new imperial capital founded by Rajendra I following the northern expedition, distinct from the earlier capital at Thanjavur.
- **Uncertainty:** Full non-monumental city layout beyond the temple and major reservoir is not fully attested (see Architecture category note below).
- **Gameplay connection:** Unlocked at Act 6 (MQ11).

### "Thanjavur" (traces to Doc 03 A1)
- **Period:** Chola capital under Rajaraja I, active through Rajendra's reign
- **Category:** Places
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions
- **Summary:** The established Chola capital, site of Rajaraja I's Brihadisvara Temple, where the game begins.
- **Uncertainty:** None significant.
- **Gameplay connection:** Unlocked at Act 1 (MQ02).

## Category: ARCHITECTURE

### "The Brihadisvara Temple, Gangaikondacholapuram" (traces to Doc 03 C2–C3)
- **Period:** built c. 1025–1035 CE
- **Category:** Architecture
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions, UNESCO "Great Living Chola Temples" documentation
- **Summary:** A Shiva temple built by Rajendra I, architecturally related to but distinct in proportion from his father's temple at Thanjavur.
- **Uncertainty:** Exact completion date debated.
- **Gameplay connection:** Central to Act 7 (Stone Alignment puzzle chain); unlocked via HD01.

### "The City's Non-Monumental Layout" (traces to Doc 03 C4)
- **Period:** contemporary with the capital's founding
- **Category:** Architecture
- **Evidence:** FICTIONAL (this entry exists specifically to flag its own uncertainty to the player)
- **Source:** Partial archaeological remains
- **Summary:** Much of the residential and market fabric of the historical city has not survived or been fully excavated — the game's depiction of streets, homes, and markets is a plausible extrapolation, not an excavated record.
- **Uncertainty:** High — explicitly acknowledged.
- **Gameplay connection:** Ambient throughout Acts 6–12; a deliberate "honesty" entry rather than a discovery reward.

## Category: MILITARY

### "The Northern Expedition" (traces to Doc 03 B1–B4)
- **Period:** c. 1023–1025 CE
- **Category:** Military
- **Evidence:** DOCUMENTED (that it occurred) / RECONSTRUCTED (specific route and events)
- **Source:** Tiruvalangadu copper plates and other royal inscriptions
- **Summary:** A major military campaign into the Gangetic region, following which Rajendra adopted the title "Gangaikonda Chola." The inscriptions list regions/rulers encountered in a laudatory style, not a tactical narrative.
- **Uncertainty:** High for specific route, battles, and tactical details — labeled "HISTORICAL RECONSTRUCTION" throughout Acts 3–5.
- **Gameplay connection:** Unlocked via HD03, central to Acts 3–5.

## Category: TRADE

### "The Merchant Guilds" (traces to Doc 03 E1)
- **Period:** active throughout this era across South India and Southeast Asia
- **Category:** Trade
- **Evidence:** DOCUMENTED
- **Source:** Guild inscriptions found across South India and Southeast Asia
- **Summary:** Organized merchant associations (such as the Ainnurruvar) coordinated trade across a wide network, evidenced by inscriptions found far from South India itself.
- **Uncertainty:** Precise internal organizational structure debated among historians.
- **Gameplay connection:** Central to Act 11 and the NQ-series quests.

## Category: RELIGION

### "Temple as Institution" (traces to Doc 03 F2)
- **Period:** throughout the Chola period
- **Category:** Religion
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions recording land grants and administration
- **Summary:** Temples functioned not only as religious centers but as significant economic and administrative institutions, managing land grants and redistributing resources.
- **Uncertainty:** None significant on the general pattern.
- **Gameplay connection:** Unlocked via HD09/SQ11.

## Category: TECHNOLOGY

### "Lost-Wax Bronze Casting" (traces to Doc 03 G1)
- **Period:** reached a recognized artistic peak under Rajaraja I and Rajendra I
- **Category:** Technology
- **Evidence:** DOCUMENTED
- **Source:** Surviving bronzes, temple inventory inscriptions
- **Summary:** The cire perdue (lost-wax) casting technique used to produce the era's celebrated bronze sculptures.
- **Uncertainty:** None on the technique's use; specific workshop practices vary by scholarly reconstruction.
- **Gameplay connection:** Unlocked via HD07/HD10.

## Category: WATER

### "The Great Reservoir" (traces to Doc 03 D1–D2)
- **Period:** constructed alongside the new capital
- **Category:** Water
- **Evidence:** DOCUMENTED (existence) / TRADITION (Ganga-water symbolism)
- **Source:** Archaeological remains; later textual tradition
- **Summary:** A large reservoir associated with the new capital. Tradition holds that it was symbolically filled with water carried from the Ganga campaign — this specific claim is not independently verifiable and is presented here as tradition, not documented fact.
- **Uncertainty:** Reservoir's existence is solid; the water's origin story is explicitly a tradition, not an attested engineering record.
- **Gameplay connection:** Central to Act 8 (Lion Well puzzle chain), unlocked via MQ17/HD04.

## Category: CULTURE

### "Village Self-Governance" (traces to Doc 03 F1)
- **Period:** documented administrative continuity through this era
- **Category:** Culture
- **Evidence:** DOCUMENTED
- **Source:** Uttaramerur inscriptions (slightly predating Rajendra, reflecting continuous administrative culture)
- **Summary:** Local village assemblies operated with documented administrative procedures, existing alongside royal administration.
- **Uncertainty:** How uniformly this specific model applied across all Chola territory is debated.
- **Gameplay connection:** Unlocked via HD05.

## Category: LANGUAGE

### "Tamil and Sanskrit in Chola Inscriptions" (traces to Doc 03 H1)
- **Period:** throughout the Chola period
- **Category:** Language
- **Evidence:** DOCUMENTED
- **Source:** The corpus of surviving Chola inscriptions
- **Summary:** Tamil was the primary administrative and inscriptional language, with Sanskrit used in specific formal, religious, and literary contexts.
- **Uncertainty:** None significant.
- **Gameplay connection:** Ambient throughout; directly informs Doc 22's dialogue rules.

## Category: ART

### "Reading a Sculptor's Hand" (traces to Doc 03 G3, general art-historical scholarship)
- **Period:** throughout the Chola period
- **Category:** Art
- **Evidence:** DOCUMENTED (general phenomenon) / FICTIONAL (specific panels shown)
- **Source:** Comparative art-historical scholarship
- **Summary:** Individual sculptors' stylistic habits can sometimes be identified across multiple works, a real phenomenon in temple sculpture scholarship.
- **Uncertainty:** The general phenomenon is documented; the specific panels the player examines in-game are fictional illustrations of it.
- **Gameplay connection:** Unlocked via PQ04.

---

## Codex System Rules (production-facing)
1. Every Codex entry's **Evidence** field must match its source Doc 03 entry's Evidence Category — no upgrading confidence in translation from research format to player format.
2. Entries with genuinely high uncertainty (like "The City's Non-Monumental Layout" above) should exist as their own entries, not be silently omitted — the Codex's credibility depends on it being honest about gaps, not just complete about knowns.
3. Every entry must show its **Gameplay connection** — no orphaned lore-dump entries unconnected to actual play.

## Open Questions
- Full Codex will need roughly 60–80 entries to properly cover Doc 03's eventual expanded database — this document establishes the format and provides one worked example per category (11 total) as the production template.
- Whether entries should link to each other (e.g., "Gangaikondacholapuram" linking to "The Great Reservoir") in the UI — UX Designer call, technically supported by Doc 18's DataTable structure regardless.

## Dependencies on Other Documents
Doc 03 (source data for every entry), Doc 18 §3–4 (technical implementation), Doc 20 §6 (locked UI format).

## Acceptance Criteria
- One worked entry per all 11 categories from your brief, each traced to a specific Doc 03 ID.
- Codex system rules explicitly prevent confidence-upgrading between Doc 03 and Codex format.
- At least one entry (Architecture category) explicitly models how the Codex handles high-uncertainty content honestly rather than omitting it.


---



<!-- ===== doc24_world_event_system.md ===== -->

# GANGAIKONDA — DOCUMENT 24: WORLD EVENT SYSTEM

**Document ID:** WES-24 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Dynamic world-event specification — the mechanism that keeps the living-world pillar feeling alive between authored quest beats.
**Dependencies:** Doc 13 (NPC AI/react-to-events principle), Doc 18 §5 (event/message subsystem this rides on), Doc 17 §6 (weather/seasonal system).

---

## 1. Market Events
- **Trigger:** seasonal cycle, or narrative state (a shortage referenced in a completed quest, e.g. MQ12)
- **NPC response:** vendor dialogue variation, goods availability shifts
- **World response:** visual density of stalls/goods changes
- **Player interaction:** optional — browsing/dialogue only, no forced interaction
- **Historical status:** [FICTIONAL] specific event instances on [DOCUMENTED] general economic patterns (Doc 03 E1, F2)

## 2. Weather Events
- **Trigger:** seasonal simulation (Doc 17 §6 monsoon cycle)
- **NPC response:** schedule shifts (reduced outdoor activity in wet season, per Doc 13 §3)
- **World response:** visual/audio weather state change (Doc 21 §1), travel speed modulation for naval/overland movement
- **Player interaction:** affects available activities (some quests naturally suit dry-season timing) without hard-blocking
- **Historical status:** [DOCUMENTED] general monsoon-seasonal climate pattern

## 3. Temple Events
- **Trigger:** narrative milestone (temple construction progress) or scheduled ceremonial activity (only where separately sourced, per Foundation Bible's festival caution)
- **NPC response:** temple official/priest NPC activity increases, ambient chanting/bell audio intensifies (Doc 21 §1)
- **World response:** temple precinct visual dressing (lamps, offerings) increases
- **Player interaction:** optional observation, some investigation-relevant NPCs more approachable during these windows
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] — only implemented for specific ceremonial content once the Historical Research Director sources it; generic "temple is busier at X time" activity is safely [FICTIONAL] ambient variation

## 4. Merchant Arrivals
- **Trigger:** narrative (NQ01/05/07 outcomes), or periodic ambient variation
- **NPC response:** new merchant NPC appears at port/market with unique dialogue/goods
- **World response:** port/market density increases temporarily
- **Player interaction:** optional trade/dialogue, occasionally tied to a light quest hook (SQ03-style)
- **Historical status:** [FICTIONAL] specific arrivals on [DOCUMENTED] trade network basis (Doc 03 E1–E2)

## 5. Military Movements
- **Trigger:** primarily narrative (Act 3 campaign, MQ20 ambush response, any garrison reinforcement post-conspiracy)
- **NPC response:** soldier NPC presence/patrol pattern shifts
- **World response:** visible troop movement on roads (World Bible §3)
- **Player interaction:** mostly observational; can trigger investigation content if the player follows/questions
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] general military activity, [FICTIONAL] specific instances

## 6. Construction Events
- **Trigger:** quest-milestone-driven (Doc 13 §5's "world reflects progress" principle) — this is the single most important event category for the living-world pillar
- **NPC response:** worker NPC activity/dialogue reflects current construction phase
- **World response:** visible structural progress (scaffolding removed, new sections active) — implemented via `UGKWorldStateSubsystem` (Doc 19 §3)
- **Player interaction:** primarily passive observation of consequence, occasionally gates new puzzle/quest access (e.g., temple sections unlocking as Stone Alignment tiers complete)
- **Historical status:** [FICTIONAL] specific progression on [DOCUMENTED] final built state (Doc 03 C2)

## 7. Political Events
- **Trigger:** conspiracy-thread milestones (MQ13/19/20/27), Doc 14 faction-relationship state
- **NPC response:** faction-affiliated NPCs' disposition/dialogue shifts per Doc 13 §6 faction AI modulation
- **World response:** ambient dialogue across the settlement reflects political developments (per Doc 13 §5's explicit requirement that the conspiracy's public resolution rippled through worker ambient dialogue)
- **Player interaction:** primarily narrative consequence; occasionally opens new SA/HD quest availability
- **Historical status:** entirely [FICTIONAL]

## 8. Festival/Reconstruction Events
- **Trigger:** only implemented where specifically sourced by Historical Research Director, per Foundation Bible's explicit "festivals only where historically supportable or clearly marked as reconstruction" rule
- **NPC response:** widespread NPC activity shift, unique dialogue/animation
- **World response:** significant visual/audio dressing change, highest-production-cost event category
- **Player interaction:** optional attendance, potential light quest content
- **Historical status:** must be explicitly labeled — either [PLAUSIBLE RECONSTRUCTION] (if sourced) or omitted entirely rather than invented; this document does not pre-authorize any specific festival content pending that sourcing

## 9. Naval Arrivals
- **Trigger:** narrative (NQ-series outcomes) or periodic ambient variation at port
- **NPC response:** new sailor/trader NPCs, Naval Commander commentary
- **World response:** port visual density increases, new ship silhouettes visible
- **Player interaction:** optional, sometimes light quest hooks
- **Historical status:** [FICTIONAL] specific instances on [DOCUMENTED] network basis (Doc 03 E1–E3)

## 10. Agricultural Events
- **Trigger:** seasonal cycle (harvest, planting, flood risk per SQ13)
- **NPC response:** farmer NPC activity/dialogue shifts
- **World response:** visible field state changes (fallow, planted, flooded, harvested)
- **Player interaction:** optional, SQ13-style light quest hooks during flood risk windows
- **Historical status:** [DOCUMENTED] general agricultural pattern (World Bible §2), [FICTIONAL] specific instances

---

## System-Wide Implementation Note
All ten event types subscribe to/broadcast via the Gameplay Message Subsystem (Doc 18 §5) rather than being hardcoded to specific levels or timers — this lets, for example, Construction Events (§6) and Political Events (§7) interact (a construction milestone completing while the conspiracy thread is active should produce ambient dialogue that references *both*, not two disconnected event systems talking past each other).

## Open Questions
- Festival/Reconstruction Events (§8) remain unimplemented pending Historical Research Director sourcing — flagged consistently with the Doc 03 Open Questions note on this same gap.
- Exact frequency/randomization for ambient-variation events (Merchant Arrivals, Naval Arrivals) needs Game Designer tuning during vertical-slice-adjacent prototyping.

## Dependencies on Other Documents
Doc 13 (NPC react-to-events principle, faction AI modulation), Doc 17 §6 (weather/seasonal), Doc 18 §5 (event subsystem), Doc 19 §3 (`UGKWorldStateSubsystem`).

## Acceptance Criteria
- All 10 event categories specified with Trigger/NPC response/World response/Player interaction/Historical status.
- Festival content explicitly withheld pending sourcing rather than invented, consistent with the Foundation Bible's explicit caution.
- Construction Events (§6) confirmed as the mechanism realizing the "world reflects player progress" requirement flagged repeatedly since Doc 01.


---



<!-- ===== doc25_progression_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 25: PROGRESSION BIBLE

**Document ID:** PB-25 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full progression system specification across your eight named tracks, expanding Doc 01 §10's principle.
**Dependencies:** Doc 01 §10 (no numeric RPG leveling — capability/world-state progression only), Doc 06 (Arulan's arc), Doc 07 (quests as progression gates).
**Core rule, restated and binding for every track below:** no arbitrary numeric stat increases. Every unlock must be a *capability* (a new tool, technique, or access) or a *world-state change*, and must be narratively justified by something Arulan has actually done in the story — never a level-up screen divorced from narrative.

---

## 1. Exploration
- **What progresses:** access, not ability — new regions unlock via the Imperial Map system (Doc 04 Act 10) and specific traversal contexts (scaffolding access as construction progresses, ship access after Act 11 begins).
- **Narrative justification:** every new area is unlocked by a specific story beat (e.g., Act 6 unlocks Gangaikondacholapuram, Act 10 unlocks the wider map, Act 11 unlocks maritime travel) — never a generic "explore 50% of the map to unlock fast travel" mechanic.
- **No numeric stat involved.**

## 2. Combat
- **What progresses:** technique variety, not power — new combat options (parry timing windows, stealth-takedown access) are introduced narratively as Arulan gains real experience (post-Act 3 campaign exposure, post-MQ20 ambush), not via a skill-point spend screen.
- **Narrative justification:** Arulan explicitly starts non-soldier-competent (Doc 06 §2) and gains capability through survival, not training-montage leveling.
- **No numeric stat involved** — enemy difficulty in later encounters comes from encounter design (more coordinated enemies, per Doc 10 §3), not from Arulan's stats increasing.

## 3. Scholarship
- **What progresses:** investigation tool depth — Inscription Decoding tiers, Royal Seal Verification access, and Codex cross-referencing capability unlock through the SA-series and HD-series quests (Doc 07c/f) as Arulan's relationship with and training from the Scholar deepens.
- **Narrative justification:** SA06 ("Teaching the Apprentice") is the clearest marker of this track — Arulan has progressed enough in scholarship to teach someone else, a narrative demonstration of growth rather than a stat number.
- **No numeric stat involved.**

## 4. Diplomacy
- **What progresses:** dialogue option breadth — new diplomatic approaches become available in Act 11 (NQ01/05) and in political scenes (MQ22) based on accumulated reputation (Doc 01 §23) rather than a "charisma stat."
- **Narrative justification:** diplomatic capability grows from demonstrated track record (how earlier faction interactions went, per Doc 13 §4 memory), not abstract leveling.
- **No numeric stat involved.**

## 5. Navigation
- **What progresses:** Star-Sight Navigation puzzle tier access — introduced in Act 11, deepened through NQ09 and PQ07, representing Arulan (or the player, through the Naval Commander's instruction) learning real period navigation method.
- **Narrative justification:** each navigation puzzle tier is explicitly taught in-fiction by a specific NPC (Naval Commander, local navigator in NQ09) before the player faces a harder instance — teaching precedes testing, never an abstract unlock.
- **No numeric stat involved.**

## 6. Craftsmanship
- **What progresses:** Stone Alignment and puzzle-adjacent craft tiers, unlocked as the Architect and Artisan trust Arulan with more complex work (MQ14 → MQ15 → MQ29's capstone).
- **Narrative justification:** craft trust is earned relationally, not granted by a skill tree — MQ15's sculptor's-doubt quest specifically ties craft-tier access to demonstrated judgment, not just repetition.
- **No numeric stat involved.**

## 7. Leadership
- **What progresses:** the degree to which NPCs defer to or seek out Arulan's judgment, most visible in Act 12 (MQ26–29) and the ending-variant framing (Doc 04) — this is the track most purely expressed through world/NPC state rather than any gated mechanical unlock.
- **Narrative justification:** leadership isn't "trained," it's accumulated through the entire game's choices (MQ22, MQ27, SA-series) — this track is really a *label* for how several other tracks' accumulated state gets read by the world in Act 12, not a standalone system with its own unlocks.
- **No numeric stat involved.**

## 8. Investigation
- **What progresses:** evidence-chain complexity Arulan can handle — from MQ02's single-inscription tutorial through MQ19's multi-source conspiracy investigation to MQ27's full evidence-presentation confrontation.
- **Narrative justification:** each investigation quest explicitly builds on skills established in an earlier one (per Doc 11 §12's chain-shape requirement) — the player is never asked to perform an investigation technique the game hasn't already taught them through an earlier, lower-stakes version of the same shape.
- **No numeric stat involved.**

---

## Cross-Track Principle
Several tracks converge at MQ29's capstone puzzle (Stone Alignment + Water + Inscription combined) and the Act 12 ending-variant system (Doc 04) — progression in this game is ultimately legible as "what Arulan has become capable of and trusted with," demonstrated through the story's own structure, rather than through a stats/skill-tree screen the player manages separately from the narrative.

## Open Questions
- Whether Leadership (§7) needs any player-facing UI representation at all, given it's described above as an emergent label rather than a system — leans toward "no dedicated UI, purely narrative," but UX Designer should confirm this doesn't leave players feeling like a stated pillar (Leadership) is invisible/unrewarded.

## Dependencies on Other Documents
Doc 01 §10 (governing principle), Doc 06 (Arulan's arc), Doc 07 (quest-gated unlocks throughout, extensively cross-referenced above), Doc 11 §12 (investigation-chain progression shape), Doc 13 §4 (reputation/memory feeding diplomacy).

## Acceptance Criteria
- All 8 tracks specified with explicit narrative justification, per your instruction.
- No numeric RPG statistic introduced anywhere in this document.
- Every unlock traceable to a specific quest or relationship-state change already defined in Doc 07/13, not a generic placeholder mechanic.


---



<!-- ===== doc26_inventory_crafting_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 26: INVENTORY & CRAFTING BIBLE

**Document ID:** ICB-26 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full inventory item-category specification, expanding Doc 01 §20–21 and Doc 20 §5.
**Dependencies:** Doc 01 §20–21 (inventory as narrative/puzzle-support tool, not loot system; light crafting only), Doc 10 §2 (weapons), Doc 21 (Craft) — representative items per category shown; full item-by-item list is Doc 30's (Prop Bible) production responsibility.

**Governing constraint, restated:** per Doc 01, this is not a loot-treadmill RPG inventory. Every item category below exists to serve narrative, puzzle, or light-craft purposes — no item should exist purely as a numeric-stat upgrade.

---

## 1. Weapons
- **Historical status:** [PLAUSIBLE RECONSTRUCTION] (Doc 03 I1, Doc 10 §2)
- **Acquisition:** narrative — Arulan is equipped appropriately to context (campaign gear in Act 3, minimal in Act 1–2, per Doc 06 §2's evolving clothing/equipment)
- **Usage:** combat (Doc 10), no separate menu-based equip-management complexity
- **Upgrade:** none numeric — a weapon doesn't get "+2 damage," but *narrative* upgrades exist (e.g., a gifted weapon from the Naval Commander post-NQ10 as a relationship marker, cosmetically distinct but not mechanically superior)
- **Visual design:** Doc 17 §10
- **Gameplay purpose:** combat function, relationship/story markers

## 2. Tools
- **Historical status:** [PLAUSIBLE RECONSTRUCTION]
- **Acquisition:** quest-granted (e.g., inscription-scan tool from Scholar in MQ02, puzzle-specific tools introduced per puzzle chain)
- **Usage:** puzzle-solving (Production Bible v2 §2), investigation (Doc 11 §6)
- **Upgrade:** capability-tier unlocks (Doc 25 track-based), not numeric
- **Visual design:** period-practical, craft-appropriate per tool type
- **Gameplay purpose:** primary mechanism connecting inventory to the puzzle/investigation systems — this category does the most mechanical work of any in this document

## 3. Clothing
- **Historical status:** [PLAUSIBLE RECONSTRUCTION]/[DOCUMENTED] per Doc 17 §11
- **Acquisition:** narrative role-progression (Doc 06 §2's Act-by-Act evolving dress) and disguise items (Doc 11 §4)
- **Usage:** cosmetic role-marking, functional disguise access
- **Upgrade:** none — clothing changes reflect story state, not player-chosen cosmetic customization loadouts (keeping Arulan's visual identity authorially consistent rather than player-customizable, consistent with a strongly authored narrative game rather than an RPG-style character builder)
- **Visual design:** Doc 17 §11, Doc 06 per-character
- **Gameplay purpose:** disguise-based stealth access (Doc 11 §4), narrative/role signaling

## 4. Artifacts
- **Historical status:** must be classified per Doc 27 (Artifact & Relic Bible) — DOCUMENTED ARTIFACT / RECONSTRUCTED OBJECT / FICTIONAL STORY OBJECT
- **Acquisition:** discovery quests (Doc 07c HD-series), optional exploration content (SQ12-style)
- **Usage:** Codex entries, occasionally quest-item function (e.g., a discovered object needed for a later quest step)
- **Upgrade:** none
- **Visual design:** varies per object, researched per Doc 17 §1/§9 principles
- **Gameplay purpose:** the primary carrier of the evidence-honesty pillar at the object level — see Doc 27 for full classification rules

## 5. Documents
- **Historical status:** varies — ledgers/letters are [FICTIONAL] specific objects representing [DOCUMENTED] general record-keeping practice (Doc 03 E1, F1–F2)
- **Acquisition:** investigation quests (MQ13/19, SQ07, conspiracy thread throughout)
- **Usage:** Doc 11 §9 document-discovery investigation system, evidence for Codex/Archive
- **Upgrade:** none — documents are read once and their information persists in the Codex/Archive rather than being re-consulted as physical inventory items after their quest relevance passes
- **Visual design:** period-appropriate writing materials/format (per Doc 03 H1–H2 script conventions)
- **Gameplay purpose:** investigation-system fuel

## 6. Trade Goods
- **Historical status:** [DOCUMENTED] general categories (Doc 15 §1), [FICTIONAL] specific instances
- **Acquisition:** Doc 15's construction-resource/trade systems, merchant quests
- **Usage:** Trade Ledger Reconciliation puzzles, resource-management gameplay (Doc 01 §21/§25)
- **Upgrade:** none — quantity/flow matters, not item-level upgrading
- **Visual design:** Doc 17 §3 material palette
- **Gameplay purpose:** economy-system gameplay (Doc 15), kept deliberately light per that document's scoping

## 7. Craft Materials
- **Historical status:** [DOCUMENTED]/[PLAUSIBLE RECONSTRUCTION] per Doc 15 §1
- **Acquisition:** construction-zone resource gameplay (MQ12), Artisan quests (SQ04–06)
- **Usage:** light-craft-assist quests (Doc 01 §21 — assisting artisan NPCs in specific quests, not full player-facing crafting system)
- **Upgrade:** N/A
- **Visual design:** Doc 17 §3, §9
- **Gameplay purpose:** grounds the "assisting a craftsperson" quest shape (SQ04–06, HD07) in tangible objects rather than abstract quest-log text

## 8. Historical Objects (distinct sub-category from Artifacts — everyday objects with Codex-flavor value but not "discoveries")
- **Historical status:** [FICTIONAL] specific objects, [PLAUSIBLE RECONSTRUCTION]/[DOCUMENTED] general material-culture basis
- **Acquisition:** environmental pickups, minor quest rewards (PQ05/PQ10's cosmetic rewards)
- **Usage:** Codex flavor entries, cosmetic display value only
- **Upgrade:** none
- **Visual design:** per Doc 17 §1/§9/§12
- **Gameplay purpose:** low-stakes collectible content for players who enjoy that kind of completionism, explicitly non-mandatory and non-power-affecting

---

## Open Questions
- Whether Historical Objects (§8) needs any dedicated "collection" UI/achievement framing, or should remain purely incidental — UX Designer call, low priority.
- Craft Materials (§7) inventory representation (abstracted resource pool vs. discrete carried items) needs a UI/technical decision aligned with Doc 15's construction-resource system implementation.

## Dependencies on Other Documents
Doc 01 §20–21 (governing principle), Doc 10 §2 (weapons), Doc 11 §4/§9 (disguise/document systems), Doc 15 (economy/craft materials), Doc 17 (visual design per category), Doc 27 (Artifact classification rules, referenced not duplicated).

## Acceptance Criteria
- All 8 categories specified with all 6 required fields.
- No item category introduces numeric power-upgrade mechanics, consistent with Doc 01's no-loot-treadmill principle.
- Artifacts (§4) explicitly deferred to Doc 27 for classification rather than duplicating that document's job here.


---



<!-- ===== doc27_artifact_relic_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 27: ARTIFACT & RELIC BIBLE

**Document ID:** ARB-27 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Classification system and worked examples for all collectible artifacts/relics, per your explicit requirement that fictional objects never be presented as authentic archaeological discoveries.
**Dependencies:** Doc 03 (evidence basis), Doc 23 (Codex — artifacts feed Codex entries), Doc 26 §4 (Inventory — this document is that section's full detail).

---

## 1. The Three-Tier Classification (mandatory for every artifact)

### DOCUMENTED ARTIFACT
An in-game object modeled directly on a real, specifically identifiable archaeological find or well-attested object type (e.g., a bronze in the general style of surviving Chola-period bronzes, Doc 03 G1). The Codex entry for a DOCUMENTED ARTIFACT may reference the real object type it's modeled on, but the specific in-game instance (this exact statue, found in this exact location by Arulan) is still narratively fictional — the *type* is documented, the *specific find* is not, and the Codex wording must make that distinction rather than implying Arulan personally excavated a named real artifact.

### RECONSTRUCTED OBJECT
An object type that plausibly existed based on general period/regional evidence but isn't tied to a specific attested find (e.g., a specific ship-fitting per Doc 03 E4's evidence gap, or a specific water-system component per Doc 03 D3). Tagged [PLAUSIBLE RECONSTRUCTION] throughout, Codex-flagged accordingly.

### FICTIONAL STORY OBJECT
An object that exists purely to serve the plot (e.g., the specific forged seal from MQ19's conspiracy thread, the specific ledgers throughout the investigation chain). Never Codex-logged with real-world sourcing — its Codex entry, if any, is explicitly about its role in Arulan's story, not a historical claim.

**Hard rule:** no object in any of the three tiers may have its Codex entry, marketing copy, or in-game dialogue worded in a way that implies the specific in-game object is a real archaeological artifact housed somewhere or excavated at a real date. This is the artifact-level enforcement of the Foundation Bible's "never fabricate inscriptions" and "never label fictional architecture as archaeological fact" rules, extended to portable objects.

---

## 2. Worked Examples

### "The Bronze of the Dancing Form" — DOCUMENTED ARTIFACT (type)
- **Basis:** modeled on the general style of Chola-period bronze sculpture (Doc 03 G1) — Nataraja-type bronzes are a well-known, extensively studied category
- **In-game context:** a specific in-game bronze discovered in the temple treasury (HD10's location)
- **Codex wording principle:** "Bronzes in this style represent a documented artistic peak of the period [Doc 03 G1] — the specific piece shown here is a fictional representative example, not a named historical object." Never: "This is [Real Museum]'s actual bronze."

### "The Water Engineer's Marker Stone" — RECONSTRUCTED OBJECT
- **Basis:** plausible type of object (a stone marking a water-system component) built on Doc 03 D1/D3's documented general reservoir/canal existence, but this specific marker and its inscription are invented
- **In-game context:** found during the Lion Well puzzle chain (Act 8)
- **Codex wording principle:** "Objects of this general kind plausibly existed given the documented water infrastructure at the site [Doc 03 D1] — this specific marker is a fictionalized illustration of that infrastructure, not an excavated find."

### "The Falsified Ledger" — FICTIONAL STORY OBJECT
- **Basis:** entirely fictional, central to MQ19's conspiracy
- **In-game context:** evidence object found in the site office investigation
- **Codex wording principle:** if logged at all, framed purely as a story artifact ("A record central to the events of Arulan's investigation") with no historical-sourcing language whatsoever — this object should probably not receive a full Doc 23-style Codex entry at all, since it has no historical-evidence content to honestly convey; a lighter "Story Item" log distinct from the Historical Codex may be the right UI solution (flagged to Doc 20).

### "The Shipwright's Model" — RECONSTRUCTED OBJECT (directly engages Doc 03 E4's gap)
- **Basis:** built on Doc 12/NQ06's explicit handling of the ship-construction evidence gap
- **In-game context:** obtainable from the shipwright NPC in NQ06
- **Codex wording principle:** "Ship construction methods of this period are not well documented [Doc 03 E4] — this model represents one plausible reconstruction based on regional shipbuilding tradition, not a documented Chola vessel design." This entry should be one of the more heavily caveated in the whole Codex, matching the gap's severity.

---

## 3. UI Implication (flagged to Doc 20)
Given "The Falsified Ledger" example above, recommend Doc 20 consider a distinct "Story Items" log separate from the Historical Codex proper — mixing plot-device objects into the same UI surface as genuinely sourced historical content risks diluting the Codex's credibility as a trustworthy evidence source. This is a meaningful cross-document recommendation, not just a formatting note.

## Open Questions
- Full artifact list (beyond the four worked examples) is a Doc 30 (Prop Bible) production task, using this document's classification system as the mandatory template for every entry.
- Whether DOCUMENTED ARTIFACT type entries should include a real-world "further reading" pointer (e.g., naming the actual museum collection the style is drawn from) — could be a nice authenticity touch, but needs legal/IP review before committing to naming specific real institutions.

## Dependencies on Other Documents
Doc 03 (evidence basis for every classification decision), Doc 12/NQ06 (Shipwright's Model example), Doc 20 (UI recommendation), Doc 23 (Codex format this feeds), Doc 30 (Prop Bible, full production list).

## Acceptance Criteria
- Three-tier classification system fully specified with a hard rule against implying real-artifact status for any fictional object.
- Four worked examples cover all three tiers plus the specific Doc 03 E4 evidence-gap case.
- Cross-document UI recommendation flagged to Doc 20 rather than silently worked around.


---



<!-- ===== doc28_cinematic_storyboard_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 28: CINEMATIC STORYBOARD BIBLE

**Document ID:** CSB-28 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Translate Doc 05's shot-level screenplay into storyboard-frame descriptions with explicit composition/blocking detail, for direct concept-artist use.
**Dependencies:** Doc 05 (source shot list — this document adds composition/blocking specificity Doc 05 doesn't carry, it does not re-derive the shots themselves).
**Relationship to Doc 05:** Doc 05 answers "what happens and how is it shot" (camera/lens/movement/sound/dialogue). This document answers "what does the frame actually look like" (composition, blocking positions, focal points) — the layer a concept artist needs that a screenplay format doesn't naturally carry.

**Scope note:** storyboarding all shots from all twelve Doc 05 cinematics at this detail is a full concept-art-department task. Below: full storyboard treatment for Cinematic 001 (Prologue) and Cinematic 003 (The Ganga) — chosen because they're the two most composition-critical, restraint-driven sequences in the game, where getting the frame wrong would undercut the whole scene. The remaining cinematics should follow this exact frame-description template once their Doc 05 shot lists are finalized (several are still pending Doc 06 voice-lock, per Doc 05's own note).

---

## CINEMATIC 001 — PROLOGUE, Storyboard Frames

**Frame 1 (Shot 001):** Composition: rule-of-thirds, ruins occupy the lower-right two-thirds, upper-left is open sky — deliberately a lot of negative space, nothing to visually "solve," inviting the eye to just sit in the stillness. Blocking: no figures in frame (empty-of-people direction from Doc 05 held strictly). Focal point: the temple base silhouette against sky.

**Frame 2 (Shot 002):** Composition: centered push toward the inscription stone, symmetrical framing — the stone is the exact visual center of the frame by the end of the push, giving it unambiguous focal weight before we cut. Blocking: N/A (no figures).

**Frame 3 (Shot 003):** Composition: low-angle close on carving hands, stone dust catching a hard light shaft from upper-left — chiaroscuro-leaning contrast, deliberately more visually alive than Frames 1–2 to sell the "we've jumped backward in time and the world has color again" feeling without a single word of exposition. Blocking: hands only, lower-frame, tool/stone upper-frame.

**Frame 4 (Shot 004):** Composition: wide establishing, temple tower positioned at the classical "golden hour reveal" upper-third position, city sprawling below in the lower two-thirds, crane movement means this frame is really a short sequence of compositions rather than one static frame — concept artist should provide start/mid/end frames for the crane move. Blocking: ambient population visible but not individually composed (crowd-as-texture, not crowd-as-subject, at this distance).

---

## CINEMATIC 003 — THE GANGA, Storyboard Frames

**Frame 1 (Shot 001):** Composition: extreme wide, army occupies a thin horizontal band roughly one-fifth up from the bottom of frame — deliberately small against the landscape, the opposite compositional choice from a typical "epic army" reveal shot, which is the entire point. Sky and river dominate. Blocking: army as a distant, undifferentiated mass — no individual figure should read as a "hero shot" here, including Rajendra.

**Frame 2 (Shot 002):** Composition: medium shot, Rajendra positioned off-center (rule of thirds, not centered — centering him would read as a "portrait" moment the scene is deliberately avoiding), seen from behind/three-quarter angle, water occupying the lower half of frame. Blocking: Rajendra alone, no other figures sharing his compositional space — isolation is the point, not grandeur.

**Frame 3 (Shot 003):** Composition: near-abstract close on water over stone, minimal color separation — concept artist should treat this frame almost like a texture study rather than a narrative image; its job is to slow the viewer down, not communicate plot information.

**Frame 4 (Shot 004):** Composition: wide lateral drift, army and horizon both present but neither dominant — a "held breath" composition with roughly equal visual weight given to land, army, and sky, avoiding any single dramatic focal point.

**Frame 5 (Shot 005):** Composition: wide tracking, messenger positioned diagonally across the frame (movement direction reads left-to-right, "toward home," reinforcing the coming "journey home begins" text card before the player reads a word). Blocking: messenger alone, clear foreground/background separation from any other figures to keep him legible as a distinct, purposeful presence rather than part of the army mass.

---

## Storyboard Production Notes (apply to all future frames built from this template)
- Every frame description should specify **where the eye lands first** and **why** — a storyboard note that doesn't answer this isn't finished.
- Blocking notes should distinguish "individually composed figures" from "crowd as texture" explicitly, since concept artists need to know which figures need real design attention vs. which are silhouette/mass work.
- Cross-reference Doc 05's lighting notes for each shot rather than re-specifying lighting here — this document adds composition/blocking only, to avoid the two documents drifting out of sync on lighting direction.

## Open Questions
- Remaining ten cinematics' storyboards should be built once their Doc 05 shot lists finalize (Act 2/5/6/8/9/11, endings 2–3, per Doc 05's own noted dependency on Doc 06 voice-lock).
- Whether full storyboards need real hand-drawn thumbnails alongside these text descriptions, or whether Concept Art can work from text description directly for a project this scoped — Cinematic Director call.

## Dependencies on Other Documents
Doc 05 (source shot lists — hard dependency, this document cannot get ahead of it), Doc 06 (character appearance for blocking accuracy).

## Acceptance Criteria
- Full storyboard-frame treatment (Composition, Blocking, Focal point) for Cinematics 001 and 003, chosen as the highest composition-stakes sequences.
- Every frame description specifies eye-landing point and rationale, per the production note requirement.
- No duplication of Doc 05's camera/lens/movement/lighting/sound specification — this document adds composition/blocking only.


---



<!-- ===== doc29_environment_production_bible.md ===== -->

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


---



<!-- ===== doc30_prop_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 30: PROP BIBLE

**Document ID:** PRB-30 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Prop categories, specs, and production rules.
**Dependencies:** Docs 16, 17, 26, 27
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Prop Categories & Template
Every prop entry: Reference · Historical status · Material · Dimensions · LOD (LOD0–LOD3, Nanite where applicable) · Texture set (2K props / 4K heroes) · Animation · Gameplay usage.

| Category | Representative props | Status | Material | Notes |
|---|---|---|---|---|
| Architecture | scaffolding poles/lashings, stone blocks (raw/dressed/carved), sluice gates, lamps niches | [PLAUSIBLE RECONSTRUCTION]/[DOCUMENTED] | granite, timber, rope | Stone blocks in 3 completion states for Zone 5→6 swap |
| Temple | oil lamps, offering vessels, bells | [DOCUMENTED] type | bronze, clay | Religious items: Cultural Consultant review |
| Household | clay pots, mats, grain bins | [PLAUSIBLE RECONSTRUCTION] | clay, fibre | Residential gap (Doc 03 C4) |
| Market | stalls, scales, awnings, textiles | [PLAUSIBLE RECONSTRUCTION] | timber, cloth | |
| Military | spears, shields, camp gear | [PLAUSIBLE RECONSTRUCTION] (Doc 03 I1/I3) | wood, iron, hide | |
| Craft | moulds, crucibles, chisels, rollers | [DOCUMENTED] technique | clay, bronze, stone | Lost-wax steps need dedicated props |
| Agriculture | tools, irrigation baskets | [PLAUSIBLE RECONSTRUCTION] | wood | |
| Navigation | star-sight boards, rope, models | [PLAUSIBLE RECONSTRUCTION] | wood, cord | Doc 03 E4 gap |
| Writing | stylus, palm-leaf bundles, stone tablets | [DOCUMENTED] general practice | palm leaf, stone | No fabricated inscription text |
| Royal | seals, regalia | [PLAUSIBLE RECONSTRUCTION] | metal | Gold as accent only |
| Religious | lamps, ritual vessels | [DOCUMENTED] type | bronze | Consultant review |
| Trade | cargo bales, jars, ledgers | [PLAUSIBLE RECONSTRUCTION] | various | |

**Rules:** props look used; wear states follow Doc 17 §3 (bronze patina vs new-cast); every artifact-class prop classified per Doc 27.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc31_character_art_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 31: CHARACTER ART BIBLE

**Document ID:** CAB-31 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Per-character art specification.
**Dependencies:** Docs 06, 17 §1/§11/§12
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Constraint
Sculptural sources are stylized (Doc 03 G3). Clothing/jewelry **must pass Cultural Sensitivity Consultant review before asset production**. No stereotypical fantasy-Indian design.

| Character | Face/Body | Hair | Clothing & Materials | Jewelry | Colors | Animation style |
|---|---|---|---|---|---|---|
| Rajendra I | Mature, composed; period sculpture conventions | Per period royal convention (to be researched) | Royal court dress; restrained | Regalia with accent gold | Deep red/earth + sparing gold | Economical, formal |
| Arulan | Early 20s, lean, observant | Practical | Evolves: court-adjacent → campaign → site practical | Minimal | Muted earth | Naturalistic, mid-athletic |
| Scholar | 50s, weathered | Grey-touched | Scribal/administrative, fieldwork wear | None/minimal | Faded cotton tones | Careful hand-work |
| Architect | 40s, sturdy | Practical | Craftsman/engineer, tool belt | Minimal | Stone dust tones | Demonstrative gestures |
| Naval Commander | 30s–40s, sun-weathered | Practical | Maritime dress | Minimal | Sea-faded | Sea-legs gait |
| Merchant | 40s | Neat | Fine but restrained textiles | Moderate (guild status) | Rich muted | Negotiation gestures |
| Artisan | 30s, burn scars/tool-worn hands | Practical | Craft dress | None | Soot/bronze | Detailed craft anims |
| Antagonist | 40s–50s, understated | Tidy | Senior official, restrained | Modest | Dark neutral (not villain-coded) | Controlled, minimal |
| Political Rival | 30s | Polished | Sharper court styling | More ornate | Brighter accents | Practiced performance |
| Messenger | 20s | Road-worn | Courier dress + insignia | None | Dust/travel | Riding/dismount set |

Pipeline: MetaHuman base where appropriate, custom grooms; LOD chain; cloth sim for long garments with performance budget per Doc 18.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc32_animation_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 32: ANIMATION BIBLE

**Document ID:** AB-32 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Animation requirements and technical approach.
**Dependencies:** Docs 06, 10, 11, 13, 18
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Requirements
- **Locomotion:** walk/run/sprint/crouch, slopes, scaffolding traverse, climb, swim; Motion Matching candidate; foot IK on uneven stone/scaffold.
- **Interaction:** scan/read inscription, handle documents, craft (casting, carving), trade, write (stylus), temple activities (period-appropriate, consultant-reviewed), ship work (rigging, rowing, steering).
- **Combat:** sword-and-shield, spear, bow, dagger takedown, block/parry/dodge, hit reactions (grounded — no superhuman flips); GAS-driven montages (Doc 18).
- **Facial:** MetaHuman facial rig; dialogue close-ups need lip-sync for Tamil primary track (+ subtitle-synced English not re-animated).
- **Cinematic:** Sequencer-driven, per Doc 05/28; restraint on Rajendra (economical gesture).
- **NPC:** Tier 1 full sets; Tier 2 shared sets with variation; Tier 3 Mass Entity crowd anim (instanced, few clips + procedural variation).
- **Animation direction per character:** see Doc 06 fields (Messenger riding set, Artisan hand-craft set, Naval Commander sea-legs).
- **Budget flags:** mounted combat anims scripted-only (Doc 10 §10).


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc33_vfx_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 33: VFX BIBLE

**Document ID:** VFX-33 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Historically appropriate effects list (Niagara).
**Dependencies:** Docs 17, 21, 34
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

| Effect | Use | Notes / Constraint |
|---|---|---|
| Water | river, reservoir flow (Lion Well feedback), rain splashes | Flow must be legible for puzzle; colorblind-safe |
| Dust / stone dust | construction zone | Drives light shafts; key to "under construction" look |
| Fire / lamp flame | oil lamps, forges | Motivated light only |
| Smoke | forges, cooking, camps | Subtle |
| Rain / monsoon | seasonal weather | Distinct wet-season mood (Doc 17 §6) |
| Wind | vegetation/cloth | Ambient |
| Metal sparks | bronze work, weapon impact | Small, grounded |
| Battle effects | hit sparks, dust kicks | No fantasy bursts/magic |
| Ship effects | spray, wake, sail motion | Physical only |
| Ganga scene | none beyond water/atmosphere | Restraint is the effect (Doc 05 C003) |

**Rule:** no glowing/mystical VFX anywhere; "emotional" moments are sold via composition and sound.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc34_lighting_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 34: LIGHTING BIBLE

**Document ID:** LB-34 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Physically plausible lighting per time/condition.
**Dependencies:** Docs 17 §5, 21, 29, UE5 Lumen
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

| Condition | Direction |
|---|---|
| Dawn | Low warm directional; mist; golden temple tops (Cinematic 001/002) |
| Morning | Clean warm light; crisp stone shadows |
| Noon | Harsh, high contrast; dust haze; shaded interiors by contrast |
| Afternoon | Warm, lengthening shadows |
| Sunset | Strong gold accent on temple silhouette; used for earned reveals |
| Night | Oil lamps, torches, moonlight; all sources in-world; stealth readability (Doc 11) |
| Monsoon | Soft diffuse, cool, desaturated; rain-slick stone |
| Storm | Dark volume, wind-driven rain; naval MQ25 |
| Temple interior | Lamp-lit; deep falloff; sanctum warmth |
| Royal court | Filtered courtyard light + lamps |
| Market | Open-sky daylight with awning bounce |
| Forest | Dappled canopy, green bounce |
| Ship | Open sea light; lantern at night |
| **Ganga (Act 4)** | **Flat overcast — deliberate** |

Technical: Lumen GI with hardware RT optional; baked fallback for low-spec; every light source must be motivated.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc35_quest_flowchart.md ===== -->

# GANGAIKONDA — DOCUMENT 35: QUEST FLOWCHART

**Document ID:** QF-35 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Dependency map for main quest spine and branching.
**Dependencies:** Docs 04, 07a–f
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout; nothing here upgrades the confidence of any Doc 03 entry.

---

## Main Spine
```
MQ01 → MQ02 → MQ03 → MQ04
→ MQ05 → MQ06 → MQ07 → MQ08 (Ganga) → MQ09 → MQ10 (Decree)
→ MQ11 → MQ12 → MQ13 (conspiracy seed)
→ MQ14 → MQ15
→ MQ16 → MQ17 (Hidden Inscription)
→ MQ18 → MQ19 (Contradiction) → MQ20 (Ambush)
→ MQ21 → MQ22 (Rival offer; major branch)
→ MQ23 → MQ24 → MQ25
→ MQ26 → MQ27 (Reckoning; major branch) → MQ28 → MQ29 (Last Stone) → MQ30 (Epilogue)
```
## Cross-Dependencies (examples)
- MQ13 → SA05 → SA07 → MQ19 evidence quality
- MQ12 supplier choice → MQ19 ledger clue
- SQ09 (witness) → MQ27 evidence options
- HD03 (praśasti) recommended before/at Act 3 labels
- NQ01 → NQ05; NQ02 → NQ03 tone
- MQ17 → HD04, PQ06
- SA08/SA10 + MQ22/27/28 flags → ending variant (Builder / Investigator / Quiet)

## Ending Flag Weights (to tune)
Relationship flags (Architect/Scholar), MQ22 choice, MQ27 resolution, SA03/05/08 choices. History never changes.


---

## Open Questions
See individual items flagged above; this condensed draft should be expanded by the owning department lead before content lock.

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–29.
- No fictional element presented as documented history.


---



<!-- ===== doc36_save_load_design.md ===== -->

# GANGAIKONDA — DOCUMENT 36: SAVE / LOAD DESIGN

**Document ID:** SLD-36 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Save architecture and behaviour.
**Dependencies:** Doc 18 §6 (authoritative schema), Doc 19
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Saved State
Quest progress · character state · inventory · world state (construction progress) · NPC relationships/memory flags · Codex unlocks · discovered locations · puzzle states · faction reputation · ship state.

## Behaviour
- **Autosave:** on quest-state change, major location transition, after puzzle solves, before/after set-piece combat. Rolling 3 slots.
- **Manual save:** any non-combat, non-cinematic moment; unlimited slots; metadata = act, location, playtime, evidence-tier of latest Codex entry.
- **Load:** world-state restored via `UGKWorldStateSubsystem`; Tier 3 crowds regenerate from schedule seed (not serialized individually).
- **Versioning:** save schema version + migration table; Codex stored as EvidenceID set (content updates don't break saves).
- **Edge cases:** save during dialogue → resume at node; ship at sea → state + position; corrupted save → fallback to previous autosave.
- **Risk:** NPC memory/world-state serialization cost at living-city density — technical spike before slice lock (Doc 18).


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc37_accessibility_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 37: ACCESSIBILITY BIBLE

**Document ID:** ACC-37 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Accessibility feature requirements.
**Dependencies:** Docs 01 §28–29, 20
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

| Area | Requirement |
|---|---|
| Subtitles | On by default for Tamil/other VO; speaker names; background panel option |
| Subtitle size | 4+ sizes; high-contrast option |
| Color-blind | Codex tiers use border + text, never color alone; flow/puzzle indicators have shape alternatives; presets (protan/deutan/tritan) |
| High contrast | UI and interactable highlight mode |
| Controller remapping | Full remap, hold/toggle alternatives |
| Difficulty | Combat/stealth sliders; puzzle *hint depth* (not trivialization) |
| Puzzle hints | 3 tiers + skip-with-explanation option; every puzzle has accessibility alternative (Doc 09) |
| Navigation assistance | Optional objective guidance; diegetic default |
| Audio controls | Separate sliders: music, ambience, VO, SFX; mono; visual cues for key sounds |
| Motion reduction | Reduced camera sway/FOV effects; cinematic motion options |
| Combat assistance | Wider parry window, auto-block option, stamina assist |
| Text scaling | UI-wide scaling incl. Codex |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc38_qa_test_plan.md ===== -->

# GANGAIKONDA — DOCUMENT 38: QA TEST PLAN

**Document ID:** QA-38 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Test categories and test-case template.
**Dependencies:** Docs 18, 37, 39
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Test Case Template
Test ID · Description · Steps · Expected result · Actual result · Severity (S1–S4) · Status

## Categories & Representative Tests
| ID | Category | Description | Expected |
|---|---|---|---|
| F-001 | Functional | Boot, menus, settings persist | No crash; settings saved |
| G-001 | Gameplay | Complete MQ01–MQ04 | Quest flags advance; no soft-lock |
| C-001 | Combat | Parry timing window | Window consistent; stagger applies |
| Q-001 | Quest | Skip optional scan in MQ13 → MQ19 | Main quest still completable (Doc 01 §14) |
| P-001 | Puzzle | Lion Well all gate permutations | Only valid sequence solves; reset works |
| AI-001 | AI | Tier 1 NPC schedule over 24h cycle | Correct locations/time; memory flag respected |
| AN-001 | Animation | Scaffold climb IK | No foot sliding/clipping |
| AU-001 | Audio | Ganga scene mix | Near-silent bed, no music pops |
| UI-001 | UI | Codex border by evidence tier | Correct style + text label |
| PF-001 | Performance | Zone 5/6 NPC density | Target fps (Doc 01 §35) |
| SL-001 | Save/Load | Save mid-dialogue, load | Resume at node |
| L-001 | Localization | Tamil/English subtitle sync, glyph rendering | No tofu/overflow |
| H-001 | Historical accuracy | Every Codex entry vs Doc 03 | Tier matches; PASS (see Doc 39) |
| CR-001 | Cultural review | Temple/religious content | Consultant sign-off |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc39_historical_authenticity_qa.md ===== -->

# GANGAIKONDA — DOCUMENT 39: HISTORICAL AUTHENTICITY QA

**Document ID:** HAQ-39 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Pre-release audit protocol (release-blocking).
**Dependencies:** Docs 03, 23, 27
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Audit Scope
Every dialogue · quest · character · building · weapon · ship · inscription · political claim · cultural claim.

## Verdicts
**PASS** · **RESEARCH REQUIRED** · **FICTIONALIZED** (correctly labelled) · **REMOVE**

## Procedure
1. Export all player-facing text + asset manifest.
2. Map each historical claim to a Doc 03 ID; unmapped → RESEARCH REQUIRED.
3. Verify evidence tag + confidence tier shown to player equals Doc 03 (no upgrading).
4. Check hard rules: no fabricated quotes; no fabricated inscriptions; no fictional architecture labelled archaeological fact; no fictional characters presented as historical; no modern interpretation used as ancient source.
5. Consultant sign-off (Historical Authenticity + Cultural Sensitivity).
6. Release gate: zero unresolved RESEARCH REQUIRED/REMOVE.

## Known Open Items to Clear
Doc 03 E4 (ships), I3 (armor), C4 (city layout), festival content (unsourced), clothing/material culture, Sanskrit approved contexts.


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc40_localization_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 40: LOCALIZATION BIBLE

**Document ID:** LOC-40 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Language scope and terminology rules.
**Dependencies:** Docs 22, 23
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Languages
Tamil (primary VO) · Sanskrit (restricted contexts) · English (default UI/subtitles) · Hindi (localized UI/subtitles).

## Rules
- **Proper nouns:** canonical transliteration table (Tamil→Latin, Devanagari title "गङ्गैकोण्ड"); one spelling per name.
- **Titles/historical terms:** glossary maintained with linguists; no mechanical translation of sacred/historical terminology.
- **Place names:** historical vs modern names listed with usage rule.
- **Codex:** highest-risk text — native-speaker historian review per language.
- **Sanskrit:** only from Historical Authenticity Consultant's approved-context list.
- **Pipeline:** string tables keyed by ID; context notes + screenshots for translators; pseudo-loc for UI overflow; font coverage for Tamil/Devanagari.
- **Blocker:** character-name authenticity review (Doc 06).


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc41_marketing_bible.md ===== -->

# GANGAIKONDA — DOCUMENT 41: MARKETING BIBLE

**Document ID:** MKT-41 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Positioning and copy.
**Dependencies:** Docs 01, 23, 42
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

**Positioning line (required):** *Historically grounded historical fiction.* Never claim "everything is historically exact."

**Game description (short):** Walk through an intelligently reconstructed 11th-century Chola world as Arulan, a fictional witness to the founding of Gangaikondacholapuram. Investigate inscriptions, solve craft-based puzzles, navigate court politics, and learn exactly what is documented, what is reconstructed, and what is invented.

**Steam description (outline):** pillars (evidence-honest Codex, craft puzzles, living capital under construction) + disclaimer paragraph.
**Website copy:** "Stone remembers." + research/consultant transparency page.
**Announcement:** teaser + Codex philosophy.
**Dev diary / social:** weekly "Documented / Reconstructed / Fictional" posts.
**Press kit:** logo, key art, fact sheet incl. evidence-category explainer.
**Key art direction:** temple silhouette at dusk, Arulan small in frame; gold only as accent.
**Logo direction:** carved-stone wordmark with Devanagari/Tamil secondary lockup; tagline "An Empire Is Remembered. A Legacy Is Built."


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc42_trailer_scripts.md ===== -->

# GANGAIKONDA — DOCUMENT 42: TRAILER SCRIPTS

**Document ID:** TS-42 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Four trailer cuts.
**Dependencies:** Docs 05, 41
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## 30s Teaser
Black, chisel on stone → hand on inscription → temple silhouette → title **GANGAIKONDA** → tagline.

## 60s Announcement
Mystery (inscription) → world (Thanjavur dawn) → Arulan → conflict (ledger discrepancy) → puzzle (stone alignment) → temple reveal → title + tagline. VO: "They say an empire is remembered in stone."

## 90s Gameplay
World → character → conflict → gameplay montage (investigation, water puzzle, stealth) → combat flash → naval sequence → Ganga restraint beat → temple reveal → title.

## 3-min Story Trailer
Mystery (0:00) → World (0:20) → Character (0:50) → Conflict: antagonist's persuasive line (1:15) → Gameplay (1:30) → Puzzle (1:50) → Combat (2:05) → Naval (2:20) → Temple reveal (2:35) → Title (2:50): **GANGAIKONDA** — *"An Empire Is Remembered. A Legacy Is Built."* End card: "Historically grounded historical fiction."

Rule: no invented quotes attributed to Rajendra; on-screen "inspired by" labels where reconstruction shown.


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc43_developer_diary_series.md ===== -->

# GANGAIKONDA — DOCUMENT 43: DEVELOPER DIARY SERIES

**Document ID:** DDS-43 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** 12 episode outlines.
**Dependencies:** Docs 03–21
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

| Ep | Topic | Content outline |
|---|---|---|
| 1 | Historical Research | How the evidence database works; documented vs reconstructed vs fictional |
| 2 | Rajendra Chola | What inscriptions tell us; why we never invent his quotes |
| 3 | Gangaikondacholapuram | Site, founding, what survives |
| 4 | Temple Architecture | Dravidian construction; Stone Alignment puzzle design |
| 5 | Water Engineering | Reservoir tradition vs fact; Lion Well |
| 6 | Inscriptions | Praśasti genre; decoding system; Scholar |
| 7 | Characters | Arulan, Scholar, Antagonist's non-villain design |
| 8 | World Building | Living-city tiers; Zone 5→6 transition |
| 9 | Combat | Grounded combat; why no sieges/damage numbers |
| 10 | Naval System | Evidence gap on ships, handled openly |
| 11 | Audio | Restraint; Ganga silence; original score |
| 12 | Building the Vertical Slice | Proof points and lessons |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc44_production_roadmap.md ===== -->

# GANGAIKONDA — DOCUMENT 44: PRODUCTION ROADMAP

**Document ID:** PR-44 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Phase plan with gates (durations indicative for a ~100–150 person AAA team).
**Dependencies:** Docs 18, 45, 46, 47
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

| Phase | Duration | Team | Deliverables | Milestone / Acceptance | Key Risks |
|---|---|---|---|---|---|
| Pre-production | 6–9 mo | Leads + research + small design/tech | Docs 01–50 baseline, evidence DB v1, tech spikes (Mass Entity, save, world-state swap) | Consultant sign-off on DB; spikes pass | Evidence gaps (E4/I3/C4) |
| Prototype | 4–6 mo | Core gameplay + tools | Movement, scan/investigation, 1 puzzle, Codex | Fun/clarity of investigation loop | Puzzle appeal |
| Vertical Slice | 6–9 mo | Cross-discipline | 40-min slice (Doc 08/47) | Meets 10 proof points; external playtest | Scope creep |
| Alpha | 12–18 mo | Full | All systems, blockout content, first-pass quests | Feature complete | Open-world complexity |
| Beta | 8–12 mo | Full + QA | Content complete, VO, localization | Content complete | Voice/loc schedule |
| Content Complete | — | — | All quests/puzzles/cinematics | Freeze | |
| Polish | 4–6 mo | Full | Perf, audio mix, VFX, lighting | Perf targets | |
| QA | 4–6 mo | QA + vendors | Test plan Doc 38 | S1/S2 zero | |
| Historical Review | 2–3 mo | Consultants | Doc 39 audit | Zero RESEARCH REQUIRED/REMOVE | Late research findings |
| Release | — | — | Gold + launch | | |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc45_team_structure.md ===== -->

# GANGAIKONDA — DOCUMENT 45: TEAM STRUCTURE

**Document ID:** TS-45 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Departments and approval authority.
**Dependencies:** Docs 44, 46
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

| Dept | Lead | Responsibilities | Deliverables | Dependencies | Approval Authority |
|---|---|---|---|---|---|
| Leadership | Creative Director / Exec Producer | Vision, budget | Vision docs | All | Final creative/budget |
| Research | Historical Research Director + Consultants | Evidence DB, audits | Doc 03, 39 | Narrative, Art | **Veto on historical claims** |
| Narrative | Narrative Director | Story, dialogue | Docs 04–07, 22 | Research | Story/dialogue |
| Design | Game Director/Lead Designer | Systems, quests, puzzles | Docs 01, 07, 09–15, 24–26 | Eng | Gameplay |
| Engineering | Technical Director | Architecture, tools | Docs 18–19, 36 | Design | Technical |
| Art | Art Director | Env/char/props/VFX/lighting | Docs 16–17, 29–34 | Research (clothing) | Visual |
| Animation | Animation Director | Anim systems | Doc 32 | Art, Eng | Animation |
| Audio | Audio/Music Director | Sound/music | Doc 21 | Narrative | Audio |
| Cinematics | Cinematic Director | Cutscenes | Docs 05, 28 | Narrative, Art | Cinematic |
| QA | QA Director | Test + release gates | Docs 38, 49 | All | Ship-readiness |
| Localization | Localization Director | Language pipeline | Doc 40 | Narrative | Loc quality |
| Production | Production Manager | Schedule/risk | Docs 44, 46 | All | Schedule |
| Marketing | Marketing Director | Positioning | Docs 41–43 | Research | Messaging accuracy sign-off by Research |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc46_risk_register.md ===== -->

# GANGAIKONDA — DOCUMENT 46: RISK REGISTER

**Document ID:** RR-46 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Project risks and mitigations.
**Dependencies:** Docs 18, 44
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

| Risk | Prob | Impact | Mitigation | Owner | Contingency |
|---|---|---|---|---|---|
| Historical inaccuracy | M | H | DB-driven content; Doc 39 gate; consultant veto | Research Dir | Cut/relabel content |
| Cultural inaccuracy | M | H | Early consultant review (clothing, religious audio) | Cultural Consultant | Replace assets |
| Scope creep | H | H | Vertical slice gate; defer open-world filler | Producer | Cut side content |
| Open-world complexity | M | H | Hub-based world; World Partition spikes | Tech Dir | Reduce zone count |
| Performance (living city) | H | H | Tier model; Mass Entity; early profiling | Tech Dir | Lower density |
| AI complexity | M | M | Bounded memory; templates | AI Lead | Simplify Tier 2 |
| Naval mechanics | M | M | Reuse systems; scripted set-pieces | Design | Reduce naval scope |
| Puzzle complexity/appeal | M | M | Playtest-driven; hint tiers | Puzzle Lead | Cut variants |
| Asset production volume | H | M | Modular kits; reuse | Art Dir | Outsource |
| Voice production | M | M | Early casting; Tamil VO pipeline | Voice Dir | Reduce VO scope |
| Localization | M | M | Early glossary; pseudo-loc | Loc Dir | Delay languages |
| Legal/IP | L | H | Original IP; IP review of any museum references | Legal | Remove references |
| Schedule | H | H | Phase gates | Producer | Re-scope |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc47_vertical_slice_production_plan.md ===== -->

# GANGAIKONDA — DOCUMENT 47: VERTICAL SLICE PRODUCTION PLAN

**Document ID:** VSP-47 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** What to build, in what order.
**Dependencies:** Docs 08, 44
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Scope (only Zone 5 construction zone)
Required systems: third-person movement · NPC AI (Tier 1–3 minimal) · dialogue · one combat encounter · one stealth sequence · one inscription · one puzzle (+ water system) · one temple environment · one Codex entry · one cinematic.

## Build Order
1. Greybox Zone 5 + traversal  2. Scan/inscription + Codex pipeline (DT_HistoricalEvidence)  3. Dialogue + NPC schedule (Tier 1/3)  4. Stone Alignment T1 + Lion Well stages 1–4  5. Investigation (ledger/seal)  6. Combat/stealth encounter  7. Cinematic  8. Art pass/Lumen/Nanite  9. Audio  10. Polish + internal review.

## Exit Criteria
All 10 proof points demonstrated; stable frame target; Historical Authenticity spot audit on slice content; external playtest feedback on investigation clarity. **No open-world production before this passes.**


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc48_asset_production_tracker.md ===== -->

# GANGAIKONDA — DOCUMENT 48: ASSET PRODUCTION TRACKER

**Document ID:** APT-48 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Tracker schema + seed rows.
**Dependencies:** Docs 27, 29, 30
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Schema
Asset ID · Asset · Category · Historical status · Reference · Artist · Priority (P0–P3) · LOD · Texture · Rig · Animation · Status · Review · Approval

## Seed Rows
| ID | Asset | Cat | Hist. status | Ref | Priority | LOD | Tex | Rig | Anim | Status | Review |
|---|---|---|---|---|---|---|---|---|---|---|---|
| ENV-0001 | Temple platform (Zone 5) | Env | [DOCUMENTED]/[FICTIONAL] stage | Doc 16 §1 | P0 | Nanite | 4K | – | – | Not started | Hist. + Art |
| ENV-0002 | Scaffolding kit | Env | [PLAUSIBLE] | Doc 29 Kit B | P0 | LOD0–3 | 2K | – | – | Not started | Art |
| PRP-0001 | Granite blocks (3 states) | Prop | [PLAUSIBLE] | Doc 30 | P0 | Nanite | 2K | – | – | Not started | Art |
| CHR-0001 | Arulan | Char | [FICTIONAL] | Doc 31 | P0 | LOD0–4 | 4K | Full | Full | Not started | Art + Cultural |
| CHR-0002 | Scholar | Char | [FICTIONAL] | Doc 31 | P0 | LOD0–4 | 4K | Full | Full | Not started | Art + Cultural |
| ART-0001 | Inscription stone (fictional text) | Prop | [FICTIONAL] | Doc 27 | P0 | LOD0–2 | 4K | – | – | Not started | Hist. |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---



<!-- ===== doc49_bug_database.md ===== -->

# GANGAIKONDA — DOCUMENT 49: BUG DATABASE

**Document ID:** BUG-49 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Bug schema and process.
**Dependencies:** Doc 38
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Schema
Bug ID · System · Description · Reproduction · Severity (S1 crash/blocker … S4 cosmetic) · Priority (P0–P3) · Assigned developer · Status · Build · Fix · Regression test ID

## Special Categories
- **HIST** — historical-accuracy defects (always S2+ if player-facing claim wrong)
- **CULT** — cultural-review defects
- **LOC** — localization defects

## Seed Entry
| BUG-0001 | Codex | Entry tier shows DOCUMENTED when Doc 03 says UNCERTAIN | Unlock entry X | S2 | P1 | Unassigned | Open | – | – | H-001 |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.


---

