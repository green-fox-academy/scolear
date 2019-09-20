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

int coordinates[160][2];
bool flag = false;

int randomNumber(int nr_min, int nr_max)
{
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        srand(time(NULL));
    }
    return rand() % nr_max + nr_min;
}

void initStarPos(int n, int starSize) {

    srand(15);
    for (int i = 0; i < n; ++i) {
        coordinates[i][0] = (randomNumber(0, SCREEN_WIDTH - starSize)) ;
        coordinates[i][1] = (randomNumber(0, SCREEN_HEIGHT - starSize));
    }
    flag = true;
}

void drawStar(SDL_Renderer* renderer, int xp, int yp, int starSize)
{
    SDL_Rect star = {xp, yp, starSize, starSize};
    SDL_RenderFillRect(renderer, &star);
}

void draw(SDL_Renderer* gRenderer) {

    // Don't forget to set the background color to black in main.cpp

    int starSize = 2;
    int numOfStars = 160;

    if (!flag) {
        initStarPos(numOfStars, starSize);
    }

    for (int i = 0; i < numOfStars; ++i) {

        int brightness = rand() % 200 + 190;

        SDL_SetRenderDrawColor(gRenderer, brightness, brightness, brightness, 255);

        drawStar(gRenderer, coordinates[i][0], coordinates[i][1], starSize);

        SDL_Delay(1);
    }

}