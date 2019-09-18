//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void draw(SDL_Renderer* gRenderer) {

    // Draw a box that has different colored lines on each edge.
    // The center of the box should align with the center of the screen.

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 - 100);

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 - 100, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 100);

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 100, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 100);

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 100, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100);

}