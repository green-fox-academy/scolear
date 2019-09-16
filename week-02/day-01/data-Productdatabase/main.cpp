/*
.Create a map with the following key-value pairs.
Product name (key) 	Price (value)
Eggs 	200
Milk 	200
Fish 	400
Apples 	150
Bread 	50
Chicken 	550

Create an application which solves the following problems.
.How much is the fish?
.What is the most expensive product?
.What is the average price?
.How many products' price is below 300?
.Is there anything we can buy for exactly 125?
.What is the cheapest product?
*/

#include <iostream>
#include <map>
#include <limits>

int howMuch(std::map<std::string, int>, std::string);
std::string mostExpensive(std::map<std::string, int>);
std::string cheapest(std::map<std::string, int>);
float average(std::map<std::string, int>);
int priceBelow(std::map<std::string, int>, int);
bool exactly(std::map<std::string, int>, int);

int main() {

    std::map<std::string, int> products =
            {
                    {"eggs", 200},
                    {"milk", 125},
                    {"fish", 400},
                    {"apples", 150},
                    {"bread", 50},
                    {"chicken", 550},
            };

    // How much is the fish?
    std::string item = "fish";
    std::cout << "How much is the " << item << ": " << howMuch(products, item) << std::endl;

    // What is the most expensive product?
    std::cout << "Most expensive item is: " << mostExpensive(products) << std::endl;

    // What is the cheapest product?
    std::cout << "Cheapest item is: " << cheapest(products) << std::endl;

    // What is the average price?
    std::cout << "Average price is: " << average(products) << std::endl;

    // How many products' price is below 300?
    int pr = 300;
    std::cout << "Price below " << pr << ": " << priceBelow(products, pr) << " items" << std::endl;

    // Is there anything we can buy for exactly 125?
    int ex = 125;
    std::cout << "Anything for exactly " << ex << "? ";
    exactly(products, ex) ? std::cout << "Yep." : std::cout << "Nope";

    return 0;
}

int howMuch(std::map<std::string, int> listMap, std::string item)
{
    return listMap[item];
}

std::string mostExpensive(std::map<std::string, int> listMap)
{
    int exp = 0;
    std::string key;

    for (std::pair<std::string, int> pricePair : listMap) {
        if (pricePair.second > exp) {
            exp = pricePair.second;
            key = pricePair.first;
        }
    }
    return key;
}

std::string cheapest(std::map<std::string, int> listMap)
{
    int chp = std::numeric_limits<int>::max();
    std::string key;

    for (std::pair<std::string, int> pricePair : listMap) {
        if (pricePair.second < chp) {
            chp = pricePair.second;
            key = pricePair.first;
        }
    }
    return key;
}

float average(std::map<std::string, int> listMap)
{
    float sum = 0;
    for (std::pair<std::string, int> pricePair : listMap) {
        sum += pricePair.second;
    }
    return sum / listMap.size();
}

int priceBelow(std::map<std::string, int> list, int price)
{
    int num = 0;
    for (std::pair<std::string, int> pricePair : list) {
        if (pricePair.second < price) {
            num++;
        }
    }
    return num;
}

bool exactly(std::map<std::string, int> list, int price)
{
    for (std::pair<std::string, int> pricePair : list) {
        if (pricePair.second == price) {
            return true;
        }
    }
    return false;
}