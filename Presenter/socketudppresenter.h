#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Model/SocketUdpModel.h>
#include <Contract/SocketUdpContractPresenter.h>
#include <Contract/SocketUdpContractView.h>

const QStringList STATUS_BAR_MESSAGE = {"Данные утверждены","Параметр успешно удален","Выберите строку для удаления","Параметр успешно добавлен"};
enum StatusMessage {ACCEPTED,LINE_DELETED,CHOOSE_LINE,LINE_ADDED};

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
