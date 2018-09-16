#include <3ds.h>

namespace gamepad {

void init() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
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
