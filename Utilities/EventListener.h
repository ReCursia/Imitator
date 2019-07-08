#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <QString>

class EventListener
{
public:
    virtual ~EventListener();
    virtual void update(QString eventType,QString message) = 0;
};

#endif // EVENTLISTENER_H
