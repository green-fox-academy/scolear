#ifndef GENERICVECTOR_GENVECTOR_H
#define GENERICVECTOR_GENVECTOR_H

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
    void **data;
} vector_t;

void init(vector_t* vec, int size, error_t* result);
void push_back(vector_t* vec, void* new_data, error_t* result);
void* element_at(vector_t* vec, int at, error_t* result);
void pop_back(vector_t* vec, error_t* result);
void destroy(vector_t* vec, error_t* result);
void print(vector_t* vec, error_t* result);

#endif //GENERICVECTOR_GENVECTOR_H
