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
    double getCheckSum(){
        double checkSum = 0.0;
        foreach(double value,data){
            checkSum += value;
        }
        return checkSum;
    }
public:
    SocketUdpModel(){
        //Counter
        transmissionCounter = 0;
        //Timer
        timer = new QTimer();
        timer->setInterval(REPEAT_INTERVAL);
        connect(timer,SIGNAL(timeout()),SLOT(sendDatagram()));
        //Status
        isWorking = false;
        //Socket
        socket = new QUdpSocket(this);
        socket->bind(QHostAddress::LocalHost);
    }
    ~SocketUdpModel(){
        delete socket;
        delete timer;
    }
    int getCounter(){
        return transmissionCounter;
    }
    void startTransmission(){
        if(!isWorking){
            timer->start();
            isWorking = true;
        }
    }
    void stopTransmission(){
        if(isWorking){
            timer->stop();
            isWorking = false;
        }
    }
    void setData(QList<double> data){
        this->data = data;
    }
public slots:
    void sendDatagram(){
        qDebug() << data << " " << getCheckSum();
    }
};

#endif // SOCKETUDPMODEL_H
