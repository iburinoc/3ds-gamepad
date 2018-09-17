#include "sender.h"

#include <3ds.h>
#include <malloc.h>
#include <sys/socket.h>

#include <cstdlib>

#define SOC_ALIGN 0x1000
#define SOC_BUFFERSIZE 0x100000

namespace gamepad {

Sender::Sender(const std::string& addr) {
    soc_mem = (uint32_t*)memalign(SOC_ALIGN, SOC_BUFFERSIZE);
    socInit(soc_mem, SOC_BUFFERSIZE);

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;

    size_t split = addr.find(':');

    inet_pton(AF_INET, addr.substr(0, split).c_str(),
              &dest.sin_addr.s_addr);  // parse ip

    uint16_t port = (split != std::string::npos) ? stoi(addr.substr(split + 1))
                                                 : DEST_PORT;  // parse port
    dest.sin_port = htons(port);
}

Sender::~Sender() {
    closesocket(sock);
    socExit();
    free(soc_mem);
}

void Sender::send(const State& state) const {
    const auto data = state.serialize();

    sendto(sock, data.data(), data.size(), 0, (const struct sockaddr*)&dest,
           sizeof(dest));
}

}  // namespace gamepad
