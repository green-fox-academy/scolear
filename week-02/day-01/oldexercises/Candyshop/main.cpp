
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> filter(std::vector<std::string> unfilteredList, const std::vector<std::string>& referenceList)
{
    if (unfilteredList.size() == referenceList.size()) return unfilteredList;

    std::vector<std::string> result;
    bool found;

    for (int i = 0; i < unfilteredList.size(); ++i) {
        found = false;
        for (int j = 0; j < referenceList.size(); ++j) {
            if (unfilteredList[i] == referenceList[j]) {
                found = true;
                break;
            }
        }
        if (found) result.push_back(unfilteredList[i]);
    }


    return result;
}

int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list. 
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the two lists as parameters. 

    std::vector<std::string> filteredList = filter(list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }

    return 0;
}