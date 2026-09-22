# Changelog

All notable changes to SENTINEL-TWIN are documented here.

The project is currently pre-1.0.

## [Unreleased]

### Added

- C++20 deterministic validation kernel.
- Technology-neutral system adapter interface.
- Scheduled controlled-condition model.
- Requirement assertions and evidence model.
- Deterministic JSON evidence serialization.
- One-dimensional monotonic boundary bisection search.
- Custom adapter example.
- Versioned scenario and evidence JSON schemas.
- Installable CMake package with sentinel::core target.
- Docker build recipe.
- Cross-compiler CI configuration and CodeQL workflow.
- AI-agent repository guidance through AGENTS.md and llms.txt.
- Architecture decision records.
- 2026-2036 roadmap.
- Enterprise adoption, simulation credibility, AI assurance and SysML v2 digital-thread designs.
- Security, performance, test, deployment, time, compatibility, data-governance and release-gate documentation.

### Verification

On 2026-09-22 the baseline was locally verified with GCC 14.2 and CMake/Ninja using warnings-as-errors. Both current test executables passed. Installation and downstream find_package(SentinelTwin) consumption were also verified.

### Not yet implemented

See docs/31-implementation-status.md. In particular, PX4/Gazebo, ROS 2, MCAP, OpenTelemetry, HIL, FMI, HLA/DIS and distributed orchestration are roadmap/integration work rather than completed features.
