//
// Created by scolear on 2019. 09. 18..
//



#include <ctime>
#include <cstdlib>
#include "draw.h"
//#include "utils.h"

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

    SDL_SetRenderDrawColor(renderer, randomNumber(0,255), randomNumber(0,255), randomNumber(0,255), 255);

    SDL_Rect rect;
    rect.x = xp;
    rect.y = yp;
    rect.h = randomNumber(50, 100);
    rect.w = randomNumber(50, 100);

    SDL_RenderDrawRect(renderer, &rect);
}

void draw(SDL_Renderer* gRenderer) {

    // Exercise:
    // draw four different size and color rectangles.
    // avoid code duplication.

    for (int i = 0; i < 4; ++i) {
        drawRect(gRenderer, ( i + 3) * 20, (i + 3) * 20);
    }

    SDL_Delay(1000);


}

