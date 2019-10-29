#include <stdio.h>
#include "vector.h"

int main() {

    vector_t vec;
    error_t result;

    init(&vec, -1, &result);

    if (result != NO_ERROR) {
        printf("ERROR: Init failed, using standard size.\n");
        init(&vec, 3, &result);
    }
    print(&vec, &result);

    for (int i = 0; i < 10; ++i) {
        push_back(&vec, i, &result);
        print(&vec, &result);
        if (result) {
            printf("ERROR: Push back failed.\n");
        }
    }

    insert_at(&vec, 2, 29, &result);
    insert_at(&vec, 0, 11, &result);
    print(&vec, &result);

    printf("Value 29 can be found at index: %d\n", find_value(&vec, 29, &result));
    printf("Value 29 can be found at index: %d\n", find_value(&vec, 100, &result));

    pop_back(&vec, &result);
    print(&vec, &result);

    printf("Element at %d: %d\n", 5, element_at(&vec, 5, &result));
    pop_at(&vec, 5, &result);
    print(&vec, &result);
    printf("Element at %d: %d\n", 5, element_at(&vec, 5, &result));

    for (int i = 0; i < 10; ++i) {
        pop_back(&vec, &result);
        print(&vec, &result);
        if (result) {
            printf("ERROR: Pop back failed.\n");
        }
    }

    destroy(&vec, &result);

    return 0;
}