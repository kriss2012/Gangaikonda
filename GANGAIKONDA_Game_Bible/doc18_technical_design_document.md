# GANGAIKONDA — DOCUMENT 18: TECHNICAL DESIGN DOCUMENT

**Document ID:** TDD-18 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full engineering architecture specification, expanding Production Bible v2 §6.
**Dependencies:** Doc 01 (all system requirements), Doc 13 (NPC/AI — Mass Entity requirements), Doc 36 (Save/Load — referenced, detailed here as the authoritative source).
**Engine:** Unreal Engine 5. **Multiplayer:** none (Doc 01 §33 decision — no network architecture required).

---

## 1. Module Architecture

Per Doc 01's modular requirement, sixteen top-level modules:

```
Core Gameplay
├── Character          (Arulan locomotion/combat/interaction; NPC shared base)
├── Combat              (Doc 10 systems)
├── Exploration          (movement, climb, swim per Doc 01 §11)
├── Puzzle               (shared puzzle framework, Doc 09/Production Bible v2 §2)
├── Quest                (data-driven quest state machine, Doc 07)
├── Dialogue             (branching dialogue + memory hooks, Doc 01 §19)
├── Inventory            (Doc 01 §20)
├── HistoricalCodex      (own top-level module per Doc 01 §6 — queried by nearly every other module)
├── World                (locations, world-state progression, Doc 02/13 §5)
├── AI                   (Mass Entity-driven NPC behavior, Doc 13)
├── Navigation            (pathfinding, EQS)
├── Weather               (Doc 17 §6)
├── Maritime               (Doc 12)
├── Save                  (§6 below)
├── UI                     (Doc 20)
└── Audio                  (Doc 21)
```

**Rationale for HistoricalCodex as a standalone module (not folded into UI or Quest, per Doc 01 §6):** Quest, Dialogue, Puzzle, and World all write to it; UI, Save, and Localization all read from it. A dependency graph with Codex embedded inside any one of those would create circular dependencies.

## 2. Class/Component Structure (representative, not exhaustive)

- `AGKCharacterBase` (C++) — shared base for Arulan and Tier 1/2 NPCs (Doc 13 §2), holds Health/Stamina/Combat components.
- `UGKCombatComponent` (C++, Actor Component) — GAS-integrated (Gameplay Ability System), attached to combat-capable characters.
- `UGKDialogueComponent` (C++) — holds current dialogue state, memory-flag references (Doc 13 §4).
- `UGKQuestSubsystem` (C++, GameInstanceSubsystem) — global quest state, drives Quest module.
- `UGKCodexSubsystem` (C++, GameInstanceSubsystem) — global Codex entry state, exposed to Blueprint for UI binding.
- `AGKPuzzleActor` (C++ base, Blueprint-extended per puzzle type) — shared puzzle-state interface (§4 below), so Save/UI/Quest modules can interact with any puzzle generically rather than needing per-puzzle-type integration code.
- NPC schedule/behavior: `UGKScheduleComponent` (C++) driving Mass Entity fragments for Tier 3 population, Blueprint-authored schedule data assets for Tier 1/2 (Doc 13 §2).

## 3. Data Models (Data Assets / Data Tables)

**Per Doc 01 §26 and the Foundation Bible's explicit requirement:** the Historical Evidence Database (Doc 03) must be structured data, not hardcoded strings, so non-engineers can review/revise it.

```
DataTable: DT_HistoricalEvidence
  Row: EvidenceID (matches Doc 03 ID, e.g. "B2")
  Fields: Claim (Text), EvidenceCategory (Enum: Documented/Plausible/Fictional),
          Source (Text), SourceType (Enum), Date (Text), Confidence (Enum: Known/Likely/Uncertain/Unknown),
          GameUsage (Text), Disclaimer (Text)

DataAsset: DA_Quest_<QuestID>
  Fields: Act, Location (SoftObjectPtr to level), Characters (array), HistoricalCategory,
          ObjectiveGraph (reference to Quest module's state machine graph),
          CodexRewardIDs (array of EvidenceID references into DT_HistoricalEvidence)

DataAsset: DA_NPC_<NPCID>
  Fields: Faction (reference into DT_Factions), ScheduleAsset, MemoryFlagSchema (array of flag keys this NPC can hold),
          Tier (Enum: 1/2/3 per Doc 13 §2)
```

