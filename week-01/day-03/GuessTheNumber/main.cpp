#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int num = 245;
    int guess = 0;
    int tries = 1;

    while (guess != num) {
        std::cout << "Enter a guess: ";

        std::cin >> guess;

        if (guess == num) {
            std::cout << "You found the number: " << num << std::endl;
            std::cout << "It took you " << tries << " tries. Good job? \n";
        } else if (guess > num) {
            std::cout << "The correct number is lower \n";
            tries++;
        } else if (guess < num) {
            std::cout << "The correct number is higher \n";
            tries++;
        }
    }

    return 0;
}