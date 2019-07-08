#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "EventListener.h"



class EventManager
{
private:
    EventListener* listener;
public:
    EventManager();
    ~EventManager();
    void subscribe(EventListener* newListener);
    void notify(QString eventType,QString message);
};

#endif // EVENTMANAGER_H
