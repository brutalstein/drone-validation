# Research Notes: September 2026 Baseline

Checked: 2026-09-22.

These notes capture public, primary-source signals that shaped the architecture. They are not claims about confidential company programs.

## ROKETSAN public hiring signal

A ROKETSAN simulation-systems engineering posting published 2026-09-20 asks for experience spanning C/C++ or modeling tools, dynamic-system and sensor modeling, simulation application development, systems engineering, verification/validation, requirements traceability, GUI frameworks, TCP/IP and UDP, with DIS/HLA/DDS listed as preferred experience.

Architecture implication:
keep a high-performance C++ core, make requirements traceable, support real/semi-real-time execution, keep simulation modular, and plan optional distributed-simulation adapters.

## Baykar public digital-engineering signal

Baykar and Leonardo reported K-SWARM live trials on 2026-06-22 and explicitly described the transition from simulation to live operation using a digital-engineering approach.

Architecture implication:
preserve the same scenario/requirement identity across simulation, HIL and physical test instead of creating disconnected test stacks.

## ASELSAN public AI strategy

ASELSAN's published 2025-2030 AI Strategy and Action Plan states an objective of applying AI across products, systems and business processes.

Architecture implication:
learning-enabled components must fit inside the same evidence, replay, model-identity and assurance framework as conventional software.

## International autonomy assurance

DARPA's completed Assured Autonomy program focused on continual assurance for learning-enabled cyber-physical systems.

NATO DIANA's 2026 Autonomy & Unmanned Systems area highlights operation in complex and degraded environments, including disrupted communication and unreliable positioning signals.

Architecture implication:
validation should systematically explore degraded conditions and produce repeatable evidence rather than depend on nominal demonstrations.

## Ecosystem direction

ROS 2 Lyrical Luth is LTS through May 2031.
Gazebo Jetty is LTS through May 2031 in the current release table.
PX4 documents uXRCE-DDS as established and Zenoh as an experimental alternative.
SysML v2 is a formal OMG standard with an API.
FMI 3.0.x supports co-simulation and virtual-controller style model packaging.
DDS-XTypes continues to evolve in 2026.
OpenTelemetry C++ traces, metrics and logs are stable.
MCAP is designed for heterogeneous timestamped pub/sub data.

See docs/reference/sources.md.
