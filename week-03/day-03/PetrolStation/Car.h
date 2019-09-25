//
// Created by scolear on 2019. 09. 25..
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class Car {
public:
    Car(int gasAmount, int capacity);

    bool isFull();
    void fill();

private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROLSTATION_CAR_H
