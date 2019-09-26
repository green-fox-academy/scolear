/*
Reuse your Animal class
Create a Farm class
    it has list of Animals
    it has slots which defines the number of free places for animals
    breed() -> creates a new animal if there's place for it
    slaughter() -> removes the least hungry animal

 */
#include <iostream>
#include "Farm.h"

int main() {

    Farm animalFarm;

    animalFarm.breed();
    animalFarm.breed();
    animalFarm.breed();
    animalFarm.breed();

    std::cout << animalFarm.getNumberOfAnimals() << std::endl;

    animalFarm.feedAnimal(0);
    animalFarm.feedAnimal(0);
    animalFarm.feedAnimal(0);

    animalFarm.slaughter();
    
    std::cout << animalFarm.getNumberOfAnimals() << std::endl;
    return 0;
}