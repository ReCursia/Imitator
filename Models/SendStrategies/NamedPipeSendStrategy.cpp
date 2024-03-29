#include "NamedPipeSendStrategy.h"

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
}
