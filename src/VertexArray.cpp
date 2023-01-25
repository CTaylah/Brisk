#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_vertexArrayID);
    glBindVertexArray(m_vertexArrayID);
}

void VertexArray::bind()
{
    glBindVertexArray(m_vertexArrayID);
}

void VertexArray::unbind()
{
    glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vertexArrayID);
}