#include "Renderer/Renderer.h"

#include "glm/glm.hpp"

#include <memory>


namespace Brisk{

    class Entity{
        public:
            Entity(RenderData* renderData) : p_renderData(renderData) { p_tranform = glm::mat4(1.0f); };
            
            void setPosition(glm::vec3 position);
            void setRotation(glm::vec3 rotation);
            void setScale(glm::vec3 scale);

            glm::vec3 getPosition() {return p_position;};
            glm::vec3 getRotation() {return p_rotation;};
            glm::vec3 getScale() {return p_scale;}
            glm::mat4 getTransform() {return p_tranform;}

            void draw(const Renderer& renderer, ShaderProgram& shaderProgram);

        protected:
            glm::vec3 p_position;
            glm::vec3 p_rotation;
            glm::vec3 p_scale;

            glm::mat4 p_tranform;

            RenderData* p_renderData;
    };
}
