# Architecture

SENTINEL-TWIN uses inward-facing dependencies.

## Contracts
Scenario, controlled perturbation, assertion, evidence and adapter contracts are stable, versioned interfaces.

## Deterministic run kernel
Owns experiment time, seed, event ordering, condition scheduling and requirement evaluation. It must run without ROS, PX4 or a simulator.

## Evidence plane
Stores manifests, hashes, time series, traces, logs, simulator artifacts and replay metadata.

## Adapters
Translate canonical contracts into simulator, middleware, controller and laboratory operations. Technology-specific dependencies remain outside the core.

## Campaign engine
Generates parameter sets and executes search strategies against the run kernel.

## Control plane
Schedules workers and hardware assets, indexes evidence and exposes enterprise APIs.

## Time
Each run has a canonical experiment clock and explicit mappings to source, monotonic and wall clocks.

## Identity
Requirements, scenarios, builds, runs and evidence have stable IDs so the digital thread survives tool replacement.
