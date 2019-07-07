#ifndef SHAREDMEMORYSENDSTRATEGY_H
#define SHAREDMEMORYSENDSTRATEGY_H

#include <Utilities/SendStrategy.h>

#include <QSharedMemory>
#include <QSystemSemaphore>

const QString SEMAPHORE_NAME = "SemaphoreName";
const QString SHARED_MEMORY_NAME = "SharedMemoryName";

class SharedMemorySendStrategy : public SendStrategy
{
private:
    QSharedMemory* sharedMemory;
    QSystemSemaphore* semaphore;
public:
    SharedMemorySendStrategy();
    ~SharedMemorySendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // SHAREDMEMORYSENDSTRATEGY_H
