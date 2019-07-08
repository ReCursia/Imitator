#include <Models/SendStrategies/NamedPipeSendStrategy.h>
#include <Models/SendStrategies/SharedMemorySendStrategy.h>
#include <Models/SendStrategies/SocketUdpSendStrategy.h>
#include "SendModel.h"
#include "Exceptions/NoDataToSend.h"
#include <Exceptions/SendError.h>
#include "QObject"
#include "QDebug"

SendModel::SendModel()
{
    //Status
    status = OFF;
    //Counter
    transmissionCounter = 0;
    //Timer
    timer = new QTimer();
    timer->setInterval(REPEAT_INTERVAL);
    connect(timer,SIGNAL(timeout()),this,SLOT(sendDatagram()));
    //Event manager
    eventManager = new EventManager();
    //Default strategy
    sendStrategy = new NamedPipeSendStrategy();
    //sendStrategy = nullptr;
}

SendModel::~SendModel()
{
    delete sendStrategy;
    delete eventManager;
    delete timer;
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

void SendModel::setSendStrategy(SendStrategy* newStrategy)
{
    //delete sendStrategy;
    //sendStrategy = newStrategy;
}


void SendModel::sendDatagram()
{
    try {
        sendStrategy->sendDatagramData(datagram);
        eventManager->notify("counter",QString::number(++transmissionCounter));
    } catch (SendError& err) {
        eventManager->notify("errorMessage",err.getErrorMessage());
    }
}
