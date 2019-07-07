#include "SharedMemorySendStrategy.h"

#include <QBuffer>

SharedMemorySendStrategy::SharedMemorySendStrategy()
{
    sharedMemory = new QSharedMemory();
    semaphore = new QSystemSemaphore("EXAMPLE",1,QSystemSemaphore::Create);
}

SharedMemorySendStrategy::~SharedMemorySendStrategy()
{
    delete sharedMemory;
    delete semaphore;
}

void SharedMemorySendStrategy::sendDatagramData(QByteArray array)
{
    sharedMemory->create(array.size());
    sharedMemory->setKey("EXAMPLE");
    semaphore->acquire();
    char* to = (char*)sharedMemory->data();
    memcpy(to,array,qMin(sharedMemory->size(),array.size()));
    semaphore->release(1);
    //getDataExample();
}


/*
void SharedMemorySendStrategy::getDataExample()
{
    QSystemSemaphore* semaphores = new QSystemSemaphore("EXAMPLE",0,QSystemSemaphore::Open);
    semaphores->acquire();
    qDebug() << "Захватили семафор";
    sharedMemory->setKey("EXAMPLE");
    //sharedMemory->attach();
    QBuffer buffer;
    //sharedMemory->lock();
    buffer.setData((char*)sharedMemory->constData(),sharedMemory->size());
    buffer.open(QBuffer::ReadOnly);
    QString data = buffer.readAll();
    qDebug() << "Считываем данные";
    //sharedMemory->unlock();
    //sharedMemory->detach();
    qDebug() << "Данные получены";
    qDebug() << data;
    semaphores->release();
}
*/
