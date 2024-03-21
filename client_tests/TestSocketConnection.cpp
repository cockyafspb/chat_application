#include <QSignalSpy>
#include "TestSocketConnection.h"
#include "../client/RoomCommand.h"


void TestSocketConnection::initTestCase() {
    signalWaitTimeMs = 1000;
}

void TestSocketConnection::cleanupTestCase() {

}

void TestSocketConnection::TestConnectToServer() {
    QSignalSpy spy(&conn, SIGNAL(ConnectedToServer()));
    conn.ConnectToServer(serverIp, serverPort);

    QVERIFY(QTest::qWaitFor([&spy]() { return !spy.isEmpty(); }, signalWaitTimeMs));
}

void TestSocketConnection::TestFirstReadFromServer() {
    //first read is list of chat rooms
    QSignalSpy spy(&conn, SIGNAL(SocketReadSuccess(const QString&)));
    conn.ConnectToServer(serverIp, serverPort);

    QVERIFY(QTest::qWaitFor([&spy]() { return !spy.isEmpty(); }, signalWaitTimeMs));

    QList<QVariant> arguments = spy.takeFirst();
    QString roomsJson = arguments.at(0).toString();

    QVERIFY(roomsJson.contains("rooms"));
}

void TestSocketConnection::TestSecondReadFromServer() {
    QSignalSpy spy(&conn, SIGNAL(SocketReadSuccess(const QString&)));
    conn.ConnectToServer(serverIp, serverPort);

    QVERIFY(QTest::qWaitFor([&spy]() { return !spy.isEmpty(); }, signalWaitTimeMs));

    RoomCommand cmd("create", "user", "room");
    conn.SendMessage(cmd.ToJsonByteArray());

    QVERIFY(QTest::qWaitFor([&spy]() { return spy.count() == 2; }, signalWaitTimeMs));

    QList<QVariant> arguments = spy.takeAt(1);
    QString roomInfoJson = arguments.at(0).toString();

    QVERIFY(roomInfoJson.contains("messages"));
    QVERIFY(roomInfoJson.contains("users"));
}

TestSocketConnection::TestSocketConnection(const QString& serverIp, const QString& serverPort) :
    serverIp(serverIp), serverPort(serverPort) {
}
