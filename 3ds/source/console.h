#pragma once

namespace gamepad {

class Console {
public:
    Console();

    void clear();
    void set_pos(int x, int y);
    void printf(const char* fmt, ...);
};

}  // namespace gamepad
