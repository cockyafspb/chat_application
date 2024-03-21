#ifndef CLIENT_SERVER_TESTSOCKETCONNECTION_H
#define CLIENT_SERVER_TESTSOCKETCONNECTION_H

#include <QTest>
#include "../client/SocketConnection.h"

class TestSocketConnection : public QObject {
Q_OBJECT
public:
    TestSocketConnection(const QString& serverIp, const QString& serverPort);
private:
    SocketConnection conn;
    QString serverIp;
    QString serverPort;
    int signalWaitTimeMs;

private slots:
    //server should be up and running for tests to work
    void initTestCase();
    void cleanupTestCase();
    void TestConnectToServer();
    void TestFirstReadFromServer();
    void TestSecondReadFromServer();
};


#endif //CLIENT_SERVER_TESTSOCKETCONNECTION_H
