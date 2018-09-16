#pragma once

#include <cstdint>
#include <vector>

#include "common/frame/frame.pb.h"
#include "console.h"

namespace gamepad {

class State {
    GamepadFrame frame;

public:
    State();
    ~State();

    void scan();
    void print(Console& c) const;
    std::vector<uint8_t> serialize() const;
};

}  // namespace gamepad
