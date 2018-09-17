#include <atomic>
#include <vector>

#include "external/common/frame/frame.pb.h"
#include "external/common/frame/pb_decode.h"
#include "server.h"

std::atomic<bool> quit(false);

void sighandle(int) {
    quit.store(true);
}

int main(int argc, char** argv) {
    gamepad::Server server("0.0.0.0", 44813);

    while (quit.load()) {
        auto data = server.receive();
    }
}
