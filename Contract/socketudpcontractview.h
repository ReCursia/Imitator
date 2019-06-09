#ifndef SOCKETUDPCONTRACT_H
#define SOCKETUDPCONTRACT_H

#include <QObject>

class SocketUdpContractView
{
public:
    virtual ~SocketUdpContractView() = 0;
    //Start button
    virtual void setStartButtonLabel(QString str) = 0;


    //Counter
    virtual void setCounterValue(int value) = 0;
    //Status bar
    virtual void setStatusBarMessage(QString message) = 0;
    //Data
    virtual QList<double> getDataFromWidgetList() = 0;
};

#endif // SOCKETUDPCONTRACT_H
