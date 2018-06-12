#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QTime>

class client : public QWidget
{
    Q_OBJECT
public:
    client(const QString& ip, const QString& port);
    QTcpSocket* socket;
signals:
    void ClientConnectedToServer();
public slots:
    void slConnection();
    void slSendMessage(const QString& msg);
};

#endif // CLIENT_H
