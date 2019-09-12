#include <iostream>

int main(int argc, char* args[]) {

    /*// Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5

    int a;
    int b;

    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    if (b <= a) {
        std::cout << "The second number should be bigger.";
    } else {
        for (int i = a; i < b; i++) {
            std::cout << i << std::endl;
        }
    }

    return 0;*/

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz \n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz \n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz \n";
        } else {
            std::cout << i << std::endl;
        }
    }


    return 0;
}