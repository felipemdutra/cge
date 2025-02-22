#include <functional>
#include <string>

class GLFWwindow;

namespace cge {
    // Prevent circular dependency
    class Window;
    
    class Input {
        public:
            using InputCallback = std::function<void()>;

            static void init(GLFWwindow* window);

            static void bindAction(std::string& action, int key);
            static void bindCallback(std::string& action, InputCallback callback);

        private:
            GLFWwindow* sWindow = nullptr;

            static std::unordered_map<int, std::string> sKeyBindings;
            static std::unordered_map<std::string, InputCallback> sActionCallbacks;

            bool keyDown(int key) const;
    };
}

