#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices)
{
    m_vertices = vertices;
    glGenBuffers(1, &m_bufferID);
    bind();
    std::cout << sizeof(vertices) << std::endl;
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
}

void VertexBuffer::subData()
{
    // TODO: implement lol
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