Designers/Historical Research Director edit `DT_HistoricalEvidence` directly; Quest module references entries by `EvidenceID` rather than duplicating claim text anywhere else in the codebase — single source of truth, per the Foundation Bible's data-driven-history requirement.

## 4. Interfaces

- `IGKInvestigatable` — implemented by any actor that can be scanned/investigated (inscriptions, documents, evidence objects per Doc 11 §6), exposes `OnInvestigate()`, decoupling the investigation system from needing to know concrete object types.
- `IGKPuzzleInterface` — implemented by all puzzle actor types, exposes `GetPuzzleState()`, `AttemptSolve()`, `ResetPuzzle()` — lets Save/Quest/UI modules interact generically with any of the puzzle types from Doc 09/Production Bible v2 §2 without per-type branching.
- `IGKMemoryHolder` — implemented by NPCs, exposes `GetMemoryFlag(FName)`/`SetMemoryFlag(FName, bool)` (Doc 13 §4).

## 5. Events
Gameplay Message Subsystem (or equivalent pub/sub) for cross-module communication — e.g., Quest module broadcasts `OnQuestCompleted(QuestID)`, consumed independently by Codex (unlock rewards), AI (NPCs react per Doc 13 §5 "react to events"), and Audio (music-cue triggers, Doc 21) without those modules needing direct references to Quest module internals. This is the concrete mechanism behind Doc 13 §5's "world ripples from player choices" requirement.

## 6. Save Architecture

Per Doc 01 §27's flagged risk: world-simulation state (construction progress, NPC relationship/memory) must be captured alongside standard quest/inventory state.

```
USaveGame subclass: UGKSaveGame
  QuestState: Map<QuestID, QuestStateEnum>
  CodexUnlocked: Set<EvidenceID>
  NPCMemory: Map<NPCID, Map<FlagName, bool>>          <- Doc 13 §4
  WorldState: Map<LocationID, WorldStateEnum>          <- construction progress etc, Doc 13 §5
  PuzzleState: Map<PuzzleID, PuzzleStateStruct>
  FactionReputation: Map<FactionID, ReputationEnum>     <- Doc 14, non-numeric per Doc 01 §23
  ShipState: (if applicable, Doc 12)
```

**Autosave:** on quest-state-changing events and major location transitions. **Manual save:** available at any non-combat moment. Recommend an early technical spike specifically on `NPCMemory` and `WorldState` serialization cost, given the living-world NPC density target (Doc 13 §2) — this was flagged as an open risk in Doc 01 and remains the save system's biggest unknown.

## 7. Logging, Debugging, Profiling
Standard UE5 logging categories per module (`LogGKQuest`, `LogGKCodex`, `LogGKAI`, etc.) for isolated debugging. Recommend a custom in-editor debug overlay showing live NPC memory-flag state and current world-state values (Doc 13 §5), given how much of the game's "did my choice matter" feedback depends on those systems working correctly — this is a good early tools investment, not a nice-to-have.

## 8. Build Pipeline
Standard UE5 build pipeline (not detailed here — Production Manager/Technical Director to specify CI/build-server setup per team infrastructure, outside this document's scope).

---

## Open Questions
- `NPCMemory`/`WorldState` serialization cost — needs the technical spike flagged in §6 before the vertical slice locks its NPC population target (Doc 13 §2 tiering decision).
- Whether `IGKPuzzleInterface` is sufficient abstraction for all 8+ puzzle categories from Production Bible v2 §2, or whether some (e.g., Star-Sight Navigation's ship-context version) need a specialized sub-interface — Tools Programmer to evaluate once more puzzle types are implemented.

## Dependencies on Other Documents
Doc 01 (system requirements this architecture serves), Doc 03 (DT_HistoricalEvidence schema), Doc 07 (DA_Quest schema), Doc 13 (DA_NPC schema, Mass Entity requirements), Doc 36 (Save/Load, detailed here as authoritative).

## Acceptance Criteria
- All 16 modules specified with clear ownership boundaries.
- HistoricalCodex confirmed as standalone module with explicit dependency rationale.
- Historical Evidence Database confirmed as structured data (DT_HistoricalEvidence), not hardcoded strings, satisfying the Foundation Bible's explicit requirement.
- Save architecture explicitly addresses the world-simulation-state risk flagged in Doc 01 §27.
