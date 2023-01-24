#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "stb_image.h"

#include "FileHandler.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Vertex.h"

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

    unsigned int vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    VertexBuffer vertexBuffer(vertices);
    IndexBuffer indexBuffer(indices);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("../../assets/container.jpg", &width, &height, &nrChannels, 0);

    if (!data)
        std::cout << "Failed to load texture" << std::endl;

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

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
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(vertexArray);

        float timeValue = glfwGetTime();
        float normalized = (sin(timeValue)) + 0.5f;
        float normalized2 = (sin(timeValue * 2)) + 0.5f;

        shaderProgram.uploadUniform4f("color", glm::vec4(normalized2, .4, normalized, 1));
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
