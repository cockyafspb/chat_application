#include "TestQString.h"
#include "TestSocketConnection.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString serverIp = "172.28.22.88";
    QString serverPort = "1234";

    QTest::qExec(new TestQString, argc, argv); //test test
    QTest::qExec(new TestSocketConnection(serverIp, serverPort), argc, argv);

    return 0;
}