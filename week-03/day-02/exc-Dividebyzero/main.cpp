#include <iostream>
#include <fstream>

void divider(int num)
{
    if (num == 0){
        std::cout << "Fail";
    } else {
        std::cout << 10 / num;
    }
}

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0.
    // Solve the excercise without using exceptions!

    int numba;
    std::cin >> numba;

    divider(numba);

    return 0;
}