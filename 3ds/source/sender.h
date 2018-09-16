#pragma once

#include <arpa/inet.h>

#include <string>

#include "state.h"

#ifndef DEST_PORT
#define DEST_PORT (44813)
#endif

namespace gamepad {

class Sender {
    int sock;
    sockaddr_in dest;

public:
    Sender(const std::string& addr);
    ~Sender();

    void send(const State& state) const;
};

}  // namespace gamepad
