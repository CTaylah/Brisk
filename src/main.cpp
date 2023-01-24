#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "FileHandler.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "Vertex.h"

bool initializeGlfw();

unsigned int createShaderProgram(std::string vertexShader, std::string fragmentShader);

int main()

{
    std::cout << "running" << std::endl;

    const std::string pathToShaders = "..\\..\\shaders\\";
    FileHandler fileHandler;

    initializeGlfw();

    GLFWwindow *window = glfwCreateWindow(800, 600, "Learn SHit", NULL, NULL);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    std::string vertexShaderFile = (pathToShaders + "vertex.vert");
    std::string fragmentShaderFile = (pathToShaders + "fragment.frag");
    // unsigned int shaderProgramID = createShaderProgram(vertexShaderSource, fragmentShaderSource);

    ShaderProgram shaderProgram(vertexShaderFile, fragmentShaderFile);

    float verticess[] = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };

    Vertex vert1;
    vert1.Position = glm::vec3(0.5f, 0.5f, 0.0f);

    Vertex vert2;
    vert2.Position = glm::vec3(0.5f, -0.5f, 0.0f);

    Vertex vert3;
    vert3.Position = glm::vec3(-0.5f, -0.5f, 0.0f);

    Vertex vert4;
    vert4.Position = glm::vec3(-0.5f, 0.5f, 0.0f);

    std::vector<Vertex> vertices = {vert1, vert2, vert3, vert4};

    // for (int i = 0; i < 12; i++)
    // {

    //     std::cout << p[i] << std::endl;
    // }

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3};

    unsigned int vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    // unsigned int bufferID;
    // glGenBuffers(1, &bufferID);
    // glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), p, GL_STATIC_DRAW);

    VertexBuffer vertexBuffer(vertices);

    unsigned int indexBufferID;
    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void *)0);
    glEnableVertexAttribArray(0);

    float red[] = {1.0f, 0.0f, 0.0f, 1.0f};

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);

        shaderProgram.use();
        glBindVertexArray(vertexArray);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwPollEvents();
    }

    return 0;
}

bool initializeGlfw()
{
    // Add error handling
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return 0;
}

unsigned int createShaderProgram(std::string vertexShader, std::string fragmentShader)
{
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    const char *vertc_str = vertexShader.c_str();

    glShaderSource(vertexShaderID, 1, &vertc_str, NULL);
    glCompileShader(vertexShaderID);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        std::cout << "Error vertex shader compilation failed" << std::endl;
    }

    const char *fragc_str = fragmentShader.c_str();
    glShaderSource(fragmentShaderID, 1, &fragc_str, NULL);
    glCompileShader(fragmentShaderID);

    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
        std::cout << "Error fragment shader compilation failed" << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragmentShaderID);
    glLinkProgram(shaderProgram);

    // Before sure to delete shaders after you've linked them to the program
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return shaderProgram;
}