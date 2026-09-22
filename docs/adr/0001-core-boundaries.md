# ADR-0001: Keep the validation core technology-neutral

Status: accepted
Date: 2026-09-22

## Decision

sentinel_core has no direct dependency on ROS 2, PX4, Gazebo, DDS, Zenoh, Qt or a specific simulator.

## Rationale

The canonical experiment and evidence model should live longer than any one robotics middleware or simulator release.

## Consequences

Technology integrations require explicit adapters.
Core tests remain fast and deterministic.
Multiple transports/simulators can coexist and be compared.
