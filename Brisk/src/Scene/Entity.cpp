#include "Entity.h"

namespace Brisk{
    
    void Entity::draw(const Renderer& renderer, ShaderProgram& shaderProgram)
    {
        shaderProgram.use();
        shaderProgram.uploadUniformMat4("transform", p_tranform);

        if(p_renderData->isIndexed)
        {
            renderer.drawIndexed(*p_renderData->vertexArray, *p_renderData->indexBuffer, shaderProgram);
        }
        else
        {
            renderer.drawTriangles(*p_renderData->vertexArray, shaderProgram, p_renderData->vertexArray->getVertexCount());
        }
    }

    void Entity::setPosition(glm::vec3 position)
    {
        p_position = position;
        p_tranform = glm::translate(glm::mat4(1.0f), p_position);
    }

    void Entity::setRotation(glm::vec3 rotation)
    {
        p_rotation = rotation;
        p_tranform = glm::rotate(p_tranform, glm::radians(p_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        p_tranform = glm::rotate(p_tranform, glm::radians(p_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        p_tranform = glm::rotate(p_tranform, glm::radians(p_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    }

    void Entity::setScale(glm::vec3 scale)
    {
        p_scale = scale;
        p_tranform = glm::scale(p_tranform, p_scale);
    }

}