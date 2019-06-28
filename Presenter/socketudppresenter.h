#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Models/SocketUdpModel.h>
#include <Contracts/SocketUdpContractPresenter.h>
#include <Contracts/SocketUdpContractView.h>

const QStringList STATUS_BAR_MESSAGE = {"Данные утверждены","Параметр успешно удален","Выберите строку для удаления","Параметр успешно добавлен","Нет данных для отправления","Нет данных для утверждения"};
enum StatusMessage {ACCEPTED,LINE_DELETED,CHOOSE_LINE,LINE_ADDED,NO_DATA_TO_SEND,NO_DATA_TO_ACCEPT};

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

class SocketUdpPresenter: public QObject, public SocketUdpContractPresenter
{
private:
    Q_OBJECT
    SocketUdpModel* socketModel;
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
    void onStartButtonPressed();
    void onAddButtonPressed();
    void onDeleteButtonPressed();
    void counterValueChanged(int value);
    void statusBarMessageChanged(QString message);
};

#endif // SOCKETUDPPRESENTER_H
