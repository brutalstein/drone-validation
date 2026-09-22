#include "sentinel/evidence/json.hpp"
#include "sentinel/search/bisection.hpp"

#include <cassert>
#include <cmath>
#include <string>

int main() {
  const auto result = sentinel::search::Bisection::find(
      0.0,
      10.0,
      0.01,
      32,
      [](double value) { return value < 6.25; });

  assert(result.found);
  assert(result.last_passing < 6.25);
  assert(result.first_failing >= 6.25);
  assert((result.first_failing - result.last_passing) <= 0.01);

  sentinel::Evidence evidence;
  evidence.scenario_id = "test.\"escaped\"";
  evidence.seed = 42;
  evidence.status = sentinel::RunStatus::Failed;
  evidence.simulated_duration_s = 2.5;
  evidence.final_metrics["error_m"] = 1.25;
  evidence.assertions.push_back({"REQ-1", false, 1.25, 1.0, 2.0});
  evidence.events.push_back("run.failed");

  const std::string json = sentinel::evidence::to_json(evidence);
  assert(json.find("\"scenario_id\":\"test.\\\"escaped\\\"\"") != std::string::npos);
  assert(json.find("\"status\":\"failed\"") != std::string::npos);
  assert(json.find("\"REQ-1\"") != std::string::npos);

  return 0;
}
