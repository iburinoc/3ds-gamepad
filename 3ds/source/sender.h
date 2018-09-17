#pragma once

#include <arpa/inet.h>

#include <cstdint>
#include <string>

#include "state.h"

#ifndef DEST_PORT
#define DEST_PORT (44813)
#endif

namespace gamepad {

class Sender {
    uint32_t* soc_mem;

    int sock;
    sockaddr_in dest;

public:
    Sender(const std::string& addr);
    ~Sender();

    void send(const State& state) const;
};

}  // namespace gamepad
