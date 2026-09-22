# Boundary Search

The campaign engine searches efficiently for requirement boundaries.

## Objective

Find parameter vectors that reduce a requirement robustness margin to zero, then minimize the boundary-inducing condition while preserving reproducibility.

## Planned search ladder

1. Deterministic grids and Latin-hypercube baselines.
2. Bisection for monotonic single variables.
3. Bayesian optimization for expensive continuous scenarios.
4. Evolutionary search for mixed nonlinear spaces.
5. Coverage-guided mutation for structured scenario spaces.
6. Surrogate-assisted search when hardware runs are scarce.
7. Multi-fidelity search: broad simulation, narrow HIL confirmation.

## Robustness

Assertions should eventually expose a signed robustness value rather than only pass/fail. Positive means margin, zero is the boundary and negative means violation.

## Confirmation gate

A discovered boundary becomes an engineering finding only after controlled reproduction and evidence capture.

## Search provenance

Record algorithm name, implementation version, hyperparameters, seed, evaluated points and stopping condition. Discovery runs and confirmation runs are distinct artifacts.
