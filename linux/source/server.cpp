#include "server.h"

#include <unistd.h>

#include <stdexcept>

namespace gamepad {

Server::Server(std::string host, int port) {
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
        throw std::runtime_error("Failed to open socket");

    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);
    if (inet_pton(AF_INET, host.c_str(), &addr.sin_addr.s_addr) != 1)
        throw std::runtime_error("Failed to convert host address");

    if (bind(sock, (const struct sockaddr*)&addr, sizeof(addr)) < 0)
        throw std::runtime_error("Failed to bind to port");
}
Server::~Server() {
    close(sock);
}

std::vector<uint8_t> Server::receive(size_t maxsize) {
    std::vector<uint8_t> res(maxsize);

    ssize_t size = recv(sock, res.data(), maxsize, 0);
    if (size < 0)
        throw std::runtime_error("Error receiving packet");

    res.resize(size);

    return res;
}

}  // namespace gamepad
