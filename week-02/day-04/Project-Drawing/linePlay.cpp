//
// Created by scolear on 2019. 09. 18..
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


    drawPattern(gRenderer, 0, 0, SCREEN_SIZE, 5);



}
