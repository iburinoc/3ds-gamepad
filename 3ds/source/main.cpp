#include <3ds.h>

#include <cstdio>

#include "console.h"
#include "gamepad.h"
#include "get_ip.h"
#include "state.h"

int main(int argc, char** argv) {
    gamepad::init();

    std::string ip = gamepad::get_ip();
    if (ip.size() == 0) {
        return 1;
    }

    gamepad::Console console;
    console.printf("Sending to: %s\n", ip.c_str());

    gamepad::State state;

    u64 prevTime = osGetTime();
    while (aptMainLoop()) {
        u64 newTime = osGetTime();
        prevTime    = newTime;

        console.set_pos(1, 2);

        state.scan();
        state.print(console);

        gamepad::presentFrame();
    }

    gamepad::teardown();
}
