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
    void fight(Carrier*);
    int fireTotalDamage();
    int getTotalDamage();
    std::string getStatus();

private:
    std::vector<Aircraft*> _aircrafts;
    int _ammo;
    int _health;
    int _totalDamage;
};

#endif //AIRCRAFTCARRIER_CARRIER_H

/*
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