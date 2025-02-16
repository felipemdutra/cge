#include "./core/engine.hpp"

int main() {
    cge::Engine engine;

    if (!engine.init()) {
        return -1;
    }

    engine.run();
    return 0;
}

