#include "glad/glad.h"
#include <iostream>
#include <vector>
#include "Vertex.h"

class VertexBuffer
{
public:
    VertexBuffer(std::vector<Vertex> vertices);
    void subData();
    void bind();
    void unbind();
    ~VertexBuffer();

private:
    unsigned int m_bufferID = 0;
    std::vector<Vertex> m_vertices;
};