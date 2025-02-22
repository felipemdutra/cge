#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"

using namespace cge;
using namespace glm;

Camera::Camera() : mPos(0.0f, 0.0f, 0.0f), mFront(0.0f, 0.0f, -1.0f),
    mUp(0.0f, 1.0f, 0.0f), mFov(45.0f), mAspectRatio(4.0f / 3.0f), 
    mNearPlane(0.1f), mFarPlane(100.0f), mYaw(YAW), mPitch(PITCH) { }

Camera::~Camera() { }

bool Camera::init(float fov, float aspectRatio, float nearPlane, float farPlane) {
    mFov = fov;
    mAspectRatio = aspectRatio;
    mNearPlane = nearPlane;
    mFarPlane = farPlane;

    mViewMatrix = lookAt(mPos, mPos + mFront, mUp);
    mProjectionMatrix = perspective(radians(mFov), mAspectRatio, mNearPlane, mFarPlane);

    return true;
}

