#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");
    std::string quote2("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you" using the replace function

    // Using replace:

    quote.replace(quote.find("you") - 1, 1, " always takes longer than ");
    std::cout << quote << std::endl;

    // Using insert:

    quote2.insert(quote2.find("you") - 1, " always takes longer than");
    std::cout << quote2 << std::endl;

    return 0;
}