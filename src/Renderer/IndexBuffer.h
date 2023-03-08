#pragma once

#include <iostream>
#include <vector>

#include "glad/glad.h"

class IndexBuffer
{
public:
    IndexBuffer(std::vector<unsigned int>& data);
    IndexBuffer() = default;
    unsigned int getCount();
    void bind();
    void unbind();
    ~IndexBuffer();

private:
    unsigned int m_bufferID = 0;
    unsigned int m_count;
};