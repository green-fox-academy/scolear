#ifndef ANIMALSINTHEZOO_EGGLAYING_H
#define ANIMALSINTHEZOO_EGGLAYING_H


#include "Animals.h"

class EggLaying : public Animals {
public:
    EggLaying(std::string name);
    virtual std::string breed() override;
};


#endif //ANIMALSINTHEZOO_EGGLAYING_H
