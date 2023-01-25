#pragma once

#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "Structures.h"

class VertexBuffer
{
public:
    VertexBuffer(std::vector<Vertex> vertices);
    void subData(std::vector<Vertex> newVertices);
    void bind();
    void unbind();
    ~VertexBuffer();

private:
    unsigned int m_bufferID = 0;
};