#ifndef CLIENT_SERVER_CHATROOM_H
#define CLIENT_SERVER_CHATROOM_H

#include <unordered_set>
#include <memory>
#include <utility>
#include "SocketConnection.h"

class ChatRoom {
public:
    ChatRoom(std::string roomName);
    void AddSocket(SocketConnection* socket);
    void RemoveSocket(SocketConnection* socket);
    void BroadcastMessage(const std::string& username, const std::string& msg);
    std::vector<std::string> GetMessages();
    std::vector<std::string> GetUsers();

private:
    std::unordered_set<SocketConnection*> sockets;
    std::vector<std::string> messages;
    std::string roomName;
};


#endif //CLIENT_SERVER_CHATROOM_H
