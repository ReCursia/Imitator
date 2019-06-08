#ifndef SOCKETUDPCONTRACT_H
#define SOCKETUDPCONTRACT_H

#include <QObject>

class SocketUdpContract
{
public:
    virtual ~SocketUdpContract() = 0;
    //Start button
    virtual void setStartButtonLabel(QString str) = 0;
    //Progress bar
    virtual void setProgressBarLabel(QString str) = 0;
    virtual void setProgressBarValue(int value) = 0;
    //Counter
    virtual void setCounterValue(int value) = 0;
    //Status bar
    virtual void setStatusBarMessage(QString message) = 0;
    //Get data from table?
};

#endif // SOCKETUDPCONTRACT_H
