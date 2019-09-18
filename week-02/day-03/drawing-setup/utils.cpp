//
// Created by scolear on 2019. 09. 18..
//
#include "utils.h"

int randomNumber(int nr_min, int nr_max)
{
    static bool initialized = false;

    if (!initialized) {
        initialized = true;
        srand(time(NULL));
    }

    return rand() % nr_max + nr_min;
}