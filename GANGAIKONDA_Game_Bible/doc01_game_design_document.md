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
