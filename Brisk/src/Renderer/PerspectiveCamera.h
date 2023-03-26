#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Brisk{

    class PerspectiveCamera{

    public:
        PerspectiveCamera(float screenWidth, float screenHeight); 
        void lookAt(double xPosition, double yPosition);
        glm::mat4 getProjectionView() const;

    private:
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;

        glm::vec3 m_cameraFront;
        glm::vec3 m_cameraPosition;
        glm::vec3 m_cameraUp;

        glm::vec3 m_worldUp;

        int m_screenWidth, m_screenHeight;
        int m_lastX, m_lastY;
        bool m_firstMove = true;

        double m_pitch = 0.0;
        double m_yaw = -90.0;

        double  m_sensitivity = 0.035f;
    
    private:
        void updateView();
    };

}