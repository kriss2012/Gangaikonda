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
