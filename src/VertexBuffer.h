#include "glad/glad.h"
#include <iostream>
#include <vector>

class VertexBuffer
{
public:
    VertexBuffer(std::vector<float> *vertices);
    void subData();
    void bind();
    void unbind();
    ~VertexBuffer();

private:
    unsigned int m_bufferID = 0;
    std::vector<float> *m_vertices;
};