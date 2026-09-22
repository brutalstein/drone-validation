# Controlled Conditions

SENTINEL-TWIN models degraded and edge conditions through one canonical contract rather than simulator-specific scripts.

## Taxonomy

Sensor:
availability, freeze, bias, drift, noise, latency and rate reduction.

Network:
latency, jitter, loss, duplication, reordering, bandwidth limits and partitions.

Compute:
CPU pressure, memory pressure, scheduling delay, process pause and restart.

Software:
service unavailable, stale data and controlled adapter-boundary errors.

Time:
clock offset, drift and timestamp discontinuity.

Environment:
model-parameter variation through simulator adapters.

Laboratory hardware:
only through independently safe interfaces and with rig-specific limits.

## Contract

Every condition has a stable ID, target, activation interval and explicit parameters. Activation and clearing are evidence events.

## Calibration

Ranges should come from requirements, measured distributions or explicitly labeled exploratory envelopes. Randomness is always seeded and recorded.
