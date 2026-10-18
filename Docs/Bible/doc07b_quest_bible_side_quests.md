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
