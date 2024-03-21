#ifndef CLIENT_SERVER_CHATROOMUI_H
#define CLIENT_SERVER_CHATROOMUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QGridLayout *gridLayout;
    QListWidget *msgboxWidget;
    QListWidget *userlistWidget;
    QLineEdit *msginputLine;
    QPushButton *sendmsgButton;

    void setupUi(QWidget *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName("ChatRoom");
        ChatRoom->resize(613, 439);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatRoom->sizePolicy().hasHeightForWidth());
        ChatRoom->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        ChatRoom->setFont(font);
        ChatRoom->setWindowOpacity(1.000000000000000);
        ChatRoom->setStyleSheet(QString::fromUtf8("QWidget {\n"
                                                  "background-color:#1e2833;\n"
                                                  "color:white;\n"
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
                                                  "\n"
                                                  "QListWidget, QLineEdit {\n"
                                                  "border: none;\n"
                                                  "border-radius:4px;\n"
                                                  "background-color: #233142;\n"
                                                  "}\n"
                                                  "\n"
                                                  "QListWidget::item {\n"
                                                  "height: 30px;\n"
                                                  "selection-background-color: #1e2833;\n"
                                                  "}\n"
                                                  "\n"
                                                  "QListWidget::item:active {\n"
                                                  "border:none;\n"
                                                  "}\n"
                                                  "\n"
                                                  "QListWidget::item:selected {\n"
                                                  "border:none;\n"
                                                  "}"));
        gridLayout = new QGridLayout(ChatRoom);
        gridLayout->setObjectName("gridLayout");
        msgboxWidget = new QListWidget(ChatRoom);
        msgboxWidget->setObjectName("msgboxWidget");
        msgboxWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(msgboxWidget, 0, 0, 1, 1);

        userlistWidget = new QListWidget(ChatRoom);
        userlistWidget->setObjectName("userlistWidget");
        userlistWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(userlistWidget, 0, 1, 1, 1);

        msginputLine = new QLineEdit(ChatRoom);
        msginputLine->setObjectName("msginputLine");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(msginputLine->sizePolicy().hasHeightForWidth());
        msginputLine->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(msginputLine, 1, 0, 1, 1);

        sendmsgButton = new QPushButton(ChatRoom);
        sendmsgButton->setObjectName("sendmsgButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sendmsgButton->sizePolicy().hasHeightForWidth());
        sendmsgButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(sendmsgButton, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 8);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnMinimumWidth(0, 2);
        gridLayout->setColumnMinimumWidth(1, 1);

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QWidget *ChatRoom)
    {
        ChatRoom->setWindowTitle(QCoreApplication::translate("ChatRoom", "ChatRoom", nullptr));
        msginputLine->setPlaceholderText(QCoreApplication::translate("ChatRoom", "enter msg", nullptr));
        sendmsgButton->setText(QCoreApplication::translate("ChatRoom", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif //CLIENT_SERVER_CHATROOMUI_H
