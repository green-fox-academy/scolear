 #include "draw.h"

 void draw(SDL_Renderer* gRenderer) {

     // draw a red horizontal line to the canvas' middle.
     // draw a green vertical line to the canvas' middle.

     SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
     SDL_RenderDrawLine(gRenderer,0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

     SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
     SDL_RenderDrawLine(gRenderer,SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);

 }

 int randomNumber(int nr_min, int nr_max)
 {
     static bool initialized = false;

     if (!initialized) {
         initialized = true;
         srand(time(NULL));
     }

     return rand() % nr_max + nr_min;
 }