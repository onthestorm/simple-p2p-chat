#include "client.h"

client::client(const QString &ip, const QString &port)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port.toInt());
    connect(socket, SIGNAL(connected()), this, SLOT(slConnection()));
}

void client::slConnection()
{
    emit ClientConnectedToServer();
}

void client::slSendMessage(const QString &msg) {
    QByteArray Block;
    QDataStream out(&Block, QIODevice::WriteOnly);
    out << quint16(0) << QTime::currentTime() << msg;
    out.device()->seek(0);
    out << quint16(Block.size() - sizeof(quint16));
    socket->write(Block);
}
