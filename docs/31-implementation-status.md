# Implementation Status

Checked: 2026-09-22.

This document distinguishes working code from design intent. Roadmap features must not be presented as implemented.

| Capability | Status | Evidence in repository |
|---|---|---|
| C++20 validation core | Implemented | include/sentinel/core, src/core |
| Deterministic fixed-step run lifecycle | Implemented | RunEngine |
| Controlled-condition activation/clearing | Implemented | FaultSpec + RunEngine events |
| Numeric requirement assertions | Implemented | AssertionSpec / AssertionResult |
| In-memory evidence model | Implemented | Evidence |
| Deterministic JSON evidence serialization | Implemented | sentinel/evidence/json |
| Monotonic one-dimensional boundary search | Implemented | sentinel/search/bisection |
| Generic custom adapter SDK | Implemented baseline | ISystemAdapter + examples/custom_adapter.cpp |
| CMake install/export package | Implemented | find_package(SentinelTwin), sentinel::core |
| Unit/regression tests | Implemented baseline | tests/ |
| GCC warnings-as-errors local verification | Verified | 2026-09-22 development verification |
| Docker build recipe | Implemented baseline | Dockerfile |
| GitHub CI workflow | Configured | .github/workflows/ci.yml |
| CodeQL workflow | Configured | .github/workflows/codeql.yml |
| Scenario/evidence JSON Schemas | Implemented baseline | schemas/ |
| YAML/JSON scenario parser | Planned | not yet implemented |
| Stable cryptographic run identity | Planned | schema/design only |
| MCAP evidence recorder | Planned | design only |
| OpenTelemetry instrumentation | Planned | design only |
| ROS 2 observer adapter | Planned | integrations/README.md |
| PX4 + Gazebo SITL adapter | Planned | integrations/README.md |
| DDS transport adapter | Planned | design only |
| Zenoh transport adapter | Planned | design only |
| FMI 3.x adapter | Planned | design only |
| HLA/DIS federation | Planned | design only |
| HIL gateway | Planned | design only |
| Web control plane | Planned | design only |
| Distributed campaign scheduler | Planned | design only |
| Bayesian/evolutionary search | Planned | design only |
| Simulation credibility service | Designed | docs/23-simulation-credibility.md |
| SysML v2 synchronization | Designed | docs/25-digital-thread-sysml.md |
| AI/ML assurance workflows | Designed | docs/24-ai-assurance.md |

## Current maturity

The repository is an executable architecture and SDK foundation, not a finished enterprise product.

The next release milestone should turn one planned vertical slice into a complete reference path:

canonical scenario -> PX4/Gazebo SITL -> ROS 2 observations -> requirements -> evidence bundle -> replay -> boundary search.

That vertical slice should be fully automated before broadening to more simulators or HIL.
