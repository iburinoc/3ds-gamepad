#include <cstdio>

#include <3ds.h>

#include "frame.pb.h"

namespace {
void init() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
}

void presentFrame() {
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
}
}

int main(int argc, char** argv) {
    init();

    u64 prevTime = osGetTime();
    while (aptMainLoop()) {
        u64 newTime = osGetTime();
        printf("\x1b[1;1HHI! %llu", (newTime - prevTime));
        prevTime = newTime;

        hidScanInput();

        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        u32 kUp = hidKeysUp();

        if (kDown & KEY_START) break;

        presentFrame();
    }

    gfxExit();
}
