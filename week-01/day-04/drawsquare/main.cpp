
#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    for (int i = 1; i <= num - 2; i++) {
        std::cout << "%";
        for (int j = 1; j <= num - 2; j++) {
            std::cout << " ";
        }
        std::cout << "%" << std::endl;
    }


    for (int i = 1; i <= num; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    return 0;
}