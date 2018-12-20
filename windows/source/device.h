#pragma once


#include "external/common/frame/frame.pb.h"

namespace gamepad {

class Device {

public:
    Device();
    ~Device();

    void send_events(GamepadFrame& frame);
};

}  // namespace gamepad
