#pragma once

#include <cstddef>
#include <functional>

namespace sentinel::search {

struct BoundaryResult {
  bool found{false};
  double last_passing{0.0};
  double first_failing{0.0};
  std::size_t evaluations{0};
};

class Bisection {
 public:
  using Evaluator = std::function<bool(double)>;

  [[nodiscard]] static BoundaryResult find(
      double known_passing,
      double known_failing,
      double tolerance,
      std::size_t max_evaluations,
      const Evaluator& requirement_passes);
};

}  // namespace sentinel::search
