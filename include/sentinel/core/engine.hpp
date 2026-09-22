#pragma once
#include "sentinel/core/adapter.hpp"
#include "sentinel/core/scenario.hpp"
#include "sentinel/core/types.hpp"

namespace sentinel {

class RunEngine {
 public:
  [[nodiscard]] Evidence execute(const Scenario& scenario, ISystemAdapter& adapter) const;

 private:
  [[nodiscard]] static bool compare(double value, Comparator comparator, double threshold);
};

}  // namespace sentinel
