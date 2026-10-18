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
