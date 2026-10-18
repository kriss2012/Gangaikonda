# GANGAIKONDA — Unreal Engine 5 Project

**"An Empire Is Remembered. A Legacy Is Built."**

Single-player historical action-adventure set in the Chola Empire under Rajendra Chola I, centered on the founding of Gangaikondacholapuram.

---

## 1. Project Overview & Hard Rules

### Hard Rules (Never Violate)
1. **Evidence Categorization:** Every historical claim in data or UI carries an evidence category (`Documented`, `PlausibleReconstruction`, `Fictional`) and confidence tier (`Known`, `Likely`, `Uncertain`, `Unknown`).
2. **Authenticity of Inscriptions:** Never fabricate inscriptions, historical quotations, or evidence. Placeholder text must be visibly marked `[PLACEHOLDER – FICTIONAL]`.
3. **Historical Attribution:** Never attribute invented dialogue to Rajendra Chola I as an authentic quote.
4. **No Tier Elevation:** Never upgrade a confidence tier when moving data from the research database to the Codex.
5. **No Fantasy Mechanics:** No fantasy elements, no magic VFX, no modern combat mechanics, no floating damage numbers, no numeric RPG stat leveling.
6. **Data-Driven History:** Historical content lives in Data Tables (`DT_HistoricalEvidence`), never hardcoded strings.
7. **Single-Player Only:** No networking code.

---

## 2. Architecture & Module Structure

The project employs a clean, modular architecture across 14 dedicated C++ runtime modules (`GK` prefix):

```
Source/
├── GKCore        — Shared types, enums (EGKEvidenceCategory, EGKConfidence), interfaces, logging
├── GKCodex       — UGKCodexSubsystem, DT_HistoricalEvidence access, no-upgrade UI model
├── GKCharacter   — AGKCharacterBase, Arulan locomotion, NPC base classes
├── GKCombat      — UGKCombatComponent (GAS-integrated, grounded stamina-based)
├── GKExploration — Traversal, scaffold climbing, scan/interact
├── GKPuzzle      — AGKPuzzleActor, IGKPuzzleInterface, load-path & hydraulic puzzles
├── GKQuest       — UGKQuestSubsystem, quest state machine (DA_Quest_*)
├── GKDialogue    — UGKDialogueComponent, branching graph runtime, memory hooks
├── GKInventory   — Lightweight narrative/puzzle item inventory
├── GKWorld       — UGKWorldStateSubsystem, construction progress tracking
├── GKAI          — UGKScheduleComponent, Mass Entity processors (Tier 3 crowds)
├── GKSave        — UGKSaveGame, game serialization subsystem
├── GKUI          — UI data-binding ViewModels (UMG Blueprint frontends)
└── GKAudio       — Music/ambience cue event subscribers
```

### Key Interfaces
- `IGKInvestigatable` — Scan mode, inscription/ledger inspection.
- `IGKPuzzleInterface` — Generic puzzle lifecycle (`GetPuzzleState`, `AttemptSolve`, `ResetPuzzle`, `GetPuzzleHint`).
- `IGKMemoryHolder` — Bounded per-NPC memory flags (`GetMemoryFlag`, `SetMemoryFlag`).

### Module Logging Categories
- `LogGKCore`
- `LogGKCharacter`
- `LogGKCombat`
- `LogGKExploration`
- `LogGKPuzzle`
- `LogGKQuest`
- `LogGKDialogue`
- `LogGKInventory`
- `LogGKCodex`
- `LogGKWorld`
- `LogGKAI`
- `LogGKSave`
- `LogGKUI`
- `LogGKAudio`

---

## 3. Build & Setup Instructions

### Prerequisites
- **Unreal Engine 5.4+**
- **Visual Studio 2022** (v143 toolset with C++ Game Development workload) or **JetBrains Rider**
- Plugins enabled: Enhanced Input, Gameplay Abilities, Mass Entity, ModelViewViewModel

### Setup Steps
1. Right-click `Gangaikonda.uproject` and select **Generate Visual Studio project files**.
2. Open `Gangaikonda.sln` in Visual Studio or Rider.
3. Select `Development Editor` configuration and `Win64` platform.
4. Build the solution (`Ctrl+Shift+B`). Zero warnings policy is enforced.
5. Launch the editor via `Gangaikonda.uproject` or by debugging in IDE.

---

## 4. Production Status (Vertical Slice)

- [x] **STEP 0 — Skeleton & standards:** Module configuration, folder structure, logging categories, coding standards, `.editorconfig`, build targets, README.
- [x] **STEP 1 — Evidence/Codex backbone:** `FGKEvidenceRow`, `DT_HistoricalEvidence` + CSV importer, `UGKCodexSubsystem`, unit tests for the no-upgrade rule.
- [x] **STEP 2 — Character & exploration:** Arulan 3rd person locomotion, scaffold climbing, interaction prompt, greybox test map Zone 5.
- [ ] **STEP 3 — Investigation & inscription system:** Inscription decoding Tier 1, reference chart, historical record notification.
- [ ] **STEP 4 — Dialogue & memory:** Branching runtime, bounded memory flags, Scholar & Architect dialogue.
- [ ] **STEP 5 — Quest subsystem:** Quest state machine, objectives, slice beats 1–13.
- [ ] **STEP 6 — Puzzles:** Stone Alignment T1 & Lion Well 1–4.
- [ ] **STEP 7 — NPC living world:** Schedules, Mass Entity crowds.
- [ ] **STEP 8 — Stealth & combat encounter:** Suspicion states, sword/shield/parry/dodge, no damage numbers.
- [ ] **STEP 9 — World state & save:** `UGKSaveGame`, construction flags.
- [ ] **STEP 10 — UI/UX pass:** Minimal HUD, Codex border styling + text labels.
- [ ] **STEP 11 — Cinematic & audio hooks:** Sequencer hooks, ambient soundscapes.
- [ ] **STEP 12 — Art/lighting/perf pass:** Nanite/Lumen, 30/60 fps targets.
- [ ] **STEP 13 — QA & historical audit:** Doc 38/39 compliance, verification of all claims against Doc 03.
