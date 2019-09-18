//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void drawFirstQuarter(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < SCREEN_SIZE / 2; i += 20) {
        SDL_RenderDrawLine(gRenderer, i, SCREEN_SIZE / 2, SCREEN_SIZE / 2, SCREEN_SIZE / 2 - i);
    }
}
void drawSecondQuarter(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < SCREEN_SIZE / 2; i += 20) {
        SDL_RenderDrawLine(gRenderer, SCREEN_SIZE / 2, i, SCREEN_SIZE / 2 + i, SCREEN_SIZE / 2);
    }
}

void drawThirdQuarter(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < SCREEN_SIZE / 2; i += 20) {
        SDL_RenderDrawLine(gRenderer, i, SCREEN_SIZE / 2, SCREEN_SIZE / 2, SCREEN_SIZE / 2 + i);
    }
}

void drawFourthQuarter(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < SCREEN_SIZE / 2 + 1; i += 20) {
        SDL_RenderDrawLine(gRenderer, SCREEN_SIZE / 2, SCREEN_SIZE / 2 + i, SCREEN_SIZE - i, SCREEN_SIZE / 2);
    }
}

void drawStar(SDL_Renderer* gRenderer)
{
    drawFirstQuarter(gRenderer);
    drawSecondQuarter(gRenderer);
    drawThirdQuarter(gRenderer);
    drawFourthQuarter(gRenderer);
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);

    drawStar(gRenderer);

}