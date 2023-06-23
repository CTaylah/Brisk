#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tinygltf/tiny_gltf.h"

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

        auto eventList = Brisk::EventHandler::getEventList();

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        m_window->setCursorVisibility(false);
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

        vertexArray.addBuffer(vertexBuffer,bufferLayout);
        lightCubeArray.addBuffer(vertexBuffer, bufferLayout);

        Brisk::ShaderProgram shaderProgram(vertexShaderSource, fragmentShaderSource);
        Brisk::ShaderProgram lightProgram(vertexShaderSource, lightShaderSource);

        Brisk::RenderData renderData(std::make_shared<Brisk::VertexArray>(vertexArray), false);

        Brisk::Entity toyCube(&renderData);
        Brisk::Entity lightCube(&renderData);

        toyCube.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
        lightCube.setPosition(glm::vec3(1.2f, 1.0f, 2.0f));

        glm::vec3 toyPosition = toyCube.getPosition();
        glm::vec3 lightPosition = lightCube.getPosition();
        
        glm::vec3 toyColor(0.5f, 0.5f, 0.2f);
        glm::vec3 lightColor(1.0f,1.0f,1.0f);

        lightProgram.use();
        lightProgram.uploadUniform3f("lightColor", lightColor);

        Brisk::PerspectiveCameraController camController(1280, 720);
        camController.setCameraSpeed(2.6f);
        camController.setSensitivty(.05);
        
        
        Brisk::Renderer renderer(camController.getCamera());
        renderer.setClearColor(0.1f, 0.2f, 0.1f, 1.0f);

        bool show_demo_window = true;
        bool cursorVisible = false;
        double lastFrame = 0.0;
        float shininess = 0.0f;
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
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

            ImGui::SliderFloat("shininess", &shininess, 0.0f, 256.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("Toy Color", (float*)&toyColor); // Edit 3 floats representing a color
            ImGui::ColorEdit3("Light Color", (float*)&lightColor); // Edit 3 floats representing a color
            if(ImGui::SliderFloat3("Toy Position", (float*)&toyPosition, -10.0f, 10.0f))
            {
                toyCube.setPosition(toyPosition);
            }
             if(ImGui::SliderFloat3("Light Position", (float*)&lightPosition, -10.0f, 10.0f))
            {
                lightCube.setPosition(lightPosition);
            }
            
           

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

            if(Brisk::Input::isKeyPressed(BRISK_KEY_E))
            {
                camController.moveCamera(Brisk::BR_UP, deltaTime);
            }
            if(Brisk::Input::isKeyPressed(BRISK_KEY_Q))
            {
                camController.moveCamera(Brisk::BR_DOWN, deltaTime);
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


            renderer.clear();

            shaderProgram.use();
            shaderProgram.uploadUniform3f("lightPosition", lightPosition);
            shaderProgram.uploadUniform3f("lightColor", lightColor);
            shaderProgram.uploadUniform3f("objectColor", toyColor);
            shaderProgram.uploadUniformf("shininess", shininess);
            toyCube.draw(renderer, shaderProgram);

            lightProgram.use();
            lightProgram.uploadUniform3f("lightColor", lightColor);
            lightCube.draw(renderer, lightProgram);

            //renderer.drawTriangles(vertexArray, shaderProgram, 36);
            //renderer.drawTriangles(vertexArray, lightProgram, 36);

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
    Brisk::testGLTF();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    delete(sandbox);
    return 0;
}