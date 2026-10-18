# GANGAIKONDA — DOCUMENT 19: UNREAL ENGINE 5 IMPLEMENTATION BIBLE

**Document ID:** UE5-19 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Concrete production implementation specification — folder structure and the C++/Blueprint/Data Asset/Data Table/Subsystem allocation for every module defined in Doc 18.
**Dependencies:** Doc 18 (module architecture, class list, data model schemas — this document makes them concrete and buildable).

---

## 1. Folder Structure

```
/Game
 /Characters
   /Arulan
   /NPCs
     /Tier1_Named        <- Doc 13 §2
     /Tier2_SemiNamed
     /Tier3_Background
 /World
   /Thanjavur
   /RoyalCourt
   /NorthernCorridor
   /Ganga
   /Gangaikondacholapuram
     /ConstructionZone
     /LivingCity
   /Port_Primary
   /Port_Secondary
   /Wilderness
 /Maps                     <- level assets per World Bible §4 locations
 /Quests
   /MainQuests              <- DA_Quest_MQ01 etc, Doc 07a
   /SideQuests               <- Doc 07b
   /HistoricalDiscovery        <- Doc 07c
   /PuzzleQuests                 <- Doc 07d
   /NavalQuests                   <- Doc 07e
   /ScholarArchiveQuests            <- Doc 07f
 /Puzzles
   /StoneAlignment
   /LionWell
   /RoyalSeal
   /InscriptionDecoding
   /TradeLedger
   /StarSightNavigation
   /MapReconstruction
   /ElevationLoadDeduction
   /Variants                    <- Environmental/Logic/HistoricalDeduction/PatternRecognition, Doc 07d
 /Combat                            <- Doc 10
 /AI                                   <- Doc 13, Mass Entity fragments/processors
 /UI                                     <- Doc 20
 /Audio                                    <- Doc 21
 /Cinematics                                 <- Doc 05
 /HistoricalCodex                              <- DT_HistoricalEvidence and Codex UI-facing assets
 /Items                                          <- Doc 26
 /Ships                                             <- Doc 12
 /Data
   /DataTables                                        <- DT_HistoricalEvidence, DT_Factions, DT_NPCSchedules
   /DataAssets                                            <- DA_Quest_*, DA_NPC_*, DA_Puzzle_*
 /Blueprints
   /Gameplay
   /UI
 /Materials
 /VFX
```

## 2. C++ / Blueprint / Data Asset / Data Table / Subsystem Allocation

**Principle:** performance-critical, deeply-shared, or systemically-central logic lives in C++; content-specific configuration and one-off scripted behavior lives in Blueprint or Data Assets; anything a non-engineer (Historical Research Director, Quest Designer, Narrative Director) needs to edit directly lives in a Data Table.

| System element | Lives in | Rationale |
|---|---|---|
| `AGKCharacterBase`, `UGKCombatComponent`, `UGKDialogueComponent` | C++ | Shared across every character, performance-relevant (Doc 18 §2) |
| Individual NPC schedule content | Data Asset (`DA_NPC_<ID>`) | Designer-editable per Doc 18 §3, no engineering needed to add/edit an NPC's day |
| Historical Evidence Database | Data Table (`DT_HistoricalEvidence`) | Must be directly editable by Historical Research Director without engineering involvement (Foundation Bible requirement, Doc 18 §3) |
| Individual quest logic/branching | Blueprint (`BP_Quest_<ID>`), referencing `DA_Quest_<ID>` for data | Quest Designers need to iterate on branching without C++ recompiles; underlying state-machine framework is C++ |
| Puzzle-type base logic (e.g., Stone Alignment load-path calculation) | C++ (`AGKPuzzleActor` subclasses per type) | Physics/logic-heavy, performance-relevant, shared across all instances of a puzzle type |
| Individual puzzle instance configuration (which stones, what solution) | Data Asset (`DA_Puzzle_<InstanceID>`) | Level/Puzzle Designers configure instances without touching puzzle-type C++ |
| Faction definitions (Doc 14) | Data Table (`DT_Factions`) | Directly editable reference data |
| Dialogue tree content | Blueprint-based dialogue graph (Dialogue module tooling) referencing localization keys | Writers/Narrative Designers need direct iteration; underlying branching engine is C++ |
| Save/Load serialization logic | C++ (`UGKSaveGame` and subsystem logic, Doc 18 §6) | Correctness-critical, not content |
| Global quest/Codex/faction-reputation state | GameInstanceSubsystem (C++: `UGKQuestSubsystem`, `UGKCodexSubsystem`) | Needs to persist across level streaming, accessible game-wide |
| NPC daily-cycle behavior (Tier 3 background population) | C++ Mass Entity fragments/processors | Performance-critical at population scale (Doc 13 §2) |
| NPC daily-cycle behavior (Tier 1/2) | Blueprint-authored schedule + C++ `UGKScheduleComponent` driving it | Balances designer iteration with shared underlying logic |
| UI widgets (Codex, Quest Journal, Map, etc.) | UMG Blueprint (widgets), C++ (data-binding subsystems) | Standard UE5 UI pattern; visual iteration in Blueprint, data plumbing in C++ |
| Cinematic sequences | Sequencer assets (per Doc 05 shot lists) | Standard UE5 cinematic tooling |

