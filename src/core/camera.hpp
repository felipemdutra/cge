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

        glm::mat4 getViewMatrix();
        glm::mat4 getProjectionMatrix();

    private:
        glm::vec3 mPos;
        glm::vec3 mFront;
        glm::vec3 mUp;
        glm::vec3 mRight;
        glm::vec3 mWorldUp;

        glm::mat4 mViewMatrix;
        glm::mat4 mProjectionMatrix;

        float mFov;
        float mAspectRatio;
        float mNearPlane;
        float mFarPlane;

        float mYaw;
        float mPitch;

        float mMovementSpeed;
        float mMouseSensitivity;
        float mZoom;
    };
} // namespace cge

