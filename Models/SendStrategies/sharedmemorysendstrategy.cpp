#include "SharedMemorySendStrategy.h"

#include <QBuffer>

SharedMemorySendStrategy::SharedMemorySendStrategy()
{
    sharedMemory = new QSharedMemory();
    sharedMemory->setKey(SHARED_MEMORY_NAME);
    freeToWrite = new QSystemSemaphore(SEMAPHORE_NAME_WRITE,1,QSystemSemaphore::Create);
    freeToRead = new QSystemSemaphore(SEMAPHORE_NAME_READ,0,QSystemSemaphore::Create);
}

SharedMemorySendStrategy::~SharedMemorySendStrategy()
{
    delete sharedMemory;
    delete freeToRead;
    delete freeToWrite;
}

void SharedMemorySendStrategy::sendDatagramData(QByteArray array)
{
    freeToWrite->acquire();
    sharedMemory->create(array.size());
    char* to = (char*)sharedMemory->data();
    memcpy(to,array,qMin(sharedMemory->size(),array.size()));
    freeToRead->release(1);
}
