# Engineering Release Gates

A SENTINEL-TWIN release should be promoted by evidence, not by calendar alone.

## Gate A: build integrity

Required:
- supported compiler matrix passes;
- warnings-as-errors passes;
- deterministic unit/contract tests pass;
- install/package-consumer smoke test passes;
- static analysis has no unresolved release-blocking findings.

## Gate B: schema integrity

Required:
- scenario/evidence schemas validate;
- compatibility policy is satisfied;
- schema migrations have tests;
- golden evidence remains readable or is explicitly migrated.

## Gate C: replay integrity

Required:
- reference deterministic scenarios replay with expected event ordering;
- known seeds reproduce expected requirement outcomes;
- adapter contract tests pass for supported reference adapters.

## Gate D: evidence integrity

Required:
- manifests are complete;
- artifact hashes verify;
- build/source identity is present;
- clock mode and adapter versions are recorded;
- no secrets appear in generated evidence.

## Gate E: integration integrity

For each supported integration profile:
- versions are pinned or bounded;
- capabilities are declared;
- one nominal scenario passes;
- one controlled degraded scenario produces the expected evidence;
- unsupported capabilities fail explicitly.

## Gate F: laboratory integrity

For HIL-enabled releases:
- rig identity and calibration are current;
- independent safety controls are verified outside SENTINEL-TWIN;
- timing characterization is recorded;
- laboratory test procedures are versioned.

## Gate G: documentation integrity

Required:
- README matches implemented capabilities;
- roadmap items are not presented as implemented;
- API and schemas are documented;
- ADRs exist for architecture changes;
- primary-source research notes include a checked date.

## Release evidence

Each release should publish a machine-readable release manifest containing source commit, toolchain, dependency/SBOM references, test summaries and provenance attestations.
