#pragma once

#include <vector>

#include "glad/glad.h"


namespace Brisk{
    class IndexBuffer
    {
    public:
        IndexBuffer(std::vector<unsigned int>& data);
        IndexBuffer(unsigned int* data, unsigned int size);
        IndexBuffer() = default;
        unsigned int getCount();
        void bind();
        void unbind();
        ~IndexBuffer();

    private:
        unsigned int m_bufferID = 0;
        unsigned int m_count;
    };
}