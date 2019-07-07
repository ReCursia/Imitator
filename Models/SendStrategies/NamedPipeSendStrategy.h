#ifndef NAMEDPIPESENDSTRATEGY_H
#define NAMEDPIPESENDSTRATEGY_H

#include <Utilities/SendStrategy.h>

#include <QDataStream>
#include <QLocalServer>
#include <QLocalSocket>


class NamedPipeSendStrategy : public QObject, public SendStrategy
{
private:
    Q_OBJECT
    QLocalServer* server;
    QLocalSocket* clientConnection;
    //CLIENT
    //QLocalSocket* exampleClient;
private slots:
    //void readData();
public:
    NamedPipeSendStrategy();
    ~NamedPipeSendStrategy();
    void sendDatagramData(QByteArray array);
};

#endif // NAMEDPIPESENDSTRATEGY_H
