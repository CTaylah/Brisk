#pragma once

#include <iostream>
#include <string>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "FileHandler.h"

class ShaderProgram
{
public:
    // For now, a ShaderProgram can only be made of a vertex shader and a fragment shader
    // Look in the future, this functionality will probably be altered
    ShaderProgram(const std::string vertexShaderFilePath, const std::string fragmentShaderFilePath);
    void use();

    ~ShaderProgram();
    void uploadUniformf(const std::string &name, float value);
    void uploadUniform2f(const std::string &name, glm::vec2 &value);
    void uploadUniform3f(const std::string &name, glm::vec3 &value);
    void uploadUniform4f(const std::string &name, glm::vec4 &value);

    void uploadUniformInt(const std::string &name, int value);

    void ShaderProgram::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix);
    void ShaderProgram::UploadUniformMat3(const std::string &name, const glm::mat3 &matrix);

private:
    unsigned int m_programID;
    std::string m_vertexShaderSource, m_fragmentShaderSource;
    void compileShaders();
};