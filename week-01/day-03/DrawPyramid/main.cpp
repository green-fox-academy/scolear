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

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            std::cout << " ";
        }


        std::cout << std::endl;
    }

    return 0;
}