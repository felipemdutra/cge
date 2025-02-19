#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"

using namespace cge;
using namespace glm;

Camera::Camera() : m_pos(0.0f, 0.0f, 0.0f), m_front(0.0f, 0.0f, -1.0f),
    m_up(0.0f, 1.0f, 0.0f), m_fov(45.0f), m_aspectRatio(4.0f / 3.0f), 
    m_nearPlane(0.1f), m_farPlane(100.0f), m_yaw(YAW), m_pitch(PITCH) { }

Camera::~Camera() { }

bool Camera::init(float fov, float aspectRatio, float nearPlane, float farPlane) {
    m_fov = fov;
    m_aspectRatio = aspectRatio;
    m_nearPlane = nearPlane;
    m_farPlane = farPlane;

    m_viewMatrix = lookAt(m_pos, m_pos + m_front, m_up);
    m_projectionMatrix = perspective(radians(m_fov), m_aspectRatio, m_nearPlane, m_farPlane);

    return true;
}

