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
