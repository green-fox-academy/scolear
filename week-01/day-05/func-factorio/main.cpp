#include <iostream>
#include <string>

void factorio(int, int&);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int num;
    int fact = 1;

    std::cout << "Enter number: ";
    std::cin >> num;

    factorio(num, fact);

    std::cout << "Factorial of " << num << " is " << fact;

    return 0;
}

void factorio(int x, int& y) {

    for (int i = 1; i <= x; ++i) {
        y *= i;
    }
}