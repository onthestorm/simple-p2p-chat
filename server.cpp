#include "server.h"

server::server(const QString &ip, const QString &port) {
    Server = new QTcpServer(this);
    QHostAddress address(ip);
    Server->listen(address, port.toInt());
    connect(Server, SIGNAL(newConnection()), this, SLOT(slNewConnection()));
}

void server::slNewConnection() {
    emit connection();
    QTcpSocket* Socket = Server->nextPendingConnection();
    connect(Socket, SIGNAL(readyRead()), this, SLOT(slReading()));
}

void server::slReading() {
    Block = 0;
    QTcpSocket* Socket = (QTcpSocket*)sender();
    QDataStream in(Socket);
    for(;;) {
        if(!Block) {
            if(Socket->bytesAvailable() < sizeof(quint16)) break;
            in >> Block;
        }
    if(Socket->bytesAvailable() < Block) break;
    QTime time;
    QString Message, msg;
    in >> time >> msg;
    Message = time.toString() + " Client : " + msg;
    Block = 0;
    emit message(Message);
    }
}
