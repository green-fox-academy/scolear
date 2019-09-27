#include "FractalGenerator.h"

FractalGenerator::FractalGenerator(SDL_Renderer *renderer, int maxDepth, int size) : _renderer(renderer), _maxDepth(maxDepth), _triangleSize(size), _carpetSize(size) {
    _triangleHeight = _triangleSize * (sqrt(3) / 2);
}

void FractalGenerator::draw(FractalType type, int x0, int y0, int xm, int ym) {
    switch (type) {
        case FractalType::TRIANGLE : drawTriangleFractal(x0, y0, _triangleSize, _triangleHeight, 0);
        case FractalType::CARPET : drawCarpetFractal(x0, y0, _carpetSize, 0);
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
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0xFF);
        drawTriangleFractal(x0 + (3 * side / 4), y0 - h / 2, side / 2, h, depth + 1);

        // downbelow:
        SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0xFF);
        drawTriangleFractal(x0 + side / 4, y0 + h / 2, side / 2, h, depth + 1);

        // upleft:
        SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0xFF);
        drawTriangleFractal(x0 - side / 4, y0 - h / 2, side / 2, h, depth + 1);
    }
}

void FractalGenerator::drawCarpetFractal(int cX, int cY, int side, int depth) {

    int halfSide = side / 2;
    SDL_Rect r = {cX - halfSide, cY - halfSide, side, side};


    SDL_RenderFillRect(_renderer, &r);

    if (depth < _maxDepth) {
        // Top row:
        SDL_SetRenderDrawColor(_renderer, 1, 25, 54, 255 );
        drawCarpetFractal(cX - side, cY - side, side / 3, depth + 1);
        drawCarpetFractal(cX, cY - side, side / 3, depth + 1);
        drawCarpetFractal(cX + side, cY - side, side / 3, depth + 1);
        // Left:
        SDL_SetRenderDrawColor(_renderer, 70, 83, 98, 255 );
        drawCarpetFractal(cX - side, cY, side / 3, depth + 1);
        // Right:
        SDL_SetRenderDrawColor(_renderer, 130, 163, 161, 255 );
        drawCarpetFractal(cX + side, cY, side / 3, depth + 1);
        // Bottom row:
        SDL_SetRenderDrawColor(_renderer, 159, 196, 144, 255 );
        drawCarpetFractal(cX - side, cY + side, side / 3, depth + 1);
        drawCarpetFractal(cX, cY + side, side / 3, depth + 1);
        drawCarpetFractal(cX + side, cY + side, side / 3, depth + 1);
    }
}
