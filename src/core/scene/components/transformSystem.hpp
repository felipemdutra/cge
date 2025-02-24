#include <glm/glm.hpp>

#include "transform.hpp"

namespace cge::scene::TransformSystem {
    /**
     * Computes the local model matrix from the local position, rotation, and scale.
     *
     * @param transform The transform component to compute the model matrix from.
     * @return The local model matrix.
     */
    glm::mat4 getLocalMatrix(const TransformComponent& transform);

    /**
     * Computes the world model matrix, which is the local model matrix relative to the parent's world model matrix.
     *
     * @param transform The transform component to compute the world model matrix from.
     * @return The world model matrix.
     */
    glm::mat4 getWorldMatrix(const TransformComponent& transform);

    void setPosition(TransformComponent& transform, const glm::vec3& newPosition);
    void setRotation(TransformComponent& transform, const glm::quat& newRotation);
    void setScale(TransformComponent& transform, const glm::vec3& newScale);

} // namespace cge::scene::TransformSystem

