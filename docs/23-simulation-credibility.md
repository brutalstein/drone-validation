# Simulation Credibility Framework

A digital twin is useful only when its fidelity is adequate for the question being asked.

## Credibility is scoped

Do not label an entire simulator as simply validated. A credibility claim is tied to:
- use case;
- operating envelope;
- variables of interest;
- reference data;
- model version;
- uncertainty;
- acceptance criteria.

## Credibility record

A future machine-readable credibility record should contain:
- model ID and version;
- model owner;
- calibration dataset identity;
- validation dataset identity;
- parameter ranges;
- compared outputs;
- error distributions;
- known exclusions;
- numerical solver configuration;
- simulator and plugin versions;
- date and reviewer.

## Correlation workflow

1. Freeze the model and test configuration.
2. Collect reference measurements from a controlled source.
3. Normalize time and coordinate frames.
4. Compare relevant output distributions and transient behavior.
5. Quantify residual error and uncertainty.
6. Store the analysis as evidence.
7. Declare the envelope in which the model is accepted for a specific validation question.

## Multi-fidelity policy

Use cheaper models to explore broad parameter spaces and higher-fidelity models or HIL for confirmation. Search algorithms must record which fidelity produced each observation.

## Differential simulation

The same canonical scenario can be run against two simulators or two model versions. Differences become explicit evidence instead of hidden tool behavior.

## Long-term goal

Campaign scheduling should select the cheapest fidelity expected to answer the current question while escalating uncertain or boundary cases to higher fidelity.
