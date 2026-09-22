#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace sentinel {

enum class Comparator { LessThan, LessOrEqual, GreaterThan, GreaterOrEqual, Equal };
enum class AssertionPolicy { AllSamples, FinalSample };

struct AssertionSpec {
  std::string id;
  std::string metric;
  Comparator comparator{Comparator::LessOrEqual};
  double threshold{0.0};
  AssertionPolicy policy{AssertionPolicy::AllSamples};
};

struct AssertionResult {
  std::string id;
  bool passed{true};
  double observed{0.0};
  double threshold{0.0};
  double first_failure_time_s{-1.0};
};

enum class RunStatus { Passed, Failed, Invalid };

struct Evidence {
  std::string scenario_id;
  std::uint64_t seed{0};
  RunStatus status{RunStatus::Invalid};
  double simulated_duration_s{0.0};
  std::map<std::string, double> final_metrics;
  std::vector<AssertionResult> assertions;
  std::vector<std::string> events;
};

}  // namespace sentinel
