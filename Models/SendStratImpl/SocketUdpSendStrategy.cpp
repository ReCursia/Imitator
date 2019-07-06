#include "SocketUdpSendStrategy.h"

SocketUdpSendStrategy::SocketUdpSendStrategy()
{
    //Socket
    socket = new QUdpSocket();
    address.setAddress(QHostAddress::LocalHost);
    socket->bind(address,SENDER_HOST);
}

SocketUdpSendStrategy::~SocketUdpSendStrategy()
{
    delete socket;
}

void SocketUdpSendStrategy::sendDatagramData(QByteArray array)
{
    socket->writeDatagram(array,address,RECEIVER_PORT); //Port 1234 ex.
    qDebug() << QString::fromStdString(array.toStdString());
}
