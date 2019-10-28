#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// the resulting array should be 20 elements long
// print the array in descending order
// delete the arrays after you don't use them

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int* pointer = NULL;
    int* pointer2 = NULL;

    pointer = (int *) malloc(10 * sizeof(int));
    pointer2 = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        *(pointer + i) = (i + 1) * 2;
    }

    for (int j = 0; j < 10; ++j) {
        if (j % 2 == 0) {
            *(pointer2 + j) = j + 11;
        } else {
            *(pointer2 + j) = j;
        }
    }

    for (int k = 0; k < 10; ++k) {
        printf("%d, ", pointer[k]);
    }
    printf("\n");
    for (int k = 0; k < 10; ++k) {
        printf("%d, ", pointer2[k]);
    }
    printf("\n");

    pointer = realloc(pointer, 20 * sizeof(int));

    for (int l = 10; l < 20; ++l) {
        pointer[l] = pointer2[l-10];
    }

    free(pointer2);

    for (int k = 0; k < 20; ++k) {
        printf("%d, ", pointer[k]);
    }

    int n = 20;
    bubbleSort(pointer, n);
    printf("\n");
    printf("Sorted array: \n");
    printArray(pointer, n);

    free(pointer);

    return 0;
}