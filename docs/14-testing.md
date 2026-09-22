# Testing Strategy

## Unit tests

Comparator semantics, condition scheduling, lifecycle, schema normalization, ID generation and evidence assembly.

## Contract tests

Every adapter must pass the same lifecycle, capability and error-handling suite.

## Golden tests

Small canonical scenarios with stable evidence summaries.

## Differential tests

Execute the same scenario against two builds, transports or simulators and compare declared outputs.

## Property tests

Useful for schema round-trips, ID stability, time ordering and invariants.

## Resilience tests

The validation platform itself must be tested under adapter crashes, malformed telemetry, clock discontinuity, disk pressure and worker termination.

## Determinism

A deterministic regression must fail when event ordering or evidence identity changes unexpectedly.

## HIL

Laboratory jobs require rig identity, calibration state, reservation metadata and a safety checklist. They are separate from ordinary CI.
