#pragma once

#include <vector>
#include "glad/glad.h"
#include <iostream>

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
            case GL_UNSIGNED_BYTE: return 4;
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

    template<typename T>
    void push(unsigned int count)
    {
        static_assert(false);
    }

    template<>
    void push<float>(unsigned int count)
    {
        m_elements.push_back({count, GL_FLOAT, false});
        m_stride+= VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
    }

    template<>
    void push <unsigned int>(unsigned int count)
    {
        m_elements.push_back( {count, GL_UNSIGNED_INT, false} );
        m_stride+= VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
    }

    template<>
    void push <unsigned char>(unsigned int count)
    {
        m_elements.push_back( {count, GL_UNSIGNED_BYTE, true} );
        m_stride+= VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
    }


    inline const std::vector<VertexBufferElement> getElements() const
    {return m_elements;}

    inline unsigned int getStride() const {return m_stride;}

};