#include <stdlib.h>
#include <stdio.h>
#include "genvector.h"

void init(vector_t* vec, int size, error_t* result) {
    *result = NO_ERROR;
    if (size <= 0) {
        *result = WRONG_ARGUMENT;
        return;
    }
    vec->data = (void *) malloc(size * sizeof(void *));
    vec->capacity = size;
    vec->size = 0;
}

void push_back(vector_t* vec, void* new_data, error_t* result) {
    *result = NO_ERROR;
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = (void *) realloc(vec->data, vec->capacity * sizeof(void *));
    }
    vec->data[vec->size] = new_data;
    vec->size++;
}

void* element_at(vector_t* vec, int at, error_t* result) {
    *result = NO_ERROR;
    if (at < 0 || at > vec->size - 1) {
        *result = OUT_OF_BOUNDS;
        return 0;
    }
    return vec->data[at];
}

void pop_back(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    if (vec->size <= 0) {
        *result = EMPTY;
        return;
    }
    vec->size--;
    if (vec->size < vec->capacity / 2) {
        vec->capacity /= 2;
        vec->data = (void *) realloc(vec->data, vec->capacity * sizeof(void*));
    }
}
