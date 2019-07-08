#ifndef NAMEDPIPESENDSTRATEGY_H
#define NAMEDPIPESENDSTRATEGY_H

#include <Utilities/SendStrategy.h>
#include <QDataStream>
#include <QLocalServer>
#include <QLocalSocket>

const QString PIPE_NAME = "PipeName";
const QString NO_CONNECTIONS = "Нет соединения с клиентом!";

class NamedPipeSendStrategy : public QObject, public SendStrategy
{
private:
    Q_OBJECT
    QLocalServer* server;
    QLocalSocket* clientConnection;
public:
    NamedPipeSendStrategy();
    ~NamedPipeSendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // NAMEDPIPESENDSTRATEGY_H
