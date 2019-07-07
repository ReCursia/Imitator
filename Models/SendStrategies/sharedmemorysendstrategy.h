#ifndef SHAREDMEMORYSENDSTRATEGY_H
#define SHAREDMEMORYSENDSTRATEGY_H

#include <Utilities/SendStrategy.h>

#include <QSharedMemory>
#include <QSystemSemaphore>


class SharedMemorySendStrategy : public SendStrategy
{
private:
    QSharedMemory* sharedMemory;
    QSystemSemaphore* semaphore;
    //void getDataExample();
public:
    SharedMemorySendStrategy();
    ~SharedMemorySendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // SHAREDMEMORYSENDSTRATEGY_H
