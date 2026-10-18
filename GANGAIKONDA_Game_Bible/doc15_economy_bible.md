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
