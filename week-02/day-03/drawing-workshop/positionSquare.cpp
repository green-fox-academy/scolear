//
// Created by scolear on 2019. 09. 18..
//

// create a function that draws one square and takes 2 parameters:
// the x and y coordinates of the square's top left corner
// and draws a 50x50 square from that point.
// draw at least 3 squares with that function.
// avoid code duplication.

#include "draw.h"
#include <cstdlib>

void drawSquare(SDL_Renderer* renderer, int xp, int yp) {

    SDL_Rect rect;
    rect.x = xp;
    rect.y = yp;
    rect.h = 50;
    rect.w = 50;

    SDL_RenderDrawRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 120, 255);

    srand(15);
    for (int i = 0; i < 5; ++i) {
        drawSquare(gRenderer, rand() % (SCREEN_WIDTH - 50), rand() % (SCREEN_HEIGHT - 50));
    }

}

