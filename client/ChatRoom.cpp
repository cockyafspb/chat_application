#include "ChatRoom.h"
#include "ChatRoomUi.h"

ChatRoom::ChatRoom(SocketConnection& conn, QWidget *parent) :
    conn(conn), QWidget(parent), ui(new Ui::ChatRoom) {
    ui->setupUi(this);

    connect(ui->sendmsgButton, &QPushButton::clicked, this, &ChatRoom::SendMessage);
}

ChatRoom::~ChatRoom() {
    delete ui;
}

void ChatRoom::InitRoom(RoomInfo roomInfo) {
    auto roomMsgs = roomInfo.messages;
    auto roomUsers = roomInfo.users;

    ui->msgboxWidget->clear();
    ui->userlistWidget->clear();

    for (const auto& s : roomMsgs) {
        ui->msgboxWidget->addItem(s);
    }

    for (const auto& s : roomUsers) {
        ui->userlistWidget->addItem(s);
    }

    connect(&conn, &SocketConnection::SocketReadSuccess, this, &ChatRoom::ReceiveMessage);
    this->show();
}

void ChatRoom::SendMessage() {
    auto msg = ui->msginputLine->text();
    ui->msginputLine->clear();
    conn.SendMessage(msg);
}

void ChatRoom::ReceiveMessage(const QString &msg) {
    qDebug() << "received msg: " << msg;
    ui->msgboxWidget->addItem(msg);
}

void ChatRoom::OnDisconnected() {
    disconnect(&conn, &SocketConnection::SocketReadSuccess, this, &ChatRoom::ReceiveMessage);
    this->hide();
}
