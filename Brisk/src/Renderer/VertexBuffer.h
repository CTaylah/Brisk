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

        VertexBuffer(float* vertices);

        VertexBuffer(std::vector<float> vertices);

        VertexBuffer() = default;

        void subData(std::vector<Vertex> newVertices);

        unsigned int getBufferSizef() const { return m_bufferSizef; }

        void bind();
        void unbind();

        ~VertexBuffer();


    private:
        unsigned int m_bufferID = 0;
        //Total number of lfoats in the buffer. Later used to calculate
        //  the number of vertices
        unsigned int m_bufferSizef;
    };


}