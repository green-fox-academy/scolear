#ifndef GFA_SDL2_DRAW_H
#define GFA_SDL2_DRAW_H

#include <SDL.h>
#include <time.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int randomNumber(int nr_min, int nr_max);

void draw(SDL_Renderer* gRenderer);

#endif //GFA_SDL2_DRAW_H
