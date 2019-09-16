/*
We are going to represent our expenses in a list containing integers.

.Create a list with the following items.
500, 1000, 1250, 175, 800 and 120
Create an application which solves the following problems.
.How much did we spend?
.Which was our greatest expense?
.Which was our cheapest spending?
.What was the average amount of our spendings?
*/

#include <iostream>
#include <vector>

int main() {

    std::vector<int> expenses = {500, 1000, 1250, 175, 800, 120};
    int sum = 0;
    int greatest = 0;
    int cheapest;
    float average;

    for (int i = 0; i < expenses.size(); ++i) {
        sum += expenses[i];
    }
    std::cout << "You spent: " << sum << std::endl;

    for (int i = 0; i < expenses.size(); ++i) {
        if (expenses[i] > greatest) {
            greatest = expenses[i];
        }
    }
    std::cout << "Greatest expense: " << greatest << std::endl;

    cheapest = expenses[0];
    for (int i = 0; i < expenses.size(); ++i) {
        if (expenses[i] < cheapest) {
            cheapest = expenses[i];
        }
    }
    std::cout << "Smallest expense: " << cheapest << std::endl;

    average = (float)sum / expenses.size();
    std::cout << "Average spending: " << average;

    return 0;
}