#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(std::vector<unsigned int>& data)
{
    m_count = (unsigned int)data.size();
    glGenBuffers(1, &m_bufferID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * data.size(), &data[0], GL_STATIC_DRAW);
}

void IndexBuffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}

void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::getCount()
{
    return m_count;
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_bufferID);
}