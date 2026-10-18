# GANGAIKONDA — DOCUMENT 38: QA TEST PLAN

**Document ID:** QA-38 · **Version:** 1.0 (condensed working draft) · **Status:** Draft for review
**Purpose:** Test categories and test-case template.
**Dependencies:** Docs 18, 37, 39
**Evidence tags:** [DOCUMENTED] / [PLAUSIBLE RECONSTRUCTION] / [FICTIONAL] apply throughout.

---

## Test Case Template
Test ID · Description · Steps · Expected result · Actual result · Severity (S1–S4) · Status

## Categories & Representative Tests
| ID | Category | Description | Expected |
|---|---|---|---|
| F-001 | Functional | Boot, menus, settings persist | No crash; settings saved |
| G-001 | Gameplay | Complete MQ01–MQ04 | Quest flags advance; no soft-lock |
| C-001 | Combat | Parry timing window | Window consistent; stagger applies |
| Q-001 | Quest | Skip optional scan in MQ13 → MQ19 | Main quest still completable (Doc 01 §14) |
| P-001 | Puzzle | Lion Well all gate permutations | Only valid sequence solves; reset works |
| AI-001 | AI | Tier 1 NPC schedule over 24h cycle | Correct locations/time; memory flag respected |
| AN-001 | Animation | Scaffold climb IK | No foot sliding/clipping |
| AU-001 | Audio | Ganga scene mix | Near-silent bed, no music pops |
| UI-001 | UI | Codex border by evidence tier | Correct style + text label |
| PF-001 | Performance | Zone 5/6 NPC density | Target fps (Doc 01 §35) |
| SL-001 | Save/Load | Save mid-dialogue, load | Resume at node |
| L-001 | Localization | Tamil/English subtitle sync, glyph rendering | No tofu/overflow |
| H-001 | Historical accuracy | Every Codex entry vs Doc 03 | Tier matches; PASS (see Doc 39) |
| CR-001 | Cultural review | Temple/religious content | Consultant sign-off |


---

## Acceptance Criteria
- Consistent with Foundation Bible v1 and Docs 01–35.
- No fictional element presented as documented history.
