namespace cge {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void init();
        void clear(float r, float g, float b, float a);

        // Draws a simple shape for now
        void draw();
    };
}

