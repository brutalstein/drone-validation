# Security Architecture

## Trust boundaries

Scenario input, adapter processes, simulator plugins, telemetry sources, CI dependencies, workers and artifact stores are separate trust boundaries.

## Principles

- least privilege;
- no shell execution from scenario data;
- isolated adapters;
- disposable workers;
- secrets excluded from evidence bundles;
- network access restricted in laboratory deployments;
- artifact hashes and build provenance;
- pinned dependencies and images;
- separation of orchestration from physical safety controls.

## Adapter isolation

Third-party integrations should support out-of-process execution. A malformed message or adapter crash must not corrupt campaign state.

## Laboratory systems

The control plane must not be the physical safety boundary. Independent interlocks, e-stop mechanisms and safe rig design remain mandatory.

## Software supply chain

The release pipeline should evolve toward signed releases, SBOMs, dependency review, reproducible-build practices where feasible and SLSA-compatible provenance.
