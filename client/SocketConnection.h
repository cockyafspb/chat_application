#ifndef CLIENT_SERVER_SOCKETCONNECTION_H
#define CLIENT_SERVER_SOCKETCONNECTION_H

#include <QObject>
#include <QtWebSockets>

class SocketConnection : public QObject {
Q_OBJECT

public:
    SocketConnection();
    void ConnectToServer(const QString& ip, const QString& port);
    void SendMessage(const QString& msg);
    void PingServer();
    void Ponged();
    void Connected();
    void Disconnected();

private:
    QWebSocket ws;
    QTimer timer;
    bool pong;

signals:
    void SocketReadSuccess(const QString& msg);
    void ConnectedToServer();
    void DisconnectedFromServer();
};


#endif //CLIENT_SERVER_SOCKETCONNECTION_H
