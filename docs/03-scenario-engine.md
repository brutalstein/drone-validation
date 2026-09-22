# Scenario Engine

Lifecycle:

validate -> resolve -> reset adapter -> schedule controlled conditions -> step -> sample -> evaluate -> finalize -> emit evidence.

## Determinism contract

Given the same canonical scenario, seed, system build and deterministic adapter, the event sequence and assertion outcome must be reproducible.

## Clocking

The initial engine uses fixed-step simulation time. Planned clock modes:
- external-clock follower for HIL;
- variable-step co-simulation;
- real-time synchronized mode;
- distributed logical time for federation.

Clock mode is evidence.

## Schema

Public schemas are versioned independently from C++ types. Parsers normalize YAML/JSON into the canonical Scenario object.

## Temporal evaluation

A future evaluator interface will support bounded temporal rules, event sequences and statistical acceptance criteria without overloading basic numeric comparators.

## Run status

Invalid: the experiment could not execute meaningfully.
Failed: it executed and at least one requirement was violated.
Aborted: reserved for infrastructure or operator termination in the distributed runner.
