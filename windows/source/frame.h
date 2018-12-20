#pragma once

#include <cstdint>
#include <vector>

#include "external/common/frame/frame.pb.h"

namespace gamepad {

GamepadFrame parse_frame(std::vector<uint8_t> data);

void print_frame(const GamepadFrame& frame);

}  // namespace gamepad
