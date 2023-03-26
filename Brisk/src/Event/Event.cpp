#include "Event.h"

namespace Brisk{

    std::shared_ptr<std::vector<Event>> EventHandler::s_eventList;

    void EventHandler::init()
    {
        std::shared_ptr<std::vector<Event>> myPtr(new std::vector<Event>);
        s_eventList = myPtr;
    }
}