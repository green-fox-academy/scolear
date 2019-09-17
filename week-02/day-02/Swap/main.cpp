#include <iostream>

void swap(int*, int*);

int main ()
{
    // Create a function which swaps the values of 'a' and 'b' variables.
    // This time use a void function and pointers.

    int a = 10;
    int b = 316;

    int *ptrA = &a;
    int *ptrB = &b;

    std::cout << a << ", " << b << std::endl;

    swap(ptrA, ptrB);

    std::cout << a << ", " << b;

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}