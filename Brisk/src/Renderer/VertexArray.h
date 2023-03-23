#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <iostream>


namespace Brisk{
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
}