#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>

#include <Model/socketudpmodel.h>

#include <Contract/socketudpcontractpresenter.h>
#include <Contract/socketudpcontractview.h>

class SocketUdpPresenter: public QObject, public SocketUdpContractPresenter
{
private:
    Q_OBJECT
    SocketUdpModel* model;
    SocketUdpContractView* view;
    Status status;
    void stopTransmission();
    void startTransmission();
public:
    SocketUdpPresenter(SocketUdpContractView* view);
    ~SocketUdpPresenter();
    void onAcceptButtonPressed();
    void onStartButtonPressed();
    // SocketUdpContractPresenter interface
public:
    void counterValueChanged(int value);
    void statusBarMessageChanged(QString message);
};

#endif // SOCKETUDPPRESENTER_H
