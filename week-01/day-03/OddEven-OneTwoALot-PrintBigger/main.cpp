
#include <iostream>

int main(int argc, char* args[]) {

    /*// Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int num;

    std::cout << "Please enter a number: ";
    std::cin >> num;

    if (num % 2 == 0){
        std::cout << "Even." << std::endl;
    } else {
        std::cout << "Odd." << std::endl;
    }

    return 0;*/


/*
    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    int num;

    std::cout << "Please enter a number: ";
    std::cin >> num;

    if (num <= 0) {
        std::cout << "Not enough" << std::endl;
    } else if (num == 1) {
        std::cout << "One" << std::endl;
    } else if (num == 2) {
        std::cout << "Two" << std::endl;
    } else if (num > 2) {
        std::cout << "A lot" << std::endl;
    }

    return 0;
*/



    // Write a program that asks for two numbers and prints the bigger one
    int a;
    int b;

    std::cout << "Please enter two numbers: \n";
    std::cin >> a;
    std::cin >> b;

    if (a > b)
        std::cout << a << std::endl;
    else
        std::cout << b << std::endl;

    return 0;
}