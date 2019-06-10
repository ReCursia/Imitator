#include "SocketUdpPresenter.h"


void SocketUdpPresenter::stopTransmission()
{
    model->stopTransmission();
    view->lightOffLed();
    view->setStartButtonLabel("Запуск");
}

void SocketUdpPresenter::startTransmission()
{
    model->startTransmission();
    view->lightOnLed();
    view->setStartButtonLabel("Остановка");
}

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContractView* view)
{
    this->view = view;
    model = new SocketUdpModel(this);
}

SocketUdpPresenter::~SocketUdpPresenter()
{
    delete model;
    delete view;
}

void SocketUdpPresenter::onAcceptButtonPressed()
{
    model->setData(view->getDataFromWidgetList());
    view->setStatusBarMessage("Данные утверждены"); //TODO закинуть как константы
}

void SocketUdpPresenter::onStartButtonPressed()
{
    switch(model->getCurrentStatus()){
    case OFF:
        startTransmission();
        break;
    case ON:
        stopTransmission();
        break;
    case ERROR:
        //Выбросить ошибку?
        break;
    }
}

void SocketUdpPresenter::counterValueChanged(int value)
{
    view->setCounterValue(value);
}

void SocketUdpPresenter::statusBarMessageChanged(QString message)
{
    view->setStatusBarMessage(message);
}
