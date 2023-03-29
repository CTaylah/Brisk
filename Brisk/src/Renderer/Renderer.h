#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"

namespace Brisk {

    class Renderer
    {
    public:
        void drawIndexed(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const;
        void drawTriangles(VertexArray& va, ShaderProgram& sh, unsigned int verticeCount) const;

        void clear() const;
        void setClearColor(float r, float g, float b, float a);
    private:
    };

}