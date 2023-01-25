#include <iostream>
#include "glad/glad.h"

class VertexArray
{
public:
    VertexArray();
    void bind();
    void unbind();
    ~VertexArray();

private:
    unsigned int m_vertexArrayID;
};