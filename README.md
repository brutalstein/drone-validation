# SENTINEL-TWIN

**Autonomous Systems Validation, Falsification, Digital-Twin and Assurance Platform**

SENTINEL-TWIN is an open, vendor-neutral engineering platform for testing autonomous cyber-physical systems across simulation, software-in-the-loop (SIL), hardware-in-the-loop (HIL), vehicle-in-the-loop (VIL), replay, and eventually mixed-fidelity distributed test environments.

The project is intentionally **not a flight controller and not a weapon-control system**. Its job is to answer a harder engineering question:

> Under what reproducible conditions does an autonomous system stop satisfying its requirements, and what evidence proves it?

## Why this exists

Modern autonomous systems combine estimation, planning, networking, perception, real-time software, middleware, AI/ML components, embedded hardware and physical dynamics. Passing a few nominal simulations is not assurance.

SENTINEL-TWIN is designed around five principles:

1. **Find boundaries, not demos.** Search for minimal reproducible failure conditions instead of relying on hand-picked tests.
2. **Evidence is a first-class artifact.** Every run produces machine-readable provenance, configuration, timing, measurements, assertions and replay metadata.
3. **Adapters isolate technology churn.** The validation core is independent of ROS 2, PX4, Gazebo, DDS, Zenoh and any single simulator.
4. **Determinism where possible; uncertainty where necessary.** Seeds, clocks and artifacts are explicit. Stochastic behavior is measured rather than hidden.
5. **Assurance cases are built from traceable evidence.** Requirements, scenarios, faults, runs and results have stable IDs that can later map into MBSE / SysML v2 workflows.

## Current repository status

This repository establishes the **v0 architecture contract and executable core**:

- C++20 deterministic validation kernel
- adapter boundary for simulator / vehicle / middleware integrations
- scenario and evidence schemas
- fault model and assertions
- deterministic machine-readable JSON evidence serialization
- executable monotonic failure-boundary bisection search
- installable CMake package and custom-adapter example
- repeatable run / replay identity
- multi-strategy falsification-search roadmap
- ROS 2 / PX4 / Gazebo integration plan
- SIL → HIL → VIL maturity model
- observability, security and software-supply-chain design
- AI-agent-friendly documentation and contribution rules
- 2026–2036 technology roadmap

The repository contains a compilable reference kernel, deterministic tests, a working boundary-search primitive, evidence JSON serialization, and a custom-adapter example. Production robotics integrations remain separate adapters so they cannot contaminate the core experiment model.

## Target architecture

```text
                           ┌──────────────────────────────┐
                           │  Campaign / Search Service   │
                           │  grid | Bayesian | adversarial│
                           └──────────────┬───────────────┘
                                          │
                           ┌──────────────▼───────────────┐
                           │   Deterministic Run Engine   │
                           │ clock | seed | state | grading│
                           └───────┬───────────┬──────────┘
                                   │           │
                    ┌──────────────▼───┐   ┌──▼────────────────┐
                    │ Fault Injection   │   │ Evidence / Replay │
                    │ sensor/net/sw/hw  │   │ MCAP + JSON + hash│
                    └──────────────┬───┘   └──┬────────────────┘
                                   │           │
                           ┌───────▼───────────▼──────────┐
                           │      Adapter Contracts       │
                           └───┬────────┬────────┬────────┘
                               │        │        │
                            Gazebo    PX4      ROS 2      FMI/
                            /other   SITL/HIL  DDS/Zenoh   HLA
```

## Quick start

Ubuntu 24.04 or another recent Linux environment with CMake >= 3.25 and a C++20 compiler:

```bash
cmake -S . -B build -DSENTINEL_BUILD_TESTS=ON -DSENTINEL_BUILD_EXAMPLES=ON
cmake --build build -j
ctest --test-dir build --output-on-failure

./build/sentinel-cli
./build/sentinel-custom-adapter-example
```

The reference CLI executes an in-memory scenario and prints a deterministic evidence summary. Integration adapters will consume the same core contracts.

## Repository map

- `include/sentinel/` — stable public C++ interfaces
- `src/` — core and CLI implementation
- `tests/` — deterministic unit / contract tests
- `schemas/` — machine-readable scenario and evidence contracts
- `configs/` — example validation scenarios
- `docs/` — architecture, assurance, integration, roadmap and research
- `docs/adr/` — architecture decision records
- `.github/workflows/` — CI and security checks
- `AGENTS.md` / `llms.txt` — instructions and map for AI coding agents

## Design baseline (September 2026)

The architecture deliberately tracks current ecosystem direction without binding the product to it:

- ROS 2 **Lyrical Luth** is an LTS release supported to May 2031.
- Modern Gazebo has LTS lines; current releases show **Jetty** supported to May 2031 and **Harmonic** to May 2029.
- PX4 exposes ROS 2 integration through uXRCE-DDS and is also developing a Zenoh path, so transport is abstracted.
- SysML v2 is now a formal OMG specification and includes a standard API, making machine-readable requirements / verification traceability practical.
- FMI 3.x supports co-simulation and virtual ECU-style integration, useful for heterogeneous digital twins.
- DDS-XTypes continues to evolve, reinforcing the need for schema/version negotiation rather than hard-coded message layouts.
- OpenTelemetry provides stable C++ traces, metrics and logs; MCAP provides a practical high-performance robotics evidence container.

See `docs/reference/sources.md` for dated primary sources.

## Scope boundaries

The platform is for **verification, validation, reliability, safety engineering and research of autonomous systems**. Reference scenarios use benign navigation and system-health objectives. Project maintainers should not add payload-delivery, targeting, engagement, weapon-effects or other weapon-operation logic to the reference implementation.

## Roadmap

The long horizon is not “one simulator with a nice UI.” It is a validation fabric:

- **v0:** deterministic core, schemas, evidence identity
- **v1:** Gazebo/PX4 SITL adapter, ROS 2 observation, MCAP evidence
- **v2:** automated falsification, distributed campaign runner, HIL gateway
- **v3:** simulation-credibility scoring, cross-simulator differential testing
- **v4:** SysML v2 requirement traceability, FMI/HLA federation, enterprise APIs
- **v5:** mixed-fidelity fleets, runtime assurance evidence, hardware farms
- **2030+:** qualification-oriented evidence pipelines, AI-component assurance, digital-thread integration

Read `docs/18-roadmap-2026-2036.md`.

## License

Apache-2.0. See `LICENSE`.
