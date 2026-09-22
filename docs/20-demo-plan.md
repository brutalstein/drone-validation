# Evaluation Demo Plan

The demo should show engineering evidence rather than a cinematic dashboard.

## Demo 1: deterministic baseline

Execute the same scenario twice. Show identical scenario ID, seed, event sequence and outcome.

## Demo 2: controlled degradation

Introduce a benign sensor-availability change and network delay. Show activation on the timeline and requirement margins.

## Demo 3: boundary search

Automatically vary one degradation parameter and converge on the smallest value that violates a requirement. Run independent confirmation repetitions.

## Demo 4: replay

Select a failed run and replay it from the evidence manifest. Demonstrate reproducible simulation outcome.

## Demo 5: build comparison

Execute the same scenario against two system builds and show regression deltas by requirement.

## Demo 6: HIL transition

Move the same canonical scenario ID to a safely configured HIL bench. Show the additional timing, calibration and rig evidence.

## Demo 7: digital thread

Show one requirement linked to scenario, run, evidence files, software build and comparison report.

## What evaluators should see

Clear architecture.
Traceable requirements.
Measured timing.
Reproducible boundaries.
Machine-readable evidence.
No hand-edited result screens.
