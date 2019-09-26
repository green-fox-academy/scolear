#ifndef FARM_FARM_H
#define FARM_FARM_H

#include <vector>
#include "Animal.h"


class Farm {
public:
    Farm();

    Animal* getAnimal(int i);
    int getNumberOfAnimals();

    void breed();
    void slaughter();

    void feedAnimal(int x);

private:
    int _slots;
    std::vector<Animal*> _animals;

};


#endif //FARM_FARM_H
