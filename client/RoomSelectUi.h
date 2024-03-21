#ifndef CLIENT_SERVER_ROOMSELECTUI_H
#define CLIENT_SERVER_ROOMSELECTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomSelect
{
public:
    QGridLayout *gridLayout;
    QLineEdit *usernameLine;
    QComboBox *comboBox;
    QPushButton *joinRoomButton;
    QPushButton *createRoomButton;

    void setupUi(QWidget *RoomSelect)
    {
        if (RoomSelect->objectName().isEmpty())
            RoomSelect->setObjectName("RoomSelect");
        RoomSelect->resize(399, 233);
        QFont font;
        font.setPointSize(12);
        RoomSelect->setFont(font);
        RoomSelect->setStyleSheet(QString::fromUtf8("QWidget {\n"
                                                    "background-color:#1e2833;\n"
                                                    "color:white;\n"
                                                    "}\n"
                                                    "\n"
                                                    "QLineEdit {\n"
                                                    "  border:none;\n"
                                                    "  border-bottom:1px solid #434a52;\n"
                                                    "}\n"
                                                    "\n"
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
                                                    "QComboBox QAbstractItemView::item {\n"
                                                    "selection-background-color:  rgb(240, 62, 140);\n"
                                                    "min-height:40px;\n"
                                                    "}\n"
                                                    "\n"
                                                    "QComboBox QAbstractItemView::item:hover {\n"
                                                    "background-color:  rgb(240, 62, 140);\n"
                                                    "}"));
        gridLayout = new QGridLayout(RoomSelect);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(10);
        usernameLine = new QLineEdit(RoomSelect);
        usernameLine->setObjectName("usernameLine");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usernameLine->sizePolicy().hasHeightForWidth());
        usernameLine->setSizePolicy(sizePolicy);

        gridLayout->addWidget(usernameLine, 0, 0, 1, 1);

        comboBox = new QComboBox(RoomSelect);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        joinRoomButton = new QPushButton(RoomSelect);
        joinRoomButton->setObjectName("joinRoomButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(joinRoomButton->sizePolicy().hasHeightForWidth());
        joinRoomButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(joinRoomButton, 2, 0, 1, 1);

        createRoomButton = new QPushButton(RoomSelect);
        createRoomButton->setObjectName("createRoomButton");
        sizePolicy2.setHeightForWidth(createRoomButton->sizePolicy().hasHeightForWidth());
        createRoomButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(createRoomButton, 3, 0, 1, 1);


        retranslateUi(RoomSelect);

        QMetaObject::connectSlotsByName(RoomSelect);
    } // setupUi

    void retranslateUi(QWidget *RoomSelect)
    {
        RoomSelect->setWindowTitle(QCoreApplication::translate("RoomSelect", "RoomSelect", nullptr));
        usernameLine->setPlaceholderText(QCoreApplication::translate("RoomSelect", "enter username", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("RoomSelect", "select room", nullptr));
        joinRoomButton->setText(QCoreApplication::translate("RoomSelect", "Join room", nullptr));
        createRoomButton->setText(QCoreApplication::translate("RoomSelect", "Create room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomSelect: public Ui_RoomSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif //CLIENT_SERVER_ROOMSELECTUI_H
