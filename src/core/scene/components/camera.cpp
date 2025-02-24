#include "camera.hpp"

using namespace cge::scene;

void CameraComponent::updateCamera() {
    mFront = glm::rotate(mRotation, glm::vec3(0.0f, 0.0f, -1.0f));
    mRight = glm::rotate(mRotation, glm::vec3(1.0f, 0.0f, 0.0f));

    mUp = glm::cross(mRight, mFront);
}

