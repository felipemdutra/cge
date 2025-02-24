#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "transform.hpp"

using namespace cge::scene;

TransformComponent::~TransformComponent() {
    mParent = nullptr;
}

