# ADR-0003: Abstract robotics transport

Status: accepted
Date: 2026-09-22

## Decision

Canonical observations and test conditions do not depend on DDS or Zenoh types. Transport adapters expose capabilities and provenance.

## Rationale

Robotics middleware is evolving. PX4 already supports uXRCE-DDS and is developing a Zenoh path, so transport-specific assumptions should not define validation semantics.

## Consequences

Message/schema identity is mapped explicitly.
QoS and transport configuration are evidence.
Transport differential testing becomes possible.