## 3. Subsystems (GameInstanceSubsystem / WorldSubsystem)

- `UGKQuestSubsystem` — global quest state (persists across level streaming via World Partition, Doc 18).
- `UGKCodexSubsystem` — global Codex unlock state, exposed to UI.
- `UGKWorldStateSubsystem` — construction-progress and other Doc 13 §5 world-state flags, the mechanism behind "revisited areas reflect current progress."
- `UGKReputationSubsystem` — faction/NPC reputation aggregation (Doc 01 §23, Doc 14), non-numeric-facing but internally tracked as structured state for UI/dialogue queries.

## 4. Implementation Note on Data-Driven History (worked example)

```
// Pseudocode: Quest module unlocking a Codex entry on quest completion,
// reading directly from DT_HistoricalEvidence rather than hardcoded text

void UGKQuestSubsystem::OnQuestCompleted(FName QuestID)
{
    UDataTable* QuestTable = LoadQuestDataTable();
    FGKQuestData* QuestData = QuestTable->FindRow<FGKQuestData>(QuestID, TEXT("QuestComplete"));

    for (const FName& EvidenceID : QuestData->CodexRewardIDs)
    {
        UGKCodexSubsystem::Get(this)->UnlockEntry(EvidenceID);
        // UnlockEntry looks up EvidenceID in DT_HistoricalEvidence directly —
        // no claim text, source, or confidence rating is duplicated in quest code.
    }

    FGKQuestCompletedMessage Message{QuestID};
    UGameplayMessageSubsystem::Get(this).BroadcastMessage(TAG_QuestCompleted, Message);
    // Doc 18 §5 event system — AI/Audio/World modules react independently
}
```

This is the concrete implementation of the Foundation Bible's data-driven-history requirement — worth keeping as a reference pattern since several other systems (Faction reputation, NPC memory) should follow the same "reference by ID into a Data Table, never duplicate the content" shape.

---

## Open Questions
- Whether dialogue tree tooling should be a custom UMG-based graph editor or a third-party dialogue plugin — Tools Programmer evaluation needed, affects Doc 22 production timeline.
- Mass Entity fragment/processor design for Tier 3 NPCs (§2) needs a dedicated technical design pass once the vertical slice's population density target is confirmed (Doc 13 §2, Doc 18 §6 open question).

## Dependencies on Other Documents
Doc 18 (module architecture and data schemas this document implements), Doc 07 (quest folder structure and DA_Quest references), Doc 13 (NPC tiering and Mass Entity requirements), Doc 03 (DT_HistoricalEvidence content).

## Acceptance Criteria
- Full `/Game` folder structure specified, matching your brief's example structure and extended per this project's specific module needs.
- Every system element explicitly allocated to C++, Blueprint, Data Asset, Data Table, or Subsystem, with rationale.
- Worked pseudocode example demonstrates the data-driven-history pattern concretely, not just asserted in principle.
