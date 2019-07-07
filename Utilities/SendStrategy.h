#ifndef SENDSTRATEGY_H
#define SENDSTRATEGY_H

#include <QByteArray>
#include "QDebug"

class SendStrategy
{
public:
    virtual ~SendStrategy(){}
    virtual void sendDatagramData(QByteArray array) = 0;
};

#endif // SENDSTRATEGY_H
