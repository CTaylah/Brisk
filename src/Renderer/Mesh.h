#pragma once

#include "Structures.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <vector>

#include "spdlog/spdlog.h"

struct DrawBuffer
{
    VertexBuffer* vbo;
    IndexBuffer* ibo;
};

class Mesh
{
public:
    Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
    ~Mesh();
    inline DrawBuffer& getDrawBuffer() {return m_drawBuffer;}
private:
    DrawBuffer m_drawBuffer;    
    
};