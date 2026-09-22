# Digital Thread and SysML v2

The long-lived value of the platform is the traceable chain from engineering intent to evidence.

## Canonical relationship

Requirement
  -> verification method
  -> scenario
  -> resolved configuration
  -> system build
  -> run
  -> assertion result
  -> evidence bundle
  -> comparison / assurance claim

## SysML v2 strategy

SysML v2 is integrated at the control-plane boundary through its standard API. SENTINEL-TWIN does not duplicate the systems model.

The platform stores external model element IDs and version/context metadata. Synchronization should be explicit and auditable.

## Traceability rules

- One requirement may map to many scenarios.
- One scenario may evaluate many requirements.
- A run always references an immutable resolved scenario.
- Evidence always references the exact system build and adapter configuration.
- A changed requirement invalidates or marks stale any assurance claim that depended on its previous definition.
- A changed model or adapter triggers impact analysis rather than silently reusing historical evidence.

## Future impact graph

The control plane should maintain a graph connecting:
requirements, models, software components, scenarios, adapters, system builds, runs, evidence and claims.

When one node changes, the graph can identify which evidence should be rerun.

## Why this matters

Tools will change over a ten-year horizon. Stable identity and machine-readable relationships allow the engineering record to survive those changes.
