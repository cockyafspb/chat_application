#ifndef CLIENT_SERVER_ROOMMESSAGE_H
#define CLIENT_SERVER_ROOMMESSAGE_H

#include "Headers.h"

struct RoomMessage {
    std::string username;
    std::string message;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RoomMessage, username, message);
};

#endif //CLIENT_SERVER_ROOMMESSAGE_H
