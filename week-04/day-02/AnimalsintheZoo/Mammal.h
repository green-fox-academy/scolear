#ifndef ANIMALSINTHEZOO_MAMMAL_H
#define ANIMALSINTHEZOO_MAMMAL_H


#include "Animals.h"

class Mammal : public Animals {
public:
    Mammal(std::string name);
    std::string breed() override;
};


#endif //ANIMALSINTHEZOO_MAMMAL_H
