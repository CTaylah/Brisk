#pragma once

#include <vector>
#include <memory>

namespace Brisk 
{
    enum EventType{
        BR_KEY_PRESSED, BR_KEY_RELEASED,

        BR_MOUSE_MOVE, BR,MOUSE_CLICK
    };   

    class Event{

        public:

            EventType getEventType() { return m_type; }

            virtual ~Event()
            { }

        protected:
            EventType m_type;
    };

    class EventHandler
    {
        public:

            static void init();

            static void pushBack();
            static void pop();

            static std::shared_ptr<std::vector<Event>>& getEventList() {return s_eventList;}

        private:
            static std::shared_ptr<std::vector<Event>> s_eventList;

    };

} 


