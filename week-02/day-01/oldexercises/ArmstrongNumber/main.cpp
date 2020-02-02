#include <iostream>
#include <cmath>

bool isArmstrong(int num)
{
    int sum = 0;
    int remainder = 0;
    int t = num;
    int digits = 0;

    while (t != 0) {
        t /= 10;
        digits++;
    }

    t = num;
    for (int i = 0; i < digits; ++i) {
        remainder = t % 10;
        remainder = std::pow(remainder, digits);
        sum += remainder;
        t /= 10;
    }
    return sum == num;
}

int main()
{
    int number;
    std::cout << "Enter the number to check: " << std::endl;
    std::cin >> number;
    std::cout << number << " is " << (isArmstrong(number) ? "" : "not ")  << "an Armstrong number."<< std::endl;

    return 0;
}
