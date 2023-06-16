
#include "PerspectiveCamera.h"

namespace Brisk{

    PerspectiveCamera::PerspectiveCamera(float screenWidth, float screenHeight)
    {

        m_viewMatrix = glm::mat4(1.0f);

        m_projectionMatrix = glm::perspective(glm::radians(45.0f), screenWidth / screenHeight, 0.1f, 100.0f);

        m_lastX = screenWidth / 2;
        m_lastY = screenHeight / 2;

        m_screenWidth = screenWidth;
        m_screenHeight = screenHeight;

        m_cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
        m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);


        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

        glm::vec3 cameraDirection = glm::normalize(m_cameraPosition - cameraTarget);

        glm::vec3 cameraRight = glm::normalize(glm::cross(m_worldUp, cameraDirection));

        m_cameraUp = glm::cross(cameraDirection, cameraRight);

        updateView();
    }

    //This function should probably be moved to the camera controller class
    void PerspectiveCamera::lookAt(double xPosition, double yPosition)
    {
        if(m_firstMove)
        {
            m_lastX = xPosition;
            m_lastY = yPosition;
        }

        double xoffset = xPosition - m_lastX;
        double yoffset = m_lastY - yPosition;

        m_lastX = xPosition;
        m_lastY = yPosition;

        m_firstMove = false;

        xoffset *= m_sensitivity;
        yoffset *= m_sensitivity;

        m_yaw += xoffset;
        m_pitch += yoffset;

        if(m_pitch > 89.0f)
            m_pitch = 89.0f;

        else if(m_pitch < -89.0f)
            m_pitch = -89.0f;

        glm::vec3 direction;

        direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        direction.y = sin(glm::radians(m_pitch));
        direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

        m_cameraFront = glm::normalize(direction);

        m_firstMove = false;
        updateView();
    }
    
    void PerspectiveCamera::updateView()
    {
        m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + m_cameraFront, m_cameraUp);  
    }

    void PerspectiveCamera::setAspectRatio(float screenWidth, float screenHeight){
        m_screenWidth = screenWidth;
        m_screenHeight = screenHeight;
        m_projectionMatrix = glm::perspective(glm::radians(45.0f), screenWidth / screenHeight, 0.1f, 100.0f);
    }

    glm::vec3& PerspectiveCamera::getCameraPosition()
    {
        return m_cameraPosition;
    }

    const glm::vec3& PerspectiveCamera::getCameraUp()
    {
        return m_cameraUp;

    }
    
    const glm::vec3& PerspectiveCamera::getCameraFront()
    {
        return m_cameraFront;
    }


    glm::mat4 PerspectiveCamera::getProjectionView() const
    {
        return m_projectionMatrix * m_viewMatrix;
    }

    glm::mat4 PerspectiveCamera::getView() const
    {
        return m_viewMatrix;
    }

    glm::mat4 PerspectiveCamera::getProjection() const
    {
        return m_projectionMatrix;
    }



}