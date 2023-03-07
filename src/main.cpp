#include <iostream>
#include <vector>

#include "glad/glad.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "glfw/glfw3.h"

#ifdef APIENTRY
#undef APIENTRY
#endif

#include "glm/glm.hpp"

#include "stb_image.h"

#include "spdlog/spdlog.h"

#include "ShaderProgram.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Structures.h"
#include "Texture.h"
#include "Mesh.h"
#include "Renderer.h"


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

    GLFWwindow *window = glfwCreateWindow(800, 600, "Brisk", NULL, NULL);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPosCallback(window, mouse_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    const char* glsl_version = "#version 130";
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
   

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
    Texture texture("../../assets/container.jpg");
    VertexBuffer vertexBuffer(vertices);
    IndexBuffer indexBuffer(indices);
    Renderer renderer;


    VertexBufferLayout layout;
    layout.push<float>(3);
    layout.push<float>(2);
    vertexArray.addBuffer(vertexBuffer, layout);

    
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)0);
    // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void *)(sizeof(float) * 3));
    // glEnableVertexAttribArray(0);
    // glEnableVertexAttribArray(1);
    

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

    // Start the Dear ImGui frame

    bool showWindow = true;
    while (!glfwWindowShouldClose(window))
    {    
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(&showWindow);
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwSwapBuffers(window);
        view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);

        ImGui::Render();
        renderer.clear();

        shaderProgram.use();
        shaderProgram.UploadUniformMat4("model", model);
        shaderProgram.UploadUniformMat4("view", view);
        shaderProgram.UploadUniformMat4("projection", projection);

        float timeValue = (float)glfwGetTime();
        float normalized = (sin(timeValue)) + 0.5f;
        float normalized2 = (sin(timeValue * 5)) + 0.5f;
        shaderProgram.uploadUniform4f("color", glm::vec4(normalized2, .9, normalized, 1));
        renderer.draw(vertexArray, indexBuffer, shaderProgram);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMove)
    {
        lastX = (float)xpos;
        lastY = (float)ypos;
    }

    float xoffset = (float)xpos - lastX;
    float yoffset = lastY - (float)ypos;
    lastX = (float)xpos;
    lastY = (float)ypos;

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