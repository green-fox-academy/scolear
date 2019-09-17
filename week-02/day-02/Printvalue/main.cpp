#include <iostream>

int main ()
{
    // Print out the value of the variable called 'age' using a pointer
    // (you have to create the pointer first)

    int age = 31;
    int *ptr = &age;

    std::cout << *ptr;

    return 0;
}