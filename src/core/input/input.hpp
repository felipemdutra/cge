#include <functional>
#include <string>

class GLFWwindow;

namespace cge {
    // Prevent circular dependency
    class Window;
    
    class Input {
        public:
            using InputCallback = std::function<void()>;

            bool init(GLFWwindow* window);

            void bindAction(std::string& action, int key);
            void bindCallback(std::string& action, InputCallback callback);

            void update();

            ~Input();

        private:
            GLFWwindow* mWindow = nullptr;

            // Key, action
            std::unordered_map<int, std::string> mKeyActions;

            // Action, callback
            std::unordered_map<std::string, InputCallback> mActionCallbacks;

            // Key, state (pressed or not)
            std::unordered_map<int, bool> mKeyStates;
            std::unordered_map<int, bool> mPreviousKeyStates;

            bool keyDown(int key) const;
    };
} // namespace cge

