#ifndef CLIENT_SERVER_ROOMCOMMAND_H
#define CLIENT_SERVER_ROOMCOMMAND_H

#include "Headers.h"

struct RoomCommand {
    std::string operation;
    std::string roomName;
    std::string userName;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RoomCommand, operation, roomName, userName);
};

#endif //CLIENT_SERVER_ROOMCOMMAND_H
