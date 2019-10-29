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

    print(&vec, &result);

    pop_back(&vec, &result);
    pop_back(&vec, &result);
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