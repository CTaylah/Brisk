#include "Renderer.h"

namespace Brisk {

    void Renderer::draw(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const 
    {
        sh.use();
        va.bind();
        ib.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    }

    void Renderer::clear() const
    {
        
        glClearColor(0.5f, 0.1f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

    }

}