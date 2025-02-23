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

            /**
             * bindKeyAction - Binds a key to an action.
             *
             * @param key - The key to bind.
             * @param action - The action to bind the key to.
             */
            void bindKeyAction(int key, std::string& action);

            /**
             * bindMouseButtonAction - Binds a mouse button to an action.
             *
             * @param button - The mouse button to bind.
             * @param action - The action to bind the mouse button to.
             */
            void bindMouseButtonAction(int button, std::string& action);

            /**
             * bindCallback - Binds an action to a callback.
             *
             * @param action - The action to bind.
             * @param callback - The callback to bind the action to.
             */
            void bindCallback(std::string& action, InputCallback callback);

            /**
             * getMousePosition - Returns the current position of the mouse cursor.
             */
            glm::vec2 getMousePosition() const;

            /**
             * getMouseX - Returns the x position of the mouse cursor.
             */
            float getMouseX() const;

            /**
             * getMouseY - Returns the y position of the mouse cursor.
             */
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

            /**
             * keyDown - Returns true if the key is currently pressed.
             *
             * @param key - The key to check.
             * @return bool - True if the key is currently pressed, false otherwise.
             */
            bool mouseButtonDown(int button) const;
    };
} // namespace cge

