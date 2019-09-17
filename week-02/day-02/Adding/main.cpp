
#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *ptrA = &a;
    int *ptrB = &b;

    std::cout << *ptrA + *ptrB;



    return 0;
}