#include <iostream>
#include "Carrier.h"

Carrier::Carrier(int initialAmmo, int initialHealth) : _ammo(initialAmmo), _health(initialHealth) {}

void Carrier::addPlane(Aircraft *plane) {
    _aircrafts.push_back(plane);
}

int Carrier::maxAmmoNeeded() {
    int count = 0;
    for (Aircraft* pl : _aircrafts) {
        count += pl->ammoNeeded();
    }
    return count;
}

void Carrier::fill() {
    /*
     * It should fill all the aircraft with ammo and subtract the needed ammo from the ammo storage
    If there is not enough ammo then it should start to fill the aircrafts with priority first
    If there is no ammo when this method is called, it should throw an exception
     */
    try {
        if (_ammo <= 0) {
            throw "No ammo left in carrier.";
        } else {

        }
    } catch (const char* e){
        std::cout << e << std::endl;
    }



}
