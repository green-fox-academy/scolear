
#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <string>

class Aircraft {
public:
    Aircraft();

    int fight();
    int ammoNeeded();
    int refill(int);
    std::string getType();
    std::string getStatus();
    bool isPriority();
    int getTotalDamage();

protected:
    int _maxAmmo;
    int _ammunition;
    int _baseDamage;
    bool _isPriority;
    std::string _type;
};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
