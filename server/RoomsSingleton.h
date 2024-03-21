#ifndef CLIENT_SERVER_ROOMSSINGLETON_H
#define CLIENT_SERVER_ROOMSSINGLETON_H

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include "ChatRoom.h"

class RoomsSingleton {
    static RoomsSingleton* shared;
    std::unordered_map<std::string, std::shared_ptr<ChatRoom>> rooms;

public:
    RoomsSingleton();
    RoomsSingleton(const RoomsSingleton& other) = delete;
    static RoomsSingleton* GetInstance();
    std::shared_ptr<ChatRoom> GetRoom(const std::string& roomName);
    void AddRoom(const std::string& roomName, const std::shared_ptr<ChatRoom>& room);
    void RemoveRoom(const std::string& roomName);
    std::vector<std::string> GetRoomNames();
};


#endif //CLIENT_SERVER_ROOMSSINGLETON_H
