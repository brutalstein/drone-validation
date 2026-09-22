#include "sentinel/search/bisection.hpp"

#include <cmath>
#include <stdexcept>

namespace sentinel::search {

BoundaryResult Bisection::find(double known_passing,
                               double known_failing,
                               double tolerance,
                               std::size_t max_evaluations,
                               const Evaluator& requirement_passes) {
  if (!requirement_passes) {
    throw std::invalid_argument("boundary evaluator is empty");
  }
  if (!(std::isfinite(known_passing) && std::isfinite(known_failing) &&
        std::isfinite(tolerance))) {
    throw std::invalid_argument("boundary inputs must be finite");
  }
  if (known_passing >= known_failing) {
    throw std::invalid_argument("known_passing must be less than known_failing");
  }
  if (tolerance <= 0.0 || max_evaluations < 2) {
    throw std::invalid_argument("invalid tolerance or evaluation budget");
  }

  BoundaryResult result;
  result.last_passing = known_passing;
  result.first_failing = known_failing;

  const bool low_passes = requirement_passes(known_passing);
  ++result.evaluations;
  const bool high_passes = requirement_passes(known_failing);
  ++result.evaluations;

  if (!low_passes || high_passes) {
    return result;
  }

  while ((result.first_failing - result.last_passing) > tolerance &&
         result.evaluations < max_evaluations) {
    const double midpoint =
        result.last_passing +
        (result.first_failing - result.last_passing) * 0.5;

    if (requirement_passes(midpoint)) {
      result.last_passing = midpoint;
    } else {
      result.first_failing = midpoint;
    }
    ++result.evaluations;
  }

  result.found =
      (result.first_failing - result.last_passing) <= tolerance;
  return result;
}

}  // namespace sentinel::search
