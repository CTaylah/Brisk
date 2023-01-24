#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices)
{
    glGenBuffers(1, &m_bufferID);
    bind();
    std::cout << sizeof(vertices) << std::endl;
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
}

void VertexBuffer::subData(std::vector<Vertex> newVertices)
{
    bind();
    // Need to add something about buffer size not being greater than current buffer size
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * newVertices.size(), &newVertices[0]);
}

void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}
void VertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_bufferID);
}