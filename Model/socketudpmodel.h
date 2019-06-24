#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"
#include "QStringListModel"
#include "DataModel.h"
#include <Contract/SocketUdpContractPresenter.h>

enum Status {OFF,ON};

const int REPEAT_INTERVAL = 1000; //ms
const int HEADER = 0x55AA;
const quint16 RECEIVER_PORT = 3456;
const quint16 SENDER_HOST = 1234;

class SocketUdpModel: public QObject
{
private:
    Q_OBJECT
    int transmissionCounter;
    Status status;
    QUdpSocket* socket;
    QHostAddress address;
    QTimer* timer;
    SocketUdpContractPresenter* presenter;
    QByteArray datagram;
    QString getCurrentStatusMessage();
private slots:
    void sendDatagram();
public:
    SocketUdpModel(SocketUdpContractPresenter* presenter);
    ~SocketUdpModel();
    Status getCurrentStatus();
    void startTransmission();
    void stopTransmission();
    void setDatagramData(QByteArray array);
};


#endif // SOCKETUDPMODEL_H
