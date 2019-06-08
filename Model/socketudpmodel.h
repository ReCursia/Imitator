#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"

class SocketUdpModel: public QObject
{

private:
    Q_OBJECT
    const int REPEAT_INTERVAL = 1000; //ms
    int transmissionCounter;
    bool isWorking;
    QUdpSocket* socket;
    QTimer* timer;
    QList<double> data;
    double getCheckSum();
private slots:
    void sendDatagram();
public:
    SocketUdpModel();
    ~SocketUdpModel();
    int getCounter();
    void startTransmission();
    void stopTransmission();
    void setData(QList<double> data);
};


#endif // SOCKETUDPMODEL_H
