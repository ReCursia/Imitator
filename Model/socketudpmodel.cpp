#include "SocketUdpModel.h"
#include "QDebug"

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
    socket = new QUdpSocket(this);
    address.setAddress(QHostAddress::LocalHost);
    socket->bind(address,SENDER_HOST);
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
    socket->writeDatagram(datagram,address,RECEIVER_PORT); //Port 1234 ex.
    qDebug() << QString::fromStdString(datagram.toStdString());
    presenter->counterValueChanged(++transmissionCounter);
}
