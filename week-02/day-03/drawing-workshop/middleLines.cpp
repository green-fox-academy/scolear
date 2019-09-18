//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"
#include "utils.h"

void draw(SDL_Renderer* gRenderer) {

    // MiddleLines
    // draw a red horizontal line to the canvas' middle.
    // draw a green vertical line to the canvas' middle.

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);

}
