# GANGAIKONDA — DOCUMENT 23: HISTORICAL CODEX

**Document ID:** HC-23 · **Version:** 1.0 · **Status:** Draft for review
**Purpose:** The player-facing in-game encyclopedia — distinct from Doc 03 (the research team's working database). This document specifies how Doc 03 entries get *translated* into player-facing Codex entries, plus a full worked set across all 11 categories.
**Dependencies:** Doc 03 (source data), Doc 20 §6 (UI format, locked), Doc 18 §3 (technical implementation — `DT_HistoricalEvidence`).

**Relationship to Doc 03:** Doc 03 is written for the research/design team (columns: ID, Claim, Evidence Category, Source, Source Type, Date, Language, Confidence, Debate, Game Usage, Misinterpretation Risk, Disclaimer). The Codex is written for the *player* — same underlying facts, translated into the simpler locked format: **Title, Period, Category, Evidence, Source, Summary, Uncertainty, Gameplay connection.** Every Codex entry must trace to a specific Doc 03 ID; no Codex entry should introduce a claim not already vetted in Doc 03.

---

## Category: PEOPLE

### "Rajendra Chola I" (traces to Doc 03 A1–A2)
- **Period:** r. c. 1014–1044 CE
- **Category:** People
- **Evidence:** DOCUMENTED
- **Source:** Copper-plate inscriptions (e.g. Tiruvalangadu plates), temple inscriptions
- **Summary:** Chola emperor, son and successor of Rajaraja I, whose reign included a major military expedition into the Gangetic region and the founding of a new imperial capital.
- **Uncertainty:** Reign dates are well-established; exact co-regency start date is approximate.
- **Gameplay connection:** Unlocked at Act 2 (MQ04).

## Category: PLACES

### "Gangaikondacholapuram" (traces to Doc 03 C1)
- **Period:** founded c. 1025 CE onward
- **Category:** Places
- **Evidence:** DOCUMENTED
- **Source:** Royal inscriptions naming the capital; ASI archaeological survey
- **Summary:** The new imperial capital founded by Rajendra I following the northern expedition, distinct from the earlier capital at Thanjavur.
- **Uncertainty:** Full non-monumental city layout beyond the temple and major reservoir is not fully attested (see Architecture category note below).
- **Gameplay connection:** Unlocked at Act 6 (MQ11).

### "Thanjavur" (traces to Doc 03 A1)
- **Period:** Chola capital under Rajaraja I, active through Rajendra's reign
- **Category:** Places
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions
- **Summary:** The established Chola capital, site of Rajaraja I's Brihadisvara Temple, where the game begins.
- **Uncertainty:** None significant.
- **Gameplay connection:** Unlocked at Act 1 (MQ02).

## Category: ARCHITECTURE

### "The Brihadisvara Temple, Gangaikondacholapuram" (traces to Doc 03 C2–C3)
- **Period:** built c. 1025–1035 CE
- **Category:** Architecture
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions, UNESCO "Great Living Chola Temples" documentation
- **Summary:** A Shiva temple built by Rajendra I, architecturally related to but distinct in proportion from his father's temple at Thanjavur.
- **Uncertainty:** Exact completion date debated.
- **Gameplay connection:** Central to Act 7 (Stone Alignment puzzle chain); unlocked via HD01.

### "The City's Non-Monumental Layout" (traces to Doc 03 C4)
- **Period:** contemporary with the capital's founding
- **Category:** Architecture
- **Evidence:** FICTIONAL (this entry exists specifically to flag its own uncertainty to the player)
- **Source:** Partial archaeological remains
- **Summary:** Much of the residential and market fabric of the historical city has not survived or been fully excavated — the game's depiction of streets, homes, and markets is a plausible extrapolation, not an excavated record.
- **Uncertainty:** High — explicitly acknowledged.
- **Gameplay connection:** Ambient throughout Acts 6–12; a deliberate "honesty" entry rather than a discovery reward.

## Category: MILITARY

### "The Northern Expedition" (traces to Doc 03 B1–B4)
- **Period:** c. 1023–1025 CE
- **Category:** Military
- **Evidence:** DOCUMENTED (that it occurred) / RECONSTRUCTED (specific route and events)
- **Source:** Tiruvalangadu copper plates and other royal inscriptions
- **Summary:** A major military campaign into the Gangetic region, following which Rajendra adopted the title "Gangaikonda Chola." The inscriptions list regions/rulers encountered in a laudatory style, not a tactical narrative.
- **Uncertainty:** High for specific route, battles, and tactical details — labeled "HISTORICAL RECONSTRUCTION" throughout Acts 3–5.
- **Gameplay connection:** Unlocked via HD03, central to Acts 3–5.

## Category: TRADE

### "The Merchant Guilds" (traces to Doc 03 E1)
- **Period:** active throughout this era across South India and Southeast Asia
- **Category:** Trade
- **Evidence:** DOCUMENTED
- **Source:** Guild inscriptions found across South India and Southeast Asia
- **Summary:** Organized merchant associations (such as the Ainnurruvar) coordinated trade across a wide network, evidenced by inscriptions found far from South India itself.
- **Uncertainty:** Precise internal organizational structure debated among historians.
- **Gameplay connection:** Central to Act 11 and the NQ-series quests.

## Category: RELIGION

### "Temple as Institution" (traces to Doc 03 F2)
- **Period:** throughout the Chola period
- **Category:** Religion
- **Evidence:** DOCUMENTED
- **Source:** Temple inscriptions recording land grants and administration
- **Summary:** Temples functioned not only as religious centers but as significant economic and administrative institutions, managing land grants and redistributing resources.
- **Uncertainty:** None significant on the general pattern.
- **Gameplay connection:** Unlocked via HD09/SQ11.

## Category: TECHNOLOGY

### "Lost-Wax Bronze Casting" (traces to Doc 03 G1)
- **Period:** reached a recognized artistic peak under Rajaraja I and Rajendra I
- **Category:** Technology
- **Evidence:** DOCUMENTED
- **Source:** Surviving bronzes, temple inventory inscriptions
- **Summary:** The cire perdue (lost-wax) casting technique used to produce the era's celebrated bronze sculptures.
- **Uncertainty:** None on the technique's use; specific workshop practices vary by scholarly reconstruction.
- **Gameplay connection:** Unlocked via HD07/HD10.

## Category: WATER

### "The Great Reservoir" (traces to Doc 03 D1–D2)
- **Period:** constructed alongside the new capital
- **Category:** Water
- **Evidence:** DOCUMENTED (existence) / TRADITION (Ganga-water symbolism)
- **Source:** Archaeological remains; later textual tradition
- **Summary:** A large reservoir associated with the new capital. Tradition holds that it was symbolically filled with water carried from the Ganga campaign — this specific claim is not independently verifiable and is presented here as tradition, not documented fact.
- **Uncertainty:** Reservoir's existence is solid; the water's origin story is explicitly a tradition, not an attested engineering record.
- **Gameplay connection:** Central to Act 8 (Lion Well puzzle chain), unlocked via MQ17/HD04.

## Category: CULTURE

### "Village Self-Governance" (traces to Doc 03 F1)
- **Period:** documented administrative continuity through this era
- **Category:** Culture
- **Evidence:** DOCUMENTED
- **Source:** Uttaramerur inscriptions (slightly predating Rajendra, reflecting continuous administrative culture)
- **Summary:** Local village assemblies operated with documented administrative procedures, existing alongside royal administration.
- **Uncertainty:** How uniformly this specific model applied across all Chola territory is debated.
- **Gameplay connection:** Unlocked via HD05.

## Category: LANGUAGE

### "Tamil and Sanskrit in Chola Inscriptions" (traces to Doc 03 H1)
- **Period:** throughout the Chola period
- **Category:** Language
- **Evidence:** DOCUMENTED
- **Source:** The corpus of surviving Chola inscriptions
- **Summary:** Tamil was the primary administrative and inscriptional language, with Sanskrit used in specific formal, religious, and literary contexts.
- **Uncertainty:** None significant.
- **Gameplay connection:** Ambient throughout; directly informs Doc 22's dialogue rules.

## Category: ART

### "Reading a Sculptor's Hand" (traces to Doc 03 G3, general art-historical scholarship)
- **Period:** throughout the Chola period
- **Category:** Art
- **Evidence:** DOCUMENTED (general phenomenon) / FICTIONAL (specific panels shown)
- **Source:** Comparative art-historical scholarship
- **Summary:** Individual sculptors' stylistic habits can sometimes be identified across multiple works, a real phenomenon in temple sculpture scholarship.
- **Uncertainty:** The general phenomenon is documented; the specific panels the player examines in-game are fictional illustrations of it.
- **Gameplay connection:** Unlocked via PQ04.

---

## Codex System Rules (production-facing)
1. Every Codex entry's **Evidence** field must match its source Doc 03 entry's Evidence Category — no upgrading confidence in translation from research format to player format.
2. Entries with genuinely high uncertainty (like "The City's Non-Monumental Layout" above) should exist as their own entries, not be silently omitted — the Codex's credibility depends on it being honest about gaps, not just complete about knowns.
3. Every entry must show its **Gameplay connection** — no orphaned lore-dump entries unconnected to actual play.

## Open Questions
- Full Codex will need roughly 60–80 entries to properly cover Doc 03's eventual expanded database — this document establishes the format and provides one worked example per category (11 total) as the production template.
- Whether entries should link to each other (e.g., "Gangaikondacholapuram" linking to "The Great Reservoir") in the UI — UX Designer call, technically supported by Doc 18's DataTable structure regardless.

## Dependencies on Other Documents
Doc 03 (source data for every entry), Doc 18 §3–4 (technical implementation), Doc 20 §6 (locked UI format).

## Acceptance Criteria
- One worked entry per all 11 categories from your brief, each traced to a specific Doc 03 ID.
- Codex system rules explicitly prevent confidence-upgrading between Doc 03 and Codex format.
- At least one entry (Architecture category) explicitly models how the Codex handles high-uncertainty content honestly rather than omitting it.
