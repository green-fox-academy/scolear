#include <iostream>
#include <vector>
#include "Station.h"

/*
    Create Station and Car classes

    Station
        Members:
            gasAmount
        create a constructor that initializes the gasAmount
        fill(car) ->    fills 1 unit of gas until the car is on full. Every time it transfers 1 unit it should print "Filling car!" on the console.
                        When the car is full it should print the remaining gas amount of the station

    Car
        Members:
            gasAmount
            capacity
        create constructor for Car with 2 arguments(gasAmount and capacity)
        car has 2 methods:
            isFull() -> returns true if capacity equals to gasAmount, false otherwise
            fill() -> increments the gasAmount by one.

    In the main function create a station and 5 cars with different amount of capacity and gas. Refill all the cars.
 */

int main() {

    Station gasStation;

    Car car1(20, 50);
    Car car2(0, 10);
    Car car3(30, 50);
    Car car4(30, 32);
    Car car5(25, 30);

    std::vector<Car> cars = {car1, car2, car3, car4, car5};

    for (int i = 0; i < cars.size(); ++i) {
        gasStation.fill(cars[i]);
    }


    return 0;
}