#pragma once

#include <libevdev/libevdev-uinput.h>
#include <libevdev/libevdev.h>

#include "external/common/frame/frame.pb.h"

namespace gamepad {

class Device {
    struct libevdev* dev;
    struct libevdev_uinput* uinput_dev;

public:
    Device();
    ~Device();

    void send_events(GamepadFrame& frame);
};

}  // namespace gamepad
