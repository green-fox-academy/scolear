#include <iostream>
#include <SDL.h>
#include "draw.h"
#include "utils.h"
#include "starryNight.h"

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
    bool visible = false;
    int ShootingStarPosX = 0;
    int ShootingStarPosY = 0;
    int initSSSize = 70;
    int ShootingStarSize = initSSSize;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {

                if (visible) {
                    std::cout << "Stop\n";
                    visible = false;
                    ShootingStarSize = 0;
                } else {
                    int mouseX, mouseY;
                    ShootingStarSize = initSSSize;
                    SDL_GetMouseState( &mouseX, &mouseY );
                    ShootingStarPosX = mouseX;
                    ShootingStarPosY = mouseY;
                    std::cout << "Shooting star from " << mouseX << " " << mouseY << std::endl;
                    visible = true;
                }
            }
        }

        //Clear screen

        // White Background:
        // SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Black background:
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

        SDL_RenderClear(gRenderer);

        if (visible) {
            ShootingStarPosY -= 20;
            ShootingStarPosX += 5;
            if ( ShootingStarSize > 0) {
                ShootingStarSize -= 5;
            }
            SDL_SetRenderDrawColor(gRenderer, 230, 255, 41, 255);
            drawStar(gRenderer, ShootingStarPosX, ShootingStarPosY, ShootingStarSize);
        }

        draw(gRenderer);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
