# Deployment Model

## Developer workstation

Core, CLI and local simulator adapters run on one machine. This is the default environment for development, deterministic regression and scenario authoring.

## Single HIL bench

Coordinator and evidence storage run on the host while adapters communicate with isolated laboratory interfaces. Physical safety mechanisms remain independent.

## Lab cluster

A control plane schedules containerized workers and reserved HIL resources. Evidence is written to object storage and metadata is indexed for search and comparison.

## Restricted or offline environments

Support local package mirrors, pinned containers, offline artifact storage and portable evidence bundles. The core must not require cloud services.

## Enterprise

Expose versioned APIs for scenarios, campaigns, runs, requirements, workers, hardware assets and evidence. Authentication and authorization belong to the control plane rather than the deterministic run kernel.

## Capability discovery

Workers and HIL assets advertise capabilities such as simulator version, middleware, controller version, GPU, real-time features and attached interfaces. Scheduling resolves required capabilities before a run starts.
