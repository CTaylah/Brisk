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
        
        //Brisk::PerspectiveCamera camera(1280.0f, 720.0f);
        Brisk::PerspectiveCameraController camController(1280, 720);
        camController.setCameraSpeed(1.8f);
        double lastFrame = 0.0;
        auto eventList = Brisk::EventHandler::getEventList();


        glm::mat4 model(1.0f);
        glm::vec3 cubPos(1.0f, 4.0f, -3.0f);
        model = glm::translate(model,cubPos);
        
        glm::mat4 lightModel(1.0f); 
        glm::vec3 lightPosition(0.7f, 1.2f, -2.0f);
        lightModel = glm::translate(lightModel, lightPosition);

        Brisk::ShaderProgram lightProgram(vertexShaderSource, lightShaderSource);


        m_renderer.setClearColor(0.1f, 0.2f, 0.1f, 1.0f);
        while(!glfwWindowShouldClose(m_window->getGlfwWindow()))
        {
            double currentFrame = glfwGetTime();
            double deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;            

            m_window->onUpdate();

            if(glfwWindowShouldClose(m_window->getGlfwWindow()))
                break;

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

                if(event->getEventType() == Brisk::BR_KEY_PRESSED)
                {
                    Brisk::KeyboardEvent* keyEvent = static_cast<Brisk::KeyboardEvent*>(event);
                    if(keyEvent->getKey() == GLFW_KEY_ESCAPE)
                    {
                        glfwSetWindowShouldClose(m_window->getGlfwWindow(), true);
                        exit(0);
                    }

                    if(keyEvent->getKey() == GLFW_KEY_W)
                        camController.moveCamera(Brisk::BR_FORWARD, deltaTime);

                    if(keyEvent->getKey() == GLFW_KEY_S)
                        camController.moveCamera(Brisk::BR_BACKWARD, deltaTime);

                    if(keyEvent->getKey() == GLFW_KEY_A)
                        camController.moveCamera(Brisk::BR_LEFT, deltaTime);

                    if(keyEvent->getKey() == GLFW_KEY_D)
                        camController.moveCamera(Brisk::BR_RIGHT, deltaTime);

                }
            }             

            
            m_renderer.clear();

            shaderProgram.use();
            shaderProgram.UploadUniformMat4("model", model);
            shaderProgram.UploadUniformMat4("view", camController.getCamera()->getView());
            shaderProgram.UploadUniformMat4("projection", camController.getCamera()->getProjection());
            shaderProgram.uploadUniform3f("lightColor", lightColor);
            shaderProgram.uploadUniform3f("objectColor", toyColor);
            shaderProgram.uploadUniform3f("lightPosition", lightPosition);
            

            lightProgram.use();
            lightProgram.UploadUniformMat4("model", lightModel);
            lightProgram.UploadUniformMat4("view", camController.getCamera()->getView());
            lightProgram.UploadUniformMat4("projection", camController.getCamera()->getProjection());
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