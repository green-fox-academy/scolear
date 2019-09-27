#include <iostream>

int sumDigits(int n)
{
    if (n / 10 == 0) return n;

    return (n % 10) + sumDigits(n / 10);
}

int main() {

    unsigned int num = 926;

    std::cout << sumDigits(num);

    return 0;
}