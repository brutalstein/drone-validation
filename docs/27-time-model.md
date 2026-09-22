# Canonical Time Model

Time is a first-class experimental variable.

## Clock domains

Experiment time:
the canonical logical time used for scenario scheduling and requirement evaluation.

Source time:
timestamp produced by a sensor, simulator, controller or middleware participant.

Monotonic ingest time:
local monotonic timestamp when the platform observed an item.

Wall time:
UTC timestamp used for operator and external-system correlation.

Hardware time:
optional PTP, GNSS-disciplined or device clock used by laboratory equipment.

## Rules

- Scenario scheduling uses experiment time.
- Wall time is never used as the sole event-ordering source.
- Clock-domain transformations are explicit evidence.
- Clock resets, jumps and drift are events, not silently corrected behavior.
- HIL runs record synchronization method and measured synchronization error.
- Cross-machine traces include uncertainty when clocks are not tightly synchronized.

## Real-time factor

Simulation speed and real-time factor are evidence. A simulation that falls behind wall time may still be scientifically valid, but a HIL interface with timing requirements may not be.

## Distributed execution

Future federation support should distinguish conservative logical ordering from wall-clock synchronization. HLA time-management behavior or equivalent adapter behavior must be declared in the run manifest.

## Deterministic replay

Replay is deterministic only to the extent that the clock model, event ordering and adapter behavior are deterministic. Claims of exact replay must name these assumptions.
