# Observability

Validation failures often emerge from timing and interaction rather than a single bad value. Traces, metrics and logs are therefore first-class evidence.

## Signals

Metrics:
rates, latency distributions, error norms, resource use and queue depth.

Traces:
causal paths across orchestrator, adapters and services.

Logs:
structured events carrying run ID, component ID and experiment timestamp.

Profiles:
optional CPU and memory performance evidence.

## OpenTelemetry

The architecture targets OpenTelemetry-compatible instrumentation. The current C++ ecosystem provides stable traces, metrics and logs.

## Clock correlation

Each telemetry item should preserve:
- experiment time;
- source timestamp when available;
- ingest monotonic timestamp;
- wall-clock timestamp for operator correlation.

Wall clock alone is never sufficient to reconstruct simulation ordering.

## Cardinality

Unbounded scenario or message content must not become metric labels. High-cardinality content belongs in events or artifacts.
