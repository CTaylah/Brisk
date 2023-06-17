#include "Renderer/Renderer.h"

#include "glm/glm.hpp"

#include <memory>


namespace Brisk{

    class Entity{
        public:
            Entity(RenderData* renderData);
            
            void setPosition(glm::vec3 position);
            void setRotation(glm::vec3 rotation);
            void setScale(glm::vec3 scale);

            glm::vec3 getPosition() const {return p_position;};
            glm::vec3 getRotation() const {return p_rotation;};
            glm::vec3 getScale() const {return p_scale;}
            glm::mat4 getTransform() const {return p_tranform;}

            void draw(const Renderer& renderer, ShaderProgram& shaderProgram);

        protected:
            glm::vec3 p_position;
            glm::vec3 p_rotation;
            glm::vec3 p_scale;

            glm::mat4 p_tranform;

            RenderData* p_renderData;
    };
}
