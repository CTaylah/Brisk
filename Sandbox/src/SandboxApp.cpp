#include "Brisk.h"

#include <iostream>

class Sandbox : public Brisk::Application
{
public:
    Sandbox()
    {
        
    }

    ~Sandbox()
    {

    }

    void run()
    {
        const std::string pathToAssets = "../../../assets/";
        const std::string pathToShaders = pathToAssets + "shaders/";

        const std::string vertexShaderSource = pathToShaders + "vertex.vert";
        const std::string fragmentShaderSource = pathToShaders + "fragment.frag";


       
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
        std::vector<unsigned int> indices = { 0, 1, 3, 1, 2, 3};

        Brisk::VertexArray vertexArray;
        Brisk::VertexBuffer vertexBuffer(vertices);
        Brisk::VertexBufferLayout bufferLayout;
        bufferLayout.push(3, GL_FLOAT);
        bufferLayout.push(2, GL_FLOAT);

        Brisk::IndexBuffer indexBuffer(indices);

        vertexArray.addBuffer(vertexBuffer,bufferLayout);

        Brisk::ShaderProgram shaderProgram(vertexShaderSource, fragmentShaderSource);
        int a = 6;

        Brisk::Log::getClientLogger()->info(a);
        std::cout << fragmentShaderSource << std::endl;

        while(!glfwWindowShouldClose(m_window->getGlfwWindow()))
        { 
            m_window->onUpdate();    
            m_renderer.clear();
            m_renderer.draw(vertexArray, indexBuffer, shaderProgram);
            glBindVertexArray(0);
        } 
    }

};

int main()
{
    Brisk::Log::init();
    Brisk::WindowProperties props;
    Sandbox* sandbox = new Sandbox();
    sandbox->run();
    delete(sandbox);
    return 0;
}