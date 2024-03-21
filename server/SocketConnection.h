#ifndef CLIENT_SERVER_SOCKETCONNECTION_H
#define CLIENT_SERVER_SOCKETCONNECTION_H

#include "Headers.h"
#include "RoomCommand.h"
using json = nlohmann::json;

class ChatRoom;

class SocketConnection : public std::enable_shared_from_this<SocketConnection> {
public:
    explicit SocketConnection(ip::tcp::socket&& socket);
    ~SocketConnection();
    void Send(const std::string& message);
    void AcceptWebsocket();
    std::string GetUserName();

private:
    websocket::stream<tcp_stream> ws;
    flat_buffer buf;
    std::shared_ptr<ChatRoom> room;
    std::string userName;
    steady_timer timer;
    bool pong;

    void SendRoomList();
    void FirstRead();
    void HandleRoomCommand(const RoomCommand& command);
    void ReadSocket();
    void SendRoomInfo();
    void SetPingTimer();
};


#endif //CLIENT_SERVER_SOCKETCONNECTION_H
