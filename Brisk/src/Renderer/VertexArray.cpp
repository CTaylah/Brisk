#include "VertexArray.h"

namespace Brisk{

    VertexArray::VertexArray() : m_vertexCount(0)
    {
        glGenVertexArrays(1, &m_vertexArrayID);
        glBindVertexArray(m_vertexArrayID);
    }

    void VertexArray::bind()
    {
        glBindVertexArray(m_vertexArrayID);
    }

    unsigned int VertexArray::getID()
    {
        return m_vertexArrayID;
    }
    unsigned int VertexArray::getVertexCount()
    {
        return m_vertexCount;
    }
    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::addBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout& bufferLayout)
    {
        bind();
        vertexBuffer.bind();
        const std::vector<VertexBufferElement> elements = bufferLayout.getElements();
        unsigned int offset = 0;
        int totalCount = 0;
        for(unsigned int i = 0; i < elements.size(); i++)
        {
            const auto& element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, element.normalized, bufferLayout.getStride(), (const void*) offset);
            offset += element.count * VertexBufferElement::getSizeOfType(element.type);
            totalCount += element.count;
        }
        m_vertexCount = vertexBuffer.getBufferSizef() / totalCount;
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_vertexArrayID);
    }

}