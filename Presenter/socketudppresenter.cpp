#include "socketudppresenter.h"


void SocketUdpPresenter::stopTransmission()
{
    model->stopTransmission();
    view->setStartButtonLabel("Запуск");
}

void SocketUdpPresenter::startTransmission()
{
    model->startTransmission();
    view->setStartButtonLabel("Остановка");
}

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContract* view)
{
    this->view = view;
    status = OFF;
}

SocketUdpPresenter::~SocketUdpPresenter()
{
    delete model;
    delete view;
}

void SocketUdpPresenter::onAcceptButtonPressed()
{
    //Get data from table
}

void SocketUdpPresenter::onStartButtonPressed()
{
    switch(status){
    case OFF:
        startTransmission();
        break;
    case ON:
        stopTransmission();
        break;
    }
}
