
#include <iostream>

int *getMin(int*, int);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    int *min = getMin(numbers, len);

    std::cout << *min;

    return 0;
}

int *getMin(int *arr, int size)
{
    int num = arr[0];
    int marker;

    for (int i = 0; i < size; ++i) {
        if(arr[i] < num) {
            num = arr[i];
            marker = i;
        }
    }

    return &arr[marker];

}