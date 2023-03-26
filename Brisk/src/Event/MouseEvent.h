#pragma once

#include "Event.h"

namespace Brisk{

    class MouseEvent : public Event
    {

    public:
        MouseEvent(double xpos, double ypos) { m_xpos = xpos; m_ypos = ypos; m_type = BR_MOUSE_MOVE;}
        double getXPosition() { return m_xpos; }
        double getYPosition() { return m_ypos; }
    private:
        double m_xpos, m_ypos;

    };

}