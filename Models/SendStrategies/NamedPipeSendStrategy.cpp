#include "NamedPipeSendStrategy.h"

#include <Exceptions/senderror.h>

NamedPipeSendStrategy::NamedPipeSendStrategy()
{
    server = new QLocalServer();
    server->listen(PIPE_NAME);
}

NamedPipeSendStrategy::~NamedPipeSendStrategy()
{
    delete server;
    delete clientConnection;
}

void NamedPipeSendStrategy::sendDatagramData(QByteArray array)
{
    if(server->hasPendingConnections()){
        clientConnection = server->nextPendingConnection();
        clientConnection->write(array);
        clientConnection->flush();
        clientConnection->disconnectFromServer();
    }
    else{
        //TODO разобраться с исключениями
        //throw new SendError(NO_CONNECTIONS);
    }
}
