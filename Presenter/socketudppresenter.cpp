#include "SocketUdpPresenter.h"
#include "Exceptions/NoDataToSend.h"
#include "Exceptions/EmptyData.h"

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContractView* view)
{
    this->view = view;
    socketModel = new SocketUdpModel(this);
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
    //Validator
    view->setDoubleValidator(dataModel->getValidator());
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
    view->enableAcceptButton();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void SocketUdpPresenter::startTransmission()
{
    try {
        socketModel->startTransmission();
        view->lightOnLed();
        view->disableAcceptButton();
        view->setStartButtonLabel(START_BUTTON_MESSAGE[STOP]);
    } catch (NoDataToSend&) {
        handleNoDataToSend();
    }

}

void SocketUdpPresenter::handleNoDataToAccept()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_ACCEPT]);
}

void SocketUdpPresenter::handleNoDataToSend()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_SEND]);
}

void SocketUdpPresenter::onAcceptButtonPressed()
{
    try {
        socketModel->setDatagramData(dataModel->getDatagram());
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[ACCEPTED]);
    } catch (EmptyData&) {
        handleNoDataToAccept();
    }
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
