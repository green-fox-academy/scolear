#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void init(vector_t* vec, int size, error_t* result){
    *result = NO_ERROR;
    if (size <= 0) {
        *result = WRONG_ARGUMENT;
        return;
    }
    vec->data = (int *) calloc(size, sizeof(int));
    vec->capacity = size;
    vec->size = 0;
}

void push_back(vector_t* vec, int new_data, error_t* result) {
    *result = NO_ERROR;
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size] = new_data;
    vec->size++;
}

int element_at(vector_t* vec, int at, error_t* result) {
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
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
    }
}

void destroy(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    vec->size = 0;
    vec->capacity = 0;
    free(vec->data);
}

void print(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    printf("Size: %d, Capacity: %d, Data: {", vec->size, vec->capacity);
    for (int i = 0; i < vec->size; ++i) {
        printf("%d, ", vec->data[i]);
    }
    printf("}\n");
}