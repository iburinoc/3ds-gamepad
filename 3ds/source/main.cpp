#include <3ds.h>

#include <cstdio>

#include "frame.pb.h"
#include "gamepad.h"
#include "get_ip.h"

int main(int argc, char** argv) {
    gamepad::init();

    std::string ip = gamepad::get_ip();
    if (ip.size() == 0) {
        return 1;
    }

    u64 prevTime = osGetTime();
    while (aptMainLoop()) {
        u64 newTime = osGetTime();
        printf("\x1b[1;1HHI! %s %llu", ip.c_str(), (newTime - prevTime));
        prevTime = newTime;

        hidScanInput();

        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        u32 kUp = hidKeysUp();

        if (kDown & KEY_START)
            break;

        gamepad::presentFrame();
    }

    gamepad::teardown();
}
