#include "EventManager.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::subscribe(EventListener *newListener)
{
    listener = newListener;
}

void EventManager::notify(QString eventType, QString message)
{
    listener->update(eventType,message);
}
