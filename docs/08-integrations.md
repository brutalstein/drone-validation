# Integrations

## ROS 2

ROS 2 is an adapter ecosystem, not a core dependency. The current Lyrical Luth release is LTS through May 2031. ROS adapters should preserve source timestamps, QoS metadata and message type identity.

## PX4

PX4 exposes ROS 2 integration through uXRCE-DDS and also has an experimental Zenoh path in the current mainline documentation. Transport therefore remains abstracted. The first reference integration should be PX4 SITL with modern Gazebo and ROS 2 observation.

## Gazebo

Simulator operations belong behind a simulator adapter. Support modern LTS lines by capability detection and compatibility tests rather than by embedding simulator assumptions in the core.

## DDS and Zenoh

Treat middleware as a replaceable data plane. QoS, discovery, security and schema/version information are run provenance.

## FMI

FMI 3.x is a strategic interface for importing and exporting dynamic models and co-simulation units, including virtual-controller style components.

## HLA / DIS

Organizations with existing distributed simulation infrastructure can use optional federation adapters. Canonical scenario and evidence semantics remain internal.

## SysML v2

Use the standard API for requirement and verification traceability. The platform links SysML elements by stable IDs instead of becoming a proprietary MBSE database.
