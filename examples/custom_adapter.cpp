#include "sentinel/core/engine.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

class MySystemAdapter final : public sentinel::ISystemAdapter {
 public:
  void reset(std::uint64_t seed) override {
    seed_ = seed;
    time_s_ = 0.0;
    tracking_error_ = 0.1;
    degraded_ = false;
  }

  void set_fault(const sentinel::FaultSpec& condition, bool active) override {
    if (condition.target == "navigation") {
      degraded_ = active;
    }
  }

  void step(double dt_s) override {
    time_s_ += dt_s;
    tracking_error_ = std::clamp(
        tracking_error_ + (degraded_ ? 0.05 : -0.02) * dt_s, 0.02, 10.0);
  }

  double metric(const std::string& name) const override {
    if (name == "tracking_error_m") return tracking_error_;
    if (name == "sim_time_s") return time_s_;
    return 0.0;
  }

  std::map<std::string, double> snapshot() const override {
    return {
        {"tracking_error_m", tracking_error_},
        {"sim_time_s", time_s_},
    };
  }

 private:
  std::uint64_t seed_{0};
  double time_s_{0.0};
  double tracking_error_{0.1};
  bool degraded_{false};
};

int main() {
  sentinel::Scenario scenario;
  scenario.id = "example.custom-adapter.v1";
  scenario.duration_s = 5.0;
  scenario.step_s = 0.01;
  scenario.seed = 7;
  scenario.assertions.push_back({
      "REQ-TRACK-001",
      "tracking_error_m",
      sentinel::Comparator::LessOrEqual,
      0.5,
      sentinel::AssertionPolicy::AllSamples,
  });

  MySystemAdapter adapter;
  sentinel::RunEngine engine;
  const auto evidence = engine.execute(scenario, adapter);

  std::cout << "scenario=" << evidence.scenario_id
            << " status="
            << (evidence.status == sentinel::RunStatus::Passed ? "PASS" : "FAIL")
            << "\n";
  return evidence.status == sentinel::RunStatus::Passed ? 0 : 1;
}
