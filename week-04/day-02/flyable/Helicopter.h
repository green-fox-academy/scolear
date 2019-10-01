#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, Flyable {
public:

    void land() override;
    void fly() override;
    void takeOff() override;
    void startEngine() override;
    void stopEngine() override;
    void accelerate() override;



};


#endif //FLYABLE_HELICOPTER_H
