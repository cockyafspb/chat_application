#include "SocketConnection.h"
#include "RoomsSingleton.h"

SocketConnection::SocketConnection(ip::tcp::socket &&socket) :
    ws(std::move(socket)), timer(ws.get_executor()), pong(true) {
}

SocketConnection::~SocketConnection() {
    std::cout << "SocketConnection dtr called\n";
    if (room) {
        room->RemoveSocket(this);
    }
}

void SocketConnection::Send(const std::string &message) {
    ws.async_write(
        buffer(message),
        [self = shared_from_this()] (error_code err, auto) {
        });
}

void SocketConnection::AcceptWebsocket() {
    ws.async_accept([this, self = shared_from_this()](error_code err) {
        if (!err) {
            std::cout << "Server accepted websocket connection from client" << std::endl;
            using namespace websocket;

            ws.control_callback(
                [this](frame_type ft, const std::string&) {
                    if (ft == frame_type::pong) {
                        pong = true;
                    }
                });

            SendRoomList();
        }
    });
}

void SocketConnection::SendRoomList() {
    auto rooms = RoomsSingleton::GetInstance();
    auto roomNames = rooms->GetRoomNames();

    json js;
    js["rooms"] = roomNames;
    auto str = nlohmann::to_string(js);

    ws.async_write(
        buffer(str),
        [str, this, self = shared_from_this()] (error_code err, auto) {
            if (!err) {
                std::cout << "Sent rooms json to client:\n" << str << std::endl;
                FirstRead();
            }
        });
}

void SocketConnection::FirstRead() {
    ws.async_read(
        buf,
        [this, self = shared_from_this()] (error_code err, auto) {
            if (!err) {
                auto str = buffers_to_string(buf.data());
                std::cout << "Received command from client:\n" << str << std::endl;

                RoomCommand cmd = json::parse(str).template get<RoomCommand>();
                HandleRoomCommand(cmd);

                SendRoomInfo();
            }
        });
}

void SocketConnection::HandleRoomCommand(const RoomCommand &command) {
    auto rooms = RoomsSingleton::GetInstance();
    userName = command.userName;

    if (command.operation == "create") {
        room = std::make_shared<ChatRoom>(command.roomName);
        rooms->AddRoom(command.roomName, room);
    } else if (command.operation == "join") {
        room = rooms->GetRoom(command.roomName);
    }

    room->AddSocket(this);
}

void SocketConnection::ReadSocket() {
    buf.consume(buf.size());

    ws.async_read(
        buf,
        [this, self = shared_from_this()] (error_code err, auto) {
            if (!err) {
                auto str = buffers_to_string(buf.data());
                std::cout << "Received on read:" << str << std::endl;

                room->BroadcastMessage(userName, str);

                ReadSocket();
            }
        });
}

std::string SocketConnection::GetUserName() {
    return userName;
}

void SocketConnection::SendRoomInfo() {
    json js;
    js["messages"] = room->GetMessages();
    js["users"] = room->GetUsers();
    auto str = nlohmann::to_string(js);

    ws.async_write(
        buffer(str),
        [str, this, self = shared_from_this()] (error_code err, auto) {
            if (!err) {
                std::cout << "Sent room info to client:\n" << str << std::endl;
                ReadSocket();

                SetPingTimer();
            }
        });
}

void SocketConnection::SetPingTimer() {
    static const int pingSec = 5;

    if (!pong) {
        std::cerr << "Pong timeout\n";
        return ws.async_close("Pong timeout", [](auto) {
        });
    }

    pong = false;

    ws.async_ping("", [this](error_code err) {
        if (!err) {
            timer.expires_after(chrono::seconds(pingSec));
            timer.async_wait([this](error_code err) {
                SetPingTimer();
            });
        }
    });
}
