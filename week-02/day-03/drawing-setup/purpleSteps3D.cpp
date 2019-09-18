//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void outlinedSquare(SDL_Renderer* renderer, int size, int xp, int yp) {

    SDL_Rect rect;
    rect.x = xp + 2;
    rect.y = yp + 2;
    rect.h = size - 4;
    rect.w = size - 4;

    SDL_Rect rect2;
    rect2.x = xp;
    rect2.y = yp;
    rect2.h = size;
    rect2.w = size;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_SetRenderDrawColor(renderer, 137, 50, 168, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    int size = 30;

    for (int i = 0; i < 5; ++i) {
        outlinedSquare(gRenderer, size, size, size);
        size *= 2;
    }

}
