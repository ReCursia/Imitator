#include "SocketUdpPresenter.h"

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContractView* view)
{
    this->view = view;
    socketModel = new SocketUdpModel(this);
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
}

SocketUdpPresenter::~SocketUdpPresenter()
{
    delete socketModel;
    delete dataModel;
    delete view;
}

void SocketUdpPresenter::stopTransmission()
{
    socketModel->stopTransmission();
    view->lightOffLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void SocketUdpPresenter::startTransmission()
{
    socketModel->startTransmission();
    view->lightOnLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[STOP]);
}

void SocketUdpPresenter::onAcceptButtonPressed()
{
    socketModel->setDatagramData(dataModel->getDatagram());
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[ACCEPTED]);
}

void SocketUdpPresenter::onStartButtonPressed()
{
    switch(socketModel->getCurrentStatus()){
    case OFF:
        startTransmission();
        break;
    case ON:
        stopTransmission();
        break;
    }
}

void SocketUdpPresenter::onAddButtonPressed()
{
    dataModel->addValue(view->getEditLineText());
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[LINE_ADDED]);
}

void SocketUdpPresenter::onDeleteButtonPressed()
{
    if(view->hasSelectedRow()){
        dataModel->deleteValue(view->getSelectedRowIndex());
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[LINE_DELETED]);
    }else{
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[CHOOSE_LINE]);
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
