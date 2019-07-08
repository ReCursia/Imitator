#ifndef SOCKETUDPSENDSTRATEGY_H
#define SOCKETUDPSENDSTRATEGY_H

#include <QObject>
#include <QUdpSocket>
#include <Utilities/SendStrategy.h>

const quint16 RECEIVER_PORT = 3456;
const quint16 SENDER_HOST = 1234;

class SocketUdpSendStrategy: public SendStrategy
{
private:
    QUdpSocket* socket;
    QHostAddress address;
public:
    SocketUdpSendStrategy();
    ~SocketUdpSendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // SOCKETUDPSENDSTRATEGY_H
