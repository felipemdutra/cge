#include <functional>
#include <glm/glm.hpp>
#include <string>

class GLFWwindow;

namespace cge {
    // Prevent circular dependency
    class Window;
    
    class Input {
        public:
            using InputCallback = std::function<void()>;

            bool init(GLFWwindow* window);

            void bindKeyAction(int key, std::string& action);
            void bindMouseButtonAction(int button, std::string& action);

            void bindCallback(std::string& action, InputCallback callback);

            glm::vec2 getMousePosition() const;
            float getMouseX() const;
            float getMouseY() const;

            void update();

            ~Input();

        private:
            GLFWwindow* mWindow = nullptr;

            std::unordered_map<int, std::string> mKeyActions;
            std::unordered_map<int, std::string> mMouseButtonActions;

            // Action, callback
            std::unordered_map<std::string, InputCallback> mActionCallbacks;

            // Key, state (pressed or not)
            std::unordered_map<int, bool> mKeyStates;
            std::unordered_map<int, bool> mPreviousKeyStates;

            std::unordered_map<int, bool> mMouseButtonStates;
            std::unordered_map<int, bool> mPreviousMouseButtonStates;

            bool keyDown(int key) const;
            bool mouseButtonDown(int button) const;
    };
} // namespace cge

