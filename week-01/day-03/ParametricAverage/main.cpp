#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4

    int num;
    int temp;
    int sum = 0;
    float average;

    std::cout << "Enter a number:";
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        std::cout << "Add number to calculation:";
        std::cin >> temp;
        sum += temp;
    }

    average = (float)sum / num;

    std::cout << "Sum: " << sum << ", Average: " << average;

    return 0;
}