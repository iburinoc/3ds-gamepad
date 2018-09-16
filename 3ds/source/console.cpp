#include "console.h"

#include <3ds.h>

#include <cstdarg>
#include <cstdio>

namespace gamepad {
Console::Console() {
    consoleInit(GFX_TOP, NULL);
}

void Console::clear() {
    consoleClear();
    set_pos(1, 1);
}

void Console::set_pos(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}

void Console::printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}
}  // namespace gamepad
