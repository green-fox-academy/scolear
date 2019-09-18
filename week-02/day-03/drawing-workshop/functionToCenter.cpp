//
// Created by scolear on 2019. 09. 18..
//

// Create a function that draws a single line and takes 2 parameters:
// The x and y coordinates of the line's starting point
// and draws a line from that point to the center of the canvas.
// Fill the canvas with lines from the edges, every 20 px, to the center.

#include "draw.h"

void funcToCenter(SDL_Renderer* renderer, int xp, int yp) {
    SDL_RenderDrawLine(renderer, xp, yp, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    for (int x = 0; x <= SCREEN_WIDTH; x += 20) {
        funcToCenter(gRenderer, x, 0);
        funcToCenter(gRenderer, x, SCREEN_HEIGHT);
    }

    for (int y = 0; y <= SCREEN_HEIGHT; y += 20) {
        funcToCenter(gRenderer, 0, y);
        funcToCenter(gRenderer, SCREEN_WIDTH, y);
    }

}

