#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Util/FileHandler.h"

namespace Brisk{

    class ShaderProgram
    {
    public:
        // For now, a ShaderProgram can only be made of a single vertex shader and a single fragment shader
        // in the future, this functionality will hopefully be improved 
        ShaderProgram(const std::string vertexShaderFilePath, const std::string fragmentShaderFilePath);
        void use();

        ~ShaderProgram();
        //Upload a float
        void uploadUniformf(const std::string &name, float value);
        //Upload a vec2
        void uploadUniform2f(const std::string &name, glm::vec2 &value);
        //Upload a vec3
        void uploadUniform3f(const std::string &name, glm::vec3 &value);
        //Upload a vec5
        void uploadUniform4f(const std::string &name, glm::vec4 &value);
        //Upload an Integer
        void uploadUniformInt(const std::string &name, int value);
        //Upload a 4x4 matrix
        void uploadUniformMat4(const std::string &name, const glm::mat4 &matrix);
        //Upload a 3x3 matrix
        void uploadUniformMat3(const std::string &name, const glm::mat3 &matrix);

    private:
        unsigned int m_programID;
        std::string m_vertexShaderSource, m_fragmentShaderSource;
        void compileShaders();
    };

}