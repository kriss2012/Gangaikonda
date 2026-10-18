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
