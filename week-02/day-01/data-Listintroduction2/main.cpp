/*
.Create a list ('List A') which contains the following values

Apple, Avocado, Blueberries, Durian, Lychee

.Create a new list ('List B') with the values of List A
.Print out whether List A contains Durian or not
.Remove Durian from List B
.Add Kiwifruit to List A after the 4th element
.Compare the size of List A and List B
.Get the index of Avocado from List A
.Get the index of Durian from List B
.Add Passion Fruit and Pomelo to List B in a single statement
.Print out the 3rd element from List A
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> listB;

    listB = listA;

    bool isDurian = std::find(listA.begin(), listA.end(), "Durian") != listA.end();
    std::cout << isDurian << std::endl;

    listB.erase(listB.begin() + 3);

    listA.insert(listA.begin() + 3, "Kiwifruit");

    std::cout << "ListA size: " << listA.size() << " ListB size: " << listB.size() << std::endl;

    // Get the index of Avocado from List A:
    std::vector<std::string>::iterator it = std::find(listA.begin(), listA.end(), "Avocado");
    int index = std::distance(listA.begin(), it);
    std::cout << index << std::endl;

    std::vector<std::string>::iterator it2 = std::find(listB.begin(), listB.end(), "Durian");
    int index2 = std::distance(listB.begin(), it2);
    if (index2 < listB.size()) {
        std::cout << index2;
    } else {
        std::cout << "Durian not in listB." << std::endl;
    }

    std::string newFruits[] = {"Passion Fruit", "Pomelo"};
    listB.insert(listB.end(), std::begin(newFruits), std::end(newFruits));

    std::cout << listA[2];

    return 0;
}