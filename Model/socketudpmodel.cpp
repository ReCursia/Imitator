#include "SocketUdpModel.h"

SocketUdpModel::SocketUdpModel(SocketUdpContractPresenter* presenter){
    this->presenter = presenter;
    //Status
    status = OFF;
    //Counter
    transmissionCounter = 0;
    //Timer
    timer = new QTimer();
    timer->setInterval(REPEAT_INTERVAL);
    connect(timer,SIGNAL(timeout()),SLOT(sendDatagram()));
    //Socket
    QHostAddress adress;
    adress.setAddress(3232235631);
    socket = new QUdpSocket(this);
    socket->bind(adress,61924);
}

SocketUdpModel::~SocketUdpModel(){
    delete socket;
    delete timer;
    delete presenter;
}

Status SocketUdpModel::getCurrentStatus()
{
    return status;
}

QString SocketUdpModel::getCurrentStatusMessage()
{
    switch(status){
    case OFF:
        return "Передача прекращена";
    case ON:
        return "Передача началась";
    }
}

void SocketUdpModel::startTransmission(){
    if(status == OFF){
        timer->start();
        status = ON;
    }
    presenter->statusBarMessageChanged(getCurrentStatusMessage());
}

void SocketUdpModel::stopTransmission(){
    if(status == ON){
        timer->stop();
        status = OFF;
    }
    presenter->statusBarMessageChanged(getCurrentStatusMessage());
}

void SocketUdpModel::setDatagramData(QByteArray array)
{
    datagram = array;
}


void SocketUdpModel::sendDatagram(){
    //TESTING
    /*
    QHostAddress adress;
    adress.setAddress(3232235631);
    socket->writeDatagram("HELLLO",adress,61924); //Port 1234 ex.
    */
    presenter->counterValueChanged(++transmissionCounter);
}
