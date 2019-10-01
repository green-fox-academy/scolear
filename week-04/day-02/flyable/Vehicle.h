#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H


class Vehicle {
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
};


#endif //FLYABLE_VEHICLE_H
