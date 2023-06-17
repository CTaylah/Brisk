#include "Renderer.h"

namespace Brisk {

    void Renderer::drawIndexed(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const 
    {
        checkCamera();
        sh.use();
        sh.uploadUniformMat4("projection", m_camera->getProjection());
        sh.uploadUniformMat4("view", m_camera->getView());
        sh.uploadUniform3f("cameraPos", m_camera->getCameraPosition());
        
        va.bind();
        ib.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    }

    void Renderer::drawTriangles(VertexArray& va, ShaderProgram& sh, unsigned int vertexCount) const
    {
        checkCamera();
        sh.use();
        sh.uploadUniformMat4("projection", m_camera->getProjection());
        sh.uploadUniformMat4("view", m_camera->getView());
        sh.uploadUniform3f("cameraPos", m_camera->getCameraPosition());

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

    void Renderer::setClearColor(glm::vec4 colorRGBA)
    {
        glClearColor(colorRGBA.r, colorRGBA.g, colorRGBA.b, colorRGBA.a);
    }
    
    void Renderer::checkCamera() const
    {
        if(m_camera == nullptr)
            Log::error("No camera set in Renderer");
    }


}