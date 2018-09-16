#include "get_ip.h"

#include <3ds.h>

#include <regex>
#include <string>

namespace gamepad {

namespace {

std::string match_leq(int x) {
    if (x < 10) {
        return "([0-" + std::to_string(x) + "])";
    }

    int l = 0, p = 1;
    while (p * 10 <= x) {
        p *= 10;
        l++;
    }

    std::stringstream s;
    s << "(";
    s << "0|" << x << "|";

    s << "[1-9]\\d{0," << (l - 1) << "}";
    for (; p > 0; p /= 10, l--) {
        int d    = (x / p) % 10;
        int pref = x / p / 10;
        if (d == 0)
            continue;
        if (pref == 0 && d == 1) {
            continue;
        }
        s << "|";
        int lim = 0;
        if (pref != 0) {
            s << (x / p / 10);
        } else {
            lim = 1;
        }
        s << "[" << lim << "-" << (d - 1) << "]\\d{0," << l << "}";
    }
    s << ")";
    return s.str();
}

SwkbdCallbackResult validate_ip(void* user,
                                const char** ppMessage,
                                const char* text,
                                size_t textlen) {
    std::string mbyte = match_leq(255);
    std::string mport = match_leq(65535);
    std::regex addr("^" + mbyte + "." + mbyte + "." + mbyte + "." + mbyte +
                    "(:" + mport + ")?$");
    bool valid = std::regex_match(text, addr);
    if (!valid) {
        *ppMessage = "Invalid IP address";
        return SWKBD_CALLBACK_CONTINUE;
    }
    return SWKBD_CALLBACK_OK;
}

}  // namespace

std::string get_ip() {
    SwkbdState state;

    swkbdInit(&state, SWKBD_TYPE_NUMPAD, 2, 21);
    swkbdSetFeatures(&state, SWKBD_FIXED_WIDTH);
    swkbdSetNumpadKeys(&state, L':', L'.');
    swkbdSetHintText(&state, "IP address");
    swkbdSetFilterCallback(&state, validate_ip, nullptr);

    const size_t size = 22;
    char ip[size];

    auto result = swkbdInputText(&state, ip, size);
    if (result != SWKBD_BUTTON_RIGHT) {
        return std::string();
    }

    return std::string(ip);
}
}  // namespace gamepad
