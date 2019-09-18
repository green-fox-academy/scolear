//
// Created by scolear on 2019. 09. 18..
//

// Create a square drawing function that takes 2 parameters:
// The square size, and the fill color,
// and draws a square of that size and color to the center of the canvas.
// Create a loop that fills the canvas with a rainbow of colored squares.

#include "draw.h"

void rainbowSquare(SDL_Renderer* renderer, int size, int r, int g, int b) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 100);

    SDL_Rect rect;
    rect.x = SCREEN_WIDTH / 2 - size / 2;
    rect.y = SCREEN_HEIGHT / 2 - size / 2;
    rect.h = size;
    rect.w = size;

    SDL_RenderFillRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    for (int i = 0; i < 60; ++i) {
        rainbowSquare(gRenderer, SCREEN_WIDTH - i * 10, 255 - i * 3, 0 + i * 3, 0 + i * 4);
    }



}
