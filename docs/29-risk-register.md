# Architecture Risk Register

This is a living engineering risk register.

## R1: simulator coupling

Risk:
validation semantics become tied to one simulator.

Control:
technology-neutral core and adapter contracts.

Trigger:
core headers import simulator types.

## R2: irreproducible experiments

Risk:
failures cannot be recreated because seed, time, binaries or configuration are missing.

Control:
immutable resolved scenarios, provenance and explicit clock models.

Trigger:
a run cannot state its exact input/build identity.

## R3: evidence volume explosion

Risk:
telemetry storage makes campaigns operationally expensive.

Control:
retention tiers, selective recording, chunked formats and small permanent manifests.

Trigger:
campaign cost scales mainly with unbounded logging rather than engineering value.

## R4: false confidence from simulation

Risk:
high simulation pass rates are mistaken for physical-system assurance.

Control:
credibility records, multi-fidelity confirmation and scoped claims.

Trigger:
evidence omits model validity envelope.

## R5: middleware churn

Risk:
DDS, Zenoh, ROS or message-version changes break historical scenarios.

Control:
transport abstraction, schema identity and adapter compatibility metadata.

Trigger:
canonical scenario files contain native message definitions.

## R6: optimizer-induced false findings

Risk:
automated search exploits simulation artifacts or stochastic noise.

Control:
robustness margins, confirmation runs, multi-seed analysis and higher-fidelity escalation.

Trigger:
a finding exists only in discovery runs.

## R7: AI analysis hallucination

Risk:
AI-generated root-cause text is treated as evidence.

Control:
every analysis statement links to concrete runs and measurements; AI output is advisory.

Trigger:
an assurance claim cites generated prose without source evidence.

## R8: HIL safety coupling

Risk:
test orchestration becomes part of the physical safety boundary.

Control:
independent interlocks, e-stop and rig procedures.

Trigger:
loss of SENTINEL-TWIN software can create an unsafe physical condition.

## R9: schema fragmentation

Risk:
teams fork incompatible scenario/evidence formats.

Control:
formal versioning, extension namespaces and migration tests.

Trigger:
organization-specific fields reinterpret canonical semantics.

## R10: premature distributed complexity

Risk:
control-plane features slow the core before repeatable single-run semantics are mature.

Control:
keep run kernel local and deterministic first; distribute at campaign level.

Trigger:
network consensus or orchestration dependencies enter sentinel_core.
