#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int percentile(int percentile, int *ordered_list, int elements) {
    int rank = ceil(((double)percentile / 100) * elements);
    return ordered_list[rank - 1];
}

int main()
{
    int rows;
    int coloumns;

    int **rowPtr = NULL;
    int *colPtr = NULL;
    int *aux = NULL;
    int auxcounter = 0;

    printf("Please enter number of rows: ");
    scanf("%d", &rows);
    printf("Please enter number of coloumns: ");
    scanf("%d", &coloumns);

    // this would be the easiest but i dont think the exercise wants me to do this:
    // int matrix[rows][coloumns];

    aux = (int *) malloc(rows * coloumns * sizeof(int));

    rowPtr = (int **) malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; ++i) {
        rowPtr[i] = (int *) malloc(coloumns * sizeof(int));
    }

    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < coloumns; ++i) {
            printf("Enter element [%d][%d]: ", j, i);
            scanf("%d", &rowPtr[j][i]);
            aux[auxcounter] = rowPtr[j][i];
            auxcounter++;
        }
    }

    bubbleSort(aux, auxcounter);

    printf("80th percentile: %d\n", percentile(80, aux, auxcounter));
    printf("90th percentile: %d\n", percentile(90, aux, auxcounter));

    return 0;
}