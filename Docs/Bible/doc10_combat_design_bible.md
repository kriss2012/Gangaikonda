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
