#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdbool.h>

typedef enum error {
    NO_ERROR = 0,
    OUT_OF_BOUNDS,
    EMPTY,
    WRONG_ARGUMENT,
    INTERNAL_ERROR
} error_t;

typedef struct vector {
    int size;
    int capacity;
    int* data;
} vector_t;

void init(vector_t* vec, int size, error_t* result);
void resize(vector_t* vec, int new_capacity, error_t* result);
void push_back(vector_t* vec, int new_data, error_t* result);
void insert_at(vector_t* vec, int index, int new_data, error_t* result);
int element_at(vector_t* vec, int at, error_t* result);
int find_value(vector_t* vec, int value, error_t* result);
int size_of(vector_t* vec, error_t* result);
int capacity_of(vector_t* vec, error_t* result);
bool is_empty(vector_t* vec, error_t* result);
void pop_back(vector_t* vec, error_t* result);
void pop_at(vector_t* vec, int index, error_t* result);

void destroy(vector_t* vec, error_t* result);
void print(vector_t* vec, error_t* result);

// todo: delete.at

#endif //VECTOR_VECTOR_H