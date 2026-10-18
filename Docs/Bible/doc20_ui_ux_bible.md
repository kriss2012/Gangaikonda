# GANGAIKONDA — DOCUMENT 20: UI/UX BIBLE

**Document ID:** UIB-20 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Full screen-by-screen UI specification, expanding Production Bible v2 §5 and Doc 17 §13.
**Dependencies:** Doc 01 §29–30 (minimal HUD principle, accessibility requirement), Doc 03 (Codex format, locked), Doc 17 §13 (material-driven visual language), Doc 37 (Accessibility, cross-referenced throughout).
**Design language, restated:** historical, minimal, elegant, stone/bronze inspired. UI frame elements borrow the material palette from Doc 17 §3 rather than a modern flat-design or fantasy-ornate aesthetic. No anachronistic iconography (no generic "RPG fantasy" icon sets).

---

## 1. Main Menu
Restrained — title treatment per Cinematic 002's title card style (Doc 05), stone/bronze-textured background panel, no animated fantasy particle effects. Options: Continue, New Game, Load, Settings, Credits.

## 2. Pause Menu
Minimal overlay, does not fully obscure the game world (subtle blur/darken only) — Map, Quest Journal, Inventory, Codex, Settings accessible from here, plus Resume/Quit.

## 3. Map
Per Doc 04 Act 10's Imperial Map system — this is both a narrative device and the primary navigation UI. Layered per your original spec (Political/Trade/Military/Maritime/Temple/Agriculture/Water/Cultural), zoomable Empire → Region → City → Temple → Street → Interior. Visual style: hand-drawn-map aesthetic consistent with period cartographic convention rather than a modern GPS-style overlay — markers use restrained iconography matching the material palette.

## 4. Quest Journal
Organized by the six Doc 07 categories (Main/Side/Historical Discovery/Puzzle/Naval/Scholar-Archive), each quest entry showing current objective and — notably — its Historical category tag (Doc 04/07 format) directly in the journal, not hidden behind a separate menu, since the evidence-honesty pillar should be visible everywhere the player encounters quest content, not just in the Codex.

## 5. Inventory
Minimal per Doc 01 §20 (narrative/puzzle-support tool, not a loot system) — evidence fragments, tools, trade goods, cosmetic items (per PQ05/PQ10 rewards) organized simply, no complex grid/weight system.

## 6. Codex
The game's signature UI surface. Locked format per Foundation Bible/Doc 03: **Source / Date-period / Confidence / Description** for every entry, organized by the categories from your original spec (People/Places/Architecture/Military/Trade/Religion/Technology/Water/Culture/Language/Art). Visual evidence-category distinction (Doc 01 §29, restated here as the authoritative UI spec):
- **[DOCUMENTED]** entries: solid border treatment, full-color.
- **[PLAUSIBLE RECONSTRUCTION]** entries: dashed/hatched border treatment.
- **[FICTIONAL]** entries: desaturated treatment with a distinct header color, clearly separated visually even from across the room on a screenshot.
Confidence tier (KNOWN/LIKELY/UNCERTAIN/UNKNOWN, per Doc 03's expanded scale) shown as explicit text, not just implied by the border style — redundant coding for accessibility (Doc 37 color-blind support requirement).

## 7. Puzzle UI
Minimal, diegetic where possible (e.g., Stone Alignment's load-stress visualization happens on the stones themselves, not a separate meter; Inscription Decoding's script-reference chart is presented as an in-world scholar's document, not a floating UI panel) — consistent with the "puzzles simulate real craft" design philosophy (Production Bible v2 §2).

## 8. Dialogue UI
Text-based branch selection (no full voice-input), subtitle-integrated for voiced lines, NPC name/portrait shown with restrained framing. Evidence-category indicator shown when a dialogue option would reveal or discuss historical content, so the player has a sense of "this is where the real history comes in" during conversation, not just after.

## 9. Combat UI
Minimal HUD per Doc 01 §29: health, stamina, equipped weapon only. No damage-number floating text (breaks grounded tone) — hit feedback communicated through animation/audio (Doc 21) rather than numeric pop-ups.

## 10. Navigation
Waypoint/compass elements minimal and diegetic-leaning where feasible — consistent with the Map's hand-drawn aesthetic rather than a modern minimap HUD element cluttering the main view.

## 11. Settings
Standard graphics/audio/control settings, plus: subtitle size, hint depth (Doc 01 §28 — puzzle hint adjustability, not puzzle-trivializing difficulty), combat assist toggles, motion-reduction toggle (Doc 37).

## 12. Accessibility
Full detail in Doc 37 — this document's UI-specific commitments: color-blind-safe Codex evidence-category coding (§6, redundant text + border style, not color alone), full subtitle text scaling, controller remapping, and a puzzle hint system that preserves intellectual content at every setting rather than trivializing puzzles (Doc 01 §28 principle, made concrete here as a settings-menu requirement).

---

## Open Questions
- Whether the Quest Journal (§4) should allow filtering by Historical category (e.g., "show only Historical Discovery quests") as a player-facing feature, or keep the six-category organization fixed — UX Designer playtesting call.
- Exact diegetic-vs-UI-panel balance for Puzzle UI (§7) needs prototyping per puzzle type before final lock.

## Dependencies on Other Documents
Doc 01 §29–30, Doc 03 (Codex format, locked), Doc 04/07 (quest category structure for Journal), Doc 17 §13 (material-driven UI visual language), Doc 37 (Accessibility, full detail).

## Acceptance Criteria
- All 12 screens/systems specified.
- Codex evidence-category visual distinction confirmed as the authoritative spec (matches Doc 01 §29's principle, now made concrete with actual border/color/text treatment).
- No UI element uses color alone to carry evidence-category meaning (accessibility requirement satisfied).
- Combat UI confirmed free of damage-number floating text, consistent with grounded-tone design throughout.
