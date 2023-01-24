#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "FileHandler.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Vertex.h"

bool initializeGlfw();

unsigned int createShaderProgram(std::string vertexShader, std::string fragmentShader);

int main()

{
    std::cout << "running" << std::endl;

    const std::string pathToShaders = "..\\..\\shaders\\";

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

    ShaderProgram shaderProgram(vertexShaderFile, fragmentShaderFile);

    Vertex vert1;
    vert1.Position = glm::vec3(0.5f, 0.5f, 0.0f);

    Vertex vert2;
    vert2.Position = glm::vec3(0.5f, -0.5f, 0.0f);

    Vertex vert3;
    vert3.Position = glm::vec3(-0.5f, -0.5f, 0.0f);

    Vertex vert4;
    vert4.Position = glm::vec3(-0.5f, 0.5f, 0.0f);

    std::vector<Vertex> vertices = {vert1, vert2, vert3, vert4};

    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3};

    unsigned int vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    VertexBuffer vertexBuffer(vertices);
    IndexBuffer indexBuffer(indices);

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
