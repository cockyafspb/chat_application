#ifndef CLIENT_SERVER_ROOMSELECT_H
#define CLIENT_SERVER_ROOMSELECT_H

#include <QWidget>
#include "SocketConnection.h"
#include "RoomInfo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class RoomSelect; }
QT_END_NAMESPACE

class RoomSelect : public QWidget {
Q_OBJECT

public:
    explicit RoomSelect(SocketConnection& conn, QWidget *parent = nullptr);
    ~RoomSelect() override;

private:
    Ui::RoomSelect *ui;
    SocketConnection& conn;
    void GetRoomList(const QString& jsonRooms);
    void GetRoomInfo(const QString& jsonRoomInfo);
    void SendJoinRoomCommand();
    void SendCreateRoomCommand();

public slots:
    void OnConnectionSuccess();
    void OnDisconnected();

signals:
    void JoiningRoom(RoomInfo roomInfo);
};


#endif //CLIENT_SERVER_ROOMSELECT_H
