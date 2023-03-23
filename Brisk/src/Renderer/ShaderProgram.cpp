#include "ShaderProgram.h"
#include "Core/Log.h"

namespace Brisk{

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
            Log::getCoreLogger()->error("ShadedProgram: Error, Vertex Shader Compilation failed");
            std::string log;
            for (int i = 0; i < 512; i++)
            {
                log = log + infoLog[i];
            }
            Log::getCoreLogger()->info(log);
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
            Log::getCoreLogger()->error("ShaderProgram: Error, Fragment Shader Compilation failed");
        }

        // Attach shaders to shader program
        glAttachShader(m_programID, vertexShaderID);
        glAttachShader(m_programID, fragmentShaderID);

        // TODO: Error  logging
        glLinkProgram(m_programID);
        glGetProgramiv(m_programID, GL_LINK_STATUS, &success);

        glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
            Log::getCoreLogger()->error("ShaderProgram: Error, Shader Program Linking failed");
        }

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
    void ShaderProgram::uploadUniformf(const std::string &name, float value)
    {
        int location = glGetUniformLocation(m_programID, name.c_str());
        glUniform1f(location, value);
    }
    void ShaderProgram::uploadUniform2f(const std::string &name, glm::vec2 &value)
    {
        int location = glGetUniformLocation(m_programID, name.c_str());
        glUniform2f(location, value.x, value.y);
    }
    void ShaderProgram::uploadUniform3f(const std::string &name, glm::vec3 &value)
    {
        int location = glGetUniformLocation(m_programID, name.c_str());
        glUniform3f(location, value.x, value.y, value.z);
    }
    void ShaderProgram::uploadUniform4f(const std::string &name, glm::vec4 &value)
    {
        int location = glGetUniformLocation(m_programID, name.c_str());
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }

    void ShaderProgram::uploadUniformInt(const std::string &name, int value)
    {
        int location = glGetUniformLocation(m_programID, name.c_str());
        glUniform1i(location, value);
    }

    void ShaderProgram::UploadUniformMat3(const std::string &name, const glm::mat3 &matrix)
    {
        GLint location = glGetUniformLocation(m_programID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void ShaderProgram::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
    {
        GLint location = glGetUniformLocation(m_programID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

}