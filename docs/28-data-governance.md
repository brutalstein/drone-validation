# Validation Data Governance

Validation evidence can contain large volumes of telemetry, proprietary system information and potentially sensitive laboratory metadata. Data policy is therefore part of system architecture.

## Data classes

Configuration:
scenario, requirements, adapter settings and model parameters.

Operational evidence:
telemetry, events, traces, metrics, logs and profiles.

Provenance:
software versions, source commits, build identities, container digests and hardware identities.

Derived analysis:
comparisons, summaries, boundary estimates and credibility calculations.

## Principles

- evidence is immutable after finalization;
- derived analysis references source evidence rather than copying it silently;
- retention policy is explicit by data class;
- sensitive fields can be redacted only through a traceable export process;
- secrets and credentials never belong in evidence;
- organizations can keep all evidence on-premises or offline;
- metadata indexes should be rebuildable from authoritative manifests.

## Storage tiers

Hot:
recent campaigns and active debugging.

Warm:
release-validation baselines and comparison history.

Cold:
long-term assurance and audit evidence.

## Reproducibility metadata

Do not discard small metadata because large telemetry is expensive. Scenario, seed, build identity, adapter versions, requirement IDs, hashes and clock configuration should survive even when high-volume data reaches its retention limit.

## Export

Evidence export should support a portable bundle containing manifests, selected artifacts, checksums and schema versions without requiring the original database.
