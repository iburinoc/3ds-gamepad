#pragma once


#include "external/common/frame/frame.pb.h"

namespace gamepad {

class Device {
    unsigned int dev_id;

public:
    Device(unsigned int dev_id=1);
    ~Device();

    void send_events(GamepadFrame& frame);
};

}  // namespace gamepad
