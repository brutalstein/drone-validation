#pragma once

#include "sentinel/core/types.hpp"

#include <string>

namespace sentinel::evidence {

[[nodiscard]] std::string to_json(const Evidence& evidence);

}  // namespace sentinel::evidence
