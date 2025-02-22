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

        private:
            GLFWwindow* sWindow = nullptr;

            std::unordered_map<int, std::string> mKeyActions;
            std::unordered_map<std::string, InputCallback> mActionCallbacks;

            bool keyDown(int key) const;
    };
}

