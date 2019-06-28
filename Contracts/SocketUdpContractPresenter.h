#ifndef SOCKETUDPCONTRACTPRESENTER_H
#define SOCKETUDPCONTRACTPRESENTER_H

#include "QString"

class SocketUdpContractPresenter
{
public:
    virtual ~SocketUdpContractPresenter() = 0;
    virtual void counterValueChanged(int value) = 0;
    virtual void statusBarMessageChanged(QString message) = 0;
};

#endif // SOCKETUDPCONTRACTPRESENTER_H
