#ifndef FRACTALS_FRACTALGENERATOR_H
#define FRACTALS_FRACTALGENERATOR_H

#include <SDL_render.h>

enum class FractalType {
    TRIANGLE,
    CARPET,
    TREE
};

class FractalGenerator {
public:

    FractalGenerator(SDL_Renderer* renderer, int maxDepth, int size);

    void draw(FractalType type, int x0, int y0, int xm, int ym);

    void drawTriangleFractal(int x0, int y0, int side, float height, int depth);
    void drawCarpetFractal(int cX, int cY, int side, int depth);
    void drawTreeFractal(int x0, int y0, int xm, int ym, int depth);

private:
    int _maxDepth;
    float _triangleHeight;
    int _triangleSize;
    int _carpetSize;
    SDL_Renderer* _renderer;
};


#endif //FRACTALS_FRACTALGENERATOR_H
