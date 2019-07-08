#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"
#include "QStringListModel"
#include "DataModel.h"
#include <Utilities/SendStrategy.h>
#include <Utilities/EventManager.h>

enum Status {OFF,ON};

const int REPEAT_INTERVAL = 1000; //ms

class SendModel: public QObject
{
private:
    Q_OBJECT
    int transmissionCounter;
    Status status;
    QTimer* timer;
    QByteArray datagram;
    SendStrategy* sendStrategy;
    bool hasData();
private slots:
    void sendDatagram();
public:
    EventManager* eventManager;
    SendModel();
    ~SendModel();
    Status getCurrentStatus();
    void startTransmission();
    void stopTransmission();
    void setDatagramData(QByteArray array);
    void setSendStrategy(SendStrategy* newStrategy);
};


#endif // SOCKETUDPMODEL_H
