#include <iostream>

void printAds(int*, int);

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int arr[5];

    std::cout << "Enter five integers:\n";

    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

/*
    std::cout << "Without pointers:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << "\t:\t" << &arr[i] << std::endl;       // easiest solution without pointers
    }
*/

    std::cout << "With pointers:\n";
    printAds(arr, 5);

    return 0;
}

void printAds(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << "\t:\t" << arr + i << std::endl;
    }
}