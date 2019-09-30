#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H


#include <vector>
#include "Plant.h"

class Garden {
public:

    void addPlant(Plant* plant);
    void waterGarden(float amount);
    void printDetailedInfo();
    void printInfo();

private:
    int countDryPlants();
    std::vector<Plant*> _plants;
};


#endif //GARDENAPPLICATION_GARDEN_H
