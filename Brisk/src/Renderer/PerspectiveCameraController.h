#pragma once

#include "PerspectiveCamera.h"

namespace Brisk{
    
    enum Direction
    {
        BR_LEFT, BR_RIGHT, 
        BR_FORWARD, BR_BACKWARD,
        BR_UP, BR_DOWN
    };

    class PerspectiveCameraController
    {
    public:
        PerspectiveCameraController(int screenWidth, int screenHeight);
        PerspectiveCamera* getCamera() { return &m_camera; }

        void moveCamera(Direction direction);
        void moveCamera(Direction direction, float deltaTime);
        void setCameraSpeed(float cameraSpeed){  m_cameraSpeed = cameraSpeed; }
        void setSensitivty(double sensitivity){ m_camera.setSensitivity(sensitivity); }

    private:
        PerspectiveCamera m_camera;
        glm::vec3* m_cameraPosition;
        float m_cameraSpeed = 0.35f;
        

    };
}