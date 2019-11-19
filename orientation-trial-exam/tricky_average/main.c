#include <stdio.h>
#include <limits.h>

// Create a function called GetTrickyAvg that takes a number array (only integers)
//     as parameter and returns the average of the smallest odd and largest even.

double GetTrickyAvg(const int *array, int array_length)
{
    int min_odd = INT_MAX;  // +2147483647
    int max_even = INT_MIN; // -2147483648

    for (int i = 0; i < array_length; ++i) {
        if ((array[i] % 2 != 0) && array[i] < min_odd) {
            min_odd = array[i];
        } else if ((array[i] % 2 == 0) && array[i] > max_even) {
            max_even = array[i];
        }
    }
    // todo: what if there is no even/odd number at all in the array?

    return ((float)max_even + (float)min_odd) / 2;
}

int main()
{
    int arr[] = {5, 2, 8, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%.1lf", GetTrickyAvg(arr, size));

    return 0;
}