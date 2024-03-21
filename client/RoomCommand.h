#ifndef CLIENT_SERVER_ROOMCOMMAND_H
#define CLIENT_SERVER_ROOMCOMMAND_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <utility>

class RoomCommand {
public:
    RoomCommand(QString operation, QString userName, QString roomName) :
    operation(std::move(operation)), roomName(std::move(roomName)), userName(std::move(userName)) {
    }

    QString operation;
    QString userName;
    QString roomName;

    QByteArray ToJsonByteArray() const {
        QJsonObject obj;
        obj["operation"] = operation;
        obj["roomName"] = roomName;
        obj["userName"] = userName;

        QByteArray data = QJsonDocument(obj).toJson();

        return data;
    }

    void FromJsonObject(const QJsonObject& json) {
        operation = json.value("operation").toString();
        roomName = json.value("roomName").toString();
        userName = json.value("userName").toString();
    }
};


#endif //CLIENT_SERVER_ROOMCOMMAND_H
