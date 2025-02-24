#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/trigonometric.hpp>

#include "transform.hpp"

namespace cge::scene {
    struct CameraComponent {
        glm::vec3 mPosition = glm::vec3(0.0f);
        glm::quat mRotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

        glm::vec3 mFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 mUp = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 mRight = glm::vec3(1.0f, 0.0f, 0.0f);

        float mFov = glm::radians(45.0f);
        float mNearPlane = 0.1f;
        float mFarPlane = 1000.0f;

        inline glm::mat4 getProjectionMatrix(float aspectRatio) const {
            return glm::perspective(mFov, aspectRatio, mNearPlane, mFarPlane); 
        }

        inline glm::mat4 getViewMatrix() const {
            return glm::lookAt(mPosition, mPosition + mFront, mUp);
        }

        void updateCamera();
    };
}

