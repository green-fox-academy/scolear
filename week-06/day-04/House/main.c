
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

bool worth_to_buy (house_p hpp) {
    float price_per_sqm = 
}

int main()
{
    int market_price = 400;
    return 0;
}