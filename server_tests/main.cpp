#include "gtest/gtest.h"
#include "../server/RoomsSingleton.h"
#include "../server/Listener.h"

TEST(RoomsSingletonTest, AddRoomGetRoom) {
    auto rooms = new RoomsSingleton();
    auto roomName = "room";
    auto room = std::make_shared<ChatRoom>(roomName);

    rooms->AddRoom(roomName, room);
    auto getRoom = rooms->GetRoom(roomName);

    EXPECT_EQ(room, getRoom);
}

TEST(RoomsSingletonTest, AddRoomRemoveRoom) {
    auto rooms = new RoomsSingleton();
    auto roomName = "room";
    auto room = std::make_shared<ChatRoom>(roomName);

    rooms->AddRoom(roomName, room);
    rooms->RemoveRoom(roomName);

    ASSERT_THROW(rooms->GetRoom(roomName), std::out_of_range);
}

TEST(RoomsSingletonTest, AddRoomsGetRoomNames) {
    auto rooms = new RoomsSingleton();
    auto room1 = std::make_shared<ChatRoom>("room1");
    auto room2 = std::make_shared<ChatRoom>("room2");

    rooms->AddRoom("room1", room1);
    rooms->AddRoom("room2", room2);

    auto roomNames = rooms->GetRoomNames();
    auto getRoom1 = std::find(roomNames.begin(), roomNames.end(), "room1");
    auto getRoom2 = std::find(roomNames.begin(), roomNames.end(), "room2");

    EXPECT_EQ(roomNames.size(), 2);
    EXPECT_NE(getRoom1, roomNames.end());
    EXPECT_NE(getRoom2, roomNames.end());
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
