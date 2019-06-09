#include "socketudpmodel.h"

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
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead())); //TESTING
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
    case ERROR:
        return "Ошибка";
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


void SocketUdpModel::setData(QList<double> data){
    this->data = data;
}

void SocketUdpModel::sendDatagram(){
    socket->writeDatagram("HELLLO",QHostAddress::LocalHost,1234); //Port 1234 ex.

    presenter->counterValueChanged(++transmissionCounter);
}

void SocketUdpModel::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 port;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&port);
    qDebug() << sender.toString() << port << "Message: " << buffer;
}

double SocketUdpModel::getCheckSum(){
    double checkSum = 0.0;
    foreach(double value,data){
        checkSum += value;
    }
    return checkSum;
}
