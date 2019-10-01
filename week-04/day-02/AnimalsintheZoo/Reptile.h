#ifndef ANIMALSINTHEZOO_REPTILE_H
#define ANIMALSINTHEZOO_REPTILE_H


#include "Animals.h"
#include "EggLaying.h"

class Reptile : public EggLaying  {
public:
    Reptile(std::string name);
};


#endif //ANIMALSINTHEZOO_REPTILE_H
