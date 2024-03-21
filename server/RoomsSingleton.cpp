#include "RoomsSingleton.h"

RoomsSingleton::RoomsSingleton() = default;

RoomsSingleton *RoomsSingleton::GetInstance() {
    if (!shared) {
        shared = new RoomsSingleton();
    }

    return shared;
}

std::shared_ptr<ChatRoom> RoomsSingleton::GetRoom(const std::string &roomName) {
    return rooms.at(roomName);
}

void RoomsSingleton::AddRoom(const std::string &roomName, const std::shared_ptr<ChatRoom> &room) {
    rooms[roomName] = room;
}

void RoomsSingleton::RemoveRoom(const std::string &roomName) {
    rooms.erase(roomName);
}

std::vector<std::string> RoomsSingleton::GetRoomNames() {
    std::vector<std::string> roomNames;

    for (auto& pr : rooms) {
        roomNames.push_back(pr.first);
    }

    return roomNames;
}

RoomsSingleton* RoomsSingleton::shared = nullptr;