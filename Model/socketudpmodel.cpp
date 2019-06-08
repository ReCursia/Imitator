#include "socketudpmodel.h"

SocketUdpModel::SocketUdpModel(){
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

SocketUdpModel::~SocketUdpModel(){
    delete socket;
    delete timer;
}

int SocketUdpModel::getCounter(){
    return transmissionCounter;
}

void SocketUdpModel::startTransmission(){
    if(!isWorking){
        timer->start();
        isWorking = true;
    }
}

void SocketUdpModel::stopTransmission(){
    if(isWorking){
        timer->stop();
        isWorking = false;
    }
}

void SocketUdpModel::setData(QList<double> data){
    this->data = data;
}

void SocketUdpModel::sendDatagram(){
    qDebug() << data << " " << getCheckSum();
}

double SocketUdpModel::getCheckSum(){
    double checkSum = 0.0;
    foreach(double value,data){
        checkSum += value;
    }
    return checkSum;
}
