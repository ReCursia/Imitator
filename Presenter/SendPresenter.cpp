#include "SendPresenter.h"
#include "Exceptions/NoDataToSend.h"
#include "Exceptions/EmptyData.h"
#include <Models/SendStrategies/NamedPipeSendStrategy.h>
#include <Models/SendStrategies/SharedMemorySendStrategy.h>
#include <Models/SendStrategies/SocketUdpSendStrategy.h>

SendPresenter::SendPresenter(SendContractView* view)
{
    this->view = view;
    sendModel = new SendModel();
    //Subcribe to sendModel
    sendModel->eventManager->subscribe(this);
    //Data model
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
    //Validator
    view->setValidator(dataModel->getValidator());
    //Combo box
    for(int i = 0; i < COMBO_BOX_SIZE; i++){
        ComboBoxValues value = static_cast<ComboBoxValues>(i);
        view->addItemToComboBox(COMBO_BOX_VALUES[value]);
    }
}

SendPresenter::~SendPresenter()
{
    delete sendModel;
    delete dataModel;
}

void SendPresenter::onStartButtonPressed()
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

void SendPresenter::startTransmission()
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

void SendPresenter::stopTransmission()
{
    sendModel->stopTransmission();
    view->lightOffLed();
    view->enableAcceptButton();
    view->enableComboBox();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void SendPresenter::handleNoDataToSend()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_SEND]);
}

void SendPresenter::onAcceptButtonPressed()
{
    try {
        sendModel->setDatagramData(dataModel->getDatagram());
        showStatusBarAcceptMessage();
    } catch (EmptyData&) {
        handleNoDataToAccept();
    }
}

void SendPresenter::showStatusBarAcceptMessage()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[ACCEPTED]+
                              ", размер данных (в байтах) = "+
                              QString::number(sendModel->getDatagramSize()));
}

void SendPresenter::onCurrentComboBoxIndexChanged(int index)
{
    switch(index){
    case UDP:
        sendModel->setSendStrategy(new SocketUdpSendStrategy());
        break;
    case NAMED_PIPE:
        sendModel->setSendStrategy(new NamedPipeSendStrategy());
        break;
    case SHARED_MEMORY:
        sendModel->setSendStrategy(new SharedMemorySendStrategy());
        break;
    }
}

void SendPresenter::handleNoDataToAccept()
{
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[NO_DATA_TO_ACCEPT]);
}

void SendPresenter::onAddButtonPressed()
{
    dataModel->addValue(view->getEditLineText());
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[LINE_ADDED]);
}

void SendPresenter::onDeleteButtonPressed()
{
    if(view->hasSelectedRow()){
        dataModel->deleteValue(view->getSelectedRowIndex());
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[LINE_DELETED]);
    }else{
        view->setStatusBarMessage(STATUS_BAR_MESSAGE[CHOOSE_LINE]);
    }
}

void SendPresenter::onDeleteAllButtonPressed()
{
    dataModel->clear();
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[DELETED_ALL]);
}

void SendPresenter::onGenerateDataButtonPressed()
{
    dataModel->generateRandomData();
    view->setStatusBarMessage(STATUS_BAR_MESSAGE[DATA_GENERATED]);
}

void SendPresenter::update(QString eventType, QString message)
{
    if(eventType == "counter"){
        view->setCounterValue(message.toInt());
    }else if(eventType == "errorMessage"){
        view->setStatusBarMessage(message);
    }
}
