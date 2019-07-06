#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Models/SendModel.h>
#include <Contracts/SocketUdpContractView.h>

const QStringList STATUS_BAR_MESSAGE = {"Данные утверждены","Параметр успешно удален","Выберите строку для удаления","Параметр успешно добавлен","Нет данных для отправления","Нет данных для утверждения"};
enum StatusMessage {ACCEPTED,LINE_DELETED,CHOOSE_LINE,LINE_ADDED,NO_DATA_TO_SEND,NO_DATA_TO_ACCEPT};

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

const QStringList COMBO_BOX_VALUES = {"UDP","Named pipe","Shared memory"};
enum ComboBoxValues {UDP,NAMED_PIPE,SHARED_MEMORY};

class SocketUdpPresenter: public QObject
{
private:
    Q_OBJECT
    SendModel* sendModel;
    DataModel* dataModel;
    SocketUdpContractView* view;
private:
    void stopTransmission();
    void startTransmission();
    void handleNoDataToSend();
    void handleNoDataToAccept();
public:
    SocketUdpPresenter(SocketUdpContractView* view);
    ~SocketUdpPresenter();
    void onAcceptButtonPressed();
    void onCurrentComboBoxIndexChanged(int index);
    void onStartButtonPressed();
    void onAddButtonPressed();
    void onDeleteButtonPressed();
};

#endif // SOCKETUDPPRESENTER_H
