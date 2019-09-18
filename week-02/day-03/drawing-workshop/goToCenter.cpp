//
// Created by scolear on 2019. 09. 18..
//

// Create a function that draws a single line and takes 2 parameters:
// The x and y coordinates of the line's starting point
// and draws a line from that point to the center of the canvas.
// Draw at least 3 lines with that function using a loop.

#include "draw.h"

void goToCenter(SDL_Renderer* renderer, int xp, int yp) {
    SDL_RenderDrawLine(renderer, xp, yp, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);

    for (int i = 0; i < 3; ++i) {
        goToCenter(gRenderer, i * 3 + 200, i * 200);
    }
}

