#pragma once

#include <glm/glm.hpp>

#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 2.5f
#define SENSITIVITY 0.1f
#define ZOOM 45.0f

namespace cge {
    class Camera {
    public:
        Camera();
        ~Camera();

        bool init(float fov, float aspectRatio, float nearPlane, float farPlane);

        void update();
        void move(glm::vec3 direction);

        glm::mat4 getViewMatrix();
        glm::mat4 getProjectionMatrix();

    private:
        glm::vec3 m_pos;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;

        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;

        float m_fov;
        float m_aspectRatio;
        float m_nearPlane;
        float m_farPlane;

        float m_yaw;
        float m_pitch;

        float m_movementSpeed;
        float m_mouseSensitivity;
        float m_zoom;
    };
} // namespace cge

