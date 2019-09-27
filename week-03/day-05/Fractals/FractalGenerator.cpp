#include "FractalGenerator.h"

FractalGenerator::FractalGenerator(SDL_Renderer *renderer, int maxDepth) : _renderer(renderer), _maxDepth(maxDepth), _triangleSize(350) {
    _triangleHeight = _triangleSize * (sqrt(3) / 2);
}

void FractalGenerator::draw(FractalType type, int x0, int y0, int xm, int ym) {

    switch (type) {
        case FractalType::TRIANGLE: drawTriangleFractal(x0, y0, _triangleSize, _triangleHeight, 0);
    }

}

void FractalGenerator::drawTriangleFractal(int x0, int y0, int side, float height, int depth) {

    float h = side * (sqrt(3) / 2);

    // Base line:
    SDL_RenderDrawLine(_renderer, x0, y0, x0 + side, y0);
    // Second line from start:
    SDL_RenderDrawLine(_renderer, x0, y0, x0 + side / 2, y0 - h);
    // Third line:
    SDL_RenderDrawLine(_renderer, x0 + side / 2, y0 - h, x0 + side, y0);

    if(depth < _maxDepth){
        // upright:
        drawTriangleFractal(x0 + (3 * side / 4), y0 - h / 2, side / 2, h, depth + 1);
        // downbelow:
        drawTriangleFractal(x0 + side / 4, y0 + h / 2, side / 2, h, depth + 1);
        // upleft:
        drawTriangleFractal(x0 - side / 4, y0 - h / 2, side / 2, h, depth + 1);
    }
}
