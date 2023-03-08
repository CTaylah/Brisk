#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"


class Renderer
{
public:
    //void set clear color
    void draw(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const;
    void clear() const;
private:

};