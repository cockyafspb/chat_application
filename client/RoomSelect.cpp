#include "RoomSelect.h"
#include "RoomSelectUi.h"
#include "RoomCommand.h"
#include <QListView>

RoomSelect::RoomSelect(SocketConnection& conn, QWidget *parent) :
    conn(conn), QWidget(parent), ui(new Ui::RoomSelect) {
    ui->setupUi(this);

    ui->comboBox->setView(new QListView());

    connect(ui->joinRoomButton, &QPushButton::clicked, this, &RoomSelect::SendJoinRoomCommand);
    connect(ui->createRoomButton, &QPushButton::clicked, this, &RoomSelect::SendCreateRoomCommand);
}

RoomSelect::~RoomSelect() {
    delete ui;
}

void RoomSelect::OnConnectionSuccess() {
    //should get room list now to add to QComboBox
    connect(&conn, &SocketConnection::SocketReadSuccess, this, &RoomSelect::GetRoomList);
    this->show();
}

void RoomSelect::GetRoomList(const QString& jsonRooms) {
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonRooms.toUtf8());

    QJsonObject jsonObject = jsonDocument.object();
    QJsonArray roomsArray = jsonObject.value("rooms").toArray();

    ui->comboBox->clear();

    for (auto value : roomsArray) {
        auto str = value.toString();
        ui->comboBox->addItem(str);
    }

    disconnect(&conn, &SocketConnection::SocketReadSuccess, this, &RoomSelect::GetRoomList);
}

void RoomSelect::SendJoinRoomCommand() {
    QString username = ui->usernameLine->text();
    QString roomname = ui->comboBox->currentText();
    if (username.isEmpty() || roomname.isEmpty()) {
        qDebug() << "Empty user or roomname";
        return;
    }

    RoomCommand cmd("join", username, roomname);
    conn.SendMessage(cmd.ToJsonByteArray());

    connect(&conn, &SocketConnection::SocketReadSuccess, this, &RoomSelect::GetRoomInfo);
}

void RoomSelect::SendCreateRoomCommand() {
    QString username = ui->usernameLine->text();
    QString roomname = username + "Room";
    if (username.isEmpty() || roomname.isEmpty()) {
        qDebug() << "Empty user or roomname";
        return;
    }

    RoomCommand cmd("create", username, roomname);
    conn.SendMessage(cmd.ToJsonByteArray());

    connect(&conn, &SocketConnection::SocketReadSuccess, this, &RoomSelect::GetRoomInfo);
}

void RoomSelect::GetRoomInfo(const QString &jsonRoomInfo) {
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonRoomInfo.toUtf8());

    QJsonObject jsonObject = jsonDocument.object();
    QJsonArray msgArray = jsonObject.value("messages").toArray();
    QJsonArray userArray = jsonObject.value("users").toArray();

    QStringList msgList;
    QStringList userList;

    for (auto value : msgArray) {
        auto str = value.toString();
        msgList.push_back(str);
    }

    for (auto value : userArray) {
        auto str = value.toString();
        userList.push_back(str);
    }

    RoomInfo roomInfo(msgList, userList);

    disconnect(&conn, &SocketConnection::SocketReadSuccess, this, &RoomSelect::GetRoomInfo);
    this->hide();
    emit JoiningRoom(roomInfo);
}

void RoomSelect::OnDisconnected() {
    this->hide();
}


