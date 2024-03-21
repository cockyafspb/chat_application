#include "ServerConnect.h"
#include "ServerConnectUi.h"


ServerConnect::ServerConnect(QWidget *parent) :
    QWidget(parent), ui(new Ui::ServerConnect) {
    ui->setupUi(this);

    connect(ui->connectButton, &QPushButton::clicked, this, &ServerConnect::ConnectClicked);
}

ServerConnect::~ServerConnect() {
    delete ui;
}

void ServerConnect::ConnectClicked() {
    QString ip = ui->ipLine->text();
    QString port = ui->portLine->text();

    emit AttemptConnect(ip, port);
}

void ServerConnect::OnConnectionSuccess() {
    qDebug() << "conn success, hiding serv connect";
    this->hide();
}

void ServerConnect::OnDisconnected() {
    qDebug() << "conn lost, showing serv connect";
    this->show();
}
