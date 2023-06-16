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

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(m_window->getGlfwWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 430");

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
        bool show_demo_window = true;
        bool cursorVisible = false;
        while(!glfwWindowShouldClose(m_window->getGlfwWindow()))
        {
            double currentFrame = glfwGetTime();
            double deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;            

            m_window->onUpdate();

            //Start ImGui Frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("Toy Color", (float*)&toyColor); // Edit 3 floats representing a color
            ImGui::ColorEdit3("Light Color", (float*)&lightColor); // Edit 3 floats representing a color
            ImGui::SliderFloat3("Toy Position", (float*)&cubPos, -10.0f, 10.0f);
            
            

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }
            ImGui::Render();

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

            if(Brisk::Input::isKeyPressed(BRISK_KEY_F))
            {
                m_window->setCursorVisibility(false);   
                cursorVisible = false;
            }
            if(Brisk::Input::isKeyPressed(BRISK_KEY_G))
            {
                m_window->setCursorVisibility(true);   
                cursorVisible = true;
            }

            if(Brisk::Input::isKeyPressed(BRISK_KEY_ESCAPE))
            {
                return;
            }
                       

            for(int i = 0; i < eventList->size(); i++)
            {
                Brisk::Event* event = eventList->at(i);
                if(event->getEventType() == Brisk::BR_MOUSE_MOVE && !cursorVisible)
                {
                    Brisk::MouseEvent* mouseEvent = static_cast<Brisk::MouseEvent*>(event);
                    double xpos = mouseEvent->getXPosition();
                    double ypos = mouseEvent->getYPosition();
                    mouseEvent->setHandled(true);
                    camController.getCamera()->lookAt(xpos, ypos);
                }

                if(event->getEventType() == Brisk::BR_WINDOW_RESIZE)
                {
                    Brisk::WindowResizeEvent* resizeEvent = static_cast<Brisk::WindowResizeEvent*>(event);
                    camController.getCamera()->setAspectRatio(resizeEvent->getWidth(), resizeEvent->getHeight());
                    glViewport(0, 0, resizeEvent->getWidth(), resizeEvent->getHeight());
                }

            }             

            
            m_renderer.clear();

            glm::mat4 transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(sin(glfwGetTime() * 3), cos(glfwGetTime()) * 3, -1.0f));
            transform = glm::translate(transform, cubPos);
            transform = glm::rotate(transform, (float)glfwGetTime() * 0.5f, glm::vec3(0.0f, 1.0f, 0.0f));
            transform = glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f));

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
            m_renderer.drawTriangles(vertexArray, lightProgram, 36);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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
    Brisk::Log::error("Sandbox has exited");

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    delete(sandbox);
    return 0;
}