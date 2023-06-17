#pragma once

#include "Core/Log.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"

#include "PerspectiveCamera.h"

#include <memory>

namespace Brisk {

    struct RenderData{

        RenderData(std::shared_ptr<VertexArray> vertexArray, bool indexed) : vertexArray(vertexArray), isIndexed(indexed) {};
        //std optional? 
        bool isIndexed;
        std::shared_ptr<VertexArray> vertexArray;
        IndexBuffer* indexBuffer;
    };


    class Renderer
    {
    public:
        Renderer(PerspectiveCamera* camera) : m_camera(camera) {};
        void drawIndexed(VertexArray& va, IndexBuffer& ib, ShaderProgram& sh) const;
        void drawTriangles(VertexArray& va, ShaderProgram& sh, unsigned int verticeCount) const;
        void draw(RenderData& renderData, ShaderProgram& sh) const;

        void clear() const;

        void setClearColor(float r, float g, float b, float a);
        void setClearColor(glm::vec4 colorRGBA);
        void setCamera(PerspectiveCamera* camera) {m_camera = camera;}

    private:
        PerspectiveCamera* m_camera;

        void checkCamera() const;
    };

}