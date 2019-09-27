#ifndef FRACTALS_FRACTALGENERATOR_H
#define FRACTALS_FRACTALGENERATOR_H

#include <SDL_render.h>

enum class FractalType {
    TRIANGLE
};

class FractalGenerator {
public:

    FractalGenerator(SDL_Renderer* renderer, int maxDepth);

    void draw(FractalType type, int x0, int y0, int xm, int ym);
    void drawTriangleFractal(int x0, int y0, int side, float height, int depth);

private:
    int _maxDepth;
    float _triangleHeight;
    int _triangleSize;
    SDL_Renderer* _renderer;
};


#endif //FRACTALS_FRACTALGENERATOR_H
