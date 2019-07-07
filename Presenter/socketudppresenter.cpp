#include "SocketUdpPresenter.h"
#include "Exceptions/NoDataToSend.h"
#include "Exceptions/EmptyData.h"
#include <Models/SendStrategies/NamedPipeSendStrategy.h>
#include <Models/SendStrategies/SocketUdpSendStrategy.h>

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContractView* view)
{
    this->view = view;
    sendModel = new SendModel();
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
    //Validator
    view->setDoubleValidator(dataModel->getValidator());
    //Combo box
    //TODO FIX THAT
    for(int i = 0; i < 3; i++){
        ComboBoxValues value = static_cast<ComboBoxValues>(i);
        view->addItemToComboBox(COMBO_BOX_VALUES[value]);
    }
}

SocketUdpPresenter::~SocketUdpPresenter()
{
    delete sendModel;
    delete dataModel;
}

void SocketUdpPresenter::onStartButtonPressed()
{
    switch(sendModel->getCurrentStatus()){
    case OFF:
        startTransmission();
        break;
    case ON:
        stopTransmission();
        break;
    }
}

void SocketUdpPresenter::startTransmission()
{
    try {
        sendModel->startTransmission();
        view->lightOnLed();
        view->disableAcceptButton();
        view->disableComboBox();
        view->setStartButtonLabel(START_BUTTON_MESSAGE[STOP]);
    } catch (NoDataToSend&) {
        handleNoDataToSend();
    }
}

void SocketUdpPresenter::stopTransmission()
{
    sendModel->stopTransmission();
    view->lightOffLed();
    view->enableAcceptButton();
    view->enableComboBox();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void SocketUdpPresenter::handleNoDataToSend()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_SEND]);
}

void SocketUdpPresenter::onAcceptButtonPressed()
{
    try {
        sendModel->setDatagramData(dataModel->getDatagram());
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[ACCEPTED]);
    } catch (EmptyData&) {
        handleNoDataToAccept();
    }
}

void SocketUdpPresenter::onCurrentComboBoxIndexChanged(int index)
{
    switch(index){
    case UDP:
        sendModel->setSendStrategy(new SocketUdpSendStrategy());
        break;
    case NAMED_PIPE:
        sendModel->setSendStrategy(new NamedPipeSendStrategy());
        break;
    case SHARED_MEMORY:
        break;
    }
}

void SocketUdpPresenter::handleNoDataToAccept()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_ACCEPT]);
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
