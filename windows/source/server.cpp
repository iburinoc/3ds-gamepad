#include "server.h"

#include "WS2tcpip.h"

#include <iostream>
#include <mutex>
#include <stdexcept>

namespace gamepad {

std::once_flag Server::init_flag;
WSADATA Server::wsadata;

void Server::static_init() {
    std::call_once(init_flag, []() {
        if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
            throw std::runtime_error("Failed to initialize Winsock");
        }
    });
}

Server::Server(std::string host, int port) {
    static_init();
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
        throw std::runtime_error("Failed to open socket");

    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&optval, sizeof(optval));

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);

    const std::wstring whost = std::wstring(host.begin(), host.end());
    if (InetPtonW(AF_INET, whost.c_str(), &addr.sin_addr.s_addr) != 1)
        throw std::runtime_error("Failed to convert host address");

    if (bind(sock, (const struct sockaddr*)&addr, sizeof(addr)) < 0)
        throw std::runtime_error("Failed to bind to port");
}

Server::~Server() {
    closesocket(sock);
}

std::vector<uint8_t> Server::receive(size_t maxsize) {
    std::vector<uint8_t> res(maxsize);

    std::cout << "Waiting for packet" << std::endl;
    int size = recv(sock, (char*)res.data(), maxsize, 0);
    if (size < 0)
        throw std::runtime_error("Error receiving packet");


    std::cout << "Received packet" << std::endl;

    res.resize(size);

    return res;
}

}  // namespace gamepad
