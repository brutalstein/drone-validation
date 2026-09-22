# Evidence and Replay

Evidence is the primary product.

## Recommended bundle

manifest.json
scenario.resolved.json
requirements.json
telemetry.mcap
events.jsonl
traces/
logs/
system/
artifacts/

## Manifest

The manifest records run ID, scenario ID, seed, status, source commit, build identity, container identity when used, adapter versions, clock mode and artifact hashes.

## High-rate data

MCAP is the planned heterogeneous time-series container. It supports indexed, timestamped streams and can carry multiple serialization families.

## Observability

OpenTelemetry-compatible traces, metrics and logs share the same run ID and explicit time correlation.

## Replay levels

Exact replay: same binaries, seed and deterministic simulation.

Semantic replay: equivalent scenario on newer compatible components.

HIL replay: recreate stimuli and timing envelopes while accepting measured physical nondeterminism.

Differential replay: execute the same canonical scenario against two builds, middleware configurations or simulators.

## Integrity

Artifacts receive SHA-256 hashes. Mature release pipelines should add signed provenance, SBOMs and SLSA-compatible attestations.
