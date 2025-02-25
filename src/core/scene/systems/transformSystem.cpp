#include <glm/gtx/quaternion.hpp>

#include "transformSystem.hpp"

using namespace cge::scene;

glm::mat4 TransformSystem::getLocalMatrix(const TransformComponent& transform) {
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), transform.mPosition);
    glm::mat4 rotation = glm::toMat4(transform.mRotation); // Convert quaternion to mat4
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), transform.mScale);

    return translation * rotation * scale;
}

glm::mat4 TransformSystem::getWorldMatrix(const TransformComponent& transform) {
    if (transform.mParent) {
        return transform.mParent->mModelMatrix * getLocalMatrix(transform);
    }

    return getLocalMatrix(transform);
}

void TransformSystem::setPosition(TransformComponent& transform, const glm::vec3& newPosition) {
    transform.mPosition = newPosition;
}

void TransformSystem::setRotation(TransformComponent& transform, const glm::quat& newRotation) {
    transform.mRotation = newRotation;
}

void TransformSystem::setScale(TransformComponent& transform, const glm::vec3& newScale) {
    transform.mScale = newScale;
}

