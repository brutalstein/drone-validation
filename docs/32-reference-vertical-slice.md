# First End-to-End Reference Vertical Slice

The next implementation target is a complete benign autonomous-navigation validation path. Depth is preferred over many shallow adapters.

## Objective

Demonstrate one canonical scenario from configuration through simulation, evidence, replay and boundary search without manual result editing.

## Components

Scenario loader:
validate YAML/JSON against the canonical schema and produce a resolved immutable scenario.

PX4/Gazebo adapter:
launch a pinned reference SITL profile, observe lifecycle/health and expose simulator capabilities through the adapter boundary.

ROS 2 observer:
read-only collection of selected state, timing and health signals. Preserve source timestamps, message type identity and QoS configuration.

Evidence recorder:
write resolved scenario, events, metrics, logs, environment/build metadata and high-rate telemetry. Produce a manifest with hashes.

Requirement evaluator:
map canonical metrics to requirement IDs and produce signed robustness margins where meaningful.

Replay:
restore exact pinned software/configuration for deterministic simulation replay.

Boundary search:
select one monotonic degraded-condition parameter, run bisection through the campaign API and confirm the discovered threshold using independent repetitions.

## Acceptance criteria

- one command configures and runs the reference campaign;
- no manual GUI action is required for a regression run;
- the same seed/configuration reproduces the deterministic result;
- every applied test condition appears on the evidence timeline;
- exact PX4, Gazebo, ROS 2 and adapter versions are in provenance;
- a failed requirement identifies first observed violation time;
- evidence can be consumed without the dashboard;
- replay creates a new evidence bundle linked to the original;
- changing a controller/software build produces a machine-readable comparison;
- all integrations remain outside sentinel_core.

## Deliberate exclusions

The reference vertical slice does not control payloads, implement targeting, model weapon effects or provide operational mission logic. It validates navigation/system-health behavior in a benign test environment.

## Completion gate

Do not call v1 complete until this path is reproducible on a clean supported host and in CI where simulator constraints permit.
