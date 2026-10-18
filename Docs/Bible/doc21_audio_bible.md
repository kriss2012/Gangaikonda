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
