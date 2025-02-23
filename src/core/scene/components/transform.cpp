#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "transform.hpp"

using namespace cge::scene;

TransformComponent::~TransformComponent() {
    mParent = nullptr;
}

glm::vec3 TransformComponent::getPosition() const {
    return mPosition;
}

glm::quat TransformComponent::getRotation() const {
    return mRotation;
}

glm::vec3 TransformComponent::getScale() const {
    return mScale;
}

glm::mat4 TransformComponent::getLocalMatrix() const {
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), mPosition);
    glm::mat4 rotation = glm::toMat4(mRotation); // Convert quaternion to mat4
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), mScale);

    return translation * rotation * scale;
}

void TransformComponent::updateTransform() {
    if (mParent) {
        mWorldModelMatrix = mParent->mWorldModelMatrix * getLocalMatrix();
    } else {
        mWorldModelMatrix = getLocalMatrix();
    }
}

