#include "SocketConnection.h"

SocketConnection::SocketConnection() {
    connect(&ws, &QWebSocket::textMessageReceived, this, &SocketConnection::SocketReadSuccess);
    connect(&ws, &QWebSocket::connected, this, &SocketConnection::Connected);
    connect(&ws, &QWebSocket::disconnected, this, &SocketConnection::Disconnected);
    connect(&ws, &QWebSocket::pong, this, &SocketConnection::Ponged);
    connect(&timer, &QTimer::timeout, this, &SocketConnection::PingServer);
}

void SocketConnection::ConnectToServer(const QString& ip, const QString& port) {
    QUrl url;
    url.setScheme(QStringLiteral("ws"));
    url.setHost(ip);
    url.setPort(port.toInt());
    ws.open(url);
}

void SocketConnection::SendMessage(const QString &msg) {
    ws.sendTextMessage(msg);
}

void SocketConnection::PingServer() {
    if (!pong) {
        return ws.close();
    }
    pong = false;
    ws.ping();
}

void SocketConnection::Ponged() {
    pong = true;
}

void SocketConnection::Connected() {
    pong = true;
    timer.start(5000);

    emit ConnectedToServer();
}

void SocketConnection::Disconnected() {
    qDebug() << "Disconnected from server";
    timer.stop();

    emit DisconnectedFromServer();
}
