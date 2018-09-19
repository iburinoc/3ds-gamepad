#pragma once

#include <libevdev/libevdev-uinput.h>
#include <libevdev/libevdev.h>

namespace gamepad {

class Device {
    struct libevdev* dev;
    struct libevdev_uinput* uinput_dev;

public:
    Device();
    ~Device();
};

}  // namespace gamepad
