# GANGAIKONDA — Performance Budget & Optimization Specification

**Document ID:** PERF-01 · **Version:** 1.0  
**Target Hardware:** Current-Gen Console Equivalent (PS5 / Xbox Series X / Modern PC)  
**Frame Rate Targets:** 30 fps Floor (33.33ms) / 60 fps Target (16.66ms) (Doc 01 §35)  
**Dependencies:** Doc 01 §35, Doc 17 §5, Doc 18 §1, Doc 34, Doc 38 (PF-001)

---

## 1. Frame Time Budget Allocation (16.66ms Target @ 60 FPS)

```
Total Frame Budget: 16.66 ms
├── Game Thread (CPU):   8.0 ms Max
├── Render Thread (CPU): 6.0 ms Max
└── GPU Frame Time:     12.0 ms Max
```

### A. Game Thread Budget (8.0ms Ceiling)
| Subsystem | Budget | Description | Optimization Technique |
| :--- | :--- | :--- | :--- |
| **Character Locomotion** | 1.5 ms | Arulan locomotion, camera boom probe collision, IK foot placement | Simple sphere raycasts, single-character tick |
| **Mass Entity Crowds** | 1.2 ms | 1,000 background craftsmen, quarry workers, and citizens (Doc 13 §2) | Fragment-based Mass processors (~24 bytes/entity), job worker threads |
| **AI Stealth & Perception** | 1.8 ms | Guard sight cone sweeps, suspicion decay, crowd-blending tests | 20 Hz tick throttling, cone sweeps batched over multiple frames |
| **Quests & World State** | 0.8 ms | Quest state evaluations, objective triggers, construction flags | Event-driven pub/sub (no per-frame ticking) |
| **Audio Subsystem** | 0.5 ms | Soundscape crossfading, water acoustics, score restraint checks | Subsystem event triggers only |
| **Headroom Buffer** | 2.2 ms | GC spikes, OS jitter, and miscellaneous engine overhead | Safety margin for 60 fps lock |

### B. Render Thread Budget (6.0ms Ceiling)
| Task | Budget | Threshold Limit |
| :--- | :--- | :--- |
| **Visibility & Occlusion Culling** | 2.5 ms | Hardware occlusion queries + Nanite cluster culling |
| **Draw Call Submission** | 3.0 ms | **< 1,500 Draw Calls per frame** (Nanite merges static mesh draws into single indirect passes) |
| **Render Thread Overhead** | 0.5 ms | Command list dispatch |

### C. GPU Budget (12.0ms Ceiling @ 1440p TSR / Dynamic 4K)
| Pass | Budget | Configuration (UE 5.4+) |
| :--- | :--- | :--- |
| **Nanite Base Pass** | 2.5 ms | `r.Nanite=1`, `r.Nanite.MaxPixelsPerEdge=1.0` (all granite courses, scaffolding timbers, architectural reliefs) |
| **Virtual Shadow Maps (VSM)** | 3.0 ms | `r.Shadow.Virtual.Enable=1`, resolution LOD bias directional `-0.5` (sharp scaffolding penumbras) |
| **Lumen Global Illumination** | 3.5 ms | Software ray tracing default, screen probe downsample factor `16` (Doc 18 / 34) |
| **Post-Processing & TSR** | 2.0 ms | Temporal Super Resolution (`r.AntiAliasingMethod=4`), exposure, tone curve |
| **UI & Slate** | 0.5 ms | Minimal HUD & MVVM data binding (no floating damage numbers) |
| **Safety Margin** | 0.5 ms | Thermal throttle buffer |

---

## 2. Memory Budgets

### VRAM Budget (6.0 GB Total Ceiling)
- **Nanite Mesh Cache:** 1,200 MB
- **Virtual Shadow Maps & Depths:** 800 MB
- **Streaming Virtual Textures (Granite, Bronze, Textiles):** 2,200 MB
- **Lumen Scene & Surface Cache:** 1,000 MB
- **Framebuffers & Post-Process Pipelines:** 800 MB

### System RAM Budget (8.0 GB Game Process Ceiling)
- **Engine Core & World Partition Streaming:** 3,500 MB
- **Mass Entity Population Tables (1,000+ entities):** < 50 MB
- **Audio Sound Banks & Foley:** 800 MB
- **Animation Sequences & Motion Data:** 1,500 MB
- **Level Geometry & Collision BVH:** 1,200 MB
- **Free Headroom:** ~950 MB

---

## 3. Motivated Lighting Verification Checklist (Doc 17 §5, Doc 34)

- [x] **No Unmotivated Lights:** Every point/spot light is anchored to an in-world diya, torch, or oil lamp.
- [x] **Gold Accent Doctrine:** Gold is restricted to material specular reflection and accents; ambient gold bloom wash is strictly prohibited (`BloomIntensity <= 0.35`).
- [x] **Act 4 Restraint:** The Ganga expedition sequence uses flat diffuse overcast lighting without cinematic hero backlighting (Doc 05 Cinematic 003).
- [x] **Time-of-Day Kelvin Calibration:**
  - Dawn: 3800 K (warm directional + mist)
  - Noon: 6200 K (harsh tropical sunlight + construction dust)
  - Sunset: 3200 K (silhouette gold highlights)
  - Night: 6800 K moonlight + 2200 K oil flame
