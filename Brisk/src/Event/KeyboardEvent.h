#pragma once

#include "Event.h"

namespace Brisk{
    
    class KeyboardEvent : public Event{

    public: 

        KeyboardEvent(int key) {m_key = key; m_type = BR_KEY_PRESSED;}
        
        int getKey() {return m_key;}

    private:
            int m_key;

        
    };

}