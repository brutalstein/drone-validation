# Future Control Plane API

The control plane API should be resource-oriented and versioned.

## Core resources

Scenario
Requirement
SystemBuild
AdapterCapability
Campaign
Run
EvidenceBundle
Worker
HardwareAsset
CredibilityRecord

## Operations

- validate and version a scenario;
- submit or cancel a campaign;
- reserve a hardware asset;
- stream run events;
- query requirement margins and discovered boundaries;
- fetch evidence manifests and artifacts;
- request replay;
- compare two runs;
- resolve requirement-to-evidence traceability.

## Constraints

API requests never contain arbitrary shell commands.
Workers execute declared capabilities, not arbitrary remote code.
Schema versions are explicit.
Long-running actions are represented as jobs with immutable input snapshots.
Every mutating operation is auditable.
