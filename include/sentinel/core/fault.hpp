#pragma once
#include <map>
#include <string>

namespace sentinel {

enum class FaultKind {
  SensorDropout,
  SensorBias,
  SensorLatency,
  PacketLoss,
  NetworkLatency,
  ProcessPause,
  ResourcePressure,
  Custom
};

struct FaultSpec {
  std::string id;
  FaultKind kind{FaultKind::Custom};
  std::string target;
  double start_time_s{0.0};
  double duration_s{0.0};
  std::map<std::string, double> parameters;

  [[nodiscard]] bool active_at(double time_s) const noexcept {
    return time_s >= start_time_s && time_s < (start_time_s + duration_s);
  }
};

}  // namespace sentinel
