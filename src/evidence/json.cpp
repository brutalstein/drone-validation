#include "sentinel/evidence/json.hpp"

#include <iomanip>
#include <sstream>
#include <string_view>

namespace sentinel::evidence {
namespace {

std::string escape(std::string_view value) {
  std::ostringstream out;
  for (const char c : value) {
    switch (c) {
      case '"': out << "\\\""; break;
      case '\\': out << "\\\\"; break;
      case '\b': out << "\\b"; break;
      case '\f': out << "\\f"; break;
      case '\n': out << "\\n"; break;
      case '\r': out << "\\r"; break;
      case '\t': out << "\\t"; break;
      default:
        if (static_cast<unsigned char>(c) < 0x20U) {
          out << "\\u"
              << std::hex << std::setw(4) << std::setfill('0')
              << static_cast<unsigned int>(static_cast<unsigned char>(c))
              << std::dec << std::setfill(' ');
        } else {
          out << c;
        }
    }
  }
  return out.str();
}

const char* status_name(RunStatus status) {
  switch (status) {
    case RunStatus::Passed: return "passed";
    case RunStatus::Failed: return "failed";
    case RunStatus::Invalid: return "invalid";
  }
  return "invalid";
}

}  // namespace

std::string to_json(const Evidence& evidence) {
  std::ostringstream out;
  out << std::setprecision(17);
  out << "{";
  out << "\"scenario_id\":\"" << escape(evidence.scenario_id) << "\",";
  out << "\"seed\":" << evidence.seed << ",";
  out << "\"status\":\"" << status_name(evidence.status) << "\",";
  out << "\"simulated_duration_s\":" << evidence.simulated_duration_s << ",";

  out << "\"final_metrics\":{";
  bool first = true;
  for (const auto& [name, value] : evidence.final_metrics) {
    if (!first) out << ",";
    first = false;
    out << "\"" << escape(name) << "\":" << value;
  }
  out << "},";

  out << "\"assertions\":[";
  first = true;
  for (const auto& assertion : evidence.assertions) {
    if (!first) out << ",";
    first = false;
    out << "{"
        << "\"id\":\"" << escape(assertion.id) << "\","
        << "\"passed\":" << (assertion.passed ? "true" : "false") << ","
        << "\"observed\":" << assertion.observed << ","
        << "\"threshold\":" << assertion.threshold << ","
        << "\"first_failure_time_s\":" << assertion.first_failure_time_s
        << "}";
  }
  out << "],";

  out << "\"events\":[";
  first = true;
  for (const auto& event : evidence.events) {
    if (!first) out << ",";
    first = false;
    out << "\"" << escape(event) << "\"";
  }
  out << "]";
  out << "}";
  return out.str();
}

}  // namespace sentinel::evidence
