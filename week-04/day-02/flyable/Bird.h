#ifndef ANIMALSINTHEZOO_BIRD_H
#define ANIMALSINTHEZOO_BIRD_H


#include "EggLaying.h"
#include "Flyable.h"

class Bird : public EggLaying, Flyable {
public:
    Bird(std::string name);

    void land() override;
    void fly() override;
    void takeOff() override;
};


#endif //ANIMALSINTHEZOO_BIRD_H
