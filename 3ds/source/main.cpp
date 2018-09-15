#include <cstdio>

#include <3ds.h>

#ifndef MILLI_PER_REPORT
#define MILLI_PER_REPORT ((u64)1)
#endif

#ifndef SHORT_WAIT
#define SHORT_WAIT ((u64)250)
#endif

void init() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
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
        gfxFlushBuffers();
        gfxSwapBuffers();
        //gspWaitForVBlank();
    }

    gfxExit();
}
