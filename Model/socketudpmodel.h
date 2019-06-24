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

class SocketUdpModel: public QObject
{
private:
    Q_OBJECT
    int transmissionCounter;
    bool isWorking;
    Status status;
    QUdpSocket* socket;
    QHostAddress adress;
    QTimer* timer;
    SocketUdpContractPresenter* presenter;
    QByteArray datagram;
private:
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
