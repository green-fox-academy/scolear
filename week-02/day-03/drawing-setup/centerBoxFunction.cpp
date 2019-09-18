//
// Created by scolear on 2019. 09. 18..
//

// create a function that draws one square and takes 1 parameters:
// the square size
// and draws a square of that size to the center of the canvas.
// draw at least 3 squares with that function.
// the squares should not be filled otherwise they will hide each other
// avoid code duplication.

#include "draw.h"

void centerSquare(SDL_Renderer* renderer, int size) {

    SDL_Rect rect;
    rect.x = SCREEN_WIDTH / 2 - size / 2;
    rect.y = SCREEN_HEIGHT / 2 - size / 2;
    rect.h = size;
    rect.w = size;

    SDL_RenderDrawRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 120, 255);

    for (int i = 0; i < 10; ++i) {
        centerSquare(gRenderer, (i + 1) * 50);
    }



}
