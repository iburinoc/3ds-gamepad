#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <cstdint>
#include <string>
#include <vector>

namespace gamepad {

class Server {
    int sock;
    sockaddr_in addr;

public:
    Server(std::string host, int port);
    ~Server();

    std::vector<uint8_t> receive();
};

}  // namespace gamepad
