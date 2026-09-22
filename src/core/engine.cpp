#include "sentinel/core/engine.hpp"

#include <cmath>
#include <unordered_map>

namespace sentinel {

bool RunEngine::compare(double value, Comparator comparator, double threshold) {
  switch (comparator) {
    case Comparator::LessThan:
      return value < threshold;
    case Comparator::LessOrEqual:
      return value <= threshold;
    case Comparator::GreaterThan:
      return value > threshold;
    case Comparator::GreaterOrEqual:
      return value >= threshold;
    case Comparator::Equal:
      return std::abs(value - threshold) <= 1e-9;
  }
  return false;
}

Evidence RunEngine::execute(const Scenario& scenario, ISystemAdapter& adapter) const {
  Evidence evidence;
  evidence.scenario_id = scenario.id;
  evidence.seed = scenario.seed;

  if (scenario.id.empty() || scenario.duration_s <= 0.0 || scenario.step_s <= 0.0 ||
      scenario.step_s > scenario.duration_s) {
    evidence.status = RunStatus::Invalid;
    evidence.events.emplace_back("scenario.invalid");
    return evidence;
  }

  adapter.reset(scenario.seed);

  evidence.assertions.reserve(scenario.assertions.size());
  for (const auto& spec : scenario.assertions) {
    evidence.assertions.push_back(
        AssertionResult{spec.id, true, 0.0, spec.threshold, -1.0});
  }

  std::unordered_map<std::string, bool> previous_fault_state;
  for (const auto& fault : scenario.faults) {
    previous_fault_state[fault.id] = false;
  }

  const auto steps =
      static_cast<std::uint64_t>(std::ceil(scenario.duration_s / scenario.step_s));

  for (std::uint64_t i = 0; i < steps; ++i) {
    const double time_s = static_cast<double>(i) * scenario.step_s;

    for (const auto& fault : scenario.faults) {
      const bool active = fault.active_at(time_s);
      const bool was_active = previous_fault_state[fault.id];
      if (active != was_active) {
        adapter.set_fault(fault, active);
        evidence.events.push_back(
            std::string(active ? "fault.activated:" : "fault.cleared:") + fault.id);
        previous_fault_state[fault.id] = active;
      }
    }

    adapter.step(scenario.step_s);

    for (std::size_t index = 0; index < scenario.assertions.size(); ++index) {
      const auto& spec = scenario.assertions[index];
      if (spec.policy != AssertionPolicy::AllSamples) {
        continue;
      }
      const double value = adapter.metric(spec.metric);
      auto& result = evidence.assertions[index];
      result.observed = value;
      if (!compare(value, spec.comparator, spec.threshold)) {
        if (result.passed) {
          result.first_failure_time_s = time_s + scenario.step_s;
        }
        result.passed = false;
      }
    }
  }

  evidence.simulated_duration_s = scenario.duration_s;
  evidence.final_metrics = adapter.snapshot();

  for (std::size_t index = 0; index < scenario.assertions.size(); ++index) {
    const auto& spec = scenario.assertions[index];
    auto& result = evidence.assertions[index];
    if (spec.policy == AssertionPolicy::FinalSample) {
      const double value = adapter.metric(spec.metric);
      result.observed = value;
      result.passed = compare(value, spec.comparator, spec.threshold);
      if (!result.passed) {
        result.first_failure_time_s = scenario.duration_s;
      }
    }
  }

  evidence.status = RunStatus::Passed;
  for (const auto& result : evidence.assertions) {
    if (!result.passed) {
      evidence.status = RunStatus::Failed;
      break;
    }
  }
  evidence.events.emplace_back(
      evidence.status == RunStatus::Passed ? "run.passed" : "run.failed");
  return evidence;
}

}  // namespace sentinel
