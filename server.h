#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

class server : public QWidget
{
    Q_OBJECT
public:
    server(const QString& ip, const QString& port);
private:
    QTcpServer* Server;
    QTcpSocket* Socket;
    quint16 Block;
signals:
    void connection();
    void message(const QString& msg);
public slots:
    void slNewConnection();
    void slReading();
};

#endif // SERVER_H
