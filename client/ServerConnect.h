#ifndef CLIENT_SERVER_SERVERCONNECT_H
#define CLIENT_SERVER_SERVERCONNECT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ServerConnect; }
QT_END_NAMESPACE

class ServerConnect : public QWidget {
    Q_OBJECT

public:
    explicit ServerConnect(QWidget *parent = nullptr);
    ~ServerConnect() override;

private:
    Ui::ServerConnect *ui;

signals:
    void AttemptConnect(const QString& ip, const QString& port);

private slots:
    void ConnectClicked();

public slots:
    void OnConnectionSuccess();
    void OnDisconnected();
};


#endif //CLIENT_SERVER_SERVERCONNECT_H
