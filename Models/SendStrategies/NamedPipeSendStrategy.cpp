#include "NamedPipeSendStrategy.h"

#include <Exceptions/senderror.h>

NamedPipeSendStrategy::NamedPipeSendStrategy()
{
    server = new QLocalServer();
    server->listen(PIPE_NAME);
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
