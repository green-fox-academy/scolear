
#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct sandwich {
    char *name;
    float price;
    float weight;
} sandwich_t;

float order_total (sandwich_t sandwich, int pieces) {
    return pieces * sandwich.price;
}

int main()
{
    sandwich_t Hamburger = {"Big Mac", 10.5f, 12};

    printf("%.2f", order_total(Hamburger, 5));

    return 0;
}