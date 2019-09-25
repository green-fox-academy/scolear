#include <iostream>
#include "Station.h"
#include "Car.h"

Station::Station() {
    _gasAmount = 1000;
}

void Station::fill(Car car) {
    std::cout << "Filling car..." << std::endl;

    while (!car.isFull()) {
        car.fill();
        _gasAmount--;
    }
    std::cout << "Car filled. Fuel remaining: " << _gasAmount << std::endl;
}