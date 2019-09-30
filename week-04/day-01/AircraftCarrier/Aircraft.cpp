
#include "Aircraft.h"

Aircraft::Aircraft() : _ammunition(0), _maxAmmo(10), _baseDamage(0), _isPriority(false), _type("default") {}

int Aircraft::fight() {
    int allDamage = getTotalDamage();
    _ammunition = 0;
    return allDamage;
}

int Aircraft::ammoNeeded() {
    return _maxAmmo - _ammunition;
}

int Aircraft::refill(int ammoStorage) {

    int ammoTaken = 0;

    while (_ammunition < _maxAmmo && ammoStorage > 0) {
        _ammunition++;
        ammoTaken++;
    }
    return ammoStorage - ammoTaken;
}

std::string Aircraft::getType() {
    return _type;
}

std::string Aircraft::getStatus() {
    return "Type " + _type + ", Ammo: " + std::to_string(_ammunition)
            + ", Base Damage: " + std::to_string(_baseDamage)
            + ", All Damage: " + std::to_string(getTotalDamage()) + "\n";
}

bool Aircraft::isPriority() {
    return _isPriority;
}

int Aircraft::getTotalDamage() {
    return _baseDamage * _ammunition;
}
