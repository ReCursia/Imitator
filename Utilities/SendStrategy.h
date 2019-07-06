#ifndef SENDSTRATEGY_H
#define SENDSTRATEGY_H

#include <QByteArray>

class SendStrategy
{
public:
    SendStrategy(){}
    virtual ~SendStrategy(){}
    virtual void sendDatagramData(QByteArray array) = 0;
};

#endif // SENDSTRATEGY_H
