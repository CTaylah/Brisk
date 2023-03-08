#pragma once

#include <iostream>
#include "glad/glad.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class VertexArray
{
public:
    VertexArray();
    void bind();
    void unbind();
    unsigned int getID();

    void addBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout& bufferLayout);

    ~VertexArray();

private:
    unsigned int m_vertexArrayID;
};