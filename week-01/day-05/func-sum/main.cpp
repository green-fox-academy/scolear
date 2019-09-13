#include <iostream>
#include <string>

int sum(int);

int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Sum of all numbers until " << num << " is: " << sum(num);
    return 0;
}

int sum(int x) {
    int summa = 0;

    for (int i = 0; i < x; ++i) {
        summa += i;
    }
    return summa;
}