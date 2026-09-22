# Versioning and Compatibility Policy

SENTINEL-TWIN separates product, schema, adapter and evidence compatibility.

## Product versions

Tagged releases follow semantic versioning after the 0.x incubation period.

During 0.x:
- public C++ interfaces may evolve;
- schema changes are still versioned explicitly;
- migration notes are required for incompatible evidence or scenario changes.

After 1.0:
- MAJOR changes may break public API or canonical schema compatibility;
- MINOR changes add backward-compatible capabilities;
- PATCH changes fix behavior without changing declared contracts.

## Schema versions

Scenario and evidence schemas have their own versions. A binary must declare which versions it can read and write.

Rules:
- never reinterpret an existing field silently;
- additions should be optional when backward compatibility is intended;
- removals require a major schema version;
- migration is explicit and testable;
- original evidence remains immutable even after migration.

## Adapter compatibility

Each adapter exposes:
- adapter semantic version;
- native dependency versions;
- supported canonical schema versions;
- supported clock modes;
- observable metrics;
- controllable test conditions;
- known limitations.

## Replay compatibility

Exact replay requires exact build and adapter identities where deterministic behavior depends on them.

Semantic replay may use newer compatible components, but it creates a new run and new evidence. Historical evidence is never overwritten.

## Long-term support

Enterprise deployments should select named compatibility profiles that pin:
compiler, standard library ABI, OS/container base, middleware, simulator, controller, schemas and adapter versions.

The project roadmap should always contain at least one conservative long-support profile and one current-feature profile.
