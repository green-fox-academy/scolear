//
// Created by scolear on 2019. 09. 18..
//

// Draw a green 100x100 square to the canvas' center.

#include "draw.h"

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 - 50);

    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 - 50, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50);

    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 50);

    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 50, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50);

}

