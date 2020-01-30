#include <iostream>
#include <vector>

std::string containsSeven(const std::vector<int>& numbers)
{
    bool found = false;

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 7) {
            found = true;
            break;
        }
    }
    return found ? "Hoorray" : "Noooooo";
}

int main(int argc, char* args[])
{
    const std::vector<int> numbers = {1, 2, 3, 4, 5};
    const std::vector<int> numbers2 = {6, 7, 8, 9, 10};

    // Write a method that checks if the vector contains "7" if it contains return "Hoorray" otherwise return "Noooooo"

    // Expected output: "Noooooo"
    std::cout << containsSeven(numbers) << std::endl;

    // Expected output: "Hoorray"
    std::cout << containsSeven(numbers2) << std::endl;

    return 0;
}