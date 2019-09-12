#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int num;

    std::cout << "Enter an odd number: ";
    std::cin >> num;

    if (num % 2 == 0){
        std::cout << "You entered an even number.";
        return 1;
    }

    for (int i = 1; i <= num / 2 + 1; i++) {
        for (int j = i; j < num / 2 + 1; j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = num / 2; i >= 1; --i) {
        for (int j = 0; j < num / 2 + 1 - i; j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}