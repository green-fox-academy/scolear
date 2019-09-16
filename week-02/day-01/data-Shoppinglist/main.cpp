/*
We are going to represent a shopping list in a list containing strings.

.Create a list with the following items.
Eggs, milk, fish, apples, bread and chicken
Create an application which solves the following problems.
Do we have milk on the list?
Do we have bananas on the list?
*/

#include <iostream>
#include <vector>

bool onList(std::vector<std::string>, std::string);

int main() {

    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};

    onList(shoppingList, "milk") ? std::cout << "Milk yes.\n" : std::cout << "Milk no.\n";
    onList(shoppingList, "banana") ? std::cout << "Banana yes.\n" : std::cout << "Banana no.\n";

    return 0;
}

bool onList(std::vector<std::string> list, std::string item) {

    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == item) return true;
    }
    return false;
}