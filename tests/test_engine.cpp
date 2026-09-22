#include "sentinel/core/engine.hpp"

#include <cassert>
#include <map>
#include <string>

class TestAdapter final : public sentinel::ISystemAdapter {
 public:
  void reset(std::uint64_t) override {
    value_ = 0.0;
    fault_ = false;
  }

  void set_fault(const sentinel::FaultSpec&, bool active) override { fault_ = active; }

  void step(double dt_s) override { value_ += (fault_ ? 2.0 : 0.1) * dt_s; }

  double metric(const std::string&) const override { return value_; }

  std::map<std::string, double> snapshot() const override {
    return {{"value", value_}};
  }

 private:
  double value_{0.0};
  bool fault_{false};
};

int main() {
  sentinel::Scenario nominal;
  nominal.id = "test.nominal";
  nominal.duration_s = 1.0;
  nominal.step_s = 0.01;
  nominal.assertions.push_back(
      {"a", "value", sentinel::Comparator::LessThan, 0.2,
       sentinel::AssertionPolicy::FinalSample});

  TestAdapter adapter;
  sentinel::RunEngine engine;
  const auto passed = engine.execute(nominal, adapter);
  assert(passed.status == sentinel::RunStatus::Passed);

  sentinel::Scenario failing = nominal;
  failing.id = "test.fault";
  failing.faults.push_back(
      {"f", sentinel::FaultKind::Custom, "x", 0.0, 1.0, {}});
  const auto failed = engine.execute(failing, adapter);
  assert(failed.status == sentinel::RunStatus::Failed);
  assert(!failed.assertions.front().passed);

  sentinel::Scenario invalid;
  const auto bad = engine.execute(invalid, adapter);
  assert(bad.status == sentinel::RunStatus::Invalid);
  return 0;
}
