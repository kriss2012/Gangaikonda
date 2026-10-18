# GANGAIKONDA — DOCUMENT 36: SAVE / LOAD DESIGN

**Document ID:** SLD-36 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Save architecture and behaviour.
**Dependencies:** Doc 18 §6 (authoritative schema), Doc 19
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Saved State
Quest progress · character state · inventory · world state (construction progress) · NPC relationships/memory flags · Codex unlocks · discovered locations · puzzle states · faction reputation · ship state.

## Behaviour
- **Autosave:** on quest-state change, major location transition, after puzzle solves, before/after set-piece combat. Rolling 3 slots.
- **Manual save:** any non-combat, non-cinematic moment; unlimited slots; metadata = act, location, playtime, evidence-tier of latest Codex entry.
- **Load:** world-state restored via `UGKWorldStateSubsystem`; Tier 3 crowds regenerate from schedule seed (not serialized individually).
- **Versioning:** save schema version + migration table; Codex stored as EvidenceID set (content updates don't break saves).
- **Edge cases:** save during dialogue → resume at node; ship at sea → state + position; corrupted save → fallback to previous autosave.
- **Risk:** NPC memory/world-state serialization cost at living-city density — technical spike before slice lock (Doc 18).


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.
