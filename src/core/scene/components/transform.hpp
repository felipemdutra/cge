#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>


namespace cge::scene {
    struct TransformComponent {
        glm::vec3 mPosition = glm::vec3(0.0f);
        glm::quat mRotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
        glm::vec3 mScale = glm::vec3(1.0f); // Must be initialized to 1.0f to prevent scaling by zero.

        // Model matrix can be calculated from local position, rotation, and scale
        // by calling updateTransform().
        glm::mat4 mWorldModelMatrix = glm::mat4(1.0f);

        TransformComponent* mParent = nullptr;

        glm::vec3 getPosition() const;
        glm::quat getRotation() const;
        glm::vec3 getScale() const;

        glm::mat4 getLocalMatrix() const;

        void updateTransform();

        ~TransformComponent();
    };
}

