//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void drawTriangle(SDL_Renderer* renderer, int startX, int startY, int sideLength, float height)
{

    // Base line:
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength, startY);
    // Second line from start:
    SDL_RenderDrawLine(renderer, startX, startY, startX + sideLength / 2, startY - height);
    // Third line:
    SDL_RenderDrawLine(renderer, startX + sideLength / 2, startY - height, startX + sideLength, startY);

}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    int size = 30;
    float height = size * (sqrt(3) / 2);
    
    int Yinit = SCREEN_SIZE - 1;

    for (int j = 21; j > 0; --j) {
        for (int i = 0; i < j; ++i) {

            int Xstart =  (21 - j) * (size / 2) + (i * size);
            int Ystart = Yinit - ((21 - j) * height);

            drawTriangle(gRenderer, Xstart, Ystart, size, height);
        }
    }
}
