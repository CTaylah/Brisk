#include "Renderer/IndexBuffer.h"
#include "Renderer/VertexArray.h"

#include "glm/glm.hpp"


namespace Brisk{

    struct RenderData{

        RenderData();
        RenderData(VertexArray* vertexArray) : vertexArray(vertexArray) {};
        
        bool isIndexed;
        VertexArray* vertexArray;
        IndexBuffer* indexCount;
    };

    class WorldObject{
        public:
            WorldObject();
            WorldObject(glm::vec3 position);

        protected:
            glm::vec3 p_position;
            glm::vec3 p_rotation;
            glm::vec3 p_scale;

            glm::mat4 p_tranform;
    };
}
