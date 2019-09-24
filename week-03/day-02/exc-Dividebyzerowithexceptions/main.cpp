
#include <iostream>
#include <fstream>

void divider(int num)
{
    if (num == 0){
        throw "fail";
    } else {
        std::cout << 10 / num;
    }
}

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0.
    // Solve the excercise using exceptions!
    // Hint: The try-catch block should be in main().

    int numba;
    std::cin >> numba;

    try {
        divider(numba);
    } catch (const char *errortext) {
        std::cout << errortext;
    }

    return 0;
}