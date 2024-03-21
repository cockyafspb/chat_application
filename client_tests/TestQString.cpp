#include "TestQString.h"

void TestQString::toUpper() {
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}
