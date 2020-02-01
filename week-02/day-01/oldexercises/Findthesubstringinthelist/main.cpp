#include <iostream>
#include <string>
#include <vector>

void subStrList(const std::string& string, const std::vector<std::string>& list)
{
    int index;

    for (index = 0; index < list.size(); ++index) {
        if (list[index].find(string) != std::string::npos) {
            std::cout << index;
            return;
        }
    }
    std::cout << -1;
}

int main(int argc, char* args[])
{
    //  Create a function that takes a string and a vector of string as a parameter
    //  Returns the index of the string in the vector where the first string is part of
    //  Only need to find the first occurence and return the index of that
    //  Returns `-1` if the string is not part any of the strings in the vector

    //  Example:
    std::vector<std::string> searchArr = {"this", "is", "what", "I'm", "searching"};
    subStrList("ching", searchArr);
    //  should print: `4`
    subStrList("not", searchArr);
    //  should print: `-1`

    return 0;
}