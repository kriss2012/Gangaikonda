# GANGAIKONDA — DOCUMENT 11: STEALTH & INVESTIGATION BIBLE

**Document ID:** SIB-11 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full specification of the game's two most heavily-used systems — investigation (the primary verb, per Doc 01 §14) and stealth (secondary, social-stealth-weighted per Doc 01 §13).
**Dependencies:** Doc 01 §13–14, Doc 06 (character skills), Doc 07 (quests using these systems extensively — MQ19/20, SA-series, HD-series).

---

## PART A — STEALTH

### 1. Visibility
Line-of-sight based detection, modulated by lighting (ties to Doc 34 Lighting Bible — shadowed areas reduce detection range) and cover (structures, crowds, scaffolding at construction sites).

### 2. Sound
Footstep/action noise attracts NPC attention within a radius modulated by ambient noise level (a busy market masks more sound than a quiet archive at night) — this directly rewards the living-world pillar: the same stealth action is easier or harder depending on time-of-day/location activity level (Doc 01 §25 world simulation).

### 3. NPC Suspicion
Graduated (not binary) suspicion state: **Unaware → Alert → Searching → Hostile**, with a cooldown/de-escalation path if the player breaks line of sight and suspicion isn't confirmed — avoids the frustration of instant-restart stealth failure, consistent with the game's generally non-punitive failure-state philosophy (Doc 01 §14 investigation failure states).

### 4. Disguises
Period-appropriate role-based disguises (worker's dress, scribe's dress, merchant's dress) grant contextual access rather than full invisibility — a disguise gets Arulan into a restricted area without automatic suspicion, but behaving inconsistently with the role (running, entering off-limits sub-areas) still raises suspicion. This keeps disguises a narrative/access tool rather than a stealth-trivializing cheat.

### 5. Social Stealth
Given the capital's population density (living-world pillar), **crowd-blending is as important as line-of-sight stealth** per Doc 01 §13 — moving through market crowds or temple festival gatherings reduces detection range significantly, reflecting a dense urban environment rather than empty patrol corridors typical of stealth games set in isolated environments.

---

## PART B — INVESTIGATION

### 6. Evidence Gathering
Core interaction: scan (inscriptions/documents/objects), observe (environmental storytelling cues), and collect (portable evidence items feeding the Codex/Archive system per Doc 07f).

### 7. Tracking
Environmental tracking (footprints, disturbed materials, cart-wheel ruts) used sparingly — primarily in MQ19/20 (conspiracy investigation, ambush aftermath) rather than as a constant mechanic, keeping it meaningful when it appears.

### 8. Interrogation
Not a forceful "interrogation" system in the crime-thriller sense — consistent with the game's grounded, non-punitive tone, this is dialogue-tree-based questioning with a trust/rapport variable (per Doc 13 NPC memory principle) rather than a pressure meter. SQ09 ("The Reluctant Witness") is the fullest example of this system in practice.

### 9. Document Discovery
Physical documents (ledgers, letters, grants) function alongside inscriptions as evidence — introduced via MQ13's ledger and expanded through the conspiracy thread; document evidence and inscription evidence share the same Codex/confidence-tagging system (Doc 03 format) so the player doesn't need to learn two separate evidence languages.

### 10. Inscription Investigation
The signature system (per your original Act 9 design and HD03/HD08/HD11's full treatment) — scan → decode → compare → cross-reference, mechanically detailed in Production Bible v2 §2.4.

### 11. Witness Systems
NPCs carry persistent memory of what they've witnessed (Doc 13 principle extended specifically to investigation-relevant events) — a witness who saw something relevant to the conspiracy remembers it whether or not the player has discovered that they're a witness yet, so the world doesn't feel like it's waiting for the player to trigger content.

---

## 12. The Investigation Chain (full worked example)

Per your specified chain, worked through using the MQ19 conspiracy thread as the concrete case:

```
DISCOVER INSCRIPTION/DOCUMENT
  → (MQ13: ledger discrepancy noticed)
TRANSLATE / DECODE
  → (Inscription Decoding or document-reading interaction)
CROSS-REFERENCE
  → (SA04: compare against other Archive holdings, surfaces a contradiction)
FIND LOCATION
  → (evidence points to the storage yards)
QUESTION NPC
  → (SQ09: the reluctant witness, or direct site officials)
DISCOVER CONTRADICTION
  → (MQ19: witness account conflicts with official ledger)
INVESTIGATE FURTHER
  → (gather corroborating evidence — Trade Ledger Reconciliation, Royal Seal Verification)
RESOLVE
  → (MQ27: confrontation, evidence-presentation mechanic)
```

**Design rule:** every major investigation thread in the game should be traceable through this exact chain shape — it's the mechanical backbone the Quest Bible's investigation-tagged quests should be checked against during production, not just a one-time illustrative example.

## 13. Failure States (system-wide principle)
Consistent with Doc 01 §14: investigation has no hard failure states. A missed clue narrows later dialogue/evidence options (as documented throughout Doc 07's quest specs) but never soft-locks main-quest completion — per the explicit edge-case requirement in Doc 01 §14, the main quest must remain completable on a reduced-context path.

---

## Open Questions
- Exact suspicion de-escalation timing (§3) needs playtesting tuning, not a fixed number here.
- Whether disguise-inconsistency detection (§4) should be a hard mechanical trigger or a soft narrative one (NPCs commenting but not immediately escalating) — leans soft-narrative for tonal consistency, but needs Game Designer confirmation.

## Dependencies on Other Documents
Doc 01 §13–14, Doc 06 (character skills), Doc 07 (quests exercising this system throughout, especially MQ19/20, SA04/07, HD03/08/11, SQ09), Doc 13 (NPC memory system this leans on heavily), Doc 34 (lighting affects visibility).

## Acceptance Criteria
- Full stealth system (visibility, sound, suspicion, disguise, social stealth) specified.
- Full investigation system (evidence gathering, tracking, interrogation, document discovery, inscription investigation, witness systems) specified.
- Worked investigation-chain example ties directly to an actual quest (MQ19), not a generic hypothetical.
- No hard investigation failure state, consistent with Doc 01.
