#ifndef CLIENT_SERVER_SERVERCONNECTUI_H
#define CLIENT_SERVER_SERVERCONNECTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerConnect
{
public:
    QGridLayout *gridLayout;
    QLineEdit *ipLine;
    QLineEdit *portLine;
    QPushButton *connectButton;

    void setupUi(QWidget *ServerConnect)
    {
        if (ServerConnect->objectName().isEmpty())
            ServerConnect->setObjectName("ServerConnect");
        ServerConnect->resize(347, 178);
        QFont font;
        font.setPointSize(12);
        ServerConnect->setFont(font);
        ServerConnect->setStyleSheet(QString::fromUtf8("QWidget {\n"
                                                       "background-color:#1e2833\n;"
                                                       "color:white;\n"
                                                       "}\n"
                                                       "\n"
                                                       "QLineEdit {\n"
                                                       "  border:none;\n"
                                                       "  border-bottom:1px solid #434a52;\n"
                                                       "}\n"
                                                       "\n"
                                                       "QPushButton {\n"
                                                       "  background-color:#214a80;\n"
                                                       "  border:none;\n"
                                                       "  border-radius:4px;\n"
                                                       "}\n"
                                                       "\n"
                                                       "QPushButton:hover{\n"
                                                       "background-color:  rgb(240, 62, 140);\n"
                                                       "}\n"
                                                       ""));
        gridLayout = new QGridLayout(ServerConnect);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(10);
        ipLine = new QLineEdit(ServerConnect);
        ipLine->setObjectName("ipLine");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ipLine->sizePolicy().hasHeightForWidth());
        ipLine->setSizePolicy(sizePolicy);
        ipLine->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ipLine, 0, 0, 1, 1);

        portLine = new QLineEdit(ServerConnect);
        portLine->setObjectName("portLine");
        sizePolicy.setHeightForWidth(portLine->sizePolicy().hasHeightForWidth());
        portLine->setSizePolicy(sizePolicy);
        portLine->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(portLine, 1, 0, 1, 1);

        connectButton = new QPushButton(ServerConnect);
        connectButton->setObjectName("connectButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy1);
        connectButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(connectButton, 2, 0, 1, 1);


        retranslateUi(ServerConnect);

        QMetaObject::connectSlotsByName(ServerConnect);
    } // setupUi

    void retranslateUi(QWidget *ServerConnect)
    {
        ServerConnect->setWindowTitle(QCoreApplication::translate("ServerConnect", "ServerConnect", nullptr));
        ipLine->setPlaceholderText(QCoreApplication::translate("ServerConnect", "enter ip", nullptr));
        portLine->setPlaceholderText(QCoreApplication::translate("ServerConnect", "enter port", nullptr));
        connectButton->setText(QCoreApplication::translate("ServerConnect", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerConnect: public Ui_ServerConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif //CLIENT_SERVER_SERVERCONNECTUI_H
