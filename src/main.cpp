#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "stb_image.h"

#include "spdlog/spdlog.h"

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Structures.h"
#include "Texture.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float pitch = 0.0f;
float yaw = -90.0f;

float lastX = 400, lastY = 300;
bool firstMove = true;

glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

void processInput(GLFWwindow *window);
bool initializeGlfw();
void mouse_callback(GLFWwindow *window, double xpos, double ypos);

int main()

{
    spdlog::info("Welcome to spdlog!");
    std::cout << "running" << std::endl;

    SPDLOG_TRACE("Some trace message with param {}", 42);

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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);

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

    // vertexArray.unbind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)(sizeof(float) * 3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    //----CAMERA

    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    // Camera direction actually points in the opposite direction of its target
    glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget);

    glm::vec3 up(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

    shaderProgram.uploadUniformInt("ourTexture", 0);

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwSwapBuffers(window);

        glClearColor(0.5f, 0.1f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);

        shaderProgram.use();
        shaderProgram.UploadUniformMat4("model", model);
        shaderProgram.UploadUniformMat4("view", view);
        shaderProgram.UploadUniformMat4("projection", projection);

        vertexArray.bind();
        float timeValue = glfwGetTime();
        float normalized = (sin(timeValue)) + 0.5f;
        float normalized2 = (sin(timeValue * 5)) + 0.5f;

        shaderProgram.uploadUniform4f("color", glm::vec4(normalized2, .9, normalized, 1));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        processInput(window);
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

void processInput(GLFWwindow *window)
{
    const float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPosition += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPosition -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        exit(0);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMove)
    {
        lastX = xpos;
        lastY = ypos;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    firstMove = false;

    const float sensitivity = 0.035f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}