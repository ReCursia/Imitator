#include "NamedPipeSendStrategy.h"

#include <Exceptions/senderror.h>

NamedPipeSendStrategy::NamedPipeSendStrategy()
{
    server = new QLocalServer();
    server->listen("EXAMPLE");
    //EXAMPLE CLIENT
    /*
    exampleClient = new QLocalSocket();
    exampleClient->connectToServer("EXAMPLE");
    connect(exampleClient,SIGNAL(readyRead()),this,SLOT(readData()));
    */
}

NamedPipeSendStrategy::~NamedPipeSendStrategy()
{
    //server->close();
    delete server;
}

void NamedPipeSendStrategy::sendDatagramData(QByteArray array)
{
    if(server->hasPendingConnections()){
        clientConnection = server->nextPendingConnection();
        clientConnection->write(array);
        clientConnection->flush();
        //clientConnection->disconnectFromServer();
    }
    else{
        throw new SendError();
    }
}

/*
void NamedPipeSendStrategy::readData()
{
    QString data = exampleClient->readAll();
    qDebug() << data;
    exampleClient->abort();
    exampleClient->connectToServer("EXAMPLE");
}
*/
