#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        for (int j = i; j < num; j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}