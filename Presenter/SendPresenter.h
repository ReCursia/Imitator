#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Models/SendModel.h>
#include <Contracts/SendContractView.h>
#include <Utilities/EventListener.h>
#include <Utilities/EventManager.h>

const QStringList STATUS_BAR_MESSAGE = {"Данные утверждены","Параметр успешно удален","Выберите строку для удаления",
                                        "Параметр успешно добавлен","Нет данных для отправления",
                                        "Нет данных для утверждения","Данные удалены","Данные сгенерированы и добавлены"};

enum StatusMessage {ACCEPTED,LINE_DELETED,CHOOSE_LINE,LINE_ADDED,NO_DATA_TO_SEND,NO_DATA_TO_ACCEPT,DELETED_ALL,DATA_GENERATED};

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

const QStringList COMBO_BOX_VALUES = {"UDP","Named pipe","Shared memory"};
enum ComboBoxValues {UDP,NAMED_PIPE,SHARED_MEMORY};
const int COMBO_BOX_SIZE = COMBO_BOX_VALUES.size();

class SendPresenter : public EventListener
{
private:
    SendModel* sendModel;
    DataModel* dataModel;
    SendContractView* view;
private:
    void stopTransmission();
    void startTransmission();
    void handleNoDataToSend();
    void handleNoDataToAccept();
public:
    SendPresenter(SendContractView* view);
    ~SendPresenter();
    void onAcceptButtonPressed();
    void onCurrentComboBoxIndexChanged(int index);
    void onStartButtonPressed();
    void onAddButtonPressed();
    void onDeleteButtonPressed();
    void onDeleteAllButtonPressed();
    void onGenerateDataButtonPressed();
    void update(QString eventType, QString message);
};

#endif // SOCKETUDPPRESENTER_H
