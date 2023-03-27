#pragma once

#include "Vertex.h"

#include "glad/glad.h"

#include <vector>

namespace Brisk{

    class VertexBuffer
    {
    public:
        //Look into static draw
        VertexBuffer(std::vector<Vertex> vertices);

        VertexBuffer(std::vector<float> vertices);

        VertexBuffer() = default;
        void subData(std::vector<Vertex> newVertices);
        void bind();
        void unbind();
        ~VertexBuffer();

    private:
        unsigned int m_bufferID = 0;
    };


}