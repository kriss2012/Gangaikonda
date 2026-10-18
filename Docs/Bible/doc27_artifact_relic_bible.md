# GANGAIKONDA — DOCUMENT 27: ARTIFACT & RELIC BIBLE

**Document ID:** ARB-27 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** Classification system and worked examples for all collectible artifacts/relics, per your explicit requirement that fictional objects never be presented as authentic archaeological discoveries.
**Dependencies:** Doc 03 (evidence basis), Doc 23 (Codex — artifacts feed Codex entries), Doc 26 §4 (Inventory — this document is that section's full detail).

---

## 1. The Three-Tier Classification (mandatory for every artifact)

### DOCUMENTED ARTIFACT
An in-game object modeled directly on a real, specifically identifiable archaeological find or well-attested object type (e.g., a bronze in the general style of surviving Chola-period bronzes, Doc 03 G1). The Codex entry for a DOCUMENTED ARTIFACT may reference the real object type it's modeled on, but the specific in-game instance (this exact statue, found in this exact location by Arulan) is still narratively fictional — the *type* is documented, the *specific find* is not, and the Codex wording must make that distinction rather than implying Arulan personally excavated a named real artifact.

### RECONSTRUCTED OBJECT
An object type that plausibly existed based on general period/regional evidence but isn't tied to a specific attested find (e.g., a specific ship-fitting per Doc 03 E4's evidence gap, or a specific water-system component per Doc 03 D3). Tagged [PLAUSIBLE RECONSTRUCTION] throughout, Codex-flagged accordingly.

### FICTIONAL STORY OBJECT
An object that exists purely to serve the plot (e.g., the specific forged seal from MQ19's conspiracy thread, the specific ledgers throughout the investigation chain). Never Codex-logged with real-world sourcing — its Codex entry, if any, is explicitly about its role in Arulan's story, not a historical claim.

**Hard rule:** no object in any of the three tiers may have its Codex entry, marketing copy, or in-game dialogue worded in a way that implies the specific in-game object is a real archaeological artifact housed somewhere or excavated at a real date. This is the artifact-level enforcement of the Foundation Bible's "never fabricate inscriptions" and "never label fictional architecture as archaeological fact" rules, extended to portable objects.

---

## 2. Worked Examples

### "The Bronze of the Dancing Form" — DOCUMENTED ARTIFACT (type)
- **Basis:** modeled on the general style of Chola-period bronze sculpture (Doc 03 G1) — Nataraja-type bronzes are a well-known, extensively studied category
- **In-game context:** a specific in-game bronze discovered in the temple treasury (HD10's location)
- **Codex wording principle:** "Bronzes in this style represent a documented artistic peak of the period [Doc 03 G1] — the specific piece shown here is a fictional representative example, not a named historical object." Never: "This is [Real Museum]'s actual bronze."

### "The Water Engineer's Marker Stone" — RECONSTRUCTED OBJECT
- **Basis:** plausible type of object (a stone marking a water-system component) built on Doc 03 D1/D3's documented general reservoir/canal existence, but this specific marker and its inscription are invented
- **In-game context:** found during the Lion Well puzzle chain (Act 8)
- **Codex wording principle:** "Objects of this general kind plausibly existed given the documented water infrastructure at the site [Doc 03 D1] — this specific marker is a fictionalized illustration of that infrastructure, not an excavated find."

### "The Falsified Ledger" — FICTIONAL STORY OBJECT
- **Basis:** entirely fictional, central to MQ19's conspiracy
- **In-game context:** evidence object found in the site office investigation
- **Codex wording principle:** if logged at all, framed purely as a story artifact ("A record central to the events of Arulan's investigation") with no historical-sourcing language whatsoever — this object should probably not receive a full Doc 23-style Codex entry at all, since it has no historical-evidence content to honestly convey; a lighter "Story Item" log distinct from the Historical Codex may be the right UI solution (flagged to Doc 20).

### "The Shipwright's Model" — RECONSTRUCTED OBJECT (directly engages Doc 03 E4's gap)
- **Basis:** built on Doc 12/NQ06's explicit handling of the ship-construction evidence gap
- **In-game context:** obtainable from the shipwright NPC in NQ06
- **Codex wording principle:** "Ship construction methods of this period are not well documented [Doc 03 E4] — this model represents one plausible reconstruction based on regional shipbuilding tradition, not a documented Chola vessel design." This entry should be one of the more heavily caveated in the whole Codex, matching the gap's severity.

---

## 3. UI Implication (flagged to Doc 20)
Given "The Falsified Ledger" example above, recommend Doc 20 consider a distinct "Story Items" log separate from the Historical Codex proper — mixing plot-device objects into the same UI surface as genuinely sourced historical content risks diluting the Codex's credibility as a trustworthy evidence source. This is a meaningful cross-document recommendation, not just a formatting note.

## Open Questions
- Full artifact list (beyond the four worked examples) is a Doc 30 (Prop Bible) production task, using this document's classification system as the mandatory template for every entry.
- Whether DOCUMENTED ARTIFACT type entries should include a real-world "further reading" pointer (e.g., naming the actual museum collection the style is drawn from) — could be a nice authenticity touch, but needs legal/IP review before committing to naming specific real institutions.

## Dependencies on Other Documents
Doc 03 (evidence basis for every classification decision), Doc 12/NQ06 (Shipwright's Model example), Doc 20 (UI recommendation), Doc 23 (Codex format this feeds), Doc 30 (Prop Bible, full production list).

## Acceptance Criteria
- Three-tier classification system fully specified with a hard rule against implying real-artifact status for any fictional object.
- Four worked examples cover all three tiers plus the specific Doc 03 E4 evidence-gap case.
- Cross-document UI recommendation flagged to Doc 20 rather than silently worked around.
