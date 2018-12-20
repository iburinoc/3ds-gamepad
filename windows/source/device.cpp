#include "device.h"

#include "Windows.h"

#include <iostream>

#include "external/common/frame/frame.pb.h"

#include "vjoy/public.h"
#include "vjoy/vjoyinterface.h"

namespace gamepad {

Device::Device(unsigned int _dev_id) : dev_id(_dev_id) {
    if (!vJoyEnabled()) {
        throw std::runtime_error("vJoy not enabled");
    }

    VjdStat status = GetVJDStatus(dev_id);
    if (status != VJD_STAT_FREE) {
        throw std::runtime_error("The vJoy device is not available");
    }

    if (!AcquireVJD(dev_id)) {
        throw std::runtime_error("Failed to acquire vJoy device");
    }

}

Device::~Device() {
    RelinquishVJD(dev_id);
}


namespace {
const int STICK_RANGE = 150;
const int VJOY_RANGE = 1 << 15;
const int FLAT = 20;

long long int convert(int32_t in) {
    if (abs(in) < FLAT) return VJOY_RANGE/2;
    return in * VJOY_RANGE / STICK_RANGE + VJOY_RANGE/2;
}
}

void Device::send_events(GamepadFrame& frame) {
    JOYSTICK_POSITION_V2 js;
    memset(&js, 0, sizeof(js));

    js.bDevice = dev_id;

    js.wAxisX = convert(frame.lx);
    js.wAxisY = convert(frame.ly);

    js.wAxisXRot = convert(frame.rx);
    js.wAxisYRot = convert(frame.ry);

    int64_t buttons = 0;
    buttons |= (frame.du) << 0;
    buttons |= (frame.dd) << 1;
    buttons |= (frame.dl) << 2;
    buttons |= (frame.dr) << 3;
    buttons |= (frame.a) << 4;
    buttons |= (frame.b) << 5;
    buttons |= (frame.x) << 6;
    buttons |= (frame.y) << 7;
    buttons |= (frame.start) << 8;
    buttons |= (frame.select) << 9;
    buttons |= (frame.l) << 10;
    buttons |= (frame.zl) << 11;
    buttons |= (frame.r) << 12;
    buttons |= (frame.zr) << 13;

    js.lButtons = buttons;

    if (!UpdateVJD(dev_id, (void*) &js)) {
        throw std::runtime_error("Failed to update vJoy device");
    }
}

}  // namespace gamepad
