#include <iostream>
#include <vector>
#include <string>

int main() {

/*
    .Create an empty list which will contain names (strings)
    .Print out the number of elements in the list
    .Add William to the list
    .Print out whether the list is empty or not
    .Add John to the list
    .Add Amanda to the list
    .Print out the number of elements in the list
    .Print out the 3rd element
    .Iterate through the list and print out each name

    William
    John
    Amanda

    .Iterate through the list and print

    1. William
    2. John
    3. Amanda

    .Remove the 2nd element
    .Iterate through the list in a reversed order and print out each name

    Amanda
    William

    .Remove all elements
*/

    std::vector<std::string> names;

    std::cout << names.size() << std::endl;

    names.push_back("William");

    if(names.empty()) {
        std::cout << "Empty" << std::endl;
    } else {
        std::cout << "Not empty" << std::endl;
    }

    names.push_back("John");
    names.push_back("Amanda");

    std::cout << names.size() << std::endl;

    std::cout << names[2] << std::endl;

    for (int i = 0; i < names.size(); ++i) {
        std::cout << names[i] << std::endl;
    }

    for (int i = 0; i < names.size(); ++i) {
        std::cout << i + 1 << ". " << names[i] << std::endl;
    }

    names.erase(names.begin() + 1);

    for (int i = 0; i < names.size(); ++i) {
        std::cout << names[names.size() - i - 1] << std::endl;
    }

    names.clear();

    if(names.empty()) {
        std::cout << "Empty" << std::endl;
    } else {
        std::cout << "Not empty" << std::endl;
    }

    return 0;
}