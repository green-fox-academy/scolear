
#include <stdio.h>
#include <stdbool.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct house {
    char* address;
    int price;
    int rooms;
    float area;
} house_t, *house_p;

bool worth_to_buy (house_p hpp, int mp) {
    float price_per_sqm = hpp->price / hpp->area;
    return price_per_sqm < mp;
}

int main()
{
    house_t house1 = {"Ujbuda", 34000, 5, 80};
    house_t house2 = {"Ujpest", 5000, 2, 30};
    house_t house3 = {"Obuda", 12000, 5, 39};

    int market_price = 400;
    house_t houses[3] = {house1, house2, house3};
    int num_of_houses = sizeof(houses) / sizeof(houses[0]);
    int count_of_worthit = 0;

    for (int i = 0; i < num_of_houses; ++i) {
        if (worth_to_buy(&houses[i], market_price)) {
            printf("House in %s is worth to buy with a price/sqm of %.2f\n", houses[i].address, houses[i].price / houses[i].area);
            count_of_worthit++;
        }
    }
    printf("Houses worth to buy: %d", count_of_worthit);

    return 0;
}