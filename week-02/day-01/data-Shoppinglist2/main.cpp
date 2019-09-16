/*
Create an application which solves the following problems.

.How much does Bob pay?
.How much does Alice pay?
Who buys more Rice?
Who buys more Potato?
Who buys more different products?
Who buys more products? (piece)
*/

#include <iostream>
#include <vector>
#include <map>

float userPays(std::map<std::string, int>, std::map<std::string, float>);
bool whoBuysMore(std::map<std::string, int>, std::map<std::string, int>, std::string);


int main() {

    std::map<std::string, float> products =
            {
                    {"milk", 1.07},
                    {"rice", 1.59},
                    {"eggs", 3.14},
                    {"apples", 2.31},
                    {"cheese", 12.60},
                    {"chicken breasts", 9.40},
                    {"tomato", 2.58},
                    {"potato", 1.75},
                    {"onion", 1.10}
            };

    std::map<std::string, int> listBob =
            {
                    {"milk", 3},
                    {"rice", 2},
                    {"eggs", 2},
                    {"apples", 1},
                    {"cheese", 1},
                    {"chicken breasts", 4},
                    {"tomato", 2},
                    {"potato", 1}
            };

    std::map<std::string, int> listAlice =
            {
                    {"rice", 1},
                    {"eggs", 5},
                    {"apples", 1},
                    {"chicken breasts", 2},
                    {"tomato", 10},
            };


    std::cout << "Bob pays: " << userPays(listBob, products) << std::endl;
    std::cout << "Alice pays: " << userPays(listAlice, products) << std::endl;

    return 0;
}

float userPays(std::map<std::string, int> usersList, std::map<std::string, float> productList)
{
    float sumPrice = 0;

    for (std::pair<std::string, int> pricePair : usersList) {
        if (productList.count(pricePair.first)) {
            sumPrice += productList[pricePair.first] * usersList[pricePair.first];
        }
    }

    return sumPrice;
}

bool whoBuysMore(std::map<std::string, int> listA, std::map<std::string, int> listB, std::string item)
{
    // returns 1 if first user buys more of item

    int a = 0;
    int b = 0;

    for (std::pair<std::string, int> itemCount : list) // todo: functionalize this also.

}