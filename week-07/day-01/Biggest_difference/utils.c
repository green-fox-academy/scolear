#include "utils.h"

int find_min(const int *array, int size) {
    int min = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int find_max(const int *array, int size) {
    int max = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}