#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> appendA(const std::vector<std::string>& inputString)
{
    std::vector<std::string> result;

    for (int i = 0; i < inputString.size(); ++i) {
        result.push_back(inputString[i] + 'a');
    }
    return result;
}

int main(int argc, char* args[])
{
    std::vector<std::string> animals = {"bo", "anacond", "koal", "pand", "zebr"};

    // Create a function called "appendA()" that adds "a" to every string in the "animals" list.
    // The parameter should be a vector.

    std::vector<std::string> newAnimals = appendA(animals);

    for(int i = 0; i < newAnimals.size(); ++i) {
        std::cout << newAnimals[i] << " ";
    }

    return 0;
}