#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "stb_image.h"

#include "FileHandler.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Structures.h"
#include "Texture.h"

bool initializeGlfw();

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
    vert1.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vert1.textureCoordinates = glm::vec2(1.0f, 1.0f);

    Vertex vert2;
    vert2.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vert2.textureCoordinates = glm::vec2(1.0f, 0.0f);

    Vertex vert3;
    vert3.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vert3.textureCoordinates = glm::vec2(0.0f, 0.0f);

    Vertex vert4;
    vert4.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vert4.textureCoordinates = glm::vec2(0.0f, 1.0f);

    std::vector<Vertex> vertices = {vert1, vert2, vert3, vert4};

    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3};

    VertexArray vertexArray;

    VertexBuffer vertexBuffer(vertices);
    IndexBuffer indexBuffer(indices);

    Texture texture("../../assets/container.jpg");

    vertexArray.unbind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)(sizeof(float) * 3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    float red[] = {1.0f, 0.0f, 0.0f, 1.0f};

    shaderProgram.uploadUniformInt("ourTexture", 0);
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);

        shaderProgram.use();
        // glBindTexture(GL_TEXTURE_2D, texture);
        // texture.bind();

        vertexArray.bind();
        float timeValue = glfwGetTime();
        float normalized = (sin(timeValue)) + 0.5f;
        float normalized2 = (sin(timeValue * 5)) + 0.5f;

        shaderProgram.uploadUniform4f("color", glm::vec4(normalized2, .9, normalized, 1));
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
