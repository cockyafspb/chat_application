#ifndef CLIENT_SERVER_CHATROOM_H
#define CLIENT_SERVER_CHATROOM_H

#include <QWidget>
#include "SocketConnection.h"
#include "RoomInfo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChatRoom; }
QT_END_NAMESPACE

class ChatRoom : public QWidget {
Q_OBJECT

public:
    explicit ChatRoom(SocketConnection& conn, QWidget *parent = nullptr);

    ~ChatRoom() override;
    void InitRoom(RoomInfo roomInfo);

private:
    Ui::ChatRoom *ui;
    SocketConnection& conn;

private slots:
    void SendMessage();
    void ReceiveMessage(const QString& msg);

public slots:
    void OnDisconnected();
};


#endif //CLIENT_SERVER_CHATROOM_H
