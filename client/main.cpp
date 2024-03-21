#include <QApplication>
#include "ServerConnect.h"
#include "RoomSelect.h"
#include "ChatRoom.h"
#include "SocketConnection.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    SocketConnection conn;
    ServerConnect connectWindow;
    RoomSelect roomSelect(conn);
    ChatRoom chatRoom(conn);
    connectWindow.show();

    QObject::connect(&conn,
                     &SocketConnection::ConnectedToServer,
                     &connectWindow,
                     &ServerConnect::OnConnectionSuccess);

    QObject::connect(&conn,
                     &SocketConnection::ConnectedToServer,
                     &roomSelect,
                     &RoomSelect::OnConnectionSuccess);

    QObject::connect(&conn,
                     &SocketConnection::DisconnectedFromServer,
                     &connectWindow,
                     &ServerConnect::OnDisconnected);

    QObject::connect(&conn,
                     &SocketConnection::DisconnectedFromServer,
                     &roomSelect,
                     &RoomSelect::OnDisconnected);

    QObject::connect(&conn,
                     &SocketConnection::DisconnectedFromServer,
                     &chatRoom,
                     &ChatRoom::OnDisconnected);

    QObject::connect(&connectWindow,
                     &ServerConnect::AttemptConnect,
                     &conn,
                     &SocketConnection::ConnectToServer);

    QObject::connect(&roomSelect,
                     &RoomSelect::JoiningRoom,
                     &chatRoom,
                     &ChatRoom::InitRoom);

    return QApplication::exec();
}
