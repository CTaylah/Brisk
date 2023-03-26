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

        Brisk::Log::warn(a);

        Brisk::EventHandler::getEventList()->push_back(Brisk::KeyboardEvent(5));


        Brisk::PerspectiveCamera camera(1280.0f, 720.0f);
        while(!glfwWindowShouldClose(m_window->getGlfwWindow()))
        { 


            m_window->onUpdate();    
            m_renderer.clear();

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

            glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
//            glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.1f, 100.0f);

            shaderProgram.UploadUniformMat4("model", model);
            shaderProgram.UploadUniformMat4("projection_view", camera.getProjectionView());


            m_renderer.draw(vertexArray, indexBuffer, shaderProgram);

            

            glBindVertexArray(0);
            if(Brisk::EventHandler::getEventList()->size() == 0)
                continue;


            if(!glfwWindowShouldClose(m_window->getGlfwWindow()))
            {
                Brisk::EventHandler::getEventList()->clear();
                Brisk::EventHandler::getEventList()->shrink_to_fit();
            }
        } 
    }

};

int main()
{
    Brisk::Log::init();
    Brisk::EventHandler::init();
    Brisk::WindowProperties props;
    Sandbox* sandbox = new Sandbox();
    sandbox->run();
    int c = Brisk::EventHandler::getEventList()->at(0).getEventType();
    delete(sandbox);
    return 0;
