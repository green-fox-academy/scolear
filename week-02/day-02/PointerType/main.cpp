
#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *ptrToA = &a;
    double *ptrToB = &b;
    std::string *ptrToString = &name;

    std::cout << ptrToA << std::endl;
    std::cout << ptrToB << std::endl;
    std::cout << ptrToString << std::endl;

    std::cout << *ptrToA << std::endl;
    std::cout << *ptrToB << std::endl;
    std::cout << *ptrToString << std::endl;


    return 0;
}