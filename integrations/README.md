# Integrations

Technology-specific code belongs here, never in sentinel_core.

## Planned reference integrations

px4-gazebo-sitl:
a reproducible software-in-the-loop profile using a supported PX4 release and modern Gazebo.

ros2-observer:
read-only observation bridge for ROS 2 topics/services/actions with timestamp, QoS and schema metadata capture.

mcap-recorder:
high-rate evidence recorder mapped to run IDs.

hil-gateway:
laboratory adapter boundary with capability declaration, clock characterization and independent safety requirements.

fmi:
co-simulation adapter for FMI 3.x components.

hla:
optional distributed-simulation federation adapter.

sysml:
control-plane synchronization adapter for SysML v2 requirement/verification references.

## Integration rule

Each integration lives in its own build boundary and declares:
- supported native versions;
- canonical schema versions;
- clock modes;
- metrics;
- controllable test conditions;
- evidence metadata;
- contract tests;
- known limitations.

A native integration failure must not corrupt canonical campaign state.
