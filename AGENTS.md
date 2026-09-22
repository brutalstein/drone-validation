# AI Agent Operating Guide

This repository is optimized for human + AI engineering.

## Mission
Build a vendor-neutral validation and assurance platform for autonomous cyber-physical systems. Discover reproducible failure boundaries, record evidence, and support SIL/HIL/VIL workflows.

## Non-negotiable invariants
1. Core must not depend on ROS 2, PX4, Gazebo, DDS, Zenoh, Qt or a specific simulator.
2. Every experiment has stable scenario ID, seed, clock model and evidence identity.
3. Integrations implement adapters; vendor types never leak into sentinel/core.
4. Reference scenarios stay benign validation scenarios. No targeting, payload-delivery, weapon-effects or engagement logic.
5. Evidence is append-oriented and machine-readable.
6. Schema changes require a version bump and migration note.
7. Tests are deterministic unless explicitly marked stochastic.
8. Prefer open standards and portable formats.

## Read order
README.md
docs/00-vision.md
docs/01-architecture.md
docs/02-domain-model.md
docs/03-scenario-engine.md
docs/06-evidence-and-replay.md
docs/17-agent-guide.md
docs/adr/

## Definition of done
Builds cleanly, tests pass, public contracts are documented, evidence impact is described, deterministic behavior is preserved, and architecture docs/ADRs are updated when needed.

## Commit style
Conventional Commits: feat:, fix:, docs:, test:, refactor:, perf:, build:, ci:, chore:.

## Review questions
Can this be replayed?
Can this be tested without the simulator?
Does it preserve IDs and provenance?
What happens when middleware/simulator versions change?
Is time explicit?
Is uncertainty measured rather than hidden?
