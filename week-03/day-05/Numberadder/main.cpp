// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

#include <iostream>

int recursiveAdder(int n) {
    if (n == 1) return 1;
    return n += recursiveAdder(n - 1);
}

int main() {

    int n = 4;

    std::cout << recursiveAdder(n);

    return 0;
}