#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string vertexShaderFilePath, const std::string fragmentShaderFilePath)
{
    m_programID = glCreateProgram();
    FileHandler fileHandler;

    m_vertexShaderSource = fileHandler.fileToString(vertexShaderFilePath);
    m_fragmentShaderSource = fileHandler.fileToString(fragmentShaderFilePath);
    compileShaders();
}

void ShaderProgram::compileShaders()
{
    int success;
    char infoLog[512];

    // Compile the vertex shader*
    const char *vertc_str = m_vertexShaderSource.c_str();
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertc_str, NULL);
    glCompileShader(vertexShaderID);

    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        std::cout << "Error: Vertex Shader Compilation failed" << std::endl;
        std::string log;
        for (int i = 0; i < 512; i++)
        {
            log = log + infoLog[i];
        }
        std::cout << log << std::endl;
    }

    // Compile the fragment shader
    const char *fragc_str = m_fragmentShaderSource.c_str();
    unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fragc_str, NULL);
    glCompileShader(fragmentShaderID);

    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
        std::cout << "Error: Fragment Shader Compilation failed" << std::endl;
    }

    // Attach shaders to shader program
    glAttachShader(m_programID, vertexShaderID);
    glAttachShader(m_programID, fragmentShaderID);

    // TODO: Error  logging
    glLinkProgram(m_programID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void ShaderProgram::use()
{
    glUseProgram(m_programID);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_programID);
}