#pragma once

#include "glad/glad.h"

#include <vector>
#include <iostream>

namespace Brisk{
    struct VertexBufferElement
    {
        unsigned int count;
        unsigned int type;
        bool normalized;

        static unsigned int getSizeOfType(unsigned int type)
        {
            switch (type)
            {
                case GL_FLOAT: return 4;
                case GL_UNSIGNED_INT: return 4;
                case GL_UNSIGNED_BYTE: return 1;
            }
            std::cout << "INVALID TYPE: VertexBufferElemet::getSizeOfType" << std::endl;
            return 0;
        }

    };

    class VertexBufferLayout
    {
    private:
        std::vector<VertexBufferElement> m_elements;
        unsigned int m_stride = 0;

    public:
        VertexBufferLayout() = default;

        void push(unsigned int count, GLenum type)
        {
            switch (type)
            {
                case GL_FLOAT: pushFloat(count);
                    break;
                case GL_UNSIGNED_INT: pushUnsignedInt(count);
                    break;
                case GL_UNSIGNED_BYTE: pushByte(count);
                    break;
            }
        }

        void pushFloat(unsigned int count)
        {
            m_elements.push_back({count, GL_FLOAT, false});
            m_stride+= VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
        }

        void pushUnsignedInt(unsigned int count)
        {
            m_elements.push_back( {count, GL_UNSIGNED_INT, false} );
            m_stride+= VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
        }

        void pushByte(unsigned int count)
        {
            m_elements.push_back( {count, GL_UNSIGNED_BYTE, true} );
            m_stride+= VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
        }

        inline const std::vector<VertexBufferElement> getElements() const {return m_elements;}

        inline unsigned int getStride() const {return m_stride;}

    };
}