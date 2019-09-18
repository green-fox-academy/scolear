//
// Created by scolear on 2019. 09. 18..
//

#include "draw.h"

void blackSquare(SDL_Renderer* renderer, int xp, int yp) {

    SDL_Rect rect2;
    rect2.x = xp;
    rect2.y = yp;
    rect2.h = SCREEN_HEIGHT / 8;
    rect2.w = SCREEN_WIDTH / 8;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect2);
}

void draw(SDL_Renderer* gRenderer) {

    int posx;
    int posy = 0;

    for (int i = 0; i < 8; i++) {
        posx = 0;
        for (int j = 0; j < 8; j++) {
            if (i == 0 || i % 2 == 0) {
                blackSquare(gRenderer, posx, posy);
                posx += SCREEN_WIDTH / 4;
            } else {
                posx += SCREEN_WIDTH / 8;
                blackSquare(gRenderer, posx, posy);
                posx += SCREEN_WIDTH / 8;
            }
        }
        posy += SCREEN_HEIGHT / 8;

    }
}

