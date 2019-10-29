#include <stdio.h>
#include "genvector.h"

int main() {

    vector_t vec;
    error_t result;

    init(&vec, 3, &result);

    int a = 54;
    float b = 23.2f;

    push_back(&vec, "something", &result);
    push_back(&vec, &a, &result);
    push_back(&vec, &b, &result);

    /*
    for (int i = 0; i < 10; ++i) {
        push_back(&vec, &i, &result);
        if (result) {
            printf("ERROR: Push back failed.\n");
        }
    }
*/

    printf("%s\n", (char*) element_at(&vec, 0, &result));
    printf("%d\n", *(int*) element_at(&vec, 1, &result));
    printf("%.2f\n", *(float*) element_at(&vec, 2, &result));

    pop_back(&vec, &result);

    printf("%.2f\n", *(float*) element_at(&vec, 2, &result));

    return 0;
}