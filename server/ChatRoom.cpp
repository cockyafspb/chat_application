#include "ChatRoom.h"
#include "RoomsSingleton.h"
#include <chrono>
#include <format>

ChatRoom::ChatRoom(std::string roomName) : roomName(std::move(roomName)) {
}

void ChatRoom::AddSocket(SocketConnection* socket) {
    sockets.insert(socket);
}

void ChatRoom::RemoveSocket(SocketConnection* socket) {
    sockets.erase(socket);

    if (sockets.empty()) {
        auto rooms = RoomsSingleton::GetInstance();
        rooms->RemoveRoom(roomName);
    }
}

void ChatRoom::BroadcastMessage(const std::string &username, const std::string &msg) {
    namespace ch = std::chrono;
    std::string timeStr = std::format("{:%T}", ch::floor<ch::seconds>(ch::system_clock::now()));
    std::string message = std::format("[{}]<{}> {}", timeStr, username, msg);

    messages.push_back(message);

    for (auto s : sockets) {
        s->Send(message);
    }
}

std::vector<std::string> ChatRoom::GetMessages() {
    return messages;
}

std::vector<std::string> ChatRoom::GetUsers() {
    std::vector<std::string> users;
    for (auto s : sockets) {
        users.push_back(s->GetUserName());
    }

    return users;
}
