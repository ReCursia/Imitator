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
        qDebug() << "ЕСТЬ!";
        clientConnection = server->nextPendingConnection();
        clientConnection->write(array);
        clientConnection->flush();
        qDebug() << "Отправили!";
        clientConnection->disconnectFromServer();
    }
    else{
        qDebug() << "НЕТ подключений";
        //throw new SendError(NO_CONNECTIONS);
    }
}
