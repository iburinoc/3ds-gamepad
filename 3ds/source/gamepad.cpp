#include <3ds.h>

namespace gamepad {

void init() {
    gfxInitDefault();
}

void teardown() {
    gfxExit();
}

void presentFrame() {
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
}

}  // namespace gamepad
