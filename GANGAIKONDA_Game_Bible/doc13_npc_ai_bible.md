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
