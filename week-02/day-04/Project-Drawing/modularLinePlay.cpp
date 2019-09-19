//
// Created by scolear on 2019. 09. 19..
//

#include "draw.h"

void drawPattern(SDL_Renderer* gRenderer, int startX, int startY, int boxSize, int space)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    for (int i = 0; i < boxSize; i += space) {
        SDL_RenderDrawLine(gRenderer, startX + i, startY, startX + boxSize, startY + i);
    }

    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    for (int i = 0; i < boxSize; i += space) {
        SDL_RenderDrawLine(gRenderer, startX, startY + i, startX + i, startY + boxSize);
    }
}

void draw(SDL_Renderer* gRenderer) {

    // Set the desired parameters here:
    int numOfElem = 8;                                      // (even) number of times texture should appear in a row
    int space = 20;                                         // distance between lines in a pattern

    // Drawing:
    int elemSize = SCREEN_SIZE / numOfElem;                 // size of a box of patterns

    for (int i = 0; i <= SCREEN_SIZE - elemSize; ++i) {
        for (int j = 0; j <= SCREEN_SIZE - elemSize; ++j) {
            drawPattern(gRenderer, j * elemSize, i * elemSize, elemSize, space);
        }
    }
}