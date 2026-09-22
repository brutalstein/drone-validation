# SIL, HIL and VIL Maturity

## L0: core-only
Validate experiment semantics with deterministic mock adapters.

## L1: model-in-the-loop
Plant and controller models share a simulation context.

## L2: software-in-the-loop
Production controller/autonomy binaries communicate with a simulator.

## L3: hardware-in-the-loop
Real control hardware runs production-like firmware while the environment and sensors are simulated through safe laboratory interfaces.

## L4: subsystem-in-the-loop
Companion compute, networking and selected real sensors are introduced.

## L5: controlled physical test
A benign test vehicle operates in a controlled environment with independent safety controls.

## Rule

Moving between levels changes timing, interfaces, noise, calibration and failure modes. Fidelity must be qualified for the engineering question.

## Cross-level traceability

The same canonical scenario ID and requirement IDs should survive across levels. Adapter, rig and calibration configuration become additional evidence rather than new test definitions.
