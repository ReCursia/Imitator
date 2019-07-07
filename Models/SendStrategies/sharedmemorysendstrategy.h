#ifndef SHAREDMEMORYSENDSTRATEGY_H
#define SHAREDMEMORYSENDSTRATEGY_H

#include <Utilities/SendStrategy.h>

#include <QSharedMemory>
#include <QSystemSemaphore>

const QString SEMAPHORE_NAME_WRITE = "SemaphoreNameWrite";
const QString SEMAPHORE_NAME_READ = "SemaphoreNameRead";
const QString SHARED_MEMORY_NAME = "SharedMemoryName";

class SharedMemorySendStrategy : public SendStrategy
{
private:
    QSharedMemory* sharedMemory;
    QSystemSemaphore* freeToWrite;
    QSystemSemaphore* freeToRead;
public:
    SharedMemorySendStrategy();
    ~SharedMemorySendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // SHAREDMEMORYSENDSTRATEGY_H
