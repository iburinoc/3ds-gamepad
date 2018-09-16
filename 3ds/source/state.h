#pragma once

#include "common/frame/frame.pb.h"
#include "console.h"

namespace gamepad {

class State {
    GamepadFrame frame;

public:
    State();
    ~State();

    void scan();
    void print(Console& c);
    void serialize();
};

}  // namespace gamepad
