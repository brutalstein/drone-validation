#pragma once
#include "sentinel/core/fault.hpp"
#include <cstdint>
#include <map>
#include <string>

namespace sentinel {

class ISystemAdapter {
 public:
  virtual ~ISystemAdapter() = default;
  virtual void reset(std::uint64_t seed) = 0;
  virtual void set_fault(const FaultSpec& fault, bool active) = 0;
  virtual void step(double dt_s) = 0;
  [[nodiscard]] virtual double metric(const std::string& name) const = 0;
  [[nodiscard]] virtual std::map<std::string, double> snapshot() const = 0;
};

}  // namespace sentinel
