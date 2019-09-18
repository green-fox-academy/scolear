//
// Created by scolear on 2019. 09. 18..
//
// Create a function that draws a single line and takes 2 parameters:
// The x and y coordinates of the line's starting point
// and draws a 50 long horizontal line from that point.
// Draw at least 3 lines with that function using a loop.

#include "draw.h"

void horizontal(SDL_Renderer* renderer, int xp, int yp) {
    SDL_RenderDrawLine(renderer, xp, yp, xp + 50, yp);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

    for (int i = 0; i < 3; ++i) {
        horizontal(gRenderer, (i + 2) * 20, (i + 2) * 40);
    }

}

