//
// Created by scolear on 2019. 09. 18..
//

// Draw the night sky:
//  - The background should be black
//  - The stars can be small squares
//  - The stars should have random positions on the canvas
//  - The stars should have random color (some shade of grey)
//
// You might have to make modifications somewhere else to create a black background ;)

#include "draw.h"
#include <ctime>
#include <cstdlib>

int randomNumber(int nr_min, int nr_max)
{
    static bool initialized = false;

    if (!initialized) {
        initialized = true;
        srand(time(NULL));
    }

    return rand() % nr_max + nr_min;
}

void drawRect(SDL_Renderer* renderer, int xp, int yp) {

    // SDL_SetRenderDrawColor(renderer, rand, randomNumber(0,255), randomNumber(0,255), 255);

    SDL_Rect rect;
    rect.x = xp;
    rect.y = yp;
    rect.h = 3;
    rect.w = 3;

    SDL_RenderFillRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    // Don't forget to set the background color to black in main.cpp

    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    srand(14);

    for (int i = 0; i < 100; ++i) {

        int whiteness = randomNumber(150, 255);
        SDL_SetRenderDrawColor(gRenderer, whiteness, whiteness, whiteness, 255);

        drawRect(gRenderer, rand() % (SCREEN_WIDTH - 3), rand() % (SCREEN_HEIGHT - 3));
    }

}

