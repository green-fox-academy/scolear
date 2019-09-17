
#include <iostream>

int findIndex(int*, int, int);

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int arr[] = {13, 15, 123, 666, 985, 12, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    int num = 666;

    std::cout << "Number " << num << " is at index " << findIndex(arr, len, num);

    return 0;
}

int findIndex(int *arr, int size, int value)
{
    for (int i = 0; i < size; ++i) {
        if ( *(arr + i) == value) {
            return i;
        }
    }

    return -1;
}