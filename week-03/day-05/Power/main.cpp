// Given base and n that are both 1 or more,
// compute recursively (no loops) the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

#include <iostream>

int powerN(int base, int n)
{
    if (n == 1) return base;
    return base * powerN(base, n -1);
}

int main() {

    int base, num;

    base = 3;
    num = 10;

    std::cout << powerN(base, num);

    return 0;
}