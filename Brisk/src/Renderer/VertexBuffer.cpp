#include "VertexBuffer.h"


namespace Brisk{

    VertexBuffer::VertexBuffer(std::vector<Vertex> vertices)
    {
        glGenBuffers(1, &m_bufferID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
        m_vertexCount = vertices.size();
    }

    VertexBuffer::VertexBuffer(std::vector<float> vertices)
    {
        glGenBuffers(1, &m_bufferID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
        m_vertexCount = vertices.size();
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

}