//
// Created by scolear on 2019. 09. 18..
//

// Create a function that takes 1 parameter:
// An array of {x, y} points
// and connects them with green lines.
// Connect these to get a box: {{10, 10}, {290,  10}, {290, 290}, {10, 290}}
// Connect these: {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}}

#include "draw.h"

void connectDots(SDL_Renderer* renderer, int arr[][2], int len) {

    for (int i = 0; i < len; ++i) {
        if (i == len - 1) {
            SDL_RenderDrawLine(renderer, arr[i][0], arr[i][1], arr[0][0], arr[0][1]);
        } else {
            SDL_RenderDrawLine(renderer, arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
        }
    }
}

void draw(SDL_Renderer* gRenderer) {

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    int box[4][2] = {{10, 10}, {290,  10}, {290, 290}, {10, 290}};
    int shape[8][2] = {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}};

    int boxsize = sizeof(box) / sizeof(box[0]);

    int shapesize = sizeof(shape) / sizeof(shape[0]);

    // connectDots(gRenderer, box, boxsize);

    connectDots(gRenderer, shape, shapesize);
    SDL_Delay(2);
}

