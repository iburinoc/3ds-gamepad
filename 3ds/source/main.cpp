#include <3ds.h>

#include <cstdio>

#include "console.h"
#include "gamepad.h"
#include "get_ip.h"
#include "sender.h"
#include "state.h"

int main(int argc, char** argv) {
    gamepad::init();

    std::string addr = gamepad::get_ip();
    if (addr.size() == 0) {
        return 1;
    }

    gamepad::Console console;
    console.printf("Sending to: %s\n", addr.c_str());

    gamepad::Sender sender(addr);
    gamepad::State state;

    while (aptMainLoop()) {
        console.set_pos(1, 2);

        state.scan();
        state.print(console);
        sender.send(state);

        gamepad::presentFrame();
    }

    gamepad::teardown();
}
