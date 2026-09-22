#pragma once
#include "sentinel/core/fault.hpp"
#include "sentinel/core/types.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace sentinel {

struct Scenario {
  std::string id;
  std::string name;
  double duration_s{10.0};
  double step_s{0.01};
  std::uint64_t seed{1};
  std::vector<FaultSpec> faults;
  std::vector<AssertionSpec> assertions;
};

}  // namespace sentinel
