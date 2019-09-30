
#include <iostream>
#include "Garden.h"

void Garden::waterGarden(float amount) {
    float amountPerPlant = amount / (float)countDryPlants();

    for (Plant* plant : _plants) {
        if (plant->needsWater()) {
            plant->waterPlant(amountPerPlant);
        }
    }

    std::cout << "\nWatering garden with " << amount << std::endl;
}

int Garden::countDryPlants() {
    int count = 0;
    for (Plant* plant : _plants) {
        if (plant->needsWater()) count++;
    }
    return count;
}

void Garden::printDetailedInfo() {

    if (_plants.empty()) {
        std::cout << "\nThe garden is empty." << std::endl;
    } else {
        std::cout << "\nPlants \t\t\t| \t Water" << std::endl;
        for (Plant *plant : _plants) {
            std::cout << plant->getDetailedInfo() << std::endl;
        }
    }
}

void Garden::addPlant(Plant *plant) {
    _plants.push_back(plant);
}

void Garden::printInfo() {
    for (Plant *plant : _plants) {
        std::cout << plant->getInfo() << std::endl;
    }
}
