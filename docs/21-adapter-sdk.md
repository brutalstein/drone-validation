# Adapter SDK

The adapter boundary is how an external simulator, controller, robotics stack or laboratory system joins SENTINEL-TWIN without changing validation semantics.

## Integration model available now

Implement sentinel::ISystemAdapter in C++.

Required lifecycle:
1. reset(seed)
2. set_fault(condition, active)
3. step(dt)
4. metric(name)
5. snapshot()

The run engine owns experiment ordering. The adapter owns translation into the system-under-test.

See examples/custom_adapter.cpp.

## Adapter responsibilities

- map canonical metric names to native data;
- preserve source timestamps when applicable;
- expose deterministic reset where possible;
- make applied test conditions observable;
- fail explicitly when a requested capability is unavailable;
- avoid hidden retries that change experiment semantics;
- keep native library types outside sentinel/core.

## Capability declaration

The next adapter API revision will add explicit capability descriptors: clock modes, controllable conditions, observable metrics, supported schema versions and integration versions.

## Planned out-of-process SDK

For proprietary tools or language isolation, a sidecar protocol will provide the same lifecycle over a versioned message contract. This enables adapters in Python, Rust, C#, Java and vendor-specific environments without linking them into the core process.

## Enterprise rule

An organization should be able to replace a simulator, middleware or controller implementation while retaining scenario IDs, requirement IDs, evidence structure and campaign history.
