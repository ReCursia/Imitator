#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"

#include <Contract/SocketUdpContractPresenter.h>

enum Status {OFF,ON,ERROR};

class SocketUdpModel: public QObject
{
private:
    Q_OBJECT
    const int REPEAT_INTERVAL = 1000; //ms
    const int HEADER = 0x55AA;
    int transmissionCounter;
    bool isWorking;
    Status status;
    QUdpSocket* socket;
    QTimer* timer;
    QList<double> data;
    double getCheckSum();
    QString getCurrentStatusMessage();
    SocketUdpContractPresenter* presenter;
private slots:
    void sendDatagram();
    //void readyRead(); //TESTING
public:
    SocketUdpModel(SocketUdpContractPresenter* presenter);
    ~SocketUdpModel();
    Status getCurrentStatus();
    void startTransmission();
    void stopTransmission();
    void setData(QList<double> data);
};


#endif // SOCKETUDPMODEL_H
