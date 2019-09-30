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

    try {
        if (_ammo <= 0) {
            throw "No ammo left in carrier.";
        } else if (_ammo < maxAmmoNeeded()){
            for (Aircraft* pl : _aircrafts) {
                if (pl->isPriority()) {
                    _ammo = pl->refill(_ammo);
                }
            }
            for (Aircraft* pl : _aircrafts) {
                _ammo = pl->refill(_ammo);
            }
        } else {
            for (Aircraft* pl : _aircrafts) {
                _ammo = pl->refill(_ammo);
            }
        }
    } catch (const char* e){
        std::cout << e << std::endl;
    }
}

int Carrier::fireTotalDamage() {
    int totalDamage = 0;
    for (Aircraft* pl : _aircrafts) {
        totalDamage += pl->fight();
    }
    return totalDamage;
}

int Carrier::getTotalDamage() {
    int totalDamage = 0;
    for (Aircraft* pl : _aircrafts) {
        totalDamage += pl->getTotalDamage();
    }
    return totalDamage;
}

void Carrier::fight(Carrier* enemyCarrier) {
    enemyCarrier->_health -= fireTotalDamage();
}

std::string Carrier::getStatus() {

    std::string str;

    if (_health <= 0) {
        str = "It's dead Jim.";
    } else {
        str = "HP: " + std::to_string(_health) +
                          ", Aircraft count: " + std::to_string(_aircrafts.size()) +
                          ", Ammo storage: " + std::to_string(_ammo) +
                          ", Total damage: " + std::to_string(getTotalDamage()) + "\n" +
                          "Aircrafts:\n";
        for (Aircraft* pl : _aircrafts){
            str += pl->getStatus();
        }
    }
    return str;
}