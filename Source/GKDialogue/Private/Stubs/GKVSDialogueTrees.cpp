#include "Stubs/GKVSDialogueTrees.h"

#define LOCTEXT_NAMESPACE "GKVSDialogueTrees"

FGKDialogueTree FGKVSDialogueTrees::BuildScholarDialogueTree()
{
	FGKDialogueTree Tree;
	Tree.TreeID = FName(TEXT("Tree_MQ03_ScholarArchive"));
	Tree.ParticipantNPCID = FName(TEXT("NPC_Scholar"));
	Tree.EntryNodeID = 1;

	// Node 1: Scholar greeting
	FGKDialogueNode Node1;
	Node1.NodeID = 1;
	Node1.SpeakerID = FName(TEXT("NPC_Scholar"));
	Node1.SpeakerDisplayName = LOCTEXT("ScholarName", "Ilango");
	Node1.SpeakerRoleTitle = LOCTEXT("ScholarTitle", "Royal Epigraphist & Archivist");
	Node1.SpokenText = LOCTEXT("ScholarNode1Text",
		"Welcome to the archive shelter, Arulan. You walk among fresh stone and damp palm leaves. "
		"The Emperor's praśasti poets sing of distant rivers, but it is my duty to ensure what is carved "
		"into the granite will endure for a thousand years.");

	// Option 1A: Inquire about the royal title [DOCUMENTED]
	FGKDialogueOption Opt1A;
	Opt1A.OptionID = 101;
	Opt1A.OptionText = LOCTEXT("ScholarOpt1AText", "The title 'Gangaikonda Chola'—it is already being inscribed on the foundation course?");
	Opt1A.NextNodeID = 2;
	Opt1A.bHasHistoricalClaim = true;
	Opt1A.HistoricalCategory = EGKEvidenceCategory::Documented;
	Opt1A.EvidenceIDToUnlock = FName(TEXT("B1"));
	Opt1A.MemoryFlagToSet = FName(TEXT("scholar_met"));
	Opt1A.bValueToSet = true;
	Node1.Options.Add(Opt1A);

	// Option 1B: Ask about the scan lens tool
	FGKDialogueOption Opt1B;
	Opt1B.OptionID = 102;
	Opt1B.OptionText = LOCTEXT("ScholarOpt1BText", "I was told you possess a polished crystal lens for examining weathered stone.");
	Opt1B.NextNodeID = 3;
	Opt1B.bHasHistoricalClaim = false;
	Opt1B.HistoricalCategory = EGKEvidenceCategory::Fictional;
	Opt1B.MemoryFlagToSet = FName(TEXT("scholar_met"));
	Opt1B.bValueToSet = true;
	Node1.Options.Add(Opt1B);

	Tree.Nodes.Add(1, Node1);

	// Node 2: Epigraphic discussion
	FGKDialogueNode Node2;
	Node2.NodeID = 2;
	Node2.SpeakerID = FName(TEXT("NPC_Scholar"));
	Node2.SpeakerDisplayName = LOCTEXT("ScholarName", "Ilango");
	Node2.SpeakerRoleTitle = LOCTEXT("ScholarTitle", "Royal Epigraphist & Archivist");
	Node2.SpokenText = LOCTEXT("ScholarNode2Text",
		"Indeed. The copper plates from Tiruvalangadu confirm the title, yet remember: the court poets write "
		"how the victory was meant to be remembered, not every turn of the muddy road. Take this reference chart; "
		"when you examine the foundation blocks, look for the transitional Grantha ligatures.");

	FGKDialogueOption Opt2A;
	Opt2A.OptionID = 201;
	Opt2A.OptionText = LOCTEXT("ScholarOpt2AText", "I will study the foundation inscriptions carefully.");
	Opt2A.NextNodeID = 4;
	Node2.Options.Add(Opt2A);

	Tree.Nodes.Add(2, Node2);

	// Node 3: Receiving the scan lens
	FGKDialogueNode Node3;
	Node3.NodeID = 3;
	Node3.SpeakerID = FName(TEXT("NPC_Scholar"));
	Node3.SpeakerDisplayName = LOCTEXT("ScholarName", "Ilango");
	Node3.SpeakerRoleTitle = LOCTEXT("ScholarTitle", "Royal Epigraphist & Archivist");
	Node3.SpokenText = LOCTEXT("ScholarNode3Text",
		"Here—cut from mountain quartz. Peer through it against angled sunlight, and chisel grooves filled with red ochre "
		"will leap forward from the weathered granite surface. Use it well.");

	FGKDialogueOption Opt3A;
	Opt3A.OptionID = 301;
	Opt3A.OptionText = LOCTEXT("ScholarOpt3AText", "Thank you, Master Epigraphist. I shall put it to immediate use.");
	Opt3A.NextNodeID = 4;
	Node3.Options.Add(Opt3A);

	Tree.Nodes.Add(3, Node3);

	// Node 4: Exit node
	FGKDialogueNode Node4;
	Node4.NodeID = 4;
	Node4.SpeakerID = FName(TEXT("NPC_Scholar"));
	Node4.SpeakerDisplayName = LOCTEXT("ScholarName", "Ilango");
	Node4.SpeakerRoleTitle = LOCTEXT("ScholarTitle", "Royal Epigraphist & Archivist");
	Node4.SpokenText = LOCTEXT("ScholarNode4Text",
		"May the auspicious verses guide your hand, Arulan. Go now to the foundation pit.");
	Node4.bIsExitNode = true;
	Tree.Nodes.Add(4, Node4);

	return Tree;
}

