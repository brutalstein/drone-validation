# Standards and Interoperability Roadmap

The platform stays standards-aware without binding the core to one standard.

## Systems engineering
SysML v2 for machine-readable requirements, behavior, analysis, verification and digital-thread links.

## Co-simulation
FMI 3.x for dynamic model exchange and co-simulation across heterogeneous tools.

## Distributed simulation
HLA and DIS through optional federation adapters where organizations already use them.

## Data distribution
DDS remains important in real-time distributed systems. DDS-XTypes evolution makes explicit schema identity and compatibility important. Zenoh is tracked as an emerging robotics data plane.

## Scenario exchange
ASAM OpenSCENARIO is automotive-centered, but its parameterization and X-in-the-loop concepts are useful. Prefer import/export adapters over copying its domain model into the core.

## Observability
OpenTelemetry for portable traces, metrics and logs.

## Evidence data
MCAP for high-rate heterogeneous robotics data and JSON Schema for small manifests/contracts.

## Supply chain
SLSA-compatible provenance, SBOM generation and signed artifacts are release-pipeline targets.
