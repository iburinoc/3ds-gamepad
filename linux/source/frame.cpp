#include "frame.h"

#include <iomanip>
#include <iostream>

#include "external/common/frame/pb_decode.h"

namespace gamepad {

GamepadFrame parse_frame(std::vector<uint8_t> data) {
    GamepadFrame frame  = GamepadFrame_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(data.data(), data.size());

    auto status = pb_decode(&stream, GamepadFrame_fields, &frame);
    if (!status) {
        std::cerr << "Decoding packet failed: " << PB_GET_ERROR(&stream)
                  << std::endl;
        return GamepadFrame_init_zero;
    }

    return frame;
}

void print_frame(const GamepadFrame& frame) {
    using namespace std;
    cout << setfill(' ') << setw(5) << "L: " << frame.lx << ", " << frame.ly
         << " " << frame.a;
    cout << endl;
}

}  // namespace gamepad
