# AI Agent Guide

AI coding agents are expected to work from architecture rather than pattern-match isolated files.

## Before editing

Read AGENTS.md and the relevant numbered documents. Search for a stable entity or interface before inventing a new one.

## Preferred workflow

1. State the invariant being changed.
2. Modify the smallest architectural layer.
3. Add deterministic tests.
4. Update schemas and docs when external behavior changes.
5. Add an ADR for durable tradeoffs.
6. Run build and tests.
7. Report compatibility and evidence impact.

## Context compression

When context is limited, read in this order:

README -> AGENTS -> docs/01 -> docs/02 -> relevant feature document -> public headers -> implementation.

## Never

- couple the core to ROS, PX4, Gazebo, DDS or Zenoh;
- silently change evidence formats;
- hide nondeterminism behind automatic retries;
- invent certification claims;
- make laboratory physical safety dependent on this software;
- merge a new adapter without contract tests.
