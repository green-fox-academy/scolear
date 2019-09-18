//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);

    for (int i = 0; i < SCREEN_SIZE; i += 20) {
        SDL_RenderDrawLine(gRenderer, i, 0, SCREEN_SIZE, i);
    }

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    for (int i = 0; i < SCREEN_SIZE; i += 20) {
        SDL_RenderDrawLine(gRenderer, 0, i, i, SCREEN_SIZE);
    }

}
