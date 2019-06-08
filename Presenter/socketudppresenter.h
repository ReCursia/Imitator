#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>

#include <Model/socketudpmodel.h>

#include <Contract/socketudpcontract.h>

class SocketUdpPresenter: public QObject
{
private:
    Q_OBJECT
    SocketUdpModel* model;
    SocketUdpContract* view;
    enum Status {ON,OFF};
    Status status;
    void stopTransmission();
    void startTransmission();
public:
    SocketUdpPresenter(SocketUdpContract* view);
    ~SocketUdpPresenter();
    void onAcceptButtonPressed();
    void onStartButtonPressed();
};

#endif // SOCKETUDPPRESENTER_H
