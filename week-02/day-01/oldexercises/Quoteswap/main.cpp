#include <iostream>
#include <string>
#include <vector>

void quoteSwap(std::vector<std::string>& quote)
{
    std::string temp = quote[2];
    quote[2] = quote[5];
    quote[5] = temp;
}

int main(int argc, char* args[])
{
    std::vector<std::string> quote = {"What", "I", "do", "create,", "I", "cannot", "not", "understand."};

    // Accidentally I messed up this quote from Richard Feynman.
    // Two words are out of place
    // Your task is to fix it by swapping the right words with code
    // Create a method called quoteSwap().

    // Also, print the sentence to the output with spaces in between.

    quoteSwap(quote);

    for (auto& word : quote) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;

    return 0;
}