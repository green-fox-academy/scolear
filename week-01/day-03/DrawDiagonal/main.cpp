#include <iostream>

void printSymbol()
{
    std::cout << "%";
}

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    int num;

    std::cout << "Enter number: ";
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        printSymbol();
    }

    std::cout << std::endl;

    for (int j = 0; j < num - 2; j++) {
        printSymbol();

        for (int k = 0; k < num - 2; k++) {
            if (k == j) {
                printSymbol();
            } else {
                std::cout << " ";
            }
        }

        printSymbol();
        std::cout << std::endl;
    }

    for (int i = 0; i < num; i++) {
        printSymbol();
    }

    return 0;
}