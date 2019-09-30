#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H


#include <vector>
#include "Aircraft.h"

class Carrier {

public:
    Carrier(int initialAmmo, int initialHealth);

    void addPlane(Aircraft* plane);
    void fill();
    int maxAmmoNeeded();

private:
    std::vector<Aircraft*> _aircrafts;
    int _ammo;
    int _health;

};


#endif //AIRCRAFTCARRIER_CARRIER_H

/*

fill

    It should fill all the aircraft with ammo and subtract the needed ammo from the ammo storage
    If there is not enough ammo then it should start to fill the aircrafts with priority first
    If there is no ammo when this method is called, it should throw an exception

fight

    It should take another carrier as a reference parameter and fire all the ammo from the aircrafts to it, then subtract all the damage from its health points

getStatus

It should return a string about itself and all of its aircrafts' statuses in the following format:

HP: 5000, Aircraft count: 5, Ammo Storage: 2300, Total damage: 2280
Aircrafts:
Type F35, Ammo: 12, Base Damage: 50, All Damage: 600
Type F35, Ammo: 12, Base Damage: 50, All Damage: 600
Type F35, Ammo: 12, Base Damage: 50, All Damage: 600
Type F16, Ammo: 8, Base Damage: 30, All Damage: 240
Type F16, Ammo: 8, Base Damage: 30, All Damage: 240

If the health points are 0 then it should return: It's dead Jim :(
 */