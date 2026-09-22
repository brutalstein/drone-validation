# ADR-0002: Evidence is a first-class immutable output

Status: accepted
Date: 2026-09-22

## Decision

Every completed run produces a versioned evidence manifest referencing immutable, hashed artifacts.

## Rationale

Validation results without provenance, timing context and replay metadata are difficult to audit, compare or reproduce.

## Consequences

Artifact identity is part of API design.
Schema migration must be managed.
Storage and retention become explicit engineering concerns.
