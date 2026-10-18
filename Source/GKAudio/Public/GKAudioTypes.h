#pragma once

#include "CoreMinimal.h"
#include "GKAudioTypes.generated.h"

/**
 * Ambient sound categories matching Doc 21 §1.
 */
UENUM(BlueprintType)
enum class EGKAmbientSoundCategory : uint8
{
	City              UMETA(DisplayName = "City (Footsteps, Crowd Murmur, Construction)"),
	Temple            UMETA(DisplayName = "Temple (Bells, Resonant Stone Acoustics)"),
	Market            UMETA(DisplayName = "Market (Textiles, Pottery, Vendor Ambience)"),
	ForestWilderness  UMETA(DisplayName = "Forest/Wilderness (Wind, Birds, Delta Insects)"),
	Water             UMETA(DisplayName = "Water (Canals, Sluice Gates, River, Sea)"),
	Battle            UMETA(DisplayName = "Battle (Grounded Weapon Impacts, No Horns)"),
	Ship              UMETA(DisplayName = "Ship (Rigging, Hull Creak, Open Water)"),
	UI                UMETA(DisplayName = "UI (Bronze/Stone Tactile Cues)"),
	Cinematic         UMETA(DisplayName = "Cinematic (Restrained Score & Foley)")
};

/**
 * Acoustically distinct water soundscapes per Doc 21 §1 (River, Reservoir, Canal-flow, Sea).
 */
UENUM(BlueprintType)
enum class EGKWaterAcousticType : uint8
{
	None        UMETA(DisplayName = "None"),
	CanalSluice UMETA(DisplayName = "Canal Sluice (Lion Well Deterministic Dredge)"),
	Reservoir   UMETA(DisplayName = "Reservoir (Cholagangam Lake Margin)"),
	River       UMETA(DisplayName = "River (Kollidam / Kaveri Flow)"),
	OpenSea     UMETA(DisplayName = "Open Sea (Bay of Bengal / Nagapattinam)")
};

/**
 * Authentic South Indian thematic motifs matching Doc 21 §2.
 */
UENUM(BlueprintType)
enum class EGKMusicTheme : uint8
{
	None             UMETA(DisplayName = "None (Ambient Silence per Restraint Rule)"),
	ArulanTheme      UMETA(DisplayName = "Arulan Theme (Curious Solo Flute to Ensemble)"),
	RajendraTheme    UMETA(DisplayName = "Rajendra Theme (Low Strings, Sparse Percussion)"),
	GangaTheme       UMETA(DisplayName = "Ganga Theme (Sustained Tone, Two-Note Motif)"),
	CapitalTheme     UMETA(DisplayName = "Capital Theme (Percussion Construction to Full Hymn)"),
	TempleTheme      UMETA(DisplayName = "Temple Theme (Ceremonial Bell & Wind Textures)"),
	ConspiracyTheme  UMETA(DisplayName = "Conspiracy Theme (Low Irregular Tension, No Stingers)"),
	NavalTheme       UMETA(DisplayName = "Naval Theme (Open Winds, Rhythmic Oar Cadence)"),
	FinalLegacyTheme UMETA(DisplayName = "Final Legacy Theme (Accumulated Climax, Act 12)")
};

/**
 * Definition of a dynamic environmental soundscape profile.
 */
USTRUCT(BlueprintType)
struct GKAUDIO_API FGKSoundscapeDefinition
{
	GENERATED_BODY()

	FGKSoundscapeDefinition()
		: SoundscapeID(NAME_None)
		, PrimaryCategory(EGKAmbientSoundCategory::City)
		, WaterType(EGKWaterAcousticType::None)
		, ConstructionIntensity(0.0f)
		, CrowdMurmurIntensity(0.5f)
		, WindDustIntensity(0.2f)
		, ReverbDecaySeconds(1.5f)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio")
	FName SoundscapeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio")
	EGKAmbientSoundCategory PrimaryCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio")
	EGKWaterAcousticType WaterType;

	/** Intensity of chisel strikes, wooden hoists, and ox-cart rumbles (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ConstructionIntensity;

	/** Density of crowd chatter and footsteps (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CrowdMurmurIntensity;

	/** Atmospheric wind and dust whoosh (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float WindDustIntensity;

	/** Acoustic reverb decay time in seconds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GK|Audio")
	float ReverbDecaySeconds;
};
