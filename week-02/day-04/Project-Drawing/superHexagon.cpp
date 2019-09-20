//
// Created by scolear on 2019. 09. 19..
//

#include "draw.h"
#include <cmath>

constexpr double pi() { return std::atan(1)*4; }

void connectDots(SDL_Renderer* renderer, int coordinates[6][2])
{
    for (int i = 0; i < 6; ++i) {
        if (i == 5) {
            SDL_RenderDrawLine(renderer, coordinates[i][0], coordinates[i][1], coordinates[0][0], coordinates[0][1]);
        } else {
            SDL_RenderDrawLine(renderer, coordinates[i][0], coordinates[i][1], coordinates[i + 1][0], coordinates[i + 1][1]);
        }
    }
}

void drawHexagon(SDL_Renderer* gRenderer, int startX, int startY, int side, double heightHalf)
{
    int coords[6][2];
    coords[0][0] = startX;
    coords[0][1] = startY;
    coords[1][0] = startX + side;
    coords[1][1] = startY;
    coords[2][0] = startX + side * 1.5;
    coords[2][1] = startY + heightHalf * side;
    coords[3][0] = startX + side;
    coords[3][1] = startY + heightHalf * 2 * side;
    coords[4][0] = startX;
    coords[4][1] = startY + heightHalf * 2 * side;
    coords[5][0] = startX - side / 2;
    coords[5][1] = startY + heightHalf * side;

    connectDots(gRenderer, coords);
}

void draw(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    double h_parameter = sin(pi() / 3);                             // sin(60)
    int patternSize = 7;
    int pattern[] = {patternSize - 3, patternSize - 2, patternSize - 1, patternSize, patternSize - 1, patternSize - 2, patternSize - 3};                             // hardcoded hexagon hexagon

    // Size of side:
    int side = 40;

    // Starting point for upperleft corner of superhexagon
    int initY = 200;
    int initX = 50;

    for (int i = 0; i < patternSize; ++i) {

        initX += side * 1.5;

        if ( i < patternSize / 2 + 1) {
            initY -= h_parameter * side;
        } else {
            initY += h_parameter * side;
        }

        for (int j = 0; j < pattern[i]; ++j) {
            drawHexagon(gRenderer, initX, initY + (j * h_parameter * 2 * side), side, h_parameter);
        }
    }
}