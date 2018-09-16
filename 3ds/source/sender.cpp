#include "sender.h"

#include <sys/socket.h>

#include <cstdlib>

namespace gamepad {

Sender::Sender(const std::string& addr) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;

    size_t split = addr.find(':');
    inet_pton(AF_INET, addr.substr(0, split).c_str(),
              &dest.sin_addr);  // parse ip
    dest.sin_port = (split != std::string::npos) ? stoi(addr.substr(split + 1))
                                                 : DEST_PORT;  // parse port
}

Sender::~Sender() {
    closesocket(sock);
}

void Sender::send(const State& state) const {
    const auto data = state.serialize();

    sendto(sock, data.data(), data.size(), 0, (const struct sockaddr*)&dest,
           sizeof(dest));
}

}  // namespace gamepad
