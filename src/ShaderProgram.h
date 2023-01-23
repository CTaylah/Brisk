#include <iostream>
#include <string>

#include "glad/glad.h"

#include "FileHandler.h"

class ShaderProgram
{
public:
    // For now, a ShaderProgram can only be made of a vertex shader and a fragment shader
    // Look in the future, this functionality will probably be altered
    ShaderProgram(const std::string vertexShaderFilePath, const std::string fragmentShaderFilePath);
    void use();

    ~ShaderProgram();

private:
    unsigned int m_programID;
    std::string m_vertexShaderSource, m_fragmentShaderSource;
    void compileShaders();
};