# Enterprise Adoption Path

The goal is to let an engineering team evaluate SENTINEL-TWIN without replacing its existing simulator, controller, middleware or requirements tool.

## First hour: prove the core

1. Build sentinel_core and run the deterministic tests.
2. Run sentinel-cli twice and compare outcomes.
3. Build examples/custom_adapter.cpp.
4. Inspect the evidence JSON and scenario/evidence schemas.
5. Confirm that no robotics middleware is required by the core.

Success criterion: the team understands the canonical run lifecycle and can link sentinel::core from its own CMake project.

## First day: connect one system

1. Select a non-destructive validation target.
2. Implement ISystemAdapter around an existing simulator or software component.
3. Map three to five engineering metrics into canonical names.
4. Define one nominal and one degraded-condition scenario.
5. Link assertions to existing requirement IDs.
6. Record exact build and adapter versions.

Success criterion: the same requirement is evaluated reproducibly through the team's native system.

## First week: create a regression campaign

1. Add a scenario catalog.
2. Add boundary search for one monotonic degradation parameter.
3. Store evidence bundles in CI artifacts or object storage.
4. Compare the current system build with a previous build.
5. Define adapter contract tests.
6. Establish evidence retention and access-control policy.

Success criterion: a software change can be traced to a measurable requirement-margin change.

## First month: laboratory integration

Add an isolated HIL adapter, rig capability descriptor, calibration metadata, explicit clock synchronization, reservation/lease controls and independent physical safety procedures.

Success criterion: one canonical scenario can move from SIL to HIL without changing its requirement identity.

## Enterprise integration principles

- Keep proprietary system details inside organization-owned adapters.
- Preserve stable IDs across tools.
- Treat simulator models as versioned engineering assets.
- Store exact configuration with every run.
- Separate discovery campaigns from confirmation campaigns.
- Never let dashboard state become the source of truth; evidence artifacts are authoritative.
- Support offline and restricted-network operation.
