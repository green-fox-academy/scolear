
#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    /*// Create a program that writes this line 100 times:
    // "I won't cheat on the exam!"

    for (int i = 0; i < 100; i++) {
        std::cout << "I won't cheat on the exam!" << std::endl;
    }

    return 0;
*/


/*
    // Create a program that prints all the even numbers between 0 and 500
    int i;

    for (i = 0; i <= 500; i++) {
        if (i % 2 == 0)
            std::cout << i << std::endl;
    }

    return 0;*/

    // Create a program that asks for a number and prints the multiplication table with that number
    //
    // Example:
    // The number 15 should print:
    //
    // 1 * 15 = 15
    // 2 * 15 = 30
    // 3 * 15 = 45
    // 4 * 15 = 60
    // 5 * 15 = 75
    // 6 * 15 = 90
    // 7 * 15 = 105
    // 8 * 15 = 120
    // 9 * 15 = 135
    // 10 * 15 = 150

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 1; i <= 10; i++) {
        std::cout << i << " * " << num << " = " << i * num << std::endl;
    }

    return 0;
}