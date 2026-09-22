#include "sentinel/core/engine.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

namespace {

class ReferenceAdapter final : public sentinel::ISystemAdapter {
 public:
  void reset(std::uint64_t seed) override {
    seed_ = seed;
    time_s_ = 0.0;
    position_error_m_ = 0.25;
    heartbeat_hz_ = 50.0;
    gnss_dropout_ = false;
    network_latency_ms_ = 5.0;
  }

  void set_fault(const sentinel::FaultSpec& fault, bool active) override {
    if (fault.kind == sentinel::FaultKind::SensorDropout && fault.target == "gnss") {
      gnss_dropout_ = active;
    }
    if (fault.kind == sentinel::FaultKind::NetworkLatency &&
        fault.target == "telemetry") {
      network_latency_ms_ = active ? parameter(fault, "latency_ms", 100.0) : 5.0;
    }
  }

  void step(double dt_s) override {
    time_s_ += dt_s;
    const double drift = gnss_dropout_ ? 0.10 * dt_s : -0.06 * dt_s;
    position_error_m_ = std::clamp(position_error_m_ + drift, 0.05, 50.0);
    heartbeat_hz_ = network_latency_ms_ > 150.0 ? 8.0 : 50.0;
  }

  [[nodiscard]] double metric(const std::string& name) const override {
    if (name == "position_error_m") return position_error_m_;
    if (name == "heartbeat_hz") return heartbeat_hz_;
    if (name == "sim_time_s") return time_s_;
    return 0.0;
  }

  [[nodiscard]] std::map<std::string, double> snapshot() const override {
    return {
        {"position_error_m", position_error_m_},
        {"heartbeat_hz", heartbeat_hz_},
        {"network_latency_ms", network_latency_ms_},
        {"sim_time_s", time_s_},
    };
  }

 private:
  static double parameter(const sentinel::FaultSpec& fault,
                          const std::string& name, double fallback) {
    const auto it = fault.parameters.find(name);
    return it == fault.parameters.end() ? fallback : it->second;
  }

  std::uint64_t seed_{0};
  double time_s_{0.0};
  double position_error_m_{0.25};
  double heartbeat_hz_{50.0};
  double network_latency_ms_{5.0};
  bool gnss_dropout_{false};
};

const char* status_name(sentinel::RunStatus status) {
  switch (status) {
    case sentinel::RunStatus::Passed:
      return "PASSED";
    case sentinel::RunStatus::Failed:
      return "FAILED";
    case sentinel::RunStatus::Invalid:
      return "INVALID";
  }
  return "UNKNOWN";
}

}  // namespace

int main() {
  sentinel::Scenario scenario;
  scenario.id = "demo.nav-resilience.v1";
  scenario.name = "Reference navigation resilience experiment";
  scenario.duration_s = 12.0;
  scenario.step_s = 0.02;
  scenario.seed = 42;

  sentinel::FaultSpec gnss;
  gnss.id = "fault.gnss.dropout";
  gnss.kind = sentinel::FaultKind::SensorDropout;
  gnss.target = "gnss";
  gnss.start_time_s = 2.0;
  gnss.duration_s = 5.0;
  scenario.faults.push_back(gnss);

  scenario.assertions.push_back({
      "req.position-error",
      "position_error_m",
      sentinel::Comparator::LessOrEqual,
      1.0,
      sentinel::AssertionPolicy::AllSamples,
  });
  scenario.assertions.push_back({
      "req.heartbeat",
      "heartbeat_hz",
      sentinel::Comparator::GreaterOrEqual,
      20.0,
      sentinel::AssertionPolicy::AllSamples,
  });

  ReferenceAdapter adapter;
  sentinel::RunEngine engine;
  const auto evidence = engine.execute(scenario, adapter);

  std::cout << "SENTINEL-TWIN reference run\n";
  std::cout << "scenario: " << evidence.scenario_id << "\n";
  std::cout << "seed: " << evidence.seed << "\n";
  std::cout << "status: " << status_name(evidence.status) << "\n";
  std::cout << std::fixed << std::setprecision(3);

  for (const auto& result : evidence.assertions) {
    std::cout << "assertion " << result.id << ": "
              << (result.passed ? "PASS" : "FAIL")
              << " observed=" << result.observed
              << " threshold=" << result.threshold << "\n";
  }

  return evidence.status == sentinel::RunStatus::Invalid ? 2 : 0;
}
