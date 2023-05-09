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
        const std::string lightShaderSource = pathToShaders + "lightsource.frag";

       
        // Vertex vert1;
        // vert1.position = glm::vec3(0.5f, 0.5f, 0.0f);
        // vert1.textureCoordinates = glm::vec2(1.0f, 1.0f);

        // Vertex vert2;
        // vert2.position = glm::vec3(0.5f, -0.5f, 0.0f);
        // vert2.textureCoordinates = glm::vec2(1.0f, 0.0f);

        // Vertex vert3;
        // vert3.position = glm::vec3(-0.5f, -0.5f, 0.0f);
        // vert3.textureCoordinates = glm::vec2(0.0f, 0.0f);

        // Vertex vert4;
        // vert4.position = glm::vec3(-0.5f, 0.5f, 0.0f);
        // vert4.textureCoordinates = glm::vec2(0.0f, 1.0f); 

        // std::vector<Vertex> vertices = {vert1, vert2, vert3, vert4};


    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
    glm::vec3 result = lightColor * toyColor;

std::vector<float> vertices = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};
       std::vector<unsigned int> indices = { 0, 1, 3, 1, 2, 3};

        Brisk::VertexArray vertexArray;
        Brisk::VertexBuffer vertexBuffer(vertices);
        Brisk::VertexBufferLayout bufferLayout;

        bufferLayout.push(3, GL_FLOAT);
        bufferLayout.push(3, GL_FLOAT);

        Brisk::VertexArray lightCubeArray;

        //Brisk::IndexBuffer indexBuffer(indices);

        vertexArray.addBuffer(vertexBuffer,bufferLayout);
        lightCubeArray.addBuffer(vertexBuffer, bufferLayout);


        Brisk::ShaderProgram shaderProgram(vertexShaderSource, fragmentShaderSource);

        m_window->setCursorVisibility(false);
        
        Brisk::PerspectiveCameraController camController(1280, 720);
        camController.setCameraSpeed(2.6f);
        camController.setSensitivty(.05);

        auto eventList = Brisk::EventHandler::getEventList();


        glm::mat4 model(1.0f);
        glm::vec3 cubPos(1.0f, 4.0f, -3.0f);
        model = glm::translate(model,cubPos);
        
        glm::mat4 lightModel(1.0f); 
        glm::vec3 lightPosition(0.7f, 1.2f, -2.0f);
        lightModel = glm::translate(lightModel, lightPosition);

        Brisk::ShaderProgram lightProgram(vertexShaderSource, lightShaderSource);

        double lastFrame = 0.0;

        glm::mat4 transform2 = glm::mat4(1.0f);
        
        m_renderer.setClearColor(0.1f, 0.2f, 0.1f, 1.0f);
        while(!glfwWindowShouldClose(m_window->getGlfwWindow()))
        {
            double currentFrame = glfwGetTime();
            double deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;            

            m_window->onUpdate();

            if(glfwWindowShouldClose(m_window->getGlfwWindow()))
                break;


            if(Brisk::Input::isKeyPressed(BRISK_KEY_W))
            {
                camController.moveCamera(Brisk::BR_FORWARD, deltaTime);
            }

            if(Brisk::Input::isKeyPressed(BRISK_KEY_A))
            {
                camController.moveCamera(Brisk::BR_LEFT, deltaTime);
            }
            if(Brisk::Input::isKeyPressed(BRISK_KEY_S))
            {
                camController.moveCamera(Brisk::BR_BACKWARD, deltaTime);
            }

            if(Brisk::Input::isKeyPressed(BRISK_KEY_D))
            {
                camController.moveCamera(Brisk::BR_RIGHT, deltaTime);
            }

            if(Brisk::Input::isKeyPressed(BRISK_KEY_ESCAPE))
            {
                exit(0);
            }
                       
                       

            for(int i = 0; i < eventList->size(); i++)
            {
                Brisk::Event* event = eventList->at(i);
                if(event->getEventType() == Brisk::BR_MOUSE_MOVE)
                {
                    Brisk::MouseEvent* mouseEvent = static_cast<Brisk::MouseEvent*>(event);
                    double xpos = mouseEvent->getXPosition();
                    double ypos = mouseEvent->getYPosition();
                    mouseEvent->setHandled(true);
                    camController.getCamera()->lookAt(xpos, ypos);
                }

                
            }             

            
            m_renderer.clear();

            glm::mat4 transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(sin(glfwGetTime() * 3), cos(glfwGetTime()) * 3, -1.0f));

            shaderProgram.use();
            shaderProgram.uploadUniformMat4("transform", transform);
            shaderProgram.uploadUniformMat4("model", model);
            shaderProgram.uploadUniformMat4("view", camController.getCamera()->getView());
            shaderProgram.uploadUniformMat4("projection", camController.getCamera()->getProjection());
            shaderProgram.uploadUniform3f("cameraPos", camController.getCamera()->getCameraPosition());
            shaderProgram.uploadUniform3f("lightColor", lightColor);
            shaderProgram.uploadUniform3f("objectColor", toyColor);
            shaderProgram.uploadUniform3f("lightPosition", lightPosition);
            

            lightProgram.use();
            lightProgram.uploadUniformMat4("transform", transform2);
            lightProgram.uploadUniformMat4("model", lightModel);
            lightProgram.uploadUniformMat4("view", camController.getCamera()->getView());
            lightProgram.uploadUniformMat4("projection", camController.getCamera()->getProjection());
            lightProgram.uploadUniform3f("lightColor", lightColor);

//            m_renderer.drawIndexed(vertexArray, indexBuffer, shaderProgram);
            m_renderer.drawTriangles(vertexArray, shaderProgram, 36);
            m_renderer.drawTriangles(lightCubeArray, lightProgram, 36);

            glBindVertexArray(0);
            if(Brisk::EventHandler::getEventList()->size() == 0)
                continue;


            Brisk::EventHandler::getEventList()->clear();
            Brisk::EventHandler::getEventList()->shrink_to_fit();
            
        } 
    }

};

int main()
{
    Brisk::Log::init();
    Brisk::EventHandler::init();
    
    Sandbox* sandbox = new Sandbox();
    sandbox->run();
    delete(sandbox);
    return 0;
}