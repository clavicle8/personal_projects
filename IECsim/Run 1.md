# Run 1 — Sun 12 April 2026
**IBSimu 1.0.6dev** | IEC Fusor — Tee Chamber, N₂ Ion Trajectories

---

## Geometry
- Loaded from `geom.dat`
- ⚠️ `Warning: loading of STLSolid not implemented` (×3)

---

## Poisson Solver — BiCGSTAB-ILU0
| Parameter | Value |
|---|---|
| Degrees of freedom | 16,957,183 |
| imax | 10,000 |
| eps | 0.0001 |
| Iterations | 168 |
| Error estimate | 9.63 × 10⁻⁵ ✓ |
| Wall time | 183.976 s |

---

## Particle Histories
| Metric | Value |
|---|---|
| Total | 1,000 |
| Flown | 984 |
| Step-count limited | 16 |
| Time limited | 0 |
| Bad definitions | 0 |
| Ave steps/particle | 92.9 |

### Boundary Currents
| Boundary | Description | Current (A) | Particles |
|---|---|---|---|
| 1 | Domain face | 5.28 × 10⁻⁴ | 264 |
| 2 | Domain face | 2.42 × 10⁻⁴ | 121 |
| 3 | Domain face | 4.04 × 10⁻⁴ | 202 |
| 4 | Domain face | 3.88 × 10⁻⁴ | 194 |
| 5 | Domain face | 2.20 × 10⁻⁵ | 11 |
| 6 | Domain face | 3.84 × 10⁻⁴ | 192 |
| 7 | Tee chamber | 0 | 0 |
| 8 | Cathode grid | 0 | 0 |
| 9 | Anode grid | 0 | 0 |

---

## Review
- ❌ Wrong cathode potential polarity (+5000 V instead of −5000 V) — repelled positive ions outward, all particles hit domain walls
- ✅ Solver converged cleanly, zero bad particle definitions
