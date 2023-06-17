#include "PerspectiveCameraController.h"

namespace Brisk
{
    PerspectiveCameraController::PerspectiveCameraController(int screenWidth, int screenHeight)
        : m_camera(screenWidth, screenHeight)
    {

        m_cameraPosition = &m_camera.getCameraPosition();

    }
    

    void PerspectiveCameraController::moveCamera(Direction direction, float deltaTime)
    {

        switch (direction)
        {
        case BR_FORWARD:
            *m_cameraPosition += (m_cameraSpeed * deltaTime) * m_camera.getCameraFront();
            break;

        case BR_BACKWARD:
            *m_cameraPosition -= (m_cameraSpeed * deltaTime) * m_camera.getCameraFront(); 
            break;

        case BR_LEFT:
            *m_cameraPosition -= glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())) * (m_cameraSpeed * deltaTime);
            break;

        case BR_RIGHT:
            *m_cameraPosition += glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())) * (m_cameraSpeed * deltaTime);
            break;

        case BR_UP:
            *m_cameraPosition += m_cameraSpeed * deltaTime * m_camera.getCameraUp();
            break;
            
        case BR_DOWN:
            *m_cameraPosition -= m_cameraSpeed * deltaTime * m_camera.getCameraUp();
            break;
                
        }
        
        m_camera.updateView();
        
    }

    void PerspectiveCameraController::moveCamera(Direction direction)
    {
        switch (direction)
        {
        case BR_FORWARD:
            *m_cameraPosition += m_cameraSpeed * m_camera.getCameraFront();
            break;

        case BR_BACKWARD:
            *m_cameraPosition -= m_cameraSpeed * m_camera.getCameraFront(); 
            break;

        case BR_LEFT:
            *m_cameraPosition -= glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())) * (m_cameraSpeed);
            break;

        case BR_RIGHT:
            *m_cameraPosition += glm::normalize(glm::cross(m_camera.getCameraFront(), m_camera.getCameraUp())) * (m_cameraSpeed);
            break;

        case BR_UP:
            *m_cameraPosition += m_cameraSpeed * m_camera.getCameraUp();
            break;
        case BR_DOWN:
            *m_cameraPosition -= m_cameraSpeed * m_camera.getCameraUp();
            break;
                
        }
        m_camera.updateView();
    }
}