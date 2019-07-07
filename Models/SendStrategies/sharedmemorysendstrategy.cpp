#include "SharedMemorySendStrategy.h"

#include <QBuffer>

SharedMemorySendStrategy::SharedMemorySendStrategy()
{
    sharedMemory = new QSharedMemory();
    sharedMemory->setKey(SHARED_MEMORY_NAME);
    semaphore = new QSystemSemaphore(SEMAPHORE_NAME,1,QSystemSemaphore::Create);
}

SharedMemorySendStrategy::~SharedMemorySendStrategy()
{
    delete sharedMemory;
    delete semaphore;
}

void SharedMemorySendStrategy::sendDatagramData(QByteArray array)
{
    semaphore->acquire();
    sharedMemory->create(array.size());
    char* to = (char*)sharedMemory->data();
    memcpy(to,array,qMin(sharedMemory->size(),array.size()));
    semaphore->release(1);
}
