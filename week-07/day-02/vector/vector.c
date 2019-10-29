#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void init(vector_t* vec, int size, error_t* result) {
    *result = NO_ERROR;
    if (size <= 0) {
        *result = WRONG_ARGUMENT;
        return;
    }
    vec->data = (int *) calloc(size, sizeof(int));
    vec->capacity = size;
    vec->size = 0;
}

void resize(vector_t* vec, int new_capacity, error_t* result) {
    *result = NO_ERROR;
    vec->data = (int *) realloc(vec->data, new_capacity * sizeof(int));
    vec->capacity = new_capacity;
}

void push_back(vector_t* vec, int new_data, error_t* result) {
    insert_at(vec, vec->size, new_data, result);
}

void insert_at(vector_t* vec, int index, int new_data, error_t* result) {
    *result = NO_ERROR; // todo: error handling
    if (vec->size >= vec->capacity) {
        resize(vec, vec->capacity * 2, result);
    }

    for (int i = vec->size; i > index; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[index] = new_data;
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

int find_value(vector_t* vec, int value, error_t* result) {
    *result = NO_ERROR;
    for (int i = 0; i < vec->size; ++i) {
        if (vec->data[i] == value) return i;
    }
    return -1;
}

int size_of(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    return vec->size;
}

int capacity_of(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    return vec->capacity;
}

bool is_empty(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    return vec->size <= 0;
}

void pop_back(vector_t* vec, error_t* result) {
    pop_at(vec, vec->size - 1, result);
}

void pop_at(vector_t* vec, int index, error_t* result) {
    *result = NO_ERROR;
    if (vec->size <= 0) {
        *result = EMPTY;
        return;
    } else if (index < 0 || index > vec->size - 1) {
        *result = OUT_OF_BOUNDS;
        return;
    }

    for (int i = index; i < vec->size - 1; ++i) {
        vec->data[i] = vec->data[i + 1];
    }

    vec->size--;

    if (vec->size < vec->capacity / 2) {
        resize(vec, vec->capacity / 2, result);
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
    printf("Size: %d, Capacity: %d, Data: { ", vec->size, vec->capacity);
    for (int i = 0; i < vec->capacity; ++i) {
        if (i < vec->size) printf("%d, ", vec->data[i]);
        else               printf("_, ");
    }
    printf("}\n");
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    for (int i = vec->size - 1; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
        // Swap arr[i] with the element at random index
        swap(&vec->data[i], &vec->data[j]);
    }
}

void unique(vector_t* vec, error_t* result) {
    *result = NO_ERROR;
    for (int i = 0; i < vec->size; ++i) {
        for (int j = i + 1; j < vec->size; ++j) {
            if (vec->data[i] == vec->data[j]) {
                pop_at(vec, j, result);
                j--;
            }
        }
    }
}

void transform(vector_t* vec, int (*function)(int num)) {

}