#include "SendModel.h"
#include "QDebug"
#include "Exceptions/NoDataToSend.h"
#include <Models/SendStratImpl/SocketUdpSendStrategy.h>

SendModel::SendModel()
{
    //Status
    status = OFF;
    //Counter
    transmissionCounter = 0;
    //Timer
    timer = new QTimer();
    timer->setInterval(REPEAT_INTERVAL);
    connect(timer,SIGNAL(timeout()),SLOT(sendDatagram()));
    //Default strategy
    strategy = new SocketUdpSendStrategy();
}

SendModel::~SendModel()
{
    delete timer;
    delete strategy;
}

Status SendModel::getCurrentStatus()
{
    return status;
}

void SendModel::startTransmission()
{
    if(!hasData()) throw NoDataToSend();
    if(status == OFF){
        timer->start();
        status = ON;
    }
}

bool SendModel::hasData()
{
    return !datagram.isEmpty();
}

void SendModel::stopTransmission()
{
    if(status == ON){
        timer->stop();
        status = OFF;
    }
}

void SendModel::setDatagramData(QByteArray array)
{
    datagram = array;
}

void SendModel::setStrategy(SendStrategy* newStrategy)
{
    delete strategy;
    strategy = newStrategy;
}


void SendModel::sendDatagram()
{
    strategy->sendDatagramData(datagram);
    //presenter->counterValueChanged(++transmissionCounter);
}