FGKDialogueTree FGKVSDialogueTrees::BuildArchitectDialogueTree()
{
	FGKDialogueTree Tree;
	Tree.TreeID = FName(TEXT("Tree_MQ05_ArchitectPavilion"));
	Tree.ParticipantNPCID = FName(TEXT("NPC_Architect"));
	Tree.EntryNodeID = 1;

	// Node 1: Master Architect greeting
	FGKDialogueNode Node1;
	Node1.NodeID = 1;
	Node1.SpeakerID = FName(TEXT("NPC_Architect"));
	Node1.SpeakerDisplayName = LOCTEXT("ArchitectName", "Maravan");
	Node1.SpeakerRoleTitle = LOCTEXT("ArchitectTitle", "Chief Sthapati (Master Architect)");
	Node1.SpokenText = LOCTEXT("ArchitectNode1Text",
		"Arulan! Look across this vast trench. My master-carvers dress fifty thousand granite courses without a speck of mortar. "
		"Yet our greatest peril lies ahead: balancing the upward curve of the vimana while channeling the vast waters from the northern reservoir.");

	// FIRST COSMETIC BRANCH (Doc 08 Minutes 14–18)
	// Branch A: Prioritize monumental stone structure [DOCUMENTED]
	FGKDialogueOption Opt1A;
	Opt1A.OptionID = 101;
	Opt1A.OptionText = LOCTEXT("ArchOpt1AText", "The sacred vimana must endure above all. Focus on stone load-paths and interlocking courses.");
	Opt1A.NextNodeID = 2; // Leads to structural focus
	Opt1A.bHasHistoricalClaim = true;
	Opt1A.HistoricalCategory = EGKEvidenceCategory::Documented;
	Opt1A.EvidenceIDToUnlock = FName(TEXT("C3"));
	Opt1A.MemoryFlagToSet = FName(TEXT("architect_favors_structure"));
	Opt1A.bValueToSet = true;
	Node1.Options.Add(Opt1A);

	// Branch B: Prioritize hydraulic canal and reservoir [PLAUSIBLE RECONSTRUCTION]
	FGKDialogueOption Opt1B;
	Opt1B.OptionID = 102;
	Opt1B.OptionText = LOCTEXT("ArchOpt1BText", "Without water, the city cannot survive. Focus on the sluice gates and the Lion Well channel first.");
	Opt1B.NextNodeID = 3; // Leads to hydraulic focus
	Opt1B.bHasHistoricalClaim = true;
	Opt1B.HistoricalCategory = EGKEvidenceCategory::PlausibleReconstruction;
	Opt1B.EvidenceIDToUnlock = FName(TEXT("D1"));
	Opt1B.MemoryFlagToSet = FName(TEXT("architect_favors_hydraulics"));
	Opt1B.bValueToSet = true;
	Node1.Options.Add(Opt1B);

	Tree.Nodes.Add(1, Node1);

	// Node 2: Structure-favored response
	FGKDialogueNode Node2;
	Node2.NodeID = 2;
	Node2.SpeakerID = FName(TEXT("NPC_Architect"));
	Node2.SpeakerDisplayName = LOCTEXT("ArchitectName", "Maravan");
	Node2.SpeakerRoleTitle = LOCTEXT("ArchitectTitle", "Chief Sthapati (Master Architect)");
	Node2.SpokenText = LOCTEXT("ArchitectNode2Text",
		"Well spoken! Unlike Thanjavur's straight pyramid, here the Emperor requested a subtle concave rhythm—graceful as a dancer, yet bearing "
		"hundreds of tons. If you inspect the scaffolding at the fourth course, verify that the load stones rest true upon their dressed facets.");

	FGKDialogueOption Opt2A;
	Opt2A.OptionID = 201;
	Opt2A.OptionText = LOCTEXT("ArchOpt2AText", "I will inspect the scaffolding blocks immediately.");
	Opt2A.NextNodeID = 4;
	Node2.Options.Add(Opt2A);

	Tree.Nodes.Add(2, Node2);

	// Node 3: Hydraulics-favored response
	FGKDialogueNode Node3;
	Node3.NodeID = 3;
	Node3.SpeakerID = FName(TEXT("NPC_Architect"));
	Node3.SpeakerDisplayName = LOCTEXT("ArchitectName", "Maravan");
	Node3.SpeakerRoleTitle = LOCTEXT("ArchitectTitle", "Chief Sthapati (Master Architect)");
	Node3.SpokenText = LOCTEXT("ArchitectNode3Text",
		"A practical mind! The Cholagangam reservoir is sixteen miles long, but silt from the rains threatens our lower feeder lines. "
		"The Lion Well sluices must be opened in exact sequence, lest the back-pressure crack the dressed granite spillway.");

	FGKDialogueOption Opt3A;
	Opt3A.OptionID = 301;
	Opt3A.OptionText = LOCTEXT("ArchOpt3AText", "I will inspect the sluice gates at the Lion Well first.");
	Opt3A.NextNodeID = 4;
	Node3.Options.Add(Opt3A);

	Tree.Nodes.Add(3, Node3);

	// Node 4: Exit node
	FGKDialogueNode Node4;
	Node4.NodeID = 4;
	Node4.SpeakerID = FName(TEXT("NPC_Architect"));
	Node4.SpeakerDisplayName = LOCTEXT("ArchitectName", "Maravan");
	Node4.SpeakerRoleTitle = LOCTEXT("ArchitectTitle", "Chief Sthapati (Master Architect)");
	Node4.SpokenText = LOCTEXT("ArchitectNode4Text",
		"May the architects of the heavens preserve our work. Proceed, Arulan.");
	Node4.bIsExitNode = true;
	Tree.Nodes.Add(4, Node4);

	return Tree;
}

#undef LOCTEXT_NAMESPACE
