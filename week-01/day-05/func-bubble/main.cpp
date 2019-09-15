#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

void bubbleSort(int[], int, bool);
void swap(int*, int*);

int main(int argc, char* args[])
{
    int numbers[] = {2, 23, 41, 93, 19, 100, 2000, 12, 123, 321, 5};
    int len = sizeof(numbers)/ sizeof(numbers[0]);

    bool desc = false;

    bubbleSort(numbers, len, desc);

    for (int i = 0; i < len; ++i) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}

void bubbleSort(int list[], int n, bool descending)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {

            if (!descending && list[j] > list[j+1]) {
                swap(&list[j], &list[j+1]);
            } else if (descending && list[j] < list[j+1]) {
                swap(&list[j], &list[j+1]);
            }
        }
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}