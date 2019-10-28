#include <stdio.h>
#include <stdlib.h>

// Please use the realloc function where applicable!
// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* xPtr = NULL;
    int x;
    int sum = 0;

    printf("Enter a number:\n");
    scanf("%d", &x);

    xPtr = (int *) malloc(x * sizeof(int));

    printf("Enter %d numbers:\n", x);
    for (int i = 0; i < x; ++i) {
        scanf("%d", xPtr + i);
        sum += *(xPtr + i);
    }

    xPtr = (int *) realloc(xPtr, sum * sizeof(int));

    for (int j = 0; j < sum; ++j) {
        *(xPtr + j) = j;
        printf("%d\n", *(xPtr + j));
    }

    free(xPtr);

    return 0;
}