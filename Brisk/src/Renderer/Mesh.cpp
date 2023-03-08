#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices)
{
    m_drawBuffer = {new VertexBuffer(vertices), new IndexBuffer(indices)};
}

Mesh::~Mesh()
{
    delete(m_drawBuffer.ibo);
    delete(m_drawBuffer.vbo);
}