#include "Renderer.h"

namespace Brisk {

    void Renderer::drawIndexed(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const 
    {
        sh.use();
        va.bind();
        ib.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    }

    void Renderer::drawTriangles(VertexArray& va, ShaderProgram& sh, unsigned int vertexCount) const
    {
        sh.use();
        va.bind();
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }

    void Renderer::clear() const
    {
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }

    void Renderer::setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r,g,b,a);
    }

}