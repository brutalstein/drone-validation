# Performance Engineering

## Core goals

- predictable event ordering;
- bounded allocation in hot paths where practical;
- no hidden blocking I/O in deterministic step execution;
- batched evidence writes;
- control plane separated from data plane.

## Real-time

The core does not claim hard real-time behavior. HIL adapters may require real-time-capable hosts, CPU isolation, thread priorities and measured scheduling latency. Such settings are run evidence, not undocumented machine configuration.

## Scaling

Campaign-level parallelism is straightforward until scarce hardware is involved. A run is the scheduling unit; HIL resources use leases and capability matching.

## Data path

High-rate telemetry streams into chunked/indexed storage instead of accumulating indefinitely in memory.

## Future benchmarks

- core-only simulated runs per second;
- event scheduler overhead;
- adapter round-trip latency;
- evidence write throughput;
- replay speed;
- campaign scheduling overhead;
- p50/p95/p99 timing distributions.
