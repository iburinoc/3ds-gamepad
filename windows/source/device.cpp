#include "device.h"

#include <iostream>

#include "external/common/frame/frame.pb.h"

namespace gamepad {

Device::Device() {
}

Device::~Device() {
}

void Device::send_events(GamepadFrame& frame) {
    std::cout << "Sending event with seqno " << frame.seqno << std::endl;
}

}  // namespace gamepad
