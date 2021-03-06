#include <iostream>
#include <SDL.h>
#include "draw.h"
#include "FractalGenerator.h"

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Draw Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    // --------------------------------------------------------------------
    FractalGenerator frac(gRenderer, 6, 350);

    FractalGenerator frac3(gRenderer, 5, 350);

    int minSize = SCREEN_WIDTH / 4;
    int maxSize = 400;
    int sizeVar = minSize;
    bool growing = true;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0xFF);
        SDL_RenderClear(gRenderer);

        // draw(gRenderer);

        // frac.draw(FractalType ::TRIANGLE, 400, 350, 0, 0);

        FractalGenerator frac2(gRenderer, 6, sizeVar);
        SDL_SetRenderDrawColor(gRenderer, 1, 25, 54, 0xFF);
        frac2.draw(FractalType::CARPET, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

        if (sizeVar >= maxSize) {
            growing = false;
            sizeVar -= 2;
        } else if (sizeVar < maxSize && growing) {
            sizeVar++;
        } else if (!growing && sizeVar > minSize) {
            sizeVar--;
        } else if (sizeVar <= minSize) {
            growing = true;
        }

        // frac3.draw(FractalType::TREE, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 60);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
