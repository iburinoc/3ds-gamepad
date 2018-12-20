#pragma once

#include "Winsock2.h"

#include <cstdint>
#include <string>
#include <thread>
#include <vector>

namespace gamepad {

class Server {
    SOCKET sock;
    sockaddr_in addr;

    static std::once_flag init_flag;
    static WSADATA wsadata;
    static void static_init();

public:
    Server(std::string host, int port);
    ~Server();

    std::vector<uint8_t> receive(size_t maxsize);
};

}  // namespace gamepad
