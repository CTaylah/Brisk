#include "Event.h"


namespace Brisk
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height) : m_width(width), m_height(height) { m_type = BR_WINDOW_RESIZE; }
        unsigned int getWidth() { return m_width; }
        unsigned int getHeight() { return m_height; }

    private:
        int m_width, m_height;
    };
}
