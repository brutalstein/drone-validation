# Security Policy

## Scope
Treat scenario files, adapters, simulator plugins, telemetry streams, CI dependencies, worker nodes and artifact stores as separate trust boundaries.

## Baseline controls
- Validate schemas before execution.
- Bound resource use.
- Never execute shell commands from scenario data.
- Isolate adapters.
- Use explicit network allowlists in lab deployments.
- Hash artifacts and record provenance.
- Pin dependencies and scan in CI.
- Keep secrets out of evidence.
- Separate orchestration from safety-critical controllers.

## HIL safety
HIL rigs require independent electrical and physical safety mechanisms. This software must never be the only e-stop, interlock or energy-limiting control.

## Reporting
Use GitHub private vulnerability reporting when enabled, or contact the repository owner through GitHub. Do not publish an exploitable issue before remediation is available.
